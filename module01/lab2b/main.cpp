#include<iostream>
using namespace std;

int main(){

    // PART 1
    
    cout<<"Wesley's Table"<<endl;
    cout<<"integer\tsquare\tcube"<<endl;

    int num = 1;
    cout<< num << "\t" << num*num << "\t" << num*num*num <<endl;
    num += 1;
    cout<< num << "\t" << num*num << "\t" << num*num*num <<endl;
    num += 1;
    cout<< num << "\t" << num*num << "\t" << num*num*num <<endl;
    num += 1;
    cout<< num << "\t" << num*num << "\t" << num*num*num <<endl;
    num += 1;
    cout<< num << "\t" << num*num << "\t" << num*num*num <<endl;
    num += 1;
    cout<< num << "\t" << num*num << "\t" << num*num*num <<endl;
    num += 1;
    cout<< num << "\t" << num*num << "\t" << num*num*num <<endl;
    num += 1;
    cout<< num << "\t" << num*num << "\t" << num*num*num <<endl;
    num += 1;
    cout<< num << "\t" << num*num << "\t" << num*num*num <<endl;
    num += 1;
    cout<< num << "\t" << num*num << "\t" << num*num*num <<endl;

    cout << endl;

    // PART 2

    char letter = 'W';
    cout << letter << " - " << static_cast<int>(letter)<<endl;
    letter = 'e';
    cout << letter << " - " << static_cast<int>(letter)<<endl;
    letter = 's';
    cout << letter << " - " << static_cast<int>(letter)<<endl;
    letter = 'l';
    cout << letter << " - " << static_cast<int>(letter)<<endl;
    letter = 'e';
    cout << letter << " - " << static_cast<int>(letter)<<endl;
    letter = 'y';
    cout << letter << " - " << static_cast<int>(letter)<<endl;

    cout << endl;

    // PART 3

    float num1, num2, num3, num4;

    cout << "Number calculator by Wesley--------" <<endl;

    cout << "Enter the first of three different numbers: ";
    cin >> num1;
    cout << "Enter the first of three different numbers: ";
    cin >> num2;
    cout << "Enter the first of three different numbers: ";
    cin >> num3;
    cout << "Enter the first of three different numbers: ";
    cin >> num4;

    cout << endl;

    cout << "The sum of your numbers is " << num1+num2+num3+num4 << endl;
    cout << "The average of your numbers is " << (num1+num2+num3+num4) / 4 << endl;
    cout << "The product of your numbers is " << num1*num2*num3*num4 << endl;

    float smallest_num = num1;

    if (num2 < smallest_num) { smallest_num = num2; }
    if (num3 < smallest_num) { smallest_num = num3; }
    if (num4 < smallest_num) { smallest_num = num4; }
    
    cout << "The smallest numbers is " << smallest_num << endl;

    float largest_num = num1;

    if (num2 > largest_num) { largest_num = num2; }
    if (num3 > largest_num) { largest_num = num3; }
    if (num4 > largest_num) { largest_num = num4; }

    cout << "The largest numbers is " << largest_num << endl;

    cout << endl;

    // EXTRA CREDIT

    int number;
    int digit;

    cout << "Enter a four-digit number: ";
    cin >> number;

    cout << "Your number in reverse order: ";
    cout << number % 10 << " ";
    number /= 10;
    cout << number % 10 << " ";
    number /= 10;
    cout << number % 10 << " ";
    number /= 10;
    cout << number;
}