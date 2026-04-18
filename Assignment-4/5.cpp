#include <iostream>
using namespace std;

//abstract base class(shape)
class Shape {
public:
    virtual double area() = 0;
    virtual void display() = 0;
    virtual ~Shape() {}
};

//rectangle
class Rectangle : public Shape {
    double l, b;
public:
    Rectangle(double l, double b) : l(l), b(b) {}
    double area() { return l * b; }
    void display() {
        cout << "Rectangle Area: " << area() << endl;
    }
};

//circle
class Circle : public Shape {
    double r;
public:
    Circle(double r) : r(r) {}
    double area() { return 3.14 * r * r; }
    void display() {
        cout << "Circle Area: " << area() << endl;
    }
};

//triangle
class Triangle : public Shape {
    double b, h;
public:
    Triangle(double b, double h) : b(b), h(h) {}
    double area() { return 0.5 * b * h; }
    void display() {
        cout << "Triangle Area: " << area() << endl;
    }
};

class ShapeStack {
    Shape* arr[100];
    int top;

public:
    ShapeStack() { top = -1; }

    void push(Shape* s) {
        arr[++top] = s;
    }

    void pop() {
        if (top >= 0) delete arr[top--];
    }

    void display() {
        for (int i = 0; i <= top; i++)
            arr[i]->display();
    }

    double totalAreaCovered() {
        double sum = 0;
        for (int i = 0; i <= top; i++)
            sum += arr[i]->area();
        return sum;
    }
};

int main() {
    ShapeStack s;

    s.push(new Rectangle(2, 3));
    s.push(new Circle(2));
    s.push(new Triangle(3, 4));

    s.display();
    cout << "Total Area: " << s.totalAreaCovered();

    return 0;
}