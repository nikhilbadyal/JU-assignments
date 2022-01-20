package assignmentthree.department01;

import  java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * @author Nikhil
 * @date 10 Feb2020
 */

public class University {
    private static final String DOESNT_EXIST = "Member doesn't exist.";
    private static final String ENTER_EMPLOYEE_ID = "Enter Employee code  :- ";
    private DepartmentList departmentList;
    private EmployeeList employeeList;

    public University(int sizeOfList) {
        this.departmentList = new DepartmentList(sizeOfList);
        this.employeeList = new EmployeeList(sizeOfList);
    }

    public University() {
        this.departmentList = new DepartmentList(50);
        this.employeeList = new EmployeeList(50);
    }

    public boolean addEmployeeRequest() {
        try {
            BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
            System.out.println(ENTER_EMPLOYEE_ID);
            long employeeCode = Long.parseLong(bufferedReader.readLine());
            RequiredClass requiredClass = employeeList.isUnique(employeeCode);
            if (requiredClass.isaBoolean()) {
                System.out.println("Enter name , department Code , Basic pay");
                Employee employee = new Employee(bufferedReader.readLine(), employeeCode,
                        Long.parseLong(bufferedReader.readLine()), Double.parseDouble(bufferedReader.readLine()));
                employeeList.addMember(employee);
                return true;
            } else {
                System.out.println("Member exist.");
            }
        } catch (NumberFormatException | IOException wrongType) {
            wrongType.getMessage();
        }
        return false;
    }

    public boolean removeEmployeeRequest() {
        try {
            BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
            System.out.println(ENTER_EMPLOYEE_ID);
            long employeeCode = Long.parseLong(bufferedReader.readLine());
            RequiredClass requiredClass = employeeList.isUnique(employeeCode);
            if (!requiredClass.isaBoolean()) {
                return employeeList.removeMember(requiredClass.getEmployee());
            } else {
                System.out.println(DOESNT_EXIST);
            }
        } catch (NumberFormatException | IOException wrongType) {
            wrongType.getMessage();
        }
        return false;
    }

    public void displayEmployee() {
        try {
            BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
            System.out.println(ENTER_EMPLOYEE_ID);
            long employeeCode = Long.parseLong(bufferedReader.readLine());
            RequiredClass requiredClass = employeeList.isUnique(employeeCode);
            if (!requiredClass.isaBoolean()) {
                System.out.println("Details are as follow.");
                System.out.println(requiredClass.getEmployee());
            } else {
                System.out.println(DOESNT_EXIST);
            }
        } catch (NumberFormatException | IOException wrongType) {
            wrongType.getMessage();
        }
    }

    public void displayMember(long employeeCode) {
        RequiredClass requiredClass = employeeList.isUnique(employeeCode);
        if (!requiredClass.isaBoolean()) {
            System.out.println("Details are as follow.");
            System.out.println(requiredClass.getEmployee());
        } else {
            System.out.println(DOESNT_EXIST);
        }
    }

    public void displayAllMembers() {
        employeeList.displayAllMembers();
    }

    public boolean updateMemberDetailsRequest() {
        try {
            BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
            System.out.println(ENTER_EMPLOYEE_ID);
            long employeeCode = Long.parseLong(bufferedReader.readLine());
            RequiredClass requiredClass = employeeList.isUnique(employeeCode);
            if (!requiredClass.isaBoolean()) {
                return employeeList.updateMemberDetails(requiredClass.getEmployee());
            } else {
                System.out.println(DOESNT_EXIST);
            }
        } catch (NumberFormatException | IOException wrongType) {
            wrongType.getMessage();
        }
        return false;
    }

    public void sortEmployee(String condition,boolean status) {
        employeeList.sortList(condition,status);
    }
    public void sortEmployee() {
        employeeList.sortList();
    }
    public void sortEmployee(boolean status) {
        employeeList.sortList(status);
    }
}
   
