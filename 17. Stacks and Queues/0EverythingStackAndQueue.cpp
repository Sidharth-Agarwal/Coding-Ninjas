#include<iostream>
#include<climits>
#include<string>

using namespace std;

// Stack using static array
/*
class StackUsingStaticArray
{
    int *data;
    int nextIndex;
    int capacity;

    public:

    StackUsingStaticArray(int totalSize)
    {
        data = new int[totalSize];
        capacity = totalSize;
        nextIndex = 0;
    }

    // Return the number of elements in the stack
    int size()
    {
        return nextIndex;
    }

    // Check if the stack is empty or not
    bool isEmpty()
    {
        return nextIndex == 0;
    }

    // Insert elements in the stack
    void push(int element)
    {
        if(nextIndex == capacity)
        {
            cout<<"Stack is full!"<<endl;
            return;
        }

        data[nextIndex] = element;
        nextIndex++;
    }

    // Return the top elements
    int top()
    {
        if(isEmpty())
        {
            cout<<"Stack is empty!"<<endl;
            return INT_MIN;
        }

        return data[nextIndex-1];
    }

    // Delete element from the stack
    int pop()
    {
        if(isEmpty())
        {
            cout<<"Stack is empty!"<<endl;
            return INT_MIN;
        }

        nextIndex--;
        return data[nextIndex];
    }
};

int main()
{
    StackUsingStaticArray s(4);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout<<s.top()<<endl;

    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;

    cout<<s.size()<<endl;

    cout<<s.isEmpty()<<endl;
}
*/

// Stack using dynamic array
/*
class StackUsingDynamicArray
{
    int *data;
    int nextIndex;
    int capacity;

    public:

    StackUsingDynamicArray()
    {
        data = new int[4];
        nextIndex = 0;
        capacity = 4;
    }

    // Retrun the number of element in the stack
    int size()
    {
        return nextIndex;
    }

    // Check if the stack is empty
    bool isEmpty()
    {
        return nextIndex == 0;
    }

    // Insert an element in the stack
    void push(int element)
    {
        if(nextIndex == capacity)
        {
            int *newData = new int[2*capacity];

            for(int i=0;i<capacity;i++)
            {
                newData[i] = data[i];
            }

            capacity *= 2;
            delete [] data;
            data = newData;
        }

        data[nextIndex] = element;
        nextIndex++;
    }

    // Return the top element from the stack
    int top()
    {
        if(isEmpty())
        {
            cout<<"Stack is empty!"<<endl;
            return INT_MIN;
        }

        return data[nextIndex-1];
    }

    // Delete element from the stack
    // Delete element from the stack
    int pop()
    {
        if(isEmpty())
        {
            cout<<"Stack is empty!"<<endl;
            return INT_MIN;
        }

        nextIndex--;
        return data[nextIndex];
    }
};

int main() 
{
	StackUsingDynamicArray s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);

	cout << s.top() << endl;

	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;

	cout << s.size() << endl;

	cout << s.isEmpty() << endl;
}
*/

// Stack using templates
/*
template<typename T>

class StackUsingTemplate
{
    T *data;
    int nextIndex;
    int capacity;

    public:

    StackUsingTemplate()
    {
        data = new T[4];
        nextIndex = 0;
        capacity = 4;
    }

    // Return the number of elements in the stack
    int size()
    {
        return nextIndex;
    }

    // Check if the stack is empty
    bool isEmpty()
    {
        return nextIndex == 0;
    }

    // Insert element in the stack
    void push(T element)
    {
        if(nextIndex == capacity)
        {
            T *newData = new T[2*capacity];

            for(int i=0;i<capacity;i++)
            {
                newData[i] = data[i];
            }

            capacity *= 2;
            delete [] data;
            data = newData;
        }

        data[nextIndex] = element;
        nextIndex++;
    }

    // Return the top element from the stack
    T top()
    {
        if(isEmpty())
        {
            cout<<"Stack is empty"<<endl;
            return 0;
        }

        nextIndex--;
        return data[nextIndex];
    }

    // Delete element from the top of the stack
    T pop()
    {
        if(isEmpty())
        {
            cout<<"Stack is empty"<<endl;
            return 0;
        }

        nextIndex--;
        return data[nextIndex];
    }
};

int main()
{
	StackUsingTemplate<char> s;
	s.push(100);
	s.push(101);
	s.push(102);
	s.push(103);
	s.push(104);

	cout << s.top() << endl;

	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;

	cout << s.size() << endl;

	cout << s.isEmpty() << endl;
}
*/

