package assignmentone.question11;
import java.io.*;

public class Instructor {
    String name;
    int phone;

    Instructor(){
        this.name  = "";
        this.phone = 0;
    }
    Instructor(String name , int phone ){
        this.name = name;
        this.phone = phone;
    }

    void set() throws IOException {
        System.out.println("Enter details of instructor :- ");
        String phone ;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        this.name = br.readLine();
        phone = br.readLine();
        this.phone = Integer.parseInt(phone);
    }

    @Override
    public String toString() {
        return "Instructor{" +
                "name='" + name + '\'' +
                ", phone=" + phone +
                '}';
    }
}
