#include <iostream>
#include "0BinarySearchTreeNode.h"

using namespace std;

class BST 
{ 
    BinaryTreeNode<int>* root;

    public:

    BST() 
    { 
        root = NULL; 
    } 
    
    ~BST() 
    { 
        delete root; 
    } 
    
    private:

    void print(BinaryTreeNode<int>* root) 
    { 
        if (root == NULL) 
        { 
            return;
        } 
        
        cout << root->data << ":";
        
        if (root->left != NULL) 
        { 
            cout << "L:" << root->left->data << ","; 
        } 
        
        if (root->right != NULL) 
        {
            cout << "R:" << root->right->data; 
        } 
        
        cout << endl; 
        print(root->left); 
        print(root->right); 
    }

    BinaryTreeNode<int>* insert(BinaryTreeNode<int>* node, int data) 
    { 
        if (node == NULL) 
        { 
            BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data); 
            return newNode; 
        }

        if (data <= node->data) 
        { 
            node->left = insert(node->left, data); 
        } 
        
        else 
        { 
            node->right = insert(node->right, data); 
        } 
        
        return node;
    }

    bool search(BinaryTreeNode<int>* node, int data) 
    { 
        if (node == NULL) 
        { 
            return false; 
        } 
        
        if (node->data == data) 
        { 
            return true; 
        } 
        
        else if (data < node->data) 
        { 
            return search(node->left, data); 
        } 
        
        return search(node->right, data); 
    }

    BinaryTreeNode<int>* remove(BinaryTreeNode<int>* node, int data) 
    { 
        if (node == NULL) 
        { 
            return NULL; 
        } 
            
        if (data > node->data) 
        { 
            node->right = remove(node->right, data); 
            return node; 
        } 
        
        else if (data < node->data) 
        { 
            node->left = remove(node->left, data); 
            return node; 
        } 
        
        else 
        { 
            if (node->left == NULL && node->right == NULL) 
            { 
                delete node; 
                return NULL; 
            } 
            
            else if (node->left == NULL) 
            { 
                BinaryTreeNode<int>* temp = node->right;
                node->right = NULL; 
                delete node; 
                return temp; 
            } 
            
            else if (node->right == NULL) 
            { 
                BinaryTreeNode<int>* temp = node->left; 
                node->left = NULL; 
                delete node; 
                return temp; 
            } 
            
            else 
            { 
                BinaryTreeNode<int>* minNode = node->right; 
                
                while (minNode->left != NULL) 
                { 
                    minNode = minNode->left; 
                } 
                
                int rightMin = minNode->data; 
                node->data = rightMin; 
                node->right = remove(node->right, rightMin); 
                return node; 
            } 
        } 
    }
    
    public: 
    
    void print() 
    { 
        print(root); 
    }
    
    void insert(int data) 
    { 
        this->root = insert(this->root, data); 
    }
    
    bool search(int data)
    { 
        return search(root, data); 
    } 

    void remove(int data) 
    { 
        root = remove(root, data); 
    }
};

int main() {
    BST *tree = new BST();

    int choice, input, q;

    cin >> q;

    while (q--) 
    {
        cin >> choice;
        switch (choice) 
        {
            case 1:
            cin >> input;
            tree->insert(input);
            break;

            case 2:
            cin >> input;
            tree->remove(input);
            break;

            case 3:
            cin >> input;
            cout << ((tree->search(input)) ? "true\n" : "false\n");
            break;

            default:
            tree->print();
            break;
        }
    }
}