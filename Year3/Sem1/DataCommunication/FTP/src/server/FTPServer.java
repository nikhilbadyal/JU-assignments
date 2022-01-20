package server;

import java.io.*;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;

public class FTPServer {

    static int port;
    ServerSocket sock;

    String setSharedFolder() {
        String pwd = System.getProperty("user.dir");
        String path = pwd+"/server";
        File folder = new File(path);
        if (!folder.exists()) {
            if (folder.mkdir()) {
                System.out.println("Successfully created shared folder");
            } else {
                System.out.println("Failed to create directory!");
            }
        }
        return path;
    }

    public static void main(String[] args) {

        FTPServer obj = new FTPServer();

        port = Integer.parseInt(args[0]);
        String rootDir = obj.setSharedFolder();
        try {
            obj.sock = new ServerSocket(port);
            System.out.println("Server Address : " + InetAddress.getLocalHost().getHostAddress());
            System.out.println("Server started on port " + port);

//            while (true) {
                System.out.println("Waiting for Connection...");
                Socket soc = obj.sock.accept();
                System.out.println("Incoming connection from " + soc.getRemoteSocketAddress());
                FTPSession fobj = new FTPSession(soc, rootDir);
                Thread t = new Thread(fobj);
                t.start();
//            }
        }
        catch (Exception e) {
            System.err.println("Socket already in use");
            e.printStackTrace();
        }
    }
}

class FTPSession implements Runnable {

    private final String root;
    private String currDir;
    private final String fileSep = System.getProperty("file.separator");

    private final Socket cSock;
    private PrintWriter out;

    private Socket dataSock;
    private OutputStream dataOut;
    private InputStream dataIn;


    FTPSession(Socket soc, String pwd) {
        this.cSock = soc;
        this.root = pwd;
        this.currDir = root;
        System.out.println("This is root = " + root);
        System.out.println("This is currDir = " + currDir);
    }

    void deleteFile(String fileName) {

        String path = currDir + fileSep + fileName;
        System.out.println(path);
        File file = new File(path);
        if (file.exists()) {
            if(file.delete()) {
                out.println("250 File deleted successfully");
            }
        }
        else {
            out.println("550 File not found");
        }
    }

    void createDir(String dirName) {
        String path = currDir + fileSep + dirName;
        File folder = new File(path);
        try{
            if(!folder.exists()){
                if(folder.mkdir()){
                    out.println("257 Directory created");

                }else{
                    out.println("550 Directory not created");
                }
            }
            else {
                out.println("550 Directory not created as it already exist");
            }
        }catch(Exception e){
            out.println("550 Directory not created");
            System.out.println("Error while creating directories.");
        }

    }

    void deleteDir(String folder) {
        String path = currDir + fileSep + folder;
        System.out.println(path);
        File file = new File(path);
        if( file.isDirectory() ) {
            String[] strings = file.list();
            if(strings == null){
                out.println("550 Error deleting directory.");
                return;
            }
            if(strings.length>0){
                out.println("550 Directory not empty.");
            }
            else {
                if(file.delete()) {
                    out.println("250 Folder deleted successfully.");
                }
            }
        }
        else {
            out.println("550 No such directory.");
            System.out.println("Error");
        }
    }

    void receiveFile(String fileName) throws IOException {
        String filePath = currDir+ fileSep + fileName;
        System.out.println("Reading: "+ filePath);
        dataOut = new FileOutputStream(filePath);
        byte[] bytes = new byte[16*1024];
        int count;
        while ((count = dataIn.read(bytes)) > 0) {
            dataOut.write(bytes, 0, count);
        }
        dataOut.close();
        dataIn.close();
    }

    void sendFile(String fileName) throws IOException {

        String filePath = currDir + fileSep + fileName;
        File file = new File(filePath);
        if (file.isDirectory()) {
            currDir = filePath;

        }
        else {
            System.out.println(file.getAbsolutePath());
            RandomAccessFile reader = new RandomAccessFile(file, "rw");
            byte[] fileBytes = new byte[1024];
//        System.out.println(file.getAbsolutePath());
            while (reader.getFilePointer() < reader.length()) {
                dataOut.write(fileBytes, 0, reader.read(fileBytes));
            }
        }
        dataOut.flush();
        dataOut.close();
    }

