/*
Nth Fibonacci Number
Send Feedback
Nth term of Fibonacci series F(n), where F(n) is a function, is calculated using the following formula -
    F(n) = F(n-1) + F(n-2), 
    Where, F(1) = F(2) = 1
Provided N you have to find out the Nth Fibonacci Number.
Input Format :
The first line of each test case contains a real number ‘N’.
Output Format :
For each test case, return its equivalent Fibonacci number.
Constraints:
1 <= N <= 10000     
Where ‘N’ represents the number for which we have to find its equivalent Fibonacci number.

Time Limit: 1 second
Sample Input 1:
6
Sample Output 1:
8
Explanation of Sample Input 1:
Now the number is ‘6’ so we have to find the “6th” Fibonacci number
So by using the property of the Fibonacci series i.e 

[ 1, 1, 2, 3, 5, 8]
So the “6th” element is “8” hence we get the output.
*/

#include<iostream>
using namespace std;


int main()
{    
    int n;
    cin>>n;
    
    int f0=1,f1=1;
    
    int fib=0;
    
    if(n==1)
    {
        cout<<f0;
    }
    
    else if(n==2)
    {
        cout<<f1;
    }
    
    else
    {
        for(int i=1;i<n-1;i++)
        {
        	fib=f0+f1;
            f0=f1;
            f1=fib;
    	}
        
        cout<<fib;
    }
}

#include<iostream> 
using namespace std; 

int main()
{ 
    int n; 
    cin>>n; 
    
    int a=0; 
    int b=1; 
    int c; 
    
    for(int i = 0; i < n; i++)
    { 
        c = a + b; 
        a = b; 
        b = c; 
    } 
    cout << a; 
}