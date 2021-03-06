# Welcome to Joshua McNew's ePortfolio

## Professional Self-Assessment

The overall goal of this ePortfolio is to demonstrate the knowledge I have gained throughout my journey in the Computer Science program offered by Southern New Hampshire University. I have provided a code review that explains how the code for each of my chosen artifact's function as well as how and why I plan to enhance them. I created a narrative for each artifact that explains why I included them in this ePortfolio as well as a reflection on the process I used to develop/enhance them, the challenges I faced, and what I learned throughout the whole process. I also explain how the code for each program could be structured better and how I could improve the comments to improve the understandability of the programs. This professional assessment is a reflection on this capstone and my overall experience in the Computer Science program. I will showcase my strengths in collaborating in a team environment, communicating to stakeholders, data structures and algorithms, software engineering and databases, security, and development using multiple programming languages. 

- **Collaborating in a team environment**
    - My experience collaborating in a team environment has been very fulfilling and has given me many skills that I plan to use going forward. I have gained a wealth of knowledge about the software development life cycle (SDLC) and the benefits of Agile development in regards to iterative software development. I have explored GitHub and Bitbucket on this journey and have learned the importance of version control in software development and how branching and merging allows developers to work collaboratively while isolating their work from affecting other developers. Utilizing these skills and many others I have gained; I will be able to effectively work and collaborate within a team environment locally or remotely.

- **Communicating to stakeholders**
    - Communicating to stakeholders is an extremely important skill to have in order to be successful in software development and this Computer Science program has given me many different skills that I will continue to use going forward. I have learned that a Request for Information (RFI) is generally used to help businesses collect information about suppliers to see if they would be able to solve their problems or offer better solutions to help a business become more efficient. As a software developer who is looking for business opportunities, it is important to figure out a way to stand out from your competition. You should try to sell yourself by explaining how you could help a business achieve their goals. I have also learned how important it is to build relationships and have effective conversations about a business’s needs before, during, and after development so you properly understand the requirements and deliver the best product possible. Overall, it is important for you to win over the business’s trust by proving you can and will get the job done.

- **Data structures and algorithms**
    - Data structures are the fundamentals of what makes a program work. I have learned how using proper data structures allows a programmer or user to manipulate data quickly and efficiently. Algorithms are the backbone of what makes a program work the way it does. Using the proper data structure and the most efficient algorithms will allow a program to run at its full potential. Throughout this program I was able to showcase my strengths and understanding of how and why data structures and algorithms are necessary for any complex software system to run efficiently. 

- **Software engineering and databases**
    - Databases are the backbone of any piece of software that stores data. In this Computer Science program, I have gained the ability to create databases in SQL and MongoDB and how to efficiently manage and manipulate data using CRUD functionalities. I have also learned the necessity of being proficient with DDL (Data Definition Language) and DML (Data Manipulation Language). The ability to effectively manipulate a database is crucial when it comes to database management and I believe I have acquired a set of skills that will allow me to efficiently create and manage databases.

- **Security**
    - One of the most crucial factors in software development is security. As an up and coming programmer, I have learned that it is extremely important to not only rely on compiler warnings and static analysis tools to find errors and bugs within a program. Visually inspecting code can go along way when it comes to identifying and fixing bugs that could lead to security vulnerabilities. I have learned the importance of how and why to mitigate dangling pointers, integer and buffer overflows, and why to always validate user input. Not doing so could allow malicious attackers to reference arbitrary code that could pose serious security threats such as data corruption/manipulation, segfaults or program crashes, and even allow them to gain full control of a system. Developing code with a security first mindset will ensure I create safe and secure software.

The following artifacts and their accompanying narratives will demonstrate my competency and understanding of Software Engineering/Design, Data Structures and Algorithms, Databases, and most importantly Security. 

