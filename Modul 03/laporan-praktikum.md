# <h1 align="center">Laporan Praktikum Modul 3 - ABSTRACT DATA TYPE (ADT)</h1>
<p align="center">Andika Rofif Sulistyawan - 109082500013</p>

## Dasar Teori

### A. Abstract Data Type (ADT)<br/>

Abstract data type (ADT) atau tipe data abstrak adalah konsep yang mendefinisikan suatu tipe data beserta sekumpulan operasi yang dapat dilakukan terhadap data tersebut. ADT menjelaskan jenis data yang dikelola dan operasi yang disediakan tanpa mengharuskan pengguna mengetahui seluruh detail implementasinya. Operasi dasar pada ADT dapat mencakup pembuatan data, pengambilan atau pengubahan nilai, validasi, serta penampilan data. Dalam pemrograman C++, ADT dapat dirancang menggunakan tipe data bentukan dan fungsi atau prosedur yang mengoperasikan tipe tersebut. Penerapan ADT dapat membantu program disusun secara modular dan membuat tanggung jawab setiap operasi lebih jelas [1].

#### 1. Struct

struct merupakan fitur C++ yang digunakan untuk mendefinisikan tipe data bentukan dengan menggabungkan beberapa anggota atau atribut di bawah satu nama. Anggota di dalam sebuah struct dapat memiliki tipe data yang berbeda, misalnya string atau integer. Setiap anggota diakses menggunakan operator titik (.) setelah nama variabel struct

#### 2. Pemisahan File Program

Program C++ dapat disusun ke dalam beberapa file untuk memisahkan deklarasi dan implementasi. File header dengan ekstensi .h umumnya berisi deklarasi tipe data dan prototipe fungsi atau prosedur. File sumber dengan ekstensi .cpp dapat berisi implementasi fungsi dan prosedur tersebut, sedangkan file utama dapat berisi fungsi main() sebagai titik masuk program dan mengatur pemanggilan operasi yang dibutuhkan. Direktif #include digunakan untuk menyertakan deklarasi dari header, sementara include guard mencegah header yang sama diproses berulang kali dalam satu proses kompilasi. Pemisahan tersebut membuat kode lebih terorganisasi dan lebih mudah dipelihara

### B. Array<br/>

Array adalah struktur data yang menyimpan sejumlah elemen dengan tipe data yang sama di bawah satu nama variabel. Setiap elemen array diakses melalui index. Dalam C++, index array dimulai dari 0, sehingga elemen pertama berada pada index 0. Array memiliki ukuran yang ditentukan saat deklarasi untuk array biasa, sehingga banyaknya elemen yang dapat ditampung dibatasi oleh ukuran tersebut. Array dapat digunakan untuk menyimpan data berurutan dan mengakses elemen tertentu secara langsung melalui index-nya [2]

#### 1. Array Satu Dimensi

Array satu dimensi menyimpan elemen dalam satu urutan index. Deklarasi seperti `int angka[5]` menyatakan array bernama angka yang dapat menyimpan lima elemen bertipe int. Elemen dapat diakses melalui index, misalnya angka[0] untuk elemen pertama. Perulangan sering digunakan untuk membaca, mengolah, atau menampilkan seluruh elemen array secara berurutan

#### 2. Array Dua Dimensi

Array dua dimensi menyimpan elemen dalam susunan baris dan kolom. Deklarasi seperti `int matriks[3][3]` membentuk array yang memiliki tiga baris dan tiga kolom. Elemen diakses menggunakan dua index, yaitu index baris dan index kolom, seperti `matriks[0][0]`. Dua perulangan `for` yang bersarang dapat digunakan untuk mengakses setiap elemen array dua dimensi.

### C. Fungsi dan Prosedur<br/>

Fungsi dan prosedur merupakan subprogram yang digunakan untuk membagi program menjadi bagian-bagian dengan tugas tertentu. Pembagian ini membantu mengurangi pengulangan kode, memperjelas alur program, dan memudahkan pengujian serta pemeliharaan

#### 1. Fungsi

