#include<iostream>

using namespace std;

#include "0Student.cpp"

int main()
{
    // creating object statically 
    Student s1;
    Student s2;

    s1.rollNumber=101;
    s1.age=10;

    cout<<s1.rollNumber<<endl;
    cout<<s1.age<<endl;

    Student s3,s4,s5;

    //creating object dynamically 
    Student *s6=new Student;

    s6->age=24;
    s6->rollNumber=104;

    cout<<(*s6).rollNumber<<endl;
    cout<<(*s6).age<<endl;

    return 0;
}