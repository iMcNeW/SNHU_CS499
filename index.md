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

# Artifact One - Software Design and Engineering

**Artifact One Narrative**

The artifact I decided to enhance for the Software Engineering/Design aspect of the ePortfolio is the final project I developed in the IT 145 Foundation in Application Development course I took in January of 2019. This artifact is written in Java and is a Zoo Authentication System that is responsible for displaying the role or job description of an employee, given they have the correct username and password. The program first prompts the user for their username and password. The password is then converted using a message digest five (MD5) hash and validated against the stored hashed password. The user has three attempts to enter the correct credentials, otherwise the program will exit. If the user enters the correct credentials, they will be given access to their correct role and their corresponding role information will be displayed. Finally, the user has an option to log out and exit the program if they wish.

I chose this artifact because the enhancements I made helped me demonstrate the mastery in some of the skills I have learned throughout my journey in this computer science program. I proved my ability to use well-founded/innovative techniques, skills, and tools for the purpose of implementing computer solutions that deliver value and accomplish industry-specific goals. I also demonstrated my ability to mitigate design flaws by exposing and providing solutions to potential security vulnerabilities that could leave the program open for attack or cause memory errors. I certainly met my course objectives for this enhancement because I improved the functionality of this program by adding an extra feature to re-print the user’s role, fixed a resource leak that could lead to memory errors, improved the overall quality of the code by using proper naming conventions, straightening up the structure of the code, and adding sophisticated comments that help explain how the code functions.

To add the functionality that allows a user to re-print their role wasn’t to challenging. I had to add an else if to the if else statement inside of the while loop at the end of the program that called the getRole() function if the user typed “role”.  The biggest challenged I faced when enhancing this program was figuring out when and where to close the scanner to fix the resource leak. I tried to close it in a few different places within the code, but the program would eventually crash when it required user input after the scanner was closed. I eventually figured out that if I closed the scanner at the end of the first for loop the program functioned properly and let the user continue to re-print their role or logout if they wish. Improving the comments and straightening up the structure of the code was pretty straightforward and fairly easy to accomplish because I now have a better understanding of coding best practices in regards to naming conventions, comments, and how code should be structured to improve readability and understandability. 

**Artifact One Enhanced Code**
- [Link to full project code](https://github.com/iMcNeW/SNHU_CS499/tree/main/ZooAuthenticationSystem/src/zooauthenticationsystem).

<details>
    <summary>Click to view ZooAuthenticationSystem.Java</summary>
  
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
</details>

# Artifact Two - Algorithms and Data Structures

**Artifact Two Narrative**

The artifact that I enhanced for the Algorithms and Data Structures aspect of the ePortfolio is a culmination of four different programs I developed in the CS 260 Data Structures and Algorithms course in May of 2019. These four programs are written in C++ and each have their own specific data structure and utilize different algorithms to analyze large amounts of data quickly and efficiently, in regards to searching, sorting, adding, and removing data from an Excel document. 

The first program (LinkedList.cpp) utilizes a linked-list data structure to organize data from a .csv file. Linked lists can basically be summed up as a straight line of data that has pointers connecting to the next node and sometimes to the node before it depending if you’re using a singly or doubly-linked list. The second program (VectorSorting.cpp) utilizes two different sorting algorithms, a selection sort and a quicksort of a vector of bids loaded from a .csv file. Vectors are basically a building block of data structures that are ordered in a specific way and can be accessed using specific commands. The third program (HashTable.cpp) utilizes a hash table data structure which is a “data structure that stores unordered items by mapping (or hashing) each item to a location in an array (or vector)” (Lysecky, 2017). It uses a hashing algorithm to increase the performance of the program by quickly searching, inserting and removing an item from a list. The fourth and final program (BinarySearchTree.cpp) utilizes a binary tree algorithm to manage data from a .csv file. Binary tree algorithms that allow you to manage an extremely large tree with millions of nodes quickly and efficiently.

I chose this artifact because the enhancements I made helped demonstrate the mastery in some of the skills I have learned throughout my journey in this computer science program. I proved my ability to design and evaluate computing solutions using four unique data structures that utilize algorithms to analyze large amounts of data quickly and efficiently, in regards to searching, sorting, adding, and removing data from an Excell document. I also demonstrated my ability to improve the efficiency of four separate programs by expanding their complexity into one fully functional program. I certainly met my course objectives for this enhancement because I improved the functionality of this program by combining all four programs into one fully functional program. I also removed a few unused variables, deallocated allocated memory that could lead to potential security vulnerabilities, improved the overall quality of the code by using proper naming conventions, straightening up the structure of the code, and adding sophisticated comments that help explain how the code functions.

To enhance this artifact, I converted all four of these programs into one program that has a main menu that gives the user an option to test out each data structure and algorithm. When analyzing these programs, I realized they all utilize a couple of the same methods, structures, and variables to function. I took all of these sections of code out of each program and put them into a separate .hpp header file so all of the programs can use them to function, which drastically reduced the amount of duplicate code between the files. It was challenging to convert each program into a functional .hpp file. I had to give each program a unique main method name in order to call them from the main menu. The biggest challenge was allowing the user to create, search, and remove a bid of their choice. The program was hard coded to perform these operations on a specific bid, but after removing this from the code and allowing the user to enter an ID, the program is much more efficient and runs flawlessly. Finally, I created the main menu .cpp file, which I used to connect all of the .hpp files together. The main menu greets the user and asks them to choose which algorithm they would like to test. The program then calls one of the four programs I mentioned above, depending on which option they choose. 

These enhancements were pretty intense, but I completed something very similar in a course I took sometime a while back and I believe this program is much more efficient and usable than it was before. I’d say the biggest lesson learned from this enhancement is that you can pretty much combine any program into one as long as you include a main menu that can call them. I find this much more efficient than developing one long C++ file that contains all of the required code. Having the four data structures and algorithms in separate files makes them much more efficient, readable, and understandable. 

**References**
- Lysecky, R. (2017, August). CS-260: Data Structures


**Artifact Two Enhanced Code**
- [Link to full project code](https://github.com/iMcNeW/SNHU_CS499/tree/main/ZooAuthenticationSystem/src/zooauthenticationsystem).

```c++

```

# Artifact Three - Databases

**Artifact Three Narrative**

**Artifact Artifact Three Enhanced Code**
- [Link to full project code](https://github.com/iMcNeW/SNHU_CS499/tree/main/ZooAuthenticationSystem/src/zooauthenticationsystem).

```python

```
