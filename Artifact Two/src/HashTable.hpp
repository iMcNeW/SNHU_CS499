//============================================================================
// Name        : HashTable.cpp
// Author      : Joshua McNew
// Version     : 1.0
// Copyright   : Copyright © 2017 SNHU COCE
// Description : Hash Table Algorithm C++, Ansi-style
//============================================================================

#ifndef HashTable_hpp_
#define HashTable_hpp_
#include <algorithm>
#include <climits>
#include <iostream>
#include <string> // atoi
#include <time.h>
#include "Artifact2.hpp"
#include "CSVparser.hpp"

using namespace std;

//============================================================================
// Global definition visible to all methods and classes
//============================================================================

const unsigned int DEFAULT_SIZE = 179;


//============================================================================
// Hash Table class definition
//============================================================================

// Class containing data members and methods to implement a hash table with chaining.
class HashTable {

private:
    // Define structures to hold bids
	struct Node {
		Bid _bid;
		unsigned _key;
		Node* next;

		Node() {
			_key = UINT_MAX;
			next = nullptr;
		}

		// Define bid
		Node(Bid bid) : Node() {
			_bid = bid;
		}

		// Define key and bid
		Node(unsigned key, Bid bid) : Node() {
			_bid = bid;
			_key = key;
		}
	};

	vector<Node> nodes;

	unsigned hashTblSize = 200;


    unsigned int hash(int key);

// Declare methods
public:
    HashTable();
    virtual ~HashTable();
    void Insert(Bid bid);
    void PrintAll();
    void Remove();
    Bid Search();
};

// Default constructor

HashTable::HashTable() {
    // Initialize the structures used to hold bids
	nodes.resize(hashTblSize);
}




/**
 * Destructor
 */
HashTable::~HashTable() {
    // Implement logic to free storage when class is destroyed
	nodes.erase(nodes.begin());
}

/**
 * Calculate the hash value of a given key.
 * Note that key is specifically defined as
 * unsigned int to prevent undefined results
 * of a negative list index.
 *
 * @param key The key to hash
 * @return The calculated hash
 */
unsigned int HashTable::hash(int key) {
    // Implement logic to calculate a hash value
	return key % hashTblSize;
}

/**
 * Insert a bid
 *
 * @param bid The bid to insert
 */
void HashTable::Insert(Bid bid) {
    // Implement logic to insert a bid
	int key = hash(atoi(bid.bidId.c_str()));

	// Find the node using a key
	Node* oNode = &(nodes.at(key));

	if(oNode != nullptr) {
		// If node is found but empty
		if (oNode->_key == UINT_MAX) {
			oNode->_key = key;
			oNode->_bid = bid;
			oNode->next = nullptr;
		} else {
			// Begin hash chaining to find the next open node
			while(true) {
				if(oNode->next == nullptr) {
					break;
				}
				oNode = oNode->next;
			}
			oNode->next = new Node(key, bid);
		}

	} else {
		Node* nNode = new Node(key,bid);
		nodes.insert(nodes.begin() + key, *nNode);
	}
}

// Print all bids
void HashTable::PrintAll() {
    // Implement logic to print all bids using a for statement
	for(unsigned int i=0; i < nodes.size(); i++){
	  Bid bid =  nodes[i]._bid;
	    cout << bid.bidId << ": " << bid.title << " | " << bid.amount << " | "
	            << bid.fund << endl;
	}

}

/**
 * Remove a bid
 *
 * @param bidId The bid id to search for
 */
void HashTable::Remove() {
	string bidId;
	cout << "Enter the bid id you would like to remove. (97985)" << endl;
	cin >> bidId;
	Bid bid;
    // Implement logic to remove a bid
	int remKey = hash(atoi(bidId.c_str()));
	nodes.erase(nodes.begin() + remKey);
}

/**
 * Search for the specified bidId
 *
 * @param bidId The bid id to search for
 */
Bid HashTable::Search() {

    string bidId;
	cout << "Enter the bid id for to search for a bid. (97985) " << endl;
	cin >> bidId;
    Bid bid;
    // Implement logic to search for and return a bid
    int key = hash(atoi(bidId.c_str()));
    Node* node = &(nodes.at(key));

    // If node matches the key is found
    bool rNode = node != nullptr;

    // If node doesn't exist, return
    if(!rNode || node->_key == UINT_MAX) {
    	return bid;
    }

    bool nmKey = node->_key != UINT_MAX;
    bool sNode = node->_bid.bidId.compare(bidId) == 0;
    if (rNode && nmKey && sNode) {
    	return node->_bid;
    }


    // Continue until a match is found
    while(true) {
    	if (node == nullptr) {
    		break;
    	}
    	if (nmKey && node->_bid.bidId.compare(bidId) == 0) {
    		return node->_bid;
    	}
    	node = node->next;
    }

    return bid;
}

/**
 * Load a CSV file containing bids into a container
 *
 * @return a container holding all the bids read
 */
void loadBids(HashTable* hashTable) {

	string csvPath;
	cout << "Please choose one of the Bid Excel documents below" << endl << endl;

	int cChoice = 0;

	cout << "1 eBid_Monthly_Sales_Dec_2016.csv " << endl;
	cout << "2 eBid_Monthly_Sales.csv " << endl;
	cin >> cChoice;

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

    // Initialize the CSV Parser using the given path
    csv::Parser file = csv::Parser(csvPath);

    // Read and display header row - optional
    vector<string> header = file.getHeader();
    for (auto const& c : header) {
        cout << c << " | ";
    }
    cout << "" << endl;

    try {
        // Loop to read rows of a CSV file
        for (unsigned int i = 0; i < file.rowCount(); i++) {

            // Create a data structure and add to the collection of bids
            Bid bid;
            bid.bidId = file[i][1];
            bid.title = file[i][0];
            bid.fund = file[i][8];
            bid.amount = strToDouble(file[i][4], '$');

            // Push this bid to the end
            hashTable->Insert(bid);
        }
    } catch (csv::Error &e) {
        std::cerr << e.what() << std::endl;
    }
}

// The one and only main() method - Display menu and switch case statement
int hashMain() {

    // Define a timer variable
    clock_t ticks;

    // Define a hash table to hold all the bids
    HashTable* bidTable;

    Bid bid;

    int choice = 0;
    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Load Bids" << endl;
        cout << "  2. Display All Bids" << endl;
        cout << "  3. Find Bid" << endl;
        cout << "  4. Remove Bid" << endl;
        cout << "  9. Return To Main Menu" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            bidTable = new HashTable();

            // Initialize a timer variable before loading bids
            ticks = clock();

            // Complete the method call to load the bids
            loadBids(bidTable);

            // Calculate elapsed time and display result
            ticks = clock() - ticks; // Current clock ticks minus starting clock ticks
            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
            break;

        case 2:
            bidTable->PrintAll();
            break;

        case 3:
            ticks = clock();

            bid = bidTable->Search();

            ticks = clock() - ticks;

            if (!bid.bidId.empty()) {
                displayBid(bid);
            } else {
                cout << "Bid Id " << bid.bidId << " not found." << endl;
            }

            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
            break;

        case 4:
            bidTable->Remove();
            break;
        }
    }

    cout << "Thank you for using my Hash Table Algorithm!" << endl << endl;

    return 0;
}
#endif
