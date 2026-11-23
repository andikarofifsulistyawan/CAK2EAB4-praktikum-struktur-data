#include <iostream>
#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return Q.head == -1 && Q.tail == -1;
}

bool isFullQueue(Queue Q) {
    return Q.tail - Q.head + 1 == 5;
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        std::cout << "Queue penuh" << std::endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            if (Q.tail == 4) {
                int j = 0;

                for (int i = Q.head; i <= Q.tail; i++) {
                    Q.info[j] = Q.info[i];
                    j++;
                }

                Q.head = 0;
                Q.tail = j - 1;
            }

            Q.tail++;
        }

        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    infotype x;

    if (isEmptyQueue(Q)) {
        std::cout << "Queue kosong" << std::endl;
        return -1;
    } else {
        x = Q.info[Q.head];

        if (Q.head == Q.tail) {
            createQueue(Q);
        } else {
            Q.head++;
        }

        return x;
    }
}

void printInfo(Queue Q) {
    std::cout << Q.head << " - " << Q.tail << "\t | ";

    if (isEmptyQueue(Q)) {
        std::cout << "empty queue";
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            std::cout << Q.info[i] << " ";
        }
    }

    std::cout << std::endl;
}