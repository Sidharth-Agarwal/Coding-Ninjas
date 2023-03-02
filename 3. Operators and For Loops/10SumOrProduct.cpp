#include<iostream>
using namespace std;

int main() {
	// Write your code here
	int n;
    cin>>n;
    
    int c;
    cin>>c;
    
    int product=1,sum=0;
    
    if(c==1)
    {
        for(int i=1;i<=n;i++)
        {
            sum+=i;
        }
        cout<<sum;
    }
    else if(c==2)
    {
        for(int i=1;i<=n;i++)
        {
            product*=i;
        }
        cout<<product;
    }
    else
    {
        cout<<-1;
    }
}