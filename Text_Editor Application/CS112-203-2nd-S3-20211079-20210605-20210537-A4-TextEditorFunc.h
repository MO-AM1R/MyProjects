#ifndef CS112-203-2nd-S3-20211079-20210605-20210537-A4-TextEditorFunc_H_INCLUDED
#define CS112-203-2nd-S3-20211079-20210605-20210537-A4-TextEditorFunc_H_INCLUDED

# include <iostream>
# include <string>
# include <regex>
# include <fstream>
# include <cstring>
# include <cctype>

using namespace std ;

string File_Name, Merge_File_Name_2 ;

fstream Merge_File_1 ;

fstream Merge_File_2 ;

string turn ;

string text ;

string Append;

char words [1000];

bool save = false ;

//-----------------------------------------

bool Check_Option(string& option) ;

//-----------------------------------------

string Get_Data(fstream& File) ;

//-----------------------------------------

void Append_To_File(fstream& File) ;

//-----------------------------------------

void Display_File(fstream& File) ;

//-----------------------------------------

void Delete_Content(fstream& File) ;

//-----------------------------------------

void Encrypt_Content (fstream& File) ;

//-----------------------------------------

void Decrypt_Content (fstream& File) ;

//-----------------------------------------

void Load_Merge_File_1() ;

//-----------------------------------------

void Load_Merge_File_2() ;

//-----------------------------------------

void Merge_File(fstream& File) ;

//-----------------------------------------

void count_words (fstream& File ) ;

//-----------------------------------------

void count_chars (fstream& File) ;

//-----------------------------------------

void count_lines(fstream& File) ;

//-----------------------------------------

void search_word (fstream& File) ;

//-----------------------------------------

void Count_Word (fstream& File) ;

//-----------------------------------------

void Upper_Case (fstream& File) ;

//-----------------------------------------

void Lower_Case (fstream& File) ;

//-----------------------------------------

void Upper_Lower (fstream& File) ;

//-----------------------------------------

void Save (fstream& File) ;

//-----------------------------------------

void Display () ;

//-----------------------------------------

#endif // CS112-203-2nd-S3-20211079-20210605-20210537-A4-TextEditorFunc_H_INCLUDED
