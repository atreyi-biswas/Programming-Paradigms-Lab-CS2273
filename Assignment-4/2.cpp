#include <iostream>
#include <cstring>
using namespace std;

class Person {
protected:
    char name[50];
    int age;
    char gender[10];

public:
    void readPerson() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Gender: ";
        cin >> gender;
    }

    void displayPerson() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
    }
};

class Employee : public Person {
protected:
    int empID;
    double salary;

public:
    void readEmployee() {
        readPerson();
        cout << "Enter EmpID: ";
        cin >> empID;
        cout << "Enter Salary: ";
        cin >> salary;
    }

    void displayEmployee() {
        displayPerson();
        cout << "EmpID: " << empID << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Developer : public Employee {
private:
    char department[50], skillSet[50], project[50];
    int experience;

public:
    void read() {
        readEmployee();
        cout << "Department: "; cin >> department;
        cout << "SkillSet: "; cin >> skillSet;
        cout << "Project: "; cin >> project;
        cout << "Experience: "; cin >> experience;
    }

    void display() {
        displayEmployee();
        cout << "Department: " << department << endl;
        cout << "SkillSet: " << skillSet << endl;
        cout << "Project: " << project << endl;
        cout << "Experience: " << experience << endl;
    }
};

class SystemAdmin : public Employee {
private:
    int workload;

public:
    void read() {
        readEmployee();
        cout << "Workload: ";
        cin >> workload;
    }

    void display() {
        displayEmployee();
        cout << "Workload: " << workload << endl;
    }
};

class Trainee : public Person {
private:
    char department[50], skillSet[50];
    int duration;
    double stipend;

public:
    void read() {
        readPerson();
        cout << "Department: "; cin >> department;
        cout << "SkillSet: "; cin >> skillSet;
        cout << "Duration: "; cin >> duration;
        cout << "Stipend: "; cin >> stipend;
    }

    void display() {
        displayPerson();
        cout << "Department: " << department << endl;
        cout << "SkillSet: " << skillSet << endl;
        cout << "Duration: " << duration << endl;
        cout << "Stipend: " << stipend << endl;
    }
};

// Client
int main() {
    Developer d;
    SystemAdmin s;
    Trainee t;

    cout << "\nEnter Developer Details:\n";
    d.read();

    cout << "\nEnter SystemAdmin Details:\n";
    s.read();

    cout << "\nEnter Trainee Details:\n";
    t.read();

    cout << "\nDeveloper: \n";
    d.display();

    cout << "\nSystemAdmin: \n";
    s.display();

    cout << "\nTrainee: \n";
    t.display();

    return 0;
}