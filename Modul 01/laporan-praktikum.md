# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahasa C++ (Bagian Pertama)</h1>
<p align="center">Andika Rofif Sulistyawan - 109082500013</p>

## Dasar Teori

C++ merupakan bahasa pemrograman yang dapat digunakan untuk membuat berbagai jenis program, mulai dari program sederhana sampai program yang lebih kompleks. Algoritma, sintaks, tipe data, variabel, operator, fungsi, serta struktur kontrol perlu dipahami terlebih dahulu karena konsep-konsep tersebut menjadi dasar dalam penyusunan program C++ [1]. C++ juga memiliki berbagai fasilitas pemrograman yang memungkinkan programmer untuk mengatur data dan alur eksekusi program sesuai dengan kebutuhan

### A. Dasar Bahasa Pemrograman C++<br/>

#### 1. Struktur Dasar Program C++<br/>

Program C++ pada umumnya memiliki fungsi `main()` sebagai bagian utama tempat program mulai dijalankan. Selain itu, program dapat menggunakan header tertentu melalui direktif `#include` untuk memperoleh fasilitas yang disediakan oleh standard library. Sebagai contoh, `#include <iostream>` digunakan ketika program membutuhkan operasi input dan output seperti `std::cin` dan `std::cout` [2]

Setiap program menggunakan `main()` sebagai titik awal eksekusi. Beberapa program juga menggunakan `#include <string>` karena terdapat penggunaan `std::string` untuk menyimpan data berupa teks. Penggunaan namespace secara eksplisit dengan penulisan `std::` juga merupakan salah satu cara untuk mengakses anggota standard library C++ tanpa harus menuliskan `using namespace std;` [4]

#### 2. Variabel dan Deklarasi<br/>

Variabel merupakan tempat untuk menyimpan data di dalam memori yang nilainya dapat digunakan selama program berjalan. Dalam C++, variabel harus dideklarasikan menggunakan tipe data tertentu sebelum digunakan. Bentuk sederhananya adalah `tipe_data nama_variabel;`, sedangkan nilai awal dapat diberikan langsung ketika deklarasi, misalnya `float variable = 0.0;` [2]. Pemilihan tipe data perlu disesuaikan dengan bentuk data yang akan diproses

#### 3. Statement<br/>

Statement merupakan instruksi yang dijalankan oleh program dan dalam C++ umumnya diakhiri dengan tanda titik koma (`;`)

#### 4. Input dan Output

Program juga perlu menerima masukan dan menampilkan hasil. Operasi input-output pada C++ dapat dilakukan melalui fasilitas pada library `iostream`. `std::cin` digunakan untuk menerima input dari user, sedangkan `std::cout` digunakan untuk menampilkan informasi atau hasil proses ke standard output. Operator `>>` digunakan bersama `std::cin` untuk mengambil data dari standard input dan menyimpannya ke dalam variabel. Sebaliknya, operator `<<` digunakan bersama `std::cout` untuk mengirimkan data atau teks ke output [4]. `std::endl` digunakan untuk mengakhiri baris output sekaligus berpindah ke baris berikutnya

### B. Tipe Data<br/>

Tipe data menentukan jenis nilai yang dapat disimpan dan diproses oleh sebuah variabel. Beberapa tipe data dasar yang umum digunakan dalam C++, antara lain, `int` untuk bilangan bulat, `float` untuk bilangan pecahan, `double` untuk bilangan pecahan dengan presisi lebih tinggi, dan `char` untuk menyimpan karakter. C++ juga menyediakan tipe data seperti `bool` serta berbagai bentuk tipe integer bertanda maupun tak bertanda [1][2]

#### 1. Tipe Data Numerik<br/>

Tipe `int` digunakan untuk menyimpan bilangan bulat dan sering digunakan sebagai variabel iterasi dalam perulangan. Sementara itu, `float` atau `double` digunakan untuk menyimpan nilai pecahan sehingga sesuai untuk program yang melakukan operasi aritmetika pada dua bilangan bertipe pecahan [1]. Tipe `float` memiliki presisi yang lebih rendah dibandingkan `double`, sehingga `double` dapat digunakan ketika perhitungan memerlukan ketelitian yang lebih tinggi. C++ juga menyediakan pemodifikasi tipe `unsigned` yang digunakan untuk nilai yang tidak memerlukan bilangan negatif [1]

