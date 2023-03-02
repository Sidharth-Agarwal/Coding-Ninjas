#include<iostream>

using namespace std;

int main()
{
    char str[] = "abcde"; // Points to the temporary memory and the can be used without any errors
    // char *pstr[] = "abcde"; // Points to the memory itself and can give error
    int a[] = {1,2,3};
    char b[] = "abc";

    cout<<a<<endl;
    cout<<b<<endl;
    
    char *c = &b[0];
    cout<<c<<endl;

    char c1 = 'a';
    char *pc = &c1;

    cout<<c1<<endl;
    cout<<pc<<endl;
}