# ifndef QUEUE_QUEUE_H
# define QUEUE_QUEUE_H

# include <iostream>
# include "DoubleLinkedList.h"
# include <iomanip>

using namespace std;

template<class data_Type>
class QueueBasedLinkedList {

private:
    struct Node {
        data_Type item;
        Node *next;
    };

    Node *front;
    Node *back;
    int length;

public:
    QueueBasedLinkedList() {
        front = back = nullptr;
        length = 0;
    }


    bool isEmpty() {
        return length == 0;
    }


    void enqueue(data_Type element) {
        Node *newNode = new Node;
        newNode->item = element;
        newNode->next = nullptr;

        if (isEmpty()) {
            back = front = newNode;
        } else {
            back->next = newNode;
            back = newNode;

        }
        length++;

    }


    data_Type dequeue() {
        data_Type temp = front->item;
        if (isEmpty()) {
            cout << "Empty queue Can't dequeue\n";
        } else {

            Node *current = front;
            if (back == front) {
                front = nullptr;
                back = nullptr;

            } else {
                front = front->next;
            }
            current->next = nullptr;
            free(current);
            length--;
        }
        return temp;


    };

    data_Type first() {
        return front->item;
    }

    data_Type queueSize() {
        return length;
    }

    void clear() {
        Node *current = front;
        while (current != nullptr) {
            front = front->next;
            delete current;
            current = front;
        }
        back = front = nullptr;
        length = 0;

    }

    void print() {
        if (isEmpty()) {
            cout << "\nQueue elements.\n";
            cout << "Empty Queue!!!\n";

        } else {

            cout << "\nQueue elements.\n";
            cout << "Front ";

            Node *current = front;
            while (current != nullptr) {
                cout << current->item << " ";
                current = current->next;
            }
            cout << "Back \n";
        }
    }
};


template<class T>
class Stack {
private:
    QueueBasedLinkedList<T> data{};

public:
    Stack() = default;

    void push(T ele) {
        if (!data.queueSize()) {
            data.enqueue(ele);
            return;
        }

        QueueBasedLinkedList<T> Temp;
        while (!data.isEmpty()) {
            Temp.enqueue(data.dequeue());
        }
        data.enqueue(ele);

        while (!Temp.isEmpty()) {
            data.enqueue(Temp.dequeue());
        }
    }

    T pop() {
        return data.dequeue();
    }

    void print() {
        QueueBasedLinkedList<T> Temp = data;

        if (Temp.isEmpty()) {
            cout << "[\n]";
            return;
        }

        cout << setw(8) << setfill('-') << "-";
        cout << "\n";

        for (int i = 0; i < data.queueSize(); ++i) {
            cout << "|" << left << setw(3) << setfill(' ') << "";
            cout << Temp.first() << left << setw(3 - to_string(Temp.first()).size())
                 << setfill(' ') << "";
            cout << "|\n";
            Temp.dequeue();
        }
        cout << setw(8) << setfill('-') << "-";
        cout << '\n';
    }
};

template <class t>
int get_min(QueueBasedLinkedList<t> & q, int last_idx)
{
    int min_index =-1;
    int min_value = INT16_MAX;
    for (int i = 0; i < q.queueSize(); ++i) {
        int ele = q.first();
        q.enqueue(q.dequeue());
        if(min_value>= ele && i<= last_idx)
        {
            min_value = ele;
            min_index = i;
        }
    }

    return min_index;
}

template <class t>
void insertToEnd(QueueBasedLinkedList<t> & q, int min_idx)
{
    int current;
    int size = q.queueSize();
    for (int i = 0; i < size; ++i) {
        if(i == min_idx)
        {
            current = q.first();
            q.dequeue();
        }
        else{
            q.enqueue(q.dequeue());
        }

    }
    q.enqueue(current);
}

template <class t>
void sortQueue(QueueBasedLinkedList<t> & q)
{
    if(q.isEmpty() || q.queueSize() == 1)
        return;
    for (int i = q.queueSize(); i >= 0 ; --i) {
        insertToEnd(q, get_min(q, i));
    }
}

template<class T>
void generateBinaryNumbers(QueueBasedLinkedList<T> &queue, int element) {
    for (int i = 1; i <= element; ++i) {
        int j = 1, reminder, binaryNumber = 0;
        int temp = i;
        while (temp != 0) {
            reminder = temp % 2;
            binaryNumber = binaryNumber + (reminder * j);
            j = j * 10;
            temp = temp / 2;
        }
        queue.enqueue(binaryNumber);
    }
}

#endif //QUEUE_QUEUE_H