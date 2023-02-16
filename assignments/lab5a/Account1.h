// Fig. 3.8: Account.h
// Account class with name and balance data members, and a 
// constructor and deposit function that each perform validation.
#include <string>
#include "DollarAmount.h"

class Account {
   public:
      
      Account(std::string accountName, int initialBalance){
         
         name = accountName;
         
         if (initialBalance > 0) {
            DollarAmount initialAmount{initialBalance};
            theBalance.add(initialAmount);
         }
      }

      // function that deposits (adds) only a valid amount to the balance
      void deposit(int depositAmount) {
         DollarAmount amount{depositAmount};

         if (depositAmount > 0) { // if the depositAmount is valid
            theBalance.add(amount); // add it to the balance 
         }
      }

      // function returns the account balance
      std::string getBalance() {
         return theBalance.toString();
      }

      // function that sets the name
      void setName(std::string accountName) {
         name = accountName;
      }

      // function that returns the name
      std::string getName() const {
         return name;
      }

   private:
      std::string name; // account name data member 
      DollarAmount theBalance{0}; // data member with default initial value
}; // end class Account