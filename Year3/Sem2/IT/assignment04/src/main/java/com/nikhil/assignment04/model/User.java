package com.nikhil.assignment04.model;


public class User {
    String fname, lname, email, password, gender, prefer;
    int newTracker;
    int discountTracker;


    public User(String fname, String lname, String email, String password, String gender,
                String prefer, int newTracker, int discountTracker) {
        super();
        this.fname = fname;
        this.lname = lname;
        this.email = email;
        this.password = password;
        this.gender = gender;
        this.prefer = prefer;
        this.newTracker = newTracker;
        this.discountTracker = discountTracker;
    }

    public String getFname() {
        if (fname == null) {
            return "";
        }
        return fname;
    }

    public int getNewTracker() {
        return newTracker;
    }

    public void setNewTracker(int newTracker) {
        this.newTracker = newTracker;
    }

    public int getDiscountTracker() {
        return discountTracker;
    }

    public void setDiscountTracker(int discountTracker) {
        this.discountTracker = discountTracker;
    }

    public String getLname() {
        return lname;
    }


    public String getEmail() {
        return email;
    }


    public String getPassword() {
        return password;
    }


    public String getGender() {
        return gender;
    }


    public String getPrefer() {
        return prefer;
    }


}
