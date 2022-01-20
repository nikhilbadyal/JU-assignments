package assignmentwo.institute02;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * @author Nikhil
 * @date 24 Jan2020
 */

public class Address {
    protected String name;
    protected long phone;
    protected int pincode;
    protected String locality;
    protected String detailedAddress;
    protected String city;
    protected String district;
    protected String state;
    protected String landmark;
    protected String addressType;
    protected long alternativeNumber;

    Address() {
        throw new  IllegalArgumentException();
    }
    Address(Address address){
        this.addressType = address.addressType;
        this.alternativeNumber = address.alternativeNumber;
        this.city = address.city;
        this.detailedAddress = address.detailedAddress;
        this.district = address.district;
        this.locality = address.locality;
        this.landmark = address.landmark;
        this.name = address.name;
        this.phone = address.phone;
        this.pincode = address.pincode;
        this.state = address.state;
    }

    public Address(String name, long phone, int pincode, String locality,
                   String detailedAddress, String city, String district, String state,
                   String landmark, String addressType, long alternativeNumber) {
        this.name = name;
        this.phone = phone;
        this.pincode = pincode;
        this.locality = locality;
        this.detailedAddress = detailedAddress;
        this.city = city;
        this.district = district;
        this.state = state;
        this.landmark = landmark;
        this.addressType = addressType;
        this.alternativeNumber = alternativeNumber;
    }

    public Address(String name, long phone, int pincode,
                   String detailedAddress, String city, String district,
                   String state, String landmark, String addressType) {
        this.name = name;
        this.phone = phone;
        this.pincode = pincode;
        this.detailedAddress = detailedAddress;
        this.city = city;
        this.district = district;
        this.state = state;
        this.landmark = landmark;
        this.addressType = addressType;
    }

    void update() {
        System.out.println("What data you want to update :- ");
        String str ;
        try{
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            str = br.readLine();
            while("stop".equalsIgnoreCase(str)){
                str = br.readLine();
            }
        }catch (IOException ioError) {
            System.out.println("IO Error occurred.");
        }
    }
}


