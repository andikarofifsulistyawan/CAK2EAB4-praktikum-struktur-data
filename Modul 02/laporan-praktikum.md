# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahasa C++ (Bagian Kedua)</h1>
<p align="center">Andika Rofif Sulistyawan - 109082500013</p>

## Dasar Teori

### A. Array<br/>

Array merupakan kumpulan data dengan ukuran maksimal tertentu dengan nama yang sama dan setiap elemennya mempunyai tipe data yang sama. Setiap elemen dalam array dapat diakses berdasarkan indeksnya. Dalam C++, penyimpanan elemen array dilakukan pada lokasi memori yang berurutan. Elemen pertama menggunakan indeks `0`, kemudian dilanjutkan dengan indeks `1`, `2`, dan seterusnya. Dengan demikian, array dengan 5 elemen mempunyai indeks dari `0` sampai `4`. Bentuk umum deklarasi array adalah `tipe_data nama_variabel[ukuran]`, misalnya `int nilai[10]` untuk membuat array yang dapat menyimpan 10 elemen bertipe integer

#### 1. Array Satu Dimensi

Array satu dimensi merupakan array yang hanya mempunyai satu larik data. Setiap elemen diakses menggunakan satu indeks dengan bentuk `nama_variabel[indeks]`. Indeks digunakan untuk menunjukkan posisi suatu elemen dalam array, sehingga akses terhadap data dapat dilakukan secara langsung. Karena indeks array dimulai dari `0`, maka elemen ke-`n` mempunyai indeks `n-1`. Array satu dimensi dapat digunakan untuk menyimpan berbagai jenis data selama seluruh elemennya mempunyai tipe data yang sama, seperti `int`, `float`, `char`, dan tipe data lainnya. Pada implementasinya, array satu dimensi juga dapat diproses menggunakan perulangan untuk membaca, mengisi, mencari, maupun mengolah setiap elemennya

#### 2. Array Dua Dimensi

Array dua dimensi mempunyai dua indeks yang digunakan untuk menunjukkan posisi data berdasarkan baris dan kolom. Bentuk array ini menyerupai tabel sehingga sering digunakan untuk merepresentasikan data yang mempunyai struktur baris dan kolom, termasuk matriks. Deklarasi array dua dimensi dapat dituliskan dalam bentuk `tipe_data nama_variabel[ukuran_baris][ukuran_kolom]`. Sebagai contoh, `int data_nilai[4][3]` merupakan array bertipe integer yang memiliki 4 baris dan 3 kolom. Pengaksesan elemen dilakukan dengan dua indeks, seperti `data_nilai[2][0]`. Dalam C++, elemen array multidimensi disusun pada penyimpanan linear dan pengaksesan indeks tertentu diterjemahkan menjadi perhitungan alamat memori berdasarkan ukuran tipe data dan posisi indeks [1]

#### 3. Array Berdimensi Banyak

Array berdimensi banyak merupakan array yang mempunyai lebih dari dua indeks. Banyaknya indeks yang digunakan menunjukkan dimensi array tersebut. Bentuk umum deklarasinya adalah `tipe_data nama_variabel[ukuran1][ukuran2]...[ukuranN]`. Sebagai contoh, `int data_rumit[4][6][6]` merupakan array dengan tiga dimensi. Array seperti ini dapat digunakan ketika data mempunyai struktur yang membutuhkan lebih dari dua tingkat pengelompokan. Semakin banyak dimensi yang digunakan, semakin kompleks pula cara merepresentasikan dan mengakses data tersebut

### B. Data, Memori, dan Alamat Memori<br/>

#### 1. Data dan Memori

Semua data yang digunakan oleh program komputer disimpan di dalam memori komputer. Memori dapat dibayangkan sebagai kumpulan lokasi penyimpanan yang masing-masing mempunyai alamat unik. Ketika sebuah variabel, objek, atau array dibuat, sistem operasi menyediakan ruang memori untuk menyimpan data tersebut. Lokasi memori yang diperoleh setiap variabel tidak harus berurutan dengan variabel lain karena penempatannya bergantung pada kondisi dan pengelolaan memori oleh sistem operasi

#### 2. Operator Alamat

Alamat memori suatu variabel dapat diperoleh menggunakan operator `&` yang ditempatkan di depan nama variabel. Hasil dari operator tersebut berupa alamat tempat variabel berada di memori. Sebagai contoh, `&a` digunakan untuk mendapatkan alamat memori dari variabel `a`. Operator yang sama juga dapat digunakan pada elemen array, misalnya `&(arr[4])`, untuk memperoleh alamat memori elemen array pada indeks tertentu

### C. Pointer<br/>

Pointer merupakan alamat bertipe yang memungkinkan programmer mengakses elemen array melalui alamat memori maupun melalui indeks [1]. Dalam kata lain, pointer merupakan variabel yang digunakan untuk menyimpan alamat memori variabel lain. Pointer mempunyai tipe data tertentu sehingga menunjukkan jenis data yang dirujuk, misalnya `int *p` merupakan pointer yang digunakan untuk menunjuk data bertipe integer. Deklarasi pointer secara umum dituliskan dalam bentuk `type *nama_variabel`. Setelah pointer diberikan alamat suatu variabel, pointer tersebut dapat digunakan untuk mengakses nilai variabel yang ditunjuk.

#### 1. Operator Dereference

Agar nilai dari variabel yang ditunjuk oleh pointer dapat diperoleh, digunakan operator `*` di depan nama pointer. Operator tersebut disebut operator dereference. Misalnya, apabila `p` menyimpan alamat variabel `x`, maka `*p` menghasilkan nilai yang terdapat pada alamat tersebut. Sementara itu, `p` sendiri menyimpan alamat memori, bukan nilai dari variabel yang ditunjuk. Pointer juga merupakan sebuah variabel sehingga pointer mempunyai ruang memori dan alamatnya sendiri

#### 2. Pointer dan Array

Array dan pointer mempunyai hubungan yang erat karena alamat elemen array dapat direpresentasikan menggunakan pointer. Jika sebuah pointer menunjuk ke elemen pertama suatu array, penambahan nilai pada pointer dapat digunakan untuk menunjuk ke elemen array berikutnya. Misalnya, apabila `p` menunjuk ke `a[0]`, maka `*(p + 1)` merujuk pada `a[1]`, sedangkan `*(p + i)` merujuk pada `a[i]`. Dalam C++, elemen array dapat diakses baik menggunakan indeks maupun pointer arithmetic [1]. Akses menggunakan pointer dan indeks merupakan dua pendekatan yang dapat digunakan untuk elemen array, meskipun kecepatan keduanya tidak selalu menunjukkan perbedaan yang konsisten pada berbagai kondisi [1]

### D. Character dan String<br/>

#### 1. Character

Tipe data `char` digunakan untuk menyimpan satu karakter. Dalam C++, beberapa karakter dapat ditempatkan secara berurutan di dalam array bertipe `char`. Karena setiap elemen array hanya menyimpan satu karakter, pengaksesan karakter dilakukan menggunakan indeks seperti pada array satu dimensi

#### 2. String

