package Server.ClientManager;

import Models.CommonObj;
import Models.Data;
import Models.Database;
import Server.Server;
import Util.CaesarCipher;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.HashMap;
import java.util.concurrent.locks.ReentrantReadWriteLock;

public class ClientManager implements Runnable {
    ReentrantReadWriteLock lock = new ReentrantReadWriteLock();
    Socket socket;
    Database database;
    ObjectOutputStream objectOutputStream;
    ObjectInputStream objectInputStream;
    boolean donaldTrump = false;

    public ClientManager(Socket socket, Database database) {
        this.socket = socket;
        this.database = database;
        try {
            objectOutputStream = new ObjectOutputStream(socket.getOutputStream());
        } catch (IOException e) {
            System.out.println("IO Error while creating output Stream. Code 10");
//            System.exit(10);
        }
        try {
            objectInputStream = new ObjectInputStream(socket.getInputStream());
        } catch (IOException e) {
            System.out.println("IO Error while creating input Stream. Code 11");
//            System.exit(11);
        }
    }

    public boolean checkUniqueUser(String username) {
        username = CaesarCipher.encrypt(username, 26 - CaesarCipher.shiftValue);
        System.out.println("Checking user " + username);
        boolean bool;
        try {
            lock.readLock().lock();
            bool = !database.getUserPassword().containsKey(username);
        } finally {
            lock.readLock().unlock();
        }
        System.out.println(bool);
        return bool;
    }

    public boolean setPassword(String username, String password) {
        username = CaesarCipher.encrypt(username, 26 - CaesarCipher.shiftValue);
        password = CaesarCipher.encrypt(password, 26 - CaesarCipher.shiftValue);
        System.out.println("Setting password");
        try {
            lock.writeLock().lock();
            database.getUserPassword().put(username, password);
            database.getDataBase().put(username, new Data());
            return true;
        } catch (Exception e) {
            return false;
        } finally {
            lock.writeLock().unlock();
        }
    }

    public boolean authenticateUser(String username, String password,boolean isEncrypted) {
        if(isEncrypted){
            username = CaesarCipher.encrypt(username, 26 - CaesarCipher.shiftValue);
            password = CaesarCipher.encrypt(password, 26 - CaesarCipher.shiftValue);
        }
        System.out.println("Checking authentication");
        try {
            lock.readLock().lock();
            if (database.getUserPassword().containsKey(username)) {
                return database.getUserPassword().get(username).equals(password);
            }
            return false;
        } catch (Exception ignore) {
            return false;
        } finally {
            lock.readLock().unlock();
        }
    }

    public void getAllData(String username) {
        username = CaesarCipher.encrypt(username, 26 - CaesarCipher.shiftValue);
        System.out.println("Request for printing all data of (" + username + ")");
        CommonObj commonObj = new CommonObj();
        boolean isPresent;

        try {
            lock.readLock().lock();
            isPresent = database.getDataBase().containsKey(username);
        } finally {
            lock.readLock().unlock();
        }

        if (!isPresent) {
            System.out.println("Username (" + username + ") does not exist");
            commonObj.setAck("notOk");
        } else {
            System.out.println("Sending ack(ok)");
            commonObj.setAck("ok");
            try {
                objectOutputStream.writeObject(commonObj);
            } catch (IOException e) {
                System.out.println("IO Error while writing to output stream. Code 15");
                donaldTrump = true;
                return;
//                System.exit(15);
            }
            try {
                objectOutputStream.reset();
            } catch (IOException e) {
                System.out.println("IO Error while resetting the output stream. Code 16");
                donaldTrump = true;
                return;
//                System.exit(16);
            }
            System.out.println("Sending all data of username (" + username + ")");
            commonObj.sendAllData(database.getDataBase().get(username));
        }
        try {
            objectOutputStream.writeObject(commonObj);
        } catch (IOException e) {
            System.out.println("IO Error while writing to output stream. Code 15");
            donaldTrump = true;
            return;
//            System.exit(15);
        }
        try {
            objectOutputStream.reset();
        } catch (IOException e) {
            System.out.println("IO Error while resetting the output stream. Code 16");
            donaldTrump = true;
//            System.exit(16);
        }
    }

