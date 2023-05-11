#include <algorithm> 
#include <array>
#include <ctime>
#include <iostream>
#include <random> 
using namespace std;

// display array elements from index low through index high
template <typename T, size_t size>
void displayElements(const array<T, size>& items, 
   size_t low, size_t high) {
   for (size_t i{0}; i < items.size() && i < low; ++i) {
      cout << "   "; // display spaces for alignment 
   }

   for (size_t i{low}; i < items.size() && i <= high; ++i) {
      cout << items[i] << " "; // display element
   }

   cout << endl;
} 


template <typename T, size_t size>                                
int proj5_1(const array<T, size>& items, const T& key) {     
   int low{0};                 
   int high{static_cast<int>(items.size()) - 1}; 
   int middle{(low + high + 1) / 2};            
   int location{-1};              

   do {                                     
      displayElements(items, low, high);                                
      for (int i{0}; i < middle; ++i) {                          
         cout << "   ";                                             
      }

      cout << " * " << endl;
                
      if (key == items[middle]) {                             
         location = middle;  
      }                                                       
      else if (key < items[middle]) {    
         high = middle - 1;      
      }                                                       
      else {                    
         low = middle + 1;         
      }                                                       

      middle = (low + high + 1) / 2; 
   } while ((low <= high) && (location == -1));               

   return location; 
} 

int main() {
   // use the default random-number generation engine to produce
   // uniformly distributed pseudorandom int values from 10 to 99
   default_random_engine engine{
      static_cast<unsigned int>(time(nullptr))};
   uniform_int_distribution<unsigned int> randomInt{10, 99}; 

   const size_t arraySize{15}; // size of array 
   array<int, arraySize> arrayForProj; // create array

   // fill arrayForProj with random values
   for (int &item : arrayForProj) {
      item = randomInt(engine);
   }

   sort(arrayForProj.begin(), arrayForProj.end()); 

   displayElements(arrayForProj, 0, arrayForProj.size() - 1); 

   // get input from user
   cout << "\nPlease enter an integer value (-1 to quit): ";
   int searchKey; // value to locate 
   cin >> searchKey; // read an int from user
   cout << endl;

   // repeatedly input an integer; -1 terminates the program
   while (searchKey != -1) {
      
      int position{proj5_1(arrayForProj, searchKey)};

      if (position == -1) {
         cout << "The integer " << searchKey << " was not found.\n";
      }
      else {
         cout << "The integer " << searchKey 
            << " was found in position " << position << ".\n";
      }

      // get input from user
      cout << "\n\nPlease enter an integer value (-1 to quit): ";
      cin >> searchKey; // read an int from user
      cout << endl;
   } 
} 