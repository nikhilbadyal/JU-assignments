package Client;

import Models.CommonObj;
import Models.Data;
import Util.PasswordChecker;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.Scanner;

public class Client {
    Socket socket;
    int port;
    ObjectOutputStream objectOutputStream;
    ObjectInputStream objectInputStream;

    public Client(String host, int port) {
        try {
            this.port = port;
            socket = new Socket(host, port);
            System.out.println(socket.getInetAddress());
        } catch (IOException e) {
            System.out.println("IO Error while creating socket. Code 18");
            System.exit(15);
        }

        try {
            objectOutputStream = new ObjectOutputStream(socket.getOutputStream());
        } catch (IOException e) {
            System.out.println("IO Error while creating output Stream. Code 10");
            System.exit(10);
        }
        try {
            objectInputStream = new ObjectInputStream(socket.getInputStream());
        } catch (IOException e) {
            System.out.println("IO Error while creating input Stream. Code 11");
            System.exit(11);
        }
    }

    public boolean checkUniqueUser(String user) {
        CommonObj commonObj = new CommonObj();
        commonObj.checkUniqueUser(user);
        try {
            objectOutputStream.writeObject(commonObj);
        } catch (IOException e) {
            System.exit(10);
        }
        try {
            commonObj = (CommonObj) objectInputStream.readObject();
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(11);

        } catch (ClassNotFoundException e) {
            System.out.println("Serialization issue. Code 19");
            System.exit(19);
        }
        return commonObj.getAck().equals("ok");
       /* }else{
            System.out.println("Server dead");
            return false;
        }*/
    }

    /*private boolean isServerAlive()  {
        try {
            return !(socket.getInputStream().read() == -1);
        } catch (SocketException e) {
            System.out.println("Server died because of you.");
            System.exit(1);
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
        return false;
    }*/


    public void setPassword(String username, String password) {
        CommonObj commonObj = new CommonObj();
        commonObj.setPassword(username, password);
        try {
            objectOutputStream.writeObject(commonObj);
        } catch (IOException e) {
            System.out.println("IO Error while writing to output stream. Code 15");
            System.exit(15);
        }
        try {
            commonObj = (CommonObj) objectInputStream.readObject();
        } catch (IOException e) {
            System.out.println("IO Error while reading from input stream Code 17");
            System.exit(17);
        } catch (ClassNotFoundException e) {
            System.out.println("Serialization issue. Code 19");
            System.exit(19);
        }
        if (!commonObj.getAck().equals("ok")) {
            System.out.println("Ops ! Something occurred on our side. Please report.");
        }
    }

    boolean authenticateUser(String username, String password) {
        CommonObj commonObj = new CommonObj();
        commonObj.authenticateUser(username, password);
        try {
            objectOutputStream.writeObject(commonObj);
        } catch (IOException e) {
            System.out.println("IO Error while writing to output stream. Code 15");
            System.exit(15);
        }
        try {
            commonObj = (CommonObj) objectInputStream.readObject();
        } catch (IOException e) {
            System.out.println("IO Error while reading from input stream Code 17");
            System.exit(17);
        } catch (ClassNotFoundException e) {
            System.out.println("Serialization issue. Code 19");
            System.exit(19);
        }
        return commonObj.getAck().equals("ok");
    }

    void printPasswordConditions() {
        System.out.println("""
                Password must have\s
                1. Upper Case
                2. Special Char
                3. Digits
                4. Small case
                5. Minimum length of 8
                """);
    }
    public void signup() {
        String username = getUsername();
        while (!checkUniqueUser(username)) {
            System.out.println("Username exists.Enter new username\n");
            username = getUsername();
            if (username.equals("-1")) {
                return;
            }
        }
        System.out.print("Enter password : \n");
        printPasswordConditions();
        String password = getPassword();
        while (!PasswordChecker.isStrong(password)) {
            System.out.println("Password not strong enough.Enter again\n");
            password = getPassword();
        }
        setPassword(username, password);
        System.out.println("Registered Successful\n");
    }

    String getUsername() {
        System.out.print("Enter username : ");
        Scanner scanner = new Scanner(System.in);
        return scanner.nextLine();
    }

    String getPassword() {
        System.out.print("Enter password : ");
        Scanner scanner = new Scanner(System.in);
        String password = scanner.nextLine();
        return scanner.nextLine();
    }

    public String login() {
        String username = getUsername();
        String password = getPassword();
        if (!authenticateUser(username, password)) {
            System.out.println("Wrong username or password\n");
            return "-1";
        }
        System.out.println("Successfully logged in\n");
        return username;
    }