    public void getParticularData(String username, String key) {
        username = CaesarCipher.encrypt(username, 26 - CaesarCipher.shiftValue);
        key = CaesarCipher.encrypt(key, 26 - CaesarCipher.shiftValue);
        System.out.println("Request for printing a particular data of (" + username + ")");
        CommonObj commonObj = new CommonObj();
        boolean isPresent;
        try {
            lock.readLock().lock();
            isPresent = database.getDataBase().containsKey(username);
        } finally {
            lock.readLock().unlock();
        }

        if (!isPresent) {
            System.out.println("Username (" + username + ") does not exist");
            commonObj.setAck("notOk");
        } else {
            System.out.println("Sending ack(ok)");
            commonObj.setAck("ok");
            try {
                objectOutputStream.writeObject(commonObj);
            } catch (IOException e) {
                System.out.println("IO Error while writting to output stream. Code 15");
                donaldTrump = true;
                return;
//                System.exit(15);
            }
            try {
                objectOutputStream.reset();
            } catch (IOException e) {
                System.out.println("IO Error while resetting the output stream. Code 16");
                donaldTrump = true;
                return;
//                System.exit(16);
            }
            System.out.println("Sending value of (" + key + ")" + "of username(" + username + ")");
            HashMap<String, String> data;
            try {
                lock.readLock().lock();
                data = database.getDataBase().get(username).getData();
            } finally {
                lock.readLock().unlock();
            }
            commonObj.getParticularData(data.getOrDefault(key, "null"));
        }
        System.out.println(commonObj.getPrintParticularMessage());
        try {
            objectOutputStream.writeObject(commonObj);
        } catch (IOException e) {
            System.out.println("IO Error while writing to output stream. Code 15");
            donaldTrump = true;
            return;
//            System.exit(15);
        }
        try {
            objectOutputStream.reset();
        } catch (IOException e) {
            System.out.println("IO Error while resetting the output stream. Code 16");
            donaldTrump = true;
//            System.exit(16);
        }
    }

    public void putData(String username, String key, String value) {
        username = CaesarCipher.encrypt(username, 26 - CaesarCipher.shiftValue);
        key = CaesarCipher.encrypt(key, 26 - CaesarCipher.shiftValue);
        value = CaesarCipher.encrypt(value, 26 - CaesarCipher.shiftValue);
        System.out.println("Request for putting data "+ key +" "+ value + "with username (" + username + ")");
        HashMap<String, String> data;
        boolean isPresent;
        try {
            lock.readLock().lock();
            data = database.getDataBase().get(username).getData();
            isPresent = data.containsKey(key);
        } finally {
            lock.readLock().unlock();
        }
        if (isPresent) {
            System.out.println("replaced");
            data.replace(key, value);
        } else {
            System.out.println("added");
            data.put(key, value);
        }

        CommonObj commonObj = new CommonObj();
        commonObj.setAck("ok");
        try {
            objectOutputStream.writeObject(commonObj);
        } catch (IOException e) {
            System.out.println("IO Error while writing to output stream. Code 15");
            donaldTrump = true;
            return;
//            System.exit(15);
        }
        try {
            objectOutputStream.reset();
        } catch (IOException e) {
            System.out.println("IO Error while resetting the output stream. Code 16");
            donaldTrump = true;
//            System.exit(16);
        }
    }

