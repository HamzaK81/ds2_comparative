#pragma once
#include <iostream>
#include <vector>


using namespace std;


// struct DataEntry 
// {

// public:
//     string filename;
//     string type;
//     int size;
//     string accessedOn;
//     string modifiedOn;
//     string path;
// };


class CSVHandler {

public:
    vector<int> entries;

    void loadData(const string &csv_file);
    void printData();
    void writeDataToFile(const std::vector<double> &x, const std::vector<double> &y, const std::string &filename);

};