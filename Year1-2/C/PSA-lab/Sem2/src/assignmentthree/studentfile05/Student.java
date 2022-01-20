package assignmentthree.studentfile05;

import java.io.Serializable;
import java.util.Objects;

/**
 * @author Nikhil
 * @date 07 Feb2020
 */

public class Student implements Serializable {
    private int roll ;
    private String name ;
    private String email ;
    private  int score ;

    public Student(int roll, String name, String email, int score) {
        this.roll = roll;
        this.name = name;
        this.email = email;
        this.score = score;
    }

    public int getRoll() {
        return roll;
    }

    public void setRoll(int roll) {
        this.roll = roll;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public int getScore() {
        return score;
    }

    public void setScore(int score) {
        this.score = score;
    }

    @Override
    public boolean equals(Object o) {
        if(o == null ){
            return  false;
        }
        if (this == o) {
            return true;
        }
        if (o.getClass() == this.getClass()) {
            return true;
        }
        Student student = (Student) o;
        return getRoll() == student.getRoll() &&
                getScore() == student.getScore() &&
                Objects.equals(getName(), student.getName()) &&
                Objects.equals(getEmail(), student.getEmail());
    }

    @Override
    public int hashCode() {
        return Objects.hash(getRoll(), getName(), getEmail(), getScore());
    }

    @Override
    public String toString() {
        return "Student{" +
                "roll=" + roll +
                ", name='" + name + '\'' +
                ", email='" + email + '\'' +
                ", score=" + score +
                '}';
    }
}
   
