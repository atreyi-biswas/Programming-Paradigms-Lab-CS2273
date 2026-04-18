#include <iostream>
using namespace std;

namespace SortModule
{
    struct Point
    {
        int x, y;
    };

    // Generic sorting function (Bubble Sort)
    template <typename T>
    void sortArray(T arr[], int n){
        for (int i = 0; i < n - 1; i++){
            for (int j = 0; j < n - i - 1; j++){
                if (arr[j] > arr[j + 1]){
                    T temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    // Generic print function
    template <typename T>
    void printArray(T arr[], int n){
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
}

int main()
{
    using namespace SortModule;

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    //integers

    int intArr[n];
    cout << "\nEnter " << n << " integers:\n";
    for (int i = 0; i < n; i++){
        cin >> intArr[i];
    }

    sortArray(intArr, n);

    cout << "Sorted integers: ";
    printArray(intArr, n);

    //short integers

    short shortArr[n];
    cout << "\nEnter " << n << " short integers:\n";
    for (int i = 0; i < n; i++){
        cin >> shortArr[i];
    }

    sortArray(shortArr, n);

    cout << "Sorted short integers: ";
    printArray(shortArr, n);

    //float

    float floatArr[n];
    cout << "\nEnter " << n << " floats:\n";
    for (int i = 0; i < n; i++){
        cin >> floatArr[i];
    }

    sortArray(floatArr, n);

    cout << "Sorted floats: ";
    printArray(floatArr, n);

    //double

    double doubleArr[n];
    cout << "\nEnter " << n << " doubles:\n";
    for (int i = 0; i < n; i++){
        cin >> doubleArr[i];
    }

    sortArray(doubleArr, n);

    cout << "Sorted doubles: ";
    printArray(doubleArr, n);

    //struct

    int m;
    cout << "\nEnter number of points: ";
    cin >> m;

    Point p[m];

    cout << "Enter " << m << " points (x y):\n";
    for (int i = 0; i < m; i++){
        cin >> p[i].x >> p[i].y;
    }

    // sortArray(p, m);  // This will NOT work
    cout << "Sorted struct: ";
    printArray(p,m);
    cout << "\nTemplate sorting does not work for struct because '>' operator is undefined.\n";

    return 0;
}