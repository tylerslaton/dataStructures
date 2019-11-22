#include <iostream>
#include "node.cpp"

// Binary Search Tree (BST) implements all the necassary functions 
// to create the logic behind the datastructure. Include:
//
// Insert - Add a new node to the tree
// Search - Find a node in the tree
// Delete - Remove a node from the tree
class BST {
    // All public attributes of the object
    public:
        // Default constructor if the user does not pass in anything
        BST(){
            root = nullptr;
        }

        // Function for inserting new values into the tree. Calls 
        // recursiveInsert to utilize a recurisve algorthim that
        // navigates the BST logically.
        void Insert(int newValue){
            // Make sure that the root is not null. If it is, 
            // set it to the value sent in. Otherwise, begin
            // the recursion process.
            if (root == nullptr){
                Node* inRoot = new Node(newValue);
                root = inRoot;
            } else {
                recursiveInsert(root, newValue);
            }
        }

        // Searches through the tree for the specified value
        int Search(int searchValue){
            // If the root node is null, the value will not be able to 
            // be found. Otherwise, begin the recursion process for
            // searching
            if(root == nullptr){
                return 0;
            } else {
                return recursiveSearch(root, searchValue);
            }
        }

        // Finds the specified value and deletes it from the tree.
        int Delete (int deleteValue){
            // If the root node is null, the value will not be able
            // to be found. Otherwise, begin the recursion process for
            // deletion of the specified value from the tree.
            if (root == nullptr){
                return 0;
            } else {
                return recursiveDelete(root, deleteValue);
            }
        }

    // All private and non-accessible portions of the object
    private:
        // The root node field
        Node *root; //Maybe this will break stuff?

        // 
        void recursiveInsert(Node* currentNode, int newValue){
            if (currentNode -> value == newValue){
                currentNode -> count++;
            } else if (currentNode -> value < newValue){
                if (currentNode -> right != nullptr){
                    recursiveInsert(currentNode -> right, newValue);
                } else {
                    currentNode -> SetRight(newValue);
                }
            } else if (currentNode -> value > newValue){
                if (currentNode -> left != nullptr){
                    recursiveInsert(currentNode -> left, newValue);
                }
                else{
                    currentNode -> SetLeft(newValue);
                }
            }
        }

        int recursiveSearch(Node* currentNode, int searchValue){
            int returnCount = 0;
            if(currentNode -> value == searchValue){
                return currentNode->count;
            } else if (currentNode -> value < searchValue){
                if (currentNode -> right == nullptr)
                    return 0;
                returnCount = recursiveSearch(currentNode -> right, searchValue);

            } else if(currentNode -> value > searchValue){
                if (currentNode -> left == nullptr)
                    return 0;
                returnCount = recursiveSearch(currentNode->left, searchValue);

            }
            return returnCount;
        }

        int recursiveDelete(Node* currentNode, int deleteValue){
            int returnCount = 0;
            if (currentNode->value == deleteValue)
            {
                if (currentNode -> count >= 1){
                    currentNode -> count--;
                } else {
                    // TODO: Do delete stuff 
                }
                return 1;
            }
            else if (currentNode->value < deleteValue)
            {
                if (currentNode->right == nullptr)
                    return 0;
                returnCount = recursiveDelete(currentNode->right, deleteValue);
            }
            else if (currentNode->value > deleteValue)
            {
                if (currentNode->left == nullptr)
                    return 0;
                returnCount = recursiveDelete(currentNode->left, deleteValue);
            }
            return returnCount;
        }
};

