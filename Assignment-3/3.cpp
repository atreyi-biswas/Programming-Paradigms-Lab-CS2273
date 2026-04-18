#include <iostream>
using namespace std;

namespace SwapModule{

    class Point{
    private:
        int x;                  //x coordinate
        int y;                  //y coordinate
        const int id;           //unique id
        static int objectCount; //count objects

    public:

        Point() : x(0), y(0), id(++objectCount){

        }  //default constructor

        Point(int a, int b) : x(a), y(b), id(++objectCount){
    
        } //parameter constructor

        Point(const Point &p) : x(p.x), y(p.y), id(++objectCount){
            
        } //copy constructor

        Point& operator=(const Point &p){   //assignment operator
            if (this != &p){
                this->x = p.x;  //copy x
                this->y = p.y;  //copy y
            }
            return *this;
        }

        void set(int a, int b){
            this->x = a;   //set x
            this->y = b;   //set y
        }

        int getX() const { return x; } //get x
        int getY() const { return y; } //get y

        static int getObjectCount(){
            return objectCount; //return count
        }

        void print() const{
            cout << "(" << x << ", " << y << ")"; //print point
        }
    };

    int Point::objectCount = 0; //initialize to 0

    template <typename T>
    void swapValues(T &a, T &b){
        T temp = a; //store a
        a = b;      //assign b to a
        b = temp;   //assign temp to b
    }
}

int main(){
    using namespace SwapModule;

        int a, b;          //integers
        float f1, f2;      //floats
        double d1, d2;     //doubles
        int x1, y1, x2, y2; //point inputs

        cout << "Enter two integers: ";
        cin >> a >> b; //input int

        cout << "Enter two floats: ";
        cin >> f1 >> f2; //input float

        cout << "Enter two doubles: ";
        cin >> d1 >> d2; //input double

        cout << "Enter x and y for Point 1: ";
        cin >> x1 >> y1; //input p1

        cout << "Enter x and y for Point 2: ";
        cin >> x2 >> y2; //input p2

        Point p1(x1, y1); //create p1
        Point p2(x2, y2); //create p2

        swapValues(a, b);   //swap int
        swapValues(f1, f2); //swap float
        swapValues(d1, d2); //swap double
        swapValues(p1, p2); //swap objects

        cout << "\nAfter swapping:\n";

        cout << "Swapped int:    " << a << " " << b << endl;
        cout << "Swapped float:  " << f1 << " " << f2 << endl;
        cout << "Swapped double: " << d1 << " " << d2 << endl;

        cout << "Swapped Points: ";
        p1.print(); //print p1
        cout << " ";
        p2.print(); //print p2
        cout << endl;

        cout << "\nTotal Point objects created: "
             << Point::getObjectCount() << endl; //show count

        return 0;
}