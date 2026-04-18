#include <iostream>
using namespace std;

namespace StackModule {

    const int INCREMENT = 5;   // default growth step

    // Stack structure
    struct GrowingStack {
        int *data;          //dynamic array
        int top;            //top index
        int capacity;       //current capacity
        int maxCapacity;    //maximum allowed size
    };


    //initialise stack
    void initialize(GrowingStack &s, int initialSize, int maxSize) {

        s.data = new int[initialSize];   //dynamic memory allocation
        s.top = -1;                      //stack starts empty
        s.capacity = initialSize;
        s.maxCapacity = maxSize;
    }


    //check stack empty
    inline bool isEmpty(const GrowingStack &s) {
        return (s.top == -1);
    }


    //check stack full
    bool isFull(const GrowingStack &s) {
        return (s.top == s.capacity - 1);
    }


    //current size
    int currentSize(const GrowingStack &s) {
        return s.top + 1;
    }


    //get max size
    int getMaxSize(const GrowingStack &s) {
        return s.maxCapacity;
    }


    //inflate stack
    void inflate(GrowingStack &s, int increment = INCREMENT) {

        // ensure we do not exceed maximum capacity
        if (s.capacity + increment > s.maxCapacity)   
            increment = s.maxCapacity - s.capacity;

        if (increment <= 0) {
            cout << "Cannot inflate further (max capacity reached)\n";
            return;
        }

        // create new bigger array
        int *newData = new int[s.capacity + increment];

        // copy old elements
        for (int i = 0; i <= s.top; i++)
            newData[i] = s.data[i];

        // delete old memory
        delete[] s.data;

        // update stack
        s.data = newData;
        s.capacity += increment;

        cout << "Stack capacity increased to " << s.capacity << endl;
    }


    //push
    void push(GrowingStack &s, int value) {

    if (isFull(s)) {

        if (s.capacity == s.maxCapacity) {
            cout << "Stack reached maximum capacity, cannot expand.\n";
            return;
        }

        char choice;
        cout << "Stack is full. Do you want to increase capacity? (y/n): ";
        cin >> choice;

        if (choice == 'y') {
            inflate(s);
        }
        else {
            cout << "Push cancelled(entered value that increments the capacity to more than max capacity).\n";
            return;
        }
    }

    s.data[++s.top] = value;
}


    //pop
    int pop(GrowingStack &s) {

        if (isEmpty(s)) {  //stack empty
            cout << "Stack is empty\n";
            return -1;
        }

        return s.data[s.top--];  //remove top element
    }


    //peek
    int peek(const GrowingStack &s) {

        if (isEmpty(s)) {
            cout << "Stack empty\n";
            return -1;
        }

        return s.data[s.top];  //check top value
    }


    //print stack
    void printStack(GrowingStack s) {

        if (isEmpty(s)) {
            cout << "Stack empty\n";
            return;
        }

        cout << "Stack elements (bottom to top): ";

        for (int i = 0; i <= s.top; i++)
            cout << s.data[i] << " ";

        cout << endl;
    }


    //destroy stack
    void destroy(GrowingStack &s) {

        delete[] s.data;
        s.data = nullptr;
        s.top = -1;
        s.capacity = 0;
        s.maxCapacity = 0;
    }
}


//============================================================================

int main() {

    using namespace StackModule;

    GrowingStack stack1, stack2, stack3;

    int initial1, max1, initial2, max2, initial3, max3;

    cout << "Enter initial and max capacity for Stack 1: ";
    cin >> initial1 >> max1;

    cout << "Enter initial and max capacity for Stack 2: ";
    cin >> initial2 >> max2;


    initialize(stack1, initial1, max1);
    initialize(stack2, initial2, max2);
    initialize(stack3, initial1+initial2, 1000);

    int inc, value;
    char choice;

    //Input stack1
    cout << "\nEnter elements for Stack 1:\n";

for (int i = 0; i < stack1.capacity; i++)
{
    cin >> value;
    push(stack1, value);
}

cout << "Do you want to increase Stack1 capacity? (y/n): ";
cin >> choice;

while ((choice == 'y' || choice == 'Y') && stack1.capacity < stack1.maxCapacity)
{
    cout << "Enter increment size: ";
    cin >> inc;

    int remaining = stack1.maxCapacity - stack1.capacity;

    if (inc > remaining)
    {
        cout << "Cannot increase by " << inc << endl;
        cout << "Remaining capacity until maxCapacity: " << remaining << endl;
        cout << "Enter increment size again: ";
        continue;
    }

    inflate(stack1, inc);

    cout << "Enter " << inc << " additional elements:\n";

    for (int i = 0; i < inc; i++)
    {
        cin >> value;
        push(stack1, value);
    }

    if (stack1.capacity == stack1.maxCapacity)
    {
        cout << "Maximum capacity reached.\n";
        break;
    }

    cout << "Do you want to increase Stack1 capacity again? (y/n): ";
    cin >> choice;
}

    //Input stack2

    cout << "\nEnter elements for Stack 2:\n";

for (int i = 0; i < stack2.capacity; i++)
{
    cin >> value;
    push(stack2, value);
}

cout << "Do you want to increase Stack2 capacity? (y/n): ";
cin >> choice;

while ((choice == 'y' ) && stack2.capacity < stack2.maxCapacity)
{
    cout << "Enter increment size: ";
    cin >> inc;

    int remaining = stack2.maxCapacity - stack2.capacity;

    if (inc > remaining)
    {
        cout << "Cannot increase by " << inc << endl;
        cout << "Remaining capacity until maxCapacity: " << remaining << endl;
        cout << "Enter increment size again: ";
        continue;
    }

    inflate(stack2, inc);

    cout << "Enter " << inc << " additional elements:\n";

    for (int i = 0; i < inc; i++)
    {
        cin >> value;
        push(stack2, value);
    }

    if (stack2.capacity == stack2.maxCapacity)
    {
        cout << "Maximum capacity reached.\n";
        break;
    }

    cout << "Do you want to increase Stack2 capacity again? (y/n): ";
    cin >> choice;
}


    //Merge stack1 & stack2 into stack3

    int count = 1;

    while (!isEmpty(stack1) || !isEmpty(stack2)) {

        if (count % 2 == 1 && !isEmpty(stack1))
            push(stack3, pop(stack1));

        else if (!isEmpty(stack2))
            push(stack3, pop(stack2));

        else if (!isEmpty(stack1))
            push(stack3, pop(stack1));

        count++;
    }


    cout << "\nElements in Stack3 (top to bottom):\n";

    while (!isEmpty(stack3))
        cout << pop(stack3) << " ";


    destroy(stack1);
    destroy(stack2);
    destroy(stack3);

    return 0;
}
