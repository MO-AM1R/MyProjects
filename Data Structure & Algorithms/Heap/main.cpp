# include "MaxHeap.h"
# include "MinHeap.h"

int main() {
    cout << "--------Max Heap--------\n" ;
    {
        MaxHeap heap;

        heap.insert(60);
        heap.insert(20);
        heap.insert(40);
        heap.insert(70);
        heap.insert(30);
        heap.insert(10);

        heap.print();

        heap.heapSort();
        heap.print();
    }
    cout << "--------Min Heap--------\n" ;
    {
        MinHeap heap;

        heap.insert(60);
        heap.insert(20);
        heap.insert(40);
        heap.insert(70);
        heap.insert(30);
        heap.insert(10);

        heap.print();

        heap.heapSort();
        heap.print();
    }

    return 0;
}
