# include "ArrayListType.h"

int main() {
    Array<int> Arr1(10);
    cout << "Is Empty -> " << Arr1.isEmpty() << endl ;

    Arr1.insert(1);
    Arr1.insert(10);
    Arr1.insertAt(2, 100);

    cout << "After insertion 1, 10 and 100 at index 2 -> " ;
    Arr1.Print() ;

    cout << "List Size -> " << Arr1.ListSize()  << endl ;
    cout << "MaxListSize -> " << Arr1.MaxListSize()  << endl ;

    int Ele = Arr1.retrieveAt(2) ;
    cout << "The element at index 3 -> " << Ele << endl ;

    Arr1.removeAt(1) ;
    cout << "After removing at index 1 -> " ;
    Arr1.Print() ;

    cout << "If item at index 0 at equal 5 -> " << Arr1.isItemEqual(0, 5) << endl ;

    Arr1.replaceAt(0, 50) ;
    cout << "After replacing element index 0 by 50 -> " ;
    Arr1.Print() ;

    Arr1.clear() ;
    cout << "After Clearing -> " ;
    Arr1.Print() ;

    return 0;
}