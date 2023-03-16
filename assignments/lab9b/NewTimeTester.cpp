// Constructor with default arguments.
#include <iostream>
#include <stdexcept>
#include "NewTime.h" // include definition of class NewTime from NewTime.h
using namespace std;

// displays a NewTime in 24-hour and 12-hour formats
void displayTime(const string& message, const NewTime& time) {
   cout << message << "\nUniversal time: " << time.toUniversalString()
      << "\nStandard time: " << time.toStandardString() << "\n\n";
}

int main() {
   NewTime t1; // all arguments defaulted                              
   NewTime t2{2}; // hour specified; minute and second defaulted     
   NewTime t3{21, 34}; // hour and minute specified; second defaulted
   NewTime t4{12, 25, 42}; // hour, minute and second specified      

   cout << "\nConstructed with:\n\n";
   displayTime("t1: all arguments defaulted", t1);
   displayTime("t2: hour specified; minute and second defaulted", t2);
   displayTime("t3: hour and minute specified; second defaulted", t3);
   displayTime("t4: hour, minute and second specified", t4);

   // attempt to initialize t5 with invalid values
   try {
      NewTime t5{27, 74, 99}; // all bad values specified
   }
   catch (invalid_argument& e) {
      cerr << "Exception while initializing t5: " << e.what() << endl << endl;
   }
}
