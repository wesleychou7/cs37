#include <iostream>
#include <string>
#include "List.h" // List class definition
using namespace std;

// display program instructions to user
void instructions() {
   cout << "Enter one of the following:\n"
      << "  1 to insert at beginning of list\n" 
      << "  2 to insert at end of list\n" 
      << "  3 to delete from beginning of list\n" 
      << "  4 to delete from end of list\n" 
      << "  5 to end list processing\n";
} 

// function to test a List
template<typename T>
void testList(List<T>& listObject, const string& typeName) {
   cout << "Testing a List of " << typeName << " values\n";
   instructions(); // display instructions

   int choice; // store user choice
   T value; // store input value

   do { // perform user-selected actions
      cout << "? ";
      cin >> choice;

      switch (choice) {
      case 1: // insert at beginning
         cout << "Enter " << typeName << ": ";
         cin >> value;
         listObject.insertAtFront(value);
         listObject.print();             
         break;
      case 2: // insert at end
         cout << "Enter " << typeName << ": ";
         cin >> value;
         listObject.insertAtBack(value);
         listObject.print();            
         break;
      case 3: // remove from beginning
         if (listObject.removeFromFront(value)) {
            cout << value << " removed from list\n";
         }

         listObject.print();
         break;
      case 4: // remove from end
         if (listObject.removeFromBack(value)) {
            cout << value << " removed from list\n";
         }

         listObject.print();
         break;
      } 
   } while (choice < 5); 

   cout << "End list test\n\n";
} 

int main() {
   // test List of int values
   List<int> integerList;
   testList(integerList, "integer"); 

   // test List of double values
   List<double> doubleList;
   testList(doubleList, "double"); 
} 