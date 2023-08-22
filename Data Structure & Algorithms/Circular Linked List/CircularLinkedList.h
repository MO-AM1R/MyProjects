# ifndef CIRCULAR_LINKED_LIST_CIRCULARLINKEDLIST_H
# define CIRCULAR_LINKED_LIST_CIRCULARLINKEDLIST_H

#include <iostream>
using namespace std;

template<class T>
struct Node {
    Node *next;
    T val;

    Node() : val(0), next(nullptr) {}
    explicit Node(T x) : val(x), next(nullptr) {}
    explicit Node(T x, Node *n) : val(x), next(n) {}
};

template<class T>
class CircularLinkedList {
private:
    Node<T> *Head{};
    Node<T> *Last{};
    int Size;

public:
    explicit CircularLinkedList() : Head(nullptr), Last(nullptr), Size(0) {}

    [[nodiscard]] bool isEmpty() const { return !Head; }

    [[nodiscard]] int CircularLinkedListSize() const { return Size; }

    void insertAtHead(const T Value) {
        insertAt(Value, 0) ;
    }

    void insertAtTail(const T Value) {
        insertAt(Value, Size) ;
    }

    void insertAt(const T Value, int Pos) {
        if ((Pos < 0 || Pos > Size) && Head){
            cerr << "Invalid Index :(\n" ;
            return;
        }
        auto *node = new Node<T>(Value);

        if (!Head){
            Head = node ;
            Last = node ;
            Last->next = Head ;
        }
        else if (!Pos){
            node->next = Head ;
            Head = node ;
        }
        else if (Pos == Size){
            Last->next = node ;
            Last = node ;
            Last->next = Head ;
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

    void removeAtHead() {
        removeAt(0) ;
    }

    void removeAtTail() {
        removeAt(Size - 1) ;
    }

    void removeAt(int Pos) {
        if (Pos < 0 || Pos >= Size){
            cerr << "Invalid Index :(\n" ;
        }

        if (!Head){
            return ;
        }

        Node<T> *newNode = Head;
        if (!Pos){
            Head = newNode->next ;
            Last->next = Head ;
            delete newNode ;
        }
        else {
            for (int i = 0; i < Pos - 1; ++i) {
                newNode = newNode->next;
            }
            Node<T>* Temp = newNode->next ;
            newNode->next = newNode->next->next;

            if (Temp == Last){
                Last = newNode ;
                Last->next = Head ;
            }
            delete Temp;
        }
        --Size ;
    }

    T retrieveAt(int index) {
        if (index < 0 || index >= Size) {
            cerr << "Invalid Index :(\n";
        }
        auto *Temp = Head;
        while (index--) {
            Temp = Temp->next;
        }

        return Temp->val;
    }

    void replaceAt(T newElement, int index) {
        if (index < 0 || index >= Size) {
            cerr << "Invalid Index :(\n";
        }
        auto *Temp = Head;
        while (index--) {
            Temp = Temp->next;
        }
        Temp->val = newElement;
    }

    void clear() {
        while (Size > 0) {
            removeAtHead();
        }
    }

    bool isExist(T ele) {
        auto *Temp = Head;

        if (Temp->val == ele) {
            return true;
        }
        Temp = Temp->next;

        while (Temp != Head) {
            if (Temp->val == ele) {
                return true;
            }
            Temp = Temp->next;
        }
        return false;
    }

    bool isItemAtEqual(const T &element, int index) {
        return (element == retrieveAt(index));
    }

    void swap(int firstItemIdx, int secondItemIdx) {
        if (firstItemIdx > secondItemIdx) {
            std::swap(secondItemIdx, firstItemIdx);
        }

        // couldn't swap tha same node
        if (firstItemIdx == secondItemIdx) {
            return;
        }

        // the indexes are invalid or one of them
        if (firstItemIdx < 0 || secondItemIdx >= Size) {
            cerr << "Invalid Index :(\n";
            return;
        }

        Node<T> *prevFirstNode = nullptr, *FirstNode = Head;
        Node<T> *prevSecondNode = nullptr, *SecondNode = Head, *Temp = Head;

        for (int i = 0; i < secondItemIdx; ++i) {
            if (i == firstItemIdx - 1) {
                FirstNode = Temp->next;
                prevFirstNode = Temp;
            }
            if (i == secondItemIdx - 1) {
                prevSecondNode = Temp;
                SecondNode = Temp->next;
            }
            Temp = Temp->next;
        }
        Temp = SecondNode->next;

        if (prevFirstNode) {
            prevFirstNode->next = SecondNode;
        }
        // Else make SecondNode as new head
        else {
            Head = SecondNode;
        }

        // Update the Last if second node is the Last
        if (!SecondNode->next) {
            Last = FirstNode;
            Last->next = Head;
        }

        prevSecondNode->next = FirstNode;

        // Swap next pointers
        SecondNode->next = FirstNode->next;
        FirstNode->next = Temp;
    }

    void print() {
        if (!Head) {
            cout << "[]\n";
            return;
        }
        auto *node = Head;
        cout << "[";

        while (node != Last) {
            cout << node->val << " --> ";
            node = node->next;
        }
        cout << node->val << "]\n";
    }

    ~CircularLinkedList() {
        if (!isEmpty()){
            clear() ;
        }
    }
};

# endif //CIRCULAR_LINKED_LIST_CIRCULARLINKEDLIST_H