#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

template<typename T>
class TreeNode
{
    public:

    T data;
    vector<TreeNode<T>*> children;    // We can also use vector<TreeNode*> children;

    TreeNode(T data)
    {
        this->data = data;
    }
};

void printTreeRecursive(TreeNode<int>* root)
{
    cout<<root->data<<":";

    for(int i=0;i<root->children.size();i++)
    {
        cout<<root->children[i]->data<<",";
    }
    
    cout<<endl;

    for(int i=0;i<root->children.size();i++)
    {
        printTreeRecursive(root->children[i]);
    }
}

int main()
{
    // TreeNode<int>* root = new TreeNode<int>(1);
    // TreeNode<int>* child1 = new TreeNode<int>(2);
    // TreeNode<int>* child2 = new TreeNode<int>(3);

    // root->children.push_back(child1);
    // root->children.push_back(child2);

    
}



// 1 3 2 3 4 2 5 6 1 7 1 8 0 0 0 0