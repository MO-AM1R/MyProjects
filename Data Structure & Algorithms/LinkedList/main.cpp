# include "LinkedList.h"

int main() {
//    {
//        LinkedList<int> L1;
//
//        L1.insertAtHead(1); // 1
//        L1.insertAtHead(2); // 2 1
//        L1.insertAtHead(3); // 3 2 1
//        L1.insertAt(10, 1); // 3 10 2 1
//        L1.insertAtHead(5); // 5 3 10 2 1
//        L1.insertAtTail(9); // 5 3 10 2 1 9
//        L1.insertAt(4, 1);  // 5 4 3 10 2 1 9
//        L1.insertAtTail(3); // 5 4 3 10 2 1 9 3
//        L1.insertAtTail(5); // 5 4 3 10 2 1 9 3 5
//        L1.insertAtTail(5); // 5 4 3 10 2 1 9 3 5 5
//        L1.insertAtTail(5); // 5 4 3 10 2 1 9 3 5 5 5
//        L1.removeAt(0);// 4 3 10 2 1 9 3 5 5 5
//        L1.removeAt(2); // 4 3 2 1 9 3 5 5 5
//        L1.removeAt(1); // 4 2 1 9 3 5 5 5
//        L1.removeAtTail();// 4 2 1 9 3 5 5
//        L1.removeAtTail();// 4 2 1 9 3 5
//
//        L1.print();
//        L1.swap(0, 5);
//        L1.print();
//    }
//    {
//        //0 3 1 0 4 5 2 0
//        LinkedList<int> L1, L2, L3;
//        L1.insertAtTail(0) ;
//        L1.insertAtTail(3) ;
//        L1.insertAtTail(1) ;
//        L1.insertAtTail(0) ;
//        L1.insertAtTail(4) ;
//        L1.insertAtTail(5) ;
//        L1.insertAtTail(2) ;
//        L1.insertAtTail(0) ;
//        combineNodesBetweenZeros(L1) ;
//        L1.print() ;
//    }
//    {
//        //  [1, 4, 5], [1, 3, 4], [2, 6]
//        LinkedList<int> L1, L2, L3;
//        L1.insertAtTail(1) ;
//        L1.insertAtTail(4) ;
//        L1.insertAtTail(5) ;
//
//        L2.insertAtTail(1) ;
//        L2.insertAtTail(3) ;
//        L2.insertAtTail(4) ;
//
//        L3.insertAtTail(2) ;
//        L3.insertAtTail(6) ;
//
//        LinkedList<int> Lists[3] = {L1, L2, L3};
//
//        L1 = mergeLinkedLists(Lists, 3) ;
//        L1.print() ;
//    }

    LinkedList<int> l1 ;
    l1.insertAtTail(1) ;
    l1.insertAtTail(2) ;
    l1.insertAtTail(3) ;
    l1.insertAtTail(4) ;

    Solution<int>::swapPairs(l1.getHead()) ;
    l1.print() ;
    return 0;
}