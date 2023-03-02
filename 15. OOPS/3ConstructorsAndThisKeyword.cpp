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
            cout<<rollNumber<<" "<<age<<endl;
        }

        void setAge(int a,int pass)
        {
            if(pass!=123)
            {
                return;
            }

            if(a<0)
            {
                return;
            }
            age=a;
        }

        int getAge()
        {
            return age;
        }
};

int main()
{
    // creating object statically 

    Student s1;

    s1.setAge(20,123);
    s1.rollNumber=101;
    //s1.age=10;

    cout<<s1.rollNumber<<endl;
    cout<<s1.getAge()<<endl;

    //creating object dynamically

    Student *s2=new Student(100);

    s2->setAge(21,12);
    //s6->age=24;
    s2->rollNumber=104;
    s2->display();

    Student *s3=new Student(101);
    (*s3).display();

    Student s4(40,401);
    s4.display();

    return 0;
}