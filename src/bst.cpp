#pragma once
#include <iostream>
#include "bst.hpp"


using namespace std;


BSTIndex::BSTIndex() {
        this->root = nullptr;
        this->currentptr = root;
}


void BSTIndex::insert(DataEntry &data) {

    bool found = false;

    this->currentptr = root;

    BSTNode* node = new BSTNode;
    node->data = data;


    if (this->root == nullptr) {  // bst is empty
        
        this->root = node;
    
    } else {

        while (!found) {

            if (data.size <= currentptr->data.size) { // search left subtree

                if (currentptr->left == nullptr) {

                    currentptr->left = node;
                    found = true;

                } else {

                    currentptr = currentptr->left;

                }

            } else {  // search right subtree

                if (currentptr->right == nullptr) {

                    currentptr->right = node;
                    found = true;

                } else {

                    currentptr = currentptr->right;
                    
                }
            }
        }
    }
}


void BSTIndex::inOrder(BSTNode* node) {

    if (node == nullptr) {
        return;
    }

    inOrder(node->left);
    cout << node->data.size << endl;
    inOrder(node->right);

}


void BSTIndex::search(int searchSize) {

    bool found = false;
    this->currentptr = root;

    if (this->root == nullptr) {  // bst is empty
        
        cout << "The Binary Search Tree is empty." << endl;
    
    } else {

        while (!found) {

            if (searchSize < currentptr->data.size) { // search left subtree

                // cout << "LEFT TURN AT: " << currentptr->data.size << endl;

                if (currentptr->left == nullptr) {

                    cout << "The searched item does not exist in the Binary Search Tree." << endl;
                    found = true;

                } else {

                    currentptr = currentptr->left;

                }

            } else if (searchSize > currentptr->data.size) {  // search right subtree

                // cout << "RIGHT TURN AT: " << currentptr->data.size << endl;

                if (currentptr->right == nullptr) {

                    cout << "The searched item does not exist in the Binary Search Tree." << endl;
                    found = true;

                } else {

                    currentptr = currentptr->right;
                    
                }
            
            } else {

                found = true;
                cout << "The details of the searched item are:" << endl;
                cout << "Filename: " << currentptr->data.filename << endl;
                cout << "Type: " << currentptr->data.type << endl;
                cout << "Size: " << currentptr->data.size << endl;
 
            }
        }

    }


}


void BSTIndex::populate(vector<DataEntry> &entries) {

    for (auto &entry : entries) {

        insert(entry);

    }


}


BSTNode* BSTIndex::remove(BSTNode* node, int deleteSize) {

    // base case
    if (node == nullptr) {
        return node;
    }


    if (deleteSize < node->data.size) {  // left subtree

        node->left = remove(node->left, deleteSize);
        return node;

    } else if (deleteSize > node->data.size) {  // right subtree

        node->right = remove(node->right, deleteSize);
        return node;

    }

    // NODE FOUND

    // node with 0 or 1 child
    if (root->left == nullptr) {

        BSTNode* temp = root->right;
        delete node;
        return temp;

    } else if (root->right == nullptr) {

        BSTNode* temp = root->left;
        delete root;
        return temp;

    }

    // node with 2 children (inorder successor method)
    BSTNode* successorParent = root;
    BSTNode* successor = root->right;
    while (successor->left != nullptr) {

        successorParent = successor;
        successor = successor->left;

    }

    node->data = successor->data;

    // delete the successor

    if (successorParent->left == successor) {

        successorParent->left = successor->right;

    } else {

        successorParent->right = successor->right;

    }

    delete successor;
    return node;

}