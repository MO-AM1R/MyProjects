#ifndef ASSIGNMENT_3_OOP_EMVECTOR_H
#define ASSIGNMENT_3_OOP_EMVECTOR_H

# include <iostream>
# include <vector>
# include <iterator>
# include <exception>

using namespace std;

template<class T>

class EMVector {
private:
    int size, capacity;
    T* data;

public:
    typedef T* iterator;
//=================================
    explicit EMVector(int cap = 2) {
        capacity = cap;
        size = 0;
        data = new T[capacity];
    }

//=================================
    EMVector(T* array, int n){
        data = new T [n] ;
        size = n ;
        capacity = n ;

        for (int i = 0; i < size; ++i) {
            data[i] = array[i] ;
        }
    }

//=================================
    EMVector (const EMVector & src){
        size = src.size;
        capacity = src.size ;

        data = nullptr ;
        if (src.data != nullptr){
            data = new T{*(src.data)} ;
        }
    }
//=================================
    EMVector (EMVector && src){
        size = src.size;
        capacity = src.size ;
        data = nullptr ;
        for(int i = 0; i < src.size; i++){
            data[i] = src.data[i];
        }
        delete[] src.data ;
    }
//=================================
    EMVector& operator=(const EMVector &other) {
        if(this != &other){
            delete[] data;
            size = other.size;
            capacity = other.capacity;
            data = new T[capacity];
            for(int i = 0; i < other.size; i++){
                data[i] = other.data[i];
            }
        }
        else{
            cout << "Cannot delete self" << endl;
        }
        return *this ;
    }
//=================================
    EMVector &operator=(const EMVector&& other) noexcept {
        if (this != &other){
            delete[] other;
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }
//=================================
    T &operator[](int Index) {
        try {
            if (Index >= size) {
                throw out_of_range("out_of_range") ;
            }
            return data[Index];
        }
        catch (out_of_range & e){
            cerr << e.what() << " Exception was thrown\n" << endl;
            exit(-1) ;
        }
    }

//=================================
    EMVector &operator=(const T &other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            capacity = other.capacity;
            data = new T[capacity];
            for (int i = 0; i < other.size; i++) {
                data[i] = other.data[i];
            }
        }
        else {
            cout << "Cannot delete self" << endl;
        }
        return *this;
    }

//=================================
    void push_back(T item) {
        if (size < capacity) {
            data[size++] = item;
        }
        else {
            if (capacity == 0) {
                capacity = 2;
                goto Skip;
            }
            capacity *= 2;

            Skip :
            T *Temp = new T[capacity];

            for (int i = 0; i < size; i++) {
                Temp[i] = data[i];
            }
            delete[] data;
            data = Temp;
            data[size++] = item;
            Temp = nullptr;
            delete[] Temp;
        }
    }

//=================================
    void erase(iterator Itr) {
        try {
            if (Itr < end() && Itr >= begin()) {
                while (Itr != end() - 1) {
                    *Itr = *(Itr + 1);
                    Itr++;
                }
                size--;
            }
            else{
                throw invalid_argument("invalid_Iterator") ;
            }
        }
        catch (invalid_argument & E){
            cerr << E.what() << " Exception was thrown\n" << endl;
            exit(-1) ;
        }
    }
//=================================
    void pop_back(){
        try {
            if (size != 0) {
                erase(end() - 1) ;
            }
            else{
                throw out_of_range("Empty Vector") ;
            }
        }
        catch (out_of_range & E){
            cerr << E.what() << " Exception was thrown\n" << endl;
            exit(-1) ;
        }
    }
//=================================
    void erase(iterator Itr1, iterator Itr2) {
        try {
            if (Itr1 < Itr2) {
                while (Itr1 != Itr2) {
                    iterator Temp = Itr1;
                    erase(Temp);
                    Itr2--;
                }
            }
            else{
                throw invalid_argument("invalid_Iterators") ;
            }
        }
        catch (invalid_argument & E){
            cerr << E.what() << " Exception was thrown\n" << endl;
            exit(-1) ;
        }
    }

//=================================
    void insert(const iterator &itr, T d) {
        try {
            if (itr < end() && itr >= begin()) {
                this->push_back(0);
                iterator Temp = end() ;

                while (Temp != itr) {
                    *(Temp) = *(Temp - 1);
                    Temp--;
                }
                *itr = d;
            }
            else if ((itr - end()) == 0){
                this->push_back(d);
            }
            else{
                throw invalid_argument("invalid_Iterator") ;
            }
        }
        catch (invalid_argument & E){
            cerr << E.what() << " Exception was thrown\n" << endl;
            exit(-1) ;
        }
    }

//=================================
    void resize(int cap) {
        if (cap > capacity)
            capacity = cap;

        size = cap;

        T *Temp = new T[capacity];
        for (int i = 0; i < size; i++) {
            Temp[i] = data[i];
        }

        delete[] data;
        data = Temp;
    }

//=================================
    bool operator==(const EMVector<T> &other) {
        if (size != other.size) {
            return false;
        }
        else {
            for (int i = 0; i < size; ++i) {
                if (data[i] == other.data[i]) {
                    continue;
                } else {
                    return false;
                }
            }
        }
        return true;
    }

//=================================
    bool operator<(const EMVector<T> &other) {
        int min = size;
        if (other.size < min) {
            min = other.size;
        }

        for (int i = 0; i < min; ++i) {
            if (other.data[i] > data[i]) {
                return true;
            }
            else if (other.data[i] == data[i]) {
                continue;
            }
            else {
                return false;
            }
        }
        if (other.size > size) {
            return true;
        }
        return false;
    }

//=================================
    bool operator>(const EMVector<T> &other) {
        int min = size;
        if (other.size < min) {
            min = other.size;
        }
        for (int i = 0; i < min; ++i) {
            if (data[i] > other.data[i]) {
                return true;
            } else if (other.data[i] == data[i]) {
                continue;
            } else {
                return false;
            }
        }
        if (size > other.size) {
            return true;
        }
        return false;
    }

//=================================
    int Size() {
        return size;
    }

//=================================
    int Capacity() {
        return capacity;
    }

//=================================
    void clear() {
        size = 0;
        capacity = 0;
    }

//=================================
    iterator begin() {
        return data;
    }

//=================================
    iterator end() {
        return data + size;
    }

//=================================
    bool empty() {
        if (size == 0) {
            return true;
        }

        return false;
    }

//=================================
    friend ostream &operator<<(ostream &out, const EMVector<T> &E) {
        out << "[" ;
        for (int i = 0; i < E.size; ++i) {
            if (i != E.size - 1) {
                out << E.data[i] << ", ";
            }
            else{
                out << E.data[i] ;
            }
        }
        out << "]" ;
        return out;
    }

//=================================
    ~EMVector() {
        if (!this->empty()) {
            delete[] data;
        }
    }
};

#endif //ASSIGNMENT_3_OOP_EMVECTOR_H