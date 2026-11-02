#include <iostream>
#include "Buku.h"

void CreateList(List& L) {
    // I.S.: terdefinisi doubly list L
    // F.S.: doubly list L menjadi doubly list kosong
    L.First = Nil;
    L.Last = Nil;
}
address alokasi(infotype x) {
    // mengembalikan alamat memori elemen doubly list baru dengan info x jika alokasi memori berhasil
    return new ElmList{x, Nil, Nil};
}
void dealokasi(address& P) {
    // I.S.: terdefinisi pointer P yang menunjuk elemen doubly list yang telah dialokasikan
    // F.S.: memori P dibebaskan dan P menjadi Nil
    delete P;
    P = Nil;
}
void printInfo(List L) {
    // I.S.: terdefinisi doubly list L yang kosong atau berisi
    // F.S.: menampilkan semua info dalam doubly list L dari akhir hingga awal jika L berisi, atau menampilkan string "List buku kosong" jika L kosong. L tidak berubah
    if (L.Last == Nil) {
        std::cout << "List buku kosong" << std::endl;
    } else {
        address node = L.Last;
        while (node != Nil) {
            std::cout << "kode buku : " << node->info.kodeBuku << std::endl;
            std::cout << "judul     : " << node->info.judul << std::endl;
            std::cout << "tahun     : " << node->info.thnTerbit << std::endl;
            node = node->prev;
        }
    }
}
void insertLast(List& L, address P) {
    // I.S.: terdefinisi doubly list L dan pointer P yang menunjuk elemen doubly list yang telah dialokasikan
    // F.S.: elemen doubly list yang ditunjuk pointer P menjadi elemen terakhir doubly list L jika tidak ada duplikasi kodeBuku, atau menampilkan string "kode buku sudah terdaftar" jika ditemukan duplikasi kodeBuku
    if (L.Last == Nil) {
        L.First = P;
        L.Last = P;
    } else {
        address node = L.First;
        while (node != Nil) {
            if (node->info.kodeBuku == P->info.kodeBuku) {
                std::cout << "kode buku sudah terdaftar" << std::endl;
                return;
            }
            node = node->next;
        }
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}