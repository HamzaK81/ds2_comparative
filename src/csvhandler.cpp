#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "csvhandler.hpp"


using namespace std;


void CSVHandler::loadData(const string &csv_file) {

    entries.clear();

    fstream file;

    file.open(csv_file, ios::in);

    vector<string> row;
    string line, word;

    getline(file, line); // Skipping header

    while (getline(file, line)) {

        stringstream ss(line);
        int entry;
        ss >> entry;

        entries.push_back(entry);
    }

    file.close();
}


void CSVHandler::printData() {

    for (auto &entry : entries) {
        cout << entry << endl;
    }

}


void CSVHandler::writeDataToFile(const std::vector<double> &x, const std::vector<double> &y, const std::string &filename) {

    ofstream file(filename);
    
    if (file.is_open()) {
    
        for (size_t i = 0; i < x.size(); ++i) {
    
            file << x[i] << "," << y[i] << "\n";
    
        }
    
        file.close();
        std::cout << "Data written to file: " << filename << endl;
    
    } else {
    
        cerr << "Unable to open file: " << filename << endl;
    
    }

}


