#include <iostream>
#include <array>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
   const size_t SIZE{10};
   array<int, SIZE> values{1, 12, 5, 2, 8, 9, 3, 10, 4, 20};
   ostream_iterator<int> output{cout, " "};

   // output initial values
   cout << "\nThe array values contains: ";
   copy(values.cbegin(), values.cend(), output);

   // output each element multiplied by two
   cout << "\n\nDisplay each element multiplied by two: ";
   
   for_each(values.cbegin(), values.cend(),
      [](auto i) {cout << i * 2 << " ";});

   // add each element to sum and output sum
   int sum = 0;
   for_each(values.cbegin(), values.cend(), [&sum](auto i) {sum += i;});

   cout << "\n\nSum of value's elements is: " << sum << endl << endl; 


   // PART 1: remove 10
   auto newEnd = remove(values.begin(), values.end(), 10);

   ostream_iterator<int> output2{cout, " "};
   cout << "\nArray after removing 10: ";
   copy(values.begin(), newEnd, output2);

   // PART 2: replace 8
   replace(values.begin(), newEnd, 8, 88);

   cout << "\n\nArray after replacing 8 with 88: ";
   for_each(values.begin(), newEnd,
      [](auto i) {cout << i << " ";});
} 
