#include <iostream>
using namespace std;

namespace StackModule {

    const int INCREMENT = 5;

    // Example struct
    struct Point {
        int x, y;
    };

    // Template Stack
    template <typename T>
    struct GrowingStack {
        T *data;
        int top;
        int capacity;
        int maxCapacity;
    };

    // initialize
    template <typename T>
    void initialize(GrowingStack<T> &s, int initialSize, int maxSize) {
        s.data = new T[initialSize];
        s.top = -1;
        s.capacity = initialSize;
        s.maxCapacity = maxSize;
    }

    template <typename T>
    inline bool isEmpty(const GrowingStack<T> &s) {
        return (s.top == -1);
    }

    template <typename T>
    bool isFull(const GrowingStack<T> &s) {
        return (s.top == s.capacity - 1);
    }

    template <typename T>
    void inflate(GrowingStack<T> &s, int increment = INCREMENT) {

        if (s.capacity + increment > s.maxCapacity)
            increment = s.maxCapacity - s.capacity;

        if (increment <= 0) {
            cout << "Cannot inflate further\n";
            return;
        }

        T *newData = new T[s.capacity + increment];

        for (int i = 0; i <= s.top; i++)
            newData[i] = s.data[i];

        delete[] s.data;

        s.data = newData;
        s.capacity += increment;

        cout << "Stack capacity increased to " << s.capacity << endl;
    }

    template <typename T>
    void push(GrowingStack<T> &s, T value) {

        if (isFull(s)) {

            if (s.capacity == s.maxCapacity) {
                cout << "Max capacity reached\n";
                return;
            }

            char choice;
            cout << "Stack is full. Increase capacity? (y/n): ";
            cin >> choice;

            if (choice == 'y')
                inflate(s);
            else
                return;
        }

        s.data[++s.top] = value;
    }

    template <typename T>
    T pop(GrowingStack<T> &s) {

        if (isEmpty(s)) {
            cout << "Stack empty\n";
            return T();   // default value
        }

        return s.data[s.top--];
    }

    template <typename T>
    T peek(const GrowingStack<T> &s) {

        if (isEmpty(s)) {
            cout << "Stack empty\n";
            return T();
        }

        return s.data[s.top];
    }

    template <typename T>
    void printStack(GrowingStack<T> s) {

        if (isEmpty(s)) {
            cout << "Stack empty\n";
            return;
        }

        for (int i = 0; i <= s.top; i++)
            cout << s.data[i] << " ";

        cout << endl;
    }

    template <typename T>
    void destroy(GrowingStack<T> &s) {
        delete[] s.data;
        s.data = nullptr;
    }
}

//====================================================================

int main() {

    using namespace StackModule;

    // Different type stacks
    GrowingStack<int> stack1;
    GrowingStack<float> stack2;
    GrowingStack<Point> stack3;

    int initial, max;

    cout << "Enter initial and max capacity for int stack: ";
    cin >> initial >> max;
    initialize(stack1, initial, max);

    cout << "Enter elements (int):\n";
    for (int i = 0; i < initial; i++) {
        int x;
        cin >> x;
        push(stack1, x);
    }

    

    cout << "\nEnter initial and max capacity for float stack: ";
    cin >> initial >> max;
    initialize(stack2, initial, max);

    cout << "Enter elements (float):\n";
    for (int i = 0; i < initial; i++) {
        float x;
        cin >> x;
        push(stack2, x);
    }

    cout << "\nEnter initial and max capacity for Point stack: ";
    cin >> initial >> max;
    initialize(stack3, initial, max);

    cout << "Enter elements (Point x y):\n";
    for (int i = 0; i < initial; i++) {
        Point p;
        cin >> p.x >> p.y;
        push(stack3, p);
    }

    // Output
    cout << "\nInt stack pop:\n";
    while (!isEmpty(stack1))
        cout << pop(stack1) << " ";

    cout << "\nFloat stack pop:\n";
    while (!isEmpty(stack2))
        cout << pop(stack2) << " ";

    cout << "\nPoint stack pop:\n";
    while (!isEmpty(stack3)) {
        Point p = pop(stack3);
        cout << "(" << p.x << "," << p.y << ") ";
    }

    destroy(stack1);
    destroy(stack2);
    destroy(stack3);

    return 0;
}