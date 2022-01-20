package assignmentthree.department01;

import java.util.Objects;

/**
 * @author Nikhil
 * @date 10 Feb2020
 */

public class Department {
    private String name;
    private long departmentCode;
    private String location;

    public Department(String name, long departmentCode, String location) {
        this.name = name;
        this.departmentCode = departmentCode;
        this.location = location;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public long getDepartmentCode() {
        return departmentCode;
    }

    public void setDepartmentCode(long departmentCode) {
        this.departmentCode = departmentCode;
    }

    public String getLocation() {
        return location;
    }

    public void setLocation(String location) {
        this.location = location;
    }

    @Override
    public boolean equals(Object o) {
        if(o == null){
            return  false;
        }
        if (this == o) {
            return true;
        }
        if (o.getClass() == this.getClass()){
            return true;
        }
        Department that = (Department) o;
        return getDepartmentCode() == that.getDepartmentCode() &&
                Objects.equals(getName(), that.getName()) &&
                Objects.equals(getLocation(), that.getLocation());
    }

    @Override
    public int hashCode() {
        return Objects.hash(getName(), getDepartmentCode(), getLocation());
    }

    @Override
    public String toString() {
        return "Department{" +
                "name='" + name + '\'' +
                ", departmentCode=" + departmentCode +
                ", location='" + location + '\'' +
                '}';
    }
}
   
