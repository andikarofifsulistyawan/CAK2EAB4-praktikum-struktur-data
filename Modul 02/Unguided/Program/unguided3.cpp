#include <iostream>
const int MAX = 10;

int cariMinimum(int arr[MAX]) {
    int minimum = arr[0];

    for (int i = 1; i < MAX; i++) {
        if (arr[i] < minimum) {
            minimum = arr[i];
        }
    }

    return minimum;
}

int cariMaksimum(int arr[MAX]) {
    int maksimum = arr[0];

    for (int i = 1; i < MAX; i++) {
        if (arr[i] > maksimum) {
            maksimum = arr[i];
        }
    }

    return maksimum;
}

void hitungRataRata(int arr[MAX]) {
    int jumlah = 0;

    for (int i = 0; i < MAX; i++) {
        jumlah += arr[i];
    }

    std::cout << "Nilai rata-rata = " << (double) jumlah / MAX << std::endl;
}

int main() { 
    int arrA[MAX] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int pilihan;

    std::cout << "\n--- Menu Program Array ---\n";
    std::cout << "1. Tampilkan isi array\n";
    std::cout << "2. Cari nilai maksimum\n";
    std::cout << "3. Cari nilai minimum\n";
    std::cout << "4. Hitung nilai rata-rata\n";
    std::cout << "Pilih menu: ";
    std::cin >> pilihan;

    switch (pilihan) {
        case 1:
            std::cout << "Isi array: ";
            for (int i = 0; i < MAX; i++) {
                std::cout << arrA[i] << " ";
            }
            std::cout << std::endl;
            break;
        case 2:
            std::cout << "Nilai maksimum = " << cariMaksimum(arrA) << std::endl;
            break;
        case 3:
            std::cout << "Nilai minimum = " << cariMinimum(arrA) << std::endl;
            break;
        case 4:
            hitungRataRata(arrA);
            break;
        default:
            std::cout << "Pilihan tidak valid." << std::endl;
    }

    return 0;
}