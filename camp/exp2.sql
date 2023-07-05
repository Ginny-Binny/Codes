CREATE TABLE songs(   
    id INT,      title 
VARCHAR(100),     genre VARCHAR(50),     duration INT,     streams  
INT   
);   
INSERT INTO songs (id, title, genre, duration, streams) VALUES (1, 'Song A',  'Pop', 240, 100);   
INSERT INTO songs (id, title, genre, duration, streams) VALUES (2, 'Song B', 'Rock', 320, 200);   
INSERT INTO songs (id, title, genre, duration, streams) VALUES (3, 'Song C', 'Hip Hop', 280, 150);   
INSERT INTO songs (id, title, genre, duration, streams) VALUES (4, 'Song D', 'Pop', 200, 300);   
INSERT INTO songs (id, title, genre, duration, streams) VALUES (5, 'Song E', 'Rock', 180, 250);   
SELECT genre, SUM(streams) AS total_streams FROM songs GROUP BY genre;  

SELECT genre, SUM(streams) AS total_streams FROM songs GROUP BY genre ORDER BY total_streams DESC FETCH FIRST ROW ONLY;

SELECT genre, AVG(duration) AS average_duration FROM songs GROUP BY genre;   


-- Create user roles  
CREATE ROLE SupportAgentRole;  
CREATE ROLE ManagerRole;  
CREATE ROLE AdminRole;  
CREATE ROLE SalesRole;  
  
-- Create tables  
CREATE TABLE Customers (   customer_id INT PRIMARY KEY,   customer_name VARCHAR(50),   email VARCHAR(50),   phone_number 
VARCHAR(20),   address 
VARCHAR(100)  
);   
CREATE TABLE Tickets (   ticket_id INT PRIMARY KEY,   customer_id INT,   agent_id INT,   issue_description TEXT,   status VARCHAR(20),   created_at TIMESTAMP,   updated_at TIMESTAMP,  
  FOREIGN KEY (customer_id) REFERENCES Customers(customer_id)  
);   
CREATE TABLE Employees (   employee_id INT PRIMARY KEY,   employee_name VARCHAR(50),   role VARCHAR(50),   hire_date 
DATE,   salary DECIMAL(10, 2)  
);   
-- Grant privileges to SupportAgentRole  
GRANT SELECT, UPDATE ON Customers TO SupportAgentRole;  
  
-- Revoke privileges from ManagerRole  
REVOKE INSERT, DELETE ON Tickets FROM ManagerRole;  
  
-- Grant all privileges to AdminRole  
GRANT ALL PRIVILEGES ON Employees TO AdminRole;  
  
-- Revoke privileges from SalesRole  
REVOKE ALL PRIVILEGES ON Customers FROM SalesRole;  
  
-- Grant privileges to specific user (SupportUser)  
GRANT SELECT, INSERT, UPDATE ON Tickets TO SupportUser;  
  
