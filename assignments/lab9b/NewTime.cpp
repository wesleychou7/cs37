// Member-function definitions for class NewTime.
#include <iomanip>
#include <stdexcept>
#include <sstream>
#include <string>
#include "NewTime.h" // include definition of class NewTime from NewTime.h
using namespace std;

// Time constructor initializes each data member    
NewTime::NewTime(int hour, int minute, int second) {
   setTime(hour, minute, second); // validate and set time
}

// set new NewTime value using universal time
void NewTime::setTime(int h, int m, int s) {
   setHour(h); // set private field hour
   setMinute(m); // set private field minute
   setSecond(s); // set private field second
}

// set hour value
void NewTime::setHour(int h) {
   if (h >= 0 && h < 24) {
      hour = h;
   }
   else {
      throw invalid_argument("hour must be 0-23");
   }
}

// set minute value
void NewTime::setMinute(int m) {
   if (m >= 0 && m < 60) {
      minute = m;
   }
   else {
      throw invalid_argument("minute must be 0-59");
   }
}

// set second value
void NewTime::setSecond(int s) {
   if (s >= 0 && s < 60) {
      second = s;
   }
   else {
      throw invalid_argument("second must be 0-59");
   }
}

// return hour value
unsigned int NewTime::getHour() const { return hour; }

// return minute value
unsigned NewTime::getMinute() const { return minute; }

// return second value
unsigned NewTime::getSecond() const { return second; }

// return NewTime as a string in universal-time format (HH:MM:SS)
string NewTime::toUniversalString() const {
   ostringstream output;
   output << setfill('0') << setw(2) << getHour() << ":"
      << setw(2) << getMinute() << ":" << setw(2) << getSecond();
   return output.str();
}

// return NewTime as string in standard-time format (HH:MM:SS AM or PM)
string NewTime::toStandardString() const {
   ostringstream output;
   output << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12)
      << ":" << setfill('0') << setw(2) << getMinute() << ":" << setw(2)
      << getSecond() << (hour < 12 ? " AM" : " PM");
   return output.str();
}