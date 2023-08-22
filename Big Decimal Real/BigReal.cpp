# include "BigReal.h"

bool BigReal::Check(string & Text)
{
    regex Format ("[+-\\-]?([0-9]+[0-9]*)?(\\.)[0-9]*") ;

    return regex_match(Text, Format)  ;
}
//--------------------------------------------------
BigReal::BigReal() {
    Number = "" ;
    small_Number  = 0 ;
}
//--------------------------------------------------
BigReal::BigReal(double realNumber) {
    small_Number = realNumber ;
    Number = to_string(realNumber) ;

    if (Number[0] != '+' && Number[0] != '-')
        Number.insert(0, "+") ;

    Sign = Number[0] ;

}
//--------------------------------------------------
BigReal::BigReal(string realNumber) {
    if (!Check(realNumber))
    {
        cout << "Invalid real Number:(\n" ;
        return ;
    }
    Number = std::move(realNumber) ;

    if (Number[0]  != '+' && Number[0]  != '-')
        Number.insert(0, "+") ;

    Sign = Number[0] ;
    small_Number  = 0 ;
}
//--------------------------------------------------
string BigReal::Get_Number() {
    return Number;
}
//--------------------------------------------------
void BigReal::Set_Number(string & Number_) {
    if (Number_[0]  != '+' && Number_[0]  != '-')
        Number_.insert(0, "+") ;

    Number = Number_ ;
    Sign = Number[0] ;
}
//--------------------------------------------------
int BigReal::Size()
{
    return (int)Number.size() - 1 ;
}
//--------------------------------------------------
int BigReal::sign()
{
    if (Number[0] == '+')
        return 1 ;

    return 0 ;
}
//--------------------------------------------------
BigReal::BigReal(BigDecimalInt bigInteger) {
    Number = bigInteger.getNumber() ;
    small_Number = 0 ;

    if (bigInteger.sign())
        Number.insert(0, "+") ;
    else
        Number.insert(0, "-") ;

    Number += ".0" ;

}
//--------------------------------------------------
BigReal::BigReal(const BigReal &other) {
    this->Number = other.Number  ;
    this->Sign = other.Sign ;
    this->small_Number = other.small_Number ;

}
//--------------------------------------------------
BigReal::BigReal(BigReal &&other) noexcept {
    if (!Check(other.Number))
    {
        cout << "Invalid real Number:(\n" ;
        return ;
    }

    Number = other.Number ;
    Sign = other.Sign ;
    small_Number = other.small_Number ;

    other.Number[0] = '\0' ;
    other.Sign = '\0' ;
    other.small_Number = 0 ;
}
//--------------------------------------------------
BigReal &BigReal::operator=(BigReal &&other) noexcept {
    this->Number = other.Number  ;
    this->Sign = other.Sign ;
    this->small_Number = other.small_Number ;

    other.Number[0] = '\0' ;
    other.Sign = '\0' ;
    other.small_Number = 0 ;

    return *this ;
}
//--------------------------------------------------
void BigReal::Correct_Number(string & RealNumber, string & other) {
    int Size_1 = (int)RealNumber.size() - (int)RealNumber.find('.') ;
    int Size_2 =  (int)other.size() - (int)other.find('.') ;

    while (Size_1 < Size_2){
        RealNumber += '0';
        Size_1++;
    }
    while (Size_1 > Size_2){
        other += '0';
        Size_2++;
    }
}
//--------------------------------------------------
string Remove_Point(string Number)
{
    Number.erase(remove(Number.begin(), Number.end(), '.'), Number.end()) ;
    return Number ;
}
//--------------------------------------------------
BigReal BigReal::operator+(const BigReal &other) {
    string Number_1 = Number, Number_2 = other.Number;
    Correct_Number(Number_2, Number_1) ;

    int Index_1 = (int)Number.find('.') ;
    int Index_2 = (int)other.Number.find('.') ;

    Number_1 = Remove_Point(Number_1) ;
    Number_2 = Remove_Point(Number_2) ;

    BigDecimalInt  B1(Number_1), B2(Number_2) ;
    B1 = B1 + B2 ;

    Number = B1.getNumber() ;
    if (B1.sign())
        Number.insert(0, "+");

    else
        Number.insert(0, "-") ;

    Number_1 = Number[0] + Number_1.substr(Index_1, -1) ;
    Number_2 = other.Number[0] + Number_2.substr(Index_2, -1) ;

    B1.setNumber(Number_1) ;
    B2.setNumber(Number_2) ;
    B1 = B1 + B2 ;

    int Point_Index = (int)Number.size() - B1.size();

    if (B1.size() > Number_1.size() - 1 && B1.size() > Number_2.size() - 1)
        Point_Index = (int)Number.size() - B1.size() + 1;

    Number.insert(Point_Index, ".") ;

    if (Number[2] == '.')
        Number.insert(1, "0") ;

    return *this  ;
}
//--------------------------------------------------
BigReal BigReal::operator-(const BigReal &other) {
    string Number_1 = Number, Number_2 = other.Number;
    Correct_Number(Number_2, Number_1) ;

    int Index_1 = (int)Number.find('.') ;
    int Index_2 = (int)other.Number.find('.') ;

    Number_1 = Remove_Point(Number_1) ;
    Number_2 = Remove_Point(Number_2) ;

    BigDecimalInt  B1(Number_1), B2(Number_2) ;
    B1 = B1 - B2 ;

    Number = B1.getNumber() ;
    if (B1.sign())
        Number.insert(0, "+");

    else
        Number.insert(0, "-") ;

    Number_1 = Number[0] + Number_1.substr(Index_1, -1) ;
    Number_2 = other.Number[0] + Number_2.substr(Index_2, -1) ;

    B1.setNumber(Number_1) ;
    B2.setNumber(Number_2) ;
    B1 = B1 - B2 ;

    int Point_Index = (int)Number.size() - B1.size();

    if (B1.size() > Number_1.size() - 1 && B1.size() > Number_2.size() - 1)
        Point_Index = (int)Number.size() - B1.size() + 1;

    Number.insert(Point_Index, ".") ;

    if (Number[2] == '.')
        Number.insert(1, "0") ;

    return *this  ;
}
//--------------------------------------------------
BigReal &BigReal::operator=(const BigReal &other) = default;
//--------------------------------------------------
ostream &operator << (ostream &out, const BigReal & num)
{
    out << num.Number ;
    return out;
}
//--------------------------------------------------
istream &operator>>(istream &in, BigReal &num) {
    in >> num.Number ;
    return in  ;
}
//--------------------------------------------------
bool BigReal::operator>(const BigReal & other) {
    string Number_1 = Number, Number_2 = other.Number;

    Correct_Number(Number_1, Number_2) ;
    Number_1 = Remove_Point(Number_1) ;
    Number_2 = Remove_Point(Number_2) ;

    if (BigDecimalInt(Number_1) > BigDecimalInt(Number_2))
        return true ;

    return false ;
}
//--------------------------------------------------
bool BigReal::operator<(const BigReal & other) {
    string Number_1 = Number, Number_2 = other.Number;

    Correct_Number(Number_1, Number_2) ;
    Number_1 = Remove_Point(Number_1) ;
    Number_2 = Remove_Point(Number_2) ;

    if (BigDecimalInt(Number_1) < BigDecimalInt(Number_2))
        return true ;

    return false ;
}
//--------------------------------------------------
bool BigReal::operator==(const BigReal & other) {
    string Number_1 = Number, Number_2 = other.Number;

    Correct_Number(Number_1, Number_2) ;
    Number_1 = Remove_Point(Number_1) ;
    Number_2 = Remove_Point(Number_2) ;

    if (BigDecimalInt(Number_1) == BigDecimalInt(Number_2))
        return true ;

    return false ;
}