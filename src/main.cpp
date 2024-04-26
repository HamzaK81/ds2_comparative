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


    cout << "Select Data Structure: " << endl;
    cout << "1. Binary Search Tree" << endl;
    cout << "2. Treap" << endl;
    cout << "3. AVL Tree" << endl;
    cout << "4. Red-Black Tree" << endl;
    cout << "Enter Choice: ";

    char structure;
    cin >> structure;

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
    cout << "Time taken: " << runtime << "s" << endl;













    

    // std::vector<double> x = {1, 2, 3, 4, 5};
    // std::vector<double> y = {2, 4, 6, 8, 10};

    // // Write data to file
    // writeDataToFile(x, y, "src/graph/graphdata.csv");

    // system("python src/graph/pyscript.py");

    // generate("data/smallsample.csv", 1000, 100);
    // generate("data/mediumsample.csv", 5000, 1000);
    // generate("data/largesample.csv", 20000, 10000);

    // handler->printData();
    
    // BSTIndex* bst = new BSTIndex;

    // bst->populate(handler->entries);

    // bst->search(408);
    // bst->remove(bst->root, 408);
    // bst->search(408);


    // bst->inOrder(bst->root);

    // handler->printData();

    // AVLNode* avl_root = nullptr;

    // avl_root = AVLpopulate(avl_root, handler->entries);

    // AVLinOrder(avl_root);

    // AVLSearch(avl_root, 884);
    // AVLDelete(avl_root, 884);
    // AVLSearch(avl_root, 884);

    // RedBlackTree* redblack = new RedBlackTree();

    // redblack->populate(handler->entries);

    // redblack->inorderTraversal();

    // TreapNode* treap_root = nullptr;

    // treap_root = treapPopulate(treap_root, handler->entries);

    // treapInOrder(treap_root);

    // treapSearch(treap_root, 19967);

    // treap_root = treapDelete(treap_root, 19967);

    // treapSearch(treap_root, 19967);



    return 0;

}