#include <iostream>
using namespace std;

int main(){

    int input;
    cout << "Enter a 5-digit integer that contain only 0s and 1s: ";
    cin >> input;


    int min = 10000;
    int max = 11111;

    int current = input;
    int digit;

    // boolean variable to check if input are 0's and 1's
    bool valid = true;

    // check if input are all 0's and 1's
    while (current){
        digit = current % 10;
        if (digit != 0 && digit != 1){
            valid = false;
        }
        current /= 10;
    }

    // check input
    while ( !(min <= input && input <= max) || !(valid) ){  //min <= input <= max;

        cout << "Error: Invalid input.\n\n";
        cout << "Enter a 5-digit integer that contain only 0s and 1s: ";
        cin >> input;

        valid = true;

        // check if input are all 0's and 1's
        current = input;
        while (current){
            digit = current % 10;
            if (digit != 0 && digit != 1){
                valid = false;
            }
            current /= 10;
        }
    }


    current = input;
    digit = 0;
    int i = 0;
    int decimal = 0;

    // when input is valid, calculate decimal value
    while (i < 5){

        // get right-most digit
        digit = current % 10;
        current /= 10;
        
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