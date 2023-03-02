#include <iostream> 
#include <string>
using namespace std;

bool testPalindrome(string, size_t, size_t);

int main() {
   string input;

   // get sentence to test from user
   cout << "Enter a sentence:\n";
   getline(cin, input); //gets the whole line of text

   // Print whether or not sentence is palindrome
   int lastElement = input.length() - 1;
   if (testPalindrome(input, 0, lastElement)) {
      cout << '\"' << input << "\" is a palindrome" << endl;
   }
   else {
      cout << '\"' << input << "\" is not a palindrome" << endl;
   }
}

bool testPalindrome(string palindrome, size_t left, size_t right) {

   if (left == right){
      return true;
   }
   if (palindrome[left] != palindrome[right]){
      return false;
   }
   
   return testPalindrome(palindrome, left + 1, right - 1);
   
}