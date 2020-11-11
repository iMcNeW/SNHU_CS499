//============================================================================
// Name        : BinarySearchTree.hpp
// Author      : Joshua McNew
// Version     : 1.0
// Copyright   : Copyright © 2017 SNHU COCE
// Description : Binary Search Algorithm C++, Ansi-style
//============================================================================

#ifndef BinarySearchTree_hpp_
#define BinarySearchTree_hpp_
#include <iostream>
#include <time.h>
#include <algorithm>
#include <string>
#include "Artifact2.hpp"
#include "CSVparser.hpp"

using namespace std;

// Internal structure for tree node
struct Node {
	Bid bid;
	Node* right;
	Node* left;

	Node() {
		right = left = nullptr;
	}

	Node(Bid bid) : Node() {
		this->bid = bid;
	}
};

//============================================================================
// Binary Search Tree class definition
//============================================================================

/**
 * Define a class containing data members and methods to
 * implement a binary search tree
 */
class BinarySearchTree {

private:
    Node* root;

    void addNode(Node* node, Bid bid);
    void inOrder(Node* node);
    Node* removeNode(Node* node, string bidId);

// Declare methods
public:
    BinarySearchTree();
    virtual ~BinarySearchTree();
    void InOrder();
    void Insert(Bid bid);
    void Remove();
    Bid Search();
};

// Default constructor
BinarySearchTree::BinarySearchTree() {
    // initialize housekeeping variables
	root = nullptr;
}

// Destructor

BinarySearchTree::~BinarySearchTree() {
    // Recurse from root deleting every node
}

// Traverse the tree in order
void BinarySearchTree::InOrder() {
	this->inOrder(root);
}
// Insert a bid
void BinarySearchTree::Insert(Bid bid) {
    // Implement logic to insert a bid into the tree
	//Sets root to node if no node exists
	if(root == nullptr) {
		root = new Node(bid);
	} else {
		// Else adds the node
		this->addNode(root, bid);
	}
}

// Remove a bid
void BinarySearchTree::Remove() {
    // Implement logic to remove a bid from the tree
	string bidId;
	cout << "Enter the bid id you would like to remove. (97985)" << endl;
	cin >> bidId;
	this->removeNode(root,bidId);
}
Node* BinarySearchTree::removeNode(Node *node, string bidId) {
	if (node == nullptr) {
		return node;
	}

	if(bidId.compare(node->bid.bidId) < 0) {
		node->left = removeNode(node->left, bidId);
	} else if (bidId.compare(node->bid.bidId) > 0) {
		node->right = removeNode(node->right, bidId);
	} else {
		// If no left or right children delete node
		if (node->left == nullptr && node->right == nullptr) {
			delete node;
			node = nullptr;
		}
		// If left children isnt null
		else if (node->left != nullptr && node->right == nullptr) {
			Node* tempNode = node;
			node = node->left;
			delete tempNode;
			// If right children isnt null
		} else if (node->left == nullptr && node->right != nullptr) {
			Node* tempNode = node;
			node = node->right;
			delete tempNode;
		} else {
			Node* temp = node->right;
			while(temp->left == nullptr) {
				temp = temp->left;
			}
			node->bid = temp->bid;
			node->right = removeNode(node->right, temp->bid.bidId);
		}
	}
	return node;
}

// Search for a bid
Bid BinarySearchTree::Search() {
    // Implement logic to search the tree for a bid
	//Search starts from the root of the tree
	string bidId;
	cout << "Enter the id for to search for a bid. (97985) " << endl;
	cin >> bidId;
	Node* current = root;

	while(current != nullptr) {
		if(current->bid.bidId.compare(bidId) == 0) {
			return current->bid;
		}
		// If the bid is less than current go left
		if(bidId.compare(current->bid.bidId) < 0) {
			current = current->left;
		// Else go right
		} else {
			current = current->right;
		}
	}
	Bid bid;
    return bid;
}

/**
 * Add a bid to some node (recursive)
 *
 * @param node Current node in tree
 * @param bid Bid to be added
 */
void BinarySearchTree::addNode(Node* node, Bid bid) {
    // Implement logic to insert a bid into the tree
	//If bid is smaller add to the left
	if (node->bid.bidId.compare(bid.bidId) > 0) {
		if(node->left == nullptr) {
			node->left = new Node(bid);
		} else {
			this->addNode(node->left, bid);
		}
	} else {
		// Else add to the right
		if(node->right == nullptr) {
			node->right = new Node(bid);
		} else {
			this->addNode(node->right, bid);
		}
	}
}
void BinarySearchTree::inOrder(Node* node) {
	// Recursively traverses in order
	if(node != nullptr) {
		inOrder(node->left);
	    cout << node->bid.bidId << ": " << node->bid.title << " | " << node->bid.amount << " | "
	            << node->bid.fund << endl;
		inOrder(node->right);
	}
}

/**
 * Load a CSV file containing bids into a container
 *
 * @return a container holding all the bids read
 */
void loadBids(BinarySearchTree* bst) {

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
            bst->Insert(bid);
        }
    } catch (csv::Error &e) {
        std::cerr << e.what() << std::endl;
    }
}

//The one and only main() method - Display menu and switch case statement
int binaryMain() {

    // Define a timer variable
    clock_t ticks;

    // Define a binary search tree to hold all bids
    BinarySearchTree* bst;

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
            bst = new BinarySearchTree();

            // Initialize a timer variable before loading bids
            ticks = clock();

            // Complete the method call to load the bids
            loadBids(bst);

            // Calculate elapsed time and display result
            ticks = clock() - ticks; // Current clock ticks minus starting clock ticks
            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
            break;

        case 2:
            bst->InOrder();
            break;

        case 3:
            ticks = clock();

            bid = bst->Search();

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
            bst->Remove();
            break;
        }
    }

    cout << "Thank you for using my Binary Search Tree Algorithm!" << endl << endl;

	return 0;
}
#endif
