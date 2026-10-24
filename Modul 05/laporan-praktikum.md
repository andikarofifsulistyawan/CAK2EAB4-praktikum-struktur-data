# <h1 align="center">Laporan Praktikum Modul 5 - Singly Linked List (Bagian Kedua)</h1>
<p align="center">Andika Rofif Sulisytawan - 109082500013</p>

## Dasar Teori

### A. Struktur Data<br/>
Struktur data adalah cara untuk mengorganisasi dan menyimpan data agar data dapat diakses serta dikelola sesuai kebutuhan. Pemilihan struktur data memengaruhi cara penyimpanan, pengaksesan, penambahan, dan penghapusan elemen. Array menyimpan elemen pada lokasi memori yang berurutan sehingga elemen dapat diakses melalui indeks, sedangkan linked list menghubungkan elemen menggunakan pointer. Dalam pengelolaan data mahasiswa, linked list dapat menjadi pilihan ketika data sering mengalami perubahan karena penambahan dan penghapusan elemen tidak mengharuskan elemen lain digeser seperti pada array[3]

### B. Abstract Data Type (ADT)<br/>
Abstract Data Type (ADT) adalah model yang menjelaskan jenis data, karakteristik data, dan operasi yang dapat dilakukan terhadap data tanpa mengharuskan pengguna mengetahui detail implementasinya. ADT memisahkan antarmuka operasi dari cara operasi tersebut diwujudkan. Pada ADT list, data disusun sebagai kumpulan elemen berurutan dan operasi yang umum disediakan meliputi pembuatan list kosong, pemeriksaan kondisi kosong, penambahan elemen, penghapusan elemen, penelusuran elemen, serta penghitungan jumlah elemen. Pemisahan ini membantu membuat definisi struktur data lebih terorganisasi dan memudahkan implementasi maupun pemeliharaannya[1][2]

### C. Singly Linked List<br/>
#### 1. Definisi Singly Linked List
Linked list atau senarai berantai adalah struktur data linear yang terdiri atas sejumlah node yang saling terhubung. Setiap node menyimpan data dan informasi penghubung ke node lain. Pada singly linked list, setiap node memiliki bagian data serta satu pointer yang menunjuk ke node berikutnya. Node pertama ditandai oleh pointer awal, sedangkan pointer next pada node terakhir bernilai Nil atau NULL untuk menunjukkan bahwa tidak ada node berikutnya. Penelusuran elemen dilakukan secara berurutan dari node pertama dengan mengikuti pointer next. Oleh karena itu, elemen pada posisi tertentu tidak dapat diakses langsung menggunakan indeks seperti pada array

#### 2. Pointer pada Singly Linked List
Pointer adalah variabel yang menyimpan alamat memori suatu objek. Dalam singly linked list, pointer digunakan untuk menghubungkan node dengan node selanjutnya dan menunjukkan node pertama. Nilai Nil atau NULL menyatakan bahwa pointer tidak menunjuk ke objek yang valid. Node linked list dapat dibuat ketika dibutuhkan melalui alokasi memori dinamis, misalnya dengan operator new dalam C++. Ketika node tidak lagi digunakan, memorinya perlu dibebaskan menggunakan delete. Sebelum memori node dihapus, hubungan antarnode harus diperbarui agar list tidak lagi menunjuk ke node yang sudah dibebaskan. Pembebasan memori juga perlu dilakukan secara teratur agar tidak terjadi memory leak

#### 3. Operasi Penyisipan Node pada Singly Linked List
Penyisipan node singly linked list adalah proses menambahkan elemen baru ke dalam singly linked list. Penyisipan dapat dilakukan di awal, di akhir, atau setelah node tertentu. Untuk penyisipan di awal, pointer pada node baru diarahkan ke node pertama sebelumnya, kemudian pointer awal diperbarui. Untuk penyisipan setelah node tertentu, pointer node baru diarahkan ke node yang semula mengikuti node sebelumnya, lalu pointer node sebelumnya diarahkan ke node baru. Penyisipan di akhir dilakukan dengan menelusuri list hingga node terakhir, kemudian menghubungkannya ke node baru

#### 4.Operasi Penelusuran Node pada Singly Linked List
Penelusuran (traversal) singly linked list adalah proses mengunjungi elemen satu per satu mulai dari node pertama hingga pointer mencapai Nil. Pada setiap langkah, pointer penelusur dipindahkan ke node berikutnya. Proses tersebut dapat digunakan untuk menjumlahkan nilai-nilai yang disimpan di setiap node. Penghitungan dilakukan dengan menginisialisasi suatu variabel jumlah dengan nol, menambah nilainya dengan nilai setiap node yang dikunjungi, lalu mengembalikan hasilnya setelah seluruh node ditelusuri

