#include <iostream> 
#include "Time.h" // include definition of class Time
using namespace std;

const int MAX_TICKS{30}; //

int main() {
  Time t{23, 59, 57}; // instantiate object t of class Time

  // output Time object t's values
  for (int ticks{1}; ticks < MAX_TICKS; ++ticks) {

    t.tick();
    cout << t.toStandardString() << endl;
    
  } 
}
