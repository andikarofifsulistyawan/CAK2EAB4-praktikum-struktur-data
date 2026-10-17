# <h1 align="center">Laporan Praktikum Modul 4 - Singly Linked List (Bagian Pertama)</h1>
<p align="center">Andika Rofif Sulistyawan - 109082500013</p>

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

#### 3. Operasi Penyisipan dan Penghapusan Node pada Singly Linked List
Penyisipan node adalah proses menambahkan elemen baru ke dalam singly linked list. Penyisipan dapat dilakukan di awal, di akhir, atau setelah node tertentu. Untuk penyisipan di awal, pointer pada node baru diarahkan ke node pertama sebelumnya, kemudian pointer awal diperbarui. Untuk penyisipan setelah node tertentu, pointer node baru diarahkan ke node yang semula mengikuti node sebelumnya, lalu pointer node sebelumnya diarahkan ke node baru. Penyisipan di akhir dilakukan dengan menelusuri list hingga node terakhir, kemudian menghubungkannya ke node baru. Operasi penghapusan dilakukan dengan mengubah hubungan pointer agar node yang dihapus terlepas dari list, lalu membebaskan memori node tersebut. Penghapusan dapat dilakukan pada node pertama, terakhir, atau node setelah posisi tertentu. Penanganan kondisi list kosong dan list yang hanya memiliki satu node diperlukan agar perubahan pointer tetap benar. Penelitian tentang pengelolaan data mahasiswa juga menguraikan bahwa linked list mendukung operasi penyisipan dan penghapusan data secara fleksibel[3][4].

#### 4.Operasi Penelusuran, Penghitungan, dan Penghapusan Seluruh Elemen pada Singly Linked List
Penelusuran (traversal) adalah proses mengunjungi elemen satu per satu mulai dari node pertama hingga pointer mencapai Nil. Pada setiap langkah, pointer penelusur dipindahkan ke node berikutnya. Proses ini dapat digunakan untuk menampilkan data atau menghitung banyaknya node. Penghitungan dilakukan dengan menginisialisasi pencacah ke nol, menambah nilainya setiap kali sebuah node ditemukan, lalu mengembalikan hasil setelah seluruh node ditelusuri. Penghapusan seluruh elemen dapat dilakukan dengan menghapus node pertama secara berulang hingga pointer awal bernilai Nil. Setelah proses tersebut selesai, list berada dalam keadaan kosong dan tidak ada node yang tersisa untuk diakses

## Guided 

### 1. Guided 1: Abstract Data Type untuk Singly Linked List Mahasiswa

**`list.h`**
```h
// hear guard digunakan untuk mencegah file header yg sama
// di-include lebih dari sekali dalam 1 program
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

// deklarasi isi data struct mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; // memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; // mendefinisikan alias address sebagai pointer ke struct node

struct node { // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct LinkedList { // ini linked listnya
    address first;
};

// semua function & procedure yang akan dipakai
bool isEmpty(LinkedList List);
void createList(LinkedList &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(LinkedList List);
void insertFirst(LinkedList &List, address nodeBaru);
void insertAfter(LinkedList &List, address nodeBaru, address Prev);
void insertLast(LinkedList &List, address nodeBaru);

void delFirst(LinkedList &List);
void delLast(LinkedList &List);
void delAfter(LinkedList &List, address nodeHapus, address nodePrev);
int nbList(LinkedList List);
void deleteList(LinkedList &List);

#endif
```

**`list.cpp`**
```C++
#include "list.h"
#include <iostream>
using namespace std;

// I.S = Initial State / kondisi awal
// F.S = Final State / kondisi akhir

// fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(LinkedList List) {
    if(List.first == Nil){
        return true;
    } else {
        return false;
    }
}

// pembuatan linked list kosong
void createList(LinkedList &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

// pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) {
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

// penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

// prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(LinkedList &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(LinkedList &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(LinkedList &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
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

// prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(LinkedList &List){
    /* I.S. list tidak kosong
       F.S. node pertama di list terhapus*/
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(LinkedList &List){
    /* I.S. list tidak kosong
       F.S. node terakhir di list terhapus */
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
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(LinkedList &List, address nodeHapus, address nodePrev){
    /* I.S. list tidak kosong, Prev alamat salah satu elemen list
       F.S. nodeBantu adalah alamat dari Prev->next, menghapus Prev->next dari list */
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { // jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

// prosedur untuk menampilkan isi list
void printList(LinkedList List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) {
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

// function untuk menampilkan jumlah node didalam list
int nbList(LinkedList List) {
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node didalam list*/
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

// prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(LinkedList &List){
    /* I.S. list sudah ada
       F.S. menghapus semua node didalam list*/
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "List sudah terhapus!" << endl;
}
```

