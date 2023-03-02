#include <iostream>
#include <queue>
#include <climits>

using namespace std;

template <typename T>
class BinaryTreeNode 
{
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) 
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() 
    {
        if (left) delete left;
        if (right) delete right;
    }
};

BinaryTreeNode<int> *takeInput() 
{
    int rootData;
    cin >> rootData;

    if (rootData == -1) 
    {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while (!q.empty()) 
    {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();

        int leftChild, rightChild;
        cin >> leftChild;
        if (leftChild != -1) 
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        cin >> rightChild;
        if (rightChild != -1) 
        {
            BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int maximum(BinaryTreeNode<int> *root)
{
    if(root == NULL)
    {
        return INT_MIN;
    }

    return max(root->data , max(maximum(root->left) , maximum(root->right)));
}

int minimum(BinaryTreeNode<int> *root)
{
    if(root == NULL)
    {
        return INT_MAX;
    }

    return min(root->data , min(minimum(root->left) , minimum(root->right)));
}

bool isBST(BinaryTreeNode<int> *root)
{
    if(root == NULL)
    {
        return true;
    }

    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);

    bool output = (root->data > leftMax) && (root->data < rightMin) && isBST(root->left) && isBST(root->right);

    return output;
}

class IsBSTReturn 
{
	public:
		bool isBST;
		int minimum;
		int maximum;
};

IsBSTReturn isBST2(BinaryTreeNode<int>* root) 
{
	if (root == NULL) 
    {
		IsBSTReturn output;
		output.isBST = true;
		output.minimum = INT_MAX;
		output.maximum = INT_MIN;
		return output;
	}

	IsBSTReturn leftOutput = isBST2(root->left);
	IsBSTReturn rightOutput = isBST2(root->right);

	int minimum = min(root->data, min(leftOutput.minimum, rightOutput.minimum));
	int maximum = max(root->data, max(leftOutput.maximum, rightOutput.maximum));

	bool isBSTFinal = (root->data > leftOutput.maximum) && (root->data <= rightOutput.minimum) &&
		leftOutput.isBST && rightOutput.isBST;

	IsBSTReturn output;
	output.minimum = minimum;
	output.maximum = maximum;
	output.isBST = isBSTFinal;
    
	return output;
}

bool isBST3(BinaryTreeNode<int>* root, int min = INT_MIN, int max = INT_MAX) 
{
	if (root == NULL) 
    {
		return true;
	}

	if (root->data < min || root->data > max) 
    {
		return false;
	}

	bool isLeftOk = isBST3(root->left, min, root->data - 1);
	bool isRightOk = isBST3(root->right, root->data, max);

	return isLeftOk && isRightOk;
}


int main() 
{
    BinaryTreeNode<int>* root = takeInput();

    cout << (isBST(root) ? "true" : "false");

    IsBSTReturn output = isBST2(root);

    cout << endl <<((output.isBST)? "true" : "false"); 
}