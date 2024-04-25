#include <iostream>
#include "csvhandler.cpp"
#include "bst.cpp"
#include "redblack.cpp"
#include "avl.cpp"
#include "treap.cpp"


using namespace std;


void someStuff() {

    CSVHandler* handler = new CSVHandler;
    // handler->loadData("./data/small.csv");
    // handler->loadData("./data/medium.csv");
    handler->loadData("./data/large.csv");

    // handler->printData();
    
    BSTIndex* bst = new BSTIndex;

    bst->populate(handler->entries);

    bst->search(111573);
    bst->remove(bst->root, 111573);
    bst->search(111573);


    // bst->inOrder(bst->root);

}


void avlInsertStuff() 
{ 
	Node *root = NULL; 
	
	/* Constructing tree given in 
	the above figure */
	root = insert(root, 10); 
	root = insert(root, 20); 
	root = insert(root, 30); 
	root = insert(root, 40); 
	root = insert(root, 50); 
	root = insert(root, 25); 
	
	/* The constructed AVL Tree would be 
				30 
			/ \ 
			20 40 
			/ \ \ 
		10 25 50 
	*/
	cout << "Preorder traversal of the "
			"constructed AVL tree is \n"; 
	preOrder(root); 
	
}


void avlDeleteStuff() {

    Node *root = NULL; 
 
    /* Constructing tree given in
    the above figure */
    root = insert(root, 9); 
    root = insert(root, 5); 
    root = insert(root, 10); 
    root = insert(root, 0); 
    root = insert(root, 6); 
    root = insert(root, 11); 
    root = insert(root, -1); 
    root = insert(root, 1); 
    root = insert(root, 2); 
 
    /* The constructed AVL Tree would be 
            9 
        / \ 
        1 10 
        / \ \ 
    0 5 11 
    / / \ 
    -1 2 6 
    */
 
    cout << "Preorder traversal of the "
            "constructed AVL tree is \n"; 
    preOrder(root); 
 
    root = deleteNode(root, 10); 
 
    /* The AVL Tree after deletion of 10 
            1 
        / \ 
        0 9 
        / / \ 
    -1 5     11 
        / \ 
        2 6 
    */
 
    cout << "\nPreorder traversal after"
         << " deletion of 10 \n"; 
    preOrder(root); 

}


void redblackstuff() {

    RedBlackTree t;
    int arr[] = {1, 4, 6, 3, 5, 7, 8, 2, 9};
    for (int i = 0; i < 9; i++) {
        t.insert(arr[i]);
        // std::cout << std::endl;
        t.inorderTraversal();
    }
    t.printTree();

}


void treapstuff() {

    srand(time(NULL));

	struct TreapNode *root = NULL;
	root = insert(root, 50);
	root = insert(root, 30);
	root = insert(root, 20);
	root = insert(root, 40);
	root = insert(root, 70);
	root = insert(root, 60);
	root = insert(root, 80);

	cout << "Inorder traversal of the given tree \n";
	inorder(root);

	cout << "\nDelete 20\n";
	root = deleteNode(root, 20);
	cout << "Inorder traversal of the modified tree \n";
	inorder(root);

	cout << "\nDelete 30\n";
	root = deleteNode(root, 30);
	cout << "Inorder traversal of the modified tree \n";
	inorder(root);

	cout << "\nDelete 50\n";
	root = deleteNode(root, 50);
	cout << "Inorder traversal of the modified tree \n";
	inorder(root);

	TreapNode *res = search(root, 50);
	(res == NULL)? cout << "\n50 Not Found ":
				cout << "\n50 found";


}


int main() {

    // someStuff();

    // redblackstuff();

    // avlInsertStuff();

    // avlDeleteStuff();

    treapstuff();




    return 0;

}