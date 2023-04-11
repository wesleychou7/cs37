#include <iostream>
#include <iomanip>
using namespace std;

int main(){

    cout << "Decimal";
    cout << setw(10) << "Octal";
    cout << setw(16) << "Hexadecimal";
    cout << setw(14) << "Character" << endl;

    for(int i=33; i<=70; i++){
        cout << dec << setw(7) << i;
        cout << oct << setw(10) << showbase << i;
        cout << hex << setw(16) << showbase << i;
        cout << dec << setw(14) << static_cast<char>(i) << endl;
    }

    return 0;
}