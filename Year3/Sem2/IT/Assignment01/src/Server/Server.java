package Server;

import Models.Database;
import Server.ClientManager.ClientManager;

import java.io.IOException;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;


public class Server {
    final int maxClients;
    int portNumber;
    public static int currentClients = 0 ;

    public Server(int portNumber, int maxClients) {
        this.maxClients = maxClients;
        this.portNumber = portNumber;
    }

    public void startServing()  {
        Database database = new Database();
        while (currentClients!= maxClients) {
            System.out.println("Waiting for client");
            Socket socket = null;
            try {
                ServerSocket serverSocket = new ServerSocket(portNumber);
                socket = serverSocket.accept();
                int    porto = socket.getPort();
                System.out.println( socket.getInetAddress());
                System.out.println( porto);
            } catch (IOException e) {
                System.out.println("IO Error while waiting for connection. Code 14");
            }
            System.out.println("Serving client " + (currentClients+ 1)+" on port "+portNumber);
            assert  socket != null;
            ClientManager clientManager = new ClientManager(socket, database);
            Thread t1 = new Thread(clientManager);
            t1.start();
            currentClients++;
            portNumber++;
        }
    }
}
