package com.nikhil.assignment03.admin.model;

public class Flight {

    private final int fno;
    private final int capacity;
    private final int seatLeft;
    private final int price;
    private final String company;
    private final String dest;
    private final String deptDate;
    private final String deptTime;
    private final String specialLimit;
    private final String specialOffer;
    private String src;


    public Flight(String company, int fno, String src,
                  String dest, String deptDate, String deptTime, int capacity,
                  int seatLeft, int price, String specialOffer, String specialLimit) {
        super();
        this.company = company;
        this.fno = fno;
        this.capacity = capacity;
        this.seatLeft = seatLeft;
        this.price = price;
        this.specialOffer = specialOffer;
        this.src = src;
        this.dest = dest;
        this.deptDate = deptDate;
        this.deptTime = deptTime;
        this.specialLimit = specialLimit;
    }


    public String getCompany() {
        return company;
    }


    public int getFno() {
        return fno;
    }


    public int getCapacity() {
        return capacity;
    }


    public int getSeatLeft() {
        return seatLeft;
    }


    public int getPrice() {
        return price;
    }


    public String getSpecialOffer() {
        return specialOffer;
    }


    public String getSrc() {
        return src;
    }


    public void setSrc(String src) {
        this.src = src;
    }


    public String getDest() {
        return dest;
    }


    public String getDeptDate() {
        return deptDate;
    }


    public String getDeptTime() {
        return deptTime;
    }


    public String getSpecialLimit() {
        return specialLimit;
    }


}
