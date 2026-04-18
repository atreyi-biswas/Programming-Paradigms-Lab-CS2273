#include <iostream>
#include <cstring>

using namespace std;

namespace StudentModule
{
    const int NAME = 50;  //max name length
    const int DEPT = 50;  //max department name length

    struct Student
    {
        char name[NAME];
        int age;
        char department[DEPT];
        int year;
    };

    // Inline function(separate entries of students)
    inline void PrintLine()
    {
        cout << "--------------------------------------\n";
    }

    // Function to read data (Call by Reference)
    void ReadStudentData(Student &s)
    {
        cout << "Enter Name: ";
        cin >> s.name;

        cout << "Enter Age: ";
        cin >> s.age;

        cout << "Enter Department: ";
        cin >> s.department;

        cout << "Enter Year: ";
        cin >> s.year;
    }

    // Function overloading (static polymorphism)
    void PrintStudentData(const Student &s)
    {
        cout << "Name:        " << s.name << endl;
        cout << "Age:         " << s.age << endl;
        cout << "Department:  " << s.department << endl;
        cout << "Year:        " << s.year << endl;
    }

    void PrintStudentData(const Student arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            PrintLine();
            PrintStudentData(arr[i]);
        }
    }
}

int main()
{
    using namespace StudentModule;

    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student *students = new Student[n];  //dynamic allocation

    for (int i = 0; i < n; i++)
    {
        cout << "\nStudent " << i + 1 << endl;
        ReadStudentData(students[i]);
    }

    cout << "\nStudent Details:\n";
    PrintStudentData(students, n);

    delete[] students;   //to avoid memory leak

    return 0;
}
