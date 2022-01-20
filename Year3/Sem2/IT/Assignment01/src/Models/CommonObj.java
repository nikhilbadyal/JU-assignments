package Models;

import Util.CaesarCipher;

import java.io.Serializable;
import java.util.ArrayList;

public class CommonObj implements Serializable {
    private final ArrayList<String> message;
    Data data;
    String ack;
    int type;

    public CommonObj() {
        message = new ArrayList<>();
        data = new Data();
        ack = "";
    }


    public void checkUniqueUser(String username) {
        username = CaesarCipher.encrypt(username, CaesarCipher.shiftValue);
        message.add(username);
        this.type = 1;
    }


    public void setPassword(String username, String password) {
        username = CaesarCipher.encrypt(username, CaesarCipher.shiftValue);
        password = CaesarCipher.encrypt(password, CaesarCipher.shiftValue);
        message.add(username);
        message.add(password);
        this.type = 2;
    }

    public void authenticateUser(String username, String password) {
        username = CaesarCipher.encrypt(username, CaesarCipher.shiftValue);
        password = CaesarCipher.encrypt(password, CaesarCipher.shiftValue);
        message.add(username);
        message.add(password);
        this.type = 3;
    }

    public void getAllData(String username) {
        username = CaesarCipher.encrypt(username, CaesarCipher.shiftValue);
        message.add(username);
        this.type = 4;
    }

    public void getParticularData(String username, String key) {
        username = CaesarCipher.encrypt(username, CaesarCipher.shiftValue);
        key = CaesarCipher.encrypt(key, CaesarCipher.shiftValue);
        message.add(username);
        message.add(key);
        this.type = 5;
    }

    public void getParticularData(String value) {
        value = CaesarCipher.encrypt(value, CaesarCipher.shiftValue);
        System.out.println("update msg");
        this.message.add(value);
    }

    public ArrayList<String> getMessage() {
        return message;
    }

    public void setAck(String ack) {
        this.ack = ack;
    }

    public String getAck() {
        return ack;
    }

    public void sendAllData(Data data) {
        this.data = data;
        System.out.println("original");
        for (String k : data.getData().keySet()) {
            System.out.println(k + " " + data.get(k));
        }
        System.out.println("after transfer");
        for (String k : this.data.getData().keySet()) {
            System.out.println(k + " " + this.data.get(k));
        }
    }

    public Data getAllData() {
        return this.data;
    }

    public String getPrintParticularMessage() {
        return CaesarCipher.encrypt(message.get(0),26-CaesarCipher.shiftValue);
    }


    public void createPutData(String username, String key, String value) {
        username = CaesarCipher.encrypt(username, CaesarCipher.shiftValue);
        key = CaesarCipher.encrypt(key, CaesarCipher.shiftValue);
        value = CaesarCipher.encrypt(value, CaesarCipher.shiftValue);
        message.add(username);
        message.add(key);
        message.add(value);
        this.type = 6;
    }


    public void createUpgradeRole(String clientUsername, String username, String password) {
        clientUsername = String.valueOf(CaesarCipher.encrypt(clientUsername,CaesarCipher.shiftValue));
        username = String.valueOf(CaesarCipher.encrypt(username,CaesarCipher.shiftValue));
        password = String.valueOf(CaesarCipher.encrypt(password,CaesarCipher.shiftValue));
        message.add(clientUsername);
        message.add(username);
        message.add(password);
        this.type = 7;
    }

    public void createViewOtherData(String managerUsername, String clientUsername) {
        clientUsername = String.valueOf(CaesarCipher.encrypt(clientUsername,CaesarCipher.shiftValue));
        managerUsername = String.valueOf(CaesarCipher.encrypt(managerUsername,CaesarCipher.shiftValue));
        message.add(managerUsername);
        message.add(clientUsername);
        this.type = 8;
    }

    public void sendViewOtherData(Data data) {
        this.data = data;

    }

    public Data getViewOtherData() {
        return data;
    }

    public int getType() {
        return type;
    }

    public void createStop() {
        this.type = 0;
    }

    public void managerCheck(String username) {
        username = String.valueOf(CaesarCipher.encrypt(username,CaesarCipher.shiftValue));
        message.add(username);
        this.type = 9;
    }

}
