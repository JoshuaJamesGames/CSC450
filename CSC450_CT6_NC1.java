import java.io.Console;
import java.io.IOException;

class CSC450_CT6_NC1{
    public static void main (String args[]) throws IOException {
      Console c = System.console();
      if (c == null) {
        System.err.println("No console.");
        System.exit(1);
      }
   
      String username = c.readLine("Enter your user name: ");
      String password = c.readLine("Enter your password: ");
   
      if (!verify(username, password)) {
        throw new SecurityException("Invalid Credentials");
      }
   
      // User is authorized, continue...
    }
   
    // Dummy verify method, always returns true  
    private static final boolean verify(String username, String password) {
      return true;
    }
  }
  