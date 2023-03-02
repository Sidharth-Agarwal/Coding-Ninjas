#include <iostream>

using namespace std;

class Student
{
    int rollNumber;
    int age;

    static int totalStudents; // total numbers of students present

    public:
    Student()
    {
        totalStudents++;
    }

    static int getTotalStudent()
    {
        return totalStudents;
    }
};

int Student :: totalStudents = 0; // inintialize static data members

int main()
{
    Student s1;

    Student s2;

    Student s3, s4, s5;

    cout << Student::getTotalStudent() << endl;
}