    public void getAllData(String username) {
        CommonObj commonObj = new CommonObj();
        commonObj.getAllData(username);
        try {
            objectOutputStream.writeObject(commonObj);
        } catch (IOException e) {
            System.out.println("IO Error while writing to output stream. Code 15");
            System.exit(15);
        }
        try {
            commonObj = (CommonObj) objectInputStream.readObject();
        } catch (IOException e) {
            System.out.println("IO Error while reading from input stream Code 17");
            System.exit(17);
        } catch (ClassNotFoundException e) {
            System.out.println("Serialization issue. Code 19");
            System.exit(19);
        }
        if (commonObj.getAck().equals("ok")) {
            try {
                commonObj = (CommonObj) objectInputStream.readObject();
            } catch (IOException e) {
                System.out.println("IO Error while reading from input stream Code 17");
                System.exit(17);
            } catch (ClassNotFoundException e) {
                System.out.println("Serialization issue. Code 19");
                System.exit(19);
            }
            Data data = commonObj.getAllData();
            System.out.println("Printing all data of User(" + username + ")");
            for (String key : data.getData().keySet()) {
                System.out.println(key + " - " + data.get(key));
            }
            System.out.println();
        }
    }

    public void printParticularData(String username) {
        System.out.println("Enter key : ");
        Scanner scanner = new Scanner(System.in);
        String key = scanner.nextLine();
        CommonObj commonObj = new CommonObj();
        commonObj.getParticularData(username, key);
        try {
            objectOutputStream.writeObject(commonObj);
        } catch (IOException e) {
            System.out.println("IO Error while writing to output stream. Code 15");
            System.exit(15);
        }
        try {
            commonObj = (CommonObj) objectInputStream.readObject();
        } catch (IOException e) {
            System.out.println("IO Error while reading from input stream Code 17");
            System.exit(17);
        } catch (ClassNotFoundException e) {
            System.out.println("Serialization issue. Code 19");
            System.exit(19);
        }
        if (commonObj.getAck().equals("ok")) {
            System.out.println("Printing a particular data of user(" + username + ") key(" + key + ")");
            try {
                commonObj = (CommonObj) objectInputStream.readObject();
            } catch (IOException e) {
                System.out.println("IO Error while reading from input stream Code 17");
                System.exit(17);
            } catch (ClassNotFoundException e) {
                System.out.println("Serialization issue. Code 19");
                System.exit(19);
            }
            System.out.println(commonObj.getPrintParticularMessage());
        } else {
            System.out.println("Wrong key");
        }
    }

    public void viewData(String username) {
        System.out.println();
        Scanner scanner = new Scanner(System.in);
        System.out.println("1. View all data ");
        System.out.println("2. View a particular data");
        System.out.print("Enter Choice : ");
        int choice = scanner.nextInt();
        switch (choice) {
            case 1 -> getAllData(username);
            case 2 -> printParticularData(username);
            default -> System.out.println("wrong choice");
        }
    }

    public void putData(String username) {
        System.out.println();
        System.out.println("Enter info");
        System.out.print("Enter key : ");
        Scanner scanner = new Scanner(System.in);
        String key = scanner.nextLine();
        System.out.print("Enter value : ");
        String value = scanner.nextLine();

        CommonObj commonObj = new CommonObj();
        commonObj.createPutData(username, key, value);
        try {
            objectOutputStream.writeObject(commonObj);
        } catch (IOException e) {
            System.out.println("IO Error while writing to output stream. Code 15");
            System.exit(15);
        }
        try {
            commonObj = (CommonObj) objectInputStream.readObject();
        } catch (IOException e) {
            System.out.println("IO Error while reading from input stream Code 17");
            System.exit(17);
        } catch (ClassNotFoundException e) {
            System.out.println("Serialization issue. Code 19");
            System.exit(19);
        }
        if (commonObj.getAck().equals("ok")) {
            System.out.println("\nSuccessfully data stored key(" + key + ") -> value(" + value + ")\n");
        } else {
            System.out.println("IO Error while writing to output stream. Code 15");
            System.exit(15);
            System.out.println("Data cannot be stored");
        }
    }

    public void upgradeRole(String username) {
        System.out.println();
        System.out.print("Enter username of Manager : ");
        Scanner scanner = new Scanner(System.in);
        String usernameManager = scanner.nextLine();
        System.out.print("Enter Password : ");
        String password = scanner.nextLine();

        CommonObj commonObj = new CommonObj();
        commonObj.createUpgradeRole(username, usernameManager, password);
        try {
            objectOutputStream.writeObject(commonObj);
        } catch (IOException e) {
            e.printStackTrace();
        }
        try {
            commonObj = (CommonObj) objectInputStream.readObject();
        } catch (IOException e) {
            System.out.println("IO Error while reading from input stream Code 17");
            System.exit(17);
        } catch (ClassNotFoundException e) {
            System.out.println("Serialization issue. Code 19");
            System.exit(19);
        }
        if (commonObj.getAck().equals("ok")) {
            System.out.println();
            System.out.println("Client(" + username + ") has been promoted to Manager");
            System.out.println();
        } else {
            System.out.println("\nOperation unsuccessful");
            System.out.println(commonObj.getAck());
            System.out.println();
        }
    }

