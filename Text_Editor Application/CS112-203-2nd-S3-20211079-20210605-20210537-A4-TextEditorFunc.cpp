# include "CS112-203-2nd-S3-20211079-20210605-20210537-A4-TextEditorFunc.h"


using namespace std ;

bool Check_Option(string& option)
{

    regex int_format ("[1-9]?[0-6]?") ;

    // I used regex_math to check the input matches to the format or no .

    // If it matches so the function return true if no return false .

    return regex_match (option, int_format) ;

}


//-----------------------------------------

string Get_Data(fstream& File)
{

    string data ;

    while(File.peek() != EOF)
    {

        File.getline(words, 1000, '\n') ;

        data += words ;

        if (File.peek() != EOF)

            data += '\n' ;

    }

    return data ;
}


//-----------------------------------------

// Mohamed Safaa
// Here I will Append text To the end of the File .
// Append Task
// Version --> 1.0

void Append_To_File(fstream& File)
{

    if (save)
    {

        fstream Append_File;

        Append_File.open(File_Name, ios::app);

        Append_File << '\n';

        Append_File << Append;

        File << Append_File.rdbuf();

        Append_File.close();

    }

    else
    {

        cout << "\nEnter What you need to put in the File\n-->";

        cin.ignore();

        getline(cin, Append);

    }
}


//-----------------------------------------

// Mohamed Safaa
// Here I will display  content of file .
// Display Task
// Version --> 1.0

void Display_File(fstream& File)
{

    cout << "\nThe Content of the file ...\n\n" ;

    cout << File.rdbuf();

}


//-----------------------------------------

// Mohamed Safaa
// Here I will Delete content of file .
// Delete Task
// Version --> 1.0

void Delete_Content(fstream& File)
{

    if (save)
    {

        cout << "\nThe Content of the file will Delete\n";

        File.close();

        File.open(File_Name, ios::out);

    }
}


//-----------------------------------------

// Mohamed Safaa
// Here I will Encrypt the Content of the File .
// Encrypt Task
// Version --> 1.0

void Encrypt_Content (fstream& File)
{

    if (save)
    {

        text = Get_Data(File) ;

        File.close();

        File.open(File_Name, ios::out) ;

        for (char i : text)
        {

            if (i != '\n')

                i = char(int (i) + 1) ;

            File.put(i);

        }
    }
}


//-----------------------------------------

// Mohamed Safaa
// Here I will Decrypt the Content of the File .
// Decrypt Task
// Version --> 1.0

void Decrypt_Content (fstream& File)
{

    if (save)
    {

        text = Get_Data(File) ;

        File.close();

        File.open(File_Name, ios::out) ;

        for (char i : text)
        {

            if (i != '\n')

                i = char(int (i) - 1) ;

            File.put(i);

        }
    }
}


//-----------------------------------------

// Badr Mohamed
// Here I Load The first file .
// merge task
// Version --> 3.0

void Load_Merge_File_1()
{

    Merge_File_1.open(File_Name, ios::app) ;

}


//-----------------------------------------

// Badr Mohamed
// Here I Load The Second File .
// merge task
// Version --> 3.0

void Load_Merge_File_2()
{

    do
    {

        cout << "\nEnter the Second file Name\n-->";

        char Merge_Name_2 [50] ;

        cin >> Merge_Name_2;

        Merge_File_Name_2 = strcat(Merge_Name_2, ".txt") ;

        Merge_File_2.open(Merge_File_Name_2);

        if (!Merge_File_2.fail())

            cout << "\nThe File is Exist :)" << endl;

        else

            cout << "\nThe File is Not Exist :(\nTry again" << endl;

    }

    while (Merge_File_2.fail()) ;

}


//-----------------------------------------

// Badr Mohamed
// Here I Merge the content of the second file to the first file .
// merge task
// Version --> 3.0

void Merge_File(fstream& File)
{

    if (save)
    {
        Merge_File_1.put(' ');

        Merge_File_1 << Merge_File_2.rdbuf() ;

        Merge_File_2.close() ;

    }

    else
    {

        Load_Merge_File_1() ;

        Load_Merge_File_2() ;

    }
}


