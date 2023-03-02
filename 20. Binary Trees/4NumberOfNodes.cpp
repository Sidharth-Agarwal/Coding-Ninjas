#include<iostream>
#include<queue>
#include"0BinaryTreeNode.h"

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

void printLevelWise(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return;
    }

    queue<BinaryTreeNode<int>*>pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty())
    {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        if(front == NULL)
        {
            cout<<endl;

            if(!pendingNodes.empty())
            {
                pendingNodes.push(NULL);
            }
        }

        else
        {
            cout<<front->data<<":";
            cout<<"L:";

            if(front->left)
            {
                pendingNodes.push(front->left);
                cout<<front->left->data<<",";
            }
            else
            {
                cout<<-1<<",";
            }

            cout<<"R:";

            if(front->right)
            {
                pendingNodes.push(front->right);
                cout<<front->right->data<<"\n";
            }

            else
            {
                cout<<-1<<"\n";
            }
        }
    }
}

int numNodes(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }

    return 1+numNodes(root->left)+numNodes(root->right);
}

int main()
{
    BinaryTreeNode<int>* root = takeInputLevelWise();

    printLevelWise(root);

    cout<<numNodes(root);
}