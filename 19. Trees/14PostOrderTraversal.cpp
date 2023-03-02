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

void postOrder(TreeNode<int>* root)
{
    if(root==NULL)
    {
        return;
    }
    
    for(int i=0;i<root->children.size();i++)
    {
        postOrder(root->children[i]);
    }

    cout<<root->data<<" ";
}

int main()
{
    TreeNode<int>* root = takeInputLevelWise();

    cout<<"The postorder traversal of the given tree is : ";
    postOrder(root);
}