String merupakan bentuk data yang digunakan untuk mengolah teks atau kalimat. Dalam pembahasan string berbasis `char`, string pada dasarnya merupakan array karakter yang diakhiri dengan karakter null `'\0'`. Karakter null tersebut berfungsi sebagai penanda akhir string. String juga dapat diinisialisasi langsung, misalnya `char nama[] = "strukdat"`

### E. Subprogram<br/>

#### 1. Function

Function merupakan subprogram yang dirancang untuk menjalankan tugas tertentu dan mengembalikan nilai tertentu. Penggunaan function membuat program lebih terstruktur karena bagian program yang kompleks dapat dipecah menjadi bagian-bagian yang lebih kecil. Function juga dapat mengurangi pengulangan kode karena satu function dapat dipanggil berkali-kali ketika tugas yang sama diperlukan. Secara umum, function dituliskan dalam bentuk `tipe_keluaran nama_function(daftar_parameter) { blok_pernyataan; }`. Function dapat menerima masukan melalui parameter dan dapat menghasilkan nilai balik melalui keyword `return`. Dalam C++, function merupakan bagian penting dari pemrograman prosedural yang digunakan untuk memisahkan operasi tertentu menjadi unit yang dapat dipanggil kembali, menerima parameter, dan secara opsional mengembalikan nilai [2]

#### 2. Prototype Function

Prototype function merupakan deklarasi function yang dituliskan sebelum function tersebut dipanggil. Prototype memberikan informasi kepada compiler mengenai nama function, tipe nilai balik, serta parameter yang diterima. Contohnya adalah `int maks3(int a, int b, int c)`. Dengan adanya prototype, compiler mengetahui bahwa terdapat function bernama `maks3` yang menerima tiga parameter bertipe integer dan mengembalikan nilai bertipe integer. Badan function kemudian dapat dituliskan setelah `main()` atau pada bagian lain sesuai dengan struktur program

#### 3. Prosedur

Dalam C++, istilah prosedur digunakan untuk menyebut subprogram yang tidak mengembalikan nilai dan dinyatakan menggunakan tipe `void`. Prosedur tetap dapat menerima parameter dan menjalankan sejumlah perintah, tetapi tidak memberikan nilai balik kepada pemanggil. Bentuk umum prosedur adalah `void nama_prosedur(daftar_parameter) { blok_pernyataan; }`. Dalam pemrograman prosedural, function digunakan sebagai unit kode yang dapat dipanggil untuk melaksanakan operasi tertentu, sementara nilai balik tidak selalu diperlukan [2]

### F. Parameter Subprogram<br/>

#### 1. Parameter Formal dan Parameter Aktual

Parameter formal merupakan variabel yang terdapat pada daftar parameter ketika sebuah subprogram didefinisikan. Sebagai contoh, pada function `maks3(int a, int b, int c)`, variabel `a`, `b`, dan `c` merupakan parameter formal. Sementara itu, parameter aktual merupakan nilai, variabel, konstanta, atau ekspresi yang dikirimkan saat subprogram dipanggil. Parameter berfungsi sebagai media untuk memberikan data dari bagian program yang memanggil subprogram kepada subprogram yang dipanggil

#### 2. Call by Value

Call by value merupakan cara melewatkan parameter dengan menyalin nilai dari parameter aktual ke parameter formal. Dengan metode ini, perubahan yang dilakukan terhadap parameter formal tidak mengubah nilai variabel yang digunakan sebagai parameter aktual. Hal tersebut terjadi karena subprogram bekerja menggunakan salinan nilai, bukan langsung menggunakan variabel aslinya. Dengan demikian, metode ini sesuai digunakan ketika data hanya diperlukan sebagai masukan dan tidak perlu diubah oleh subprogram

#### 3. Call by Pointer

Call by pointer merupakan cara melewatkan parameter dengan mengirimkan alamat memori suatu variabel ke dalam subprogram. Parameter subprogram dideklarasikan sebagai pointer, misalnya `void tukar(int *x, int *y)`, kemudian alamat variabel dikirim saat pemanggilan menggunakan operator `&`, seperti `tukar(&a, &b)`. Nilai variabel yang ditunjuk kemudian diakses menggunakan operator dereference `*`. Karena subprogram memperoleh alamat variabel asli, perubahan terhadap data yang ditunjuk dapat langsung mengubah variabel tersebut

#### 4. Call by Reference

Call by reference merupakan cara melewatkan parameter dengan menggunakan reference sehingga parameter formal merujuk langsung pada variabel yang diberikan saat subprogram dipanggil. Parameter formal dideklarasikan menggunakan tanda `&`, misalnya `void tukar(int &x, int &y)`. Berbeda dengan call by pointer, pemanggilan subprogram dengan call by reference tidak memerlukan operator `&` pada parameter aktual sehingga dapat dilakukan dengan bentuk `tukar(a, b)`. Perubahan terhadap parameter reference akan langsung memengaruhi variabel aktual yang dirujuk. Dalam C++, mekanisme subprogram dan parameter seperti ini merupakan bagian dari dukungan bahasa terhadap pemrograman prosedural dan pengolahan data melalui subprogram [2]

## Guided 

### 1. Array Satu Dimensi

```C++
#include <iostream>
using namespace std;

int main() {
    int nilai[5];

    nilai[0] = 80;
    nilai[1] = 85;
    nilai[2] = 90;
    nilai[3] = 75;
    nilai[4] = 95;

    for (int i = 0; i < 5; i++) {
        cout << "index ke-" << i << " = " << nilai[i] << endl;
    }

    return 0;
}
```
Program di atas adalah program yang digunakan untuk menyimpan lima nilai ke dalam array satu dimensi, yaitu 80, 85, 90, 75, dan 95, kemudian menampilkan setiap nilai beserta indeksnya ke standard output atau terminal. Pertama, program mendeklarasikan variabel `nilai` bertipe array of `int` dengan ukuran 5 sehingga array memiliki indeks 0 sampai 4. Setiap elemen kemudian diisi secara langsung menggunakan `nilai[0]` hingga `nilai[4]`. Setelah itu, program menggunakan perulangan `for` dengan variabel `i` sebagai indeks yang dimulai dari 0 dan berjalan selama `i < 5`. Pada setiap iterasi, program mencetak string `"index ke-"`, nilai variabel iterasi `i`, string `" = "`, dan nilai elemen `nilai[i]`

### 2. Array Dua Dimensi

```C++
#include <iostream>
using namespace std;

int main() {
    int nilai[3][3] = {
        {80, 85, 90},
        {75, 80, 85},
        {90, 95, 100}
    };

    // for (int i = 0; i < 3; i++) {
    //     for (int j = 0; j < 3; j++) {
    //         cout << nilai[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << nilai[0][0] << endl; //80
    cout << nilai[1][1] << endl; //80
    cout << nilai[2][2] << " "; //100

    return 0;
}
```
Program di atas adalah program yang digunakan untuk mendeklarasikan dan mengakses sebuah array dua dimensi berukuran 3x3 yang berisi bilangan-bilangan bulat. Array tersebut memiliki tiga baris dan tiga kolom, dengan setiap elemen diakses menggunakan dua indeks, yaitu indeks baris dan indeks kolom. Program kemudian secara langsung mengakses tiga elemen, yaitu `nilai[0][0]` yang bernilai 80, `nilai[1][1]` yang bernilai 80, dan `nilai[2][2]` yang bernilai 100, lalu menampilkannya ke standard output atau terminal menggunakan `cout`. Bagian kode yang dikomentari sebenarnya digunakan untuk menampilkan seluruh isi array dengan dua perulangan `for`, tetapi pada program ini bagian tersebut tidak dijalankan

