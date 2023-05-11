#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
   Stack<double> doubleStack; 
   const size_t doubleStackSize{5};
   double doubleValue{1.1};

   cout << "\nPushing elements onto doubleStack\n";

   // push 5 doubles onto doubleStack
   for (size_t i{0}; i < doubleStackSize; ++i) {
      doubleStack.push(doubleValue);
      cout << doubleValue << ' ';
      doubleValue += 1.1;
   } 

   //  TO DO - swap top and second value
   double temp1d = doubleStack.top();
   doubleStack.pop();
   double temp2d = doubleStack.top();
   doubleStack.pop();
   doubleStack.push(temp1d);
   doubleStack.push(temp2d);

   cout << "\n\nPopping elements from doubleStack\n";

   // pop elements from doubleStack
   while (!doubleStack.isEmpty()) { // loop while Stack is not empty
      cout << doubleStack.top() << ' '; // display top element
      doubleStack.pop(); // remove top element
   } 

   cout << "\nStack is empty, cannot pop.\n";

   Stack<int> intStack; // create a Stack of int
   const size_t intStackSize{10}; // stack size
   int intValue{1}; // first value to push

   cout << "\nPushing elements onto intStack\n";

   // push 10 integers onto intStack
   for (size_t i{0}; i < intStackSize; ++i) {
      intStack.push(intValue);
      cout << intValue++ << ' ';
   } 

   //  TO DO - swap top and second value
   int temp1i = intStack.top();
   intStack.pop();
   int temp2i = intStack.top();
   intStack.pop();
   intStack.push(temp1i);
   intStack.push(temp2i);
  
   cout << "\n\nPopping elements from intStack\n";

   // pop elements from intStack
   while (!intStack.isEmpty()) { // loop while Stack is not empty
      cout << intStack.top() << ' '; // display top element
      intStack.pop(); // remove top element
   } 

   cout << "\nStack is empty, cannot pop.\n" << endl;
} 