Fungsi adalah subprogram yang dapat menerima parameter, menjalankan serangkaian perintah, dan mengembalikan nilai melalui keyword `return`. Tipe nilai yang dikembalikan ditentukan pada deklarasi fungsi. Sebagai contoh, fungsi bertipe `float` dapat mengembalikan hasil perhitungan berupa bilangan pecahan. Parameter memungkinkan fungsi menerima data yang diperlukan untuk melakukan pengolahan

#### 2. Prosedur

Dalam pemrograman C++, istilah prosedur umumnya merujuk pada fungsi bertipe `void`, yaitu subprogram yang tidak mengembalikan nilai. Prosedur dapat digunakan untuk menjalankan tindakan tertentu, seperti membaca masukan atau menampilkan data. Baik fungsi maupun prosedur dapat menerima parameter untuk menggunakan data dari bagian program lain

#### 3. Parameter Nilai dan Referensi

Parameter berdasarkan nilai (pass by value) menerima salinan nilai argumen, sehingga perubahan terhadap parameter tidak mengubah variabel asal. Sementara itu, parameter referensi ditandai dengan simbol `&` pada deklarasi parameter, misalnya `mahasiswa &m`. Parameter referensi mengacu pada variabel asal, sehingga perubahan terhadap parameter dapat langsung memengaruhi objek tersebut

### D. Pointer<br/>

Pointer adalah variabel yang menyimpan alamat memori dari objek atau variabel lain. Pada C++, operator `&` digunakan untuk memperoleh alamat suatu variabel, sedangkan operator `*` digunakan dalam deklarasi pointer dan untuk melakukan dereferensi, yaitu mengakses nilai pada alamat yang ditunjuk. Sebagai contoh, pointer bertipe `int*` dapat menunjuk ke variabel bertipe `int`. Melalui dereferensi, program dapat membaca atau mengubah nilai variabel yang ditunjuk oleh pointer

## Guided 

### 1. Guided 1: Abstract Data Type Mahasiswa

**`mahasiswa.h`**
```h
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED
struct mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);
#endif // MAHASISWA_H_INCLUDED
```

**`mahasiswa.cpp`**
```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "input nim = ";
    cin >> (m).nim;
    cout << "input nilai = ";
    cin >> (m).nilai1;
    cout << "input nilai2 = ";
    cin >> (m).nilai2;
}

float rata2(mahasiswa m) {
    return float(m.nilai1 + m.nilai2) / 2.0;
}
```

**`main.cpp`**
```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

int main() {
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "rata-rata = " << rata2(mhs);
    return 0;
}
```
Program di atas merupakan implementasi abstract data type untuk menyimpan data mahasiswa dan menghitung nilai rata-rata dari dua nilai. Program terdiri dari tiga file, yaitu mahasiswa.h untuk header deklarasi struktur dan prototipe subprogram, mahasiswa.cpp untuk implementasi subprogram, serta main.cpp sebagai program utama atau driver

Pada file mahasiswa.h, terdapat struct mahasiswa yang memiliki atribut nim bertipe array karakter serta nilai1 dan nilai2 bertipe int. Di dalamnya juga ada prosedur inputMhs() untuk memasukkan data mahasiswa dan fungsi rata2() untuk menghitung nilai rata-rata

Pada file mahasiswa.cpp, prosedur inputMhs() menerima parameter mahasiswa &m, yaitu reference ke objek mahasiswa, sehingga data yang dimasukkan langsung disimpan ke objek aslinya. Fungsi rata2() menjumlahkan nilai1 dan nilai2, kemudian membaginya dengan 2.0 untuk memperoleh nilai rata-rata bertipe float

Pada file main.cpp, program membuat variabel mhs bertipe mahasiswa, kemudian memanggil prosedur inputMhs(mhs) untuk menerima data dari pengguna. Setelah itu, program memanggil fungsi rata2(mhs) dan menampilkan hasilnya menggunakan std::cout. Ada pula statement return 0 yang menandakan bahwa program telah selesai dijalankan secara normal

## Unguided 

### 1. Unguided 1: Penyimpanan Data Mahasiswa
Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3 * uts + 0.4 * uas + 0.3 * tugas.