### 3. Array Tiga Dimensi

```C++
#include <iostream>
using namespace std;

int main() {
    int data[2][3][3] {
        {
            {1,2,3},
            {4,5,6},
            {7,8,9}
        },
        {
            {10,11,12},
            {13,14,15},
            {16,17,18}
        }
    };

    // for (int i = 0; i < 2; i++) {
    //     for (int j = 0; j < 3; j++) {
    //         for (int k = 0; k < 3; k++) {
    //             cout << data[i][j][k] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }

    cout << data[0][1][1] << " "; // 5

    return 0;
}
```
Program di atas adalah program yang digunakan untuk mendeklarasikan dan mengakses array berdimensi banyak (tepatnya berdimensi tiga), yaitu array data berukuran 2x3x3. Array tersebut mempunyai tiga indeks yang masing-masing digunakan untuk mengakses dimensi pertama, dimensi kedua, dan dimensi ketiga. Data kemudian diisi dengan bilangan 1 sampai 18 dan dapat diakses menggunakan bentuk `data[i][j][k]`. Pada program ini, bagian perulangan `for` yang dikomentari sebenarnya digunakan untuk menampilkan seluruh isi array dengan tiga tingkat perulangan, tetapi tidak dijalankan. Program hanya mengakses `data[0][1][1]`, yakni elemen pada indeks dimensi pertama 0, dimensi kedua 1, dan dimensi ketiga 1, sehingga nilai yang ditampilkan adalah 5

### 4. Array Empat Dimensi

```C++
#include <iostream>
using namespace std;

int main() {
    int data[2][2][2][2] = {
        {
            {
                {1,2},
                {3,4}
            },
            {
                {5,6},
                {7,8}
            }
        },
        {
            {
                {9,10},
                {11,12}
            },
            {
                {13,14},
                {15,16}
            }
        }
    };

    cout << data[0][0][0][0] << endl; // 1
    cout << data[1][1][1][1] << endl; // 16

    return 0;
}
```
Program di atas adalah program yang digunakan untuk mendeklarasikan dan mengakses array berdimensi banyak dengan empat dimensi, yaitu data berukuran 2x2x2x2. Array tersebut memiliki empat indeks yang digunakan untuk menentukan posisi suatu elemen dalam setiap dimensinya. Data di dalam array diisi dengan bilangan 1 sampai 16, kemudian program secara langsung mengakses dua elemen, yaitu `data[0][0][0][0]` yang menghasilkan nilai 1 dan `data[1][1][1][1]` yang menghasilkan nilai 16, lalu keduanya ditampilkan menggunakan `cout`. Karena indeks array dalam C++ dimulai dari 0, indeks terbesar pada setiap dimensi adalah 1 karena masing-masing dimensi berukuran 2

### 5. Value & Memory Address

```C++
#include <iostream>
using namespace std;

int main() {
    char a;
    int j;
    char arr[6];

    arr[3] = 'b';
    a = 'u';
    j = 10;

    cout << a << endl; //u
    cout << &a << endl; //alamat memory atau address

    cout << j << endl; //10
    cout << &j << endl; //alamat memory atau addresss

    cout << arr[3] << endl; //value
    cout << &(arr[4]) << endl; //alamat memory atau address

    return 0;
}
```
Program di atas adalah program yang digunakan untuk mendeklarasikan beberapa variabel dengan tipe data `char`, `int`, dan array of `char`, kemudian menyimpan nilai ke dalam variabel-variabel tersebut dan menampilkan nilai maupun alamat memorinya. Variabel `a` bertipe `char` diberi nilai `'u'`, variabel `j` bertipe `int` diberi nilai `10`, sedangkan variabel `arr` bertipe array of `char` memiliki 6 elemen, dan elemen pada indeks 3 diberi nilai `'b'`. Program kemudian menampilkan nilai variabel `a`, alamat memori variabel `a`, nilai variabel `j`, alamat memori variabel `j`, nilai `arr[3]`, dan alamat memori `arr[4]`. Operator `&` yang digunakan sebelum nama variabel atau elemen array berfungsi untuk mendapatkan alamat memori tempat data tersebut disimpan

### 6. Pointer

```C++
#include <iostream>
using namespace std;

int main() {
    int x, y;
    int *px;

    x = 87;
    px = &x;
    y = *px;

    cout << "Alamat x = " << &x << endl;
    cout << "Isi px = " << px << endl;
    cout << "Isi x = " << x << endl;
    cout << "Nilai yang ditunjuk px = " << *px << endl;
    cout << "Nilai y = " << y << endl;

    return 0;
}
```
Program di atas adalah program yang digunakan untuk memperkenalkan penggunaan pointer dalam C++, yaitu dengan menyimpan alamat memori suatu variabel dan mengakses nilai variabel tersebut melalui pointer. Program mendeklarasikan variabel `x` dan `y` bertipe `int` serta pointer `px` yang bertipe `int *`. Variabel `x` kemudian diberi nilai 87, lalu `px` diberi nilai alamat memory `x`, lalu `y` diberi nilai berupa nilai yang ditunjuk pointer `px`, sehingga `y` mendapatkan nilai 87. Program kemudian menampilkan alamat memori `x` menggunakan `&x`, lalu menampilkan isi pointer `px` yang juga berupa alamat memori `x`, lalu menampilkan nilai `x`, lalu menampilkan nilai yang ditunjuk oleh `px` menggunakan `*px`, lalu menampilkan nilai `y`. Dengan demikian, program menunjukkan bahwa `&x` dan `px` menghasilkan alamat yang sama, sedangkan `x`, `*px`, dan `y` menghasilkan nilai yang sama, yaitu 87

### 7. Array Satu Dimensi dan Dua Dimensi

```C++
#include <iostream>
#define MAX 5
using namespace std;

int main() {
    int i, j;
    float nilai_total, rata_rata;
    float nilai[MAX];

    static int nilai_tahun[MAX][MAX] = {
        {0,2,2,0,0},
        {0,1,1,1,0},
        {0,3,3,3,0},
        {4,4,0,0,4},
        {5,0,0,0,5}
    };

    // inisialisasi array satu dimensi
    for (i = 0; i < MAX; i++) {
        cout << "masukkkan nilai ke-" << i + 1 << endl;
        cin >> nilai[i];
    }

    cout << "\ndata nilai siswa:\n";

    // menampilkan array satu dimensi
    for (i = 0; i < MAX; i++) {
        cout << "nilai k-" << i + 1 << "=" << nilai[i] << endl;
    }

    cout << "\nnilai tahunan : \n";

    // meanmpilkan array dua dimensi
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            cout << nilai_tahun[i][j];
        }

        cout << "\n";
    }

    return 0;
}
```
Program di atas adalah program yang digunakan untuk membaca dan menampilkan data menggunakan dua jenis array, yaitu array satu dimensi dan array dua dimensi. Ada direktif `#define MAX 5` yang mendefinisikan `MAX` sebagai konstanta 5. Ada variabel `i` dan `j` bertipe `int` digunakan sebagai variabel iterasi, sedangkan `nilai_total` dan `rata_rata` dideklarasikan sebagai variabel `float`, tetapi tidak digunakan dalam program ini. Ada pula variabel `nilai` bertipe array of `float` dengan ukuran MAX, yaitu 5 elemen, dan variabel `nilai_tahun` bertipe array of `int` dengan MAX baris dan MAX kolom, yaitu 5 baris dan 5 kolom. Array `nilai` kemudian diisi dengan lima nilai dari user menggunakan perulangan `for` dan statement `cin >> nilai[i]`, lalu seluruh elemennya ditampilkan kembali dengan perulangan `for`. Sementara itu, array `nilai_tahun` sudah diinisialisasi dengan nilai saat deklarasi, kemudian ditampilkan menggunakan dua perulangan `for`, dengan `i` digunakan untuk mengakses baris dan `j` untuk mengakses kolom

