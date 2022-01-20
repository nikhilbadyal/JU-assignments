package assignmentthree.storenames04;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import  java.io.FileWriter;
import java.io.FileReader;


/**
 * @author Nikhil
 * @date 10 Feb2020
 */

public class NamesInAFile{
        public static void main(String[] args){
            File filename = new File("C:\\Users\\nikhi\\Downloads\\" +
                    "Asus Tuff\\Asus Tuff\\Code\\C\\PSA lab\\Sem2\\src\\" +
                    "assignmentthree\\storenames04\\nikhil.txt");
            try(FileWriter fileWriter = new FileWriter(filename);
                BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in))) {
                int count = 0;
                while (count != 5) {
                    fileWriter.write(bufferedReader.readLine());
                    fileWriter.write("\n");
                    ++count;
                }
            }catch(FileNotFoundException fof){
                System.out.println("File not found.");
            } catch (IOException ioError){
                System.out.println("IO Interrupt.");
            }
            try(FileReader fileReader = new FileReader(filename)){
                int c ;
                while ((c = fileReader.read()) != -1 ){
                    System.out.print((char)c);
                }
            }catch(FileNotFoundException fof){
                System.out.println("File not found.");
            } catch (IOException ioError){
                System.out.println("IO Interrupt.");
            }
        }
}

   