## Guided 

### 1. Abstract Data Type untuk Singly Linked List Buah

**`listBuah.h`**
```h
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include <string>
using namespace std;

struct buah{
    string nama;
    int jumlah; 
    float harga;
};

typedef buah dataBuah; 

typedef struct node *address; 

struct node{ 
    dataBuah isidata;
    address next;
};

struct linkedlist{ 
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, float hargaAwal, float HargaAkhir);

#endif
```

**`listBuah.cpp`**
```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
    node = Nil;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    if (nodeBaru != Nil) {
        nodeBaru->next = List.first; 
        List.first = nodeBaru;
    }
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - UPDATE -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - SEARCHING -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}
```

**`main.cpp`**
```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    printList(List);
    updateLast(List);
    printList(List);
    updateAfter(List, nodeD);
    printList(List);

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    FindNodeByData(List, "kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);

    delFirst(List);
    printList(List);
    delLast(List);
    printList(List);
    delAfter(List, nodeD, nodeC);
    printList(List);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```

Program di atas mengimplementasikan struktur data singly linked list untuk menyimpan data buah yang terdiri dari nama, jumlah, dan harga. Dalam file `listBuah.h`, didefinisikan struct `buah`, `dataBuah` sebagai alias untuk struct `buah`, `address` sebagai alias untuk pointer to struct `node`, struct `node`, dan struct `linkedlist`, serta deklarasi prototype subprogram yang digunakan. File `listBuah.cpp` berisi implementasi subprogram yang dideklarasikan dalam file `listBuah.h` sebelumnya. Dalam file `main.cpp`, program membuat list kosong, kemudian mengalokasikan lima node berisi data Jeruk, Apel, Pir, Semangka, dan Durian. Node-node tersebut dimasukkan menggunakan insertFirst, insertLast, dan insertAfter, lalu isi list tersebut dan banyaknya node dalam list tersebut ditampilkan. Selanjutnya, program menjalankan update data dengan updateFirst, updateLast, dan updateAfter; pencarian data buah dengan FindNodeByData, FindNodeByAddress, dan FindNodeByRange; penghapusan node dengan delFirst, delLast, dan delAfter; dan terakhir menghapus seluruh isi list menggunakan deleteList

## Unguided 

### 1. Unguided 1: Abstract Data Type untuk Singly Linked List
Buatlah ADT Singly Linked list sebagai berikut di dalam file "Singlylist.h"
```text
Type infotype : int
Type address : pointer to ElmList
Type ElmList <
    info : infotype
    next : address
>
Type List : < First : address >
procedure createList( input/output L : List )
function alokasi( x : infotype ) → address
procedure dealokasi(input/output P : address )
procedure printInfo( input L : List )
procedure insertFirst(input/output L : List, input P :address) 
```
Kemudian buat implementasi ADT Singly Linked list pada file "Singlylist.cpp".

Cobalah hasil implementasi ADT pada file "main.cpp"
```C++
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
    
    printInfo(L);
    return 0;
} 
```

**`Singlylist.h`**
```h
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

#endif
```

**`Singlylist.cpp`**
```C++
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
```

**`main.cpp`**
```C++
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
    
    printInfo(L);
    return 0;
} 
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/andikarofifsulistyawan/CAK2EAB4-praktikum-struktur-data/blob/main/Modul%2005/Unguided/Output/output-unguided1-1.png)

Program di atas merupakan program untuk mengimplementasikan struktur data singly linked list menggunakan bahasa C++. Program terdiri dari tiga file, yaitu `Singlylist.h` sebagai header file yang berisi deklarasi struktur data dan prototype subprogram, `Singlylist.cpp` sebagai implementation file yang berisi implementasi subprogram, serta `main.cpp` sebagai driver file yang digunakan untuk menjalankan program. Struktur data tersebut menyimpan elemen dalam bentuk node yang masing-masing memiliki dua bagian, yaitu `info` untuk menyimpan nilai dan `next` untuk menyimpan alamat node berikutnya

Dalam file `Singlylist.h`, ada direktif `#ifndef SINGLYLIST_H` dan `#endif` yang digunakan untuk mencegah header file `SINGLYLIST_H` diproses berulang kali. Ada pula direktif `#include <cstddef>` untuk menyediakan definisi yang berkaitan dengan tipe dan nilai standar, termasuk `NULL`. Selanjutnya, Nil didefinisikan sebagai alias untuk `NULL`, untuk menandai pointer yang tidak menunjuk ke suatu elemen. Tipe `infotype` didefinisikan sebagai alias untuk `int`, sedangkan `address` merupakan alias untuk pointer to struct `Elmlist`. Struct `Elmlist` memiliki atribut `info` bertipe `infotype` dan `next` bertipe `address`. Struct `List` memiliki atribut `First` yang menyimpan alamat memori elemen pertama dalam linked list

