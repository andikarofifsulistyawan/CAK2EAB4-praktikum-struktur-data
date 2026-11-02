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
    std::cout << std::endl;
    
    std::string kodeBukuYangDicari;
    std::cout << "Masukkan Kode Buku yang dicari: ";
    std::getline(std::cin, kodeBukuYangDicari);
    std::cout << std::endl;
    
    address nodeBukuYangDicari = findElm(L, {kodeBukuYangDicari, "", 0});
    if (nodeBukuYangDicari == Nil) {
        std::cout << "Buku dengan kode itu tidak ditemukan" << std::endl;
    } else {
        std::cout << "Kode Buku    : " << nodeBukuYangDicari->info.kodeBuku << std::endl;
        std::cout << "Judul        : " << nodeBukuYangDicari->info.judul << std::endl;
        std::cout << "Tahun Terbit : " << nodeBukuYangDicari->info.thnTerbit << std::endl;
    }
    
    return 0;
}