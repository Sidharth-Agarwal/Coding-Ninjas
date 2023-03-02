/*

Code : Find a node
Send Feedback
For a given Binary Tree of integer type and a number X, find whether a node exists in the tree with data X or not.
Input Format:
The first line of each test case contains elements of the first tree in the level order form. The line consists of 
values of nodes separated by a single space. In case a node is null, we take -1 in its place.

The second line of each test case contains the node value you have to find.


For example, the input for the tree depicted in the below image would be:
example

1
2 3
4 -1 5 6
-1 7 -1 -1 -1 -1
-1 -1
Explanation:
Level 1:
The root node of the tree is 1

Level 2:
Left child of 1 = 2
Right child of 1 = 3

Level 3:
Left child of 2 = 4
Right child of 2 = null (-1)
Left child of 3 = 5
Right child of 3 = 6

Level 4:
Left child of 4 = null (-1)
Right child of 4 = 7
Left child of 5 = null (-1)
Right child of 5 = null (-1)
Left child of 6 = null (-1)
Right child of 6 = null (-1)

Level 5:
Left child of 7 = null (-1)
Right child of 7 = null (-1)

The first not-null node(of the previous level) is treated as the parent of the first two nodes of the current level. 
The second not-null node (of the previous level) is treated as the parent node for the next two nodes of the current 
level and so on.
The input ends when all nodes at the last level are null(-1).
Note:
The above format was just to provide clarity on how the input is formed for a given tree.
The sequence will be put together in a single line separated by a single space. Hence, for the above-depicted tree, 
the input will be given as:

1 2 3 4 -1 5 6 -1 7 -1 -1 -1 -1 -1 -1
Output Format:
The only line of output prints 'true' or 'false'.

The output of each test case should be printed in a separate line.
Note:
You are not required to print anything explicitly. It has already been taken care of.
Constraints:
1 <= N <= 10^5

Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec.
Sample Input 1:
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
7
Sample Output 1:
true
Explanation For Output 1:
Clearly, we can see that 7 is present in the tree. So, the output will be true.
Sample Input 2:
2 3 4 -1 -1 -1 -1
10
Sample Output 2:
false

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

bool isPresent(BinaryTreeNode<int>* root,int x)
{
    if(root==NULL)
    {
        return false;
    }

    else if(root->data == x)
    {
        return true;
    }

    return isPresent(root->left,x) || isPresent(root->right,x);
}

int main()
{
    BinaryTreeNode<int>* root = takeInputLevelWise();

    printLevelWise(root);

    int x;

    cin >> x;
    cout << ((isPresent(root, x)) ? "true" : "false");
}