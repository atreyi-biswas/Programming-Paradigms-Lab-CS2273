#include <iostream>
using namespace std;

namespace StackModule{

    const int INCREMENT = 5;   // Default growth size

    template <typename T>
    class GrowingStack{

    private:
        T *data;               //dynamic array for stack elements
        int top;               //index of top element
        int capacity;          //current capacity
        const int maxCapacity; //max allowed capacity

        static int stackCount; //tracks number of stacks created
        static int MAX_STACKS; //max stacks allowed

    public:

        //constructor with parameters
        GrowingStack(int initialSize, int maxSize)
            : capacity(initialSize), maxCapacity(maxSize){

            //check if stack limit exceeded
            if (stackCount >= MAX_STACKS){
                cout << "Cannot create more stacks. Limit reached.\n";
                exit(0); 
            }

            data = new T[capacity]; //allocate memory
            top = -1;               //stack is empty initially
            stackCount++;           //increment stack count
        }

        //destructor
        ~GrowingStack(){
            delete[] data;   //free memory
            stackCount--;    //decrease count
        }

        //static function to get total stacks
        static int getStackCount(){
            return stackCount;
        }

        //check if stack is empty
        bool isEmpty() const{
            return (top == -1);
        }

        //check if stack is full
        bool isFull() const{
            return (top == capacity - 1);
        }

        //get maximum capacity
        int getMaxSize() const{
            return maxCapacity;
        }

        //get current capacity
        int getCapacity() const{
            return capacity;
        }

        //increase stack capacity dynamically
        void inflate(int increment = INCREMENT){

            //prevent exceeding max capacity
            if (capacity + increment > maxCapacity){
                increment = maxCapacity - capacity;
            }

            if (increment <= 0){
                cout << "Cannot inflate further\n";
                return;
            }

            //create new larger array
            T *newData = new T[capacity + increment];

            //copy old elements
            for (int i = 0; i <= top; i++)
                newData[i] = data[i];

            delete[] data;   //delete old array
            data = newData;  //assign new array
            capacity += increment;

            cout << "Capacity increased to " << capacity << endl;
        }

        //push element into stack
        void push(T value){

            if (isFull()){

                //if already at max capacity
                if (capacity == maxCapacity){
                    cout << "Max capacity reached\n";
                    return;
                }

                //ask user to expand
                char ch;
                cout << "Stack full. Increase capacity? (y/n): ";
                cin >> ch;

                if (ch == 'y')
                    inflate();
                else
                    return;
            }

            data[++top] = value; //insert element
        }

        //pop element from stack
        T pop(){
            if (isEmpty()){
                cout << "Stack empty\n";
                return -1;
            }
            return data[top--]; //return top and decrease index
        }

        //print stack elements
        void printStack(){
            for (int i = 0; i <= top; i++)
                cout << data[i] << " ";
            cout << endl;
        }
    };

    //initialize static variables
    template <typename T>
    int GrowingStack<T>::stackCount = 0;

    template <typename T>
    int GrowingStack<T>::MAX_STACKS = 3;
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