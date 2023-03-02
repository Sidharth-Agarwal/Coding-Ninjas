/*

Find Path in BST
Send Feedback
Given a BST and an integer k. Find and return the path from the node with data k and root (if a node with data k is 
present in given BST) in a list. Return empty list otherwise.
Note: Assume that BST contains all unique elements.
Input Format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree 
is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an 
indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.   
The following line of input contains an integer, that denotes the value of k.
Output Format :
The first line and only line of output prints the data of the nodes in the path from node k to root. The data of the 
nodes is separated by single space.
Constraints:
Time Limit: 1 second   
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2
Sample Output 1:
2 5 8

*/

#include<iostream>
#include<vector>
#include<queue>
#include"0BinarySearchTreeNode.h"

using namespace std;

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

vector<int>* getPathInBST(BinaryTreeNode<int>* root, int data)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(root->data == data)
    {
        vector<int>* output = new vector<int>();
        output->push_back(root->data);
        return output;
    }

    else if(data < root->data)
    {
        vector<int>* output = getPathInBST(root->left,data);

        if(output!=NULL)
        {
            output->push_back(root->data);
        }

        return output;
    }

    vector<int>* output = getPathInBST(root->right,data);

    if(output!=NULL)
    {
        output->push_back(root->data);
    }

    return output;
}

int main()
{
    BinaryTreeNode<int>* root = takeInputLevelWise();

    cout<<"Enter the node to find the path : ";

    int data;
    cin>>data;

    vector<int>* output = getPathInBST(root,data);

    for(int i=0;i<output->size();i++)
    {
        cout<<output->at(i)<<" ";
    }
    
    return 0;
}