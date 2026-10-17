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
void deleteFirst(List &L) {
    // I.S.: terdefinisi list L yang kosong atau berisi
    // F.S.: jika L tidak kosong, elemen pertama dihapus. Jika L kosong, L tetap kosong
    if (L.First != Nil) {
        address P = L.First;
        L.First = L.First->next;
        dealokasi(P);
    }
}
void deleteLast(List &L) {
    // I.S.: terdefinisi list L yang kosong atau berisi
    // F.S.: jika L tidak kosong, elemen terakhir dihapus. Jika L kosong, L tetap kosong
    if (L.First != Nil) {
        address P = L.First;

        if (P->next == Nil) {
            L.First = Nil;
            dealokasi(P);
        } else {
            address Prec = Nil;

            while (P->next != Nil) {
                Prec = P;
                P = P->next;
            }

            Prec->next = Nil;
            dealokasi(P);
        }
    }
}
void deleteAfter(List &L, address Prec) {
    // I.S.: terdefinisi list L dan pointer Prec yang menunjuk elemen list dalam L atau bernilai Nil
    // F.S.: jika Prec bukan Nil dan memiliki elemen setelahnya, elemen setelah Prec dihapus. Jika tidak, L tidak berubah
    if (Prec != Nil && Prec->next != Nil) {
        address P = Prec->next;
        Prec->next = P->next;
        dealokasi(P);
    }
}
int nbList(List L) {
    // mengembalikan banyaknya elemen yang tersimpan dalam list L
    int jumlah = 0;
    address P = L.First;

    while (P != Nil) {
        jumlah++;
        P = P->next;
    }

    return jumlah;
}
void deleteList(List &L) {
    // I.S.: terdefinisi list L yang kosong atau berisi
    // F.S.: seluruh elemen dalam list L dihapus dan L menjadi kosong
    while (L.First != Nil) {
        deleteFirst(L);
    }
}