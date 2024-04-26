#pragma once
#include <iostream>
#include "csvhandler.cpp"


using namespace std;


class BSTNode {

public:

    BSTNode* left = nullptr;
    BSTNode* right = nullptr;
    int data;

};


class BSTIndex {

public:

    BSTNode* root;
    BSTNode* currentptr;


    BSTIndex();

    void populate(vector<int> &entries);
    void insert(int &data);
    BSTNode* predecessor(BSTNode* node);
    BSTNode* remove(BSTNode* node, int deleteSize);
    void search(int searchSize);
    void inOrder(BSTNode* node);

};