#include <iostream>
using namespace std;

class Container {
public:
    virtual double volume() = 0; //pure virtual function
    virtual ~Container() {}
};

class Box : public Container {
private:
    double l, w, h;

public:
    Box(double l, double w, double h) {
        this->l = l;
        this->w = w;
        this->h = h;
    }

    double volume() {
        return l*w*h;
    }
};

class Cylinder : public Container {
private:
    double r, h;

public:
    Cylinder(double r, double h) {
        this->r = r;
        this->h = h;
    }

    double volume() {
        return 3.14*r*r*h;
    }
};

class Pyramid : public Container {
private:
    double baseArea, h;

public:
    Pyramid(double b, double h) {
        baseArea = b;
        this->h = h;
    }

    double volume() {
        return (1.0 / 3)*baseArea*h;
    }
};

int main() {
    int n, choice;
    cout << "Enter number of containers: ";
    cin >> n;

    Container **arr = new Container*[n];

    for (int i = 0; i < n; i++) {
        cout << "\nChoose Container Type:\n";
        cout << "1. Box\n2. Cylinder\n3. Pyramid\n";
        cin >> choice;

        if (choice == 1) {
            double l, w, h;
            cout << "Enter length, width, height: ";
            cin >> l >> w >> h;
            arr[i] = new Box(l, w, h);
        }
        else if (choice == 2) {
            double r, h;
            cout << "Enter radius and height: ";
            cin >> r >> h;
            arr[i] = new Cylinder(r, h);
        }
        else if (choice == 3) {
            double b, h;
            cout << "Enter base area and height: ";
            cin >> b >> h;
            arr[i] = new Pyramid(b, h);
        }
        else {
            cout << "Invalid choice! Try again.\n";
            i--;
        }
    }

    double total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i]->volume(); //dynamic polymorphism
    }

    cout << "\nTotal Volume = " << total << endl;

    for (int i = 0; i < n; i++) {
        delete arr[i];
    }
    delete[] arr;

    return 0;
}