#### 2. Tipe Data Karakter<br/>

Tipe data `char` digunakan untuk menyimpan satu karakter. Karakter yang disimpan dapat berupa huruf, angka, atau simbol tertentu yang direpresentasikan sebagai suatu nilai karakter [1][2]. Berbeda dengan `std::string` yang dapat digunakan untuk menyimpan rangkaian karakter, sebuah variabel bertipe `char` hanya digunakan untuk satu karakter

#### 3. Tipe Data Boolean<br/>

Tipe data `bool` digunakan untuk menyimpan nilai logika yang hanya memiliki dua kemungkinan, yaitu `true` atau `false` [2]. Tipe data ini banyak digunakan dalam kondisi percabangan dan perulangan karena hasil dari suatu perbandingan dapat direpresentasikan sebagai nilai benar atau salah.

#### 4. Array<br/>

Array adalah kumpulan beberapa data dengan tipe data yang sama dan kapasitas maksimal yang disimpan dalam memori secara bersebelahan dan diakses berdasarkan indeks. Array dapat digunakan ketika beberapa data yang memiliki jenis yang sama perlu disimpan dan diproses secara berurutan

#### 5. String<br/>

String digunakan untuk menyimpan rangkaian karakter atau teks. Dalam C++, `std::string` merupakan tipe yang umum digunakan untuk mengelola data teks dan tersedia melalui header `string` [3]

### C. Operator <br/>

#### 1. Operator Aritmetika<br/>

Operator aritmetika digunakan untuk melakukan operasi perhitungan terhadap operand. Operator tersebut adalah `+` untuk penjumlahan, `-` untuk pengurangan, `*` untuk perkalian, dan `/` untuk pembagian. Selain itu, operator `%` atau modulus digunakan untuk mendapatkan sisa hasil pembagian bilangan bulat dan banyak digunakan ketika bekerja dengan bilangan bulat

#### 2. Operator Relasional<br/>

Operator relasional atau operator hubungan digunakan untuk membandingkan dua nilai. Operator relasional yang umum digunakan dalam C++, antara lain, `==` untuk menyatakan sama dengan, `!=` untuk menyatakan tidak sama dengan, `<` untuk menyatakan kurang dari, `<=` untuk kurang dari atau sama dengan, `>` untuk lebih dari, dan `>=` untuk lebih dari atau sama dengan [1]. Hasil dari perbandingan tersebut berupa nilai kebenaran: `true` atau `false` yang dapat digunakan dalam percabangan atau perulangan

#### 3. Operator Kondisional<br/>

Operator kondisional `?:` digunakan untuk memilih salah satu dari dua ekspresi berdasarkan hasil suatu kondisi [1]. Bentuk umum operator ini adalah `kondisi ? ekspresi1 : ekspresi2`. Jika kondisi bernilai `true`, `ekspresi1` yang digunakan, sedangkan jika kondisi bernilai `false`, `ekspresi2` yang digunakan

#### 4. Operator Logika<br/>

Operator logika digunakan untuk menggabungkan atau membalikkan kondisi logika. C++ menyediakan operator `&&` yang menyatakan AND, `||` yang menyatakan OR, dan `!` yang menyatakan NOT [1]. Operator `&&` menghasilkan nilai `true` apabila kedua operand bernilai `true`, serta `false` untuk selain itu. Operator `||` menghasilkan nilai `true` apabila setidaknya salah satu operand bernilai benar, serta `false` selain itu. Sementara itu, operator `!` membalik nilai logika dari operand-nya

#### 5. Operator Penugasan<br/>

Operator penugasan digunakan untuk memberikan nilai dari suatu ekspresi kepada sebuah variabel. Nilai yang dihasilkan dari operasi di sebelah kanan operator akan disimpan ke variabel yang berada di sebelah kiri. Operator penugasan yang paling dasar adalah `=`

