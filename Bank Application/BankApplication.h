# ifndef BANK_ACCOUNT_BANKAPPLICATION_H
# define BANK_ACCOUNT_BANKAPPLICATION_H

# include <iostream>
# include <fstream>
# include <vector>
# include <iomanip>
# include <regex>

using namespace std ;

class BankAccount {
protected:
    string AccountId ;
    string Type_Account ;
    double Balance ;
public:
    BankAccount() ;
    explicit BankAccount(double amount, int Id) ;
    virtual bool WithDraw(double amount) ;
    virtual void Deposit(double amount) ;
    void Set_Id(const string & Id) ;
    void Set_Balance(double Balance) ;
    void Set_Type(const string & Type) ;
    double Get_Balance() const ;
    string Get_Type() ;
    string Get_Id() ;
};

class Client {
private:
    BankAccount Account ;
    string name ;
    string  Address ;
    string phone ;
    static int Number_Clients ;

public:
    Client() ;
    void Set_Name(const string & Name) ;
    void Set_Address(const string & Address_) ;
    void Set_Phone(const string & phone_) ;
    string Get_Name() ;
    string Get_Address() ;
    string Get_Phone() ;
    static int Get_Number_Clients () ;
};

class SavingBankAccount : public BankAccount{
private:
    double Minimum_Balance = 1000 ;
public:
    SavingBankAccount(double amount, int Id) ;
    bool WithDraw(double amount) override ;
    void Deposit(double amount) override ;
};

class BankApplication {
private:
    string File_Name ;
    fstream  Data ;
    vector <pair<Client, BankAccount>> clients ;

public:
    BankApplication() = default ;
    explicit BankApplication(string & M) ;
    bool addClient() ;
    void Update_File() ;
    void Check_Id(const string & ID, int Choice) ;
    void Print_Info() ;
    ~BankApplication() ;
};

#endif //BANK_ACCOUNT_BANKAPPLICATION_H