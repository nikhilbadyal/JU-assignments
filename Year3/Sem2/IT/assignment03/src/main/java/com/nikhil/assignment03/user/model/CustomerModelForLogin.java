package com.nikhil.assignment03.user.model;

public class CustomerModelForLogin {

    private final String username;
    private final String password;


    public CustomerModelForLogin(String username, String password) {
        super();
        this.username = username;
        this.password = password;
    }


    public String getUsername() {
        return username;
    }


    public String getPassword() {
        return password;
    }


}