//-----------------------------------------
// Mohamed Amir
// Here I get the number of a word in the file
// First Task
// Version --> 3.0

void Count_Word (fstream& File)
{

    int count_word = 0 ;

    // Here the user input the word .

    string word;

    cout << "\nEnter the word\n-->";

    cin.ignore();

    getline(cin, word);

    transform(word.begin(), word.end(), word.begin(), ::tolower) ;

    // Here the while stop when the file ends .

    while (File >> text)
    {

        transform(text.begin(), text.end(), text.begin(), ::tolower) ;

        if (text == word)
        {

            // If they are equal, So I increment the counter of the word .

            count_word++;

        }
    }

    cout << "\nThe Word --> \" " << word << " \" is Exist " << count_word << " Times in the File --> " << File_Name
         << endl;

}

//---------------------------------------

// Mohamed Amir
// Here I Convert the character to uppercase .
// Second Task
// Version --> 3.0

void Upper_Case (fstream& File)
{

    if (save)
    {

        text = Get_Data(File) ;

        transform(text.begin(), text.end(), text.begin(), ::toupper);

        File.close();

        File.open(File_Name, ios::out);

        for (char i : text)
        {

            File.put(i);

        }
    }
}


void search_word (fstream& File)
{
    cout<<"\nEnter the word that you want to search for it: "<<endl;

    cin.ignore();

    getline(cin, text);

    transform(text.begin(), text.end(), text.begin(), ::tolower);

    bool found = false;

    string word;

    while(File >> word )
    {

        transform(word.begin(), word.end(), word.begin(), ::tolower);

        if ( word == text)
        {
            found = true;
            break;

        }
        else
        {
            found = false;
        }
    }

        if (found)
        {
            cout<<"\nWord was found in the file\n";
        }

        else

        {
            cout<<"\nWord was not found in the file\n";
        }

        File.close();

}



void count_lines(fstream& File)
{
    int countlines = 0;

    while (!File.eof())
    {

        File.getline(words, 256, '\n');

        countlines++;

    }

        cout<<"The number of lines is  =  "<<countlines;

        File.close();

}


void count_chars (fstream& File)
{
    char chars ;

    int countchars = 0;

    while(File >> chars)
    {

        countchars ++;

    }

        cout<<"\n"<<"the number of characters is =  "<<countchars;

        File.close();
}


void count_words (fstream& File )
{

    int countwords = 0 ;

    while(File >> text)
    {

        countwords++ ;

    }

        cout<<"\n"<<"the words in the file is  =  "<<countwords;

        File.close();
}

//---------------------------------------

// Mohamed Amir
// Here I Convert the character to lowercase .
// Third Task
// Version --> 3.0

void Lower_Case (fstream& File)
{

    if (save)
    {

        text = Get_Data(File) ;

        transform(text.begin(), text.end(), text.begin(), ::tolower) ;

        File.close();

        File.open(File_Name, ios::out) ;

        for (char i : text)
        {

            File.put(i);

        }
    }
}


//---------------------------------------

// Mohamed Amir
// Here I Convert the character to lowercase Except the first .
// Fourth Task
// Version --> 3.0

void Upper_Lower (fstream& File)
{

    if (save)
    {

        text = Get_Data(File) ;

        File.close() ;

        File.open(File_Name, ios::out) ;

        text[0] = toupper(text[0]) ;

        File.put(text[0]) ;

        for (int i = 1; i < text.length() - 1; ++i)
        {

            if (text[i] == ' ' || text[i] == '\n')
            {

                File.put(text[i]);

                if(isalpha(text[i + 1]))
                {

                    text[i + 1] = toupper(text[i + 1]) ;

                    File.put(text[i + 1]) ;

                    i++ ;

                }
            }

            else
            {

                text[i] = tolower(text[i]) ;

                File.put(text[i]) ;

            }
        }
    }
}


//---------------------------------------

// Mohamed Amir
// Here I Save the File After any Edit .
// Fifth Task
// Version --> 3.0