### 8. Character & String

```C++
#include <iostream>
using namespace std;

int main() {
    char nama[] = "strukdat";

    cout << nama << endl;
    cout << nama[3] << endl;

    return 0;
}
```
Program di atas adalah program yang digunakan untuk mendeklarasikan dan menampilkan data bertipe string menggunakan array of `char`. Ada variabel `nama` yang dideklarasikan sebagai array of `char` dan diinisialisasi dengan string `"strukdat"`, sehingga setiap karakter disimpan sebagai elemen array dan diakhiri dengan karakter null `'\0'`. Lalu, statement `cout << nama` digunakan untuk menampilkan seluruh isi string, sedangkan `cout << nama[3]` digunakan untuk mengakses dan menampilkan karakter pada indeks 3, yaitu karakter `u`. Karena indeks array dimulai dari 0, karakter-karakter dalam string `"strukdat"` berada pada indeks 0 hingga 7

### 9. Function

```C++
#include <iostream>
using namespace std;

int maks3(int a, int b, int c);

int main() {
    int x,y,z;
    cout << "masukkan nilai bilangan ke-1 = ";
    cin >> x;
    cout << "masukkan nilai bilangan ke-2 = ";
    cin >> y;
    cout << "masukkan nilai bilangan ke-3 = ";
    cin >> z;
    cout << "nilai maksimumnya adalah = " << maks3(x,y,z);
    return 0;
}

int maks3(int a, int b, int c) {
    int temp_max = a;
    if (b > temp_max) {
        temp_max = b;
    }
    if (c > temp_max) {
        temp_max = c;
    }
    return temp_max;
}
```
Program di atas adalah program yang digunakan untuk mencari nilai terbesar dari tiga bilangan yang dimasukkan oleh user dengan memanfaatkan sebuah function bernama `maks3()`. Di dalam function `main()`, program mendeklarasikan variabel `x`, `y`, dan `z` untuk menyimpan tiga bilangan yang di-input melalui `cin`, kemudian memanggil `maks3(x, y, z)` untuk mendapatkan nilai maksimum dan menampilkannya menggunakan `cout`. Sebelum function `main()`, ada prototype `int maks3(int a, int b, int c)` yang memberi tahu compiler bahwa terdapat function `maks3()` yang menerima tiga parameter integer dan mengembalikan nilai integer. Di dalam function tersebut, variabel `temp_max` pertama kali diberi nilai `a` sebagai nilai maksimum sementara, kemudian `b` dan `c` masing-masing dibandingkan dengan `temp_max`. Jika salah satunya lebih besar, nilai `temp_max` diperbarui dengan nilai yang lebih besar tersebut. Setelah semua nilai diperiksa, function mengembalikan nilai `temp_max`

### 10. Prosedur

```C++
#include <iostream>
using namespace std;

void tulis(int x);

int main() {
    int jum;
    cout << "jumlah baris kata = ";
    cin >> jum;
    tulis(jum);
    return 0;
}

void tulis(int x) {
    for (int i = 0; i < x; i++) {
        cout << "baris ke-" << i + 1 << endl;
    }
}
```
Program di atas adalah program yang digunakan untuk mencetak sejumlah baris kata berdasarkan jumlah yang dimasukkan oleh user dengan memanfaatkan prosedur bernama `tulis()`. Di dalam function `main()`, variabel `jum` digunakan untuk menyimpan jumlah baris yang di-input user melalui `cin`, kemudian nilai tersebut dikirim sebagai parameter aktual untuk `x` ke prosedur `tulis()`. Prototype `void tulis(int x)` digunakan untuk mendeklarasikan prosedur yang menerima parameter integer `x`. Di dalam prosedur `tulis()`, ada perulangan `for` menggunakan variabel `i` yang dimulai dari 0 dan berjalan selama `i < x`. Setiap iterasi mencetak string `"baris ke-"` diikuti `i + 1`, sehingga nomor baris dimulai dari 1 hingga jumlah yang dimasukkan user

### 11. Parameter & Cara Memberikan Nilai Parameter

```C++
#include <iostream>
using namespace std;

// 1. Call by Value: variabel asli TIDAK berubah
void tukarValue(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

// 2. Call by Pointer: variabel asli IKUT berubah (pakai *)
void tukarPointer(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// 3. Call by Reference: variabel asli IKUT berubah (pakai &)
void tukarReference(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 4, b = 6;

    // Tes call by value
    tukarValue(a, b);
    cout << "Setelah Call by Value      -> a = " << a << ", b = " << b << " (Tetap)" << endl;

    // Tes call by pointer (kirim alamatnya pakai &)
    tukarPointer(&a, &b);
    cout << "Setelah Call by Pointer    -> a = " << a << ", b = " << b << " (Berubah!)" << endl;

    // Tes call by reference (mengembalikan posisi semula)
    tukarReference(a, b);
    cout << "Setelah Call by Reference  -> a = " << a << ", b = " << b << " (Berubah lagi!)" << endl;

    return 0;
}
```
Program di atas adalah program yang digunakan untuk membandingkan tiga cara melewatkan parameter pada subprogram dalam C++, yaitu call by value, call by pointer, dan call by reference, dengan contoh pertukaran nilai dua variabel `a` dan `b`. Program mempunyai tiga prosedur, yaitu `tukarValue()`, `tukarPointer()`, dan `tukarReference()`, yang masing-masing menggunakan cara pengiriman parameter yang berbeda. Pada prosedur `tukarValue(int x, int y)`, nilai `a` dan `b` hanya disalin ke parameter `x` dan `y`, sehingga pertukaran yang dilakukan di dalam prosedur tidak mengubah nilai variabel asli. Pada prosedur `tukarPointer(int *x, int *y)`, alamat memori variabel `a` dan `b` dikirim menggunakan operator `&`, kemudian nilai variabel asli diakses menggunakan operator `*`, sehingga pertukaran di dalam prosedur mengubah nilai variabel `a` dan `b`. Sementara itu, pada prosedur `tukarReference(int &x, int &y)`, parameter `x` dan `y` merupakan reference yang merujuk langsung pada variabel asli, sehingga perubahan di dalam prosedur juga mengubah `a` dan `b`. Di dalam function `main()`, nilai awal `a = 4` dan `b = 6` terlebih dahulu dikirim ke prosedur `tukarValue(a, b)`, sehingga nilainya tetap `4` dan `6`. Kemudian, prosedur `tukarPointer(&a, &b)` menukar nilainya menjadi `6` dan `4`. Setelah itu, prosedur `tukarReference(a, b)` menukar kembali nilainya menjadi `4` dan `6`

