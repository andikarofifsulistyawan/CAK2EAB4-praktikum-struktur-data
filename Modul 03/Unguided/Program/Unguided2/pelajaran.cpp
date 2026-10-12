
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