```C++
#include <iostream>
#include <string>

const short TOTAL_MAHASISWA_MAKSIMAL = 10;

struct Mahasiswa {
    std::string nama, nim;
    float uts, uas, tugas, nilaiAkhir;
};  

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

int main() {
    Mahasiswa arrayMahasiswa[TOTAL_MAHASISWA_MAKSIMAL] = {};
    int totalMahasiswa = 0;

    std::cout << "Total mahasiswa (maksimal "<< TOTAL_MAHASISWA_MAKSIMAL << "): ";
    std::cin >> totalMahasiswa;

    if (totalMahasiswa < 1 || totalMahasiswa > TOTAL_MAHASISWA_MAKSIMAL) {
        std::cout << "Total mahasiswa tidak valid" << std::endl;
        return 1;
    }

    for (int i = 0; i < totalMahasiswa; i++) {
        std::cout << "\nData mahasiswa ke-" << i + 1;
        
        std::cout << "\nNama: ";
        std::getline(std::cin >> std::ws, arrayMahasiswa[i].nama);
        
        std::cout << "NIM: ";
        std::cin >> arrayMahasiswa[i].nim;
        
        std::cout << "Nilai UTS: ";
        std::cin >> arrayMahasiswa[i].uts;
        
        std::cout << "Nilai UAS: ";
        std::cin >> arrayMahasiswa[i].uas;
        
        std::cout << "Nilai Tugas: ";
        std::cin >> arrayMahasiswa[i].tugas;
        
        arrayMahasiswa[i].nilaiAkhir = hitungNilaiAkhir(arrayMahasiswa[i].uts, arrayMahasiswa[i].uas, arrayMahasiswa[i].tugas);
    }
    
    std::cout << "\n==== DATA MAHASISWA =====";
    for (int i = 0; i < totalMahasiswa; i++) {
        std::cout << "\nData mahasiswa ke-" << i + 1;
        std::cout << "\nNama: " << arrayMahasiswa[i].nama;
        std::cout << "\nNIM: " << arrayMahasiswa[i].nim;
        std::cout << "\nNilai UTS: " << arrayMahasiswa[i].uts;
        std::cout << "\nNilai UAS: " << arrayMahasiswa[i].uas;
        std::cout << "\nNilai Tugas: " << arrayMahasiswa[i].tugas;
        std::cout << "\nNilai Akhir: " << arrayMahasiswa[i].nilaiAkhir;
        std::cout << std::endl;
    }

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/andikarofifsulistyawan/CAK2EAB4-praktikum-struktur-data/blob/main/Modul%2003/Unguided/Output/output-unguided1-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/andikarofifsulistyawan/CAK2EAB4-praktikum-struktur-data/blob/main/Modul%2003/Unguided/Output/output-unguided1-2.png)

##### Output 3
![Screenshot Output Unguided 1_3](https://github.com/andikarofifsulistyawan/CAK2EAB4-praktikum-struktur-data/blob/main/Modul%2003/Unguided/Output/output-unguided1-3.png)

Program di atas merupakan program untuk menyimpan dan menampilkan data mahasiswa, yang meliputi nama, NIM, nilai UTS, nilai UAS, nilai tugas, dan nilai akhir. Program tersebut menggunakan struct untuk mengelompokkan atribut setiap mahasiswa, array untuk menyimpan data-data mahasiswa, serta function untuk menghitung nilai akhir berdasarkan bobot masing-masing komponen penilaian. Setelah seluruh data dimasukkan, program akan menampilkan kembali data-data mahasiswa beserta nilai akhirnya ke standard output atau terminal

Pada bagian awal program, terdapat direktif #include <iostream> dan #include <string>. Header iostream digunakan untuk menyediakan fasilitas input dan output melalui std::cin dan std::cout, sedangkan header string digunakan agar program dapat menggunakan tipe data std::string untuk menyimpan teks. Selanjutnya, terdapat deklarasi konstanta TOTAL_MAHASISWA_MAKSIMAL bertipe short dengan nilai 10. Konstanta tersebut digunakan untuk menentukan total maksimal mahasiswa yang dapat disimpan oleh program

Setelah itu, program mendeklarasikan struct Mahasiswa yang memiliki atribut nama dan nim bertipe std::string, serta uts, uas, tugas, dan nilaiAkhir bertipe float. Struct itu digunakan untuk mengelompokkan seluruh data yang dimiliki oleh seorang mahasiswa dalam satu kesatuan. Program juga memiliki function hitungNilaiAkhir() yang menerima tiga parameter, yaitu nilai UTS, UAS, dan tugas. Function tersebut mengembalikan hasil perhitungan menggunakan rumus 0.3 * uts + 0.4 * uas + 0.3 * tugas, sehingga nilai UTS memiliki bobot 30%, UAS 40%, dan tugas 30%

Selanjutnya, ada function main() sebagai titik masuk program. Di dalamnya, program mendeklarasikan array arrayMahasiswa bertipe Mahasiswa dengan kapasitas sebanyak TOTAL_MAHASISWA_MAKSIMAL, yaitu 10 elemen. Penulisan {} pada deklarasi array digunakan untuk menginisialisasi elemen-elemennya secara eksplisit dengan nilai awal. Variabel totalMahasiswa bertipe int juga dideklarasikan dengan nilai awal 0 untuk menyimpan total mahasiswa yang akan dimasukkan. Program kemudian meminta user memasukkan total mahasiswa melalui std::cin. Jika total tersebut < 1 atau > 10, program menampilkan pesan "Total mahasiswa tidak valid" dan statement return 1 dijalankan untuk mengakhiri program dengan adanya kegagalan

Jika total mahasiswa valid, program menjalankan perulangan for untuk memasukkan data setiap mahasiswa. Variabel iterasi i digunakan sebagai index array, dimulai dari 0 hingga totalMahasiswa - 1. Pada setiap iterasi, program meminta user memasukkan nama, NIM, nilai UTS, nilai UAS, dan nilai tugas. std::getline(std::cin >> std::ws, arrayMahasiswa[i].nama) digunakan untuk membaca nama secara utuh, termasuk nama yang mengandung spasi. Sementara itu, std::cin digunakan untuk membaca NIM, nilai UTS, nilai UAS, dan nilai tugas. Setelah seluruh data seorang mahasiswa dimasukkan, program memanggil function hitungNilaiAkhir() dan menyimpan hasilnya ke atribut nilaiAkhir milik mahasiswa tersebut

Setelah proses input selesai, program menampilkan judul "==== DATA MAHASISWA =====" dan menjalankan perulangan for kedua untuk menampilkan seluruh data mahasiswa yang telah disimpan. Pada setiap iterasi, program mengakses atribut mahasiswa melalui arrayMahasiswa[i], kemudian menampilkan nama, NIM, nilai UTS, nilai UAS, nilai tugas, dan nilai akhir menggunakan std::cout. std::endl digunakan untuk mengakhiri baris sekaligus memindahkan posisi output ke baris berikutnya. Setelah seluruh data ditampilkan, program menjalankan statement return 0 untuk menandakan bahwa program telah selesai dieksekusi dengan normal

### 2. Unguided 2: Abstract Data Type Pelajaran
Buatlah ADT pelajaran sebagai berikut di dalam file "pelajaran.h":
```text
Type pelajaran < 
    namaMapel : string
    kodeMapel : string