## Unguided 

### 1. Operasi Matriks 3x3

Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3 

```C++
#include <iostream>
const int MAX_BARIS = 3;
const int MAX_KOLOM = 3;

int main() {
    int A[MAX_BARIS][MAX_KOLOM] = {0};
    int B[MAX_BARIS][MAX_KOLOM] = {0};

    std::cout << "Masukkan matrix A:" << std::endl;
    for (int i = 0; i < MAX_BARIS; i++) {
        for (int j = 0; j < MAX_KOLOM; j++) {
            std::cin >> A[i][j];
        }
    }
    std::cout << std::endl;
    
    std::cout << "Masukkan matrix B:" << std::endl;
    for (int i = 0; i < MAX_BARIS; i++) {
        for (int j = 0; j < MAX_KOLOM; j++) {
            std::cin >> B[i][j];
        }
    }
    std::cout << std::endl;
    
    std::cout << "A + B:" << std::endl;
    for (int i = 0; i < MAX_BARIS; i++) {
        for (int j = 0; j < MAX_KOLOM; j++) {
            std::cout << A[i][j] + B[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    
    std::cout << "A - B:" << std::endl;
    for (int i = 0; i < MAX_BARIS; i++) {
        for (int j = 0; j < MAX_KOLOM; j++) {
            std::cout << A[i][j] - B[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    
    std::cout << "A * B:" << std::endl;
    for (int i = 0; i < MAX_BARIS; i++) {
        for (int j = 0; j < MAX_KOLOM; j++) {
            int hasil = 0;
            for (int k = 0; k < MAX_KOLOM; k++) {
                hasil += A[i][k] * B[k][j];
            }
            std::cout << hasil << " ";
        }
        std::cout << std::endl;
    }
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/andikarofifsulistyawan/CAK2EAB4-praktikum-struktur-data/blob/main/Modul%2002/Unguided/Output/output-unguided1-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/andikarofifsulistyawan/CAK2EAB4-praktikum-struktur-data/blob/main/Modul%2002/Unguided/Output/output-unguided1-2.png)

##### Output 3
![Screenshot Output Unguided 1_3](https://github.com/andikarofifsulistyawan/CAK2EAB4-praktikum-struktur-data/blob/main/Modul%2002/Unguided/Output/output-unguided1-3.png)

Program di atas adalah program yang membaca dua buah matriks berukuran 3 x 3 dari user, yaitu matriks A dan matriks B, kemudian melakukan tiga operasi terhadap kedua matriks tersebut, yaitu penjumlahan, pengurangan, dan perkalian matriks. Setelah setiap operasi selesai dilakukan, program akan mencetak hasil operasi tersebut ke standard output atau dalam hal ini adalah terminal komputer. Program menggunakan array dua dimensi untuk merepresentasikan matriks, karena array dua dimensi dapat digunakan untuk menyimpan data dalam bentuk tabel dengan dua indeks, yaitu indeks baris dan indeks kolom

Di baris pertama, ada direktif `#include <iostream>`, yang berarti program menggunakan header `iostream` dari standard library C++. Header tersebut menyediakan berbagai fasilitas untuk melakukan input dan output berbasis teks, seperti `std::cin` untuk membaca input dari user dan `std::cout` untuk menampilkan output ke standard output. Tanpa `#include <iostream>`, program tidak dapat menggunakan `std::cin` dan `std::cout`. Setelah itu, terdapat deklarasi dua buah konstanta menggunakan keyword `const`, yaitu `MAX_BARIS` dan `MAX_KOLOM`. Konstanta `MAX_BARIS` diberi nilai `3`, yang digunakan untuk menyatakan banyaknya baris maksimal matriks, sedangkan konstanta `MAX_KOLOM` juga diberi nilai `3`, yang digunakan untuk menyatakan banyaknya kolom maksimal matriks

Selanjutnya, terdapat deklarasi function `main()`. Function tersebut merupakan titik masuk program, sehingga seluruh perintah utama yang ingin dijalankan ditempatkan di dalam function tersebut. Di dalam function `main()`, pertama-tama program mendeklarasikan dua variabel array dua dimensi, yakni
1. variabel `A`, yang bertipe array of integers dengan ukuran `MAX_BARIS x MAX_KOLOM`, yang digunakan untuk menyimpan elemen-elemen matriks A; dan
2. variabel `B`, yang bertipe array of integers dengan ukuran `MAX_BARIS x MAX_KOLOM`, yang digunakan untuk menyimpan elemen-elemen matriks B.

Penulisan `int A[MAX_BARIS][MAX_KOLOM]` berarti variabel `A` merupakan array dua dimensi bertipe integer yang mempunyai 3 baris dan 3 kolom. Array tersebut mempunyai elemen yang diakses menggunakan dua indeks, yaitu indeks pertama untuk menyatakan baris dan indeks kedua untuk menyatakan kolom. Sebagai contoh, `A[0][0]` menyatakan elemen pada baris pertama dan kolom pertama. Pada C++, indeks array dimulai dari `0`, sehingga untuk matriks berukuran 3 x 3, indeks baris yang digunakan adalah `0` sampai `2`, sedangkan indeks kolom juga `0` sampai `2`. Pada deklarasi `A` dan `B` juga terdapat `{0}` setelah ukuran array. `{0}` digunakan untuk memberikan nilai awal `0` pada elemen-elemen array yang tidak diberikan nilai secara eksplisit. Dengan demikian, pada saat pertama kali dibuat, seluruh elemen matriks A dan B berada dalam keadaan bernilai `0`

Setelah deklarasi array, program menampilkan teks `"Masukkan matrix A:"` menggunakan `std::cout`, yang berfungsi sebagai informasi kepada user bahwa program sedang meminta elemen-elemen matriks A. Setelah itu, program menggunakan dua perulangan `for` yang saling bersarang untuk membaca seluruh elemen matriks A. Perulangan `for` pertama menggunakan variabel `i` sebagai indeks baris. Perulangan dimulai dari `i = 0`, kemudian terus berjalan selama `i < MAX_BARIS`, atau selama `i` masih kurang dari `3`. Setiap satu kali iterasi selesai, nilai `i` bertambah satu. Di dalamnya terdapat perulangan `for` kedua menggunakan variabel `j` sebagai indeks kolom. Perulangan tersebut juga dimulai dari `j = 0` dan berjalan selama `j < MAX_KOLOM`. Pada setiap posisi matriks, program menjalankan `std::cin >> A[i][j]`. Perintah tersebut digunakan untuk membaca sebuah nilai integer dari user dan menyimpannya pada elemen matriks A yang sesuai dengan indeks `i` dan `j` sehingga setelah dua perulangan selesai dilakukan, seluruh 9 elemen matriks A telah mendapatkan nilai dari user