**`main.cpp`**
```C++
#include "list.h"
#include <iostream>
using namespace std;

int main(){
    LinkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "231110014", 21);
    nodeC = alokasi("Rizal", "231110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

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
Program di atas mengimplementasikan singly linked list yang menyimpan data mahasiswa berupa nama, NIM, dan umur. Dalam file list.h, didefinisikan struct mahasiswa dan alias dataMahasiswa untuk menyimpan informasi mahasiswa dalam setiap node. Selain itu, ada deklarasi subprogram, yaitu memeriksa kondisi list melalui fungsi isEmpty(), membuat list baru dengan prosedur createList(), mengalokasikan node baru dengan fungsi alokasi(), membebaskan memori suatu elemen dengan prosedur dealokasi(), menambahkan node melalui insertFirst(), insertAfter(), dan insertLast(); menghapus node melalui delFirst(), delLast(), dan delAfter(); mencetak informasi setiap node dalam list menggunakan prosedur printList(), menghitung banyaknya node dengan fungsi nbList(), serta menghapus seluruh node dalam list dengan deleteList(). Dalam file list.cpp, didefinisikan implementasi dari setiap subprogram dalam file list.h. Dalam file main.cpp, lima data mahasiswa dimasukkan menggunakan prosedur penyisipan, kemudian list ditampilkan dan banyaknya node dihitung. Setelah itu, program menghapus node pertama, node terakhir, dan node setelah nodeC, lalu menampilkan kembali isi list. Terakhir, prosedur deleteList() dipanggil untuk menghapus seluruh node sehingga list kosong, dan program menampilkan isi serta banyaknya node setelah penghapusan

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
![Screenshot Output Unguided 1_1](https://github.com/andikarofifsulistyawan/CAK2EAB4-praktikum-struktur-data/blob/main/Modul%2004/Unguided/Output/output-unguided1-1.png)

Program di atas merupakan program untuk mengimplementasikan struktur data singly linked list menggunakan bahasa C++. Program terdiri dari tiga file, yaitu Singlylist.h sebagai header file yang berisi deklarasi tipe data dan subprogram, Singlylist.cpp sebagai implementation file yang berisi implementasi subprogram, serta main.cpp sebagai driver file yang digunakan untuk menjalankan program. Struktur data ini menyimpan elemen dalam bentuk node yang masing-masing memiliki dua bagian, yaitu info untuk menyimpan nilai dan next untuk menyimpan alamat node berikutnya. Program menyediakan lima subprogram utama, yaitu prosedur createList(), fungsi alokasi(), prosedur dealokasi(), prosedur printInfo(), dan prosedur insertFirst()

Dalam file Singlylist.h, ada direktif #ifndef, #define, dan #endif yang digunakan untuk mencegah header file diproses berulang kali. Direktif #include <cstddef> digunakan untuk menyediakan definisi yang berkaitan dengan tipe dan nilai standar, termasuk NULL. Selanjutnya, Nil didefinisikan sebagai alias untuk NULL, untuk menandai pointer yang tidak menunjuk ke suatu elemen. Tipe infotype didefinisikan sebagai alias untuk int, sedangkan address merupakan alias untuk pointer to struct Elmlist. Struct Elmlist memiliki atribut info bertipe infotype dan next bertipe address. Sementara itu, struct List memiliki atribut First yang menyimpan alamat memori elemen pertama dalam linked list

Dalam file Singlylist.cpp, didefinisikan implementasi dari setiap subprogram yang terdefinisi dalam file Singlylist.h. Untuk setiap prosedur, diberikan informasi initial state dan final state-nya, sedangkan untuk fungsi, diberikan informasi nilai apa yang dikembalikan. Pertama, prosedur createList(List &L) digunakan untuk menginisialisasi linked list dengan mengatur L.First = Nil sehingga list berada dalam keadaan kosong. Selanjutnya, fungsi alokasi(infotype x) membuat elemen baru menggunakan syntax new Elmlist, lalu mengisi atribut info dengan nilai x, lalu mengatur next menjadi Nil, lalu mengembalikan alamat elemen tersebut. Prosedur dealokasi(address &P) digunakan untuk membebaskan memori elemen melalui syntax delete P, kemudian mengatur P = Nil agar pointer tidak lagi menyimpan alamat elemen yang telah dibebaskan. Prosedur printInfo(List L) digunakan untuk menampilkan seluruh nilai dalam list menggunakan perulangan while. Terakhir, prosedur insertFirst(List &L, address P) menambahkan elemen di awal list dengan mengatur P->next = L.First, kemudian memperbarui L.First = P. Dengan urutan tersebut, elemen baru menjadi elemen pertama dan tetap terhubung dengan elemen-elemen sebelumnya

Dalam file main.cpp, program mendeklarasikan variabel L bertipe List serta pointer P1, P2, P3, P4, dan P5 bertipe address. Prosedur createList(L) dipanggil terlebih dahulu untuk membuat list kosong. Setelah itu, program mengalokasikan elemen bernilai 2, 0, 8, 12, dan 9 secara berurutan menggunakan fungsi alokasi(). Setiap elemen yang berhasil dialokasikan kemudian dimasukkan ke awal list menggunakan prosedur insertFirst(). Karena setiap elemen baru ditempatkan di depan elemen yang sudah ada, urutan elemen dalam list menjadi kebalikan dari urutan penyisipannya, yakni 9, 12, 8, 0, dan 2. Setelah seluruh elemen dimasukkan, program memanggil prosedur printInfo(L) untuk menampilkan nilai-nilai dalam linked list L dari elemen pertama hingga elemen terakhir. Hasil keluarannya adalah 9 12 8 0 2, sesuai dengan urutan penyisipan menggunakan prosedur insertFirst(). Terakhir, statement return 0 dijalankan untuk menandakan bahwa program telah selesai dieksekusi secara normal

### 2. Unguided 2: Penambahan Prosedur deleteFirst(), Prosedur deleteLast(), Prosedur deleteAfter(), Fungsi nbList(), dan Prosedur deleteList() pada Unguided 1
Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh node menggunakan deleteList()
Output yang diharapkan: 
```text
12 0
Jumlah node : 2

