// Fig. 3.9: AccountTest.cpp
// Displaying and updating Account balances.
#include <iostream>
#include "Account.h"

using namespace std;

void displayAccount(Account accountToDisplay) {

    cout << accountToDisplay.getName() << " balance is $"
        << accountToDisplay.getBalance();

}

int main() 
{
    cout << "Wesley Chou\n\n";

    Account account1 = Account("Jane Green", 50);
    Account account2 = Account("John Blue", -7); 

    // display initial balance of each object
    cout << "account1: ";
    displayAccount(account1);
    cout << "\naccount2: ";
    displayAccount(account2); 

    cout << "\n\nEnter deposit amount for account1: "; // prompt
    int depositAmount;
    cin >> depositAmount; // obtain user input
    cout << "adding " << depositAmount << " to account1 balance";
    account1.deposit(depositAmount); // add to account1's balance

    // display balances
    cout << "\n\naccount1: "; 
    displayAccount(account1);
    cout << "\naccount2: ";
    displayAccount(account2); 

    cout << "\n\nEnter deposit amount for account2: "; // prompt
    cin >> depositAmount; // obtain user input
    cout << "adding " << depositAmount << " to account2 balance";
    account2.deposit(depositAmount); // add to account2 balance

    // display balances
    cout << "\n\naccount1: " << account1.getName() << " balance is $"
        << account1.getBalance(); 
    cout << "\naccount2: " << account2.getName() << " balance is $"
        << account2.getBalance() << endl; 

    // withdraw
    int withdrawAmount;
    cout << "\nEnter withdraw amount for acocunt1: ";
    cin >> withdrawAmount;
    cout << account1.withdraw(withdrawAmount) << endl;
    
    withdrawAmount = 0;

    cout << "\nEnter withdraw amount for acocunt2: ";
    cin >> withdrawAmount;
    cout << account2.withdraw(withdrawAmount) << endl;
    
    cout << "\naccount1: "; 
    displayAccount(account1);
    cout << "\naccount2: ";
    displayAccount(account2); 
}