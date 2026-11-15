#include <iostream>
#include "stack.h"

void CreateStack(Stack &S) {
    S.top = 0;
}

bool isEmpty(Stack S) {
    return S.top == 0;
}

bool isFull(Stack S) {
    return S.top == 20;
}

void push(Stack &S, infotype x) {
    if (isFull(S)) {
        std::cout << "Stack penuh" << std::endl;
    } else {
        S.info[S.top] = x;
        S.top++;
    }
}

infotype pop(Stack &S) {
    if (isEmpty(S)) {
        std::cout << "Stack kosong" << std::endl;
        return 0;
    } else {
        S.top--;
        return S.info[S.top];
    }
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        std::cout << "Stack kosong" << std::endl;
    } else {
        std::cout << "[TOP] ";

        for (int i = S.top - 1; i >= 0; i--) {
            std::cout << S.info[i] << " ";
        }

        std::cout << std::endl;
    }
}

void balikStack(Stack &S) {
    int kiri = 0;
    int kanan = S.top - 1;
    int temp;

    while (kiri < kanan) {
        temp = S.info[kiri];
        S.info[kiri] = S.info[kanan];
        S.info[kanan] = temp;

        kiri++;
        kanan--;
    }
}

void pushAscending(Stack &S, int x) {
    if (isFull(S)) {
        std::cout << "Stack penuh" << std::endl;
    } else {
        int i = S.top - 1;
        while (i >= 0 && S.info[i] > x) {
            S.info[i + 1] = S.info[i];
            i--;
        }
    
        S.info[i + 1] = x;
        S.top++;
    }
}