>
function create_pelajaran( namapel : string, kodepel : string ) → pelajaran 
procedure tampil_pelajaran( input pel : pelajaran ) 
```
Buatlah implementasi ADT pelajaran pada file "pelajaran.cpp". Cobalah hasil implementasi ADT pada file "main.cpp"
```C++
using namespace std;
int main(){
    string namapel = "Struktur Data";
    string kodepel = "STD";
    pelajaran pel = create_pelajaran(namapel,kodepel);
    tampil_pelajaran(pel);
    return 0; 
} 
```

**`pelajaran.h`**
```h
#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED

#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif
```

**`pelajaran.cpp`**
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran pel = {};
    pel.namaMapel = namapel;
    pel.kodeMapel = kodepel;
    return pel;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "Nama mata pelajaran: " << pel.namaMapel << endl;
    cout << "Kode mata pelajaran: " << pel.kodeMapel << endl;
}
```

**`main.cpp`**
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;
int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";
    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}
```

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/andikarofifsulistyawan/CAK2EAB4-praktikum-struktur-data/blob/main/Modul%2003/Unguided/Output/output-unguided2-1.png)

Program di atas merupakan implementasi abstract data type untuk merepresentasikan data mata pelajaran menggunakan tiga file, yaitu pelajaran.h sebagai header, pelajaran.cpp sebagai implementasi, dan main.cpp sebagai driver. Program menggunakan struct untuk mengelompokkan atribut mata pelajaran, function untuk membuat data mata pelajaran, serta prosedur untuk menampilkan data tersebut ke standard output atau terminal. Pemisahan kode ke dalam tiga file ini bertujuan untuk memisahkan deklarasi tipe data dan fungsi, implementasi fungsi, serta program utama

Pada file pelajaran.h, ada include guard yang terdiri dari #ifndef PELAJARAN_H_INCLUDED, #define PELAJARAN_H_INCLUDED, dan #endif. Bagian itu digunakan untuk mencegah header yang sama diproses berulang kali dalam satu proses kompilasi. Selanjutnya, direktif #include <string> digunakan agar program dapat menggunakan tipe data string untuk menyimpan teks. Ada pula statement using namespace std; supaya bisa menggunakan nama dari namespace std tanpa harus menuliskan awalan std::. Setelah itu, ada deklarasi struct pelajaran yang memiliki dua atribut, yaitu namaMapel dan kodeMapel, keduanya bertipe string. Struct tersebut digunakan untuk menyimpan nama dan kode mata pelajaran dalam satu kesatuan. File ini juga mendeklarasikan prototipe function create_pelajaran(string namapel, string kodepel) yang mengembalikan nilai bertipe pelajaran, serta prototipe prosedur tampil_pelajaran(pelajaran pel) yang digunakan untuk menampilkan data mata pelajaran

Pada file pelajaran.cpp, ada direktif #include <iostream> untuk menyediakan fasilitas output melalui cout dan #include "pelajaran.h" untuk menggunakan deklarasi tipe data serta prototipe subprogram yang telah dibuat pada file header. Function create_pelajaran() didefinisikan dengan dua parameter, yaitu namapel dan kodepel, yang masing-masing digunakan untuk menerima nama dan kode mata pelajaran. Di dalam function tersebut, variabel pel bertipe pelajaran dibuat dan diinisialisasi menggunakan {}. Selanjutnya, atribut pel.namaMapel diisi dengan nilai namapel, sedangkan atribut pel.kodeMapel diisi dengan nilai kodepel. Nilai pel tersebut kemudian dikembalikan ke pemanggil fungsinya melalui statement return pel. Setelah itu, ada prosedur tampil_pelajaran() yang menerima parameter pel bertipe pelajaran. Procedure tersebut menggunakan cout untuk menampilkan atribut namaMapel dan kodeMapel. endl digunakan untuk mengakhiri baris output dan berpindah ke baris berikutnya

Pada file main.cpp, ada direktif #include <iostream> dan #include "pelajaran.h" agar program dapat menggunakan fasilitas output serta deklarasi ADT pelajaran. Function main() menjadi titik masuk program. Di dalamnya, variabel namapel diinisialisasi dengan teks "Struktur Data", sedangkan variabel kodepel diinisialisasi dengan teks "STD". Kedua variabel tersebut kemudian diberikan sebagai argumen saat function create_pelajaran() dipanggil. Nilai yang dikembalikan oleh function tersebut disimpan ke dalam variabel pel bertipe pelajaran. Setelah data berhasil dibuat, program memanggil tampil_pelajaran(pel) untuk menampilkan nama dan kode mata pelajaran ke terminal. Terakhir, program berakhir dengan statement return 0 yang menandakan bahwa program telah selesai dijalankan secara normal

### 3. Unguided 3: Pertukaran Isi Array dan Variabel Melalui Pointer
Buatlah program dengan ketentuan :
- 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer
- fungsi/prosedur yang menampilkan isi sebuah array integer 2D
- fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu
- fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer

```C++
#include <iostream>

void tampilkanArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void tukarArray(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90}
    };

    int x = 100, y = 200;
    int *p1 = &x;
    int *p2 = &y;

    std::cout << "Array A:\n";
    tampilkanArray(A);

    std::cout << "\nArray B:\n";
    tampilkanArray(B);

    int baris, kolom;
    std::cout << "\nMasukkan posisi baris (0-2): ";
    std::cin >> baris;
    std::cout << "Masukkan posisi kolom (0-2): ";
    std::cin >> kolom;

    if (baris < 0 || baris > 2 || kolom < 0 || kolom > 2) {
        std::cout << "Posisi tidak valid!" << std::endl;
        return 1;
    }

    tukarArray(A, B, baris, kolom);

    std::cout << "\nArray A setelah pertukaran:\n";
    tampilkanArray(A);

    std::cout << "\nArray B setelah pertukaran:\n";
    tampilkanArray(B);

    std::cout << "\nSebelum pertukaran pointer: x = " << x << ", y = " << y << std::endl;
    tukarPointer(p1, p2);
    std::cout << "Setelah pertukaran pointer: x = " << x << ", y = " << y << std::endl;

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/andikarofifsulistyawan/CAK2EAB4-praktikum-struktur-data/blob/main/Modul%2003/Unguided/Output/output-unguided3-1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/andikarofifsulistyawan/CAK2EAB4-praktikum-struktur-data/blob/main/Modul%2003/Unguided/Output/output-unguided3-2.png)

