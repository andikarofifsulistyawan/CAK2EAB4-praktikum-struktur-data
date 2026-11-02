#include <iostream>
#include "Buku.h"

int main() {
    List L;
    CreateList(L);
    
    int banyaknyaInput;
    std::cout << "Banyaknya buku yang ingin di-input: ";
    std::cin >> banyaknyaInput;
    std::cin.ignore();
    
    infotype buku;
    for (int i = 1; i <= banyaknyaInput; i++) {        
        std::cout << "masukkan kode buku: ";
        std::getline(std::cin, buku.kodeBuku);
        
        std::cout << "masukkan judul buku: ";
        std::getline(std::cin, buku.judul);
        
        std::cout << "masukkan tahun terbit: ";
        std::cin >> buku.thnTerbit;
        std::cin.ignore();
        
        insertLast(L, alokasi(buku));
        
        std::cout << std::endl;
    }
    
    std::cout << "DATA LIST 1" << std::endl << std::endl;
    printInfo(L);
    return 0;
}