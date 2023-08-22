# include "DoubleLinkedList.h"

int main() {
    /*DoubleLinkedList<int> L1 ;
    cout << L1.isEmpty() << endl ;

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

    L1.forwardTraversal() ;
    L1.backwardTraversal() ;

    cout << "---------After Swapping---------\n" ;
    L1.swap(0, L1.doubleLinkedListSize() - 1) ;

    L1.forwardTraversal() ;
    L1.backwardTraversal() ;

    cout << L1.isItemAtEqual(4, L1.doubleLinkedListSize() - 1) << endl ;
    cout << L1.doubleLinkedListSize() << endl ;*/

    Tree tree ;
    tree.insert(0) ;
    tree.insert(1) ;
    tree.insert(2) ;
    tree.insert(-5) ;
    tree.insert(5) ;

    cout << "inOrder -> " ;
    tree.inOrder(tree.getRoot()) ;
    cout << "\npreOrder -> " ;
    tree.preOrder(tree.getRoot()) ;
    cout << "\npostOrder -> " ;
    tree.postOrder(tree.getRoot()) ;
    tree.remove(tree.getRoot(), -5) ;
    cout << "\ninOrder -> " ;
    tree.inOrder(tree.getRoot()) ;
    return 0;
}