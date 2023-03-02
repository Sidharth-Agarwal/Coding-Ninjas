#include<iostream>

using namespace std;

class Student
{
    public:

    int age;
    const int rollNumber;
    int &x;  // Age reference variable

    Student(int rollNumber,int age) : rollNumber(rollNumber),age(age),x(this->age)
    {

    }
};

int main()
{
    Student s1(101,20);
}