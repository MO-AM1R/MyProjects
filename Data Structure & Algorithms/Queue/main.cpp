# include "Queue.h"

int main() {
    {
        QueueBasedLinkedList<int> Q;
        cout << Q.isEmpty() << endl;

        Q.enqueue(1);
        Q.enqueue(2);
        Q.enqueue(3);
        Q.enqueue(10);
        Q.enqueue(5);
        Q.enqueue(9);
        Q.enqueue(4);
        Q.enqueue(5);
        Q.print();

        Q.dequeue();
        Q.dequeue();
        Q.dequeue();
        Q.print();

        sortQueue(Q);
        Q.print();

    }

    cout << "------------Generate Binary Numbers------------\n" ;

    {
        QueueBasedLinkedList<int> Q;
        generateBinaryNumbers(Q, 5);
        Q.print() ;
    }

    cout << "------------Stack with Queue------------\n" ;

    {
        Stack<int> S;

        S.push(1);
        S.push(2);
        S.push(3);
        S.push(10);
        S.push(5);
        S.push(9);
        S.push(4);
        S.push(5);
        S.pop();
        S.pop();
        S.pop();

        S.print();
    }

    cout << "------------Sorting Queue------------\n" ;

    {
        QueueBasedLinkedList<int> Q;
        Q.enqueue(1); //0
        Q.enqueue(2);//1
        Q.enqueue(3);//2
        Q.enqueue(10);//3
        Q.enqueue(5);//4
        Q.enqueue(9);//5
        Q.enqueue(-1);//6
        Q.enqueue(5);//7

        sortQueue(Q);
        Q.print();
    }
    return 0;
}