Dalam file `Singlylist.cpp`, didefinisikan implementasi dari setiap subprogram yang terdefinisi dalam file `Singlylist.h`. Pertama, prosedur `createList(List &L)` digunakan untuk menginisialisasi linked list dengan mengatur L.First = Nil sehingga list berada dalam keadaan kosong. Selanjutnya, fungsi `alokasi(infotype x)` membuat elemen baru menggunakan syntax `new Elmlist`, lalu mengisi atribut `info` dengan nilai `x`, lalu mengatur `next` menjadi Nil, lalu mengembalikan alamat elemen tersebut. Prosedur `dealokasi(address &P)` digunakan untuk membebaskan memori elemen melalui syntax `delete P`, kemudian mengatur P = Nil agar pointer tidak lagi menyimpan alamat elemen yang telah dibebaskan. Prosedur `printInfo(List L)` digunakan untuk menampilkan seluruh nilai `info` dalam list menggunakan perulangan while. Terakhir, prosedur `insertFirst(List &L, address P)` menambahkan elemen di awal list dengan mengatur P->next = L.First, kemudian memperbarui L.First = P. Dengan urutan tersebut, elemen baru menjadi elemen pertama dan tetap terhubung dengan elemen-elemen sebelumnya

Dalam file `main.cpp`, program mendeklarasikan variabel `L` bertipe `List` serta pointer `P1`, `P2`, `P3`, `P4`, dan `P5` bertipe `address`. Prosedur `createList` dipanggil terlebih dahulu untuk membuat list kosong. Setelah itu, program mengalokasikan elemen bernilai 2, 0, 8, 12, dan 9 secara berurutan menggunakan fungsi `alokasi`. Setiap elemen yang berhasil dialokasikan kemudian dimasukkan ke awal list menggunakan prosedur `insertFirst`. Karena setiap elemen baru ditempatkan di depan elemen yang sudah ada, urutan elemen dalam list menjadi kebalikan dari urutan penyisipannya, yakni 9, 12, 8, 0, dan 2. Setelah seluruh elemen dimasukkan, program memanggil prosedur `printInfo` untuk menampilkan nilai-nilai info dalam linked list `L` dari elemen pertama hingga elemen terakhir. Hasil keluarannya adalah 9 12 8 0 2. Terakhir, statement `return 0` dijalankan untuk menandakan bahwa program telah selesai dieksekusi secara normal

### 2. Penambahan Fungsi findElm pada ADT Sebelumnya
Carilah elemen dengan info 8 dengan membuat fungsi baru.
```text
fungsi findElm( L : List, x : infotype ) : address
```

**`Singlylist.h`**
```h
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
address findElm(List L, infotype x);

#endif
```

**`Singlylist.cpp`**
```C++
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
```

**`main.cpp`**
```C++
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
    
    infotype infoYangDicari = 8;
    address PNodeInfoYangDicari = findElm(L,infoYangDicari);
    std::cout << infoYangDicari << (PNodeInfoYangDicari == Nil ? "tidak " : "") << " ditemukan dalam list" << std::endl;
    return 0;
}
```

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/andikarofifsulistyawan/CAK2EAB4-praktikum-struktur-data/blob/main/Modul%2005/Unguided/Output/output-unguided2-1.png)

Program di atas adalah pengembangan dari program ADT singly linked list pada Unguided 1 dengan menambahkan fungsi `findElm` untuk mencari elemen berdasarkan nilai info yang tersimpan dalam node secara sekuensial. Program terdiri dari tiga file, yaitu `Singlylist.h` sebagai header file yang berisi definisi struktur data dan prototype subprogram, `Singlylist.cpp` sebagai implementation file yang berisi implementasi subprogram, serta main.cpp sebagai driver file yang digunakan untuk menjalankan program dan menguji fungsi pencarian. Setiap node pada list tetap memiliki dua atribut, yakni `info` untuk menyimpan nilai bertipe `infotype` (alias untuk integer) dan `next` untuk menyimpan alamat node berikutnya. Struct `List` tetap memiliki atribut `First` yang menunjuk ke elemen pertama singly linked list

