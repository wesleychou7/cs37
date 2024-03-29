// Time class containing a constructor with default arguments.
// Member functions defined in NewTime.cpp.
#include <string>

// prevent multiple inclusions of header
#ifndef NEWTIME_H
#define NEWTIME_H

// NewTime class definition
class NewTime {
public:
   explicit NewTime(int = 0, int = 0, int = 0); // default constructor

   // set functions
   void setTime(int, int, int); // set hour, minute, second
   void setHour(int); // set hour (after validation)
   void setMinute(int); // set minute (after validation)
   void setSecond(int); // set second (after validation)

   // get functions
   unsigned int getHour() const; // return hour
   unsigned int getMinute() const; // return minute
   unsigned int getSecond() const; // return second

   std::string toUniversalString() const; // 24-hour time format string
   std::string toStandardString() const; // 12-hour time format string
private:
   //unsigned int hour{0}; // 0 - 23 (24-hour clock format)
   //unsigned int minute{0}; // 0 - 59
   //unsigned int second{0}; // 0 - 59
   unsigned int seconds{0}; // seconds since midnight 0 - 86,399
};

#endif