Selain operator `=`, C++ menyediakan operator penugasan gabungan yang menggabungkan operasi aritmetika dengan proses penugasan. Operator tersebut terdiri dari `+=`, `-=`, `*=`, `/=`, dan `%=` [1]. Penggunaannya membuat statement menjadi lebih singkat karena variabel yang berada di sebelah kiri digunakan kembali dalam proses perhitungan

Bentuk-bentuk operator penugasan tersebut dapat dijelaskan sebagai berikut

| Operator | Bentuk lengkap | Keterangan |
|----------|----------------|------------|
| = | a = b | Menyimpan nilai b ke a |
| += | a += b (setara dengan a = a + b) | Menambahkan nilai a dengan b lalu menyimpannya ke a |
| -= | a -= b (setara dengan a = a - b) | Mengurangi nilai a dengan b lalu menyimpannya ke a |
| *= | a *= b (setara dengan a = a * b) | Mengalikan nilai a dengan b lalu menyimpannya ke a |
| /= | a /= b (setara dengan a = a / b) | Membagi nilai a dengan b lalu menyimpannya ke a |
| %= | a %= b (setara dengan a = a % b) | Menghitung sisa bagi bilangan bulat antara a dengan b lalu menyimpannya ke a |

## D. Struktur Kontrol

### 1. Percabangan `if-else`<br/>

Percabangan `if` digunakan ketika program perlu menentukan tindakan berdasarkan suatu kondisi. Kondisi tersebut merupakan ekspresi yang menghasilkan nilai `true` atau `false`. Jika kondisi bernilai `true`, statement pada bagian `if` akan dijalankan. Sebaliknya, jika kondisi bernilai `false`, statement pada bagian `else` yang akan dijalankan

Kondisi pada `if` biasanya menggunakan operator relasional, seperti `==`, `!=`, `<`, `>`, `<=`, atau `>=`. Operator logika seperti `&&`, `||`, dan `!` juga dapat digunakan apabila keputusan bergantung pada lebih dari satu kondisi boolean [1].

Apabila program memiliki lebih dari dua kemungkinan kondisi, percabangan dapat dikembangkan dengan menggunakan `else if`. `else if` digunakan untuk memeriksa kondisi setelah `if` atau `else if` sebelumnya kalau kondisi pada `if` atau `else if` sebelumnya bernilai `false`. Dengan demikian, beberapa kondisi dapat diperiksa secara berurutan sampai ditemukan kondisi yang bernilai `true`

### 2. Perulangan `for`<br/>

Perulangan `for` digunakan untuk menjalankan statement secara berulang selama kondisi yang diberikan masih terpenuhi. `for` cocok digunakan ketika ada suatu variabel iterasi yang memiliki nilai awal, kondisi tertentu, dan perubahan nilai yang jelas pada setiap iterasi [1]. Bentuk umum perulangan `for` dituliskan sebagai `for (initialization; condition; increment/decrement)`. Bagian `initialization` digunakan untuk menentukan nilai awal variabel iterasi. Bagian `condition` digunakan untuk menentukan apakah perulangan masih dapat dilanjutkan. Sementara itu, `increment/decrement` digunakan untuk mengubah nilai variabel iterasi setelah statement pada satu iterasi selesai dijalankan [1]

Perulangan `for` juga dapat digunakan untuk menghasilkan pola tertentu dengan memanfaatkan perulangan bersarang. Perulangan bersarang merupakan perulangan yang terdapat di dalam perulangan lainnya.

Hal penting dalam penggunaan perulangan adalah memastikan terdapat kondisi berhenti yang jelas. Nilai variabel iterasi harus mengalami perubahan sehingga pada suatu titik kondisi perulangan menjadi bernilai `false` dan eksekusi dapat berlanjut ke statement setelah blok `for` [1]

### E. Fungsi dan Rekursi<br/>

#### 1. Fungsi<br/>

Fungsi merupakan bagian program yang dibuat untuk menjalankan tugas tertentu dan dapat dipanggil dari bagian program lain. Penggunaan fungsi membantu membagi program menjadi bagian-bagian yang lebih teratur sehingga kode lebih mudah dipahami dan digunakan kembali [4]