// Stack using linked list
/*
template <typename T>
class Node 
{
	public :

	T data;
	Node<T> *next;

	Node(T data) 
    {
		this -> data = data;
		next = NULL;
	}
};

template <typename T>
class StackUsingLinkedList 
{
	Node<T> *head;
	int size;		// number of elements prsent in stack

	public :

	StackUsingLinkedList() 
    {
		head = NULL;
		size = 0;
	}

    // Return the number of element in the stack
	int getSize() 
    {
		return size;
	}

    // Check is the stack is empty
	bool isEmpty() 
    {
		return size == 0;
	}
    
    // Insert an element in the stack
	void push(T element) 
    {
		Node<T> *newNode = new Node<T>(element);
		newNode -> next = head;
		head = newNode;
		size++;
	}

    // Return the top element from the stack
	T top() 
    {
		if(isEmpty()) 
        {
			return 0;		
		}

		return head -> data;
	}

    // Delete element from the top of the stack
	T pop() 
    {
		if(isEmpty()) 
        {
			return 0;		
		}

		T ans = head -> data;
		Node<T> *temp = head;
		head = head -> next;
		delete temp;
		size--;
		return ans;
	}
};

int main()
{
	StackUsingLinkedList<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);

	cout << s.top() << endl;

	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;

	cout << s.getSize() << endl;

	cout << s.isEmpty() << endl;
}
*/


// In-Built Stack
/*
#include <stack>

int main() 
{
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	s.push(60);

	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;

	cout << s.size() << endl;
	cout << s.empty() << endl;
}
*/

// Balanced Parenthesis
/*
#include<stack>

bool isBalancedParenthesis(string str)
{
    stack<int> s;

    for(int i=0;i<str.length();i++)
    {
        if(str[i] == '(')
        {
            s.push(str[i]);
        }

        else if(str[i] == ')')
        {
            if(s.empty())
            {
                return false;
            }

            char topChar = s.top();
            s.pop();

            if(str[i] == ')' && topChar == '(')
            {
                continue;
            }

            else
            {
                return false;
            }
        }
    }

    return s.empty();
}

int main()
{
    string s;
    cin>>s;

    cout << ((isBalancedParenthesis(s)) ? "true" : "false");
}
*/

// Queue Using Static Arrays
/*
template<typename T>
class QueueUsingStaticArray
{
    T *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

    public:

    QueueUsingStaticArray(int s)
    {
        data = new T[s];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = s;
    }

    // Return the number of element present in the queue
    int getSize()
    {
        return size;
    }

    // Check if the queue is empty
    bool isEmpty()
    {
        return size == 0;
    }

    // Insert an element in the queue
    void enqueue(T element)
    {
        if(size == capacity)
        {
            cout<<"Queue is full"<<endl;
            return;
        }

        data[nextIndex] = element;
        nextIndex = (nextIndex+1)%capacity;

        if(firstIndex == -1)
        {
            firstIndex=0;
        }

        size++;
    }
    
    // Return the front element form the queue
    T front()
    {
        if(isEmpty())
        {
            cout<<"Queue is empty";
            return 0;
        }

        return data[firstIndex];
    }

    // Delete an element from the queue
    T dequeue()
    {
        if(isEmpty())
        {
            cout<<"Queue is empty";
            return 0;
        }

        T ans = data[firstIndex];
        firstIndex = (firstIndex+1)%capacity;
        size--;

        if(size == 0)
        {
            firstIndex = -1;
            nextIndex = 0;
        }

        return ans;
    }
};

int main()
{
    QueueUsingStaticArray<int> q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    cout<<q.front()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    cout<<q.getSize()<<endl;

    cout<<q.isEmpty()<<endl;
}
*/

// Queue using dynamic array
/*
template<typename T>
class QueueUsingDynamicArray
{
    T *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

    public:

    QueueUsingDynamicArray(int s)
    {
        data = new T[s];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = s;
    }

    // Return the number of element present in the queue
    int getSize()
    {
        return size;
    }

    // Check if the queue is empty
    bool isEmpty()
    {
        return size == 0;
    }

    // Insert an element in the queue
    void enqueue(T element)
    {
        if(size == capacity)
        {
            T *newData = new T[2*capacity];

            int j = 0;

            for(int i=firstIndex;i<capacity;i++)
            {
                newData[j] = data[i];
                j++;
            }

            for(int i=0;i<firstIndex;i++)
            {
                newData[j] = data[i];
                j++;
            }

            delete [] data;
            data = newData;
            firstIndex = 0;
            nextIndex = capacity;
            capacity *= 2;
        }

        data[nextIndex] = element;
        nextIndex = (nextIndex+1)%capacity;

        if(firstIndex == -1)
        {
            firstIndex=0;
        }

        size++;
    }
    
    // Return the front element form the queue
    T front()
    {
        if(isEmpty())
        {
            cout<<"Queue is empty";
            return 0;
        }

        return data[firstIndex];
    }

    // Delete an element from the queue
    T dequeue()
    {
        if(isEmpty())
        {
            cout<<"Queue is empty";
            return 0;
        }

        T ans = data[firstIndex];
        firstIndex = (firstIndex+1)%capacity;
        size--;

        if(size == 0)
        {
            firstIndex = -1;
            nextIndex = 0;
        }

        return ans;
    }
};

int main()
{
    QueueUsingDynamicArray<int> q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    cout<<q.front()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    cout<<q.getSize()<<endl;

    cout<<q.isEmpty()<<endl;
}
*/

