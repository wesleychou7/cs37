// Fig. 5.8: DollarAmount.h
// DollarAmount class stores dollar amounts as a whole numbers of pennies
#include <string>
#include <cmath> 

class DollarAmount {
   public:
      // initialize dollars & cents from an int64_t value
      int dollars;
      int cents;
      explicit DollarAmount(int64_t value){
         dollars = value / 100;
         cents = value % 100;
      }

      // add right's amount to this object's amount
      void add(DollarAmount right) {
         // can access private data of other objects of the same class
         dollars += right.dollars;
         
         int add_cents = cents + right.cents;

         if (add_cents >= 100){
            dollars += 1;
            add_cents -= 100;
            cents = add_cents;
         }
         else {
            cents += right.cents;
         }
         
      }

      // subtract right's amount from this object's amount
      void subtract(DollarAmount right) {
         // can access private data of other objects of the same class
         dollars -= right.dollars;
         
         int sub_cents = cents - right.cents;

         if (sub_cents < 0){
            sub_cents = 100 + sub_cents;
            cents = sub_cents;
            dollars -= 1;
         }
         else{
            cents = 100 - sub_cents;
            dollars += 1;
         }
      }

      // uses integer arithmetic to calculate interest amount, 
      // then calls add with the interest amount
      void addInterest(int rate, int divisor) {
         // create DollarAmount representing the interest

         DollarAmount interest{((dollars * 100 + cents) * rate + divisor / 2) / divisor};

         add(interest); // add interest to this object's amount
      }

      // return a string representation of a DollarAmount object
      std::string toString(){
         if (std::to_string(cents).length() > 1){
            return std::to_string(dollars) + "." + std::to_string(cents);
         }
         else{
            return std::to_string(dollars) + ".0" + std::to_string(cents);
         }
      }

   private:
      int64_t amount = 0; // dollar amount in pennies
};


/**************************************************************************
* (C) Copyright 1992-2017 by Deitel & Associates, Inc. and               *
* Pearson Education, Inc. All Rights Reserved.                           *
*                                                                        *
* DISCLAIMER: The authors and publisher of this book have used their     *
* best efforts in preparing the book. These efforts include the          *
* development, research, and testing of the theories and programs        *
* to determine their effectiveness. The authors and publisher make       *
* no warranty of any kind, expressed or implied, with regard to these    *
* programs or to the documentation contained in these books. The authors *
* and publisher shall not be liable in any event for incidental or       *
* consequential damages in connection with, or arising out of, the       *
* furnishing, performance, or use of these programs.                     *
*************************************************************************/
