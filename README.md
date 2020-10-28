# Welcome to Joshua McNew's ePortfolio

## Professional Self-Assessment

- *Collaborating in a team environment*
    - Text
- *Communicating to stakeholders*
    - Text
- *Data structures and algorithms*
    - Text
- *Software engineering and databases*
    - Text
- *Security*
    - Text

## Code Review
The goal of this code review is to explain how the code for each of my chosen artifact's function as well as how and why I plan to enhance them.
- [Code Review](www.test.com).

# Artifact 1 - Software Design and Engineering

**Artifact 1 Enhanced Code**
```java
package zooauthenticationsystem;
import java.security.MessageDigest;
import java.util.Scanner;
//Author Joshua McNew

public class ZooAuthenticationSystem {

    public static void main(String[] args) throws Exception {
        
	//Initializes scanner 
        Scanner scan = new Scanner(System.in);
        
        //An array that accesses credentials "I skipped ahead on Zybooks"
        final int credNumber = 8;
        String[] userCred = new String[credNumber];
        String[] passCred = new String[credNumber];
       
        String username = "";
        String password = "";
        String hashedPass = "";
        String logOut = "";
        
        //Initialize variables for loop
        int i = 0;
        int u = 0;
        int user = 0;
        boolean matched = false;
        
        ZooUserRoles userInput = new ZooUserRoles();
        
        //Username credentials array
        userCred[0] = "Joshua.M";
        userCred[1] = "Bethony.M";
        userCred[2] = "griffin.keyes";
        userCred[3] = "rosario.dawson";
        userCred[4] = "bernie.gorilla";
        userCred[5] = "donald.monkey";
        userCred[6] = "jerome.grizzlybear";
        userCred[7] = "bruce.grizzlybear";
        
        //Password credentials array
        passCred[0] = "5ac5355b84894ede056ab81b324c4675";
        passCred[1] = "2b1973d2105a8e955c9e4a9a6140ceff";
        passCred[2] = "108de81c31bf9c622f76876b74e9285f";
        passCred[3] = "3e34baa4ee2ff767af8c120a496742b5";
        passCred[4] = "a584efafa8f9ea7fe5cf18442f32b07b";
        passCred[5] = "17b1b7d8a706696ed220bc414f729ad3";
        passCred[6] = "3adea92111e6307f8f2aae4721e77900";
        passCred[7] = "0d107d09f5bbe40cade3de5c71e9e9b7";
        
        
        //Prompts the user for their username and password and allows them to quit at anytime
        System.out.println("Welcome, please login!");
        System.out.println("Enter \"quit\" at anytime to exit or type \"logout\" when done.");
        
        System.out.print("Enter username: ");
        username = scan.nextLine();
        
        if (username.equals("quit")) {
            System.out.println("You have chose to quit the program, Goodbye.");
            scan.close();
            return; }
        
        System.out.print("Enter password: ");
        password = scan.nextLine();
        
        if (password.equals("quit")) {
            System.out.println("You have chose to quit the program, Goodbye.");
            scan.close();
            return; }
        
        //For loop that limits attempts to 3 and converts using MD5
        for (i = 0; i < 3; ++i) {

            for (u = 0; u < credNumber; ++u) {
                
                if (username.equals(userCred[u])) {
                    String original = password;  //Given MD5 code
                    MessageDigest md = MessageDigest.getInstance("MD5");
                    md.update(original.getBytes());
                    byte[] digest = md.digest();
                    StringBuffer sb = new StringBuffer();
                    
                    for (byte b : digest) {
                        sb.append(String.format("%02x", b & 0xff)); }

                    matched = true;
                    user = u;
                    hashedPass = sb.toString();    
                }   
            }
            //Compares user credentials and exits after 3 attempts
            if (!hashedPass.equals(passCred[user])) {
                matched = false;
                
                if (i < 2) {
                    System.out.println("Credentials could not be validated. ");
                    System.out.print("Enter username: ");
                    username = scan.nextLine();
                    
                    if (username.equals("quit")) {
                        System.out.println("You typed quit, Goodbye.");
                        break; }
                    
                    System.out.print("Enter password: ");
                    password = scan.nextLine();
                    
                    if (password.equals("quit")) {
                        System.out.println("You typed quit, Goodbye.");
                        break; }
                }
                if ((i == 2) && (!matched)) {
                    System.out.println("Too many failed attempts. Goodbye.");
                    break; }
            }
            else {
                userInput.setUser(username); //Sets username to select from role file
                userInput.getRole(); //Imports role from role file
            
                //While loop that allows the user to logout
                while (true) {
                    System.out.print("Please Type \"logout\" to exit or \"role\" to reprint user role\n");
                    logOut = scan.nextLine();
                    
                    

                    if (logOut.equals("logout")) {
                        System.out.print("See ya next time, Goodbye!");
                        return; }
                    else if (logOut.equals("role")) {
                    	userInput.getRole();
                        }
                    else {
                    	continue;
                    }
                }
            }
            scan.close();
        }
    }
}
```

# Artifact 2 - Algorithms and Data Structures

**Artifact 1**
```c++

```

# Artifact 3 - Databases

**Artifact 1**
```python

```
