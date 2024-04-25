#pragma once
#include <iostream>
#include <vector>


using namespace std;


struct DataEntry 
{

public:
    string filename;
    string type;
    int size;
    string accessedOn;
    string modifiedOn;
    string path;
};


class CSVHandler {

public:
    vector<DataEntry> entries;

    void loadData(const string &csv_file);
    void printData();

};