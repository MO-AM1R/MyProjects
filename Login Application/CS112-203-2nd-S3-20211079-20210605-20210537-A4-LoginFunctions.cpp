# include "CS112-203-2nd-S3-20211079-20210605-20210537-A4-LoginFunctions.h"

using namespace std ;

string Encrypt(string& Decrypt_Pass)
{

    int ind ;

    vector <char> alpha_cipher ;

    string alpha ;

    alpha_cipher.push_back('c') ;

    alpha_cipher.push_back('a') ;

    alpha_cipher.push_back('i') ;

    alpha_cipher.push_back('r') ;

    alpha_cipher.push_back('o') ;

    for (int i = 97; i <= 122; i++)

        alpha.push_back(char(i)) ;

    for (int i = 65; i <= 90 ; i++)

        alpha.push_back(char(i)) ;

    for (int i = 97; i <= 122; i++)
    {

        if (!count(alpha_cipher.begin(), alpha_cipher.end(), char(i)))

            alpha_cipher.push_back(char(i));

    }

    alpha_cipher.push_back('C') ;

    alpha_cipher.push_back('A') ;

    alpha_cipher.push_back('I') ;

    alpha_cipher.push_back('R') ;

    alpha_cipher.push_back('O') ;

    for (int i = 65; i <= 90; i++)
    {

        if (!count(alpha_cipher.begin(), alpha_cipher.end(), char(i)))

            alpha_cipher.push_back(char(i));

    }

    for (char & Pas : Decrypt_Pass)
    {
        if (Pas == ' ' )

            Pas = char (int(Pas) + 1) ;

        else if (ispunct(Pas) || isdigit(Pas))
        {

            Pas = char (int(Pas) - 1);

        }

        else
        {

            ind = (int) alpha.find(Pas) ;

            Pas = (char) alpha_cipher.at(ind) ;

        }
    }

    return Decrypt_Pass ;
}


//----------------------

string Decrypt(string& Decrypt_Pass)
{

    int ind ;

    vector <char> alpha_cipher ;

    string alpha;

    alpha_cipher.push_back('c') ;

    alpha_cipher.push_back('a') ;

    alpha_cipher.push_back('i') ;

    alpha_cipher.push_back('r') ;

    alpha_cipher.push_back('o') ;

    for (int i = 97; i <= 122; i++)

        alpha.push_back(char(i)) ;

    for (int i = 65; i <= 90 ; i++)

        alpha.push_back(char(i)) ;

    for (int i = 97; i <= 122; i++)
    {

        if (!count(alpha_cipher.begin(), alpha_cipher.end(), char(i)))

            alpha_cipher.push_back(char(i));

    }

    alpha_cipher.push_back('C') ;

    alpha_cipher.push_back('A') ;

    alpha_cipher.push_back('I') ;

    alpha_cipher.push_back('R') ;

    alpha_cipher.push_back('O') ;

    for (int i = 65; i <= 90; i++)
    {

        if (!count(alpha_cipher.begin(), alpha_cipher.end(), char(i)))

            alpha_cipher.push_back(char(i));

    }

    for (char& Pas : Decrypt_Pass)
    {

        if (Pas == '!')

            Pas = char (int(Pas) - 1) ;

        else if (ispunct(Pas) || isdigit(Pas))
        {

            Pas = char (int(Pas) + 1);

        }

        else
        {

            auto it = find(alpha_cipher.begin(), alpha_cipher.end(), Pas);

            if (it != alpha_cipher.end())

                ind = int(it - alpha_cipher.begin()) ;

            Pas = alpha.at(ind);

        }
    }

    return Decrypt_Pass ;
}


//----------------------

void Fill_Map(fstream& File)
{
    string Id, User_Name, Email, Mobile, Password ;

    File.close() ;

    File.open(Name) ;

    while (File.peek() != EOF)
    {

        getline(File, Id) ;

        getline(File, User_Name) ;

        getline(File, Email) ;

        getline(File, Mobile) ;

        getline(File, Password) ;

        User_Info[Id] = {Id, User_Name, Email, Mobile, Password} ;

    }

    File.close() ;
}


//----------------------

bool Check_Email(string& text)
{

    bool Exist_Email = false ;

    for (const auto& iter : User_Info)
    {

        if(User_Info[iter.first].Email == text)
        {

            Exist_Email = true ;

        }
    }

    return !Exist_Email ;

}


//----------------------

bool Check_ID(string& text)
{

    if (User_Info.count(text) == 1)
    {

        return true ;

    }

    else
    {

        return false ;

    }
}


//----------------------

