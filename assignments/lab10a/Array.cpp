#include <iostream>
#include <iomanip>
#include <stdexcept>

#include "Array.h"
using namespace std;

// Defines a constructor for class Array. 
// The constructor takes an int arraySize as its argument and initializes a pointer
// to an array of integers of that specified size.
// Checks if arraySize is greater than 0. If not, then throws an error. Else, 
// initialize and allocate memory for a new array of size arraySize
Array::Array(int arraySize)
   : size{(arraySize > 0 ? static_cast<size_t>(arraySize) :
        throw invalid_argument{"Array size must be greater than 0"})},
     ptr{new int[size]{}} { /* empty body */ }

// Defines a constructor for class Array.
// Takes in a constant reference to an Array called arrayToCopy.
// Creates a new Array object that is a copy of the Array that arrayToCopy references.
// It does this by looping through each element of arrayToCopy.
Array::Array(const Array& arrayToCopy)
   : size{arrayToCopy.size}, ptr{new int[size]} {
   for (size_t i{0}; i < size; ++i) {
      ptr[i] = arrayToCopy.ptr[i];
   }
}

// Defines a destructor for Array class.
// Deallocates the memory block pointed to by the ptr member variable.
Array::~Array() {
   delete[] ptr;
}

// Defines function that returns a size_t object, which is the size of the Array.
// Does not modify the object's state.
size_t Array::getSize() const {
   return size;
}

// Overloads the = operator for Array objects
// Takes in a constant reference to an Array called right
// Returns a reference to the current Array object
const Array& Array::operator=(const Array& right) {
   // checks if checks if right is the same object as the current Array object by 
   // comparing their addresses. 
   if (&right != this) { 
      // Check if right has a different size as the current Array object.
      // If they are not equal, then the memory allocated for the current 
      // object's ptr array is deallocated. Then, a new array of size right.size 
      // is initialized and allocated.
      if (size != right.size) {
         delete[] ptr;
         size = right.size;
         ptr = new int[size];
      }
      // Loop that copies each element of right.ptr to the corresponding element of 
      // the newly allocated ptr array.
      for (size_t i{0}; i < size; ++i) {
         ptr[i] = right.ptr[i];
      }
   }
   return *this;
}

// Overloads the == operator for Array objects
// Takes in a constant reference to an Array called right
// Compares two Array objects for equality, returning true if they have the same 
// size and each corresponding element in the two arrays is equal. 
// Returns false otherwise
bool Array::operator==(const Array& right) const {
   if (size != right.size) {
      return false;
   }
   for (size_t i{0}; i < size; ++i) {
      if (ptr[i] != right.ptr[i]) {
         return false;
      }
   }
   return true;
}

// Overloads the [] operator for Array objects
// Takes in an integer called subscript, which represents an index
// Returns a reference to the element at that specified index
int& Array::operator[](int subscript) {
   // Check whether subscript is within the bounds of the array.
   if (subscript < 0 || subscript >= size) {
      throw out_of_range{"Subscript out of range"};
   }
   return ptr[subscript];
}

// Overloads the [] operator for Array objects
// Takes in an integer called subscript, which represents an index
// Returns the value of the element at that specified index
int Array::operator[](int subscript) const {
   // Check whether subscript is within the bounds of the array.
   if (subscript < 0 || subscript >= size) {
      throw out_of_range{"Subscript out of range"};
   }
   return ptr[subscript];
}

// Overloads the >> operator
// Takes two arguments: a reference to an input stream called input, 
// and a reference to an Array called a. 
// Returns a reference to the input stream object after reading the values from 
// the stream using a for loop that iterates over a.
istream& operator>>(istream& input, Array& a) {
   for (size_t i{0}; i < a.size; ++i) {
      input >> a.ptr[i];
   }
   return input; 
}

// Overloads the << operator
// Takes two arguments: a reference to an output stream called output, 
// and a reference to a constant Array called a. 
// Returns a reference to the output stream object by iterating over Array a and 
// adding a new line.
ostream& operator<<(ostream& output, const Array& a) { 
   for (size_t i{0}; i < a.size; ++i) {
      output << a.ptr[i] << "  ";
   }
   output << endl;
   return output; 
}
