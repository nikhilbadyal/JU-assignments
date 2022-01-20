package assignmentthree.department01;

/**
 * @author Nikhil
 * @date 13 Feb2020
 */

public class UniversityMain {
    public  static void main(String[] args){
        University myUniversity = new University();
        System.out.println("Adding member.");
        System.out.println(myUniversity.addEmployeeRequest());
        System.out.println(myUniversity.addEmployeeRequest());
        System.out.println("Removing member.");
        System.out.println(myUniversity.removeEmployeeRequest());
        System.out.println("Displaying member.");
        myUniversity.displayEmployee();
        System.out.println("Displaying member by code.");
        myUniversity.displayMember(100);
        System.out.println("Displaying all member.");
        myUniversity.displayAllMembers();
        //myUniversity.updateMemberDetailsRequest();
        System.out.println("Sorted  member as per Name");
        String condition = "Name";
        boolean status = true;
        boolean status1 = false;
        myUniversity.sortEmployee(condition,status);
        myUniversity.displayAllMembers();
        myUniversity.sortEmployee(condition,status1);
        myUniversity.displayAllMembers();
        System.out.println("Sorted  member as per Employee Code");
        condition = "Employee Code";
        myUniversity.sortEmployee(condition,status);
        myUniversity.displayAllMembers();
        myUniversity.sortEmployee(condition,status1);
        myUniversity.displayAllMembers();
        System.out.println("Sorted  member as per Department Code");
        condition = "Department Code";
        myUniversity.sortEmployee(condition,status);
        myUniversity.displayAllMembers();
        myUniversity.sortEmployee(condition,status1);
        myUniversity.displayAllMembers();
        System.out.println("Sorted  member as per Basic Pay");
        condition = "Basic Pay";
        myUniversity.sortEmployee(condition,status);
        myUniversity.displayAllMembers();
        myUniversity.sortEmployee(condition,status1);
        myUniversity.displayAllMembers();
        System.out.println("Sorted  member by natural ordering.");
        myUniversity.sortEmployee();
        myUniversity.displayAllMembers();
        myUniversity.sortEmployee(true);
        myUniversity.displayAllMembers();
        myUniversity.sortEmployee(false);
        myUniversity.displayAllMembers();
    }
}
   
