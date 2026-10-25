/*
 * File Name: ItemTracker.cpp
 * Date: October 18, 2026
 * Student's Name: Atticus Morris
 * Assignment/Lab/Project: Corner Grocer (Project Three)
 * Description: Implementation of ItemTracker class methods for reading input data,
 *              backing up to frequency.dat, searching items, and generating reports/histograms.
 */

#include "ItemTracker.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Constructor initialization
ItemTracker::ItemTracker(string inputFilename, string backupFilename)
    : m_inputFilename(inputFilename), m_backupFilename(backupFilename) {
}

// Reads input records, populates map, and automatically writes backup file frequency.dat
void ItemTracker::loadDataAndBackup() {
    ifstream inFile(m_inputFilename);
    if (!inFile.is_open()) {
        cout << "Error: Could not open input file " << m_inputFilename << "\n";
        return;
    }

    string item;
    while (inFile >> item) {
        m_itemFrequencyMap[item]++;
    }
    inFile.close();

    // Automatically create frequency.dat backup file without user intervention
    ofstream outFile(m_backupFilename);
    if (!outFile.is_open()) {
        cout << "Error: Could not create backup file " << m_backupFilename << "\n";
        return;
    }

    for (const auto& pair : m_itemFrequencyMap) {
        outFile << pair.first << " " << pair.second << "\n";
    }
    outFile.close();
}

// Menu Option 1: Search for specific item frequency
void ItemTracker::searchItem(const string& item) const {
    auto it = m_itemFrequencyMap.find(item);
    if (it != m_itemFrequencyMap.end()) {
        cout << "\n[Result] Item: " << it->first << " | Purchased Frequency: " << it->second << "\n";
    }
    else {
        cout << "\n[Result] Item '" << item << "' was not found in the purchase records.\n";
    }
}

// Menu Option 2: Print list of all items and frequencies
void ItemTracker::printFrequencyList() const {
    cout << "\n========================================\n";
    cout << "       Item Purchase Frequencies        \n";
    cout << "========================================\n";
    for (const auto& pair : m_itemFrequencyMap) {
        cout << left << setw(15) << pair.first << " " << pair.second << "\n";
    }
    cout << "----------------------------------------\n";
}

// Menu Option 3: Print text-based histogram with asterisks
void ItemTracker::printHistogram() const {
    cout << "\n========================================\n";
    cout << "      Purchase Frequency Histogram      \n";
    cout << "========================================\n";
    for (const auto& pair : m_itemFrequencyMap) {
        cout << left << setw(15) << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            cout << "*";
        }
        cout << "\n";
    }
    cout << "----------------------------------------\n";
}