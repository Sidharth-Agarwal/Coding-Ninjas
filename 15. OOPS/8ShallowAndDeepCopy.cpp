#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Student
{
    int age;
    
    public:
    char *name;

    Student(int age,char *name)
    {
        this->age=age;

        // Shallow Copy
        // this->name=name

        // Deep Copy

        this->name=new char[strlen(name)+1];
        strcpy(this->name,name);
    }

    // Copy constructor

    Student(Student const &s)
    {
        this->age=age;

        //Shallow copy
        //this->name=s.name

        //Deep Copy

        this->name=new char[strlen(s.name)+1];
        strcpy(this->name,name);
    }

    void display()
    {
        cout<<name<<" "<<age<<endl;
    }
};

int main()
{
    char name[]="abcd";

    Student s1(20,name);

    s1.display();

    name[3]='e';
    Student s2(24,name);
    
    s2.display();

    s1.display();

    name[0]='x';
    Student s3(s2);
    s3.display();
    s2.display();

    return 0;
}