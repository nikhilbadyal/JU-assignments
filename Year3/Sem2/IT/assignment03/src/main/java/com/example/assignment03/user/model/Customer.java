package com.nikhil.assignment03.user.model;

public class Customer {
    private String uname;
    private String email;
    private String password;
    private String phone;
    private String address;


    public Customer() {
        super();
    }


    public Customer(String uname, String email, String password, String phone, String address) {
        super();
        this.uname = uname;
        this.email = email;
        this.password = password;
        this.phone = phone;
        this.address = address;
    }


    public String getUname() {
        return uname;
    }


    public String getEmail() {
        return email;
    }


    public String getPassword() {
        return password;
    }


    public String getPhone() {
        return phone;
    }


    public String getAddress() {
        return address;
    }


}
