# include "BigDecimalInt.h"

bool isSmaller(string str1, string str2)
{

    int n1 = (int)str1.length(), n2 = (int)str2.length() ;

    if (n1 < n2)

        return true ;

    else if (n1 > n2)

        return false ;

    else
    {

        for (int i = 1; i <= n1; ++i)
        {

            if (str1[i] < str2[i])

                return true ;

            else if (str1[i] > str2[i])

                return false ;
        }

        return false ;

    }
}


//---------------------------------------------------------------

bool Check (string & Str){

    bool is_Valid = false ;

    regex format ("[+-\\-]?[0-9]+") ;

    if(regex_match(Str, format))

        is_Valid = true ;

    return is_Valid ;
}


//---------------------------------------------------------------

BigDecimalInt::BigDecimalInt()
{

    decStr = "0" ;

    decInt = 0 ;
}

//---------------------------------------------------------------

BigDecimalInt::BigDecimalInt(string Str, int N)
{

    if (Check(Str))
    {
        for (int i = 0; i < N; ++i)

            decStr += Str;

    }

    decInt = 0 ;
}

//---------------------------------------------------------------

BigDecimalInt::BigDecimalInt(int Num)
{

    decInt = Num ;

}

//---------------------------------------------------------------

int BigDecimalInt::Size()
{

    int Num_Digits = (int)this->decStr.length() ;

    if (this->decStr[0] == '+' || this->decStr[0] == '-')

        Num_Digits -- ;

    return Num_Digits ;
}

//---------------------------------------------------------------

char BigDecimalInt::Sign()
{

    char Sign = '+' ;

    if (this->decStr[0] == '+')

        Sign = '+' ;

    else if (this->decStr[0] == '-')

        Sign = '-' ;

    return Sign ;
}

//---------------------------------------------------------------

BigDecimalInt BigDecimalInt::operator + (BigDecimalInt & anotherDec)
{

    int Size_1 = (int) this->decStr.size() - 1, Size_2 = (int) anotherDec.decStr.size() - 1;

    bool Swap = false ;

    string Final_Result ;

    if (isSmaller(this->decStr, anotherDec.decStr))
    {
        swap(this->decStr, anotherDec.decStr) ;

        swap(Size_1, Size_2) ;

        Swap = true ;
    }

    reverse(this->decStr.begin(), this->decStr.end()) ;

    reverse(anotherDec.decStr.begin(), anotherDec.decStr.end()) ;

    int Carry = 0 ;

    for (int i = 0 ; i < Size_2; ++i)
    {

        int Result = (this->decStr[i] - '0') + (anotherDec.decStr[i] - '0') + Carry ;

        if (Result >= 10)
        {
            Result -= 10 ;

            Carry = 1 ;
        }
        else

            Carry = 0 ;

        Final_Result.push_back(Result + '0');
    }

    for (int i = Size_2; i < Size_1; ++i)
    {

        int Result = (this->decStr[i] - '0') + Carry ;

        if (Result >= 10)
        {
            Result -= 10;

            Carry = 1 ;
        }
        else

            Carry = 0 ;

        Final_Result.push_back(Result + '0') ;

    }

    if (Carry)

        Final_Result.push_back(Carry + '0') ;

    BigDecimalInt B3("0", (int) Final_Result.size() + 1);

    for (int j = 0; j < Final_Result.size(); ++j)

        B3.decStr[j] = Final_Result[j] ;

    if (Swap)

        swap(this->decStr, anotherDec.decStr) ;

    reverse(B3.decStr.begin(), B3.decStr.end()) ;

    reverse(this->decStr.begin(), this->decStr.end()) ;

    reverse(anotherDec.decStr.begin(), anotherDec.decStr.end()) ;

    return B3;
}

//---------------------------------------------------------------

ostream & operator << (ostream &out, BigDecimalInt &b) {

    out << "( " << b.decStr << " )" ;

    return out;
}


//---------------------------------------------------------------

istream &operator>>(istream &in, BigDecimalInt &b) {

    in >> b.decStr;

    return in;
}

//---------------------------------------------------------------

