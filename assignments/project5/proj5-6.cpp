#include <iostream> 
#include <iomanip> 
#include <cstdlib>
#include <ctime>
#include <array>
using namespace std;

const int SIZE = 10;

// function prototypes
void proj5_6a(array < int, SIZE > &, int, int);
int proj5_6b(array < int, SIZE > &, int, int);
void proj5_6c(int * const, int * const);

int main() {
   srand(static_cast<unsigned int>(time(0)));
   const int MAX_NUMBER{100};
   array<int, SIZE> arrayForProj;

   // randomly generate content 
   for (int& item : arrayForProj) {
      item = rand() % MAX_NUMBER;
   }

   cout << "Initial array values are:\n";
   
   // print out values of the array
   for (int item : arrayForProj) {
       cout << setw(4) << item;
   }
   cout << "\n\n";

   // if there is only one element
   if (SIZE == 1) {
      cout << "Array is sorted: " << arrayForProj[0] << '\n';
   }
   else 
   {
      proj5_6a(arrayForProj, 0, SIZE - 1);
      cout << "The sorted array values are:\n";

      for (int item : arrayForProj) {
         cout << setw(4) << item;
      }

      cout << endl;
   } 
} 


void proj5_6a(array<int, SIZE>& data, int first, int last) {
   if (first >= last) {
      return;
   }

   int currentLocation = proj5_6b(data, first, last); 
   proj5_6a(data, first, currentLocation - 1); 
   proj5_6a(data, currentLocation + 1, last); 
} 


int proj5_6b(array<int, SIZE>& data, int left, int right) {
   int position{left};

   while (true) {
      while (data[position] <= data[right] && position != right) {
         --right;
      }

      if (position == right) {
         return position;
      }

      if (data[position] > data[right]) {
         proj5_6c(&data[position], &data[right]);
         position = right;
      } 

      while (data[left] <= data[position] && left != position) {
         ++left;
      }

      if (position == left) {
         return position;
      }

      if (data[left] > data[position]) {
         proj5_6c(&data[position], &data[left]);
         position = left;
      } 
   } 
} 

void proj5_6c(int * const ptr1, int * const ptr2)
{
   int temp;

   temp = *ptr1;
   *ptr1 = *ptr2;
   *ptr2 = temp;
} 
