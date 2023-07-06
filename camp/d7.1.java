import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

public class ArithmeticCalculatorServlet extends HttpServlet {

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
        response.setContentType("text/html");

        // Retrieve the input parameters
        String number1Str = request.getParameter("number1");
        String number2Str = request.getParameter("number2");
        String operator = request.getParameter("operator");

        PrintWriter out = response.getWriter();
        out.println("<html><body>");

        try {
            // Parse the numbers
            int number1 = Integer.parseInt(number1Str);
            int number2 = Integer.parseInt(number2Str);

            // Perform the arithmetic operation based on the operator
            int result = 0;
            String operation = "";

            switch (operator) {
                case "+":
                    result = number1 + number2;
                    operation = "Addition";
                    break;
                case "-":
                    result = number1 - number2;
                    operation = "Subtraction";
                    break;
                case "*":
                    result = number1 * number2;
                    operation = "Multiplication";
                    break;
                case "/":
                    if (number2 != 0) {
                        result = number1 / number2;
                        operation = "Division";
                    } else {
                        out.println("<h1>Error: Cannot divide by zero!</h1>");
                        out.println("</body></html>");
                        return;
                    }
                    break;
                default:
                    out.println("<h1>Error: Invalid operator!</h1>");
                    out.println("</body></html>");
                    return;
            }

            // Display the result
            out.println("<h1>" + operation + " Result:</h1>");
            out.println("<p>Number 1: " + number1 + "</p>");
            out.println("<p>Number 2: " + number2 + "</p>");
            out.println("<p>Operator: " + operator + "</p>");
            out.println("<p>Result: " + result + "</p>");

        } catch (NumberFormatException e) {
            // Handle invalid number input
            out.println("<h1>Error: Invalid number format!</h1>");
        }

        out.println("</body></html>");
    }
}