bool Register_Check(int process, string text)
{

    bool ret = false;

    if (process == 1)
    {

        regex ID_Format ("[0-9]+") ;

        if (regex_match(text, ID_Format) && (!Check_ID(text)))

            ret = true ;

    }

    else if (process == 2)
    {

        regex User_Name_Format ("([a-zA-Z])+[\\_]?([a-zA-Z])+") ;

        ret = regex_match(text, User_Name_Format) ;

    }

    else if (process == 3)
    {

        regex Email_Format ("^[a-zA-Z0-9+_.-]+@[a-zA-Z.-]+$") ;

        if (regex_match(text, Email_Format) && (Check_Email(text)))

            ret = true ;

    }

    else if (process == 4)
    {

        regex Mobile_Format ("(011|012|010|015){1}[0-9]{8}") ;

        ret = regex_match(text, Mobile_Format) ;

    }

    else
    {

        regex Pass_Format ("((?=.*[a-z])(?=.*[0-9])(?=.*[A-Z])(?=.*[!?_.,/><*&^%$#@ ]*)[a-zA-Z0-9!?_.,/><*&^%$#@ ]*){8,15}") ;

        ret = regex_match(text, Pass_Format) ;

    }

    return ret ;
}


//----------------------

void Registration()
{

    cout << endl << setw(50) << setfill('=') << '=' << endl << endl ;

    cout << setw(16) << setfill('=') << '=' << " Register Step :) " << setw(16) << setfill('=') << '=' << endl ;

    cout << "\nNote --> To Register you Should fill the next\nYou must Sure that you don't have Email\n" ;

    Id:

    cout << "\nEnter the ID\nIt Should only Numbers\n-->" ;

    cin >> inFormation.ID ;

    if (!Register_Check(1, inFormation.ID))
    {

        cout << "\nYou Entered an Exist ID or Wrong ID :(\nTry again\n" ;

        goto Id ;

    }

    Us:

    cout << "\nEnter the User Name\nWithout any Spaces or Punctuations Except (' _ ')\n-->" ;

    cin >> inFormation.User_Name ;

    if (!Register_Check(2, inFormation.User_Name))
    {

        cout << "\nYou Entered an Wrong User_Name :(\nTry again\n" ;

        goto Us ;

    }

    Em:

    cout << "\nEnter the Email\nThe First character Should be letter Then Followed by ( '@' ) and ('.com') in the End\n-->" ;

    cin >> inFormation.Email ;

    if (!Register_Check(3, inFormation.Email))
    {

        cout << "\nYou Entered an Exist Email or Wrong Email :(\nTry again\n" ;

        goto Em ;

    }

    Mo:

    cout << "\nEnter the mobile\nThe Mobile Number Should be 11 Digit and Start by 01\n-->" ;

    cin >> inFormation.Mobile ;

    if (!Register_Check(4, inFormation.Mobile))
    {

        cout << "\nYou Entered a Wrong Mobile :(\nTry again\n" ;

        goto Mo ;

    }

    Pass:

    string Repeated_Pass ;

    cout << "\nEnter the Password\n--> The password Should Contain at least One of ...\n--> Special Character"
            "\n--> Letter\n--> Upper_case\n--> Letter Lower_case\n--> Digit\n--> At least 8 Characters upto 15"
            "\n--> Space\n-->" ;

    char character ;

    int Check = 0 ;

    while((character = (char)getch()) != '\r' )
    {

        if (character < 0 || Check % 2 != 0)
        {

            Check ++ ;

        }

        else if(character == 8)
        {

            if (!inFormation.Password.empty())
            {

                inFormation.Password.pop_back() ;

                cout << character << " " << character ;

            }
        }

        else
        {

            inFormation.Password += character ;

            cout << "*" ;

        }
    }

    if (!Register_Check(5, inFormation.Password))
    {

        cout << "\nThe Password isn't Strong :(\nTry again\n" ;

        inFormation.Password = "" ;

        goto Pass ;

    }

    cout << "\nEnter the Repeated_Password\n-->" ;

    Check = 0 ;

    while((character = (char)getch()) != '\r' )
    {

        if (character < 0 || Check % 2 != 0)
        {

            Check ++ ;

        }

        else if(character == 8)
        {

            if (!Repeated_Pass.empty())
            {

                Repeated_Pass.pop_back() ;

                cout << character << " " << character ;

            }
        }

        else
        {

            Repeated_Pass += character ;

            cout << "*" ;

        }
    }

    if (Repeated_Pass != inFormation.Password)
    {

        cout << "\nThe Passwords aren't Identical :(\nTry again\n" ;

        inFormation.Password = "" ;

        Repeated_Pass = "" ;

        goto Pass ;

    }

}


//----------------------

void Fill_File(fstream& File)
{

    File.close() ;

    File.open(Name, ios::app) ;

    File << inFormation.ID << endl ;

    File << inFormation.User_Name << endl ;

    File << inFormation.Email << endl ;

    File << inFormation.Mobile << endl ;

    Encrypt(inFormation.Password) ;

    File << inFormation.Password << endl;

    File.close() ;

}