Selanjutnya, program menampilkan teks `"Masukkan matrix B:"` untuk meminta user memasukkan elemen-elemen matriks B. Proses pembacaan matriks B dilakukan dengan cara yang sama seperti matriks A, yaitu menggunakan dua perulangan `for` bersarang. Variabel `i` digunakan untuk mengakses baris dan variabel `j` digunakan untuk mengakses kolom. Pada setiap iterasi, perintah `std::cin >> B[i][j]` membaca nilai dari user dan menyimpannya ke elemen matriks B pada posisi yang sesuai. Setelah kedua matriks berhasil diperoleh, program mulai melakukan operasi penjumlahan. Program terlebih dahulu mencetak teks `"A + B:"` sebagai penanda bahwa akan ditampilkan hasil penjumlahan matriks A dan matriks B

Untuk menghitung penjumlahan matriks, program kembali menggunakan dua perulangan `for` bersarang untuk mengakses setiap elemen dari kedua matriks. Pada setiap posisi `[i][j]`, program menjalankan ekspresi `A[i][j] + B[i][j]`. Ekspresi tersebut menjumlahkan elemen matriks A dan elemen matriks B yang berada pada posisi baris dan kolom yang sama. Hasil penjumlahan tersebut kemudian langsung ditampilkan menggunakan `std::cout`. Setelah hasil penjumlahan selesai ditampilkan, program kemudian mencetak teks `"A - B:"` sebagai penanda bahwa program akan menampilkan hasil pengurangan matriks.

Proses pengurangan hampir sama dengan proses penjumlahan. Program menggunakan dua perulangan `for` bersarang untuk mengakses seluruh elemen matriks. Perbedaannya terdapat pada operasi yang digunakan, yaitu `A[i][j] - B[i][j]`. Ekspresi tersebut mengurangi elemen matriks A dengan elemen matriks B yang berada pada posisi yang sama. Hasil pengurangan kemudian langsung ditampilkan menggunakan `std::cout`. Setelah hasil pengurangan selesai ditampilkan, program kemudian mencetak teks `"A * B:"` sebagai penanda bahwa program akan menampilkan hasil perkalian matriks

Berbeda dengan penjumlahan dan pengurangan, perkalian matriks membutuhkan tiga perulangan `for`. Hal ini terjadi karena untuk mendapatkan satu elemen hasil perkalian pada posisi `[i][j]`, program harus mengalikan setiap elemen pada baris ke-`i` dari matriks A dengan elemen pada kolom ke-`j` dari matriks B, kemudian menjumlahkan seluruh hasil perkalian tersebut. Pada bagian ini, perulangan pertama menggunakan variabel `i` untuk menentukan baris dari matriks A dan baris dari matriks hasil. Perulangan kedua menggunakan variabel `j` untuk menentukan kolom dari matriks B dan kolom dari matriks hasil. Untuk setiap kombinasi `i` dan `j`, program kemudian mendeklarasikan variabel lokal bernama `hasil` dengan tipe integer dan memberikan nilai awal `0`. Variabel `hasil` digunakan untuk menyimpan sementara hasil penjumlahan perkalian elemen-elemen yang diperlukan untuk mendapatkan satu elemen matriks hasil. Nilai awal `0` diperlukan karena hasil akhir akan diperoleh dari beberapa operasi penjumlahan. Setelah itu, program menjalankan perulangan ketiga menggunakan variabel `k`. Perulangan tersebut berjalan dari `k = 0` sampai `k < MAX_KOLOM`. Pada setiap iterasi, program menjalankan perintah `hasil += A[i][k] * B[k][j]`. Jadi, pada setiap iterasi, program mengambil elemen matriks A pada posisi `[i][k]`, mengambil elemen matriks B pada posisi `[k][j]`, mengalikan keduanya, kemudian menambahkan hasil perkalian tersebut ke variabel `hasil`

Sebagai gambaran, untuk menghitung elemen hasil pada posisi baris pertama dan kolom pertama, program akan menghitung `A[0][0] * B[0][0]`, kemudian `A[0][1] * B[1][0]`, kemudian `A[0][2] * B[2][0]`, dan seluruh hasil tersebut dijumlahkan ke dalam variabel `hasil`. Dengan demikian, ketika perulangan `k` selesai, variabel `hasil` sudah berisi nilai perkalian matriks untuk posisi `[i][j]` yang sedang diproses

Setelah nilai `hasil` diperoleh, program mencetaknya menggunakan `std::cout << hasil << " "`. Spasi setelah nilai digunakan agar elemen-elemen pada satu baris tidak saling berhimpitan. Setelah seluruh kolom pada suatu baris selesai dihitung, program menjalankan `std::cout << std::endl;` untuk berpindah ke baris berikutnya.

### 2. Menukar Tiga Variabel

Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel 

```C++
#include <iostream>

void tukarPointer(int *a, int *b, int *c) {
    int temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}

void tukarReference(int &a, int &b, int &c) {
    int temp = a;
    a = b;
    b = c;
    c = temp;
}

int main() {
    int a = 4, b = 6, c = 8;

    std::cout << "Sebelum ditukar -> a = " << a << ", b = " << b << ", c = " << c << std::endl;

    tukarPointer(&a, &b, &c);
    std::cout << "Setelah Call by Pointer -> a = " << a << ", b = " << b << ", c = " << c << std::endl;

    tukarReference(a, b, c);
    std::cout << "Setelah Call by Reference -> a = " << a << ", b = " << b << ", c = " << c << std::endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/andikarofifsulistyawan/CAK2EAB4-praktikum-struktur-data/blob/main/Modul%2002/Unguided/Output/output-unguided2-1.png)

Program di atas adalah program yang digunakan untuk menukar nilai dari tiga variabel integer, yaitu `a`, `b`, dan `c`, menggunakan dua pendekatan, yaitu call by pointer dan call by reference. Program diawali dengan nilai `a = 4`, `b = 6`, dan `c = 8`, kemudian menampilkan nilai awal tersebut. Setelah itu, program memanggil prosedur `tukarPointer()` untuk menukar nilai ketiga variabel menggunakan pointer dan menampilkan hasilnya. Selanjutnya, program memanggil prosedur `tukarReference()` untuk kembali menukar nilai ketiga variabel menggunakan reference, lalu menampilkan hasil akhirnya

Di baris pertama, ada direktif `#include <iostream>`, yang berarti program menggunakan header `iostream` dari standard library C++. Header tersebut menyediakan fasilitas input dan output berbasis teks, salah satunya adalah `std::cout` yang digunakan untuk menampilkan informasi ke standard output atau terminal komputer. Setelah itu terdapat prosedur `tukarPointer()` yang mempunyai tiga parameter, yakni `int *a`, `int *b`, dan `int *c`. Tanda `*` menunjukkan bahwa ketiga parameter tersebut merupakan pointer yang menyimpan alamat memori variabel bertipe integer. Pointer digunakan agar prosedur dapat mengakses dan mengubah nilai variabel yang berada di luar prosedur melalui alamat memorinya

Di dalam prosedur `tukarPointer()`, pertama-tama dibuat variabel `temp` untuk menyimpan nilai sementara. Statement `int temp = *a` berarti simpan nilai yang ditunjuk oleh pointer `a` ke dalam variabel `temp`. Selanjutnya, ada statement `*a = *b`, yang berarti buat nilai yang ditunjuk `a` menjadi nilai yang ditunjuk `b`. Kemudian, ada statement `*b = *c`, yang berarti buat nilai yang ditunjuk `b` menjadi nilai yang ditunjuk `c`. Terakhir, ada statement `*c = temp`, yang berarti buat nilai yang ditunjuk `c` menjadi nilai awal `a` yang sudah disimpan dalam `temp` sebelumnya. Dengan demikian, nilai `4, 6, 8` berubah menjadi `6, 8, 4`. 

