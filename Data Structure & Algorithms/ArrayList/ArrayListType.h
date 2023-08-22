#ifndef DATASTRUCTURE_Array_H
#define DATASTRUCTURE_Array_H

# include <iostream>
# include <vector>
#include <cassert>
using namespace std ;


template <class elemType>
class Array {
private:
    elemType* List ;
    int Length{}, MaxSize{} ;

public:
    Array() = default ;

    explicit Array(int S = 100){
        List = new elemType[S] ;
        assert(List != NULL) ;

        Length = 0 ;
        MaxSize = S ;
    }

    [[nodiscard]] bool isEmpty() const{
        return !Length ;
    }

    [[nodiscard]] bool isFull() const{
        return Length == MaxSize ;
    }

    [[nodiscard]] int ListSize() const{
        return Length ;
    }

    [[nodiscard]] int MaxListSize() const{
        return MaxSize ;
    }

    void insertAt(const int Pos, const elemType & ELe) {
        if (isFull()){
            cerr << "The List is Full :(" << endl ;
        }
        else if(Pos < 0 || Pos >= MaxSize){
            cerr << "Invalid Index :(\n" ;
        }
        else {
            for (int i = Length - 1; i > Pos; --i) {
                List[i] = List[i - 1];
            }
            List[Pos] = ELe;
            Length++;
        }
    }

    void insert(const elemType & ELe) {
        if (isFull()){
            cerr << "The List is Full :(" << endl ;
            return ;
        }
        List[Length++] = ELe;
    }

    elemType retrieveAt(const int Pos){
        if(Pos < 0 || Pos >= Length){
            cerr << "Invalid Index :(\n" ;
            return INT32_MAX * -1 ;
        }
        return List[Pos] ;
    }

    void removeAt(const int Pos){
        if (isEmpty()){
            cerr << "The List is Empty :(\n" ;
        }
        else if (Pos < 0 || Pos >= Length){
            cerr << "Invalid Index :(\n" ;
        }
        else {
            List[Pos] = 0;
            for (int i = Pos; i < Length; ++i) {
                List[i] = List[i + 1];
            }
            --Length;
        }
    }

    bool isItemEqual(const int Pos, const elemType & ELe) const{
        if (Pos < 0 || Pos >= Length){
            cerr << "Invalid Index :(\n" ;
            return false ;
        }
        return (List[Pos] == ELe) ;
    }

    void replaceAt(const int Pos, const elemType & ELe) const{
        if (Pos < 0 || Pos >= Length){
            cerr << "Invalid Index :(\n" ;
            return ;
        }
        List[Pos] = ELe ;
    }

    void clear(){
        delete[] List ;
        Length = 0 ;
        MaxSize = 0;
    }

    void Print() const{
        cout << "[" ;
        for (int i = 0; i < Length; ++i) {
            if (i == Length - 1){
                cout << List[i] ;
                break ;
            }
            cout << List[i] << ", " ;
        }
        cout << "]\n" ;
    }

    ~Array(){
        if (!isEmpty()) {
            delete[] List;
            Length = 0;
            MaxSize = 0;
        }
    }
};

#endif //DATASTRUCTURE_Array_H