BigDecimalInt BigDecimalInt::operator - (BigDecimalInt &anotherDec)
{

    char Sign = '+';

    int Size_1 = (int) this->decStr.length() - 1, Size_2 = (int) anotherDec.decStr.length() - 1 ;

    bool Swap = false ;

    string Final_Result ;

    if (isSmaller(this->decStr, anotherDec.decStr))
    {
        swap(this->decStr, anotherDec.decStr) ;

        swap(Size_1, Size_2) ;

        Swap = true ;

        Sign = '-' ;
    }

    reverse(this->decStr.begin(), this->decStr.end()) ;

    reverse(anotherDec.decStr.begin(), anotherDec.decStr.end()) ;

    int Carry = 0 ;

    for (int i = 0; i < Size_2; ++i)
    {

        int Result = (this->decStr[i] - '0') - (anotherDec.decStr[i] - '0') - Carry ;

        if (Result < 0)
        {

            Result += 10 ;

            Carry = 1 ;
        }
        else

            Carry = 0;

        Final_Result.push_back(Result + '0');

    }

    for (int i = Size_2; i < Size_1; ++i)
    {

        int Result = (this->decStr[i] - '0') - Carry ;

        if (Result < 0)
        {

            Result += 10 ;

            Carry = 1 ;
        }
        else

            Carry = 0 ;

        Final_Result.push_back(Result + '0') ;
    }

    int Plus = 0 ;

    if (Sign == '-')

        Plus = 1 ;

    BigDecimalInt B3("0", ((int)Final_Result.size() + Plus));

    for (int j = 0; j < Final_Result.size(); ++j)

        B3.decStr[j] = Final_Result[j] ;

    if (Swap)

        swap(this->decStr, anotherDec.decStr) ;

    reverse(B3.decStr.begin(), B3.decStr.end()) ;

    reverse(this->decStr.begin(), this->decStr.end()) ;

    reverse(anotherDec.decStr.begin(), anotherDec.decStr.end()) ;

    if (Sign == '-')

        B3.decStr[0] = Sign ;

    return B3;
}

//---------------------------------------------------------------

bool BigDecimalInt::operator > (BigDecimalInt & anotherDec)
{
    bool Greater = true ;

    if (this->decStr[0] == '+' && anotherDec.decStr[0] == '-')

        return true ;

    else if (this->decStr[0] == '-' && anotherDec.decStr[0] == '+')

        return false ;

    if (this->decStr.size() == anotherDec.decStr.size())
    {

        for (int i = 1; i < this->decStr.size(); ++i)
        {

            if (this->decStr[i] > anotherDec.decStr[i])
            {

                Greater = true;

                break ;
            }
            else

                Greater = false ;

        }
    }

    else if (this->decStr.size() > anotherDec.decStr.size())

        Greater = true ;

    else

        Greater = false ;

    if (this->decStr[0] == '-' && anotherDec.decStr[0] == '-' && Greater)

        Greater = !Greater ;

    return Greater ;

}

//---------------------------------------------------------------

bool BigDecimalInt::operator < (BigDecimalInt & anotherDec)
{
    bool Smaller = false ;

    if (this->decStr[0] == '+' && anotherDec.decStr[0] == '-')

        return false ;

    else if (this->decStr[0] == '-' && anotherDec.decStr[0] == '+')

        return true ;

    if (this->decStr.size() == anotherDec.decStr.size())
    {

        for (int i = 1; i < this->decStr.size(); ++i)
        {

            if (this->decStr[i] < anotherDec.decStr[i])
            {

                Smaller = true;

                break ;
            }

            else

                Smaller = false ;

        }
    }

    else if (this->decStr.size() < anotherDec.decStr.size())

        Smaller = true ;

    else

        Smaller = false ;

    if (this->decStr[0] == '-' && anotherDec.decStr[0] == '-' && Smaller)

        Smaller = !Smaller ;

    return Smaller ;
}

//---------------------------------------------------------------

bool BigDecimalInt::operator == (BigDecimalInt & anotherDec)
{
    bool Equal = true ;

    if (this->decStr.size() == anotherDec.decStr.size())
    {

        for (int i = 1; i < this->decStr.size(); ++i)
        {

            if (this->decStr[i] == anotherDec.decStr[i])

                Equal = true ;

            else
            {

                Equal = false ;

                break ;
            }
        }
    }

    else

        Equal = false ;

    return Equal ;
}

