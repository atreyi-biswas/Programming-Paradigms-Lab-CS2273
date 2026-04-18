#include <iostream>
using namespace std;

namespace SwapModule
{
    struct Point
    {
        int x;
        int y;
    };

    // template swap function
    template <typename T>
    void swapValues(T &a, T &b)
    {
        T temp = a;
        a = b;
        b = temp;
    }

    // function to print struct
    void print(Point p)
    {
        cout << "(" << p.x << ", " << p.y << ")";
    }
}

int main()
{
    using namespace SwapModule;

    int a, b;
    float f1, f2;
    double d1, d2;
    Point p1, p2;

    // user input
    cout << "Enter two integers: ";
    cin >> a >> b;

    cout << "Enter two floats: ";
    cin >> f1 >> f2;

    cout << "Enter two doubles: ";
    cin >> d1 >> d2;

    cout << "Enter x and y for Point 1: ";
    cin >> p1.x >> p1.y;

    cout << "Enter x and y for Point 2: ";
    cin >> p2.x >> p2.y;

    // swapping
    swapValues(a, b);
    swapValues(f1, f2);
    swapValues(d1, d2);
    swapValues(p1, p2);

    // output
    cout << "\nAfter swapping:\n";

    cout << "Swapped int:    " << a << " " << b << endl;
    cout << "Swapped float:  " << f1 << " " << f2 << endl;
    cout << "Swapped double: " << d1 << " " << d2 << endl;

    cout << "Swapped struct: ";
    print(p1);
    cout << " ";
    print(p2);
    cout << endl;

    return 0;
}
