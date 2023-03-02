/*
Reverse a Stack

You have been given two stacks that can store integers as the data. Out of the two given stacks, one is populated 
and the other one is empty. You are required to write a function that reverses the populated stack using the 
one which is empty.

Input Format :
The first line of input contains an integer N, denoting the total number of elements in the stack.

The second line of input contains N integers separated by a single space, representing the order in which the 
elements are pushed 
into the stack.
Output Format:
The only line of output prints the order in which the stack elements are popped, all of them separated by a 
single space. 
Note:
You are not required to print the expected output explicitly, it has already been taken care of. Just make the 
changes in the input stack itself.
Constraints:
1 <= N <= 10^3
-2^31 <= data <= 2^31 - 1

Time Limit: 1sec 

Sample Input 1:
6
1 2 3 4 5 10
Note:
Here, 10 is at the top of the stack.

Sample Output 1:
1 2 3 4 5 10
Note:
Here, 1 is at the top of the stack.

Sample Input 2:
5
2 8 15 1 10

Sample Output 2:
2 8 15 1 10

*/

#include<iostream>
#include<stack>

using namespace std;

/*
void reverseStack(stack<int> &s1, stack<int> &s2) 
{
    int x;
	while(!s1.empty())
    {
        x=s1.top();
        s2.push(x);
        s1.pop();
    }
    s1=s2;
}
*/

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