    void sendFileList() throws IOException {
        System.out.println("Sending file list");
        StringBuilder listing = new StringBuilder();
        try
        {
            Process process = Runtime.getRuntime()
                    .exec("cmd /c dir", null, new File(currDir));
            process.waitFor();
            BufferedReader reader=new BufferedReader(new InputStreamReader(process.getInputStream()));
            String line=reader.readLine();
            while(line!=null)
            {
                listing.append(line).append("\r\n");
                line=reader.readLine();
            }
        }
        catch(Exception ignored) {
            System.out.println("Error occurred");
        }
        dataOut.write(listing.toString().getBytes());
        dataOut.flush();
        dataOut.close();
    }
    void cmdProcessor(String cmd, PrintWriter out) throws IOException {

        String[] args = cmd.split(" ");

        switch (args[0]) {

            case "PWD":
                System.out.println("Sending pwd result");
                out.println("257 "+'"'+ currDir +'"'+" is current directory.");
                break;
            case "RNTO":
                    try {
                        File oldName =
                                new File(currDir + fileSep + args[1]);
                        File newName =
                                new File(currDir + fileSep + args[2]);
                        if (oldName.renameTo(newName))
                            out.println("Renamed");
                        else
                            out.println("534 Error while remaining.");
                    }catch (Exception exception){
                        out.println("534 Exception while remaining.");
                    }
                    break;
            case "CWD":
                    System.out.println(currDir);
                    if(args[1].equals(".")){
                        if(currDir.equals(root)){
                            out.println("257 " + '"' + currDir + '"' + " is current directory.");
                            break;
                        }
                        File file = new File(currDir);
                        String newPath = file.getParent();
                        System.out.println(newPath+"is the path");
                        currDir = root;
                        out.println("257 " + '"' + currDir + '"' + " is current directory.");
                        break;
                    }
                    String newPath = currDir + fileSep + args[1];
                    File file = new File(newPath);
                    System.out.println(newPath+"is the path");
                    /*if(!file.isDirectory()){
                        out.println("No such directory");
                    }else */if(!file.exists()){
                        out.println("Directory doesnt exist.");
                    }
                    else if (root.equals(args[1])) {
                        currDir = args[1];
                        out.println("257 " + '"' + currDir + '"' + " is current directory.");
                    }else {
                        String cur = currDir;
                        currDir = cur + fileSep + args[1];
                        out.println("257 " + '"' + currDir + '"' + " is current directory.");
                    }
                break;

            case "TYPE":
                if (args[1].equals("I")) {
                    out.println("200 Type set to I.");
                }
                else {
                    out.println("200 Type set to A.");
                }
                break;

            case "EPSV":
                ServerSocket s = new ServerSocket(0);
                out.println("229 Entering Extended Passive Mode (|||"+ s.getLocalPort() +"|)");
                dataSock = s.accept();
                break;

            case "LIST":
            case "NLST":
            case "MLSD":
                out.println("150 Opening data connection.\n");
                try{
                    dataOut = dataSock.getOutputStream();
                    sendFileList();
                }catch (Exception exception){
                    out.println("534 Please run EPSV first");
                    break;
                }
                out.println("226 Transfer complete.\n");
                break;

            case "STOR":
                try{
                    dataIn = dataSock.getInputStream();
                    out.println("150 File status ok.");
                    receiveFile(args[1]);
                }catch(SocketException socketException){
                    out.println("534 Please run EPSV first");
                    out.flush();
                    break;

                }catch (Exception exception){
                    out.println("334 Wrong Argument.");
                    out.flush();
                    break;
                }
                out.println("226 transfer of " + args[1] + " complete");
                break;

            case "RETR":
                try{
                    dataOut = dataSock.getOutputStream();
                    out.println("150 File status ok.");
                    sendFile(args[1]);
                }catch(SocketException socketException){
                    out.println("534 Please run EPSV first");
                    break;

                }catch (Exception exception){
                    out.println("334 Wrong Argument.");
                    break;

                }
                out.println("226 transfer of " + args[1] + " complete");
                break;

            case "DELE":
                try{
                    deleteFile(args[1]);
                }catch (Exception exception){
                    out.println("550 Not file provided.");
                    break;

                }
                break;

            case "RMD":
                try{
                    deleteDir(args[1]);
                }catch (Exception exception){
                    out.println("550 Not file provided.");
                    break;

                }
                break;

            case "MKD":
                try{
                    createDir(args[1]);
                }catch (Exception exception){
                    out.println("550 Not file provided.");
                    break;

                }

                break;

            default:
                out.println("502 Command not implemented");
                break;
        }
    }

    public void run() {
        BufferedReader in = null;
        this.out = null;
        try {
            in = new BufferedReader(new InputStreamReader(cSock.getInputStream()));
            this.out = new PrintWriter(cSock.getOutputStream(),true);
            String clientCmd;
            out.flush();
            out.println("220 Localhost Connected\r\n");
            out.println("331 Anonymous login no password needed\r\n");

            boolean connected = true;

            while (connected) {
                clientCmd = in.readLine();

                if (clientCmd != null) {
                    System.out.println("Command from client: "+ clientCmd);
                    if (clientCmd.equals("QUIT")) {
                        connected = false;
                    }
                    else{
                        cmdProcessor(clientCmd, out);
                    }
                }
            }
        }
        catch (IOException e) {
            e.printStackTrace();
        }
        finally{
            currDir = "";
            try {
                if (in != null)
                    in.close();
                if (out != null)
                    out.close();
                if (cSock != null)
                    cSock.close();
            }
            catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
