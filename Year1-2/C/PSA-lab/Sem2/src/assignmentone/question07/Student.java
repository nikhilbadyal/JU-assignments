package assignmentone.question07;

/**
 * @author Nikhil
 */

public class Student {
    protected String  name;
    protected int score;
    protected int roll;

    public Student(){
        this.name = "";
        this.score = 0;
        this.roll = 0;
    }

    public Student(String name, int score , int roll){
        this.name = name;
        this.roll = roll;
        this.score = score;
    }
    public Student(Student d){
        this.name = d.name;
        this.score = d.score;
        this.roll = d.roll;
    }

    void set(String name , int score , int roll){
        this.roll = roll;
        this.score = score;
        this.name = name;
    }

    void set(Student s){
        s.score = this.score;
        s.roll = this.roll;
        s.name = this.name;
    }

    void get(){
        System.out.println(this);
    }
    @Override
    public String toString() {
        return "Name : "+name+" Roll : "+roll+ " Score : "+score;
    }
}
