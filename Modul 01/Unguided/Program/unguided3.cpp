// NIM: 109082500013
// NAMA: Andika Rofif Sulistyawan

#include <iostream>

int main() {
    unsigned int banyakBaris = 0;
    std::cin >> banyakBaris;

    for (int i = banyakBaris; i >= 0; i--) {
        for (int j = banyakBaris; j > i; j--) {
            std::cout << "  ";
        }

        for (int j = i; j >= 1; j--) {
            std::cout << j << " ";
        }

        std::cout << "*";

        for (int j = 1; j <= i; j++) {
            std::cout << " " << j;
        }

        std::cout << std::endl;
    }

    return 0;
}