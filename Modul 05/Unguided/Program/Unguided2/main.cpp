#include "Singlylist.h"
#include <iostream>

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
    
    infotype infoYangDicari = 8;
    address PNodeInfoYangDicari = findElm(L,infoYangDicari);
    std::cout << infoYangDicari << (PNodeInfoYangDicari == Nil ? "tidak " : "") << " ditemukan dalam list" << std::endl;
    return 0;
}