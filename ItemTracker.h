/*
 * File Name: ItemTracker.h
 * Date: October 18, 2026
 * Student's Name: Atticus Morris
 * Assignment/Lab/Project: Corner Grocer (Project Three)
 * Description: Header file declaring the ItemTracker class utilizing std::map
 *              for frequency analysis and file processing.
 */

#ifndef ITEM_TRACKER_H
#define ITEM_TRACKER_H

#include <string>
#include <map>

class ItemTracker {
private:
    std::map<std::string, int> m_itemFrequencyMap;
    std::string m_inputFilename;
    std::string m_backupFilename;

public:
    // Constructor
    ItemTracker(std::string inputFilename, std::string backupFilename);

    // Core functionality methods
    void loadDataAndBackup();
    void searchItem(const std::string& item) const;
    void printFrequencyList() const;
    void printHistogram() const;
};

#endif // ITEM_TRACKER_H