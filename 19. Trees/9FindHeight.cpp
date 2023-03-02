/*

Code : Find height
Send Feedback
Given a generic tree, find and return the height of given tree.
Input Format:
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, 
number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the 
nodes of the tree is separated by space.  
Output Format :
The first and only line of output prints the height of the given generic tree.
Constraints:
Time Limit: 1 sec
Sample Input 1:
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1:
3

*/

#include<iostream>
#include<queue>
#include"0TreeNode.h"

using namespace std;

TreeNode<int>* takeInputLevelWise()
{
    int rootData;
    cout<<"Enter the root data : ";
    cin>>rootData;

    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);

    while(pendingNodes.size()!=0)
    {
        TreeNode<int>* front=pendingNodes.front();
        pendingNodes.pop();

        cout<<"Enter the number of children of "<<front->data<<endl;

        int numChild;
        cin>>numChild;

        for(int i=0;i<numChild;i++)
        {
            int childData;

            cout<<"Enter "<<i<<" th child of "<<front->data<<endl;
            cin>>childData;

            TreeNode<int>* child = new TreeNode<int>(childData);

            front->children.push_back(child);

            pendingNodes.push(child); 
        }
    }

    return root;
}

void printLevelWise(TreeNode<int>* root)
{
    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);

    while(!pendingNodes.empty())
    {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        cout<<front->data<<" : ";

        for(int i=0;i<front->children.size();i++)
        {
            if(i<(front->children.size()-1))
            {
                cout<<front->children[i]->data<<",";
            }

            else
            {
                cout<<front->children[i]->data;
            }

            pendingNodes.push(front->children[i]);
        }

        cout<<endl;
    }
}

int height(TreeNode <int>* root)
{
    int ans=0;

    for(int i=0;i<root->children.size();i++)
    {
        int childHeight = height(root->children[i]);

        if(childHeight>ans)
        {
            ans=childHeight;
        }
    }

    return ans + 1;
}

int main()
{
    TreeNode<int>* root = takeInputLevelWise();

    cout<<"The height of the tree is : "<<height(root);
}