- List Berhasil Terhapus -
Jumlah node : 0
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
void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(List &L, address Prec);
int nbList(List L);
void deleteList(List &L);

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
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/andikarofifsulistyawan/CAK2EAB4-praktikum-struktur-data/blob/main/Modul%2004/Unguided/Output/output-unguided2-1.png)

Program di atas merupakan pengembangan dari program singly linked list pada soal unguided 1. Penambahan utamanya adalah beberapa prosedur untuk menghapus node, fungsi untuk menghitung banyaknya node, dan prosedur untuk menghapus seluruh node dalam list. Dalam file Singlylist.h, ditambahkan deklarasi prosedur deleteFirst(), prosedur deleteLast(), prosedur deleteAfter(), fungsi nbList(), dan prosedur deleteList() serta implementasinya dalam file Singlylist.cpp, agar subprogram-subprogram tersebut bisa digunakan pada program utama

Prosedur deleteFirst(List &L) digunakan untuk menghapus node pertama dalam list. Prosedur tersebut memeriksa apakah list tidak kosong melalui kondisi L.First != Nil. Jika list berisi node, pointer P menyimpan alamat node pertama, kemudian L.First dipindahkan ke node berikutnya. Setelah itu, dealokasi(P) dipanggil untuk membebaskan memori node yang dihapus. Sementara itu, deleteLast(List &L) digunakan untuk menghapus node terakhir. Jika list hanya memiliki satu node, L.First diatur menjadi Nil sebelum memorinya dibebaskan. Jika terdapat lebih dari satu node, pointer P bergerak hingga mencapai node terakhir, sedangkan Prec menyimpan alamat node sebelumnya. Selanjutnya, Prec->next diatur menjadi Nil dan node terakhir dihapus menggunakan dealokasi(P)