Fungsi dapat didefinisikan dengan parameter dan nilai balik. Parameter merupakan data yang diberikan kepada fungsi ketika fungsi tersebut dipanggil. Parameter memungkinkan satu fungsi digunakan untuk memproses nilai yang berbeda tanpa harus menulis fungsi yang sama berulang kali [4]. Nilai yang dihasilkan oleh fungsi dapat dikembalikan menggunakan keyword `return`. Nilai balikan tersebut harus sesuai dengan tipe balikan dari fungsi tersebut

Apabila fungsi tidak mengembalikan nilai, tipe `void` digunakan sebagai tipe nilai balik. Sebaliknya, apabila fungsi menghasilkan suatu nilai, tipe data pada bagian awal fungsi menunjukkan jenis nilai yang dikembalikan.

#### 2. Rekursi<br/>

Rekursi merupakan teknik penyelesaian masalah ketika sebuah fungsi memanggil dirinya sendiri dengan parameter yang lebih sederhana. Dengan cara ini, masalah yang lebih besar dapat diuraikan menjadi masalah yang lebih kecil hingga mencapai kondisi tertentu yang menghentikan pemanggilan fungsi [4]

Dalam rekursi, terdapat dua bagian penting, yaitu base case dan recursive case. Base case merupakan kondisi yang menyebabkan fungsi berhenti memanggil dirinya sendiri, sedangkan recursive case merupakan bagian ketika fungsi kembali memanggil dirinya sendiri dengan nilai yang lebih sederhana. Adanya base case diperlukan agar proses rekursi tidak berlangsung tanpa batas

---

## Unguided 

### 1. Soal Unguided 1

Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.

```C++
// NIM: 109082500013
// NAMA: Andika Rofif Sulistyawan

#include <iostream>

int main() {
    float input1 = 0.0;
    float input2 = 0.0;

    std::cout << "Bilangan pertama: ";
    std::cin >> input1;

    std::cout << "Bilangan kedua: ";
    std::cin >> input2;

    std::cout << input1 << " + " << input2 << " = " << input1 + input2 << std::endl;
    std::cout << input1 << " - " << input2 << " = " << input1 - input2 << std::endl;
    std::cout << input1 << " * " << input2 << " = " << input1 * input2 << std::endl;
    if (input2 == 0.0) {
        std::cout << input1 << " / " << input2 << " = tidak terdefinisi" << std::endl;
    } else {
        std::cout << input1 << " / " << input2 << " = " << input1 / input2 << std::endl;
    }

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/andikarofifsulistyawan/CAK2EAB4-praktikum-struktur-data/blob/main/Modul%2001/Unguided/Output/output-unguided1-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/andikarofifsulistyawan/CAK2EAB4-praktikum-struktur-data/blob/main/Modul%2001/Unguided/Output/output-unguided1-2.png)

##### Output 3
![Screenshot Output Unguided 1_3](https://github.com/andikarofifsulistyawan/CAK2EAB4-praktikum-struktur-data/blob/main/Modul%2001/Unguided/Output/output-unguided1-3.png)

##### Output 4
![Screenshot Output Unguided 1_4](https://github.com/andikarofifsulistyawan/CAK2EAB4-praktikum-struktur-data/blob/main/Modul%2001/Unguided/Output/output-unguided1-4.png)

##### Output 5
![Screenshot Output Unguided 1_5](https://github.com/andikarofifsulistyawan/CAK2EAB4-praktikum-struktur-data/blob/main/Modul%2001/Unguided/Output/output-unguided1-5.png)

Program unguided pertama adalah program C++ yang digunakan untuk menerima dua buah bilangan bertipe `float` dari user, kemudian menghitung dan menampilkan hasil dari empat operasi aritmetika dasar, yakni penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut. Pada awal program, terdapat direktif `#include <iostream>` yang digunakan untuk memasukkan header `iostream`, sehingga program dapat menggunakan fasilitas input dan output seperti `std::cin` dan `std::cout`. Selanjutnya, ada fungsi `main()` yang menjadi titik awal eksekusi program. Di dalamnya, dideklarasikan dua variabel, yakni `input1` dan `input2`, yang bertipe `float` dan masing-masing diberi nilai awal `0.0`. Pada program tersebut, saya tidak menggunakan statement `using namespace std;` karena saya ingin menggunakan nama dari standard library C++ secara eksplisit dengan menuliskan namespace `std` pada setiap penggunaannya, seperti `std::cout`, `std::cin`, dan `std::endl` untuk membuat asal setiap fungsi atau object menjadi lebih jelas serta menghindari potensi konflik nama apabila terdapat identifier lain yang memiliki nama sama dengan fungsi atau prosedur atau object atau yang ada dalam namespace `std`

