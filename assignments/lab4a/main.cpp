#include <iostream>
using namespace std;

int main(){

    int input;
    cout << "Enter a 5-digit integer that contain only 0s and 1s: ";
    cin >> input;

    int check_input = input;
    int digit_count = 0;
    int digit;

    // check input
    while (check_input){

        digit = check_input % 10;
        check_input /= 10;
        digit_count++;

        if (digit != 0 && digit != 1){
            cout << "Error: Invalid input.\n" << endl;
            // prompt new input
            cout << "Enter a 5-digit integer that contain only 0s and 1s: ";
            cin >> input;

            // reset values
            check_input = input;
            digit_count = 0;
            digit = 0;
        }

        // check if input has length 5
        while (digit_count != 5){

            cout << "Error: Invalid input.\n" << endl;
            // prompt new input
            cout << "Enter a 5-digit integer that contain only 0s and 1s: ";
            cin >> input;

            digit_count = 0;
            check_input = input;

            while (check_input){
                check_input /= 10;
                digit_count++ ;
            }
        }

    }


    // reset and initialize values
    check_input = input;
    digit = 0;
    int i = 0;
    int decimal = 0;

    // when input is valid, calculate decimal value
    while (i < 5){

        // get right-most digit
        digit = check_input % 10;
        check_input /= 10;
        
        // get the 2^exponent value ; e.g., 2^3 = 8
        int j = 0;
        int multiply = 1;
        while (j < i){
            multiply *= 2;
            j++;
        }

        // update values
        decimal += digit * multiply;
        i++;
    }

    
    cout << "The decimal value is: " << decimal << endl;

    return 0;
}