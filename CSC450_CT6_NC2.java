import java.io.FileInputStream;
import java.io.FileNotFoundException;

class CSC450_CT6_NC2{
    public static void main(String[] args) throws FileNotFoundException {
      // Linux stores a user's home directory path in
      // the environment variable $HOME, Windows in %APPDATA%
      FileInputStream fis =
          new FileInputStream(System.getenv("APPDATA") + args[0]); 
    }
  }
  