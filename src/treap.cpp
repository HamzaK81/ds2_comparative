#include <iostream>
#include <vector>


using namespace std;


struct TreapNode {

	int key, priority;
	TreapNode *left, *right;

};



TreapNode *rightRotate(TreapNode *y) {

	TreapNode *x = y->left, *T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Return new root
	return x;

}



TreapNode *leftRotate(TreapNode *x) {

	TreapNode *y = x->right, *T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Return new root
	return y;

}


// Utility function to add a new key 
TreapNode* newNode(int key) {

	TreapNode* temp = new TreapNode;

	temp->key = key;

	temp->priority = rand()%100;

	temp->left = temp->right = nullptr;

	return temp;

}


// Function to search a given key in a given BST
void treapSearch(TreapNode* root, int key)
{
	
	if (root == nullptr || root->key == key) {

        if (root == nullptr) {

            cout << "The searched node does not exist in the Treap." << endl;
            return;

        } else if (key == root->key) {

            cout << "The value: " << root->key << " was found in the treap!" << endl;
            return;

        }

        

    }
	
	if (root->key < key) {

        return treapSearch(root->right, key);

    }
	
	return treapSearch(root->left, key);
}


// Function to insert given key in treap rooted at passed root
TreapNode* treapInsert(TreapNode* root, int key) {
    
	
	if (!root) {

        return newNode(key);

    }
		

	if (key <= root->key) {

		root->left = treapInsert(root->left, key);

		// Fix Heap property if it is violated
		if (root->left->priority > root->priority) {

            root = rightRotate(root);

        }

	} else {  // If key is greater 

		// Insert in right subtree
		root->right = treapInsert(root->right, key);

		// Fix Heap property if it is violated
		if (root->right->priority > root->priority) {

            root = leftRotate(root);

        }
			
	}

	return root;

}


// Function to delete given key in treap rooted at passed root
TreapNode* treapDelete(TreapNode* root, int key)
{
	if (root == nullptr) {

        return root;

    }
		

	if (key < root->key) {

        root->left = treapDelete(root->left, key);

    } else if (key > root->key) {

        root->right = treapDelete(root->right, key);

    }
		

	// If key is at the root:


	// If left is empty
	else if (root->left == NULL) {

		TreapNode *temp = root->right;

		delete(root);

		root = temp; // Make right child as root

	}

	// If right is empty
	else if (root->right == NULL) {

		TreapNode *temp = root->left;

		delete(root);

		root = temp; // Make left child as root

	}

	// If key is at root and both left and right are not empty
	else if (root->left->priority < root->right->priority) {

		root = leftRotate(root);
		
        root->left = treapDelete(root->left, key);
	
    } else {

		root = rightRotate(root);
		
        root->right = treapDelete(root->right, key);
	
    }

	return root;

}



void treapInOrder(TreapNode* root)
{
	if (root) {

		treapInOrder(root->left);

		cout << "key: "<< root->key << " | priority: " << root->priority;

		if (root->left) {

            cout << " | left child: " << root->left->key;

        }
			
		if (root->right) {

            cout << " | right child: " << root->right->key;

        }
			
		cout << endl;

		treapInOrder(root->right);

	}
}



TreapNode* treapPopulate(TreapNode* root, vector<int> entries) {

    for (auto entry : entries) {

        root = treapInsert(root, entry);

    }

    return root;

}

