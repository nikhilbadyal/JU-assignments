package assignmentthree.department01;

import java.util.ArrayList;

/**
 * @author Nikhil
 * @date 10 Feb2020
 */

public class DepartmentList {
    private ArrayList<Department> departmentArrayList ;

    public DepartmentList(ArrayList<Department> departmentArrayList) {
        this.departmentArrayList = departmentArrayList;
    }

    public DepartmentList(int n) {
        this.departmentArrayList = new ArrayList<>(n);
    }
    public DepartmentList() {
        this.departmentArrayList = new ArrayList<>(50);
    }

}
   