//---------------------------------------------------------------

string Display(BigDecimalInt & B1, BigDecimalInt & B2) ;

//---------------------------------------------------------------

BigDecimalInt Check_Sign(string & Operator, BigDecimalInt & B1, BigDecimalInt & B2) ;

//---------------------------------------------------------------

BigDecimalInt Correct_Zeros (BigDecimalInt & B1) ;


//---------------------------------------------------------------

bool Is_True(string & c)
{

    if (c == "1" || c == "2")

        return true ;

    else

        return false ;
}


//---------------------------------------------------------------

string Display(BigDecimalInt & B1, BigDecimalInt & B2)
{

    string Operator ;

    cout << "\nPlease Enter the Numbers\nNumber_1\n-->" ;

    b1 :

    cin >> B1 ;

    if (!Check(B1.decStr))
    {

        cout << "Invalid Input :(\nTry again\n-->" ;

        goto b1;
    }

    cout << "\nNumber_2\n-->" ;

    b2 :

    cin >> B2 ;

    if (!Check(B2.decStr))
    {

        cout << "Invalid Input :(\nTry again\n-->" ;

        goto b2;
    }

    cout << "\n1 --> " << B1 << " + " << B2
         << "\n2 --> " << B1 << " - " << B2
         << "\n\nWhat Operator do you want ?\n-->" ;

    Input :

    cin.sync() ;

    getline(cin, Operator) ;

    if (!Is_True(Operator))
    {

        cout << "Invalid Input :(\nTry again\n-->" ;

        goto Input;
    }

    cout << endl ;

    if (Operator == "1")

        Operator = "+" ;

    else

        Operator = "-" ;

    return Operator ;
}


//---------------------------------------------------------------

BigDecimalInt Correct_Zeros (BigDecimalInt & B1)
{

    BigDecimalInt B3 ;

    int index = 0;

    bool Check = true ;

    for (int i = 0 ; i < (int)B1.decStr.length() ; ++i)
    {

        if (B1.decStr[i] == '0' || B1.decStr[i] == '-')

            Check = false ;

        else
        {

            Check = true ;

            index = i ;

            break ;
        }
    }

    if (!Check)

        B3.decStr = "0" ;

    else
    {

        B3.decStr = B1.decStr.substr(index, -1) ;

        if (B1.decStr[0] == '-')

            B3.decStr.insert(0, "-") ;

    }

    return B3 ;
}


//---------------------------------------------------------------

BigDecimalInt Check_Sign(string & Operator, BigDecimalInt & B1, BigDecimalInt & B2)
{

    if (B1.decStr[0] != '+' && B1.decStr[0] != '-')

        B1.decStr.insert(0, "+") ;

    if (B2.decStr[0] != '+' && B2.decStr[0] != '-')

        B2.decStr.insert(0, "+") ;

    BigDecimalInt B3 ;

    if ((B1.decStr[0] == '+' && B2.decStr[0] == '+' && Operator == "+")
        || (B1.decStr[0] == '+' && B2.decStr[0] == '-' && Operator == "-"))

        B3 = B1 + B2 ;

    else if ((B1.decStr[0] == '+' && B2.decStr[0] == '+' && Operator == "-")
             || (B1.decStr[0] == '+' && B2.decStr[0] == '-' && Operator == "+"))

        B3 = B1 - B2 ;

    else if ((B1.decStr[0] == '-' && B2.decStr[0] == '-' && Operator == "-")
             || (B1.decStr[0] == '-' && B2.decStr[0] == '+' && Operator == "+"))

        B3 = B2 - B1 ;

    else if ((B1.decStr[0] == '-' && B2.decStr[0] == '-' && Operator == "+")
             || (B1.decStr[0] == '-' && B2.decStr[0] == '+' && Operator == "-"))
    {

        B3 = (B1 + B2);

        B3.decStr[0] = '-' ;

    }

    B3 = Correct_Zeros(B3) ;

    return B3 ;
}