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
    return (Q.tail + 1) % 5 == Q.head;
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        std::cout << "Queue penuh" << std::endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail = (Q.tail + 1) % 5;
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
            Q.head = (Q.head + 1) % 5;
        }

        return x;
    }
}

void printInfo(Queue Q) {
    std::cout << Q.head << " - " << Q.tail << "\t | ";

    if (isEmptyQueue(Q)) {
        std::cout << "empty queue";
    } else {
        int i = Q.head;

        while (true) {
            std::cout << Q.info[i] << " ";

            if (i == Q.tail) {
                break;
            }

            i = (i + 1) % 5;
        }
    }

    std::cout << std::endl;
}