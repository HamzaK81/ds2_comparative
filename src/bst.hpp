#pragma once
#include <iostream>
#include "csvhandler.cpp"


using namespace std;


class BSTNode {

public:

    BSTNode* left = nullptr;
    BSTNode* right = nullptr;
    DataEntry data;

};


class BSTIndex {

public:

    BSTNode* root;
    BSTNode* currentptr;


    BSTIndex();

    void populate(vector<DataEntry> &entries);
    void insert(DataEntry &data);
    BSTNode* predecessor(BSTNode* node);
    BSTNode* remove(BSTNode* node, int deleteSize);
    void search(int searchSize);
    void inOrder(BSTNode* node);

};