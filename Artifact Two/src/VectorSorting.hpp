//============================================================================
// Name        : VectorSorting.hpp
// Author      : Joshua McNew
// Version     : 1.0
// Copyright   : Copyright © 2017 SNHU COCE
// Description : Vector Sorting Algorithm
//============================================================================

#ifndef VectorSortinge_hpp_
#define VectorSorting_hpp_
#include <algorithm>
#include <iostream>
#include <time.h>
#include "Artifact2.hpp"
#include "CSVparser.hpp"

using namespace std;

/**
 * Load a CSV file containing bids into a container
 *
 * @return a container holding all the bids read
 */
vector<Bid> loadBids() {

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

    // Define a vector data structure to hold a collection of bids.
    vector<Bid> bids;

    // Initialize the CSV Parser using the given path
    csv::Parser file = csv::Parser(csvPath);

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
            bids.push_back(bid);
        }
    } catch (csv::Error &e) {
        std::cerr << e.what() << std::endl;
    }
    return bids;
}

// Implement the quick sort logic over bid.title

/**
 * Partition the vector of bids into two parts, low and high
 *
 * @param bids Address of the vector<Bid> instance to be partitioned
 * @param begin Beginning index to partition
 * @param end Ending index to partition
 */
int partition(vector<Bid>& bids, int begin, int end) {

	int lower = begin;
	int higher = end;

	// Set pivot point to the middle element
	int pivot = begin + (end - begin) / 2;

	bool done = false;
	while(!done) {

		// Increment lower if it is less than pivot
		while (bids.at(lower).title.compare(bids.at(pivot).title) < 0) {
			++lower;
		}

		// Decrement higher if it is less than pivot
		while (bids.at(pivot).title.compare(bids.at(higher).title) < 0) {
			--higher;
		}

		if (lower >= higher) {
			done = true;
		} else {
			// Swap lower and higher
			swap(bids.at(lower), bids.at(higher));

			// Increment lower and decrement higher
			++lower;
			--higher;
		}


	}
	return higher;
}

/**
 * Perform a quick sort on bid title
 * Average performance: O(n log(n))
 * Worst case performance O(n^2))
 *
 * @param bids address of the vector<Bid> instance to be sorted
 * @param begin the beginning index to sort on
 * @param end the ending index to sort on
 */
void quickSort(vector<Bid>& bids, int begin, int end) {

	int middle = 0;

	// If begin is greater than or equal to end, done
	if (begin >= end) {
		return;
	}

	// Partition bids
	middle = partition(bids, begin, end);

	// Call quickSort using middle value
	quickSort(bids, begin, middle);

	// Call quickSort using middle value +1
	quickSort(bids, middle + 1, end);
}

// Implement the selection sort logic over bid.title

/**
 * Perform a selection sort on bid title
 * Average performance: O(n^2))
 * Worst case performance O(n^2))
 *
 * @param bid address of the vector<Bid>
 *            instance to be sorted
 */
void selectionSort(vector<Bid>& bids) {

	// Initialize variable for selectionSort
	int unsigned mini;

	// Assign sel the bid to sort
	for (unsigned sel = 0; sel < bids.size(); ++sel) {
		mini = sel;

		for (unsigned j = sel + 1; j < bids.size(); ++j) {
			if (bids.at(j).title.compare(bids.at(mini).title) < 0) {
				mini = j;
			}
		}
		// Swaps the bids
		if (mini != sel) {
			swap(bids.at(sel), bids.at(mini));
		}
	}
}

// The one and only main() method - Display Menu and switch case statement
int vectorMain() {

    // Define a vector to hold all the bids
    vector<Bid> bids;

    // Define a timer variable
    clock_t ticks;

    int choice = 0;
    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Load Bids" << endl;
        cout << "  2. Display All Bids" << endl;
        cout << "  3. Selection Sort All Bids" << endl;
        cout << "  4. Quick Sort All Bids" << endl;
        cout << "  9. Return To Main Menu" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            // Initialize a timer variable before loading bids
            ticks = clock();

            // Complete the method call to load the bids
            bids = loadBids();

            cout << bids.size() << " bids read" << endl;

            // Calculate elapsed time and display result
            ticks = clock() - ticks; // current clock ticks minus starting clock ticks
            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

            break;

        case 2:
            // Loop and display the bids read
            for (unsigned int i = 0; i < bids.size(); ++i) {
                displayBid(bids[i]);
            }
            cout << endl;

            break;

        // Invoke the selection sort and report timing results
        case 3:
             // Initialize a timer variable before loading bids
             ticks = clock();

             // Complete the method call to load the bids
             selectionSort(bids);

             cout << bids.size() << " bids sorted" << endl;

             // Calculate elapsed time and display result
             ticks = clock() - ticks; // Current clock ticks minus starting clock ticks
             cout << "time: " << ticks << " clock ticks" << endl;
             cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

             break;

        // Invoke the quick sort and report timing results
        case 4:
             // Initialize a timer variable before loading bids
             ticks = clock();

             // Complete the method call to load the bids
             quickSort(bids, 0, bids.size() - 1);

             cout << bids.size() << " bids sorted" << endl;

             // Calculate elapsed time and display result
             ticks = clock() - ticks;
             cout << "time: " << ticks << " clock ticks" << endl;
             cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

             break;
        }
    }

    cout << "Thank you for using my Vector Sorting Algorithm!" << endl << endl;

    return 0;
}
#endif
