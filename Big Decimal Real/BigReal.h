# ifndef MAIN_CPP_BIGREAL_H
# define MAIN_CPP_BIGREAL_H

# include "BigDecimalIntClass.h"

class BigReal {
private:
    string Number ;
    double small_Number ;
    char Sign{} ;
    void Correct_Number(string & Number, string & other) ;
    static bool Check(string & Text) ;

public:
    BigReal() ;
    explicit BigReal(double realNumber) ;
    explicit BigReal(string realNumber)  ;
    explicit BigReal (BigDecimalInt bigInteger) ;
    BigReal (const BigReal& other) ;
    BigReal (BigReal&& other) noexcept ;
    string Get_Number() ;
    void Set_Number(string & Number_) ;
    BigReal& operator = (const BigReal& other) ;
    BigReal& operator = (BigReal&& other) noexcept ;
    BigReal operator + (const BigReal& other);
    BigReal operator - (const BigReal& other);
    friend ostream &operator << (ostream &out,const BigReal& num) ;
    friend istream &operator >> (istream &in, BigReal& num) ;
    bool operator < (const BigReal & other) ;
    bool operator > (const BigReal & other) ;
    bool operator == (const BigReal & other) ;
    int Size() ;
    int sign() ;
};

# endif //MAIN_CPP_BIGREAL_H