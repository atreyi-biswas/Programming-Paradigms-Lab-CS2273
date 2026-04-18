#include <iostream>
#include <cstring>
using namespace std;

namespace StudentModule{

    const int NAME = 50;
    const int DEPT = 50;

    template <typename T>
    class Student{
    private:
        char name[NAME];        //student name
        T age;                  //template type for age
        char department[DEPT];  //department name
        int year;               //academic year
        const int id;           //unique ID

        static int count;       //total students created

        //memory pool
        static const int POOL_SIZE = 5;
        static const int OBJECT_SIZE = 128; //approximate size for Student<T>
        static char pool[POOL_SIZE * OBJECT_SIZE]; //raw memory pool
        static bool used[POOL_SIZE];    //track usage

    public:

        //constructor
        Student() : id(++count){
            strcpy(name, "Unknown");
            age = 0;
            strcpy(department, "None");
            year = 0;
        }

        //custom new(allocated from pool)
        void* operator new(size_t size) throw(){
            for (int i = 0; i < POOL_SIZE; i++){
                if (!used[i]){
                    used[i] = true;
                    cout << "Allocated from pool\n";
                    return &pool[i * OBJECT_SIZE];
                }
            }
            cout << "Memory pool exhausted!\n";
            return nullptr;
        }

        //custom delete(return to pool)
        void operator delete(void* ptr){
            for (int i = 0; i < POOL_SIZE; i++){
                if (ptr == &pool[i * OBJECT_SIZE]){
                    used[i] = false;
                    static_cast<Student<T>*>(ptr)->~Student(); //explicit destructor
                    cout << "Returned to pool\n";
                    return;
                }
            }
        }

        //input function
        void ReadStudentData(){
            cout << "Enter Name: ";
            cin >> name;

            cout << "Enter Age: ";
            cin >> age;

            cout << "Enter Department: ";
            cin >> department;

            cout << "Enter Year: ";
            cin >> year;
        }

        //display function
        void PrintStudentData() const{
            cout << "ID: " << id << endl;
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Department: " << department << endl;
            cout << "Year: " << year << endl;
        }

        //static function
        static int GetCount(){
            return count;
        }
    };

    //static initialization
    template <typename T>
    int Student<T>::count = 0;

    template <typename T>
    char Student<T>::pool[POOL_SIZE * OBJECT_SIZE];

    template <typename T>
    bool Student<T>::used[POOL_SIZE] = {false};
}

//----------------------------------------------------------------------

int main(){
    using namespace StudentModule;

    int n;
    cout << "Enter number of students (max 5): ";
    cin >> n;

    if (n > 5){
        cout << "Exceeds pool limit!\n";
        return 0;
    }

    Student<int>* students[5];

    //input students
    for (int i = 0; i < n; i++){
        students[i] = new Student<int>();

        if (students[i] != nullptr){
            cout << "\nStudent " << i+1 << endl;
            students[i]->ReadStudentData();
        }
    }

    //display students
    cout << "\nStudent Details:\n";
    for (int i = 0; i < n; i++){
        if (students[i] != nullptr){
            cout << "------------------\n";
            students[i]->PrintStudentData();
        }
    }

    //free memory
    for (int i = 0; i < n; i++){
        delete students[i];
    }

    cout << "\nTotal Students Created: "
         << Student<int>::GetCount() << endl;

    return 0;
}