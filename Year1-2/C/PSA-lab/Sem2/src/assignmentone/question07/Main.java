package assignmentone.question07;

/**
 * @author Nikhil
 */
public class Main {
    public  static  void main(String[] args){
        Student s = new Student();
        s.set("Nikhil",99,69);
        s.get();
        Student s1 = new Student(s);
        s1.get();
        Student s3 = new Student();
        s1.set(s3);
        s3.get();
        Student s4 = new Student("Nikhl",99,69);
        s4.get();
        Student s5 = new Student();
        s5.set("Nikhil",99,69);
        s5.get();

        System.out.println(s5);
    }
}