    public void upgradeRole(String clientUsername, String managerUsername, String managerPassword) {
        clientUsername = CaesarCipher.encrypt(clientUsername, 26 - CaesarCipher.shiftValue);
        managerUsername = CaesarCipher.encrypt(managerUsername, 26 - CaesarCipher.shiftValue);
        managerPassword = CaesarCipher.encrypt(managerPassword, 26 - CaesarCipher.shiftValue);
        System.out.println("Request to upgrade role of (" + clientUsername + ")");
        CommonObj commonObj = new CommonObj();

        boolean isPresent;
        try {
            lock.readLock().lock();
            isPresent = database.getDataBase().containsKey(managerUsername);
        } finally {
            lock.readLock().unlock();
        }
        if (isPresent) {
            boolean isManager;
            try {
                lock.readLock().lock();
                isManager = database.getDataBase().get(managerUsername).getRole().equals("manager");
            } finally {
                lock.readLock().unlock();
            }

            if (isManager) {

                boolean auth;
                try {
                    lock.readLock().lock();
                    auth = authenticateUser(managerUsername, managerPassword,false);
                } finally {
                    lock.readLock().unlock();
                }
                if (auth) {
                    System.out.println("Upgrading client (" + clientUsername + ") to manager");
                    database.getDataBase().get(clientUsername).setType("manager");
                    commonObj.setAck("ok");
                } else {
                    System.out.println("Wrong username or password of manager");
                    commonObj.setAck("Wrong username or password");
                }
            } else {
                commonObj.setAck("(" + managerUsername + ") has no authority to upgrade any user");
                System.out.println(managerUsername + "has no authority to upgrade any user");
            }
        } else {
            commonObj.setAck("Manager does not exist");
            System.out.println("Manager with username (" + managerUsername + ") does not exist");
        }
        System.out.println("writing " + commonObj.getAck());
        try {
            objectOutputStream.writeObject(commonObj);
        } catch (IOException e) {
            System.out.println("IO Error while writing to output stream. Code 15");
            donaldTrump = true;
            return;
//            System.exit(15);
        }
        try {
            objectOutputStream.reset();
        } catch (IOException e) {
            System.out.println("IO Error while resetting the output stream. Code 16");
            donaldTrump = true;
//            System.exit(16);
        }
    }

    public void viewOtherData(String managerUsername, String otherUsername) {
        managerUsername = CaesarCipher.encrypt(managerUsername, 26 - CaesarCipher.shiftValue);
        otherUsername = CaesarCipher.encrypt(otherUsername, 26 - CaesarCipher.shiftValue);
        System.out.println("Request for views data of (" + otherUsername + ") by (" + managerUsername + ")");
        CommonObj commonObj = new CommonObj();

        boolean isManager;
        try {
            lock.readLock().lock();
            isManager = database.getDataBase().get(managerUsername).getRole().equals("manager");
        } finally {
            lock.readLock().unlock();
        }

        if (isManager) {
            boolean isPresent;
            try {
                lock.readLock().lock();
                isPresent = database.getDataBase().containsKey(otherUsername);
            } finally {
                lock.readLock().unlock();
            }
            if (isPresent) {
                commonObj.setAck("ok");
                System.out.println("writing " + commonObj.getAck());
                try {
                    objectOutputStream.writeObject(commonObj);
                } catch (IOException e) {
                    System.out.println("IO Error while writing to output stream. Code 15");
                    donaldTrump = true;
//                    System.exit(15);
                }
                try {
                    objectOutputStream.reset();
                } catch (IOException e) {
                    System.out.println("IO Error while resetting the output stream. Code 16");
                    donaldTrump = true;
//                    System.exit(16);
                }
                Data data;
                try {
                    lock.readLock().lock();
                    data = database.getDataBase().get(otherUsername);
                } finally {
                    lock.readLock().unlock();
                }
                commonObj.sendViewOtherData(data);
                System.out.println("Sending data of (" + otherUsername + ") to (" + managerUsername + ")");
            } else {
                commonObj.setAck("Client (" + otherUsername + ") does not exist");
                System.out.println("writing " + commonObj.getAck());
            }
        } else {
            commonObj.setAck("(" + managerUsername + ")has not authority");
            System.out.println("writing " + commonObj.getAck());
        }
        try {
            objectOutputStream.writeObject(commonObj);
        } catch (IOException e) {
            System.out.println("IO Error while writing to output stream. Code 15");
            donaldTrump = true;
//            System.exit(15);
        }
        try {
            objectOutputStream.reset();
        } catch (IOException e) {
            System.out.println("IO Error while resetting the output stream. Code 16");
            donaldTrump = true;
//            System.exit(16);
        }
    }