// Queue Using Linked List
/*
template <typename T>
class Node
{
	public:

	T data;
	Node<T> *next;

	Node(T data) 
    {
		this -> data = data;
		next = NULL;
	}
};

template <typename T>
class Queue 
{
	Node<T> *head;
	Node<T> *tail;
	int size;

	public : 

	Queue() 
    {
		head = NULL;
		tail = NULL;
		size = 0;
	}

    // Return the number of element in the queue
	int getSize() 
    {
		return size;
	}
    
    // Check if the queue is empty
	bool isEmpty() 
    {
		return size == 0;
	}

    // Insert an element in the queue
	void enqueue(T element) 
    {
		Node<T> *newNode = new Node<T>(element);

		if(head == NULL) 
        {
			head = newNode;
			tail = newNode;
		}

		else 
        {
			tail -> next = newNode;
			tail = newNode;
		}

		size++;
	}

    // Return the front element from the queue
	T front() 
    {
		if(isEmpty()) 
        {
			return 0;
		}

		return head -> data;	
	}

    // Delete an element from the queue
	T dequeue() 
    {
		if(isEmpty()) 
        {
			return 0;
		}

		T ans = head -> data;
		Node<T> *temp = head;
		head = head -> next;
		delete temp;
		size--;
		return ans;
	}
};

int main() 
{
	Queue<int> q;

	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.enqueue(60);


	cout << q.front() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;

	cout << q.getSize() << endl;
	cout << q.isEmpty() << endl;
}
*/

// In-Built Queue

/*
#include <queue>

int main() 
{
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);
	q.push(60);

	cout << q.front() << endl;
	q.pop();
	cout << q.front() << endl;
	cout << q.size() << endl;
	cout << q.empty() << endl;

	while(!q.empty()) 
	{
		cout << q.front() << endl;
		q.pop();
	}
}
*/

// Reverse a Stack
/*
#include<stack>

void reverseStack(stack<int> &input,stack<int> &extra)
{
    if(input.size()<=1)
    {
        return;
    }

    int lastElement=input.top();
    input.pop();

    reverseStack(input,extra);

    while(!input.empty())
    {
        int top=input.top();
        input.pop();
        extra.push(top);
    }

    input.push(lastElement);

    while(!extra.empty())
    {
        int top=extra.top();
        extra.pop();
        input.push(top);
    }
}

int main()
{
    stack<int> input,extra;

    int size;
    cout<<"Enter the size : ";
    cin>>size;

    for (int i = 0, val; i < size; i++) 
    {
        cin >> val;
        input.push(val);
    }

    reverseStack(input, extra);

    while (!input.empty()) 
    {
        cout << input.top() << " ";
        input.pop();
    }
}
*/

// Reverse a queue
/*
#include<queue>

void reverseQueue(queue<int> &input)
{
    if(input.size() <= 1)
    {
        return;
    }

    int front = input.front();
    input.pop();

    reverseQueue(input);

    input.push(front);
}

int main() 
{
    queue<int> q;
    int size;
    cin >> size;

    for (int i = 0, val; i < size; i++) 
    {
        cin >> val;
        q.push(val);
    }

    reverseQueue(q);

    while (!q.empty()) 
    {
        cout << q.front() << " ";
        q.pop();
    }
}
*/

// Check redundant brackets

#include<stack>

bool checkRedundantBrackets(string expression)
{

}

int main() 
{
    string input;
    cin >> input;
    
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}

// Stock Span
/*
#include<stack>

int *stockSpan(int *price, int n)
{
    int *span = new int[n];

    span[0] = 1;

    stack<int> s;
    
    s.push(0);

    for(int i=1;i<n;i++)
    {
        while(!s.empty() && price[i] > price[s.top()])
        {
            s.pop();
        }

        if(s.empty())
        {
            span[i] = i+1;
        }

        else
        {
            span[i] = i-s.top();
        }
        s.push(i);
    }

    return span;
}

int main() 
{
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> input[i];
    }

    int *output = stockSpan(input, size);

    for (int i = 0; i < size; i++) 
    {
        cout << output[i] << " ";
    }

    cout << "\n";

    delete[] input;
    delete[] output;
}
*/

// Minimum Bracket Reversal
/*
#include<stack>

int countBracketReversals(string input)
{
    int len = input.length();

    if(len == 0)
    {
        return 0;
    }

    if(len%2!=0)
    {
        return -1;
    }

    stack<char> stack;

    for(int i=0;i<len;i++)
    {
        char currChar = input[i];

        if(currChar == '{')
        {
            stack.push(currChar);
        }

        else
        {
            if(!stack.empty() && stack.top() == '{')
            {
                stack.pop();
            }
            else
            {
                stack.push(currChar);
            }
        }
    }

    int count = 0;

    while(!stack.empty())
    {
        char c1 = stack.top();
        stack.pop();

        char c2 = stack.top();
        stack.pop();

        if(c1!=c2)
        {
            count += 2;
        }

        else
        {
            count += 1;
        }
    }

    return count;
}

int main() {
    string input;
    cin >> input;

    cout << countBracketReversals(input);
}
*/