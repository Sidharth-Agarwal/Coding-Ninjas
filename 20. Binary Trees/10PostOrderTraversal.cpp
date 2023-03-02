/*

Postorder Binary Tree
Send Feedback
For a given Binary Tree of integers, print the post-order traversal.
Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 
is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.
Output Format:
The only line of output prints the post-order traversal of the given binary tree.
Constraints:
1 <= N <= 10^6
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
 Sample Output 1:
4 5 2 6 7 3 1 
Sample Input 2:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
 Sample Output 1:
2 9 3 6 10 5 

*/

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

void postOrder(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);

    cout<<root->data<<" ";
}

int main()
{
    BinaryTreeNode<int>* root = takeInputLevelWise();

    printLevelWise(root);

    postOrder(root);
}