Dalam file `Singlylist.h`, ada penambahan prototype fungsi `address findElm(List L, infotype x);`. Fungsi tersebut menerima parameter `L` bertipe `List` sebagai list yang akan diperiksa dan `x` bertipe `infotype` sebagai nilai yang ingin dicari. Return type-nya adalah `address`, yang mana adalah alamat node yang memiliki nilai info sesuai dengan nilai yang dicari. Apabila nilai tersebut tidak ditemukan, fungsi tersebut akan mengembalikan Nil (alias untuk `NULL`)

Dalam file `Singlylist.cpp`, fungsi `findElm` tersebut diimplementasikan. Digunakan variabel temporary bernama `node` dengan tipe `address` yang diinisialisasi dengan `L.First` karena akan dilakukan penelusuran dari node pertama sampai node terakhir singly linked list `L`. Untuk melakukan penelusuran tersebut, digunakan perulangan while dengan kondisi selama variabel `node` tidak bernilai Nil dan nilai `node->info` tidak sama dengan `x`. Jika kondisi tersebut terpenuhi, variabel `node` diberi nilai `node->next`, yang berarti ia berpindah ke node berikutnya. Perulangan akan berhenti ketika nilai yang dicari ditemukan atau ketika pointer telah mencapai akhir list. Setelah perulangan selesai, fungsi tersebut mengembalikan nilai variabel `node`. Jika nilainya ditemukan, variabel `node` akan berisi alamat memori node dengan nilai yang dicari, sedangkan jika nilainya tidak ditemukan, variabel `node` akan berisi Nil karena nilai atribut `next` pada node terakhir singly linked list sudah pasti adalah Nil

Dalam file `main.cpp`, program mendeklarasikan variabel `L` bertipe `List` serta pointer `P1`, `P2`, `P3`, `P4`, dan `P5` bertipe `address`. Prosedur `createList` dipanggil terlebih dahulu untuk membuat list kosong. Setelah itu, program mengalokasikan elemen bernilai 2, 0, 8, 12, dan 9 secara berurutan menggunakan fungsi `alokasi`. Setiap elemen yang berhasil dialokasikan kemudian dimasukkan ke awal list menggunakan prosedur `insertFirst`. Karena setiap elemen baru ditempatkan di depan elemen yang sudah ada, urutan elemen dalam list menjadi kebalikan dari urutan penyisipannya, yakni 9, 12, 8, 0, dan 2. Setelah seluruh elemen dimasukkan, program mendeklarasikan variabel `infoYangDicari` dengan nilai 8, kemudian memanggil fungsi `findElm` untuk mencari node yang memiliki nilai info tersebut dalam list `L`. Hasilnya disimpan dalam variabel `PNodeInfoYangDicari` bertipe `address`. Selanjutnya, program mencetak output-nya. Jika node-nya ditemukan, program mencetak string "8 ditemukan dalam list", tetapi jika tidak ditemukan, dengan bantuan operator ternary, program mencetak "8 tidak ditemukan dalam list". Terakhir, statement `return 0` dijalankan untuk menandakan bahwa program telah selesai dieksekusi secara normal

### 3. Penambahan Subprogram untuk Menghitung Total Info Seluruh Elemen pada ADT Sebelumnya
Hitunglah jumlah total info seluruh elemen (9+12+8+0+2=31).

**`Singlylist.h`**
```h
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
address findElm(List L, infotype x);
infotype hitungTotalInfo(List L);

#endif
```

**`Singlylist.cpp`**
```C++
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
```

