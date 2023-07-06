import java.sql.*;

public class ProductInventoryManagement {
    public static void main(String[] args) {
        try {
            // Step 1: Load the JDBC driver
            Class.forName("com.mysql.jdbc.Driver");

            // Step 2: Establish a connection to the database
            String url = "jdbc:mysql://localhost:3306/inventorydb";
            String username = "username";
            String password = "password";
            Connection connection = DriverManager.getConnection(url, username, password);

            // Step 3: Create a statement object
            Statement statement = connection.createStatement();

            // Step 4: Perform database operations
            // Add a new product
            String addProductSql = "INSERT INTO products (name, price, quantity) VALUES ('Book', 10.99, 50)";
            statement.executeUpdate(addProductSql);

            // Retrieve product details
            int productId = 1;
            String getProductSql = "SELECT * FROM products WHERE id = " + productId;
            ResultSet resultSet = statement.executeQuery(getProductSql);
            if (resultSet.next()) {
                String name = resultSet.getString("name");
                double price = resultSet.getDouble("price");
                int quantity = resultSet.getInt("quantity");
                System.out.println("Product Details:");
                System.out.println("ID: " + productId);
                System.out.println("Name: " + name);
                System.out.println("Price: $" + price);
                System.out.println("Quantity: " + quantity);
            }

            // Update product price
            double newPrice = 12.99;
            String updatePriceSql = "UPDATE products SET price = " + newPrice + " WHERE id = " + productId;
            statement.executeUpdate(updatePriceSql);

            // Update product quantity
            int newQuantity = 40;
            String updateQuantitySql = "UPDATE products SET quantity = " + newQuantity + " WHERE id = " + productId;
            statement.executeUpdate(updateQuantitySql);

            // Delete a product
            String deleteProductSql = "DELETE FROM products WHERE id = " + productId;
            statement.executeUpdate(deleteProductSql);

            // Display list of all products
            String getAllProductsSql = "SELECT * FROM products";
            ResultSet allProductsResultSet = statement.executeQuery(getAllProductsSql);
            System.out.println("List of Products:");
            while (allProductsResultSet.next()) {
                int id = allProductsResultSet.getInt("id");
                String productName = allProductsResultSet.getString("name");
                double productPrice = allProductsResultSet.getDouble("price");
                int productQuantity = allProductsResultSet.getInt("quantity");
                System.out.println("ID: " + id);
                System.out.println("Name: " + productName);
                System.out.println("Price: $" + productPrice);
                System.out.println("Quantity: " + productQuantity);
                System.out.println("--------------------");
            }

            // Step 5: Close the ResultSet, Statement, and Connection objects
            allProductsResultSet.close();
            statement.close();
            connection.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
