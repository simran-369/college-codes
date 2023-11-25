/* Assignment 05 :
title : implement binary search tree */
//CODE

#include <iostream>
#include <queue>

using namespace std;

// Node structure for the Binary Search Tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    // Helper function for insertion
    Node* insertRecursive(Node* root, int value) {
        if (root == nullptr) {
            return new Node(value);
        }

        if (value < root->data) {
            root->left = insertRecursive(root->left, value);
        } else if (value > root->data) {
            root->right = insertRecursive(root->right, value);
        } else {
            // Duplicate entry handling (optional)
            // You can choose to ignore duplicates or update the existing node
            // Here, we choose to ignore duplicates
            cout << "Duplicate entry ignored: " << value << endl;
        }

        return root;
    }

    // Helper function for deletion
    Node* deleteRecursive(Node* root, int value) {
        if (root == nullptr) {
            return root;
        }

        if (value < root->data) {
            root->left = deleteRecursive(root->left, value);
        } else if (value > root->data) {
            root->right = deleteRecursive(root->right, value);
        } else {
            // Node with only one child or no child
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children, get the inorder successor (smallest in the right subtree)
            root->data = findMin(root->right)->data;

            // Delete the inorder successor
            root->right = deleteRecursive(root->right, root->data);
        }

        return root;
    }

    // Helper function for finding the minimum value node in a subtree
    Node* findMin(Node* root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    // Helper function for searching
    Node* searchRecursive(Node* root, int value) {
        if (root == nullptr || root->data == value) {
            return root;
        }

        if (value < root->data) {
            return searchRecursive(root->left, value);
        }

        return searchRecursive(root->right, value);
    }

    // Helper function for in-order traversal
    void inorderTraversal(Node* root) {
        if (root) {
            inorderTraversal(root->left);
            cout << root->data << " ";
            inorderTraversal(root->right);
        }
    }

    // Helper function to display leaf nodes
    void displayLeafNodes(Node* root) {
        if (root) {
            if (root->left == nullptr && root->right == nullptr) {
                cout << root->data << " ";
            } else {
                displayLeafNodes(root->left);
                displayLeafNodes(root->right);
            }
        }
    }

    // Helper function to display tree level wise
    void displayLevelWise(Node* root) {
        if (root == nullptr) {
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            cout << current->data << " ";

            if (current->left != nullptr) {
                q.push(current->left);
                cout << "Left Child of " << current->data << ": " << current->left->data << endl;
            }

            if (current->right != nullptr) {
                q.push(current->right);
                cout << "Right Child of " << current->data << ": " << current->right->data << endl;
            }
        }
    }

    // Helper function to display parent nodes with their child nodes
    void displayParentChild(Node* root) {
        if (root == nullptr) {
            return;
        }

        if (root->left != nullptr) {
            cout << "Parent: " << root->data << ", Left Child: " << root->left->data << endl;
            displayParentChild(root->left);
        }

        if (root->right != nullptr) {
            cout << "Parent: " << root->data << ", Right Child: " << root->right->data << endl;
            displayParentChild(root->right);
        }
    }

public:
    // Constructor
    BinarySearchTree() : root(nullptr) {}

    // Function to insert a value into the tree
    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // Function to delete a value from the tree
    void deleteValue(int value) {
        root = deleteRecursive(root, value);
    }

    // Function to search for a value in the tree
    Node* search(int value) {
        return searchRecursive(root, value);
    }

    // Function to display the tree (in-order traversal)
    void displayTree() {
        cout << "In-order Traversal: ";
        inorderTraversal(root);
        cout << endl;
    }

    // Function to display leaf nodes
    void displayLeafNodes() {
        cout << "Leaf Nodes: ";
        displayLeafNodes(root);
        cout << endl;
    }

    // Function to display tree level-wise
    void displayLevelWise() {
        cout << "Tree Level-wise: ";
        displayLevelWise(root);
        cout << endl;
    }

    // Function to display parent nodes with their child nodes
    void displayParentChildNodes() {
        cout << "Parent Nodes with their Child Nodes:\n";
        displayParentChild(root);
    }
};

