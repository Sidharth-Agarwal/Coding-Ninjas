/*
Number Pattern 2
Send Feedback
Print the following pattern
Pattern for N = 4
   1
  12
 123
1234
The dots represent spaces.



Input Format :
N (Total no. of rows)
Output Format :
Pattern in N lines
Sample Input :
5
Sample Output :


The dots represent spaces.
*/

#include<iostream>
using namespace std;


int main()
{
    int n;
    cin>>n;
    
    int i=1;
    int a=1;
    
    while(i<=n)
    {
        int k=1;
        
        while(k<=n-i)
        {
            cout<<" ";
            k++;
        }
        
        int j=1;
        a=i;
        
        while(j<=i)
        {
            cout<<a;
            a++;
            j++;
        }
        cout<<endl;
        i++;
    }
    return 0;
}