## Code Review
The goal of this code review is to explain how the code for each of my chosen artifact's function as well as how and why I plan to enhance them.
- [Click to view Code Review](https://youtu.be/kx_hbfEpFe0).

# Artifact One - Software Design and Engineering

**Artifact One Narrative**

The artifact I decided to enhance for the Software Engineering/Design aspect of the ePortfolio is the final project I developed in the IT 145 Foundation in Application Development course I took in January of 2019. This artifact is written in Java and is a Zoo Authentication System that is responsible for displaying the role or job description of an employee, given they have the correct username and password. The program first prompts the user for their username and password. The password is then converted using a message digest five (MD5) hash and validated against the stored hashed password. The user has three attempts to enter the correct credentials, otherwise the program will exit. If the user enters the correct credentials, they will be given access to their correct role and their corresponding role information will be displayed. Finally, the user has an option to log out and exit the program if they wish.

I chose this artifact because the enhancements I made helped me demonstrate the mastery in some of the skills I have learned throughout my journey in this computer science program. I proved my ability to use well-founded/innovative techniques, skills, and tools for the purpose of implementing computer solutions that deliver value and accomplish industry-specific goals. I also demonstrated my ability to mitigate design flaws by exposing and providing solutions to potential security vulnerabilities that could leave the program open for attack or cause memory errors. I certainly met my course objectives for this enhancement because I improved the functionality of this program by adding an extra feature to re-print the user’s role, fixed a resource leak that could lead to memory errors, improved the overall quality of the code by using proper naming conventions, straightening up the structure of the code, and adding sophisticated comments that help explain how the code functions. Going forward I would like to remove the password and username credentials out of the program and into a separate file to increase the overall security of the program.

To add the functionality that allows a user to re-print their role wasn’t to challenging. I had to add an else if to the if else statement inside of the while loop at the end of the program that called the getRole() function if the user typed “role”.  The biggest challenged I faced when enhancing this program was figuring out when and where to close the scanner to fix the resource leak. I tried to close it in a few different places within the code, but the program would eventually crash when it required user input after the scanner was closed. I eventually figured out that if I closed the scanner at the end of the first for loop and when the user logs out the program functioned properly and let the user continue to re-print their role or logout if they wish. Improving the comments and straightening up the structure of the code was pretty straightforward and fairly easy to accomplish because I now have a better understanding of coding best practices in regards to naming conventions, comments, and how code should be structured to improve readability and understandability.

**Artifact One Enhanced Code**
- [Link to full project code](https://github.com/iMcNeW/iMcNeW.github.io/tree/master/Artifact%20One/ZooAuthenticationSystem/src/zooauthenticationsystem).


<details>
    <summary><b>ZooAuthenticationSystem.Java (click to view)</b></summary>

```java
// Author Joshua McNew

package zooauthenticationsystem;
import java.security.MessageDigest;
import java.util.Scanner;


public class ZooAuthenticationSystem {

    public static void main(String[] args) throws Exception {
        
    	// Initializes scanner 
        Scanner scan = new Scanner(System.in);
        
        // An array that accesses credentials and define variables
        final int credNumber = 8;
        String[] userCred = new String[credNumber];
        String[] passCred = new String[credNumber];
       
        String username = "";
        String password = "";
        String hashedPass = "";
        String logOut = "";
        
        // Initialize variables for loop
        int i = 0;
        int u = 0;
        int user = 0;
        boolean matched = false;
        
        // Set variable to be used in the ZooUserRoles class
        ZooUserRoles userInput = new ZooUserRoles();
        
        // Username credentials array
        userCred[0] = "Joshua.M";
        userCred[1] = "Bethony.M";
        userCred[2] = "griffin.keyes";
        userCred[3] = "rosario.dawson";
        userCred[4] = "bernie.gorilla";
        userCred[5] = "donald.monkey";
        userCred[6] = "jerome.grizzlybear";
        userCred[7] = "bruce.grizzlybear";
        
        // Password credentials array
        passCred[0] = "5ac5355b84894ede056ab81b324c4675";
        passCred[1] = "2b1973d2105a8e955c9e4a9a6140ceff";
        passCred[2] = "108de81c31bf9c622f76876b74e9285f";
        passCred[3] = "3e34baa4ee2ff767af8c120a496742b5";
        passCred[4] = "a584efafa8f9ea7fe5cf18442f32b07b";
        passCred[5] = "17b1b7d8a706696ed220bc414f729ad3";
        passCred[6] = "3adea92111e6307f8f2aae4721e77900";
        passCred[7] = "0d107d09f5bbe40cade3de5c71e9e9b7";
        
        
        // Prompts the user for their username and password and allows them to quit at anytime
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
        
        // For loop that limits login attempts to 3 and converts password using MD5 hash
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
            
            // Compares user credentials and exits after 3 unsuccessful login attempts
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
            
            // Sets username to select from role file and imports the description
            else {
                userInput.setUser(username);
                userInput.getRole();
            
                // While loop that allows the user to logout or reprint their role
                while (true) {
                    System.out.print("Please Type \"logout\" to exit or \"role\" to reprint user role\n");
                    logOut = scan.nextLine();
                    
                    if (logOut.equals("logout")) {
                        System.out.print("See ya next time, Goodbye!");
                        scan.close();
                        return;
                    }
                    else if (logOut.equals("role")) {
                    	userInput.getRole();
                    }
                    else {
                    	continue;
                    }
                }
            }
        }
    
    // Close scanner to prevent resource leak
    scan.close();
    }
}
```
</details>

<details>
<summary><b>ZooUserRoles.Java (click to view)</b></summary>

```java
// Author Joshua McNew

package zooauthenticationsystem;

class ZooUserRoles {
	
    // Creates private Strings role and user
    private String role;
    private String user;

    public void setUser(String userInput) {
        user = userInput;
    }
    
    // Switch statement that holds all of the given credentials
    public String getRole() {
        switch (user) {
            case "Joshua.M":
                role = "author";
                System.out.println("You are the author of this program, congratulations!\n");
                break;
            case "Bethony.M":
                role = "wife";
                System.out.println("Hey I hope my wife doesn't see this.\n");
                break;
            case "griffin.keyes":
            case "donald.monkey":
                role = "zookeeper";
                System.out.println("Hello, Zookeeper!");
                System.out.print("As zookeeper, you have access to all of the animals' information and their daily monitoring logs.\n");
                System.out.println("This allows you to track their feeding habits, habitat conditions, and general welfare.\n");
                break;
            case "rosario.dawson":
            case "bruce.grizzlybear":
                role = "admin";
                System.out.println("Hello, System Admin!");
                System.out.print("As administrator, you have access to the zoo's main computer system.\n");
                System.out.println("This allows you to monitor users in the system and their roles.\n");
                break;
            case "bernie.gorilla":
            case "jerome.grizzlybear":
                role = "veterinarian";
                System.out.println("Hello, Veterinarian");
                System.out.print("As veterinarian, you have access to all of the animals' health records.\n");
                System.out.println("This allows you to view each animal's medical history and current treatments/illnesses (if any), and to maintain a vaccination log.\n");
                break;
            default:
                break; 
        }
        
    // Returns matched role
    return role;
    }
}
```
</details>

# Artifact Two - Algorithms and Data Structures

**Artifact Two Narrative**

The artifact that I enhanced for the Algorithms and Data Structures aspect of the ePortfolio is a culmination of four different programs I developed in the CS 260 Data Structures and Algorithms course in May of 2019. These four programs are written in C++ and each have their own specific data structure and utilize different algorithms to analyze large amounts of data quickly and efficiently, in regards to searching, sorting, adding, and removing data from an Excel document.

The first program (LinkedList.cpp) utilizes a linked-list data structure to organize data from a .csv file. Linked lists can basically be summed up as a straight line of data that has pointers connecting to the next node and sometimes to the node before it depending if you’re using a singly or doubly-linked list. The second program (VectorSorting.cpp) utilizes two different sorting algorithms, a selection sort and a quicksort of a vector of bids loaded from a .csv file. Vectors are basically a building block of data structures that are ordered in a specific way and can be accessed using specific commands. The third program (HashTable.cpp) utilizes a hash table data structure which is a “data structure that stores unordered items by mapping (or hashing) each item to a location in an array (or vector)” (Lysecky, 2017). It uses a hashing algorithm to increase the performance of the program by quickly searching, inserting and removing an item from a list. The fourth and final program (BinarySearchTree.cpp) utilizes a binary tree algorithm to manage data from a .csv file. Binary tree algorithms that allow you to manage an extremely large tree with millions of nodes quickly and efficiently.

I chose this artifact because the enhancements I made helped demonstrate the mastery in some of the skills I have learned throughout my journey in this computer science program. I proved my ability to design and evaluate computing solutions using four unique data structures that utilize algorithms to analyze large amounts of data quickly and efficiently, in regards to searching, sorting, adding, and removing data from an Excel document. I also demonstrated my ability to improve the efficiency of four separate programs by expanding their complexity into one fully functional program. I certainly met my course objectives for this enhancement because I improved the functionality of this program by combining all four programs into one fully functional program with an intuitive main menu. I also removed a few unused variables, deallocated allocated memory that could lead to potential security vulnerabilities, improved the overall quality of the code by using proper naming conventions, straightening up the structure of the code, and adding sophisticated comments that help explain how the code functions.

To enhance this artifact, I converted all four of these programs into one program that has a main menu that gives the user an option to test out each data structure and algorithm. When analyzing these programs, I realized they all utilize a couple of the same methods, structures, and variables to function. I took all of these sections of code out of each program and put them into a separate .hpp header file so all of the programs can use them to function, which drastically reduced the amount of duplicate code between the files. It was challenging to convert each program into a functional .hpp file, but I eventually had to give each program a unique main method name in order to call them from the main menu. The biggest challenge was allowing the user to create, search, and remove a bid of their choice. The program was hard coded to perform these operations on a specific bid, but after removing this from the code and developing logic that allows a user to enter an ID, the program is much more efficient and runs flawlessly. Finally, I created the main menu .cpp file, which I used to connect all of the .hpp files together. The main menu greets the user and asks them to choose which algorithm they would like to test. The program then calls one of the four programs I mentioned above, depending on which option they choose.

These enhancements were pretty intense, but I completed something very similar in a course I took some time a while back and I believe this program is much more efficient and usable than it was before. I’d say the biggest lesson learned from this enhancement is that you can pretty much combine any program into one as long as you include a main menu that can call them. I find this much more efficient than developing one long C++ file that contains all of the required code. Having the four data structures and algorithms in separate files makes them much more efficient, readable, and understandable.

**References**
- Lysecky, R. (2017, August). CS-260: Data Structures


**Artifact Two Enhanced Code** 
- Please view full program. [Link to full project code](https://github.com/iMcNeW/iMcNeW.github.io/tree/master/Artifact%20Two/src).

<details>
    <summary><b>Artifact2.cpp (click to view)</b></summary>

```c++
//============================================================================
// Name        : Artifact2.cpp
// Author      : Joshua McNew
// Version     : 1.0
// Copyright   : Copyright © 2017 SNHU COCE
// Description : Artifact 2 Algorithm Main Display C++, Ansi-style
//============================================================================
#include <algorithm>
#include <iostream>
#include <time.h>

// Header files for the four different data structures and algorithms
#include "BinarySearchTree.hpp"
#include "HashTable.hpp"
#include "LinkedList.hpp"
#include "VectorSorting.hpp"
#include "Artifact2.hpp"
using namespace std;

class Artifact2{
};

// Main method - Display menu that allows a user to choose an algorithm or exit using a switch case statement
int main(){
	cout << "Welcome to my algorithm testing program! " << endl <<endl;
		int choice = 0;
		while ( choice != 9) {
		cout << "Please select an algorithm to begin testing!" << endl << endl;
		cout << "1. Hash Table Algorithm" << endl;
		cout << "2. Vector Sorting Algorithm" << endl;
		cout << "3. Linked List Algorithm" << endl;
		cout << "4. Binary Search Tree Algorithm" << endl;
		cout << "9. Exit System: " << endl << endl;
		cout << "Enter choice: ";
		cin >> choice;

		switch (choice) {
			case 1:
				hashMain();
				break;
			case 2:
				vectorMain();
				break;
			case 3:
				linkedMain();
				break;
			case 4:
				binaryMain();
				break;
			case 9:
				if(choice == 9){
					cout << "Thank you for testing my Algorithm program, Good bye!" << endl;
				}
				break;
			default:
				if(choice != true){
					cout<<"Please insert the correct option."<<endl;
				}
				break;
		}
}
return 0;
}
```
</details>

<details>
    <summary><b>Artifact2.hpp (click to view)</b></summary>

```c++
//============================================================================
// Name        : Artifact2.hpp
// Author      : Joshua McNew
// Version     : 1.0
// Copyright   : Copyright © 2017 SNHU COCE
// Description : Artifact2 hpp file C++, Ansi-style
//============================================================================

#ifndef Artifact2_hpp_
#define Artifact2_hpp_
#include <iostream>
#include <time.h>
#include <algorithm>
#include <string>

#include "CSVparser.hpp"

using namespace std;

// Shared methods and functions used by all of the data structures and algorithms

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

// Forward declarations
double strToDouble(string str, char ch);

// Structure that holds bid information
struct Bid {
    string bidId; // unique identifier
    string title;
    string fund;
    double amount;
    Bid() {
        amount = 0.0;
    }
};

/**
 * Prompt user for bid information using console (std::in)
 *
 * @return Bid struct containing the bid info
 */
Bid getBid() {
    Bid bid;

    cout << "Enter Id: ";
    cin.ignore();
    getline(cin, bid.bidId);

    cout << "Enter title: ";
    getline(cin, bid.title);

    cout << "Enter fund: ";
    cin >> bid.fund;

    cout << "Enter amount: ";
    cin.ignore();
    string strAmount;
    getline(cin, strAmount);
    bid.amount = strToDouble(strAmount, '$');

    return bid;
}

/**
 * Simple C function to convert a string to a double
 * after stripping out unwanted char
 *
 * credit: http://stackoverflow.com/a/24875936
 *
 * @param ch The character to strip out of the bid amount in the csv file "$"
 */
double strToDouble(string str, char ch) {
    str.erase(remove(str.begin(), str.end(), ch), str.end());
    return atof(str.c_str());
}

/**
 * Display the bid information to the console (std::out)
 *
 * @param bid struct containing the bid info
 */
void displayBid(Bid bid) {
    cout << bid.bidId << ": " << bid.title << " | " << bid.amount << " | "
            << bid.fund << endl;
    return;
}

#endif
```
</details>

# Artifact Three - Databases

**Artifact Three Narrative**

The artifact that I enhanced for the databases aspect of the ePortfolio is also a culmination of four different programs written in Python that I developed in the CS 340 Advanced Programming Concepts course in July 2020. I developed these four programs to complete Milestone One of this course and they are responsible for implementing the fundamental operations of create, read, update, and delete (CRUD) on a document collection inside of a MongoDB database. For this assignment, I was not sure if all the operations were supposed to be in one Python file. I tried forever to get it to work inside of one, but ultimately could not figure out how to implement it and eventually had to create a separate Python file for each CRUD operation. Each of these programs perform their specific CRUD operation on a specific hard-coded document inside of the database.
	
I chose this artifact because the enhancements I made helped me demonstrate the mastery in some of the skills I have learned throughout my journey in this computer science program. I proved my ability to use well-founded and innovative techniques to develop a secure program that allows a user to perform CRUD operations on a document inside of a MongoDB document database. I certainly met my course objectives for this enhancement because I demonstrated my ability to improve the efficiency of four separate programs by expanding their complexity and converting them into one fully functional program that has an intuitive main menu that allows a user to perform CRUD operations on a document of their choosing. I ensured the program validated and converted user input because not doing so could lead to potential security vulnerabilities. I improved the overall quality of the code by using proper naming conventions, straightening up the structure of the code, and adding sophisticated comments that help explain how the code functions. These enhancements made the program much more efficient, secure, and understandable from a programmer's point of view. 

To enhance this artifact, I successfully converted all four of these programs into one program that has a main menu that gives the user an option to perform CRUD operations on a document of their choosing. The user is able to create their own document, search for a specific document, update specific documents, and delete specific documents using the documents ID. I’d say the most challenging part of this enhancement was actually allowing the user to create and update a document because these two methods were hard coded to perform these operations on a specific document before, all I had to do was run the program. After combining all four programs, I decided the best option was to continually prompt the user to enter the required information, store the input in a variable, then either create or update the document. After some research on Python, I learned that raw_input() is a secure function that converts a user’s input into the proper format so arbitrary code cannot be injected into the program. I utilized this secure alternative to ensure the program was secure from injection. Coding the main menu was straightforward and not too difficult to implement, as I have completed this task in Java and C++ before. 


**Artifact Three Enhanced Code**
- [Link to full project code](https://github.com/iMcNeW/iMcNeW.github.io/tree/master/Artifact%20Three).

<details>
    <summary><b>ArtifactThree.py (click to view)</b></summary>

```python
import json
import pprint
from bson import json_util
from pymongo import MongoClient

# Establish connection to MongoClient to utilize MongoDB
connection = MongoClient('localhost', 27017)
db = connection['city']
collection = db['inspections']

# Create operation - Allows you to create a new document
def create_new_document():
  print("Enter id")
  id = str(raw_input())
  print("Enter certificate number")
  cert = str(raw_input())
  print("Enter business name")
  business = str(raw_input())
  print("Enter date")
  date = str(raw_input())
  print("Enter result")
  result = str(raw_input())
  print("Enter sector")
  sector = str(raw_input())
  print("Enter address")
  print("Enter city")
  city = str(raw_input())
  print("Enter zip")
  zip = str(raw_input())
  print("Enter street")
  street = str(raw_input())
  print("Enter number")
  number = str(raw_input())
  try:
    inspections_data = {
      "id" : id,
      "certificate_number" : cert,
      "business_name" : business,
      "date" : date,
      "result" : result,
      "sector" : sector,
      "address" : {
      "city" : city,
      "zip" : zip,
      "street" : street,
      "number" : number
      }
    }
    result = collection.insert_one(inspections_data)
    print('Record Succesfully Added: {0}'.format(result.inserted_id))
    
    if inspections_data == True:
      print(False)
    else:
      print(True)
    
  except ValidationError as ve:
      abort(400, str(ve))
      return result

# Read operation - Allows you to search and display a document
def read_document():
  try:
    print("Enter ID")
    ID = str(raw_input())
    inspections_data = collection.find_one({"id" : ID})
    
    if inspections_data == None:
        print("Record not found")
    else:
        print("Record found\n")
        print("Current record details for " + ID)
        pprint.pprint(inspections_data)
  
  except ValidationError as ve:
    abort(400, str(ve))
    return result

# Update operation - Allows you to update an existing document
def update_document():
  print("Enter ID")
  ID = str(raw_input())
  print("\nCurrent record details for " + ID)
  inspections_data = collection.find_one({"id" : ID})
  pprint.pprint(inspections_data)
    
  print("\nWould you like to update this record? (Y or N)")
  
  while True:
    choice = str(raw_input())
    
    if choice == "Y":
      print("Enter certificate number")
      cert = str(raw_input())
      print("Enter business name")
      business = str(raw_input())
      print("Enter date")
      date = str(raw_input())
      print("Enter result")
      result = str(raw_input())
      print("Enter sector")
      sector = str(raw_input())
      print("Enter address")
      print("Enter city")
      city = str(raw_input())
      print("Enter zip")
      zip = str(raw_input())
      print("Enter street")
      street = str(raw_input())
      print("Enter number")
      number = str(raw_input())
      try:
        collection.update_one({"id" : ID}, 
                              {"$set":{"certificate_number" : cert,
                                       "business_name" : business,
                                       "date" : date,
                                       "result" : result,
                                       "sector" : sector,
                                       "address" : {
                                         "city" : city,
                                         "zip" : zip,
                                         "street" : street,
                                         "number" : number}}})
      
        inspections_data = collection.find_one({"id" : ID})
        print("\nUpdated record for " + ID)
        pprint.pprint(inspections_data)
        print("Update Succesful\n")
        break
        
      except ValidationError as ve:
        abort(400, str(ve))
        return result
      
    elif choice == "N":
      print("Goodbye! Back to the main menu.")
      break
      
    else:
      print("\nInvalid Selection, enter Y or N!\n")

# Delete operation - Allows you to delete an existing document
def delete_document():
  print("Enter ID")
  ID = str(raw_input())
  print("\nCurrent record details for " + ID)
  inspections_data = collection.find_one({"id" : ID})
  pprint.pprint(inspections_data)
    
  print("\nWould you like to delete this record? (Y or N)")
  
  while True:
    choice = str(raw_input())
    
    if choice == "Y":
      try:
        if inspections_data == None:
          print("ID not found. Please try again\n")
          break
        else:
          collection.delete_one({"id" : ID})
          print("Inspection Data Deleted Succesfully!")
          break

      except ValidationError as ve:
        abort(400, str(ve))
        return result

    elif choice == "N":
      print("Goodbye! Back to the main menu.")
      break

    else:
      print("\nInvalid Selection, enter Y or N!\n")

# Main menu - Allows a user to choose one of the CRUD operations
def mainMenu():
  while True:
    selection = str(raw_input(
      '\nPlease select an option below: '
      '\n1 Create a new record.'
      '\n2 Search and display record by id.'
      '\n3 Update record by id.'
      '\n4 Delete record by id.'
      '\n9 Quit\n\n'))
      
    if selection == '1':
      create_new_document()
    elif selection == '2':
      read_document()
    elif selection == '3':
      update_document()
    elif selection == '4':
      delete_document()
    elif selection == '9':
      quit()
    else:
      print('\nInvalid selection! \n')
      

mainMenu()

```
</details>

