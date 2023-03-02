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

void printAtLevelK(TreeNode<int>* root, int k) 
{
	if (root == NULL) 
    {
		return;
	}

	if (k == 0) 
    {
		cout <<"The node at the required level are : "<<root->data << endl;
		return;
	}

	for (int i = 0; i < root->children.size(); i++) 
    {
		printAtLevelK(root->children[i], k - 1);
	}
}

int main()
{
    TreeNode<int>* root = takeInputLevelWise();

    int k;
    
    cout<<"Enter the level to print the node : ";
    cin>>k;

    printAtLevelK(root,k);
}