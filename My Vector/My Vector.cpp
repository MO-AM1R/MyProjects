# include "EMVector.h"

using namespace std;

int main() {
    EMVector<int> vec1;
    for (int i = 0; i < 4; ++i) {
        vec1.push_back(i);
    }
    cout << "int vector:" << vec1;

    EMVector<char> vec2;
    vec2.push_back('a');
    vec2.push_back('b');
    vec2.push_back('c');
    vec2.push_back('d');
    cout << "\nchar vector:" << vec2;

    EMVector<string> vec3;
    vec3.push_back("sunday");
    vec3.push_back("Monday");
    vec3.push_back("Tuesday");
    vec3.push_back("Wednesday");
    vec3.push_back("Thursday");
    cout << "\nstring vector:" << vec3;

    cout << "\n------------------< pop >-----------------------------\n";
    vec1.pop_back();
    cout << "int vector after pop:" << vec1 << " the size = " << vec1.Size() << " the capacity = " << vec1.Capacity();
    vec2.pop_back();
    cout << "\nchar vector after pop:" << vec2 << " the size = " << vec2.Size() << " the capacity = "
         << vec2.Capacity();
    vec3.pop_back();
    cout << "\nstring vector after pop:" << vec3 << " the size = " << vec3.Size() << " the capacity = "
         << vec3.Capacity();

    cout << "\n------------------< erase and insert >----------------------------";
    vec1.erase(vec1.begin());
    cout << "\nint vector after erase first element:" << vec1;
    vec1.insert(vec1.begin(), 100);
    cout << "\nint vector after insert 100:" << vec1;
    vec1.erase(vec1.begin(), vec1.begin() + 2);
    cout << "\nint vector after erase the first two elements:" << vec1;

    cout << "\n--------------------< comparison >-------------------------\n";
    EMVector<int> vec1_compare;
    EMVector<int> vec2_compare;
    vec1.pop_back();

    vec1_compare.push_back(1);
    vec1_compare.push_back(2);
    vec1_compare.push_back(3);
    vec1_compare.push_back(4);
    vec1_compare.push_back(5);
    vec2_compare.push_back(1);
    vec2_compare.push_back(2);
    vec2_compare.push_back(3);
    vec2_compare.push_back(4);
    vec2_compare.push_back(5);

    cout << vec1_compare << "\n" << vec2_compare;
    if (vec1_compare == vec2_compare)
        cout << "\ntwo vectors are equal\n";
    vec1_compare.push_back(6);
    cout << vec1_compare << "\n" << vec2_compare;

    if (vec1_compare > vec2_compare)
        cout << "\nvec1 bigger";
    else if (vec1_compare < vec2_compare)
        cout << "\nvec2 smaller";
    else
        cout << "\nare equal";

    cout << "\n-----------------< clear and empty >------------------------\n";
    vec1.clear();
    cout << "clear int vector and check if empty\n";
    if (vec1.empty())
        cout << "yes empty\n";

    cout << "\n-------------------< resize >---------------------\n";
    cout << "before resizing : " << vec1_compare << " the size = " << vec1_compare.Size() << " the capacity = "
         << vec1_compare.Capacity() << endl;
    vec1_compare.resize(3);
    cout << "after resizing to 3 : " << vec1_compare << " the size = " << vec1_compare.Size() << " the capacity = "
         << vec1_compare.Capacity() << endl ;
    cout << "\n-------------------< Constructors >---------------------\n";

    string* array ;
    array = new string [5] ;

    for (int i = 0; i < 5; ++i) {
        array[i] = to_string(i) ;
    }

    EMVector<string> ve(array, 5) ;
    cout << ve << endl ;

    EMVector<string> ve_2 ;
    ve_2.push_back("A") ;
    ve_2.push_back("B") ;
    ve_2.push_back("C") ;
    ve_2.push_back("D") ;

    ve = ve_2 ;
    cout << ve << endl ;
    
    cout << "\n-------------------< Exception >---------------------\n";
    cout << vec1_compare[500] ;
}