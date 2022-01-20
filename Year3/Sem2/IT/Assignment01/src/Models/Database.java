package Models;

import java.util.HashMap;

public class Database {
    HashMap<String, String> userPassword;
    HashMap<String, Data> dataBase;  // store data of every client

    public Database() {
        dataBase = new HashMap<>();
        Data data = new Data();
        data.setType("manager");
        dataBase.put("nikhil", data);
        userPassword = new HashMap<>();
        userPassword.put("nikhil", "1234");
    }

    public HashMap<String, String> getUserPassword() {
        return userPassword;
    }

    public HashMap<String, Data> getDataBase() {
        return dataBase;
    }
}
