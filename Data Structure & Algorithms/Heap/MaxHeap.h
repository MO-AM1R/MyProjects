# ifndef HEAP_MAXHEAP_H
# define HEAP_MAXHEAP_H
# include <vector>
# include <iostream>
using namespace std ;

class MaxHeap {
    vector<int> data ;

public:
    [[nodiscard]] int Size() const {return (int)data.size();};

    [[nodiscard]] bool empty() const {return (int)data.size() == 0;};

    void heapify(int index, int n){
        int left = 2 * index + 1 ;
        int right = 2 * index + 2 ;
        int max = index;

        if (left < n && data[left] > data[max]){
            max = left ;
        }
        if (right < n && data[right] > data[max]){
            max = right ;
        }

        if (max != index){
            swap(data[index], data[max]) ;
            heapify(max, n);
        }
    }

    void insert(int ele){
        data.push_back(ele) ;
        int n = (int)data.size() ;

        if (!n){
            return ;
        }
        else{
            for (int i = n / 2 - 1; i >= 0 ; --i) {
                heapify(i, n) ;
            }
        }
    }

    void heapSort(){
        for (int i = (int)data.size() - 1; i >= 0 ; --i) {
            swap(data[i], data[0]) ;
            heapify(0, i) ;
        }
    }

    void print() const{
        cout << '[' ;

        for (int i = 0; i < data.size(); ++i) {
            if (i == data.size() - 1){
                cout << data.at(i) << "]\n" ;
                return ;
            }
            cout << data.at(i) << ", " ;
        }
    }
};

# endif //HEAP_MAXHEAP_H
