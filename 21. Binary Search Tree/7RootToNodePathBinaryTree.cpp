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

vector<int>* getRootToNodePath(BinaryTreeNode<int>* root, int data)
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

    vector<int>* leftOutput = getRootToNodePath(root->left,data);

    if(leftOutput!=NULL)
    {
        leftOutput->push_back(root->data);
        return leftOutput;
    }

    vector<int>* rightOutput = getRootToNodePath(root->right,data);

    if(rightOutput!=NULL)
    {
        rightOutput->push_back(root->data);
        return rightOutput;
    }
    else
    {
        return NULL;
    }
}

int main()
{
    BinaryTreeNode<int>* root = takeInputLevelWise();

    cout<<"Enter the node to find the path : ";

    int data;
    cin>>data;

    vector<int>* output = getRootToNodePath(root,data);
    
    for(int i=0;i<output->size();i++)
    {
        cout<<output->at(i)<<" ";
    }
    
    delete output;
    
    return 0;
}