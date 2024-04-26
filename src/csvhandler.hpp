#pragma once
#include <iostream>
#include <vector>


using namespace std;


class CSVHandler {

public:
    vector<int> entries;

    void loadData(const string &csv_file);
    void printData();
    void writeDataToFile(const std::vector<double> &x, const std::vector<double> &y, const std::string &filename);

};