#include <iostream>
#define PI 3.14
using namespace std;

int main(){

    cout << "\n---Part 1------------------\n" << endl;

    cout <<"  *  \n *** \n*****"<<endl;


    cout << "\n---Part 2------------------\n" << endl;

    int num1 = 17;
    int num2 = 5;
    int quotient = 17 / 5;
    int remainder = 17 % 5;

    cout << num1<< " / "<< num2 << " = " << quotient << " remainder " << remainder << endl; 


    cout << "\n---Part 3------------------\n" << endl;

    int radius;
    int diameter;
    float circumference;
    float area;

    cout<< "Enter the radius of the circle: ";
    cin>> radius;
    cout<< endl;

    diameter = radius * 2;
    circumference = 2 * PI * radius;
    area = PI * radius * radius;

    cout<< "Radius is " << radius << endl;
    cout<< "Diameter is " << diameter << endl;
    cout<< "Circumference is " << circumference << endl;
    cout<< "Area is "<< area << endl; 



    return 0;
}