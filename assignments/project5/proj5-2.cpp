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
void proj5_2b(array<T, size>& items,                              
   size_t left, size_t middle1, size_t middle2, size_t right) {
   size_t leftIndex{left};               
   size_t rightIndex{middle2};          
   size_t combinedIndex{left}; 
   array<T, size> combined;                         

   cout << "merge:   ";                  
   displayElements(items, left, middle1);     
   cout << "         ";          
   displayElements(items, middle2, right);    
   cout << endl;                         

   while (leftIndex <= middle1 && rightIndex <= right) {  
                     
      if (items[leftIndex] <= items[rightIndex]) {        
         combined[combinedIndex++] = items[leftIndex++];  
      }                                                   
      else {                                              
         combined[combinedIndex++] = items[rightIndex++]; 
      }                                                   
   }                                                      

   if (leftIndex == middle2) {          
      while (rightIndex <= right) { 
         combined[combinedIndex++] = items[rightIndex++];         
      }                                                           
   }                                                              
   else {                                   
      while (leftIndex <= middle1) { 
         combined[combinedIndex++] = items[leftIndex++];          
      }                                                           
   }                                                              

   for (size_t i = left; i <= right; ++i) {
      items[i] = combined[i];          
   }                                       
       
   cout << "         ";            
   displayElements(items, left, right);
   cout << endl;           
} 


template <typename T, size_t size>                              
void proj5_2a(array<T, size>& items, size_t low, size_t high) {
 
   if ((high - low) >= 1) { 
      size_t middle1{(low + high) / 2}; 
      size_t middle2{middle1 + 1};    
                                         
      cout << "split:   ";                                          
      displayElements(items, low, high);                                 
      cout << "         ";                                  
      displayElements(items, low, middle1);                              
      cout << "         ";                                  
      displayElements(items, middle2, high);                             
      cout << endl;                                         

      proj5_2a(items, low, middle1);  
      proj5_2a(items, middle2, high);

      proj5_2b(items, low, middle1, middle2, high);
   } 
} 


int main() {
   // use the default random-number generation engine to produce
   // uniformly distributed pseudorandom int values from 10 to 99
   default_random_engine engine{
      static_cast<unsigned int>(time(nullptr))};
   uniform_int_distribution<unsigned int> randomInt{10, 99}; 

   const size_t arraySize{10}; // size of array 
   array<int, arraySize> data; // create array

   // fill data with random values
   for (int &item : data) {
      item = randomInt(engine);
   }

   // display data's values
   cout << "Unsorted array:" << endl;
   displayElements(data, 0, data.size() - 1); 
   cout << endl;

   proj5_2a(data, 0, data.size() - 1);

   // display data's values after
   cout << "Sorted array:" << endl;
   displayElements(data, 0, data.size() - 1); 
} 
