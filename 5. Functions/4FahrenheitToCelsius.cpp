#include<iostream>

using namespace std;

void printTable(int start, int end, int step) 
{
    int c=1;
    
    for(int i=start;i<=end;i=i+step)
    {
        c=(i-32)*5/9;
        cout<<i<<"\t"<<c<<endl;
    }
}

int main()
{
    int start, end, step;
    cin >> start >> end >> step;
  
    printTable(start, end, step);
}