//----------------------

string Get_Pass(string& ID)
{

    string Pass = User_Info[ID].Password ;

    return Pass ;
}


//----------------------

string Get_Name(string& ID)
{

    string User_Name = User_Info[ID].User_Name ;

    return User_Name ;
}


//----------------------

void Login()
{

    // Here I Display the user Welcome .

    cout << endl << setw(50) << setfill('=') << '=' << endl << endl ;

    cout << setw(18) << setfill('=') << '=' << " Login Step :) " << setw(17) << setfill('=') << '=' << endl ;

    // The Counter I Used it to Deny the user if input the Password or ID incorrect 3 Times .

    int counter = 2 ;

    string ID, Pass, Password ;

    // Here I declare a Label to return to it again if the User input incorrect ID .

    Log_ID :

    ID = "" ;

    cout << "\nEnter the ID Correctly :)\n-->" ;

    // Here I get the ID from User .

    cin.sync() ;

    cin.clear() ;

    getline(cin, ID) ;

    // Here I Assign Pass to Get_Pass Function to get the Actually Password .

    Pass = Get_Pass(ID) ;

    // Here I Decrypt The Pass to Compare it by the Password which User input .

    Pass = Decrypt(Pass) ;

    cout << "\nEnter the Password Correctly :)\n-->" ;

    // This Code I just Cover the Password by * by getch Function .

    char character ;

    int Check = 0 ;

    while((character = (char)getch()) != '\r' )
    {

        // Here I handle the probably Errors .

        if (character < 0 || Check % 2 != 0)
        {

            Check++;

        }

        else if (character == 8)
        {

            if (!Password.empty())
            {

                Password.pop_back();

                cout << character << " " << character;

            }
        }

        else
        {

            // Here I add The character to Password .

            Password += character ;

            cout << '*' ;

        }
    }

    // Here I Declare the Login variable as a bool to use it to Check if the user input correctly .

    bool Log_in = false ;

    // Here I Check if the Actually Password is equal to Password Which user input

    // and the counter is still greater than 0 .

    if ((Pass != Password || !Check_ID(ID)) && counter != 0)
    {

        // If Not, So I return To Log_ID Again .

        cout << "\nWrong Password OR Wrong ID :(\nPlease try Again Carefully Remaining Attempts : " << counter << endl ;

        counter -- ;

        Password = "" ;

        goto Log_ID ;

    }

    else if (Pass == Password && Check_ID(ID))

        // If yes, So I Assign the Log_in Variable by true .

        Log_in = true ;


    // If Log_in is true, So The User Login Successfully .

    if (Log_in)

        cout << "\nSuccessful Login Welcome " << Get_Name(ID) << " :)" << endl ;

    // If Not I told to the User You are Denied from the System .

    else

        cout << "\nYou are denied Access to the System :(" ;

}


//----------------------

// HEre I Replace the Old Password to the New .

void Change_File_Pass(string& ID, string& Pass, string& New_Pass, fstream& File)
{

    // Here I Close the File and Open it again to return the Seek to hte first of the file .

    File.close() ;

    File.open(Name) ;

    string Each_Line ;

    string Line ;

    // Here I get the data of the File in the string Line .

    while (getline(File, Each_Line))
    {

        // If the line is the old_Pass, So I replace it in the Line by The New_Pass .

        if (Each_Line == Pass)

            Line += New_Pass ;

        // If Not, So I add the Lines .

        else

            Line += Each_Line ;

        Line += '\n' ;

    }

    // Here I Close the File and Open it at ios::app to delete the data .

    File.close() ;

    File.open(Name, ios::out) ;

    // After Deleting the data of the File I add the Lines .

    File << Line ;

    // Finally, I Close the File .

    File.close() ;

}


//----------------------

