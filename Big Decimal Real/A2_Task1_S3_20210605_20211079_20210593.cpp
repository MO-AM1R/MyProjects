# include "BigReal.h"

int main() {
    string num = "-0.574", num_2 = ".356" ;

    //----------------------------- General Tests -----------------------------
    cout << left << setw(10) << setfill('-') << '-' << " General Tests " << setw(10) << setfill('-') << '-' << endl ;
    BigReal b1(num), b2("-12.57491"), b3(b2), b4(BigDecimalInt("1000")), b5(+5000) ;
    cout  << "Number 1 -> " << b1 << "\nNumber 2 -> " << b2 << "\nNumber 3 -> " << b3
    << "\nNumber 4 -> " << b4 << "\nNumber 5 -> " << b5 << endl ;
    //----------------------------- Plus Tests -----------------------------
    b3.Set_Number(num_2) ;
    cout << left << setw(10) << setfill('-') << '-' << " Plus Tests " << setw(10) << setfill('-') << '-' << endl ;
    cout << b1 << " (+) " << b2 << " --> " << b1 + b2 << endl ;
    cout << b3 << " (+) " << b4 << " --> " << b3 + b4 << endl ;
    cout << b3 << " (+) " << b4 << " (+) " << b1 << " --> " << b3 + b4 + b1 << endl ;
    //----------------------------- Minus Tests -----------------------------
    cout << left << setw(10) << setfill('-') << '-' << " Minus Tests " << setw(10) << setfill('-') << '-' << endl ;
    cout << b1 << " (-) " << b2 << " --> " << b1 - b2 << endl ;
    cout << b3 << " (-) " << b4 << " --> " << b3 - b4 << endl ;
    cout << b3 << " (-) " << b4 << " (-) " << b1 << " --> " << b3 - b4 - b1 << endl ;
    //----------------------------- Mixed Tests -----------------------------
    cout << left << setw(10) << setfill('-') << '-' << " Mixed Tests " << setw(10) << setfill('-') << '-' << endl ;
    cout << b1 << " (-) " << b2 << " (+) " << b3 << " --> " << b1 - b2 + b3 << endl ;
    cout << b3 << " (-) " << b4 << " (+) " << b1 << " --> " << b3 - b4 + b1 << endl ;
    cout << b3 << " (+) " << b4 << " (+) " << b1 << " (-) " << b2 << " --> " << b3 + b4 + b1 - b2 << endl ;
    //----------------------------- Greater Test -----------------------------
    cout << left << setw(10) << setfill('-') << '-' << " Greater Tests " << setw(10) << setfill('-') << '-' << endl ;
    if (b1 > b2)
    {
        cout << b1 << " is greater than " << b2 << endl ;
    }
    else
    {
        cout << b1 << " isn't greater than " << b2 << endl ;
    }
    if (b3 > b4)
    {
        cout << b3 << " is greater than " << b4 << endl ;
    }
    else
    {
        cout << b3 << " isn't greater than " << b4 << endl ;
    }
    //----------------------------- Smaller Test -----------------------------
    cout << left << setw(10) << setfill('-') << '-' << " Smaller Tests " << setw(10) << setfill('-') << '-' << endl ;
    if (b3 < b4)
    {
        cout << b3 << " is smaller than " << b4 << endl ;
    }
    else
    {
        cout << b3 << " isn't smaller than " << b4 << endl ;
    }
    if (b1 < b3)
    {
        cout << b1 << " is smaller than " << b3 << endl ;
    }
    else
    {
        cout << b1 << " isn't smaller than " << b3 << endl ;
    }
    //----------------------------- Equality Test -----------------------------
    cout << left << setw(10) << setfill('-') << '-' << " Equality Tests " << setw(10) << setfill('-') << '-' << endl ;
    b1 = b3 ;
    if (b1 == b3)
    {
        cout << b1 << " is equal to " << b3 << endl ;
    }
    else
    {
        cout << b1 << " isn't equal to " << b3 << endl ;
    }
    if (b4 == b2)
    {
        cout << b4 << " is equal than " << b2 << endl ;
    }
    else
    {
        cout << b4.Get_Number() << " isn't equal than " << b2 << endl ;
    }
    //----------------------------- Input Test -----------------------------
    cout << "If you want to Test the Code please Press (Y) if not Press (N)\n-->" ;
    if (cin.get() != 'Y') {
        cout << left << setw(5) << setfill('-') << '-' << " Thanks for using the program " << char(1)
        << ' ' << setw(5) << setfill('-') << '-' << endl ;
        exit(0);
    }

    cout << "\nEnter First Number\n-->" ;
    cin >> b1 ;
    cout << "\nEnter Second Number\n-->" ;
    cin >> b2 ;

    cout << "1 -> " << b1 << " (+) " << b2 << "\n2 -> " << b1 << " (-) " << b2 << endl ;
    char Operator ;
    cin >> Operator ;
    BigReal Result ;

    if (Operator == '1')
    {
        Result = b1 + b2 ;
        cout << "The Result --> " << Result << "\nThe Size --> " << Result.Size() << endl ;
        if (Result.sign())
            cout << "The Sign --> (+)" << endl ;
        else
            cout << "The Sign --> (-)" << endl ;
    }
    else if (Operator == '2')
    {
        Result = b1 - b2 ;
        cout << "The Result --> " << Result << "\nThe Size --> " << Result.Size() << endl ;
        if (Result.sign())
            cout << "The Sign --> (+)" << endl ;
        else
            cout << "The Sign --> (-)" << endl ;
    }

    if (b1 > b2)
    {
        cout << b1 << " is greater than " << b2 << endl ;
    }
    else if (b1 < b2)
    {
        cout << b1 << " is Smaller than " << b2 << endl ;
    }
    else
    {
        cout << b1 << " is Equal to " << b2 << endl ;
    }

    cout << left << setw(5) << setfill('-') << '-' << " Thanks for using the program " << char(1) << ' '
    << setw(5) << setfill('-') << '-' << endl ;

    return 0;
}