Program kemudian meminta user memasukkan kedua bilangan menggunakan `std::cout` dan `std::cin`. Statement `std::cout << "Bilangan pertama: ";` digunakan untuk menampilkan pesan ke standard output (terminal) untuk meminta bilangan pertama, kemudian `std::cin >> input1;` membaca input dari user dan menyimpannya ke dalam variabel `input1`. Proses yang sama dilakukan untuk bilangan kedua dan disimpan dalam variabel `input2`. Setelah kedua nilai diperoleh, program menggunakan operator aritmetika `+` untuk penjumlahan, `-` untuk pengurangan, `*` untuk menghitung perkalian, dan `/` untuk pembagian. Setiap hasil langsung ditampilkan menggunakan `std::cout`. `std::endl` digunakan untuk mengakhiri setiap baris output

Untuk operasi pembagian, program tidak langsung menghitung `input1 / input2`, tetapi terlebih dahulu melakukan pengecekan menggunakan percabangan `if-else`. Kondisi `input2 == 0.0` digunakan untuk memeriksa apakah bilangan kedua = nol. Jika `input2` = 0, program menampilkan hasil pembagian adalah `tidak terdefinisi` karena pembagian dengan 0 tidak terdefinisi dalam aritmetika. Jika `input2` != 0, program menampilkan hasil pembagian kedua bilangan. Terakhir, ada statement `return 0;` yang menandakan bahwa program telah selesai dijalankan dengan flow normal (tanpa error)

### 2. Soal Unguided 2

Buatlah sebuah program yang menerima masukan bilangan dan mengeluarkan output nilai bilangan tersebut dalam bentuk tulisan. Angka yang akan di- input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100. 

Contoh: 
```text
79: tujuh puluh sembilan
```

```C++
// NIM: 109082500013
// NAMA: Andika Rofif Sulistyawan

#include <iostream>
#include <string>

std::string satuan[] = {
    "nol", 
    "satu", 
    "dua", 
    "tiga", 
    "empat",
    "lima", 
    "enam", 
    "tujuh", 
    "delapan", 
    "sembilan",
};

std::string terbilang(unsigned short n) {
    if (n < 10) {
        return satuan[n];
    } 
    if (n == 10) {
        return "sepuluh";
    } 
    if (n == 11) {
        return "sebelas";
    }
    if (n < 20) {
        return satuan[n - 10] + " belas";
    }
    if (n < 100) {
        return satuan[n / 10] + " puluh" + (n % 10 == 0 ? "" : " " + terbilang(n % 10));
    }
    if (n == 100) {
        return "seratus";
    }
    
    return "bilangan harus di antara 0 sampai 100 (inklusif)";
}

int main() {
    unsigned short input = 0;

    std::cout << "Input bilangan: ";
    std::cin >> input;

    std::cout << input << ": " << terbilang(input);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/andikarofifsulistyawan/CAK2EAB4-praktikum-struktur-data/blob/main/Modul%2001/Unguided/Output/output-unguided2-1.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/andikarofifsulistyawan/CAK2EAB4-praktikum-struktur-data/blob/main/Modul%2001/Unguided/Output/output-unguided2-2.png)

##### Output 3
![Screenshot Output Unguided 2_3](https://github.com/andikarofifsulistyawan/CAK2EAB4-praktikum-struktur-data/blob/main/Modul%2001/Unguided/Output/output-unguided2-3.png)

##### Output 4
![Screenshot Output Unguided 2_4](https://github.com/andikarofifsulistyawan/CAK2EAB4-praktikum-struktur-data/blob/main/Modul%2001/Unguided/Output/output-unguided2-4.png)

##### Output 5
![Screenshot Output Unguided 2_5](https://github.com/andikarofifsulistyawan/CAK2EAB4-praktikum-struktur-data/blob/main/Modul%2001/Unguided/Output/output-unguided2-5.png)


Program unguided kedua adalah program C++ yang digunakan untuk menerima sebuah bilangan cacah antara 0 sampai 100 (inklusif) dari user, kemudian mengubah bilangan tersebut menjadi bentuk tulisannya dalam bahasa Indonesia. Program tersebut menggunakan array of strings `satuan` untuk menyimpan nama satuan bilangan dari nol sampai sembilan, kemudian menggunakan fungsi `terbilang(unsigned short n)` untuk menentukan tulisan berdasarkan nilai `n` yang diberikan. Tipe data `unsigned short` digunakan karena user input adalah bilangan cacah antara 0 sampai 100 (inklusif) saja sehingga tipe tersebut bisa menghemat penggunaan memori

Pada awal program, terdapat direktif `#include <iostream>` yang digunakan untuk memasukkan header `iostream`, sehingga program dapat menggunakan fasilitas input dan output seperti `std::cin` untuk input dan `std::cout` untuk output, serta `#include <string>` untuk menggunakan tipe data `std::string`. Array `satuan` diisi dengan string `"nol"` hingga `"sembilan"` yang nantinya digunakan sebagai dasar pembentukan nama bilangan. Pada program tersebut, saya tidak menggunakan statement `using namespace std;` karena saya ingin menggunakan nama dari standard library C++ secara eksplisit dengan menuliskan namespace `std` pada setiap penggunaannya, seperti `std::cout`, `std::cin`, dan `std::endl` untuk membuat asal setiap fungsi atau object menjadi lebih jelas serta menghindari potensi konflik nama apabila terdapat identifier lain yang memiliki nama sama dengan fungsi atau prosedur atau object atau yang ada dalam namespace `std`

