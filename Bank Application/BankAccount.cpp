# include "BankApplication.h"

BankAccount::BankAccount() {
    AccountId = ""  ;
    Type_Account = "" ;
    Balance = 0 ;
}

BankAccount::BankAccount(double amount, int Id) {
    Balance = amount ;
    string ID = to_string(Id) ;
    Id = 3 - (int)ID.size() ;
    while (Id--)
    {
        ID.insert(0, "0") ;
    }
    ID = "FCAI-" + ID ;
    Type_Account = "(Basic)" ;

    AccountId = ID ;
}

bool BankAccount::WithDraw(double amount) {
    if (Balance >= amount)
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

void BankAccount::Deposit(double amount) {

    Balance += amount ;
    cout << "Thank you.\nAccount ID : " << AccountId << "\nNew Balance "
    << Balance << endl ;
}

void BankAccount::Set_Id(const string & Id) {
    AccountId = Id ;
}

void BankAccount::Set_Balance(double Balance_) {
    Balance = Balance_ ;
}

double BankAccount::Get_Balance() const {
    return Balance;
}

string BankAccount::Get_Id() {
    return AccountId ;
}

string BankAccount::Get_Type() {
    return Type_Account ;
}

void BankAccount::Set_Type(const string &Type) {
    Type_Account = "( " + Type + " )" ;
}