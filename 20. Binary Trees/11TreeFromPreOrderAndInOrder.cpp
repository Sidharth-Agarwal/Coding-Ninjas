/*

Code: Construct Tree from Preorder and Inorder
Send Feedback
For a given preorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary 
tree using the given two arrays/lists. You just need to construct the tree and return the root.
Note:
Assume that the Binary Tree contains only unique elements. 
Input Format:
The first line of input contains an integer N denoting the size of the list/array. It can also be said that N is the 
total number of nodes the binary tree would have.

The second line of input contains N integers, all separated by a single space. It represents the preorder-traversal of 
the binary tree.

The third line of input contains N integers, all separated by a single space. It represents the inorder-traversal of 
the binary tree.
Output Format:
The given input tree will be printed in a level order fashion where each level will be printed on a new line. 
Elements on every level will be printed in a linear fashion. A single space will separate them.
Constraints:
1 <= N <= 10^4
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
7
1 2 4 5 3 6 7 
4 2 5 1 6 3 7 
Sample Output 1:
1 
2 3 
4 5 6 7 
Sample Input 2:
6
5 6 2 3 9 10 
2 6 3 9 5 10 
Sample Output 2:
5 
6 10 
2 3 
9 

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

void printLevelATNewLine(BinaryTreeNode<int> *root) 
{
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) 
    {
        BinaryTreeNode<int> *first = q.front();
        q.pop();

        if (first == NULL) 
        {
            if (q.empty()) 
            {
                break;
            }

            cout << endl;
            q.push(NULL);
            continue;
        }

        cout << first->data << " ";

        if (first->left != NULL) 
        {
            q.push(first->left);
        }
        if (first->right != NULL) 
        {
            q.push(first->right);
        }
    }
}

BinaryTreeNode<int> *buildTreeHelper(int *preOrder, int preStart, int preEnd ,int *inOrder, int inStart, int inEnd)
{
    if(preStart > preEnd || inStart > inEnd)
    {
        return NULL;
    }

    int rootVal = preOrder[preStart];

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootVal);

    //find root element index from inorder array
    int k=0;

    for(int i=inStart;i<=inEnd;i++)
    {
        if(rootVal == inOrder[i])
        {
            k=i;
            break;
        }
    }

    root->left = buildTreeHelper(preOrder,preStart+1,preStart+(k-inStart),inOrder,inStart,k-1);

    root->right = buildTreeHelper(preOrder,preStart+(k-inStart)+1,preEnd,inOrder,k+1,inEnd);

    return root;
}

BinaryTreeNode<int>* buildTree(int *preOrder,int preLength,int *inOrder, int inLength)
{
    int preStart = 0;
    int preEnd = preLength-1;
    int inStart = 0;
    int inEnd = inLength-1;

    return buildTreeHelper(preOrder,preStart,preEnd,inOrder,inStart,inEnd);
}

int main() 
{
    int size;
    cin >> size;

    int *pre = new int[size];
    int *in = new int[size];

    for (int i = 0; i < size; i++) 
    {
        cin >> pre[i];
    }

    for (int i = 0; i < size; i++) 
    {
        cin >> in[i];
    }

    BinaryTreeNode<int> *root = buildTree(pre, size, in, size);

    printLevelATNewLine(root);
}