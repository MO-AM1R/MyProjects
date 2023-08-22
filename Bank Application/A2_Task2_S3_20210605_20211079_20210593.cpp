# include "BankApplication.h"

int Client::Number_Clients = 0 ;

bool Is_Valid(string & Text)
{
    regex Format("[1-2-3-4-0]?") ;

    return regex_match(Text, Format) ;
}

int main() {

    string File_Name = "Bank Accounts.txt" ;
    BankApplication B1(File_Name) ;

    vector <pair<Client, BankAccount>> Test (5) ;

    cout << "-------------------- 5 Test Cases --------------------\n" ;
    //  ----------------------------------
    Test.at(0).first.Set_Name("Mohamed") ;
    Test.at(0).first.Set_Address("20 Elmaka Fysal, Giza") ;
    Test.at(0).first.Set_Phone("01110089085") ;
    Test.at(0).second.Set_Id("FCAI-001") ;
    Test.at(0).second.Set_Type("Saving") ;
    Test.at(0).second.Set_Balance(1500) ;
    //  ----------------------------------
    Test.at(1).first.Set_Name("Badr") ;
    Test.at(1).first.Set_Address("2 ElTben Helwan, Giza") ;
    Test.at(1).first.Set_Phone("01110541806") ;
    Test.at(1).second.Set_Id("FCAI-002") ;
    Test.at(1).second.Set_Type("Basic") ;
    Test.at(1).second.Set_Balance(2000) ;
    //  ----------------------------------
    Test.at(2).first.Set_Name("Omar") ;
    Test.at(2).first.Set_Address("Elmarg, Giza") ;
    Test.at(2).first.Set_Phone("01200514972") ;
    Test.at(2).second.Set_Id("FCAI-003") ;
    Test.at(2).second.Set_Type("Saving") ;
    Test.at(2).second.Set_Balance(15500) ;
    //  ----------------------------------
    Test.at(3).first.Set_Name("FAR3OON") ;
    Test.at(3).first.Set_Address("Elmaka Fysal, Giza") ;
    Test.at(3).first.Set_Phone("01110089085") ;
    Test.at(3).second.Set_Id("FCAI-003") ;
    Test.at(3).second.Set_Type("Basic") ;
    Test.at(3).second.Set_Balance(20000) ;
    //  ----------------------------------
    Test.at(4).first.Set_Name("Mahmoud") ;
    Test.at(4).first.Set_Address("20 Bolaq, Giza") ;
    Test.at(4).first.Set_Phone("01117860514") ;
    Test.at(4).second.Set_Id("FCAI-004") ;
    Test.at(4).second.Set_Type("Saving") ;
    Test.at(4).second.Set_Balance(1000) ;
    //  ----------------------------------

    for (auto & client : Test) {
        cout << setw(5) << setfill('-') << " " << client.first.Get_Name() << " " << setw(5) << setfill('-') << "-" ;
        cout << "\nAddress : " << client.first.Get_Address() << " Phone : " << client.first.Get_Phone() <<
             "\nAccount ID : " << client.second.Get_Id() << " " << client.second.Get_Type() <<
             "\nBalance : " << client.second.Get_Balance() << endl ;
    }

    while (true)
    {
    Here:

        cout << "\n1. Create a New Account \n"
                "2. List Clients and Accounts \n"
                "3. Withdraw Money \n"
                "4. Deposit Money\n"
                "0. Exit\n=========>" ;

        string Choice ;
        cin.sync() ;
        getline(cin, Choice) ;

        if (!Is_Valid(Choice)) {
            cout << "Invalid Choice :(\n"  ;
            goto Here ;
        }
        if (Choice == "1"){
            B1.addClient() ;
        }
        else if(Choice == "2"){
            B1.Print_Info() ;
        }
        else  if(Choice == "3"){
            string ID ;
            cout << "Please Enter Account ID (e.g., FCAI-015) =========>" ;
            cin >> ID ;

            B1.Check_Id(ID, 1) ;
        }
        else if(Choice == "4"){
            string ID ;
            cout << "Please Enter Account ID (e.g., FCAI-015) =========>" ;
            cin >> ID ;

            B1.Check_Id(ID, 2) ;
        }
        else{
            return 0 ;
        }
    }
}