#include <iostream>

void tukarPointer(int *a, int *b, int *c) {
    int temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}

void tukarReference(int &a, int &b, int &c) {
    int temp = a;
    a = b;
    b = c;
    c = temp;
}

int main() {
    int a = 4, b = 6, c = 8;

    std::cout << "Sebelum ditukar -> a = " << a << ", b = " << b << ", c = " << c << std::endl;

    tukarPointer(&a, &b, &c);
    std::cout << "Setelah Call by Pointer -> a = " << a << ", b = " << b << ", c = " << c << std::endl;

    tukarReference(a, b, c);
    std::cout << "Setelah Call by Reference -> a = " << a << ", b = " << b << ", c = " << c << std::endl;

    return 0;
}