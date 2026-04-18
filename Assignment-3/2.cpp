#include <iostream>
using namespace std;

namespace StackModule{

    const int INCREMENT = 5;

    template <typename T>
    class GrowingStack{

    private:                        //access specifier
        T *data;
        int top;
        int capacity;
        const int maxCapacity;      //constant data member
        static int stackCount;      //static member

    public:

        //default constructor
        GrowingStack() : capacity(5), maxCapacity(20){

            data = new T[capacity];
            top = -1;
            stackCount++;
        }

        //overloaded constructor
        GrowingStack(int initialSize, int maxSize) : capacity(initialSize), maxCapacity(maxSize){
            data = new T[capacity];
            top = -1;
            stackCount++;
        }

        //copy constructor
        GrowingStack(const GrowingStack &s) : capacity(s.capacity), maxCapacity(s.maxCapacity){
            this->top = s.top;
            data = new T[capacity];

            for (int i = 0; i <= top; i++)
                data[i] = s.data[i];

            stackCount++;
        }

        //assignment operator
        GrowingStack& operator=(const GrowingStack &s){
            if (this != &s){
                delete[] data;

                capacity = s.capacity;
                top = s.top;
                data = new T[capacity];

                for (int i = 0; i <= top; i++)
                    data[i] = s.data[i];
            }
            return *this;
        }

        //destructor
        ~GrowingStack(){
            delete[] data;
            stackCount--;
        }

        //static member function
        static int getStackCount(){
            return stackCount;
        }

        //check empty
        bool isEmpty() const{
            return (top == -1);
        }

        //check full
        bool isFull() const{
            return (top == capacity - 1);
        }

        //current size
        int currentSize() const{
            return top + 1;
        }

        //get max size
        int getMaxSize() const{
            return maxCapacity;
        }

        //inflate stack
        void inflate(int increment = INCREMENT){
            if (capacity + increment > maxCapacity){
                increment = maxCapacity - capacity;
            }
            if (increment <= 0){
                cout << "max capacity reached\n";
                return;
            }

            T *newData = new T[capacity + increment];

            for (int i = 0; i <= top; i++)
                newData[i] = data[i];

            delete[] data;

            data = newData;
            capacity += increment;

            cout << "Stack capacity increased to " << capacity << endl;
        }

        //push
        void push(T value){
            if (isFull()){

                if (capacity == maxCapacity){
                    cout << "Stack reached maximum capacity, cannot expand.\n";
                    return;
                }

                char choice;
                cout << "Stack is full. Do you want to increase capacity? (y/n): ";
                cin >> choice;

                if (choice == 'y')
                    inflate();
                else{
                    cout << "Push cancelled.\n";
                    return;
                }
            }
            data[++top] = value;
        }

        //pop
        T pop(){

            if (isEmpty()) {
                cout << "Stack empty\n";
                return -1;
            }
            return data[top--];
        }

        //peek
        T peek() const{
            if (isEmpty()){
                cout << "Stack empty\n";
                return -1;
            }
            return data[top];
        }

        //print stack
        void printStack() const{
            if (isEmpty()) {
                cout << "Stack empty\n";
                return;
            }

            cout << "Stack elements (bottom to top): ";

            for (int i = 0; i <= top; i++){
                cout << data[i] << " ";
            }
            cout << endl;
        }
        int getCapacity() const {
            return capacity;
        }
    };

    template <typename T>
    int GrowingStack<T>::stackCount = 0;

}


//----------------------------------------------------------------------

int main(){
    using namespace StackModule;

    int initial1, max1, initial2, max2, initial3, max3;

    cout << "Enter initial and max capacity for Stack 1: ";
    cin >> initial1 >> max1;

    cout << "Enter initial and max capacity for Stack 2: ";
    cin >> initial2 >> max2;

    cout << "Enter initial and max capacity for Stack 3: ";
    cin >> initial3 >> max3;

    GrowingStack<int> stack1(initial1, max1);
    GrowingStack<int> stack2(initial2, max2);
    GrowingStack<int> stack3(initial3, max3);

    int inc, value;
    char choice;

    cout << "\nEnter elements for Stack 1:\n";

    for (int i = 0; i < stack1.getCapacity(); i++){
        cin >> value;
        stack1.push(value);
    }

    cout << "Do you want to increase Stack1 capacity? (y/n): ";
    cin >> choice;

    while ((choice == 'y') && stack1.getCapacity() < stack1.getMaxSize()){
        cout << "Enter increment size: ";
        cin >> inc;
        stack1.inflate(inc);
        cout << "Enter " << inc << " additional elements:\n";

        for (int i = 0; i < inc; i++){
            cin >> value;
            stack1.push(value);
        }
        cout << "Do you want to increase Stack1 capacity again? (y/n): ";
        cin >> choice;
    }

    cout << "\nEnter elements for Stack 2:\n";

    for (int i = 0; i < stack2.getCapacity(); i++){
        cin >> value;
        stack2.push(value);
    }
    cout << "Do you want to increase Stack2 capacity? (y/n): ";
    cin >> choice;

    while ((choice == 'y') && stack2.getCapacity() < stack2.getMaxSize()){
        cout << "Enter increment size: ";
        cin >> inc;
        stack2.inflate(inc);
        cout << "Enter " << inc << " additional elements:\n";

        for (int i = 0; i < inc; i++){
            cin >> value;
            stack2.push(value);
        }
        cout << "Do you want to increase Stack2 capacity again? (y/n): ";
        cin >> choice;
    }


    int count = 1;

    while (!stack1.isEmpty() || !stack2.isEmpty()){ //when either one of the 2 stacks not empty
        if (count % 2 == 1 && !stack1.isEmpty()) //count is odd, s1 not empty, push in s3
            stack3.push(stack1.pop());

        else if (!stack2.isEmpty())  //otherwise s2 push in s3
            stack3.push(stack2.pop());

        else if (!stack1.isEmpty()) //no s2, push s1 in s3
            stack3.push(stack1.pop());

        count++;
    }
    

    cout << "\nElements in Stack3 (top to bottom):\n";

    while (!stack3.isEmpty())
        cout << stack3.pop() << " ";

    cout << "\n\nTotal stacks created: "
         << GrowingStack<int>::getStackCount() << endl;

    return 0;
}