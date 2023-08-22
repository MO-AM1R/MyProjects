# include "CircularLinkedList.h"

int main() {
    CircularLinkedList<int> L1 ;

    L1.insertAtHead(1); // 1
    L1.insertAtHead(2) ; // 2 1
    L1.insertAtHead(3) ; // 3 2 1
    L1.insertAt(10, 1) ; // 3 10 2 1
    L1.insertAtHead(5) ; // 5 3 10 2 1
    L1.insertAtTail(9) ; // 5 3 10 2 1 9
    L1.insertAt(4, 1) ;  // 5 4 3 10 2 1 9
    L1.insertAtTail(3) ; // 5 4 3 10 2 1 9 3
    L1.insertAtTail(5) ; // 5 4 3 10 2 1 9 3 5
    L1.insertAtTail(5) ; // 5 4 3 10 2 1 9 3 5 5
    L1.insertAtTail(5) ; // 5 4 3 10 2 1 9 3 5 5 5
    L1.removeAt(0) ;// 4 3 10 2 1 9 3 5 5 5
    L1.removeAt(2) ; // 4 3 2 1 9 3 5 5 5
    L1.removeAt(1) ; // 4 2 1 9 3 5 5 5
    L1.removeAtTail() ;// 4 2 1 9 3 5 5
    L1.removeAtTail() ;// 4 2 1 9 3 5

    L1.print() ;
    return 0;
}