Setelah itu, ada prosedur `tukarReference()` yang mempunyai parameter `int &a`, `int &b`, dan `int &c`. Tanda `&` menunjukkan bahwa parameter tersebut merupakan reference yang merujuk langsung kepada variabel asli sehingga perubahan pada parameter akan langsung mengubah variabel yang digunakan saat prosedur dipanggil. Di dalam prosedur `tukarReference()`, proses pertukaran dilakukan dengan cara yang sama, yaitu menggunakan variabel sementara `temp`. Ada statement `int temp = a`, yang berarti simpan nilai awal `a` ke `temp`. Kemudian, statement `a = b` berarti simpan nilai `b` ke dalam `a`. Kemudian, statement `b = c` berarti simpan nilai `c` ke dalam `b`. Terakhir, statement `c = temp` berarti simpan nilai  nilai awal `a` yang disimpan dalam `temp` sebelumnya ke dalam `c`. 

Perbedaan utama antara prosedur `tukarPointer()` dan prosedur `tukarReference()` adalah cara mengakses parameternya. Pada prosedur `tukarPointer()`, nilai harus diakses menggunakan operator dereference `*`, sedangkan pada prosedur `tukarReference()`, reference nilai dapat digunakan secara langsung tanpa operator dereference `*`. Selain itu, saat prosedur `tukarPointer()` dipanggil, alamat variabel harus dikirim menggunakan `&`, sedangkan pada prosedur `tukarReference()` reference pemanggilannya cukup menggunakan nama variabel biasa

Selanjutnya, di dalam function `main()`, program mendeklarasikan tiga variabel integer, yaitu `a`, `b`, dan `c`, sekaligus memberikan nilai awal `4`, `6`, dan `8`. Program kemudian menampilkan nilai tersebut menggunakan `std::cout`. Setelah itu, program menjalankan prosedur `tukarPointer(&a, &b, &c)`. Tanda `&` digunakan untuk mendapatkan alamat memori ketiga variabel tersebut dan mengirimkannya kepada prosedur `tukarPointer()`. Karena prosedur menerima alamat tersebut, perubahan nilai yang dilakukan melalui pointer akan langsung memengaruhi variabel asli. Setelah pemanggilan tersebut selesai, nilai menjadi `a = 6`, `b = 8`, dan `c = 4`, kemudian program mencetak hasilnya. Selanjutnya, program menjalankan prosedur `tukarReference(a, b, c)`. Pada pemanggilan ini, tidak diperlukan operator `&` karena parameter prosedur sudah dideklarasikan sebagai reference. Prosedur tersebut kemudian menukar kembali nilai ketiga variabel sehingga hasil akhirnya menjadi `a = 8`, `b = 4`, dan `c = 6`

### 3. Menampilkan Isi Array dan Mencari Nilai Minimum, Maksimum, serta Rata-Rata-nya

Diketahui sebuah array 1 dimensi sebagai berikut:
`arrA = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55}`
Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata-rata dari array tersebut! Gunakan function `cariMinimum()` untuk mencari nilai minimum dan function `cariMaksimum()` untuk mencari nilai maksimum, serta gunakan prosedur `hitungRataRata()` untuk menghitung nilai rata-rata! Buat program menggunakan menu switch-case seperti berikut ini:
```text
--- Menu Program Array --- 
1. Tampilkan isi array 
2. cari nilai maksimum 
3. cari nilai minimum 
4. Hitung nilai rata - rata
```

```C++
#include <iostream>
const int MAX = 10;

int cariMinimum(int arr[MAX]) {
    int minimum = arr[0];

    for (int i = 1; i < MAX; i++) {
        if (arr[i] < minimum) {
            minimum = arr[i];
        }
    }

    return minimum;
}

int cariMaksimum(int arr[MAX]) {
    int maksimum = arr[0];

    for (int i = 1; i < MAX; i++) {
        if (arr[i] > maksimum) {
            maksimum = arr[i];
        }
    }

    return maksimum;
}

void hitungRataRata(int arr[MAX]) {
    int jumlah = 0;

    for (int i = 0; i < MAX; i++) {
        jumlah += arr[i];
    }

    std::cout << "Nilai rata-rata = " << (double) jumlah / MAX << std::endl;
}

int main() { 
    int arrA[MAX] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int pilihan;

    std::cout << "\n--- Menu Program Array ---\n";
    std::cout << "1. Tampilkan isi array\n";
    std::cout << "2. Cari nilai maksimum\n";
    std::cout << "3. Cari nilai minimum\n";
    std::cout << "4. Hitung nilai rata-rata\n";
    std::cout << "Pilih menu: ";
    std::cin >> pilihan;

    switch (pilihan) {
        case 1:
            std::cout << "Isi array: ";
            for (int i = 0; i < MAX; i++) {
                std::cout << arrA[i] << " ";
            }
            std::cout << std::endl;
            break;
        case 2:
            std::cout << "Nilai maksimum = " << cariMaksimum(arrA) << std::endl;
            break;
        case 3:
            std::cout << "Nilai minimum = " << cariMinimum(arrA) << std::endl;
            break;
        case 4:
            hitungRataRata(arrA);
            break;
        default:
            std::cout << "Pilihan tidak valid." << std::endl;
    }

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/andikarofifsulistyawan/CAK2EAB4-praktikum-struktur-data/blob/main/Modul%2002/Unguided/Output/output-unguided3-1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/andikarofifsulistyawan/CAK2EAB4-praktikum-struktur-data/blob/main/Modul%2002/Unguided/Output/output-unguided3-2.png)

##### Output 3
![Screenshot Output Unguided 3_3](https://github.com/andikarofifsulistyawan/CAK2EAB4-praktikum-struktur-data/blob/main/Modul%2002/Unguided/Output/output-unguided3-3.png)

##### Output 4
![Screenshot Output Unguided 3_4](https://github.com/andikarofifsulistyawan/CAK2EAB4-praktikum-struktur-data/blob/main/Modul%2002/Unguided/Output/output-unguided3-4.png)

##### Output 5
![Screenshot Output Unguided 3_5](https://github.com/andikarofifsulistyawan/CAK2EAB4-praktikum-struktur-data/blob/main/Modul%2002/Unguided/Output/output-unguided3-5.png)

Program di atas adalah program yang digunakan untuk mengolah sebuah array satu dimensi bernama `arrA` yang berisi 10 bilangan bulat, yaitu `11, 8, 5, 7, 12, 26, 3, 54, 33, dan 55`. Program menyediakan menu yang memungkinkan user memilih salah satu dari empat operasi, yaitu menampilkan isi array, mencari nilai maksimum, mencari nilai minimum, atau menghitung nilai rata-rata. Untuk mencari nilai minimum, digunakan function `cariMinimum()`. Untuk mencari nilai maksimum, digunakan function `cariMaksimum()`. Untuk menghitung rata-rata, digunakan prosedur `hitungRataRata()`

Di baris pertama, ada direktif `#include <iostream>`, yang berarti program menggunakan header `iostream` dari standard library C++. Header tersebut menyediakan fasilitas input dan output berbasis teks, seperti `std::cin` untuk membaca input dari user dan `std::cout` untuk menampilkan output ke standard output atau terminal komputer. Setelah itu terdapat deklarasi konstanta `MAX` dengan nilai `10`. Konstanta tersebut digunakan untuk menyatakan banyaknya elemen array sehingga nilai `10` tidak perlu ditulis berulang kali pada bagian program lainnya. Selanjutnya terdapat function `cariMinimum()` yang menerima parameter `arr` bertipe array of integers dengan ukuran `MAX`. Di dalam function tersebut, variabel `minimum` dideklarasikan dan diberi nilai awal berupa `arr[0]`, sehingga elemen pertama array dianggap sebagai nilai minimum sementara. Kemudian, program melakukan perulangan dari indeks `1` sampai `MAX - 1`. Pada setiap iterasi, program membandingkan `arr[i]` dengan `minimum` menggunakan kondisi `arr[i] < minimum`. Jika kondisi tersebut bernilai true, maka nilai `minimum` diganti dengan nilai `arr[i]`. Setelah seluruh elemen diperiksa, function mengembalikan nilai `minimum` menggunakan statement `return minimum`