Fungsi `terbilang(unsigned short n)` digunakan sebagai bagian utama yang mengubah nilai bilangan menjadi tulisan. Jika `n` < 10, fungsi tersebut langsung mengembalikan elemen array `satuan` sesuai nilai `n`, sehingga misalnya user memasukkan bilangan 7, fungsi tersebut mengembalikan string `"tujuh"`. Jika `n` = 10, fungsi tersebut mengembalikan string `"sepuluh"`. Jika `n` = 11 fungsi tersebut mengembalikan string `"sebelas"`. Jika 12 <= `n` <= 19, fungsi tersebut mengembalikan string nama satuannya dari array `satuan` digabung dengan string `" belas"`, sehingga jika user memasukkan bilangan 15, fungsi tersebut mengembalikan string `"lima belas"`. Jika 20 <= `n` <= 99, fungsi tersebut mengambil bilangan puluhannya menggunakan operasi pembagian `n / 10`, kemudian menggabungnya dengan string `" puluh"`. Jika masih terdapat bilangan satuan yang ditunjukkan oleh `n % 10`, fungsi `terbilang(unsigned short n)` dipanggil kembali untuk mengubah bilangan satuan tersebut menjadi tulisan, dengan nilai parameter `n` = `n` mod 10. Sebagai contoh, bilangan 79 akan menghasilkan `"tujuh puluh sembilan"`. Jika `n` = 100, fungsi tersebut mengembalikan string `"seratus"`. Sementara itu, jika `n` > 100, fungsi tersebut mengembalikan string `"bilangan harus di antara 0 sampai 100 (inklusif)"`

Setelah fungsi tersebut didefinisikan, program memasuki fungsi `main()` sebagai titik awal eksekusi. Di dalamnya, ada variabel `input` bertipe `unsigned short` untuk menyimpan bilangan cacah yang dimasukkan user. Program menampilkan pesan `"Input bilangan: "` ke standard output (terminal) menggunakan `std::cout` dan membaca user input dengan `std::cin`, lalu nilai tersebut dikirim sebagai argumen ke fungsi `terbilang(unsigned short n)`. Output akhir program adalah bilangan cacah yang di-input oleh user diikuti string `": "` diikuti dengan string yang dikembalikan oleh fungsi `terbilang(unsigned short n)`. Terakhir, ada statement `return 0;` yang menandakan bahwa program telah selesai dijalankan dengan flow normal (tanpa error)

