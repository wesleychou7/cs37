#include <array>
#include <iomanip>
#include <iostream> 
using namespace std;

                                
template <typename T, size_t size>                                     
void proj5_5(array<T, size>& items) {                            
                                     
   for (size_t i{0}; i < items.size() - 1; ++i) {                      
      size_t indexOfSmallest{i}; 
                      
      for (size_t index{i + 1}; index < items.size(); ++index) {       
         if (items[index] < items[indexOfSmallest]) {                  
            indexOfSmallest = index;                                   
         }                                                             
      }                                                                
         
      T hold{items[i]};                                                
      items[i] = items[indexOfSmallest];                               
      items[indexOfSmallest] = hold;                                   
   }                                                                   
}                                                                      

int main() {
   const size_t arraySize{10}; 
   array<int, arraySize> data{34, 56, 4, 10, 77, 51, 93, 30, 5, 52};

   cout << "Unsorted array:\n";

   // output original array
   for (size_t i{0}; i < arraySize; ++i) {
      cout << setw(4) << data[i];
   }

   proj5_5(data); 

   cout << "\nSorted array:\n";

   // output sorted array
   for (size_t i{0}; i < arraySize; ++i) {
      cout << setw(4) << data[i];
   }

   cout << endl;
} 
