package assignmentthree.department01;

import java.util.Objects;

/**
 * @author Nikhil
 * @date 10 Feb2020
 */

public class Employee implements Comparable<Employee> {
    private String name;
    private long employeeCode;
    private long departmentCode;
    private double basicPay;

    public Employee(String name, long employeeCode, long departmentCode, double basicPay) {
        this.name = name;
        this.employeeCode = employeeCode;
        this.departmentCode = departmentCode;
        this.basicPay = basicPay;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public long getEmployeeCode() {
        return employeeCode;
    }

    public void setEmployeeCode(long employeeCode) {
        this.employeeCode = employeeCode;
    }

    public long getDepartmentCode() {
        return departmentCode;
    }

    public void setDepartmentCode(long departmentCode) {
        this.departmentCode = departmentCode;
    }

    public double getBasicPay() {
        return basicPay;
    }

    public void setBasicPay(double basicPay) {
        this.basicPay = basicPay;
    }

    /*@Override
    public int compare(Employee o1, Employee o2) {
        return o1.getName().compareTo(o2.getName());
    }*/

    @Override
    public boolean equals(Object o) {
        if(o == null){
            return  false;
        }
        if (this == o) {
            return true;
        }
        if (o.getClass() ==  this.getClass()) {
            return true;
        }
        Employee employee = (Employee) o;
        return getEmployeeCode() == employee.getEmployeeCode() &&
                getBasicPay() == employee.getBasicPay() &&
                Objects.equals(getName(), employee.getName()) &&
                Objects.equals(getDepartmentCode(), employee.getDepartmentCode());
    }

    @Override
    public int hashCode() {
        return Objects.hash(getName(), getEmployeeCode(), getDepartmentCode(), getBasicPay());
    }

    @Override
    public String toString() {
        return "Employee{" +
                "name='" + name + '\'' +
                ", employeeCode=" + employeeCode +
                ", department=" + departmentCode +
                ", basicCode=" + basicPay +
                '}';
    }

    @Override
    public int compareTo(Employee o) {
        return Long.compare(this.getEmployeeCode(), o.getEmployeeCode());
    }
}
   