**`main.cpp`**
```C++
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

    std::cout << "Total info dari kelima elemen adalah " << hitungTotalInfo(L);
    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/andikarofifsulistyawan/CAK2EAB4-praktikum-struktur-data/blob/main/Modul%2005/Unguided/Output/output-unguided3-1.png)

Program di atas merupakan pengembangan dari program ADT singly linked list pada Unguided 2 dengan menambahkan fungsi `hitungTotalInfo(List L)` untuk menghitung jumlah seluruh nilai `info` yang ada dalam list. Program terdiri dari tiga file, yaitu `Singlylist.h` sebagai header file yang berisi definisi struktur data dan prototype subprogram, `Singlylist.cpp` sebagai implementation file yang berisi implementasi subprogram, serta `main.cpp` sebagai driver file yang digunakan untuk menjalankan program dan menampilkan hasil perhitungan. Setiap node pada list tetap memiliki dua atribut, yakni `info` untuk menyimpan nilai bertipe `infotype` (alias untuk integer) dan `next` untuk menyimpan alamat node berikutnya. Struct `List` tetap memiliki atribut `First` yang menunjuk ke elemen pertama singly linked list

Dalam file `Singlylist.h`, ada penambahan prototype fungsi `infotype hitungTotalInfo(List L);`. Fungsi tersebut menerima parameter `L` bertipe `List` yang berisi elemen-elemen yang akan dijumlahkan nilai `info`-nya, kemudian mengembalikan hasil penjumlahan seluruh nilai `info` dalam tipe `infotype`

Dalam file `Singlylist.cpp`, fungsi `hitungTotalInfo(List L)` diimplementasikan. Digunakan variabel `totalInfo` yang diinisialisasi dengan nilai 0 untuk menyimpan jumlah nilai `info` dan `node` yang diinisialisasi dengan nilai `L.First` untuk menyimpan pointer tiap node dalam list `L`. Selanjutnya, digunakan perulangan while untuk menelusuri seluruh elemen selama variabel `node` tidak bernilai Nil. Pada setiap iterasi, nilai `info` dari node yang sedang dikunjungi ditambahkan ke variabel `totalInfo` menggunakan statement `totalInfo += node->info` (ekuivalen dengan `totalInfo = totalInfo + node->info`). Setelah itu, pointer `node` berpindah ke elemen berikutnya melalui statement `node = node->next`. Proses tersebut terus dilakukan sampai seluruh elemen dalam list selesai diperiksa

Dalam file `main.cpp`, program mendeklarasikan variabel `L` bertipe `List` serta pointer `P1`, `P2`, `P3`, `P4`, dan `P5` bertipe `address`. Prosedur `createList` dipanggil terlebih dahulu untuk membuat list kosong. Setelah itu, program mengalokasikan elemen bernilai 2, 0, 8, 12, dan 9 secara berurutan menggunakan fungsi `alokasi`. Setiap elemen yang berhasil dialokasikan kemudian dimasukkan ke awal list menggunakan prosedur `insertFirst`. Karena setiap elemen baru ditempatkan di depan elemen yang sudah ada, urutan elemen dalam list menjadi kebalikan dari urutan penyisipannya, yakni 9, 12, 8, 0, dan 2. Setelah seluruh elemen dimasukkan, program memanggil fungsi `hitungTotalInfo` di dalam perintah `std::cout` untuk menghitung sekaligus menampilkan jumlah seluruh nilai info yang terdapat dalam list. Hasil perhitungannya adalah 9+12+8+0+2=31, sehingga keluaran program adalah "Total info dari kelima elemen adalah 31". Terakhir, statement `return 0` dijalankan untuk menandakan bahwa program telah selesai dieksekusi secara normal

## Kesimpulan
Singly linked list adalah struktur data yang bisa digunakan untuk menyimpan dan mengelola data dengan menghubungkan setiap node menggunakan pointer. Pada praktikum ini, dipelajari penerapan operasi linked list yang berfokus pada pencarian serta traversal. Setiap operasi perlu memperhatikan hubungan antarnode dan pengaturan pointer agar list dapat berjalan dengan benar

## Referensi
[1] Triase. (2020). *Diktat Edisi Revisi: Struktur Data*. Medan: Universitas Islam Negeri Sumatera Utara Medan.<br/>
[2] Indahyati, U., & Rahmawati Yunianita. (2020). *Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++*. Sidoarjo: Umsida Press. https://doi.org/10.21070/2020/978-623-6833-67-4<br/>
[3] Sofianti, H. A., Manullang, Y. V., Tampubolon, N. A., Naibaho, L. H., & Gunawan, I. (2025). Implementasi Struktur Data Array dan Linked List dalam Pengelolaan Data Mahasiswa. *Menulis: Jurnal Penelitian Nusantara, 1*(6), 871–877. https://doi.org/10.59435/menulis.v1i6.417. Teks lengkap: https://padangjurnal.web.id/index.php/menulis/article/download/417/433<br/>