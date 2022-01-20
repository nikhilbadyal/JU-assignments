package assignmentone.question11;

import java.io.*;


public class Course {
    Instructor inst;
    TextBook txt;
    String name ;

    public Course() {
        this.inst = new Instructor();
        this.txt = new TextBook();
        this.name = "";
    }

    public Course(Instructor inst, TextBook txt, String name) {
        this.inst = inst;
        this.txt = txt;
        this.name = name;
    }

    void show(){
        System.out.println("Course details are as follow.");
        System.out.println("Course { name = '"+ name+"'}");
        System.out.println(inst);
        System.out.println(txt);
    }

    public void set(Instructor inst, TextBook txt, String name) {
        this.inst = inst;
        this.txt = txt;
        this.name = name;
    }

    void set() throws IOException {
        System.out.print("Enter course name :- ");
        String s ;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        this.name = br.readLine();
        this.txt.set();
        this.inst.set();
    }


    @Override
    public String toString() {
        return "Course{ " +  "\n" + "Name ="
                + name + "\n" +
                inst + "\n" + txt + "\n"+ " }";
    }
}