Prosedur deleteAfter(List &L, address Prec) digunakan untuk menghapus node yang berada tepat setelah node yang ditunjuk oleh Prec. Penghapusan dilakukan apabila Prec bukan Nil dan masih memiliki node setelahnya. Pointer P menyimpan alamat node yang akan dihapus, kemudian Prec->next dihubungkan langsung ke node setelah P. Setelah hubungan antarnode diperbarui, dealokasi(P) membebaskan memori node tersebut

Fungsi nbList(List L) ditambahkan untuk menghitung banyaknya node yang tersimpan dalam list. Variabel jumlah diinisialisasi dengan nilai 0, kemudian pointer P digunakan untuk menelusuri list mulai dari L.First. Setiap kali menemukan node, nilai jumlah bertambah satu dan pointer P berpindah ke node berikutnya. Setelah seluruh node ditelusuri, fungsi mengembalikan nilai jumlah menggunakan statement return jumlah

Terakhir, prosedur deleteList(List &L) digunakan untuk menghapus seluruh node. Prosedur tersebut menjalankan prosedur deleteFirst(L) berulang kali selama L.First != Nil, sehingga setiap node dihapus dari awal hingga list menjadi kosong

Pada fungsi main(), list mula-mula diisi dengan nilai 2, 0, 8, 12, dan 9 menggunakan fungsi alokasi() serta prosedur insertFirst(), sehingga urutan node menjadi 9 12 8 0 2. Selanjutnya, prosedur deleteFirst(L) dipanggil untuk menghapus node 9, lalu prosedur deleteLast(L) dipanggil untuk menghapus node 2, lalu prosedur deleteAfter(L,L.First) dipanggil untuk menghapus node 8. Hasilnya, printInfo(L) menampilkan 12 0, dan fungsi nbList(L) menampilkan node sebanyak 2. Setelah itu, prosedur deleteList(L) dipanggil untuk menghapus seluruh node. Akibatnya, pemanggilan fungsi nbList(L) berikutnya menghasilkan 0

## Kesimpulan
Singly linked list merupakan struktur data yang setiap elemennya terhubung melalui pointer. Setiap node menyimpan data dan alamat node berikutnya, sementara First menunjuk ke node pertama dalam list. Pada praktikum ini, saya mempelajari untuk membuat abstract data type (ADT) untuk singly linked list menggunakan bahasa C++, mulai dari pembuatan list kosong, alokasi dan dealokasi memori, hingga operasi penyisipan dan penghapusan node. Selain itu, ada juga fungsi untuk memeriksa apakah list kosong atau tidak, prosedur untuk menampilkan isi list, dan fungsi untuk menghitung banyaknya node

## Referensi
[1] Triase. (2020). *Diktat Edisi Revisi: Struktur Data*. Medan: Universitas Islam Negeri Sumatera Utara Medan.<br/>
[2] Indahyati, U., & Rahmawati Yunianita. (2020). *Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++*. Sidoarjo: Umsida Press. https://doi.org/10.21070/2020/978-623-6833-67-4<br/>
[3] Sofianti, H. A., Manullang, Y. V., Tampubolon, N. A., Naibaho, L. H., & Gunawan, I. (2025). Implementasi Struktur Data Array dan Linked List dalam Pengelolaan Data Mahasiswa. *Menulis: Jurnal Penelitian Nusantara, 1*(6), 871–877. https://doi.org/10.59435/menulis.v1i6.417. Teks lengkap: https://padangjurnal.web.id/index.php/menulis/article/download/417/433<br/>
[4] Fitra, M. R. A., Effendi, A. A. S., & Ramadhani, F. (2025). Implementasi Python dalam Pengolahan Data Pribadi Mahasiswa Ilmu Komputer Angkatan 23 pada Universitas Negeri Medan Menggunakan Struktur Data Linked List. *JATI (Jurnal Mahasiswa Teknik Informatika), 9*(1). https://doi.org/10.36040/jati.v9i1.12164<br/>