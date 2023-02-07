#include <iostream>
using namespace std;

int main(){

    int input;

    cout << "Enter a 5-digit integer that contain only 0s and 1s: ";
    cin >> input;

    
    int check_input = input;
    int i = 0;
    int digit;
    int decimal = 0;

    while (i  < 5){

        // get right-most digit
        digit = check_input % 10;

        // check if input is 5 digits
        // will finish this next time

        check_input /= 10;

        // check if user input contains only 0s and 1s
        if (digit != 0 && digit != 1){
            cout << "Error: invalid input. Enter only 0s or 1s.\n\n" << endl;
            cout << "Enter a 5-digit integer that contain only 0s and 1s: ";
            cin >> input;
            i = 0;
        }
        
        // get the 2^exponent value ; e.g., 2^3 = 8
        int j = 0;
        int multiply = 1;
        while (j < i){
            multiply *= 2;
            j++;
        }

        // update decimal value
        decimal += digit * multiply;

        i++;
    }

    cout << "The decimal value is: " << decimal << endl;

    return 0;
}