Setelah function `cariMinimum()`, terdapat function `cariMaksimum()` yang mempunyai bentuk hampir sama, tetapi digunakan untuk mencari nilai terbesar dalam array. Pertama-tama, variabel `maksimum` diberi nilai awal `arr[0]`. Kemudian, program melakukan perulangan dari indeks `1` sampai `MAX - 1`. Pada setiap iterasi, program mengecek apakah `arr[i]` lebih besar daripada `maksimum` melalui kondisi `arr[i] > maksimum`. Jika kondisi tersebut bernilai true, nilai `maksimum` akan diganti menjadi `arr[i]`. Setelah seluruh elemen selesai dibandingkan, function mengembalikan nilai maksimum menggunakan statement `return maksimum`

Selanjutnya, ada prosedur `hitungRataRata()` yang menerima array yang sama sebagai parameter. Di dalamnya, terdapat variabel `jumlah` yang diinisialisasi dengan `0`, kemudian dilakukan perulangan untuk mengakses seluruh elemen array dan menjumlahkannya dalam `jumlah` menggunakan `jumlah += arr[i]`. Setelah seluruh elemen dijumlahkan, program menghitung rata-rata dengan ekspresi `(double) jumlah / MAX`. `(double)` digunakan untuk konversi tipe data dari integer (bilangan bulat) ke float (bilangan pecahan) agar hasil pembagian dapat berupa bilangan pecahan, bukan hasil pembagian bilangan bulat. Hasil tersebut kemudian langsung ditampilkan menggunakan `std::cout`

Selanjutnya, program masuk ke function `main()`. Di dalamnya dideklarasikan array `arrA` bertipe integer dengan ukuran `MAX` dan langsung diinisialisasi dengan 10 nilai yang telah diberikan oleh soal. Karena `MAX` bernilai `10`, array tersebut memiliki indeks dari `0` sampai `9`. Setelah itu, dideklarasikan variabel `pilihan` bertipe integer untuk menyimpan pilihan menu yang dimasukkan oleh user. Program kemudian menampilkan teks `"--- Menu Program Array ---"` beserta empat pilihan menu menggunakan `std::cout`, yaitu menu `1` untuk menampilkan isi array, menu `2` untuk mencari nilai maksimum, menu `3` untuk mencari nilai minimum, dan menu `4` untuk menghitung nilai rata-rata. Setelah menu ditampilkan, program menggunakan `std::cin >> pilihan` untuk membaca pilihan user dan menyimpannya ke dalam variabel `pilihan`.

Setelah mendapatkan nilai `pilihan`, program menggunakan struktur `switch-case` untuk menentukan operasi yang akan dijalankan. Pada `case 1`, program mencetak teks `"Isi array: "` kemudian melakukan perulangan dari indeks `0` sampai `MAX - 1` untuk menampilkan setiap elemen `arrA[i]`. Dengan demikian, seluruh isi array ditampilkan secara berurutan. Pada `case 2`, program memanggil function `cariMaksimum(arrA)` dan hasil nilai yang dikembalikan function tersebut langsung ditampilkan menggunakan `std::cout`. Pada `case 3`, program melakukan hal yang sama dengan memanggil `cariMinimum(arrA)` untuk mendapatkan dan menampilkan nilai minimum. Pada `case 4`, program memanggil prosedur `hitungRataRata(arrA)`. Berbeda dengan dua function sebelumnya, prosedur tersebut tidak menghasilkan nilai balik sehingga hasil rata-rata langsung ditampilkan dari dalam prosedur. Terakhir, terdapat `default` pada struktur `switch`, yaitu bagian yang akan dijalankan apabila nilai `pilihan` tidak sama dengan `1`, `2`, `3`, atau `4`. Pada kondisi tersebut, program menampilkan teks `"Pilihan tidak valid."` untuk memberitahu user bahwa pilihan menu yang dimasukkan tidak tersedia. Setiap `case` diakhiri dengan `break` agar setelah satu pilihan selesai dijalankan, program keluar dari struktur `switch` dan tidak melanjutkan eksekusi ke `case` berikutnya

## Kesimpulan
Bahasa C++ menyediakan berbagai bentuk pengelolaan data dan pengorganisasian program melalui array, pointer, string, function, prosedur, serta parameter. Array dapat digunakan untuk menyimpan sekumpulan data dengan tipe yang sama dalam satu atau beberapa dimensi, sedangkan pointer digunakan untuk menyimpan dan mengakses alamat memori suatu variabel. String pada dasarnya dapat direpresentasikan sebagai array karakter yang diakhiri dengan karakter `'\0'`. Selain itu, function digunakan untuk membagi program menjadi bagian-bagian yang memiliki tugas tertentu dan dapat mengembalikan nilai, sedangkan prosedur digunakan untuk menjalankan tugas tanpa mengembalikan nilai. Parameter function atau prosedur bisa dilewatkan dengan call by value, call by pointer, atau call by reference.

Praktikum kali ini telah memberikan pemahaman mengenai cara menggunakan berbagai konsep tersebut dalam program C++, mulai dari mendeklarasikan dan mengakses array satu dimensi, array dua dimensi, serta array berdimensi banyak, mengetahui nilai dan alamat memori suatu variabel, menggunakan pointer, mengolah string, hingga membuat function dan prosedur dengan berbagai cara pemberian parameter. Selain itu, melalui praktikum ini, konsep-konsep tersebut diterapkan untuk melakukan operasi pada matriks, menukar nilai beberapa variabel, serta mengolah data dalam array seperti mencari nilai minimum, maksimum, dan rata-rata

## Referensi
[1] Logožar, Robert., Matija Mikac, Danijel Radošević. (2024). "Exploring the Access to the Static Array Elements via Indices and via Pointers — the Introductory C++ Case Expanded." Journal of Information and Organizational Sciences, 48(1), 49–80. https://doi.org/10.31341/jios.48.1.3.<br/>
[2] Rassokhin, Dmitrii. (2020). "The C++ programming language in cheminformatics and computational chemistry." Journal of Cheminformatics, 12, 10. https://doi.org/10.1186/s13321-020-0415-y<br/>