#ifndef CS112-203-2nd-S3-20211079-20210605-20210537-A4-LoginFunctions_H_INCLUDED
#define CS112-203-2nd-S3-20211079-20210605-20210537-A4-LoginFunctions_H_INCLUDED

# include <iostream>
# include <string>
# include <conio.h>
# include <fstream>
# include <vector>
# include <map>
# include <regex>
# include <iomanip>

using namespace std ;


//----------------------

struct info
{

    string ID, User_Name, Email, Mobile, Password ;

} ;


//----------------------

string Name ;

map <string, info> User_Info ;

info inFormation ;


//----------------------

string Encrypt(string& Decrypt_Pass) ;

//----------------------

string Decrypt(string& Decrypt_Pass) ;

//----------------------

void Fill_Map(fstream& File) ;

//----------------------

bool Check_Email(string& text) ;

//----------------------

bool Check_ID(string& text) ;

//----------------------

bool Register_Check(int process, string text) ;

//----------------------

void Registration() ;

//----------------------

void Fill_File(fstream& File) ;

//----------------------

string Get_Pass(string& ID) ;

//----------------------

string Get_Name(string& ID) ;

//----------------------

void Login() ;

//----------------------

void Change_File_Pass(string& ID, string& Pass, string& New_Pass, fstream& File) ;

//----------------------

void Change_Pass (fstream& File) ;

//----------------------

void Display() ;

//----------------------

#endif // CS112-203-2nd-S3-20211079-20210605-20210537-A4-LoginFunctions_H_INCLUDED
