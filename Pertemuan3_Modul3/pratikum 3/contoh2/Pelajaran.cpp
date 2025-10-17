#include<iostream>
#include "Pelajaran.h"
using namespace std;


pelajaran create_pelajaran(string namaMapel, float kodeMapel) {
    pelajaran pel;
    pel.namaMapel = namaMapel;
    pel.kodeMapel = kodeMapel;
    return pel;
}

//Implementasi prosedur Tampil_pelajaran
void Tampil_pelajaran(pelajaran pel) {
    cout << "Nama Pelajaran: " << pel.namaMapel << endl;
    cout << "Kode Pelajaran: " << pel.kodeMapel << endl;
}