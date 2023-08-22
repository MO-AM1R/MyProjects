#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include <iostream>
using namespace std ;

template<class T>
struct Node{
    Node* next ;
    T val ;
    Node() : val(0), next(nullptr) {}
    explicit Node(T x) : val(x), next(nullptr) {}
    explicit Node(T x, Node* n) : val(x), next(n) {}
};

template<class T>
class LinkedList{
private:
    Node<T>* Head{} ;
    Node<T>* Last{} ;
    int Size ;

public:
    explicit LinkedList() : Head(nullptr), Last(nullptr), Size(0) {}

    [[nodiscard]] bool isEmpty() const {return !Head ;}

    [[nodiscard]] int linkedListSize() const {return Size ;}

    void insertAtHead(const T Value){
        insertAt(Value, 0) ;
    }

    void insertAtTail(const T Value){
        insertAt(Value, Size) ;
    }

    Node<T>* getHead(){
        return Head ;
    }
    void insertAt(const T Value, int Pos){
        if ((Pos < 0 || Pos > Size) && Head){
            cerr << "Invalid Index :(\n" ;
            return;
        }
        auto *node = new Node<T>(Value);

        if (!Head){
            Head = node ;
            Last = node ;
        }
        else if (!Pos){
            node->next = Head ;
            Head = node ;
        }
        else if (Pos == Size){
            Last->next = node ;
            Last = node ;
        }
        else {
            Node<T> *Temp = Head;

            for (int i = 0; i < Pos - 1; ++i) {
                Temp = Temp->next;
            }
            node->next = Temp->next;
            Temp->next = node;
        }
        ++Size ;
    }

    void removeAt(int Pos){
        if (Pos < 0 || Pos >= Size){
            cerr << "Invalid Index :(\n" ;
        }

        if (!Head){
            return ;
        }

        Node<T> *newNode = Head;

        if (!Pos){
            Head = nullptr ;
            if (newNode->next) {
                Head = newNode->next ;
            }
        }
        else {
            for (int i = 0; i < Pos - 1; ++i) {
                newNode = newNode->next;
            }
            Node<T>* Temp = newNode->next ;
            newNode->next = newNode->next->next;

            if (Temp == Last){
                Last = newNode ;
            }
            delete Temp;
        }
        --Size ;
    }

    void removeAtHead(){
        removeAt(0) ;
    }

    void removeAtTail(){
        removeAt(Size - 1) ;
    }

    T retrieveAt (int index){
        if (index < 0 || index >= Size){
            cerr << "Invalid Index :(\n" ;
        }
        auto* Temp = Head ;
        while (index--){
            Temp = Temp->next ;
        }

        return Temp->val ;
    }

    void replaceAt (T newElement, int index){
        if (index < 0 || index >= Size){
            cerr << "Invalid Index :(\n" ;
        }
        auto* Temp = Head ;
        while (index--){
            Temp = Temp->next ;
        }
        Temp->val = newElement ;
    }

    void clear(){
        while (Size > 0){
            removeAtHead() ;
        }
    }

    bool isExist(T ele){
        auto* Temp = Head ;

        while (Temp){
            if (Temp->val == ele){
                return true ;
            }
            Temp = Temp->next ;
        }
        return false ;
    }

    bool isItemAtEqual (const T & element, int index){
        return (element == retrieveAt(index)) ;
    }

    void swap (int firstItemIdx, int secondItemIdx){
        if (firstItemIdx > secondItemIdx){
            std::swap(secondItemIdx, firstItemIdx) ;
        }

        // couldn't swap tha same node
        if (firstItemIdx == secondItemIdx){
            return;
        }

        // the indexes are invalid or one of them
        if (firstItemIdx < 0 || secondItemIdx >= Size){
            cerr << "Invalid Index :(\n" ;
            return;
        }

        Node<T> *prevFirstNode = nullptr, *FirstNode = Head ;
        Node<T> *prevSecondNode = nullptr, *SecondNode = Head, *Temp = Head ;

        for (int i = 0; i < secondItemIdx; ++i) {
            if (i == firstItemIdx - 1){
                FirstNode = Temp->next ;
                prevFirstNode = Temp ;
            }
            if (i == secondItemIdx - 1){
                prevSecondNode = Temp ;
                SecondNode = Temp->next ;
            }
            Temp = Temp->next ;
        }
        Temp = SecondNode->next ;

        if (prevFirstNode) {
            prevFirstNode->next = SecondNode;
        }
        // Else make SecondNode as new head
        else {
            Head = SecondNode ;
        }

        // Update the Last if second node is the Last
        if (!SecondNode->next) {
            Last = FirstNode;
        }

        prevSecondNode->next = FirstNode;

        // Swap next pointers
        SecondNode->next = FirstNode->next ;
        FirstNode->next = Temp;
    }

    void print (){
        if (!Head){
            cout << "[]" ;
            return ;
        }
        auto* node = Head ;
        cout << "[" ;

        while (node != Last){
            cout << node->val << " --> ";
            node = node->next ;
        }
        cout << node->val << "]\n" ;
    }

    ~LinkedList(){
        if (!isEmpty()){
            clear() ;
        }
    }
};


//-------------------------> Problems <-------------------------
void combineNodesBetweenZeros(LinkedList<int> & l)
{
    l.insertAtTail(-1);
    int count = 0;
    for (int i = 0;l.retrieveAt(i) != -1; ++i) {
        if(l.retrieveAt(i) == 0)
        {
            for (int j = i+1; j <l.linkedListSize(); ++j) {
                count += l.retrieveAt(j);
                if(l.retrieveAt(j) == 0) {
                    if(count != 0) {
                        l.insertAtTail(count);
                        break;
                    }
                    i++;
                }
            }
            count = 0;
        }
    }
    for (int i = 0;  l.retrieveAt(0) != -1; ++i) {
        l.removeAtHead();
    }
    l.removeAtHead();
}


template<class T>
LinkedList<T> mergeTwoLists(LinkedList<T> & list1, LinkedList<T> & list2) {
    int Size1 = list1.linkedListSize() ;
    int Size2 = list2.linkedListSize() ;
    LinkedList<T> Result ;

    if (!Size1 && !Size2){
        return Result ;
    }
    int i = 0, j = 0 ;

    while (i < Size1 && j < Size2){
        if (list1.retrieveAt(i) < list2.retrieveAt(j)){
            Result.insertAtTail(list1.retrieveAt(i++)) ;
        }
        else{
            Result.insertAtTail(list2.retrieveAt(j++)) ;
        }
    }

    while (i < Size1){
        Result.insertAtTail(list1.retrieveAt(i++)) ;
    }

    while (j < Size2){
        Result.insertAtTail(list2.retrieveAt(j++)) ;
    }

    return Result ;
}

template <class T>
LinkedList<T> mergeLinkedLists(LinkedList<T> Lists[], int k){
    for (int i = 1; i < k; ++i) {
        Lists[0] = mergeTwoLists(Lists[0], Lists[i]) ;
    }

    return Lists[0] ;
}

#endif //LINKEDLIST_LINKEDLIST_H