int main() {
    BinarySearchTree bst;
    int choice;

    do {
        cout << "\nBinary Search Tree Operations:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Display Tree (In-order Traversal)\n";
        cout << "5. Display Leaf Nodes\n";
        cout << "6. Display Tree Level-wise\n";
        cout << "7. Display Parent Nodes with their Child Nodes\n";
        cout << "8. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                cout << "Enter the value to insert: ";
                cin >> value;
                bst.insert(value);
                break;
            }
            case 2: {
                int value;
                cout << "Enter the value to delete: ";
                cin >> value;
                bst.deleteValue(value);
                break;
            }
            case 3: {
                int value;
                cout << "Enter the value to search: ";
                cin >> value;
                Node* result = bst.search(value);
                if (result) {
                    cout << value << " found in the tree." << endl;
                } else {
                    cout << value << " not found in the tree." << endl;
                }
                break;
            }
            case 4:
                bst.displayTree();
                break;
            case 5:
                bst.displayLeafNodes();
                break;
            case 6:
                bst.displayLevelWise();
                break;
            case 7:
                bst.displayParentChildNodes();
                break;
            case 8:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 8);

    return 0;
}

//OUTPUT//
/*
Binary Search Tree Operations:
1. Insert
2. Delete
3. Search
4. Display Tree (In-order Traversal)
5. Display Leaf Nodes
6. Display Tree Level-wise
7. Display Parent Nodes with their Child Nodes
8. Exit
Enter your choice: 1
Enter the value to insert: 12


Enter your choice: 1
Enter the value to insert: 15

Enter your choice: 1
Enter the value to insert: 67

Enter your choice: 1
Enter the value to insert: 46

Enter your choice: 1
Enter the value to insert: 38

Binary Search Tree Operations:
1. Insert
2. Delete
3. Search
4. Display Tree (In-order Traversal)
5. Display Leaf Nodes
6. Display Tree Level-wise
7. Display Parent Nodes with their Child Nodes
8. Exit
Enter your choice: 4
In-order Traversal: 12 15 38 46 67

Binary Search Tree Operations:
1. Insert
2. Delete
3. Search
4. Display Tree (In-order Traversal)
5. Display Leaf Nodes
6. Display Tree Level-wise
7. Display Parent Nodes with their Child Nodes
8. Exit
Enter your choice: 5
Leaf Nodes: 38

Binary Search Tree Operations:
1. Insert
2. Delete
3. Search
4. Display Tree (In-order Traversal)
5. Display Leaf Nodes
6. Display Tree Level-wise
7. Display Parent Nodes with their Child Nodes
8. Exit
Enter your choice: 6
Tree Level-wise: 12 Right Child of 12: 15
15 Right Child of 15: 67
67 Left Child of 67: 46
46 Left Child of 46: 38
38

Binary Search Tree Operations:
1. Insert
2. Delete
3. Search
4. Display Tree (In-order Traversal)
5. Display Leaf Nodes
6. Display Tree Level-wise
7. Display Parent Nodes with their Child Nodes
8. Exit
Enter your choice: 7
Parent Nodes with their Child Nodes:
Parent: 12, Right Child: 15
Parent: 15, Right Child: 67
Parent: 67, Left Child: 46
Parent: 46, Left Child: 38

Binary Search Tree Operations:
1. Insert
2. Delete
3. Search
4. Display Tree (In-order Traversal)
5. Display Leaf Nodes
6. Display Tree Level-wise
7. Display Parent Nodes with their Child Nodes
8. Exit
Enter your choice: 3
Enter the value to search: 67
67 found in the tree.

Binary Search Tree Operations:
1. Insert
2. Delete
3. Search
4. Display Tree (In-order Traversal)
5. Display Leaf Nodes
6. Display Tree Level-wise
7. Display Parent Nodes with their Child Nodes
8. Exit
Enter your choice: 2
Enter the value to delete: 15

Binary Search Tree Operations:
1. Insert
2. Delete
3. Search
4. Display Tree (In-order Traversal)
5. Display Leaf Nodes
6. Display Tree Level-wise
7. Display Parent Nodes with their Child Nodes
8. Exit
Enter your choice: 4
In-order Traversal: 12 38 46 67

  */