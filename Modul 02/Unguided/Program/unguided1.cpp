#include <iostream>
const int MAX_BARIS = 3;
const int MAX_KOLOM = 3;

int main() {
    int A[MAX_BARIS][MAX_KOLOM] = {0};
    int B[MAX_BARIS][MAX_KOLOM] = {0};

    std::cout << "Masukkan matrix A:" << std::endl;
    for (int i = 0; i < MAX_BARIS; i++) {
        for (int j = 0; j < MAX_KOLOM; j++) {
            std::cin >> A[i][j];
        }
    }
    std::cout << std::endl;
    
    std::cout << "Masukkan matrix B:" << std::endl;
    for (int i = 0; i < MAX_BARIS; i++) {
        for (int j = 0; j < MAX_KOLOM; j++) {
            std::cin >> B[i][j];
        }
    }
    std::cout << std::endl;
    
    std::cout << "A + B:" << std::endl;
    for (int i = 0; i < MAX_BARIS; i++) {
        for (int j = 0; j < MAX_KOLOM; j++) {
            std::cout << A[i][j] + B[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    
    std::cout << "A - B:" << std::endl;
    for (int i = 0; i < MAX_BARIS; i++) {
        for (int j = 0; j < MAX_KOLOM; j++) {
            std::cout << A[i][j] - B[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    
    std::cout << "A * B:" << std::endl;
    for (int i = 0; i < MAX_BARIS; i++) {
        for (int j = 0; j < MAX_KOLOM; j++) {
            int hasil = 0;
            for (int k = 0; k < MAX_KOLOM; k++) {
                hasil += A[i][k] * B[k][j];
            }
            std::cout << hasil << " ";
        }
        std::cout << std::endl;
    }
}