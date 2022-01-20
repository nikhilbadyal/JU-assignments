package assignmentthree.department01;

/**
 * @author Nikhil
 * @date 13 Feb2020
 */

public class RequiredClass {
    Employee employee;
    boolean aBoolean;

    public RequiredClass(Employee employee, boolean aBoolean) {
        this.employee = employee;
        this.aBoolean = aBoolean;
    }

    public Employee getEmployee() {
        return employee;
    }

    public void setEmployee(Employee employee) {
        this.employee = employee;
    }

    public boolean isaBoolean() {
        return aBoolean;
    }

    public void setaBoolean(boolean aBoolean) {
        this.aBoolean = aBoolean;
    }
}
   
