#include <iostream>
#include <array>
using namespace std;
         
template <typename T, size_t size>                           
int proj5_3(const array<T, size>& items, const T& key) {
   for (size_t i{0}; i < items.size(); ++i) {                
      if (key == items[i]) {                     
         return i;                  
      }                                                      
   }                                                         

   return -1;                                
}                                                            

int main() {
   const size_t arraySize{100}; // size of array 
   array<int, arraySize> arrayForProj; // create array

   for (size_t i{0}; i < arrayForProj.size(); ++i) {
      arrayForProj[i] = 2 * i; // create some data
   }

   cout << "Enter integer search key: ";
   int searchKey; 
   cin >> searchKey;

   
   int element{proj5_3(arrayForProj, searchKey)};

   // display results
   if (element != -1) {
      cout << "Found value in element " << element << endl;
   }
   else {
      cout << "Value not found" << endl;
   }
} 