### 3. Soal Unguided 3

Buatlah program yang memberikan input dan output sebagai berikut<br/>
Input:
```text
3
```

Output:
```text
3 2 1 * 1 2 3
  2 1 * 1 2
    1 * 1
      *
```

```C++
// NIM: 109082500013
// NAMA: Andika Rofif Sulistyawan

#include <iostream>

int main() {
    unsigned int banyakBaris = 0;
    std::cin >> banyakBaris;

    for (int i = banyakBaris; i >= 0; i--) {
        for (int j = banyakBaris; j > i; j--) {
            std::cout << "  ";
        }

        for (int j = i; j >= 1; j--) {
            std::cout << j << " ";
        }

        std::cout << "*";

        for (int j = 1; j <= i; j++) {
            std::cout << " " << j;
        }

        std::cout << std::endl;
    }

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/andikarofifsulistyawan/CAK2EAB4-praktikum-struktur-data/blob/main/Modul%2001/Unguided/Output/output-unguided3-1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/andikarofifsulistyawan/CAK2EAB4-praktikum-struktur-data/blob/main/Modul%2001/Unguided/Output/output-unguided3-2.png)

##### Output 3
![Screenshot Output Unguided 3_3](https://github.com/andikarofifsulistyawan/CAK2EAB4-praktikum-struktur-data/blob/main/Modul%2001/Unguided/Output/output-unguided3-3.png)

Program unguided ketiga adalah program yang digunakan untuk menampilkan pola bilangan dan tanda `*` berdasarkan banyaknya baris yang di-input oleh user. Pada program tersebut, saya tidak menggunakan statement `using namespace std;` karena saya ingin menggunakan nama dari standard library C++ secara eksplisit dengan menuliskan namespace `std` pada setiap penggunaannya, seperti `std::cout`, `std::cin`, dan `std::endl` untuk membuat asal setiap fungsi atau object menjadi lebih jelas serta menghindari potensi konflik nama apabila terdapat identifier lain yang memiliki nama sama dengan fungsi atau prosedur atau object atau yang ada dalam namespace `std`. 

Pada awal program, terdapat direktif `#include <iostream>` yang digunakan untuk memasukkan header `iostream`, sehingga program dapat menggunakan fasilitas input dan output seperti `std::cin` untuk input dan `std::cout` untuk output. Selanjutnya, ada fungsi `main()` yang menjadi titik awal eksekusi program. Di dalam fungsi `main()`, ada variabel `banyakBaris` bertipe `unsigned int` yang digunakan untuk menyimpan bilangan cacah yang merupakan banyaknya baris output yang akan ditampilkan (meski banyaknya baris aktual pada output adalah nilai variabel `banyakBaris` + 1). Variabel tersebut diinisialisasi dengan nilai 0, kemudian user diminta memasukkan banyaknya baris melalui `std::cin`. Bilangan yang di-input oleh user lalu disimpan dalam variabel `banyakBaris`

Setelah mendapatkan input, program menggunakan perulangan `for` dengan variabel iterasi `i` bertipe `int` yang dimulai dari nilai `banyakBaris` dan terus berkurang hingga `i` < 0. Tipe data `int` digunakan untuk variabel iterasi `i` karena perulangan menggunakan kondisi `i >= 0`, sehingga setelah mencapai nilai 0, nilai `i` bisa berkurang menjadi -1 dan perulangan berhenti. Di dalam perulangan tersebut, terdapat perulangan bersarang pertama yang menggunakan variabel iterasi `j` untuk mencetak dua spasi setiap kali nilai `j` > `i`. Perulangan tersebut berguna untuk memberikan jarak atau indentasi pada setiap baris sehingga pola yang dihasilkan tampak makin menjorok ke kanan. Selanjutnya, ada perulangan bersarang kedua menggunakan variabel iterasi `j` untuk mencetak bilangan secara menurun dari nilai `i` sampai 1 digabung dengan satu karakter spasi. Setelah itu, ada statement `std::cout << "*";` yang digunakan untuk mencetak tanda `*` sebagai bagian tengah pola. Setelah itu, ada perulangan bersarang ketiga menggunakan variabel iterasi `j` untuk mencetak satu karakter spasi digabung dengan bilangan secara menaik mulai dari 1 sampai nilai `i`. Ketika nilai `i` makin kecil, banyaknya bilangan yang dicetak juga semakin sedikit dan posisi pola makin menjorok ke kanan. Terakhir, statement `std::cout << std::endl;` digunakan untuk berpindah ke baris berikutnya setelah seluruh bagian pada satu baris selesai dicetak. Setelah perulangan selesai, program menjalankan statement `return 0;` untuk mengakhiri fungsi `main()` dan menandakan bahwa program telah berjalan dengan flow normal (tanpa error)


