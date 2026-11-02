#ifndef BUKU_H
#define BUKU_H

#include <string>
#define Nil NULL

struct buku {
    std::string kodeBuku;
    std::string judul;
    int thnTerbit;
};

typedef buku infotype;
typedef struct ElmList* address;
struct ElmList {
    infotype info;
    address next;
    address prev;
};
struct List {
    address First;
    address Last;
};

void CreateList(List& L);
address alokasi(infotype x);
void dealokasi(address& P);
void printInfo(List L);
void insertLast(List& L, address P);

#endif