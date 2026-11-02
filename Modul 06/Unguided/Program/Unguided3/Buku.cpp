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
address findElm(List L, infotype x) {
    // mengembalikan alamat memori dari elemen doubly list dengan nilai kodeBuku yang sama dengan nilai kodeBuku milik x dalam doubly list L jika ditemukan atau Nil jika tidak ditemukan
    address node = L.First;
    while (node != Nil && node->info.kodeBuku != x.kodeBuku) {
        node = node->next;
    }
    return node;
}
void deleteFirst(List& L, address& P) {
    // I.S.: terdefinisi doubly list L yang kosong atau berisi dan pointer P
    // F.S.: P menunjuk alamat memori elemen pertama dari doubly list L jika L berisi, atau P bernilai Nil jika L kosong
    if (L.First == Nil) {
        P = Nil;
        return;
    }
    
    P = L.First;
    if (L.First == L.Last) {
        L.First = Nil;
        L.Last = Nil;
    } else {
        L.First = L.First->next;
        L.First->prev = Nil;
        P->next = Nil;
    }
}
void deleteLast(List& L, address& P) {
    // I.S.: terdefinisi doubly list L yang kosong atau berisi dan pointer P
    // F.S.: P menunjuk alamat memori elemen terakhir dari doubly list L jika L berisi, atau P bernilai Nil jika L kosong
    if (L.First == Nil) {
        P = Nil;
        return;
    }

    P = L.Last;
    if (L.First == L.Last) {
        L.First = Nil;
        L.Last = Nil;
    } else {
        L.Last = L.Last->prev;
        L.Last->next = Nil;
        P->prev = Nil;
    }
}
void deleteAfter(address Prec, address& P) {
    // I.S.: terdefinisi pointer Prec yang menunjuk suatu elemen doubly list yang telah dialokasikan dan pointer P
    // F.S.: P menunjuk alamat memori elemen setelah elemen yang ditunjuk pointer Prec jika pointer next milik Prec tidak Nil, atau P bernilai Nil jika pointer next milik Prec bernilai Nil
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = Prec->next->next;
        if (P->next != Nil) {
            P->next->prev = Prec;
        }
    } else {
        P = Nil;
    }
}