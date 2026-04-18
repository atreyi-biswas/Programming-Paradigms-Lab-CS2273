#include <iostream>
#include <cstring>

using namespace std;

namespace StudentModule{
    const int NAME = 50;  //max name length
    const int DEPT = 50;  //max department name length

    //Class Template
    template <typename T>
    class Student{
    private:
        char name[NAME];
        int age;
        char department[DEPT];
        int year;
        const int id;            //constant data member

        static int count;        //static data member

    public:

        // Default Constructor(no parameters, called when obj is created without any arguments)
        Student() : id(++count){
            strcpy(this->name, "\0"); //set current name to null
            this->age = 0;
            strcpy(this->department, "\0");
            this->year = 0;
        }

        // Overloaded Constructor(different parameters))
        Student(const char n[], int a, const char d[], int y) : id(++count){
            strcpy(this->name, n);
            this->age = a;
            strcpy(this->department, d);
            this->year = y;
        }

        // Copy Constructor(copies one object to another)
        Student(const Student &s) : id(++count){
            strcpy(this->name, s.name);
            this->age = s.age;
            strcpy(this->department, s.department);
            this->year = s.year;
        }

        //Assignment Operator(one obj gets updated to another obj))
        Student& operator=(const Student &s){
            if (this != &s){
                strcpy(this->name, s.name);
                this->age = s.age;
                strcpy(this->department, s.department);
                this->year = s.year;
            }
            return *this;
        }

        //function to read data
        void ReadStudentData(){
            cout << "Enter Name: ";
            cin >> this->name;

            cout << "Enter Age: ";
            cin >> this->age;

            cout << "Enter Department: ";
            cin >> this->department;

            cout << "Enter Year: ";
            cin >> this->year;
        }

        //Print student
        void PrintStudentData() const{
            cout << "ID:          " << id << endl;
            cout << "Name:        " << name << endl;
            cout << "Age:         " << age << endl;
            cout << "Department:  " << department << endl;
            cout << "Year:        " << year << endl;
        }

        // Static member function
        static int GetCount(){
            return count;  //static member
        }
    };

    // Static member initialization outside class
    template <typename T>
    int Student<T>::count = 0;

    inline void PrintLine(){
        cout << "--------------------------------------\n";
    }


    //function overloading
    template <typename T>
    void PrintStudentData(const Student<T> arr[], int n){
        for (int i = 0; i < n; i++){
            PrintLine();
            arr[i].PrintStudentData();
        }
    }
}

int main(){
    using namespace StudentModule;

    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student<int> *students = new Student<int>[n];  //default constructor

    for (int i = 0; i < n; i++){
        cout << "\nStudent " << i + 1 << endl;
        students[i].ReadStudentData();
    }

    char name[50], dept[50];
    int age, year;

    cout << "\nEnter details for Overloaded Constructor:\n";
    cout << "Name: "; cin >> name;
    cout << "Age: "; cin >> age;
    cout << "Department: "; cin >> dept;
    cout << "Year: "; cin >> year;

    Student<int> s1(name, age, dept, year);  // overloaded constructor

    // copy constructor
    Student<int> s2 = s1;

    // assignment operator
    Student<int> s3;
    s3 = s1;

    cout << "\nArray Students:\n";
    PrintStudentData(students, n);

    cout << "\nOverloaded Constructor Object:\n";
    s1.PrintStudentData();

    cout << "\nCopy Constructor Object:\n";
    s2.PrintStudentData();

    cout << "\n Assignment Operator Object:\n";
    s3.PrintStudentData();

    cout << "\nTotal Students Created: "
         << Student<int>::GetCount() << endl;

    delete[] students;

    return 0;
}
