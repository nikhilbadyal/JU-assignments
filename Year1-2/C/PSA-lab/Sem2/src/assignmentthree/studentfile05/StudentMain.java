package assignmentthree.studentfile05;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.OutputStream;

/**
 * @author Nikhil
 * @date 07 Feb2020
 */

public class StudentMain {
    public  static  void main(String[] args){

        OutputStream out;
        String filename = "C:\\Users\\nikhi\\Downloads\\Asus Tuff\\Asus Tuff" +
                "\\Code\\C\\PSA lab\\Sem2\\src\\assignmentthree\\studentfile05\\Serial.ser";
        File file = new File(filename);
        try(ObjectOutputStream objectOutputStream = new ObjectOutputStream(new FileOutputStream(file))){
            Student s = new Student(12,"nikhil","nikh@gmail.com",45);
            System.out.println(s);
            objectOutputStream.writeObject(s);
        } catch (FileNotFoundException e) {
            e.getMessage();
        }catch (IOException e) {
            e.getMessage();
        }
        try(ObjectInputStream objectInputStream = new ObjectInputStream(new FileInputStream(file))){
            Student s2 = (Student)objectInputStream.readObject();
            System.out.println(s2);
        } catch (FileNotFoundException e) {
            e.getMessage();
        } catch (IOException e) {
            e.getMessage();
        } catch (ClassNotFoundException e) {
            e.getMessage();
        }
    }
}
   
