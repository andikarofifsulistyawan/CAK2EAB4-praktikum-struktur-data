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