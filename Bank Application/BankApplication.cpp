# include "BankApplication.h"

BankApplication::BankApplication(string & M) {
    File_Name = M ;
    Data.open(File_Name)  ;
    string Line ;
    while (getline(Data, Line))
    {
        Client C  ;
        BankAccount A ;

        C.Set_Name(Line.substr(0, (int)Line.find('|') - 1)) ;

        Line = Line.substr((int)Line.find('|') + 2, - 1) ;
        C.Set_Address(Line.substr(0, (int)Line.find('|') - 1)) ;

        Line = Line.substr((int)Line.find('|') + 2, - 1) ;
        C.Set_Phone(Line.substr(0, (int)Line.find('|') - 1)) ;

        Line = Line.substr((int)Line.find('|') + 2, - 1) ;
        A.Set_Id(Line.substr(0, (int)Line.find('(') - 2)) ;

        Line = Line.substr((int)Line.find('('), - 1) ;
        A.Set_Type(Line.substr(0, (int)Line.find(')') + 1)) ;

        Line = Line.substr((int)Line.find('|') + 2, - 1) ;
        Line = Line.substr(0, (int)Line.find(';') - 1) ;
        A.Set_Balance(stod(Line)) ;

        clients.insert(clients.end(), {C, A}) ;
    }
    Data.close() ;
    Data.open(File_Name, ios::app) ;
}

void BankApplication::Update_File()
{
    Data.close() ;
    Data.open(File_Name, ios::out) ;

    for (int i = 0; i < Client::Get_Number_Clients(); ++i) {
        Data << clients[i].first.Get_Name() << " | "
        << clients[i].first.Get_Address() << " | "
        << clients[i].first.Get_Phone() << " | "
        << clients[i].second.Get_Id() << "  " << clients[i].second.Get_Type()
        << " | " << clients[i].second.Get_Balance() << " ;\n" ;
    }
}

bool BankApplication::addClient() {
    string Temp ;
    Client c1 ;
    cout << "Please Enter Client Name =========>" ;
    cin >> Temp ;
    c1.Set_Name(Temp);

    cout << "Please Enter Client Address =========>" ;
    cin.sync() ;
    getline(cin, Temp) ;
    c1.Set_Address(Temp) ;

Phone:
    cout << "Please Enter Client Phone =========>" ;
    cin >> Temp ;
    if (Temp.size() != 11) {
        cout << "Invalid Input :(\n";
        goto Phone;
    }

    c1.Set_Phone(Temp);
Again:
    cout << "\nWhat Type of Account Do You Like? (1) Basic (2) Saving – Type 1 or 2 =========>" ;
    char Option ;
    cin >> Option ;
    if (Option == '1')
    {
        double Bal ;
        cout  << "\nPlease Enter the Starting Balance =========>" ;
        cin >> Bal ;
        BankAccount Acc (Bal, Client::Get_Number_Clients()) ;
        clients.emplace_back(c1, Acc) ;
    }
    else if(Option == '2')
    {
    Input :
        double Bal ;
        cout  << "\nEnter the Balance\nNotice that there is 1000 L.E (minimum balance) "
                 "will be refunded in your Account =========>" ;
        cin >> Bal ;

        if (Bal < 1000)
        {
            cout << "You must deposit at least 1000 L.E\n" ;
            goto Input ;
        }

        SavingBankAccount S(Bal, Client::Get_Number_Clients()) ;
        clients.emplace_back(c1, S) ;
    }
    else
    {
        cout << "Invalid Input :(\n" ;
        goto Again;
    }

    cout << "An account was created with ID " << clients[Client::Get_Number_Clients() - 1].second.Get_Id()
    << " and Starting Balance " << clients[Client::Get_Number_Clients() - 1].second.Get_Balance() << " L.E.\n" ;

    Update_File() ;
    return true;
}

void BankApplication::Check_Id(const string & ID, int Choice) {
    bool Exist = false;

    for (auto & client : clients) {
        if (client.second.Get_Id() == ID)
        {
            cout << "Account ID : " <<  client.second.Get_Id() << endl ;
            cout << "Account type : "  << client.second.Get_Type() << endl ;
            cout << "Balance : " << client.second.Get_Balance() << endl ;

        Again :
            double amount ;
            cout << "\nEnter the Amount =========>" ;
            cin >> amount ;

            if (Choice == 1)
            {
                if(!client.second.WithDraw(amount)) {
                    goto Again;
                }
            }
            else
            {
                client.second.Deposit(amount) ;
            }

            Update_File() ;
            Exist = true ;
        }
    }
    if (!Exist){
        cout << "The ID isn't Exist :(" << endl ;
    }
}

BankApplication::~BankApplication() {
    Data.close() ;
}

void BankApplication::Print_Info() {
    for (auto & client : clients) {
        cout << setw(5) << setfill('-') << " " << client.first.Get_Name() << " " << setw(5) << setfill('-') << "-" ;
        cout << "\nAddress : " << client.first.Get_Address() << " Phone : " << client.first.Get_Phone() <<
        "\nAccount ID : " << client.second.Get_Id() << " " << client.second.Get_Type() <<
        "\nBalance : " << client.second.Get_Balance() << endl ;
    }
}