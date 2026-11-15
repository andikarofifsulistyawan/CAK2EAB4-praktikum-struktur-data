#ifndef STACK_H
#define STACK_H

typedef int infotype;
struct Stack {
    infotype info[20];
    int top;
};

// I.S.: stack belum diinisialisasi
// F.S.: terbentuk stack kosong dengan top = 0
void CreateStack(Stack &S);

// mengembalikan true jika stack kosong, atau false jika stack tidak kosong
bool isEmpty(Stack S);

// mengembalikan true jika stack penuh, atau false jika stack belum penuh
bool isFull(Stack S);

// I.S.: stack mungkin kosong atau tidak penuh
// F.S.: elemen x ditambahkan ke posisi top, kemudian top bertambah 1
void push(Stack &S, infotype x);

// I.S.: stack tidak kosong
// F.S.: elemen paling atas diambil dan top berkurang 1
// Return: nilai elemen yang sebelumnya berada di top. Mengembalikan 0 jika stack kosong
infotype pop(Stack &S);

// I.S.: stack mungkin kosong atau berisi elemen
// F.S.: seluruh elemen stack ditampilkan dari top hingga elemen terbawah
void printInfo(Stack S);

// I.S.: stack mungkin kosong atau berisi elemen
// F.S.: urutan seluruh elemen stack dibalik
void balikStack(Stack &S);

// I.S.: stack mungkin kosong atau berisi elemen
// F.S.: elemen x dimasukkan ke stack sehingga urutan elemen dari bawah ke atas tetap ascending
void pushAscending(Stack &S, int x);

#endif