    public void viewOtherData(String username) {
        System.out.println();
        System.out.print("Enter the username : ");
        Scanner scanner = new Scanner(System.in);
        String otherUsername = scanner.nextLine();

        CommonObj commonObj = new CommonObj();
        commonObj.createViewOtherData(username, otherUsername);
        try {
            objectOutputStream.writeObject(commonObj);
        } catch (IOException e) {
            System.out.println("IO Error while writing to output stream. Code 15");
            System.exit(15);
        }
        try {
            commonObj = (CommonObj) objectInputStream.readObject();
        } catch (IOException e) {
            System.out.println("IO Error while reading from input stream Code 17");
            System.exit(17);
        } catch (ClassNotFoundException e) {
            System.out.println("Serialization issue. Code 19");
            System.exit(19);
        }
        if (commonObj.getAck().equals("ok")) {
            System.out.println();
            System.out.println("Printing all data of User(" + otherUsername + ")");
            try {
                commonObj = (CommonObj) objectInputStream.readObject();
            } catch (IOException e) {
                System.out.println("IO Error while reading from input stream Code 17");
                System.exit(17);
            } catch (ClassNotFoundException e) {
                System.out.println("Serialization issue. Code 19");
                System.exit(19);
            }
            Data data = commonObj.getViewOtherData();
            for (String key : data.getData().keySet()) {
                System.out.println(key + " - " + data.get(key));
            }
        } else {
            System.out.println(commonObj.getAck());
        }
        System.out.println();
    }

    public void processCommands(String username) {
        boolean goOn = true;
        while (goOn) {
            CommonObj commonObj = new CommonObj();
            commonObj.managerCheck(username);
            try {
                objectOutputStream.writeObject(commonObj);
            } catch (IOException e) {
                System.out.println("IO Error while writing to output stream. Code 15");
                System.exit(15);
            }
            try {
                commonObj = (CommonObj) objectInputStream.readObject();
            } catch (IOException e) {
                System.out.println("IO Error while reading from input stream Code 17");
                System.exit(17);
            } catch (ClassNotFoundException e) {
                System.out.println("Serialization issue. Code 19");
                System.exit(19);
            }

            System.out.println("1. View data");
            System.out.println("2. Put data");
            if (commonObj.getAck().equals("ok")) {
                System.out.println("3. View other's data");
                System.out.println("4. Exit ");
                Scanner scanner = new Scanner(System.in);
                int choice = scanner.nextInt();
                switch (choice) {
                    case 1 -> viewData(username);
                    case 2 -> putData(username);
                    case 3 -> viewOtherData(username);
                    case 4 -> goOn = false;
                    default -> System.out.println("Wrong choice");
                }
            } else {
                System.out.println("3. Upgrade role");
                System.out.println("4. Exit ");
                Scanner scanner = new Scanner(System.in);
                int choice = scanner.nextInt();
                switch (choice) {
                    case 1 -> viewData(username);
                    case 2 -> putData(username);
                    case 3 -> upgradeRole(username);
                    case 4 -> goOn = false;
                    default -> System.out.println("Wrong choice");
                }
            }
        }
    }

    public void stop() {
        CommonObj commonObj = new CommonObj();
        commonObj.createStop();
        try {
            objectOutputStream.writeObject(commonObj);
        } catch (IOException e) {
            System.out.println("IO Error while writing to output stream. Code 15");
            System.exit(15);
        }
    }

    public void connect() {
        boolean end = false;
        while (!end) {
            String choice = menu();
            switch (choice) {
                case "1" -> signup();
                case "2" -> {
                    String username = login();
                    if (!username.equals("-1")) {
                        processCommands(username);
                    }
                }
                case "3" -> {
                    stop();
                    end = true;
                }
                default -> System.out.println("Wrong choice");
            }

        }
        try {
            socket.close();
        } catch (IOException e) {
            System.out.println("IO Error while closing socket. Code 19");
            System.exit(19);
        }
    }

    public String menu() {
        System.out.println("1. Sign Up");
        System.out.println("2. login");
        System.out.println("3. Exit");
        Scanner scanner = new Scanner(System.in);
        return scanner.nextLine();
    }
}
