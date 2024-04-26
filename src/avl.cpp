using namespace std; 


class AVLNode {

public: 

	int key; 
	AVLNode *left; 
	AVLNode *right; 
	int height; 

}; 


int height(AVLNode* node) { 

	if (node == nullptr) {

        return 0; 
    
    }
		
	return node->height; 

} 


int max(int a, int b) {

	return (a > b)? a : b; 

} 


// Allocate new node
AVLNode* newNode(int key) {

	AVLNode* node = new AVLNode(); 
	node->key = key; 
	node->left = nullptr; 
	node->right = nullptr; 
	node->height = 1; // new node is initially added as a leaf

	return(node); 

} 


// right rotate a tree rooted at rooted
AVLNode *rightRotate(AVLNode *rooted) 
{ 
	AVLNode *x = rooted->left; 

	AVLNode *T2 = x->right; 

	// Perform rotation 
	x->right = rooted; 

	rooted->left = T2; 

	// Update heights 
	rooted->height = max(height(rooted->left), height(rooted->right)) + 1; 

	x->height = max(height(x->left), height(x->right)) + 1; 

	// Return new root 
	return x; 
} 


// right rotate a tree rooted at rooted
AVLNode *leftRotate(AVLNode *rooted) 
{ 
	AVLNode *y = rooted->right; 

	AVLNode *T2 = y->left; 

	// Perform rotation 
	y->left = rooted; 

	rooted->right = T2; 

	// Update heights 
	rooted->height = max(height(rooted->left), height(rooted->right)) + 1; 

	y->height = max(height(y->left), height(y->right)) + 1; 

	// Return new root 
	return y; 
} 


// Get balance factor of passed node 
int getBalance(AVLNode *node) {

	if (node == nullptr) {

        return 0; 

    }
		
	return height(node->left) - height(node->right); 

} 


// Recursive function to insert a key in subtree of passed node
AVLNode* insert(AVLNode* node, int key) 
{ 

	// Perform the normal BST insertion
	if (node == nullptr) {

        return(newNode(key)); 

    }
		

	if (key < node->key) {

        node->left = insert(node->left, key);

    } else if (key > node->key) {

        node->right = insert(node->right, key); 

    } else {
        
        return node; 

        }
		

	// Update height of this ancestor node
	node->height = 1 + max(height(node->left), height(node->right)); 


	// Get the balance factor of this ancestor node
	int balance = getBalance(node); 


	// If this node becomes unbalanced, then:

	// Case: left-left
	if (balance > 1 && key < node->left->key) {

        return rightRotate(node); 

    }
		

	// Case: right-right
	if (balance < -1 && key > node->right->key) {

        return leftRotate(node); 

    }


	// Case: left-right
	if (balance > 1 && key > node->left->key) {

		node->left = leftRotate(node->left); 
		
        return rightRotate(node); 
	
    } 


	// Case: right-left
	if (balance < -1 && key < node->right->key) { 

		node->right = rightRotate(node->right); 

		return leftRotate(node); 

	} 

	// return the (unchanged) node pointer
	return node; 

} 


// Find the minimum value node in tree rooted at passed node
AVLNode * minValueNode(AVLNode* node) {

    AVLNode* current = node; 
 
    /* loop down to find the leftmost leaf */
    while (current->left != NULL) {

        current = current->left; 

    }
        
    return current; 

} 
 
// Recursive function to delete a node with value "key", from tree rooted at "root". Returns new root
AVLNode* deleteNode(AVLNode* root, int key) { 
     
    if (root == NULL) {

        return root; 

    }
        
    if ( key < root->key ) {

        root->left = deleteNode(root->left, key); 

    } else if( key > root->key ) {

        root->right = deleteNode(root->right, key); 

    } else { 

        // node with only one child or no child 
        if((root->left == nullptr) || (root->right == nullptr)) { 

            AVLNode *temp = root->left ? root->left : root->right; 
 
            // No child case 
            if (temp == nullptr) {

                temp = root; 
                root = nullptr; 

            } else {  // One child case 

                *root = *temp; // Copy the contents of the non-empty child 

            }
            
            free(temp); 

        } else { 

            // node with two children: find inorder successor
            AVLNode* successor = minValueNode(root->right); 
 
            // Copy successor's data to this node 
            root->key = successor->key; 
 
            // Delete successor 
            root->right = deleteNode(root->right, successor->key); 
        } 
    } 
 
    // If the tree had only one node then return 
    if (root == nullptr) {

        return root; 

    }
    

    // STEP 2: Update height of current node
    root->height = 1 + max(height(root->left), height(root->right)); 
 

    // STEP 3: get balance factor
    int balance = getBalance(root); 
 

 
    // Case: left-left
    if (balance > 1 && getBalance(root->left) >= 0) {

        return rightRotate(root); 

    }
        
 
    // Case: left-right 
    if (balance > 1 && getBalance(root->left) < 0) {

        root->left = leftRotate(root->left); 
    
        return rightRotate(root); 
    
    } 
 
    // Case: right-right
    if (balance < -1 && getBalance(root->right) <= 0) {

        return leftRotate(root); 

    }
        
 
    // Case: right-left
    if (balance < -1 && getBalance(root->right) > 0) {

        root->right = rightRotate(root->right); 

        return leftRotate(root); 

    } 
 
    return root; 
} 


void AVLinOrder(AVLNode *root) 
{ 
	if(root != nullptr) 
	{ 
        AVLinOrder(root->left);

		cout << root->key << endl;

		AVLinOrder(root->right); 
	} 
} 


AVLNode* AVLpopulate(AVLNode* root, vector<int> entries) {

    for (auto entry : entries) {

        root = insert(root, entry);

    }

    return root;
    
}

void AVLSearch() {

    
}
