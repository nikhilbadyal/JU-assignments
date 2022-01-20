package assignmentthree.filecheck03;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * @author Nikhil
 * @date 10 Feb2020
 */

public class FileCheck {
    public static void main(String[] args){
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try{
            System.out.println("Enter path" + "name :- ");
            String pathOfFile = br.readLine();
            File fileStream = new File(pathOfFile);
            if(fileStream.exists()){
                System.out.println("Entered path Exist ");
                if(fileStream.isDirectory()){
                    System.out.println("Entered name is Directory.");
                    String[] fileName = fileStream.list();
                    System.out.println("Existing files within directory.");
                    for(String s : fileName){
                        System.out.println(s);
                    }
                }else{
                    System.out.println("Entered name is not a Directory.");
                }
            }else{
                System.out.println("Entered path doesn't exist.");
            }
        }catch(FileNotFoundException fof){
            System.out.println("File not found.");
        } catch (IOException ioError){
            System.out.println("IO Interrupt.");
        }
    }
}
   
