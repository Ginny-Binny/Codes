import java.util.HashMap;
import java.util.Scanner;

public class EmployeeManagementSystem {
    public static void main(String[] args) {
        HashMap<Integer, Employee> employeeMap = new HashMap<>();
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("Employee Management System");
            System.out.println("1. Add Employee");
            System.out.println("2. Retrieve Employee Details");
            System.out.println("3. Update Employee Details");
            System.out.println("4. Remove Employee");
            System.out.println("5. Display All Employees");
            System.out.println("6. Exit");
            System.out.print("Enter your choice: ");
            int choice = scanner.nextInt();
            scanner.nextLine(); // Consume the newline character

            switch (choice) {
                case 1:
                    System.out.print("Enter Employee ID: ");
                    int employeeId = scanner.nextInt();
                    scanner.nextLine(); // Consume the newline character
                    System.out.print("Enter Employee Name: ");
                    String name = scanner.nextLine();
                    System.out.print("Enter Employee Designation: ");
                    String designation = scanner.nextLine();
                    System.out.print("Enter Employee Salary: ");
                    double salary = scanner.nextDouble();
                    scanner.nextLine(); // Consume the newline character

                    Employee newEmployee = new Employee(name, designation, salary);
                    employeeMap.put(employeeId, newEmployee);
                    System.out.println("Employee added successfully.");
                    System.out.println();
                    break;
                case 2:
                    System.out.print("Enter Employee ID: ");
                    int empId = scanner.nextInt();
                    scanner.nextLine(); // Consume the newline character

                    if (employeeMap.containsKey(empId)) {
                        Employee employee = employeeMap.get(empId);
                        System.out.println("Employee Details:");
                        System.out.println("ID: " + empId);
                        System.out.println("Name: " + employee.getName());
                        System.out.println("Designation: " + employee.getDesignation());
                        System.out.println("Salary: " + employee.getSalary());
                    } else {
                        System.out.println("Employee not found.");
                    }
                    System.out.println();
                    break;
                case 3:
                    System.out.print("Enter Employee ID: ");
                    int empID = scanner.nextInt();
                    scanner.nextLine(); // Consume the newline character

                    if (employeeMap.containsKey(empID)) {
                        Employee emp = employeeMap.get(empID);
                        System.out.print("Enter New Employee Name: ");
                        String newName = scanner.nextLine();
                        System.out.print("Enter New Employee Designation: ");
                        String newDesignation = scanner.nextLine();
                        System.out.print("Enter New Employee Salary: ");
                        double newSalary = scanner.nextDouble();
                        scanner.nextLine(); // Consume the newline character

                        emp.setName(newName);
                        emp.setDesignation(newDesignation);
                        emp.setSalary(newSalary);
                        System.out.println("Employee details updated successfully.");
                    } else {
                        System.out.println("Employee not found.");
                    }
                    System.out.println();
                    break;
                case 4:
                    System.out.print("Enter Employee ID: ");
                    int empIdToRemove = scanner.nextInt();
                    scanner.nextLine(); // Consume the newline character

                    if (employeeMap.containsKey(empIdToRemove)) {
                        employeeMap.remove(empIdToRemove);
                        System.out.println("Employee removed successfully.");
                    } else {
                        System.out.println("Employee not found.");
                    }
                    System.out.println();
                    break;
                case 5:
                    System.out.println("List of Employees:");
                    for (int empIDKey : employeeMap.keySet()) {
                        Employee emp = employeeMap.get(empIDKey);
                        System.out.println("Employee ID: " + empIDKey);
                        System.out.println("Name:Certainly! Here's the code with proper indentation:
