#include<iostream>

using namespace std;

class Student
{
    public:
        int rollNumber;

    private:
        int age;

    public:
        //default constructor
        Student()
        {
            cout<<"Constructor 1 called"<<endl;
        }

        // parameterized constructor
        Student(int rollNumber)
        {
            cout<<"Constructor 2 called"<<endl;
            this->rollNumber=rollNumber;
        }

        Student(int age,int rollNumber)
        {
            cout<<"Constructor 3 called"<<endl;
            this->age=age;
            this->rollNumber=rollNumber;
        }

        void display()
        {
            cout<<rollNumber<<" "<<age;
        }
};

int main()
{
    Student s1;  // Constructor 1 called

    Student s2(20);  // Constructor 2 called

    Student s3(30,100);  // Constructor 3 called

    Student s4(s3);  // Copy Constructor

    s1=s2;  // Copy Assignment Operator

    Student s5=s4;  // Copy Constructor
}