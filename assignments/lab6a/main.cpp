#include<iostream>
using namespace std;


void inputFunc(int&, int&);
float convertToKG(int, int);
void outputFunc(float);

int main(){

    int userInput = 0;
    do{
        int pounds = 0;
        int ounces = 0;
        float kilograms = 0.0;

        // input
        inputFunc(pounds, ounces);

        // conversion
        kilograms = convertToKG(pounds, ounces);

        // output
        outputFunc(kilograms);

        cout << "Enter -1 to exit. Enter 1 to continue. "; 
        cin >> userInput;
        cout << "\n";

    } while (userInput != -1);

    cout << "Program exited.";

    return 0;
}


void inputFunc(int& p, int& o){

    cout << "Enter pounds: ";
    cin >> p;

    cout << "Enter ounces: ";
    cin >> o;
}

float convertToKG(int p, int o){
    int total_ounces = p * 16 + o;

    float total_grams = total_ounces * 28.3495;

    return total_grams / 1000;
}

void outputFunc(float kg){

    int kilos = static_cast<int>(kg);

    int grams = static_cast<int>((kg - kilos) * 100);

    cout << "\nWeight converted to kilograms and pounds: " << endl;
    cout << "kilograms: " << kilos << endl;
    cout << "grams: " << grams << endl;
    cout << "\n";
}





