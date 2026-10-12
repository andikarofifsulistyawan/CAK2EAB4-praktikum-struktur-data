#include <iostream>

void tampilkanArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void tukarArray(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90}
    };

    int x = 100, y = 200;
    int *p1 = &x;
    int *p2 = &y;

    std::cout << "Array A:\n";
    tampilkanArray(A);

    std::cout << "\nArray B:\n";
    tampilkanArray(B);

    int baris, kolom;
    std::cout << "\nMasukkan posisi baris (0-2): ";
    std::cin >> baris;
    std::cout << "Masukkan posisi kolom (0-2): ";
    std::cin >> kolom;

    if (baris < 0 || baris > 2 || kolom < 0 || kolom > 2) {
        std::cout << "Posisi tidak valid!" << std::endl;
        return 1;
    }

    tukarArray(A, B, baris, kolom);

    std::cout << "\nArray A setelah pertukaran:\n";
    tampilkanArray(A);

    std::cout << "\nArray B setelah pertukaran:\n";
    tampilkanArray(B);

    std::cout << "\nSebelum pertukaran pointer: x = " << x << ", y = " << y << std::endl;
    tukarPointer(p1, p2);
    std::cout << "Setelah pertukaran pointer: x = " << x << ", y = " << y << std::endl;

    return 0;
}