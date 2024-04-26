#include <iostream>


using namespace std;


class RedBlackTree {

private:

    struct RedBlackNode {

        int data;
        RedBlackNode* left;
        RedBlackNode* right;
        char colour;
        RedBlackNode* parent;
 
        RedBlackNode(int data) : data(data), left(nullptr), right(nullptr), colour('R'), parent(nullptr) {}

    };
 
    RedBlackNode* root;

    bool ll; // Left-Left Rotation flag

    bool rr; // Right-Right Rotation flag
    
    bool lr; // Left-Right Rotation flag

    bool rl; // Right-Left Rotation flag
 


    RedBlackNode* rotateLeft(RedBlackNode* node) {

        RedBlackNode* x = node->right;

        RedBlackNode* y = x->left;

        x->left = node;
        
        node->right = y;

        node->parent = x;

        if (y != nullptr) {

            y->parent = node;

        }
            
        return x;

    }


 
    RedBlackNode* rotateRight(RedBlackNode* node) {
        RedBlackNode* x = node->left;
        RedBlackNode* y = x->right;
        x->right = node;
        node->left = y;
        node->parent = x;
        if (y != nullptr)
            y->parent = node;
        return x;
    }
 

    // Helper function for insertion
    RedBlackNode* insertHelp(RedBlackNode* root, int data) {

        bool conflict = false; // Flag to check RED-RED conflict
 
        if (root == nullptr) {

            return new RedBlackNode(data);

        } else if (data < root->data) {

            root->left = insertHelp(root->left, data);

            root->left->parent = root;

            if (root != this->root) {

                if (root->colour == 'R' && root->left->colour == 'R')

                    conflict = true;

            }

        } else {

            root->right = insertHelp(root->right, data);

            root->right->parent = root;

            if (root != this->root) {
                
                if (root->colour == 'R' && root->right->colour == 'R') {

                    conflict = true;

                }
            }
        }
 
        // Perform rotations
        if (ll) {

            root = rotateLeft(root);
            root->colour = 'B';
            root->left->colour = 'R';
            ll = false;

        } else if (rr) {

            root = rotateRight(root);
            root->colour = 'B';
            root->right->colour = 'R';
            rr = false;

        } else if (rl) {

            root->right = rotateRight(root->right);
            root->right->parent = root;
            root = rotateLeft(root);
            root->colour = 'B';
            root->left->colour = 'R';
            rl = false;

        } else if (lr) {

            root->left = rotateLeft(root->left);
            root->left->parent = root;
            root = rotateRight(root);
            root->colour = 'B';
            root->right->colour = 'R';
            lr = false;
            
        }
 

        // Handle RED-RED conflicts
        if (conflict) {

            if (root->parent->right == root) {

                if (root->parent->left == nullptr || root->parent->left->colour == 'B') {

                    if (root->left != nullptr && root->left->colour == 'R') {

                        rl = true;

                    } else if (root->right != nullptr && root->right->colour == 'R') {

                        ll = true;

                    }
                } else {

                    root->parent->left->colour = 'B';
                    root->colour = 'B';

                    if (root->parent != this->root) {

                        root->parent->colour = 'R';

                    }
                }

            } else {

                if (root->parent->right == nullptr || root->parent->right->colour == 'B') {

                    if (root->left != nullptr && root->left->colour == 'R') {

                        rr = true;
                        
                    } else if (root->right != nullptr && root->right->colour == 'R') {

                        lr = true;

                    }

                } else {

                    root->parent->right->colour = 'B';
                    root->colour = 'B';

                    if (root->parent != this->root) {

                        root->parent->colour = 'R';

                    }
                        
                }
            }

            conflict = false;
        }

        return root;
    }

 
    // Helper function for Inorder Traversal
    void inorderTraversalHelper(RedBlackNode* node) {

        if (node != nullptr) {

            inorderTraversalHelper(node->left);

            std::cout << node->data << " ";

            inorderTraversalHelper(node->right);

        }
    }


 
public:
    RedBlackTree() : root(nullptr), ll(false), rr(false), lr(false), rl(false) {}
 

    // Function to insert data into the tree
    void insert(int data) {

        if (root == nullptr) {

            root = new RedBlackNode(data);

            root->colour = 'B';

        } else {

            root = insertHelp(root, data);

        }
    }
 

    // Function to perform Inorder Traversal of the tree
    void inorderTraversal() {

        inorderTraversalHelper(root);
  
    }


    void populate(vector<int> entries) {

        for (auto entry : entries) {

            this->insert(entry);

        }
    }
};