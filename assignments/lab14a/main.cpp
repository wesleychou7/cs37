#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

// void outputLine(int serialnum, const string& name, int quant){
//     cout << left << setw(15) << serialnum << setw(13) << name << quant << endl;
// }
void outputLine(int serialnum, string name, int quant){
    cout << left << setw(15) << serialnum << setw(13) << name << quant << endl;
}

int main(){

    // TASK 1 ------------------------------------------------------------------

    // open file
    ofstream outClientFile("inventory.txt", ios::out);

    // exit program if unable to create file
    if (!outClientFile) { // overloaded ! operator
        cerr << "File could not be opened" << endl;
        exit(EXIT_FAILURE);
    }

    cout << "Enter the account, name, and balance.\n"
        << "Enter end-of-file to end input.\n? ";

    int serialNum;
    string partName;
    int quantity;   

    while (cin >> serialNum >> quoted(partName) >> quantity) {
        outClientFile << serialNum << ' ' << quoted(partName) << ' ' << quantity << endl;
        cout << "? ";
    }
    outClientFile.close();


    // TASK 2 ------------------------------------------------------------------

    // open file
    ifstream inClientFile("inventory.txt", ios::in);

    // exit program if unable to create file
    if (!inClientFile) {
        cerr << "File could not be opened" << endl;
        exit(EXIT_FAILURE);
    }
    cout << endl;
    cout << left << setw(15) << "Serial Number" << setw(13) << "Part Name" << "Quantity\n";

    while (inClientFile >> serialNum >> quoted(partName) >> quantity) {
        outputLine(serialNum, partName, quantity);
    }
    inClientFile.close();

    return 0;
}