#include <iostream>
#include "Singlylist.h"

int main() 
{ 
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    createList(L);

    P1 = alokasi(2);
    insertFirst(L,P1);

    P2 = alokasi(0);
    insertFirst(L,P2);

    P3 = alokasi(8);
    insertFirst(L,P3);

    P4 = alokasi(12);
    insertFirst(L,P4);

    P5 = alokasi(9);
    insertFirst(L,P5);

    deleteFirst(L);
    deleteLast(L);
    deleteAfter(L,L.First);
    
    printInfo(L);

    std::cout << "Jumlah node : " << nbList(L) << std::endl;

    deleteList(L);

    std::cout << "\n- List Berhasil Terhapus -" << std::endl;
    std::cout << "Jumlah node : " << nbList(L) << std::endl;

    return 0;
} 