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


