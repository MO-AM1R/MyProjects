# include "BigDecimalInt.h"

int main()
{

    cout << endl << setw(50) << setfill('=') << " Welcome to large Numbers Calculator " << char(1) << ' '
         << setw(13) << setfill('=') << '=' << endl << endl ;

    string Exit ;

    while (Exit != "E")
    {
        BigDecimalInt B1("-500"), B2("-500"), B3, B4(500), B5("1", 5);

        string Operator = Display(B1, B2);

        B3 = Check_Sign(Operator, B1, B2);

        cout << B1 << ' ' << Operator << ' ' << B2 << " = " << B3
             << "\nThe Size --> " << B3.Size() << " and The Sign --> " << B3.Sign() << "\n\n";

        if (B1 > B2)

            cout << B1 << " is Greater than " << B2 << endl;

        else if (B1 < B2)

            cout << B1 << " is Smaller than " << B2 << endl;

        else if (B1 == B2)

            cout << B1 << " is Equal to " << B2 << endl;

        cout << "\nIf you want to Exit press E, If Not press anything else\n-->" ;

        cin.sync() ;

        getline(cin, Exit) ;

    }
    cout << endl << setw(43) << setfill('=') << " Thanks for Using the Program " << char(1) << ' '
         << setw(13) << setfill('=') << '=' << endl << endl ;

    return 0 ;
}