void Change_Pass (fstream& File)
{

    cout << endl << setw(50) << setfill('=') << '=' << endl << endl ;

    cout << setw(13) << setfill('=') << '=' << " Change Password Step :) " << setw(12) << setfill('=') << '=' << endl ;

    string old_pass, ID , Pass, New_Pass,New_Rep_Pass  ;

    ID:

    cout << "\nEnter the id :)\n-->" ;

    cin >> ID;

    if(!Check_ID(ID))
    {

        ID = "";

        goto ID;

    }

    Old_Password:

    cout << "\nEnter the old password\n-->" ;

    char character ;

    int Check = 0 ;

    while((character = (char)getch()) != '\r' )
    {

        if (character < 0 || Check % 2 != 0)
        {

            Check ++ ;

        }

        else if(character == 8)
        {

            if (!old_pass.empty())
            {

                old_pass.pop_back() ;

                cout << character << " " << character ;

            }
        }

        else
        {

            old_pass += character ;

            cout << "*" ;

        }
    }

    old_pass = Encrypt(old_pass) ;

    Pass = Get_Pass(ID) ;

    if(Pass != old_pass)
    {

        old_pass = "";

        cout << "\nThe Password isn't correct\nTry again\n" ;

        goto Old_Password ;

    }

    cout << "\nEnter the Password\n--> The password Should Contain at least One of ...\n--> Special Character"
            "\n--> Letter\n--> Upper_case\n--> Letter Lower_case\n--> Digit\n--> At least 8 Characters upto 15"
            "\n--> Space\n-->" ;

    Check = 0 ;

    while((character = (char)getch()) != '\r' )
    {

        if (character < 0 || Check % 2 != 0)
        {

            Check ++ ;

        }

        else if(character == 8)
        {

            if (!New_Pass.empty())
            {

                New_Pass.pop_back() ;

                cout << character << " " << character ;

            }
        }

        else
        {

            New_Pass += character ;

            cout << "*" ;

        }
    }

    if (!Register_Check(5, New_Pass))
    {

        cout << "\nThe Password isn't Strong :(\nTry again\n" ;

        New_Pass = "" ;

        goto Old_Password;

    }

    cout << "\nEnter the Repeated New Password :)\n-->" ;

    Check = 0 ;

    while((character = (char)getch()) != '\r' )
    {

        if (character < 0 || Check % 2 != 0)
        {

            Check ++ ;

        }

        else if(character == 8)
        {

            if (!New_Rep_Pass.empty())
            {

                New_Rep_Pass.pop_back() ;

                cout << character << " " << character ;

            }
        }

        else
        {

            New_Rep_Pass += character ;

            cout << "*" ;

        }
    }

    if (New_Rep_Pass != New_Pass)
    {

        cout << "\nThe Passwords aren't Identical :(\nTry again\n" ;

        New_Pass = "" ;

        New_Rep_Pass = "" ;

        goto Old_Password;

    }

    New_Pass = Encrypt(New_Pass) ;

    User_Info[ID].Password = New_Pass ;

    Change_File_Pass(ID, old_pass, New_Pass, File);

    cout << "\nThe Password Has Changed Successfully :)\n" ;

}


//----------------------

// Here I Display the menu to the user .

void Display()
{

    cout << endl << setw(50) << setfill('=') << '=' << endl << endl ;

    cout << setw(8) << setfill('=') << '=' << " Welcome To Login Application :) " << setw(9) << setfill('=') << '=' << endl ;

    cout << endl << setw(50) << setfill('=') << '=' << endl << endl ;

    cout << setw(18) << setfill('=') << '=' << " File Step :) " << setw(18) << setfill('=') << '=' << endl ;

    // Here I Declare the fstream file to open the Users File .

    fstream File ;

    Name = "Login.txt" ;

    File.open(Name) ;

    // Here I check if the File Exist or not if it's ,so I open it if not I Create a New and open it by ios::app

    // to Append at it .

    if (File.fail())
    {

        cout << "\nThe File isn't Exist So I creat a New :)" << endl ;

        File.close() ;

        File.open(Name, ios::app) ;

    }

    else
    {

        cout << "\nThe File is Exist :)" << endl ;

        File.close() ;

        File.open(Name, ios::app) ;

    }

    // Here I call Fill_Map to Fil the Map by The Information of the Users in the File .

    Fill_Map(File) ;

    // Here I Declare choice to allow the user to input the Process .

    string choice ;

    while (choice != "0")
    {

        cout << endl << setw(50) << setfill('=') << '=' << endl << endl ;

        cout << setw(18) << setfill('=') << '=' << " Main Step :) " << setw(18) << setfill('=') << '=' << endl ;

        cout << "\n0 - To Exit ...\n1 - To Register ...\n2 - To Login ...\n3 - To Change Password ...\n-->" ;

        cin >> choice ;

        if (choice == "1" || choice == "01")
        {

            Registration();

            Fill_File(File);

            Fill_Map(File) ;

        }

        else if(choice == "2" || choice == "02")

            Login() ;

        else if( choice == "3" || choice == "03")

            Change_Pass(File);

        else if (choice == "0")

            continue ;

        else

            cout << "\nInvalid Input\nTry again\n" ;

    }

    File.close() ;

    cout << endl << setw(50) << setfill('=') << '=' << endl << endl ;

    cout << setw(18) << setfill('=') << '=' << " Exit Step :) " << setw(18) << setfill('=') << '=' << endl << endl ;

    cout << setw(6) << setfill('=') << '=' << " Thanks For Using Login Application :) " << setw(5)

     << setfill('=') << '=' << endl ;


}
