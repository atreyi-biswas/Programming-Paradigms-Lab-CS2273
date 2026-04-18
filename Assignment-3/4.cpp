#include <iostream>
using namespace std;

class ComplexNumber{
private:
    int real, imag; //real and imaginary parts

public:
    ComplexNumber(int r, int i){  //constructor
        real = r; 
        imag = i; 
    }

    ComplexNumber plus(const ComplexNumber &c){
        return ComplexNumber(real + c.real, imag + c.imag); //add
    }

    ComplexNumber minus(const ComplexNumber &c){
        return ComplexNumber(real - c.real, imag - c.imag); //subtract
    }

    void display(){
        cout << real << " + " << imag << "i" << endl; //print
    }
};

int main(){

    int r1, i1, r2, i2; //input variables

    cout << "Enter real and imaginary part of first complex number: ";
    cin >> r1 >> i1; //input c1

    cout << "Enter real and imaginary part of second complex number: ";
    cin >> r2 >> i2; //input c2

    ComplexNumber c1(r1, i1); //create c1
    ComplexNumber c2(r2, i2); //create c2

    ComplexNumber sum = c1.plus(c2);   //add
    ComplexNumber diff = c1.minus(c2);  //subtract

    cout << "Sum: ";
    sum.display(); //display sum

    cout << "Difference: ";
    diff.display(); //display difference

    return 0;
}