    public void managerCheck(String userName) {
        userName = CaesarCipher.encrypt(userName, 26 - CaesarCipher.shiftValue);
        System.out.println("Request for manager check");
        CommonObj commonObj = new CommonObj();
        Data data = database.getDataBase().get(userName);
        if (data.getRole().equals("manager")) {
            commonObj.setAck("ok");
            try {
                objectOutputStream.reset();
            } catch (IOException e) {
                System.out.println("IO Error while resetting the output stream. Code 16");
                donaldTrump = true;
//                System.exit(16);
            }
        } else {
            commonObj.setAck("notOk");
            System.out.println("writing " + commonObj.getAck());
        }
        try {
            objectOutputStream.writeObject(commonObj);
        } catch (IOException e) {
            System.out.println("IO Error while writing to output stream. Code 15");
            donaldTrump = true;
//            System.exit(15);
        }
        try {
            objectOutputStream.reset();
        } catch (IOException e) {
            System.out.println("IO Error while resetting the output stream. Code 16");
            donaldTrump = true;
//            System.exit(16);
        }
    }


    public void start() {
        while (!donaldTrump) {
            CommonObj commonObj = null;
            try {
                commonObj = (CommonObj) objectInputStream.readObject();
            } catch (IOException e) {
                System.out.println("IO Error while reading from input stream. Code 17");
                donaldTrump = true;
                return;
//                System.exit(17);
            } catch (ClassNotFoundException e) {
                System.out.println("Serialization issue. Code 19");
                donaldTrump = true;
//                System.exit(19);
            }
            assert commonObj != null;
            switch (commonObj.getType()) {
                case 0 -> donaldTrump = true;
                case 1 -> {
                    if (checkUniqueUser(commonObj.getMessage().get(0))) {
                        commonObj.setAck("ok");
                    } else {
                        commonObj.setAck("notOk");
                    }
                    try {
                        objectOutputStream.writeObject(commonObj);
                    } catch (IOException e) {
                        System.out.println("IO Error while writing to output stream. Code 15");
                        donaldTrump = true;
//                        System.exit(15);
                    }
                    try {
                        objectOutputStream.reset();
                    } catch (IOException e) {
                        System.out.println("IO Error while resetting the output stream. Code 16");
                        donaldTrump = true;
//                        System.exit(16);
                    }
                }
                case 2 -> {
                    if (setPassword(commonObj.getMessage().get(0), commonObj.getMessage().get(1))) {
                        commonObj.setAck("ok");
                    } else {
                        commonObj.setAck("notOk");
                    }
                    try {
                        objectOutputStream.writeObject(commonObj);
                    } catch (IOException e) {
                        System.out.println("IO Error while writing to output stream. Code 15");
                        donaldTrump = true;
//                        System.exit(15);
                    }
                    try {
                        objectOutputStream.reset();
                    } catch (IOException e) {
                        System.out.println("IO Error while resetting the output stream. Code 16");
                        donaldTrump = true;
//                        System.exit(16);
                    }
                }
                case 3 -> {
                    if (authenticateUser(commonObj.getMessage().get(0), commonObj.getMessage().get(1),true)) {
                        commonObj.setAck("ok");
                    } else {
                        commonObj.setAck("notOk");
                    }
                    try {
                        objectOutputStream.writeObject(commonObj);
                    } catch (IOException e) {
                        System.out.println("IO Error while writing to output stream. Code 15");
                        donaldTrump = true;
//                        System.exit(15);
                    }
                    try {
                        objectOutputStream.reset();
                    } catch (IOException e) {
                        System.out.println("IO Error while resetting the output stream. Code 16");
                        donaldTrump = true;
//                        System.exit(16);
                    }
                }
                case 4 -> getAllData(commonObj.getMessage().get(0));
                case 5 -> getParticularData(commonObj.getMessage().get(0), commonObj.getMessage().get(1));
                case 6 -> putData(commonObj.getMessage().get(0), commonObj.getMessage().get(1), commonObj.getMessage().get(2));
                case 7 -> upgradeRole(commonObj.getMessage().get(0), commonObj.getMessage().get(1), commonObj.getMessage().get(2));
                case 8 -> viewOtherData(commonObj.getMessage().get(0), commonObj.getMessage().get(1));
                case 9 -> managerCheck(commonObj.getMessage().get(0));
            }

        }
    }

    @Override
    public void run() {
        try{
            start();
        }finally{
            System.out.println("One client disconnected");
            Server.currentClients--;
        }

    }
}
