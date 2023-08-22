# ifndef DOUBLE_LINKED_LIST_DOUBLEDoubleLinkedList_H
# define DOUBLE_LINKED_LIST_DOUBLEDoubleLinkedList_H

# include <iostream>
#include <vector>
# include "Empty.h"
# include "InvalidIndex.h"
using namespace std ;

template<class t>
class DoubleLinkedList {
private:
    struct node{
        t info;
        node* next;
        node*prev;
    };
    node * head;
    node * last;
    int length;
public:
    DoubleLinkedList(){
        head = last =  nullptr;
        length =0;
    }
    void insertAtHead (t ele)
    {
        node *new_node = new node;
        new_node->info = ele;
        new_node->next = head;
        new_node->prev = nullptr;

        if (length == 0) {
            head = last = new_node;
        } else {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
        length++;

    }

    void insertAtTail(t item)
    {
        node *new_node = new node;
        new_node->info = item;
        new_node->next = nullptr;
        new_node->prev = last;

        if(length ==0)
        {
            head = last = new_node;
        }
        else
        {
            last ->next = new_node;
            last = new_node;
        }
        length++;
    }
    void insertAt(t item, int position)
    {
        node * new_node = new node;
        if(position <0 || position >length)
        {
//            throw out_of_range("Index out of range");
            cerr<<"bad alloc"<<endl;
        }
        else
        {
            if(position == 0){
                insertAtHead(item);
            }
            else if(position == length)
            {
                insertAtTail(item);
            }
            else
            {
                node * curr = head;
                for (int i = 0; i < position-1; ++i){
                    curr = curr->next;
                }
                new_node->info = item;
                new_node->prev = curr;
                new_node->next = curr->next;
                curr->next->prev = new_node;
                curr->next = new_node;
                length++;
            }
        }
    }
    void insertAfter(node *prev_node, t element)
    {
        node * new_node = new node;

        if(prev_node == nullptr)
        {
            cerr<<"invalid node";
            return;
        }
        else
        {
            if(prev_node->next == last)
            {
                insertAtTail(element);
                return;
            }
            else
            {
                new_node->info = element;
                new_node->prev = prev_node;
                new_node->next = prev_node->next;
                prev_node->next->prev = new_node;
                prev_node->next = new_node;
                length++;
            }

        }
    }
    void removeAtHead()
    {
        if(isEmpty())
        {
            cerr<<"is_empty"<<endl;
            return;
        }
        else{
            node* node = head;
            head = head->next;
            if(head == nullptr)
            {
                last = nullptr;
            }
            else{head->prev = nullptr;}
            delete node;

        }
        length--;

    }
    void removeAtTail()
    {
        if(isEmpty())
        {
            cerr<<"is_empty"<<endl;
            return;
        }
        else{
            node* node = last;
            last = last->prev;
            if(last == nullptr)
            {
                head = nullptr;
            }
            else{
                node->prev->next = nullptr;
            }
            delete node;
        }
        length--;
    }
    void removeAt(int idx)
    {
        if(idx <0 || idx >=length)
        {
            cerr<<"bad alloc"<<endl;
            return;
        }
        else
        {
            if(idx == 0)
            {
                removeAtHead();
                return;
            }
            else if(idx == length-1)
            {
                removeAtTail();
                return;
            }
            else {
                node *current = head;
                for (int i = 0; i < idx ; ++i) {
                    current = current->next;
                }

                current->next->prev = current->prev;
                current->prev->next = current->next;
                delete current;
                length--;
            }
        }

    }
    t retrieveAt(int position)
    {
        t ele;
        node * current = head;
        if(position <0 || position >=length)
        {
            cerr<<"bad alloc"<<endl;
        }
        else
        {
            for (int i = 0; i < position; ++i) {
                current = current->next;
            }
            ele = current->info;
        }
        return ele;

    }
    node* getNode(int idx)
    {
        node* curr = head;
        if(idx<0 || idx>=this->length)
        {
            curr = nullptr;
        }
        else {
            for (int i = 0; i < idx; ++i) {
                curr = curr->next;
            }
        }
        return curr;
    }
    void swap (int firstItemIdx, int secondItemIdx){
        if (firstItemIdx > secondItemIdx){
            std::swap(firstItemIdx, secondItemIdx) ;
        }
        if (firstItemIdx == secondItemIdx){
            return ;
        }
        if (firstItemIdx < 0 || secondItemIdx >= length){
            cerr << "Invalid Index :(\n" ;
            return ;
        }

        node *firstNode = head;
        node *secondNode = head ;
        node *Temp = head;

        for (int i = 0; i < secondItemIdx; ++i) {
            if (i == firstItemIdx - 1){
                firstNode = Temp->next ;
            }
            else if (i == secondItemIdx - 1){
                secondNode = Temp->next ;
            }
            Temp = Temp->next ;
        }

        //Update The Last and Head
        if (firstNode == head){
            head = secondNode ;
        }

        if (secondNode == last){
            last = firstNode ;
        }

        //Swap The next Nodes
        Temp = firstNode->next ;
        firstNode->next = secondNode->next ;
        secondNode->next = Temp ;

        //Update The Previous of next Nodes
        if (firstNode->next) {
            firstNode->next->prev = firstNode;
        }
        if (secondNode->next) {
            secondNode->next->prev = secondNode;
        }

        //Swap The Previous Nodes
        Temp = firstNode->prev ;
        firstNode->prev = secondNode->prev ;
        secondNode->prev = Temp ;

        //Update The next of Previous Nodes
        if (firstNode->prev) {
            firstNode->prev->next = firstNode;
        }
        if (secondNode->prev) {
            secondNode->prev->next = secondNode;
        }
    }
    void reverse()
    {
        if(isEmpty())
        {
            cerr<<"is_empty"<<endl;
            return;
        }
        else if(head->next == nullptr)
        {
            return;
        }
        node* Node = head;
        while(Node != nullptr)
        {
//            std::swap(Node->next, Node->prev);
            node* temp = Node->next;
            Node->next = Node->prev;
            Node->prev = temp;

            Node = temp;
        }
        std::swap(head, last);
    }
    bool isItemAtEqual(t element, int position)
    {
        node * current = head;
        if(position <0 || position >length)
        {
            cerr<<"bad alloc"<<endl;
        }
        else
        {
            for (int i = 0; i < position; ++i) {
                current = current->next;
            }
            if(current->info == element)
                return true;
            else
                return false;
        }

    }
    bool isExist(t item)
    {
        node * current = head;
        for (int i = 0; i < length; ++i) {
            if(current->info == item)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }
    bool isEmpty()
    {
        return length == 0;

    }
    int doubleLinkedListSize()
    {
        return length;
    }

    void clear()
    {
        while(head != nullptr)
        {
            node * current = head;
            head = head ->next;

            if (head == nullptr) {
                last = nullptr;
            } else {
                head->prev = nullptr;
            }
            current->next = nullptr;
            delete current;
        }
        length = 0;
    }

    void backwardTraversal()
    {
        node* current = last;
        while (current != nullptr) {
            cout << current->info << " ";
            current = current->prev;
        }
        cout << endl;

    }

    void  forwardTraversal() {
        node *loop = head;
        while (loop != nullptr) {
            cout << loop->info << " ";
            loop = loop->next;
        }
        cout << endl;
    }
};

#endif //DOUBLE_LINKED_LIST_DOUBLEDoubleLinkedList_H