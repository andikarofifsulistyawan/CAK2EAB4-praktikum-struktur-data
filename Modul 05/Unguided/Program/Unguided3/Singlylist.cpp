#include <iostream>
#include "Singlylist.h"

void createList(List &L) {
    // I.S.: terdefinisi list L
    // F.S.: list L menjadi list kosong
    L.First = Nil;
}
address alokasi(infotype x) {
    // mengembalikan alamat memori elemen list baru berisi x jika alokasi memori berhasil
    address P = new Elmlist;
    P->info = x;
    P->next = Nil;
    return P;
}
void dealokasi(address &P) {
    // I.S.: terdefinisi pointer P yang menunjuk elemen list yang telah dialokasikan
    // F.S.: memori P dibebaskan dan P menjadi Nil
    delete P;
    P = Nil;
}
void printInfo(List L) {
    // I.S.: terdefinisi list L yang kosong atau berisi
    // F.S.: semua info dalam list L ditampilkan dari awal hingga akhir. L tidak berubah
    address P = L.First;
    while (P != Nil) {
        std::cout << P->info << " ";
        P = P->next;
    }
    std::cout << std::endl;
}
void insertFirst(List &L, address P) {
    // I.S.: terdefinisi list L dan pointer P yang menunjuk elemen list yang telah dialokasikan
    // F.S.: elemen list yang ditunjuk pointer P menjadi elemen pertama list L
    P->next = L.First;
    L.First = P;
}
address findElm(List L, infotype x) {
    // mengembalikan alamat memori dari elemen list dengan infotype x dalam list L jika ditemukan atau Nil jika tidak ditemukan
    address node = L.First;
    while (node != Nil && node->info != x) {
        node = node->next;
    }
    return node;
}
infotype hitungTotalInfo(List L) {
    // mengembalikan total nilai info dalam list L
    infotype totalInfo = 0;
    address node = L.First;
    while (node != Nil) {
        totalInfo += node->info;
        node = node->next;
    }
    return totalInfo;
}