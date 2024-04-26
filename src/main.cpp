#include <iostream>
#include <chrono>
#include <cstdlib>
#include "csvhandler.cpp"
#include "bst.cpp"
#include "redblack.cpp"
#include "avl.cpp"
#include "treap.cpp"
#include "generate.cpp"

using namespace std;



int main() {

    CSVHandler* handler = new CSVHandler;

    BSTIndex* bst = new BSTIndex();
    AVLNode* avl_root = nullptr;
    RedBlackTree* redblack = new RedBlackTree();
    TreapNode* treap_root = nullptr;


    char structure = '0';

    while (structure != '5') {

        system("cls");

        cout << "Select Data Structure: " << endl;
        cout << "1. Binary Search Tree" << endl;
        cout << "2. Treap" << endl;
        cout << "3. AVL Tree" << endl;
        cout << "4. Red-Black Tree" << endl;
        cout << "5. EXIT" << endl;
        cout << "Enter Choice: ";

        cin >> structure;
        if (structure == '5') {
            system("cls");
            continue;
        }
            

        system("cls");

        cout << "Select data size: " << endl;
        cout << "1. Small (100) [PRESS 's']" << endl;
        cout << "2. Medium (1000) [PRESS 'm']" << endl;
        cout << "3. Large (10000) [PRESS 'l']" << endl;
        cout << "Enter size: ";

        char size;
        cin >> size;

        system("cls");

        cout << "Populating data structure..." << endl;

        if (size == 's') {

            handler->loadData("./data/smallsample.csv");

        } else if (size == 'm') {

            handler->loadData("./data/mediumsample.csv");

        } else {

            handler->loadData("./data/largesample.csv");

        }

        auto start = chrono::steady_clock::now();

        if (structure == '1') {

            bst->populate(handler->entries);

        } else if (structure == '2') {

            treap_root = treapPopulate(treap_root, handler->entries);

        } else if (structure == '3') {

            avl_root = AVLpopulate(avl_root, handler->entries);

        } else {

            redblack->populate(handler->entries);

        }

        auto end = chrono::steady_clock::now(); 

        chrono::duration<double> duration = end - start;
        double runtime = duration.count();

        cout << "Data population complete." << endl;
        cout << "Time taken: " << runtime << "s" << endl << endl;

        cout << "Select Operation: " << endl;
        cout << "1. Search" << endl;
        cout << "2. Delete" << endl;
        cout << "Enter operation: ";

        char operation;
        cin >> operation;

        cout << "Enter value: ";

        int key;
        cin >> key;

        start = chrono::steady_clock::now();

        if (structure == '1') {

            if (operation == '1')
                bst->search(key);
            else
                bst->remove(bst->root, key);

        } else if (structure == '2') {

            if (operation == '1')
                treapSearch(treap_root, key);
            else
                treapDelete(treap_root, key);

        } else if (structure == '3') {

            if (operation == '1')
                AVLSearch(avl_root, key);
            else
                avl_root = AVLDelete(avl_root, key);

        } else {

            if (operation == '1') {
                redblack->insert(key);
                cout << "Node with value: " << key << " was found in the Red-Black Tree" << endl;
            }
            else
                bst->remove(bst->root, key);
        }

        end = chrono::steady_clock::now(); 

        duration = end - start;
        runtime = duration.count();

        cout << "Time taken: " << runtime << "s" << endl;

        cout << endl << "Press any key to continue..." << endl;
        char dummy;
        cin >> dummy;

    }

    

    return 0;

}