##### Output 3
![Screenshot Output Unguided 3_3](https://github.com/andikarofifsulistyawan/CAK2EAB4-praktikum-struktur-data/blob/main/Modul%2003/Unguided/Output/output-unguided3-3.png)

Program di atas merupakan program untuk mengolah dua array dua dimensi berukuran 3x3 dan melakukan pertukaran nilai menggunakan pointer. Program memiliki tiga prosedur utama, yaitu tampilkanArray() untuk menampilkan elemen array, tukarArray() untuk menukar elemen pada posisi tertentu dari dua array, dan tukarPointer() untuk menukar nilai dua variabel melalui pointer. Program menggunakan array dua dimensi untuk menyimpan sekumpulan bilangan bulat dalam bentuk baris dan kolom, sedangkan pointer digunakan untuk mengakses dan mengubah nilai variabel melalui alamat memorinya

Pada bagian awal program, ada direktif #include <iostream> yang digunakan untuk menyediakan fasilitas input dan output melalui std::cin dan std::cout. Selanjutnya, program mendeklarasikan prosedur tampilkanArray(int arr[3][3]) yang menerima parameter berupa array dua dimensi berukuran 3x3. Di dalam prosedur tersebut, ada dua perulangan for bersarang. Perulangan pertama menggunakan variabel iterasi i untuk mengakses baris, sedangkan perulangan kedua menggunakan variabel iterasi j untuk mengakses kolom. Pada setiap iterasi, perintah std::cout << arr[i][j] << " " digunakan untuk menampilkan elemen array sesuai index. Setelah seluruh elemen pada satu baris ditampilkan, program mengeksekusi std::cout << std::endl untuk berpindah ke baris berikutnya

Selanjutnya, ada prosedur tukarArray(int arr1[3][3], int arr2[3][3], int baris, int kolom) yang digunakan untuk menukar elemen dari dua array pada posisi yang sama. Parameter arr1 dan arr2 merupakan dua array yang akan diproses, sedangkan baris dan kolom menentukan posisi elemen yang akan ditukar. Di dalam prosedur tersebut, ada variabel temp bertipe int digunakan untuk menyimpan sementara nilai arr1[baris][kolom]. Setelah itu, nilai elemen arr2[baris][kolom] disalin ke arr1[baris][kolom], kemudian nilai yang sebelumnya disimpan dalam temp dimasukkan ke arr2[baris][kolom]

Setelah itu, ada prosedur tukarPointer(int *p1, int *p2) yang digunakan untuk menukar nilai dua variabel melalui pointer. Parameter p1 dan p2 bertipe pointer to integer, yang berarti keduanya dapat menyimpan alamat memori dari variabel bertipe int. Di dalam prosedur tersebut, kita menggunakan operator dereference, yakni *, seperti pada *p1 dan *p2, untuk mengakses nilai yang berada pada alamat memori yang ditunjuk oleh masing-masing pointer. Nilai yang ditunjuk oleh p1 terlebih dahulu disimpan ke dalam variabel sementara temp. Selanjutnya, nilai yang ditunjuk oleh p2 diberikan kepada variabel yang ditunjuk oleh p1, kemudian nilai temp diberikan kepada variabel yang ditunjuk oleh p2. Dengan demikian, kedua nilai berhasil ditukar tanpa kehilangan nilai awalnya

Selanjutnya, ada function main() sebagai titik masuk program. Di dalamnya, program mendeklarasikan dua array dua dimensi, yaitu A dan B, yang masing-masing berukuran 3x3 dan diinisialisasi dengan nilai tertentu. Array A berisi bilangan dari 1 sampai 9, sedangkan array B berisi bilangan 10, 20, 30, ..., 90. Program juga mendeklarasikan variabel integer x dan y dengan nilai awal masing-masing 100 dan 200. Setelah itu, pointer p1 diinisialisasi menggunakan alamat variabel x melalui operator &, sedangkan p2 diinisialisasi menggunakan alamat variabel y. Operator & digunakan untuk memperoleh alamat memori suatu variabel

Program kemudian menampilkan array A dan B dengan memanggil prosedur tampilkanArray() untuk masing-masing array. Setelah kedua array ditampilkan, program meminta pengguna memasukkan posisi baris dan kolom yang ingin ditukar. Variabel baris dan kolom digunakan untuk menyimpan posisi tersebut. Program melakukan validasi untuk memastikan kedua index berada dalam rentang 0 sampai 2, sesuai dengan ukuran array. Jika salah satu index berada di luar rentang tersebut, program menampilkan pesan "Posisi tidak valid!" dan menjalankan statement return 1 untuk mengakhiri program dengan status kegagalan. Jika posisi valid, program memanggil tukarArray(A, B, baris, kolom) untuk menukar elemen pada posisi yang ditentukan. Setelah pertukaran selesai, kedua array ditampilkan kembali menggunakan prosedur tampilkanArray() agar perubahan nilainya dapat dilihat

Pada bagian akhir, program menampilkan nilai awal variabel x dan y sebelum pertukaran pointer dilakukan. Selanjutnya, program memanggil prosedur tukarPointer(p1, p2) untuk menukar nilai kedua variabel melalui pointer yang telah menyimpan alamatnya. Setelah prosedur tersebut selesai dijalankan, program kembali menampilkan nilai x dan y. Karena pointer menunjuk ke variabel asli, pertukaran nilai melalui *p1 dan *p2 menyebabkan nilai variabel x dan y benar-benar berubah, bukan sekadar menukar salinan nilainya. Terakhir, program berakhir dengan return 0 yang menandakan bahwa program telah selesai dijalankan secara normal

## Kesimpulan
Abstract data type bisa digunakan untuk mengelompokkan data dan operasi yang berkaitan. Struct memungkinkan beberapa atribut dengan tipe berbeda disimpan dalam satu tipe data bentukan. Pemisahan deklarasi dan implementasi ke dalam file header, implementasi, dan program utama atau driver membantu membuat program C++ lebih terstruktur

## Referensi
[1] Sofa, M. M. F., & Prasetya, R. I. (2025). Sistem Manajemen Nilai Mahasiswa Berbasis Konsol Menggunakan C++: Pendekatan Prosedural Tipe Data Abstrak. Jurnal Aplikasi Teknologi dan Komputasi, 1(4), 38–48. https://www.journals.arces.org/jatekom/article/view/191/0<br/>
[2] Putri, G. M., Pradja, K. A. D., Azizi, M. B. M., Nurwahid, P., Perdana, A. S., & Munawir. (2024). Implementasi Stack dan Array pada Pengurutan Lagu dengan Metode Selection Sort. Jurnal Teknologi dan Sistem Informasi Bisnis, 6(2), 286–296. https://doi.org/10.47233/jteksis.v6i2.1192<br/>