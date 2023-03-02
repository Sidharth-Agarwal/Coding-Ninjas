#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;
template<typename T>

class BinaryTreeNode
{
	public:

	T data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;

	BinaryTreeNode(T data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }

    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }	
};

// Take input and print recursive
/*
BinaryTreeNode<int>* takeInput()
{
    int rootData;

    cout<<"Enter the data : ";
    cin>>rootData;

    if(rootData == -1)
    {
        return NULL;
    }

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* leftChild = takeInput();
    BinaryTreeNode<int>* rightChild = takeInput();

    root->left = leftChild;
    root->right = rightChild;

    return root;
}

void print(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }

    cout<<root->data<<" : ";

    if(root->left!=NULL)
    {
        cout<<"Left : "<<root->left->data<<" ";
    }

    if(root->right!=NULL)
    {
        cout<<"Right : "<<root->right->data<<endl;
    }

    print(root->left);
    print(root->right);
}

int main()
{
    BinaryTreeNode<int>* root = takeInput();

    print(root);
}
*/

// Take input and print level wise

BinaryTreeNode<int>* takeInputLevelWise()
{
    int rootData;

    cout<<"Enter the root data : ";
    cin>>rootData;

    if(rootData == -1)
    {
        return NULL;
    }

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int>*> pendingNodes;

    pendingNodes.push(root);

    while(!pendingNodes.empty())
    {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        cout<<"Enter the left child of "<<front->data<<endl;

        int leftChildData;
        cin>>leftChildData;

        if(leftChildData != -1)
        {
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }

        cout<<"Enter the right child of "<<front->data<<endl;

        int rightChildData;
        cin>>rightChildData;

        if(rightChildData != -1)
        {
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }

    return root;
}

void printLevelWise(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }

    queue<BinaryTreeNode<int>*> pendingNodes;
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

// Number of nodes in the binary tree
int numNodes(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return 0;
    }

    return 1 + numNodes(root->left) + numNodes(root->right);
}

// Check if the node is present in the tree
bool isPresent(BinaryTreeNode<int>* root, int x)
{
    if(root == NULL)
    {
        return false;
    }

    else if(root->data == x)
    {
        return true;
    }

    return isPresent(root->left,x) || isPresent(root->right,x);
}

// Find the height of the binary tree
int height(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return 0;
    }

    return max(height(root->left), height(root->right)) + 1;
}

// Mirror binary tree
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

void mirrorBinaryTree(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }

    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);

    BinaryTreeNode<int>* tempLeft = root->left;
    root->left = root->right;
    root->right = tempLeft;
}

// In-Order Traversal
void inorder(BinaryTreeNode<int>* root) 
{
	if (root == NULL) 
    {
		return;
	}

	inorder(root->left);

	cout << root->data << " ";

	inorder(root->right);
}

// Pre-Order
void preOrder(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }

    cout<<root->data<<" ";

    preOrder(root->left);
    preOrder(root->right);
}

// Post-Order
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

// Construct Binary Tree from PreOrder and InOrder


int main()
{
    BinaryTreeNode<int>* root = takeInputLevelWise();

    printLevelWise(root);

    mirrorBinaryTree(root);

    printLevelATNewLine(root);
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1