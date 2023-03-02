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
            
        }

        // parameterized constructor
        Student(int rollNumber)
        {
            this->rollNumber=rollNumber;
        }

        Student(int age,int rollNumber)
        {
            this->age=age;
            this->rollNumber=rollNumber;
        }

        void display()
        {
            cout<<rollNumber<<" "<<age;
        }

        ~Student()
        {
            cout<<"Destructor Called"<<endl;
        }
};

int main()
{
    //Copy Constructor

    Student s1(20,101);
    Student s2(s1);
    
    Student *s3=new Student(20,201);
    Student *s4=new Student(*s3);

    Student s5(*s3);
    Student *s6=new Student(s1);

    //Copy Assignment Operator

    Student s7(30,301);
    Student s8(40,401);

    Student *s9=new Student(50,501);

    s7=s8;

    *s9=s7;

    s8=*s9;

    //Dynamic Objects
    
    delete s3;
    delete s4;
    delete s6;
    delete s9;
}