package com.nikhil.assignment03.admin.model;

public class Admin {
    private String eid;
    private String ecode;


    public Admin() {
        super();
    }


    public Admin(String eid, String ecode) {
        super();
        this.eid = eid;
        this.ecode = ecode;
    }


    public String getEid() {
        return eid;
    }


    public String getEcode() {
        return ecode;
    }


}
