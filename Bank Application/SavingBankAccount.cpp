#include "BankApplication.h"

SavingBankAccount::SavingBankAccount(double amount, int Id) {
    string ID = to_string(Id) ;
    Id = 3 - (int)ID.size() ;
    while (Id--)
    {
        ID.insert(0, "0") ;
    }
    ID.insert(0, "FCAI-") ;
    Type_Account = "(Saving)" ;
    Balance = amount ;
    AccountId = ID ;
}

bool SavingBankAccount::WithDraw(double amount) {
    if (BankAccount::Get_Balance() >= amount)
    {
        Balance -= amount ;
        cout << "Thank you.\nAccount ID : " << AccountId << "\nNew Balance "
             << Balance << endl ;
        return true ;
    }
    else
    {
        cout << "Sorry. This is more than what you can withdraw.\n" ;
        return false ;
    }
}

void SavingBankAccount::Deposit(double amount) {
    Balance += amount ;
    cout << "Thank you.\nAccount ID : " << AccountId << "\nNew Balance "
    << Balance << endl ;
}