#include <iostream>
#include "MyInteger.h"
using namespace std;

int main(){

    cout << "Wesley Chou \n\n";

    MyInteger num1(4);
    MyInteger num2(6);

    // get
    cout << "Getting num1: " << num1.get() << endl;
    cout << "Getting num2: " << num2.get() << endl;


    // set
    int setNum1 = 10;
    int setNum2 = 20;

    cout << "\nSetting num1 to " << setNum1 << endl;
    num1.set(setNum1);
    cout << "num1 is set to " << num1.get() << endl;

    cout << "\nSetting num2 to " << setNum2 << endl;
    num2.set(setNum2);
    cout << "num2 is set to " << num2.get() << endl;


    // add
    int addNum1 = 5;
    int addNum2 = 10;

    cout << "\nAdding " << addNum1 << " to num1" << endl;
    num1.add(addNum1);
    cout << "After adding, num1 is " << num1.get() << endl;

    cout << "\nAdding " << addNum2 << " to num2" << endl;
    num2.add(addNum2);
    cout << "After adding, num2 is " << num2.get() << endl;


    // subtract
    int subNum1 = 5;
    int subNum2 = 10;

    cout << "\nSubtracting " << subNum1 << " from num1" << endl;
    num1.subtract(subNum1);
    cout << "After subtracting, num1 is " << num1.get() << endl;

    cout << "\nSubtracting " << subNum2 << " from num2" << endl;
    num2.subtract(subNum2);
    cout << "After subtracting, num2 is " << num2.get() << endl;


    // multiply 
    int multiNum1 = 3;
    int multiNum2 = 2;

    cout << "\nMultiplying num1 by " << multiNum1 << endl;
    num1.multiply(multiNum1);
    cout << "After multiplying, num 1 is " << num1.get() << endl;

    cout << "\nMultiplying num2 by " << multiNum2 << endl;
    num2.multiply(multiNum2);
    cout << "After multiplying, num 2 is " << num2.get() << endl;


    // compare
    cout << "\nComparing num1 with num2: ";
    int k = num1.compare(num2);
    if (k == 0) { cout << "num 1 is less than num2" << endl; }
    if (k == 1) { cout << "num1 is equal to num2" << endl; }
    if (k == 2) { cout << "num1 is greater than num2" << endl; }

    return 0;
}