## Kesimpulan

Bahasa pemrograman C++ memiliki struktur dasar yang sederhana untuk digunakan dalam membuat program. Program C++ menggunakan fungsi `main()`, yang memiliki nilai balik berupa bilangan bulat status eksekusi program (0 jika tanpa error; selain 0 jika ada error), sebagai bagian utama tempat instruksi program dijalankan. Dalam bahasa ini, kita menggunakan direktif `#include <iostream>` untuk melakukan proses input dan output menggunakan `std::cin` untuk input, `std::cout` untuk output, dan `std::endl` untuk baris baru. Selain itu, bahasa C++ adalah bahasa yang bersifat staticly typed sehingga setiap variabel, argumen, dan lain-lain harus didefinisikan dengan tipe data yang sesuai, serta setiap statement harus diakhiri dengan tanda titik koma

Penerapan konsep-konsep tersebut terlihat pada tiga program yang dikerjakan. Program unguided pertama digunakan untuk melakukan operasi aritmetika terhadap dua bilangan `float` sekaligus menangani pembagian dengan nilai nol. Program unguided kedua mengubah bilangan dari 0 sampai 100 (inklusif) menjadi bentuk tulisan dengan memanfaatkan array, percabangan, fungsi, dan rekursi. Program unguided ketiga menggunakan perulangan `for` yang disusun secara bersarang untuk membentuk pola bilangan dan tanda `*` sesuai input. Dari keseluruhan praktikum, bisa disimpulkan bahwa pemilihan tipe data dan pengaturan alur program sangat berpengaruh terhadap hasil yang diperoleh

## Referensi

[1] Harnadi, Bernardinus., Antonius Eldy Putra., Wilibrordus Endra Bima., Alfonso Praditya Galuh Mahesa., Ignatius Yogyawan Dwi., Mikha Eka Saputra., Tegar Heru Saputra., Irwan Wirawan Gulo. (2025). *Dasar logika pemrograman dengan C++*. Semarang: SIEGA Publisher. https://www.unika.ac.id/wp-content/uploads/2025/02/ebook-Berdi-Dasar-Logika-Pemrograman-C.pdf.<br/>
[2] Basiroh. (2017). *Dasar pemrograman C++*. Cilacap: Ihya Media. ISBN 978-602-6753-22-9. https://repository.uniba.ac.id/1185/1/buku%20c%2B%2Bdownload-1506055498338.pdf.<br/>
[3] Samala, Agariadne Dwinggo., Bayu Ramadhani Fajri., Fadhli Ranuarja. (2021). *Pemrograman C++*. Padang: UNP PRESS. https://books.google.co.id/books?hl=id&lr=&id=49ZbEAAAQBAJ&oi=fnd&pg=PA2&dq=pemrograman+c%2B%2B&ots=4sYIx_JYCx&sig=ouhrRQNOGTjAM3F2phz0_RIeUjY&redir_esc=y#v=onepage&q=pemrograman%20c%2B%2B&f=false.<br/>
[4] Sianipar, Rismon Hasiholan. (2014). *Pemrograman C++ untuk pemula*. Jakarta: Penerbit INFORMATIKA. ISBN 978-602-1514-320. https://books.google.co.id/books?hl=id&lr=&id=tQR2DwAAQBAJ&oi=fnd&pg=PA1&dq=pemrograman+c%2B%2B&ots=rEm8lyLHIR&sig=wmpxiLpPmn8dn5Q9vP9zY8XrsgQ&redir_esc=y#v=onepage&q=pemrograman%20c%2B%2B&f=false.<br/>
