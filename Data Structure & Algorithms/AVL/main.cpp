/*


void merge(string & arr, int first, int middle, int last){
    int n1 = middle - first + 1;
    int n2 = last - middle;
    string arr1 ;
    string arr2 ;

    for (int i = 0; i < n1; ++i) {
        arr1[i] = arr[first + i] ;
    }
    for (int i = 0; i < n2; ++i) {
        arr2[i] = arr[i + middle + 1] ;
    }
    int i = 0, j = 0, k = first ;

    while ((i < n1) && (j < n2)){
        if (arr1[i] < arr2[j]){
            arr[k++] = arr1[i++] ;
        }
        else{
            arr[k++] = arr2[j++] ;
        }
    }

    while (i < n1){
        arr[k++] = arr1[i++] ;
    }

    while (j < n2){
        arr[k++] = arr2[j++] ;
    }

}

void mergeSort(string & arr, int first, int last){
    if (first >= last){
        return;
    }
    else{
        int middle = (first + last) / 2 ;
        mergeSort(arr, first, middle) ;
        mergeSort(arr, middle + 1, last) ;
        merge(arr, first, middle, last) ;
    }
}

void insertionSort(string & arr) {
    char k;
    int j;
    for (int i = 1; i < arr.size(); ++i) {
        k = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > k) {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = k;

    }
}

void selectionSort(string & arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int Min_index = i;
        int j;

        for (j = i + 1; j < n; ++j) {
            if (arr[j] < arr[Min_index]) {
                Min_index = j;
            }
        }
        swap(arr[i], arr[Min_index]);
    }
}
*/


# include <iostream>
# include <stack>
using namespace std ;

bool isOpen(const char & bracket){
    return bracket == '(' || bracket == '{' || bracket == '[' ;
}

bool isMatched(const char & bracket, const char & top){
    return bracket == ')' && top == '('
    || bracket == '}' && top == '{'
    || bracket == ']' && top == '[' ;
}

int main() {
    int turn ;
    cin >> turn ;

    while (turn--){
        stack<char> stack1 ;

        string brackets ;
        cin >> brackets ;

        for (char bracket : brackets) {
            if(isOpen(bracket)){
                stack1.push(bracket) ;
            }
            else{
                if(!stack1.empty()){
                    if(isMatched(bracket, stack1.top())){
                        stack1.pop() ;
                    }
                }
                else{
                    stack1.push('d') ;
                }
            }
        }

        if(stack1.empty()){
            cout << "YES\n" ;
        }
        else{
            cout << "NO\n" ;
        }
    }
}
/*
 *  9 1 0 -1 5 2 6 10 11
 *  1 0 -1 9 5 2 6 11
 *
 */

//    AVL<int> avl{} ;
//
//    avl.insert(9) ;
//    avl.insert(5) ;
//    avl.insert(10) ;
//    avl.insert(0) ;
//    avl.insert(6) ;
//    avl.insert(11) ;
//    avl.insert(-1) ;
//    avl.insert(1) ;
//    avl.insert(2) ;
//
//    avl.preOrder() ;
//    cout << '\n' ;
//
//    avl.remove(10) ;
//
//    avl.preOrder() ;
//    cout << '\n' ;

