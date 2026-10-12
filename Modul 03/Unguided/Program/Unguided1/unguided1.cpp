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