package assignmentthree.department01;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

/**
 * @author Nikhil
 * @date 10 Feb2020
 */

public class EmployeeList {
    private ArrayList<Employee> employeeArrayList ;

    private Comparator<Employee> employeeNameComparatorAscending =
            (Employee e1,Employee e2) -> e1.getName().compareTo(e2.getName());

    private Comparator<Employee> employeeNameComparatorDescending = ( Employee e1,Employee e2) -> {
        if(e1.getName().compareTo(e2.getName()) > 1){
            return  -1;
        }else if(e1.getName().compareTo(e2.getName()) < -1){
            return  1;
        }else{
            return  0;
        }
    };
    private Comparator<Employee> employeePayComparatorAscending = (Employee e1,Employee e2) -> {
        if(e1.getBasicPay() < e2.getBasicPay()){
            return  -1;
        }else if(e1.getBasicPay() > e2.getBasicPay()){
            return  1;
        }else{
            return  0;
        }
    };
    private Comparator<Employee> employeePayComparatorDescending = (Employee e1,Employee e2) -> {
        if(e1.getBasicPay() < e2.getBasicPay()){
            return  1;
        }else if(e1.getBasicPay() > e2.getBasicPay()){
            return  -1;
        }else{
            return  0;
        }
    };
    private Comparator<Employee> employeeDepartmentCodeComparatorAscending = (Employee e1,Employee e2) -> {
        if(e1.getDepartmentCode() < e2.getDepartmentCode()){
            return  -1;
        }else if(e1.getDepartmentCode() > e2.getDepartmentCode()){
            return  1;
        }else{
            return  0;
        }
    };
    private Comparator<Employee> employeeDepartmentCodeComparatorDescending = (Employee e1,Employee e2) -> {
        if(e1.getDepartmentCode() < e2.getDepartmentCode()){
            return  1;
        }else if(e1.getDepartmentCode() > e2.getDepartmentCode()){
            return  -1;
        }else{
            return  0;
        }
    };
    private Comparator<Employee> employeeEmployeeCodeComparatorAscending = (Employee e1, Employee e2) -> {
        if(e1.getEmployeeCode() < e2.getEmployeeCode()){
            return  -1;
        }else if(e1.getEmployeeCode() > e2.getEmployeeCode()){
            return  1;
        }else{
            return  0;
        }
    };
    private Comparator<Employee> employeeEmployeeCodeComparatorDescending = (Employee e1,Employee e2) -> {
        if(e1.getEmployeeCode() < e2.getEmployeeCode()){
            return  1;
        }else if(e1.getEmployeeCode() > e2.getEmployeeCode()){
            return  -1;
        }else{
            return  0;
        }
    };

    public EmployeeList(ArrayList<Employee> employeeArrayList) {
        this.employeeArrayList = employeeArrayList;
    }

    public EmployeeList(int n ) {
        this.employeeArrayList = new ArrayList<>(n);
    }

    public EmployeeList() {
        this.employeeArrayList = new ArrayList<>(50);
    }

    RequiredClass isUnique(long employeeCode){
        for(Employee e : employeeArrayList){
            if(e.getEmployeeCode() == employeeCode){
                return  new RequiredClass(e,false);
            }
        }
        return new RequiredClass(null, true);
    }
    public boolean addMember(Employee e) {
        employeeArrayList.add(e);
        return  false;
    }

    public boolean removeMember(Employee e) {
        employeeArrayList.remove(e);
        return  false;
    }

    public void displayAllMembers() {
        for(Employee employee: employeeArrayList){
            System.out.println(employee);
        }
    }

    public boolean updateMemberDetails(Employee employee) {
        System.out.println("What do you want to update.");
        try {
            BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
            String str =bufferedReader.readLine();
            System.out.println("Please Enter details :- ");
            switch (str){
                case "Name":
                    employee.setName(bufferedReader.readLine());
                    break;
                case "Basic Pay":
                    employee.setBasicPay(Double.parseDouble( bufferedReader.readLine()));
                    break;
                case "Department Code":
                    employee.setDepartmentCode(Long.parseLong( bufferedReader.readLine()));
                    break;
                case "Emplyoee Code":
                    employee.setEmployeeCode(Long.parseLong( bufferedReader.readLine()));
                    break;
                default:
                    System.out.println("Please enter properly.");
            }
        } catch (NumberFormatException | IOException wrongType) {
            wrongType.getMessage();
        }
        return false;
    }



    public  void sortList(){
        Collections.sort(employeeArrayList);
    }
    public  void sortList(boolean isAscending){
        if(isAscending){
            Collections.sort(employeeArrayList, employeeEmployeeCodeComparatorAscending);
        }else{
            Collections.sort(employeeArrayList, employeeEmployeeCodeComparatorDescending);
        }
    }
    public void sortList(String condition,boolean status) {
        if ("Name".equalsIgnoreCase(condition)) {
            if(status){
                Collections.sort(employeeArrayList, employeeNameComparatorAscending);
            }else{
                Collections.sort(employeeArrayList, employeeNameComparatorDescending);
            }
        } else if("Basic Pay".equalsIgnoreCase(condition)){
            if(status){
                Collections.sort(employeeArrayList, employeePayComparatorAscending);
            }else{
                Collections.sort(employeeArrayList, employeePayComparatorDescending);
            }
        }else if("Department Code".equalsIgnoreCase(condition)){
            if(status){
                Collections.sort(employeeArrayList, employeeDepartmentCodeComparatorAscending);
            }else{
                Collections.sort(employeeArrayList, employeeDepartmentCodeComparatorDescending);
            }
        }else if("Employee Code".equalsIgnoreCase(condition)){
            if(status){
                Collections.sort(employeeArrayList, employeeEmployeeCodeComparatorAscending);
            }else{
                Collections.sort(employeeArrayList, employeeEmployeeCodeComparatorDescending);
            }
        }else {
            System.out.println("Enter properly.");
        }
    }
}
   