void Save (fstream& File)
{

    string choice ;

    save = true ;

    if (turn == "1")
    {

        Append_To_File(File) ;

    }

    else if (turn == "3")

        Delete_Content(File) ;

    else if (turn == "4")

        Encrypt_Content(File) ;

    else if (turn == "5")

        Decrypt_Content(File) ;

    else if (turn == "6")
    {

        Merge_File(File);

        while(Merge_File_1.peek() != EOF)
        {

            File.put((char)Merge_File_1.get()) ;

        }

        Merge_File_1.close() ;
    }

    else if (turn == "12")

        Upper_Case(File) ;

    else if (turn == "13")

        Lower_Case(File) ;

    else if (turn == "14")
    {

        Upper_Lower(File) ;

    }

    while (true)
    {

        cout << "\nEnter the process\n\n1 - To Save in the Same File\n2 - To Save in New File\n-->" ;

        cin >> choice ;

        if (choice == "1")
        {

            File.close();

            break ;

        }

        else if (choice == "2")
        {

            File.close() ;

            File.open(File_Name) ;

            ofstream New_File ;

            char Name[50];

            string New_File_Name ;

            cout << "\nEnter the file Name\n-->";

            cin >> Name;

            // Here I add the .txt to the string .

            New_File_Name = strcat(Name, ".txt");

            New_File.open(New_File_Name) ;

            New_File << File.rdbuf() ;

            New_File.close() ;

            break ;
        }

        else

            cout << "\nInvalid Input :(\nTry again" << endl ;

    }

    save = false ;

}


//---------------------------------------

// Mohamed Amir
// Here I Save the File After any Edit .
// Display Task
// Version --> 1.0

void Display()
{

    cout << "\nHello User :)\n\nWelcome to Text Editor :)\n" << endl ;

    fstream File ;

    char Name[50] ;

    cout << "\nEnter the file Name\n-->";

    cin >> Name;

    // Here I add the .txt to the string .

    File_Name = strcat(Name, ".txt");

    File.open(File_Name) ;

    // Here I check if the file Exist or no .

    if (!File.fail())
    {

        cout << "\nThe File is Exist :)" << endl;

    }

    else
    {

        File.open(File_Name, ios::out) ;

        cout << "\n\"This is a new file. I created it for you \uF04A" << endl;

    }

    string option ;

    while(true)
    {

        cout << "\nYou Must Enter Save to save the Edit in the file if you don't make save the Edit was lost" << endl << endl ;

        cout << "\nEnter The process\n\n01 - To Append to the end of The File\n02 - To Display The File content"
                "\n03 - To Delete The File content\n04 - To Encrypt the File content\n05 - To Decrypt the File content"
                "\n06 - To Merge Two Files\n07 - To Count the number of words in the file\n08 - To Count the number of characters in the file"
                "\n09 - To Count the number of lines in the file\n10 - To Search for a word in the file\n11 - To Count a Word in the file\n12 - To Upper_Case All Characters of the file"
                "\n13 - To To Lower_Case All Characters of the file\n14 - To To Lower_Case All Characters of the file Except the First"
                "\n15 - To Save\n16 - To Exit\n-->" ;

        option = "" ;

        cin >> option;

        if(Check_Option(option))
        {

            if (option == "1")

                Append_To_File(File) ;

            if (option == "2")

                Display_File(File) ;

            else if (option == "6")

                Merge_File(File);

            else if (option == "7")

                count_words(File) ;

            else if (option == "8")

                count_chars(File) ;

            else if(option == "9")

                count_lines(File) ;

            else if(option == "10")

                search_word(File) ;

            else if (option == "11")

                Count_Word(File);

            else if (option == "15")
            {

                Save(File) ;

            }

            else if (option == "16")
            {

                cout << "\n\nThanks for using Image_Editor :)\n" ;

                exit(1) ;

            }

            else

                Get_Data(File) ;

            turn = option ;

            File.close() ;

            File.open(File_Name) ;

        }

        else

            cout << "\nInvalid Input :(\nTry again" << endl ;


    }
}
