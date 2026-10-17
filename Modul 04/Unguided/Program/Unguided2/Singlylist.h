#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <cstddef>
#define Nil NULL

typedef int infotype;
typedef struct Elmlist *address;
struct Elmlist { 
    infotype info;
    address next;
};
struct List {
    address First;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);
void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(List &L, address Prec);
int nbList(List L);
void deleteList(List &L);

#endif