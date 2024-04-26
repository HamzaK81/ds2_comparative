#pragma once
#include <iostream>
#include "bst.hpp"


using namespace std;


BSTIndex::BSTIndex() {
        this->root = nullptr;
        this->currentptr = root;
}


void BSTIndex::insert(int &data) {

    bool found = false;

    this->currentptr = root;

    BSTNode* node = new BSTNode;
    node->data = data;


    if (this->root == nullptr) {  // bst is empty
        
        this->root = node;
    
    } else {

        while (!found) {

            if (data <= currentptr->data) { // search left subtree

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
    cout << node->data << endl;
    inOrder(node->right);

}


void BSTIndex::search(int search) {

    bool found = false;
    this->currentptr = root;

    if (this->root == nullptr) {  // bst is empty
        
        cout << "The Binary Search Tree is empty." << endl;
    
    } else {

        while (!found) {

            if (search < currentptr->data) { // search left subtree

                // cout << "LEFT TURN AT: " << currentptr->data << endl;

                if (currentptr->left == nullptr) {

                    cout << "The searched item does not exist in the Binary Search Tree." << endl;
                    found = true;

                } else {

                    currentptr = currentptr->left;

                }

            } else if (search > currentptr->data) {  // search right subtree

                // cout << "RIGHT TURN AT: " << currentptr->data << endl;

                if (currentptr->right == nullptr) {

                    cout << "The searched item does not exist in the Binary Search Tree." << endl;
                    found = true;

                } else {

                    currentptr = currentptr->right;
                    
                }
            
            } else {

                found = true;
                cout << "The node: " << currentptr->data << " was found." << endl;
                return;
 
            }
        }

    }


}


void BSTIndex::populate(vector<int> &entries) {

    for (auto &entry : entries) {

        insert(entry);

    }


}


BSTNode* BSTIndex::remove(BSTNode* node, int del) {

    // base case
    if (node == nullptr) {
        return node;
    }


    if (del < node->data) {  // left subtree

        node->left = remove(node->left, del);
        return node;

    } else if (del > node->data) {  // right subtree

        node->right = remove(node->right, del);
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