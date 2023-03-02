/*

Code : Count leaf nodes
Send Feedback
Given a generic tree, count and return the number of leaf nodes present in the given tree.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, 
number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the 
nodes of the tree is separated by space.  
Output Format :
The first and only line of output prints the count of leaf nodes present in the given tree.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
4

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
        TreeNode <int>* front=pendingNodes.front();
        pendingNodes.pop();

        cout<<"Enter the number of children of "<<front->data<<endl;

        int numChild;
        cin>>numChild;

        for(int i=0;i<numChild;i++)
        {
            int childData;

            cout<<"Enter "<<i<<" th child of "<<front->data<<endl;
            cin>>childData;

            TreeNode<int>* child=new TreeNode<int>(childData);

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
        TreeNode<int>* front=pendingNodes.front();
        pendingNodes.pop();

        cout<<front->data<<":";

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

int getLeafNodes(TreeNode<int>* root)
{
    int count = 0;

    if(root->children.size()==0)
    {
        count++;
    }

    for(int i=0;i<root->children.size();i++)
    {
        count += getLeafNodes(root->children[i]);
    }

    return count;
}

int main()
{
    TreeNode<int>* root = takeInputLevelWise();

    int leafNodes = getLeafNodes(root);

    cout<<"Number of leaf nodes : "<<leafNodes;  
}