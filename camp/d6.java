import java.sql.*;

public class StudentDatabaseManagement {
    public static void main(String[] args) {
        try {
            // Step 1: Load the JDBC driver
            Class.forName("com.mysql.jdbc.Driver");

            // Step 2: Establish a connection to the database
            String url = "jdbc:mysql://localhost:3306/studentdb";
            String username = "username";
            String password = "password";
            Connection connection = DriverManager.getConnection(url, username, password);

            // Step 3: Create a statement object
            Statement statement = connection.createStatement();

            // Step 4: Perform database operations
            // Add a new student
            String addStudentSql = "INSERT INTO students (name, roll_number, grade) VALUES ('John Doe', '123', 'A')";
            statement.executeUpdate(addStudentSql);

            // Retrieve student details
            String rollNumber = "123";
            String getStudentSql = "SELECT * FROM students WHERE roll_number = '" + rollNumber + "'";
            ResultSet resultSet = statement.executeQuery(getStudentSql);
            if (resultSet.next()) {
                String name = resultSet.getString("name");
                String grade = resultSet.getString("grade");
                System.out.println("Student Name: " + name);
                System.out.println("Grade: " + grade);
            }

            // Update student grade
            String updateStudentSql = "UPDATE students SET grade = 'B' WHERE roll_number = '" + rollNumber + "'";
            statement.executeUpdate(updateStudentSql);

            // Delete a student
            String deleteStudentSql = "DELETE FROM students WHERE roll_number = '" + rollNumber + "'";
            statement.executeUpdate(deleteStudentSql);

            // Display list of all students
            String getAllStudentsSql = "SELECT * FROM students";
            ResultSet allStudentsResultSet = statement.executeQuery(getAllStudentsSql);
            while (allStudentsResultSet.next()) {
                String studentName = allStudentsResultSet.getString("name");
                String studentRollNumber = allStudentsResultSet.getString("roll_number");
                String studentGrade = allStudentsResultSet.getString("grade");
                System.out.println("Student Name: " + studentName);
                System.out.println("Roll Number: " + studentRollNumber);
                System.out.println("Grade: " + studentGrade);
                System.out.println("--------------------");
            }

            // Step 5: Close the ResultSet, Statement, and Connection objects
            allStudentsResultSet.close();
            statement.close();
            connection.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
