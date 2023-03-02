#include<iostream>
#include<climits>

using namespace std;

// Node class
class Node
{
    public:

    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

// Print a linked list
void print(Node *head)
{
    Node* temp = head;

    while(temp)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// Take input
Node* takeInput()
{
    int data;
    cin>>data;

    Node* head = NULL;

    while(data!=-1)
    {
        Node* newNode = new Node(data);

        if(head == NULL)
        {
            head = newNode;
        }

        else
        {
            Node* temp = head;

            while(temp)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        cin>>data;
    }

    return head;
}

// Take input Better way
Node* takeInputBetter()
{
    int data;
    cin>>data;

    Node* head = NULL;
    Node* tail = NULL;

    while(data!=-1)
    {
        Node* newNode = new Node(data);

        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
        }

        else
        {
            tail->next = newNode;
            tail = tail->next;
        }

        cin>>data;
    }

    return head;
}

// Length of linked list
int length(Node *head)
{
    int length;

    while(head)
    {
        head = head->next;
        length++;
    }

    return length;
}

// Print ith Node
void printIthNode(Node* head, int i)
{
    int position = 0;

    Node* temp = head;

    while(temp!=NULL && position < i)
    {
        temp = temp->next;
        position++;
    }

    if(temp!=NULL)
    {
        cout<<temp->data;
    }
}

//Insert Node
Node* insertNode(Node* head, int i, int data)
{
    Node* newNode = new Node(data);
    int count = 0;
    Node* temp = head;

    if(i == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }

    while(temp!=NULL && count < i-1)
    {
        count++;
        temp = temp->next;
    }

    if(temp!=NULL)
    {
        Node *a = temp->next;
        temp->next = newNode;
        newNode->next = a;
    }

    return head;
}

// Delete Node
Node* deleteNode(Node* head, int i)
{
    int count = 0;
    Node* temp = head;

    if(head == NULL)
    {
        return head;
    }

    if(i == 0)
    {
        return head->next;
    }

    while(temp!=NULL && count < i-1)
    {
        count++;
        temp = temp->next;
    }

    if(temp == NULL || temp->next == NULL)
    {
        return head;
    }

    temp->next = temp->next->next;

    return head;
}

// Length of Linked List recursive
int lengthRecursive(Node *head)
{
    if(head == NULL)
    {
        return 0;
    }

    return 1 + length(head->next);
}

// Insert Node recursively
Node *insertNodeRecursively(Node* head, int i, int data)
{
    if(head == NULL)
    {
        if(i == 0)
        {
            Node* newNode = new Node(data);
            return newNode;
        }
        return head;
    }

    Node* newNode = new Node(data);

    if(i == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }

    head->next = insertNodeRecursively(head->next,i-1,data);

    return head;
}

// Delete node recursively
Node* deleteNodeRecursively(Node* head, int i)
{
    if(head == NULL)
    {
        return head;
    }

    if(i == 0)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    head->next = deleteNodeRecursively(head->next, i-1);

    return head;
}

// Find a node in linked list
int findNode(Node* head, int data)
{
    int pos = 0;

    while(head!=NULL)
    {
        if(head->data == data)
        {
            return pos;
        }
        pos++;
        head = head->next;
    }

    return -1;
}

// Append last to first
Node* appendLastToFirst(Node* head, int n)
{
    if(n == 0 || head == NULL)
    {
        return head;
    }

    Node* fast = head;
    Node* slow = head;
    Node* initialHead = head;

    for(int i=0;i<n;i++)
    {
        fast = fast->next;
    }

    while(fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    Node* temp = slow->next;
    slow->next = NULL;
    fast->next = initialHead;
    head = temp;

    return head;
}

// Eliminate duplicates
Node* removeDuplicates(Node* head)
{
    if(head == NULL)
    {
        return head;
    }

    Node* temp = head;

    while(temp->next != NULL)
    {
        if(temp->data == temp->next->data)
        {
            temp->next = temp->next->next;
        }
        temp = temp->next;
    }

    return head;
}

// Print reverse of a linked list
void printReverse(Node* head)
{
    if(head == NULL)
    {
        return;
    }

    printReverse(head->next);

    cout<<head->data<<" ";
}

// Palindrome linked list
Node *reverseLinkedList(Node *head) 
{ 
    Node *curr = head; 
    Node *prev = NULL;
    Node *fwd = NULL;
     
    while (curr != NULL) 
    { 
        fwd = curr->next; 
        curr->next = prev; 
        prev = curr; 
        curr = fwd; 
    } 
    
    return prev; 
} 

bool isPalindrome(Node *head) 
{ 
    if (head == NULL || head->next == NULL) 
    { 
        return true;
    } 
    
    // Find center of list 
    Node *fast = head; 
    Node *slow = head; 
    
    while (fast->next != NULL && fast->next->next != NULL) 
    { 
        fast = fast->next->next; 
        slow = slow->next; 
    } 
    
    Node *secondHead = slow->next; 
    slow->next = NULL; 
    secondHead = reverseLinkedList(secondHead); 
    
    //Compare the two sublists 
    
    Node *firstSubList = head; 
    Node *secondSubList = secondHead; 
    
    bool ans = true;
    
    while (secondSubList != NULL) 
    { 
        if (firstSubList->data != secondSubList->data) 
        { 
            ans = false; 
            break; 
        } 
        
        firstSubList = firstSubList->next; 
        secondSubList = secondSubList->next; 
    } 
    
    //Rejoin the two sublists 
    firstSubList = head; 
    secondSubList = reverseLinkedList(secondHead); 
    
    while(firstSubList->next != NULL) 
    { 
        firstSubList = firstSubList->next; 
    } 
    
    firstSubList->next = secondSubList; 
    
    return ans; 
}

// Mid point of a linked list
Node *midPoint(Node *head) 
{ 
    if (head == NULL || head->next == NULL) 
    { 
        return head; 
    } 
    
    Node *slow = head, *fast = head->next; 
    
    while (fast != NULL && fast->next != NULL) 
    { 
        slow = slow->next; 
        fast = fast->next->next; 
    } 
    
    return slow; 
}

// Merge two sorted linked list
Node* mergeTwoSortedLinkedLists(Node* head1, Node* head2)
{
    if(head1 == NULL)
    {
        return head2;
    }

    if(head2 == NULL)
    {
        return head1;
    }

    Node* newHead = NULL;
    Node* newTail = NULL;

    if(head1->data < head2->data)
    {
        newHead = head1;
        newTail = head1;
        head1 = head1->next;
    }

    else
    {
        newHead = head2;
        newTail = head2;
        head2 = head2->next;
    }

    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data < head2->data)
        {
            newTail->next = head1;
            newTail = newTail->next;
            head1 = head1->next;
        }

        else
        {
            newTail->next = head2;
            newTail = newTail->next;
            head2 = head2->next;
        }
    }

    if(head1 != NULL)
    {
        newTail->next = head1;
    }

    if(head2 != NULL)
    {
        newTail->next = head2;
    }

    return newHead;
}

// Merge Sort
Node* mergeSort(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    Node* mid = midPoint(head);

    Node* half1 = head;
    Node* half2 = mid->next;

    mid->next = NULL;

    half1 = mergeSort(half1);
    half2 = mergeSort(half2);

    Node* newHead = mergeTwoSortedLinkedLists(half1,half2);

    return newHead;
}

// Reverse linked list recursive
Node* reverseLinkedListRecursive(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    Node* smallHead = reverseLinkedListRecursive(head->next);

    head->next->next = head;
    head->next = NULL;
    
    return smallHead;
}

//Reverse linked list iterative
Node* reverseLinkedListIterative(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    Node* curr = head;
    Node* fwd = NULL;
    Node* prev = NULL;

    while(curr != NULL)
    {
        fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
    }

    return prev;
}

// Find a node recursive
int findNodeRecursive(Node* head, int n)
{
    if(head == NULL)
    {
        return -1;
    }

    else if(head->data == n)
    {
        return 0;
    }

    int smallAns = findNodeRecursive(head->next,n);

    if(smallAns == -1)
    {
        return -1;
    }

    return smallAns + 1;
}

// Even after odd linked list
Node* evenAfterOdd(Node* head)
{
    if(head == NULL)
    {
        return head;
    }

    Node* evenHead = NULL;
    Node* evenTail = NULL;
    Node* oddHead = NULL;
    Node* oddTail = NULL;

    while(head!=NULL)
    {
        if(head->data%2 == 0)
        {
            if(evenHead == NULL)
            {
                evenHead = head;
                evenTail = head;
            }

            else
            {
                evenTail->next = head;
                evenTail = evenTail->next;
            }
        }

        else
        {
            if(oddHead == NULL)
            {
                oddHead = head;
                oddTail = head;
            }

            else
            {
                oddTail->next = head;
                oddTail = oddTail->next;
            }
        }

        head = head->next;
    }

    if (oddHead == NULL) 
    { 
        return evenHead; 
    } 

    else 
    {
        oddTail->next = evenHead; 
    }

    if (evenHead != NULL) 
    { 
        evenTail->next = NULL; 
    } 
    
    return oddHead; 
}

// Delete every n Node


//Swap two nodes


// k Reverse
Node* kReverse(Node* head, int k)
{
    if(k == 0 || k == 1)
    {
        return head;
    }

    Node* curr = head;
    Node* fwd = NULL;
    Node* prev = NULL;

    int count = 0;

    while(count < k && curr != NULL)
    {
        fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
        count++;
    }

    if(fwd!=NULL)
    {
        head->next = kReverse(fwd,k);
    }

    return prev;
}

int main()
{
	Node *head = takeInputBetter();

	int k;
	cin >> k;

	head = kReverse(head, k);

	print(head);
	
	return 0;
}

// Bubble sort iterative

