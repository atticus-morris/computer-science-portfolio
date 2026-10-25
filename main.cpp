/*
 * File Name: main.cpp
 * Date: October 18, 2026
 * Student's Name: Atticus Morris
 * Assignment/Lab/Project: Corner Grocer (Project Three)
 * Description: Main driver for the Corner Grocer item tracking application.
 *              Handles the interactive user menu and input validation.
 */

#include <iostream>
#include <string>
#include <limits>
#include "ItemTracker.h"

using namespace std;

// Function to display the user menu
void displayMenu() {
    cout << "\n========================================\n";
    cout << "        CORNER GROCER ITEM TRACKER      \n";
    cout << "========================================\n";
    cout << "1. Search for a specific item frequency\n";
    cout << "2. Print all item frequencies list\n";
    cout << "3. Print histogram of frequencies\n";
    cout << "4. Exit program\n";
    cout << "Enter your choice (1-4): ";
}

int main() {
    // Initialize ItemTracker with input file and required backup file name
    ItemTracker tracker("CS210_Project_Three_Input_File.txt", "frequency.dat");

    // Process input data and generate frequency.dat backup automatically on startup
    tracker.loadDataAndBackup();

    int choice = 0;
    do {
        displayMenu();
        if (!(cin >> choice)) {
            cout << "Invalid entry. Please enter a valid number between 1 and 4.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
        case 1: {
            string searchItem;
            cout << "Enter the item name you wish to look for: ";
            cin >> searchItem;
            tracker.searchItem(searchItem);
            break;
        }
        case 2:
            tracker.printFrequencyList();
            break;
        case 3:
            tracker.printHistogram();
            break;
        case 4:
            cout << "\nExiting program. Thank you for using Corner Grocer Item Tracker!\n";
            break;
        default:
            cout << "Invalid selection. Please choose an option from 1 to 4.\n";
        }
    } while (choice != 4);

    return 0;
}