#include<iostream>

using namespace std;

int main()
{
    int a[10];

    cout<<a<<endl;
    cout<<&a[0]<<endl;

    a[0] = 5;
    a[1] = 10;

    cout<<*a<<endl;
    cout<<*(a+1)<<endl;
    // i[a], a[i] and  *(a+i) all are the same thing

    int *p = &a[0];

    cout<<a<<endl;
    cout<<p<<endl;

    cout<<&p<<endl;
    cout<<&a<<endl;

    cout<<sizeof(a)<<endl;
    cout<<sizeof(p)<<endl;

    // p = p+1; Can do this
    // a = a+1; Can't do this in arrays
}