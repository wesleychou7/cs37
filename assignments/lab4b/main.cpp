#include<iostream>
using namespace std;

int main(){

    cout << "Insert cash: ";
    int dollars;
    cin >> dollars;

    int total_bars = dollars;
    int coupons = dollars;

    int new_bars = 0;

    cout << "With $" << dollars <<  ", you can get " << dollars << " chocolate bars and " 
        << coupons << " coupons." << endl;
    cout << "With " << coupons << " coupons, you can ";

    while (coupons >= 6){
        new_bars += 1;
        coupons -= 6;
        coupons += 1;
    }
    total_bars += new_bars;

    cout << "get an additional " << new_bars << " chocolate bars." << endl;
    cout << "You will get a grand total of " << total_bars << " chocolate bars." << endl;
    cout << "You will have " << coupons << " coupons left." << endl;

    return 0;
}