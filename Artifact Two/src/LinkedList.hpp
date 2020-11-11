//============================================================================
// Name        : LinkedList.cpp
// Author      : Joshua McNew
// Version     : 1.0
// Copyright   : Copyright © 2017 SNHU COCE
// Description : Lab 3-3 Lists and Searching
//============================================================================

#ifndef LinkedList_HPP_
#define LinkedList_HPP_
#include <algorithm>
#include <iostream>
#include <time.h>
#include "Artifact2.hpp"
#include "CSVparser.hpp"

using namespace std;

//============================================================================
// Linked-List class definition
//============================================================================

// Class containing data members and methods to implement a linked-list.
class LinkedList {

private:
    //Internal structure for list entries, housekeeping variables

	// Declares the Bid struct and the Node pointer is set to next
	struct Node {
        Bid _bid;
        Node* next;

        // Constructor for the Node struct and sets next to null
    	Node() {
    		next = nullptr;
        }

    	// Constructor override and initializes _bid
        Node(Bid bid) {
        	_bid = bid;
        	next = nullptr;
        }
    };

    Node* head;
    Node * tail;
    int size = 0;

// Declare methods
public:
    LinkedList();
    virtual ~LinkedList();
    void Append(Bid bid);
    void Prepend(Bid bid);
    void PrintList();
    void Remove();
    Bid Search();
    int Size();
};

// Default constructor
LinkedList::LinkedList() {
    // FIXME (2): Initialize housekeeping variables
	head = nullptr;
	tail = nullptr;
}

// Destructor
LinkedList::~LinkedList() {
}

// Append a new bid to the end of the list
void LinkedList::Append(Bid bid) {
    // Append logic
	Node* node = new Node(bid);
	if(head == nullptr) {
		head = node; // Sets the head as the node if there is nothing is the list.
	} else {
		if(tail != nullptr) {
			tail->next = node; // Sets node to the tail.
		}
	}
	tail = node;
	size++;
}

//Prepend a new bid to the start of the list
void LinkedList::Prepend(Bid bid) {
    // Prepend logic
	Node* prependNode = new Node(bid);
	if(head != nullptr) {
		prependNode->next = head; // Sets prepended node as the head.
	}
	head = prependNode;
	size++;
}

// Simple output of all bids in the list
void LinkedList::PrintList() {
    // Print logic
	Node* currNode = head;
	while(currNode != nullptr) {
		cout << currNode->_bid.bidId << ": "
			 	<<currNode->_bid.title << " | "
			 	<<currNode->_bid.fund << " | "
			 	<<currNode->_bid.amount << " | " << endl;
		currNode = currNode -> next; // Sets next as currNode

	}
}

/**
 * Remove a specified bid
 *
 * @param bidId The bid id to remove from the list
 */
void LinkedList::Remove() {

    // Remove logic
	string bidId;
	cout << "Enter the bid id you would like to remove. (97985)" << endl;
	cin >> bidId;
	if(head != nullptr) {
		if(head->_bid.bidId == bidId) { // Sets the head as the node if there is nothing is the list.
			Node* temp = head->next; // Set temp to the next node.
			delete head;
			head = temp; // Delete and set new head to temp.
		}
	}

	Node* currNode = head; // While loop that loops through the list.
		while(currNode->next != nullptr) {
			if(currNode->next->_bid.bidId == bidId) {
				Node* tempNode = currNode->next; // Create temp node.
				currNode->next = tempNode->next;
				// Delete temp node
				delete tempNode;
				return; // Return back to menu
			}
			currNode = currNode->next;
		}

}

/**
 * Search for the specified bidId
 *
 * @param bidId The bid id to search for
 */
Bid LinkedList::Search() {
    // Search logic
	string bidId;
	cout << "Enter the bid id for to search for a bid. (97985) " << endl;
	cin >> bidId;

	Node* currNode = head;
		while(currNode != nullptr) {
			if(currNode->_bid.bidId == bidId) {
				return currNode->_bid; // Returns bid if match found.
			}
			currNode = currNode -> next; // Sets currNode to next.
		}
		Bid bid;
		return bid;
}

/**
 * Returns the current size (number of elements) in the list
 */
int LinkedList::Size() {
    return size;
}

/**
 * Load a CSV file containing bids into a LinkedList
 *
 * @return a LinkedList containing all the bids read
 */
void loadBids(LinkedList *list) {

	string csvPath;
	cout << "Please choose one of the Bid Excel documents below" << endl << endl;

	int cChoice = 0;

	cout << "1 eBid_Monthly_Sales_Dec_2016.csv " << endl;
	cout << "2 eBid_Monthly_Sales.csv " << endl;
	cin >> cChoice;

	// Path to two separate Excel documents
	if(cChoice == 1){
		csvPath = "eBid_Monthly_Sales_Dec_2016.csv";
	}
	else if(cChoice == 2){
		csvPath = "eBid_Monthly_Sales.csv";
	}
	else {
		cout <<"Invalid Selection!";

	}

	cout << "Loading CSV file " << csvPath << endl;

    // Initialize the CSV Parser
    csv::Parser file = csv::Parser(csvPath);

    try {
        // Loop to read rows of a CSV file
        for (unsigned int i = 0; i < file.rowCount(); i++) {

            // Initialize a bid using data from current row (i)
            Bid bid;
            bid.bidId = file[i][1];
            bid.title = file[i][0];
            bid.fund = file[i][8];
            bid.amount = strToDouble(file[i][4], '$');

            // Add this bid to the end
            list->Append(bid);
        }
    } catch (csv::Error &e) {
        std::cerr << e.what() << std::endl;
    }
}

// The one and only main() method - Display menu and switch case statement
int linkedMain() {

    clock_t ticks;

    LinkedList bidList;

    Bid bid;

    int choice = 0;
    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Enter a Bid" << endl;
        cout << "  2. Load Bids" << endl;
        cout << "  3. Display All Bids" << endl;
        cout << "  4. Find Bid" << endl;
        cout << "  5. Remove Bid" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            bid = getBid();
            bidList.Append(bid);
            displayBid(bid);

            break;

        case 2:
            ticks = clock();

            loadBids(&bidList);

            cout << bidList.Size() << " bids read" << endl;

            // Calculate elapsed time and display result
            ticks = clock() - ticks; // Current clock ticks minus starting clock ticks
            cout << "time: " << ticks << " milliseconds" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

            break;

        case 3:
            bidList.PrintList();

            break;

        case 4:
            ticks = clock();

            bid = bidList.Search();

            ticks = clock() - ticks;

            if (!bid.bidId.empty()) {
                displayBid(bid);
            } else {
            	cout << "Bid Id " << bid.bidId << " not found." << endl;
            }

            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

            break;

        case 5:
            bidList.Remove();

            break;
        }
    }

    cout << "Thank you for using my Linked List Algorithm!" << endl << endl;

    return 0;
}
#endif
