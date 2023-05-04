#include <iostream>
#include <array>
using namespace std;

// compare key to every element of array until location is     
// found or until end of array is reached; return location of  
// element if key is found or -1 if key is not found 

template <typename T, size_t size>                           
int linearSearch(const array<T, size>& items, const T& key) {
   for (size_t i{0}; i < items.size(); ++i) {                
      if (key == items[i]) { // if found,                    
         return i; // return location of key                 
      }                                                      
   }                                                         
   return -1; // key not found                               
}

template <typename T, size_t size>     
int recursiveLinearSearch(const array<T, size>& items, const T& key, int start){

   if (start > items.size()){
      return -1;
   }
   if (key == items[start]){
      return start;
   }
   else{
      return recursiveLinearSearch(items, key, start+1);
   }
}

int main() {
  
   const size_t arraySize{100}; // size of array 
   array<int, arraySize> arrayToSearch; // create array

   for (size_t i{0}; i < arrayToSearch.size(); ++i) {
      arrayToSearch[i] = 2 * i; // create some data
   }

   cout << "\nEnter integer search key: ";
   int searchKey; // value to locate 
   cin >> searchKey;

   // attempt to locate searchKey in arrayToSearch
   // int element{linearSearch(arrayToSearch, searchKey)};
   int element{recursiveLinearSearch(arrayToSearch, searchKey, 0)};

   // display results
   if (element != -1) {
      cout << "\nFound value in element " << element << endl;
   }
   else {
      cout << "\nValue not found" << endl;
   }
  cout << endl;
} 