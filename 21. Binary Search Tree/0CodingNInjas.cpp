#include <iostream>
#include <queue>
#include <stack>
#include <climits>
#include <vector>
using namespace std;

// Binary tree ndoe

template <typename T>
class BinaryTreeNode 
{
	public:

	T data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;

	BinaryTreeNode(T data) 
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}

	~BinaryTreeNode() 
	{
		delete left;
		delete right;
	}
};

// Take input level wise 

BinaryTreeNode<int>* takeInputLevelWise()
{
    int rootData;

    cout<<"Enter root data : ";
    cin>>rootData;

    if(rootData==-1)
    {
        return NULL;
    }

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int>*> pendingNodes;

    pendingNodes.push(root);

    while(pendingNodes.size()!=0)
    {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        cout<<"Enter the left child of "<<front->data<<endl;
        
        int leftChildData;
        cin>>leftChildData;

        if(leftChildData!=-1)
        {
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
            front->left=child;
            pendingNodes.push(child);
        }

        cout<<"Enter the right child of "<<front->data<<endl;

        int rightChildData;
        cin>>rightChildData;

        if(rightChildData!=-1)
        {
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
            front->right=child;
            pendingNodes.push(child);
        }
    }

    return root;
}

// Search in BST



// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1