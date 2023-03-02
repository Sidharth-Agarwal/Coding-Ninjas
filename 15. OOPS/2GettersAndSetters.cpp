#include<iostream>

using namespace std;

class Student
{
    public:
        int rollNumber;

    private:
        int age;

    public:
        void display()
        {
            cout<<rollNumber<<" "<<age;
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

    Student *s2=new Student;

    s2->setAge(21,12);
    //s6->age=24;
    s2->rollNumber=104;

    cout<<(*s2).rollNumber<<endl;
    cout<<(*s2).getAge()<<endl;

    return 0;
}