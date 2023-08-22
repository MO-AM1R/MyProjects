# ifndef MAIN_CPP_BIGDECIMALINT_H
# define MAIN_CPP_BIGDECIMALINT_H

# include <iostream>
# include <regex>
# include <vector>
# include <iomanip>

using namespace std ;

bool isSmaller(string str1, string str2) ;

//---------------------------------------------------------------

bool Check (string & Str) ;

//---------------------------------------------------------------

class BigDecimalInt {

private :

    string decStr ;

    int decInt ;

public :

    BigDecimalInt() ;

    //---------------------------------------------------------------

    explicit BigDecimalInt(int Num) ;

    //---------------------------------------------------------------

    BigDecimalInt(string Str, int N = 0) ;

    //---------------------------------------------------------------

    int Size() ;

    //---------------------------------------------------------------

    char Sign() ;

    //---------------------------------------------------------------

    BigDecimalInt operator + (BigDecimalInt & anotherDec) ;

    //---------------------------------------------------------------

    friend ostream &operator<<(ostream &out, BigDecimalInt &b) ;

    //---------------------------------------------------------------

    friend istream &operator>>(istream &in, BigDecimalInt &b) ;

    //---------------------------------------------------------------

    BigDecimalInt operator - (BigDecimalInt &anotherDec) ;

    //---------------------------------------------------------------

    bool operator > (BigDecimalInt & anotherDec) ;

    //---------------------------------------------------------------

    bool operator < (BigDecimalInt & anotherDec) ;

    //---------------------------------------------------------------

    bool operator == (BigDecimalInt & anotherDec) ;

    //---------------------------------------------------------------

    friend string Display(BigDecimalInt & B1, BigDecimalInt & B2) ;

    //---------------------------------------------------------------

    friend BigDecimalInt Check_Sign(string & Operator, BigDecimalInt & B1, BigDecimalInt & B2) ;

    //---------------------------------------------------------------

    friend BigDecimalInt Correct_Zeros (BigDecimalInt & B1) ;

};

bool Is_True(string & c) ;

//---------------------------------------------------------------

string Display(BigDecimalInt & B1, BigDecimalInt & B2) ;

//---------------------------------------------------------------

BigDecimalInt Correct_Zeros (BigDecimalInt & B1) ;

//---------------------------------------------------------------

BigDecimalInt Check_Sign(string & Operator, BigDecimalInt & B1, BigDecimalInt & B2) ;

# endif //MAIN_CPP_BIGDECIMALINT_H
