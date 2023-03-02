/*
Code : Mirror Number Pattern
Send Feedback

Input format :
Integer N (Total no. of rows)
Output format :
Pattern in N lines
Constraints
0 <= N <= 50
Sample Input 1:
3
Sample Output 1:
    1 
   12
  123
Sample Input 2:
4
Sample Output 2:
   1 
  12
 123
1234

*/

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    int i=1;
    
    while(i<=n)
    {
        int j=1;
        
        int k=1;
        
        while(k<=n-i)
        {
            cout<<" ";
            k++;
        }
        
        while(j<=i)
        {
            cout<<j;
            j++;
        }
        
        cout<<endl;
        i++;
    }
}