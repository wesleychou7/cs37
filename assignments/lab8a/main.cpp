#include<iostream>
using namespace std;

int main(){

    long value1{200000}; // 200,000
    long value2{0};

    /*
    a) Declare the variable longPtr to be a pointer to an object of type long
    b) Assign the address of variable value1 to pointer variable longPtr
    c) Display the value of the object pointed to by longPtr
    d) Assign the value of the object pointed to by longPtr to variable value2
    e) Display the value of value2
    f) Display the address of value1
    g) Display the address stored in longPtr
    */

    // A
    long* longPtr = 0;

    // B
    longPtr = &value1;

    // C
    cout << "Value of the object pointed to by longPtr: " << *longPtr << endl;

    // D
    value2 = *longPtr;

    // E
    cout << "The value of value2: " << value2 << endl;

    // F
    cout << "The address of value1: " << &value1 << endl;

    // G
    cout << "The address stored in longPtr: " << longPtr << endl;
    
    return 0;
}