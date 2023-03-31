#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

class Array {
   // declares a function to overload the << operator
   // two arguments: 1) an output stream and 2) a constant object of type Array
   friend std::ostream& operator<<(std::ostream&, const Array&);

   // declares a function to overload the >> operator
   // two arguments: 1) an input stream and 2) an object of type Array
   friend std::istream& operator>>(std::istream&, Array&);

public:
   // explicit constructor that takes an optional integer argument with a default value of 10
   explicit Array(int = 10);

   // a copy constructor for Array class
   // takes a reference to another object of type Array as its argument.
   Array(const Array&);

   // a destructor for Array that is explicitly called, which frees up memory
   ~Array();
   
   // member function that returns an object of type size_t
   // does not modify the object's state
   size_t getSize() const;

   // declares a function that overloads the = operator
   // takes in a constant reference to an object of type Array
   // returns a constant reference to an object of type Array
   const Array& operator=(const Array&);

   // declares a function that overloads the == operator (equality comparison for Array objects)
   // takes in a constant reference to an object of type Array
   // returns a boolean 
   // does not modify the object's state
   bool operator==(const Array&) const; 

   // declares a function that overloads the != operator (inequality comparison for Array objects)
   // takes in a constant reference to an object of type Array called right
   // returns true if the current Array object is not equal to right, false otherwise 
   // does not modify the object's state
   bool operator!=(const Array& right) const {
      return !(*this == right);
   }

   // declares a function that overloads the [] operator 
   // takes an interger as an argument, which will be the index
   // returns a reference to the element at the given index
   int& operator[](int);

   // declares a function that overloads the [] operator 
   // takes an interger as an argument, which will be the index
   // returns a the element at the given index
   // does not modify the object's state
   int operator[](int) const;

private:
   size_t size;
   int* ptr;
};

#endif
