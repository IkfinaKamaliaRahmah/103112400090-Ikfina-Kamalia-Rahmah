# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Ikfina Kamalia Rahmah - 103112400090</p>

## Dasar Teori

### A. Abstract Data Type (ADT)<br/>
#### 1. Pengertian ADT
        Abstract Data Type (ADT) adalah tipe data yang mendefinisikan operasi apa yang dapat dilakukan, tanpa menentukan bagaimana operasi tersebut diimplementasikan. Dengan kata lain, ADT memisahkan antara spesifikasi (interface) dan implementasi (body). Contoh umum ADT adalah Stack, Queue, dan List, yang masing-masing dapat diimplementasikan menggunakan array atau pointer.
        Dalam bahasa C++, ADT sering diwujudkan dalam bentuk struct atau class. Konsep ADT membantu menjaga modularitas program, sehingga perubahan di sisi implementasi tidak memengaruhi bagian lain dari kode yang menggunakan ADT tersebut [1].
#### 2. Keunggulan dan Kelemahan C++
        Keunggulan:
        Eksekusi program cepat karena dikompilasi langsung ke bahasa mesin.
        Mendukung pemrograman berorientasi objek sehingga lebih mudah dikembangkan.
        Fleksibel dalam pengelolaan memori melalui pointer dan dynamic allocation.
        Kelemahan:
        Struktur sintaks cukup kompleks bagi pemula.
        Risiko terjadinya error seperti memory leak dan dangling pointer jika tidak hati-hati.
        Kurva belajar lebih tinggi dibandingkan bahasa yang sudah otomatis mengatur memori seperti Java atau Python.
        Dalam penelitian “Implementasi Penggunaan Bahasa C++ dalam Perkuliahan Jurusan Teknik Elektro”, disebutkan bahwa mahasiswa merasa C++ sangat membantu memahami konsep dasar pemrograman, walaupun banyak yang mengalami kesulitan di bagian objek dan pointer [1].
#### 3. Perbandingan dengan Bahasa Lain
        Jika dibandingkan dengan bahasa modern seperti C# atau Python, C++ unggul dari sisi kecepatan dan efisiensi memori, tapi kalah dalam hal kemudahan penggunaan.
        Bahasa seperti C# memiliki garbage collector untuk mengelola memori otomatis, sedangkan di C++ programmer harus mengelola sendiri. Namun hal ini membuat C++ lebih unggul untuk aplikasi yang membutuhkan performa tinggi, seperti sistem real-time dan game engine [2].
### B. Abstract Data Type (ADT) dan IDE CodeBlocks<br/>
#### 1. Apa itu IDE?
        Abstract Data Type (ADT) adalah tipe data yang didefinisikan berdasarkan perilaku (operasi yang dapat dilakukan), bukan berdasarkan implementasi detailnya.
        Contohnya, kita tahu bahwa pada struktur data Stack ada operasi push() dan pop(), tapi kita tidak perlu tahu apakah Stack itu dibuat dengan array atau linked list.
        Dengan ADT, program jadi lebih modular, fleksibel, dan mudah diubah tanpa harus menulis ulang semua kode.
        C++ sering menggunakan struct atau class untuk menerapkan ADT.
        Misalnya, dalam modul ini ADT diterapkan pada Mahasiswa dan Pelajaran untuk memisahkan bagian interface (file .h) dan implementasi (file .cpp).
        Penelitian “Evaluasi Efisiensi Struktur Data Linked List pada Implementasi Sistem Antrian” menunjukkan bahwa penerapan ADT membantu efisiensi program karena memungkinkan pemisahan fungsi logika dan representasi data [3].
#### 2. CodeBlocks & Fitur Utama
        Mendukung berbagai compiler seperti GCC dan MinGW.
        Fitur syntax highlighting dan auto-completion.
        Dapat melakukan compile, run, dan debugging secara langsung.
        Mendukung proyek multi-file (misalnya .h dan .cpp terpisah untuk ADT).Dengan CodeBlocks, mahasiswa bisa fokus memahami konsep logika program tanpa harus repot mengatur perintah kompilasi di terminal.
        Dalam penelitian “Model Pembelajaran Pemrograman Bahasa C++”, IDE seperti CodeBlocks terbukti membantu mahasiswa, terutama pemula, untuk memahami alur pemrograman karena tampilan yang sederhana dan terintegrasi [4].
#### 3. Kelebihan & Tantangan Penggunaan di Praktikum
        Kelebihan:
        Praktis dan mudah digunakan karena semua proses (edit, compile, run) ada di satu tempat.
        Menampilkan pesan error dengan jelas, membantu mahasiswa belajar dari kesalahan.
        Cocok untuk pemula yang baru memahami konsep dasar bahasa C++.
        Tantangan:
        Perlu konfigurasi awal compiler sebelum bisa digunakan.
        Terkadang terjadi error linkage jika file header dan implementasi tidak sinkron.
        Mahasiswa sering bingung dalam memisahkan file .h, .cpp, dan main.cpp pada penerapan ADT.
        Namun, setelah memahami struktur proyek di CodeBlocks, mahasiswa dapat lebih mudah mengembangkan program modular seperti yang diterapkan pada ADT Mahasiswa dan Pelajaran.
        Praktikum ini menjadi langkah awal untuk mengenal bagaimana konsep Abstract Data Type diterapkan secara nyata dalam bahasa C++ menggunakan IDE modern.

## Guided 

### 1. struct

#include<iostream>
using namespace std;

struct mahasiswa{
    string nama;
    float nilai1,nilai2; 
};

void inputMhs(mahasiswa m){
    cout<<"Masukkan nama mahasiswa : "; 
    cin>>m.nama;
    cout<<"Masukkan nilai 1: "; 
    cin >> m.nilai1;
    cout <<"Masukkan nilai 2: "; 
    cin>>m.nilai2;
}

float rata2(mahasiswa m){
    return (m.nilai1 + m.nilai2)/2;
}

int main(){
    mahasiswa mhs;
    inputMhs(mhs);
    cout<<"Rata rata: "<<rata2(mhs);
    return 0;
}

penjelasan singkat guided 1
program diatas berfungsi untuk menyimpan dan mengolah data mahasiswa menggunakan struct dan fungsi terpisah, meski agar benar-benar berfungsi, parameter inputMhs() sebaiknya menggunakan reference (&) supaya data tersimpan ke variabel aslinya.

### 2.1. Pelajaran.h

// header guard digunakan untuk mencegah file header yang sama 
// di include lebihbdari sekali dalam satu program

#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <iostream>
using namespace std;

//deklarasi ADT pelajaran
struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

//function untuk membuat data pelajaran
pelajaran create_pelajaran(string namaMapel, string kodepel);

//prosedur untuk menampilkan data pelajaran
void tampil_pelajaran(pelajaran pel);

#endif

penjelasan singkat guided 2
membuat program yang saling berhubungan main.cpp, Pelajaran.cpp, dan Pelajaran.h — ini adalah contoh implementasi Abstract Data Type (ADT) dalam C++ dengan pemisahan antara header, implementasi, dan main program.
File ini berisi rancangan ADT pelajaran. Di dalamnya ada struct pelajaran yang punya dua atribut: namaMapel dan kodeMapel. Selain itu, ada deklarasi dua fungsi: create_pelajaran() buat bikin data pelajaran baru, dan tampil_pelajaran() buat nampilin datanya. Header guard (#ifndef, #define, #endif) dipakai biar file ini nggak kebaca dua kali sama compiler. Intinya, file ini cuma nyimpen deklarasi dan struktur, belum ada logika programnya.

### 2.2. Pelajaran.h

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


penjelasan singkat guided pelajaran
File ini isinya realisasi dari fungsi-fungsi yang ada di header. Fungsi create_pelajaran() bikin objek pelajaran baru dan ngisi datanya sesuai input, sedangkan tampil_pelajaran() buat nampilin nama dan kode pelajaran ke layar. Jadi, file ini tempat semua logika fungsi ADT dijalankan. Ada sedikit catatan aja, nama fungsi dan tipe data harus disamain sama yang di header biar nggak error.

### 2.3. main
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

penjelasan singkat guided main
File ini adalah program utama yang berfungsi untuk menjalanin semuanya. Di sini dibuat variabel namapel dan kodepel, lalu dipakai buat bikin objek pelajaran lewat create_pelajaran(). Setelah itu, hasilnya ditampilin lewat tampil_pelajaran().

## Unguided 

### 1. Data Mahasiswa

#include <iostream>
using namespace std;

// Struct untuk menyimpan data mahasiswa
struct Mahasiswa {
    string nama;
    string nim;
    float uts, uas, tugas, nilaiAkhir;
};

// Fungsi untuk menghitung nilai akhir
float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * tugas) + (0.4 * uas) + (0.3 * uts);
}

int main() {
    Mahasiswa mhs[10];
    int n;

    cout << "Masukkan jumlah mahasiswa (maks 10): ";
    cin >> n;
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << "Data Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama  : ";
        cin >> mhs[i].nama;
        cout << "NIM   : ";
        cin >> mhs[i].nim;
        cout << "Nilai UTS   : ";
        cin >> mhs[i].uts;
        cout << "Nilai UAS   : ";
        cin >> mhs[i].uas;
        cout << "Nilai Tugas : ";
        cin >> mhs[i].tugas;

        // Hitung nilai akhir menggunakan fungsi
        mhs[i].nilaiAkhir = hitungNilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
        cout << endl;
    }

    cout << "\n=== Data Mahasiswa ===\n";
    for (int i = 0; i < n; i++) {
        cout << "Nama        : " << mhs[i].nama << endl;
        cout << "NIM         : " << mhs[i].nim << endl;
        cout << "Nilai Akhir : " << mhs[i].nilaiAkhir << endl;
        cout << "--------------------------" << endl;
    }

    return 0;
}


### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/IkfinaKamaliaRahmah/103112400090-Ikfina-Kamalia-Rahmah/blob/main/!03112400090-Ikfina-Kamalia-Rahmah/images3/Output-Unguided1-Modul3-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/IkfinaKamaliaRahmah/103112400090-Ikfina-Kamalia-Rahmah/blob/main/!03112400090-Ikfina-Kamalia-Rahmah/images3/Output-Unguided1-Modul3-2.png)

penjelasan unguided 1 
Program diatas digunakan untuk mengelola data mahasiswa menggunakan struct dan fungsi dalam C++. Di awal, dibuat struct Mahasiswa yang menyimpan data seperti nama, NIM, nilai UTS, UAS, tugas, dan nilai akhir. Fungsi hitungNilaiAkhir() menghitung nilai akhir berdasarkan bobot 30% tugas, 40% UAS, dan 30% UTS.
Dalam fungsi main(), pengguna memasukkan jumlah mahasiswa (maksimal 10) lalu mengisi data tiap mahasiswa. Nilai akhir dihitung otomatis dan hasilnya ditampilkan dalam bentuk daftar nama, NIM, dan nilai akhir.


### 2.1. Pelajaran.h

#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <iostream>
using namespace std;

// Deklarasi struct ADT pelajaran
struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

// Deklarasi function & procedure
pelajaran create_pelajaran(string namaMapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif

### 2.2. Pelajaran.cpp
#include "pelajaran.h"

// Implementasi function create_pelajaran
pelajaran create_pelajaran(string namaMapel, string kodepel) {
    pelajaran p;
    p.namaMapel = namaMapel;
    p.kodeMapel = kodepel;
    return p;
}

// Implementasi procedure tampil_pelajaran
void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}

### 2.3. main
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}


### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/IkfinaKamaliaRahmah/103112400090-Ikfina-Kamalia-Rahmah/blob/main/!03112400090-Ikfina-Kamalia-Rahmah/images3/Output-Unguided2-Modul3-3.png)


penjelasan unguided 2
Program ini terdiri dari tiga file utama yang saling berhubungan, yaitu Pelajaran.h, Pelajaran.cpp, dan main.cpp. File Pelajaran.h berfungsi sebagai header file yang berisi deklarasi struktur data dan prototipe fungsi. Di dalamnya terdapat struct bernama pelajaran yang menyimpan dua atribut, yaitu namaMapel dan kodeMapel, serta dua fungsi: create_pelajaran() untuk membuat data pelajaran baru dan tampil_pelajaran() untuk menampilkan isinya. File Pelajaran.cpp berisi implementasi dari fungsi-fungsi tersebut. Pada fungsi create_pelajaran(), data pelajaran diisi berdasarkan parameter yang diberikan, lalu dikembalikan ke pemanggilnya. Sedangkan fungsi tampil_pelajaran() digunakan untuk menampilkan data namaMapel dan kodeMapel ke layar.
Sementara itu, file main.cpp menjadi bagian utama program yang menjalankan seluruh proses. Di dalamnya, pengguna mendefinisikan dua variabel namapel dan kodepel, lalu memanggil fungsi create_pelajaran() untuk membuat objek pel, dan memanggil tampil_pelajaran() untuk menampilkan hasilnya ke layar. Program ini memperlihatkan bagaimana konsep Abstract Data Type (ADT) diimplementasikan dalam C++ dengan cara memisahkan deklarasi, implementasi, dan pemanggilan fungsi ke dalam file yang berbeda. Melalui program ini, mahasiswa dapat belajar bagaimana menggunakan struct, fungsi, dan pemisahan file untuk membuat program yang lebih terstruktur, rapi, serta mudah dipahami.


### 3. (Program Pola Angka Simetris (Pattern Printing))

#include <iostream>
using namespace std;

void tampilArray(int arr[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


void tukarPosisi(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
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
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int x = 10, y = 20;
    int *ptr1 = &x;
    int *ptr2 = &y;

    cout << "Array A sebelum ditukar:" << endl;
    tampilArray(A);
    cout << "Array B sebelum ditukar:" << endl;
    tampilArray(B);

    
    tukarPosisi(A, B, 1, 1);

    cout << "Array A setelah ditukar:" << endl;
    tampilArray(A);
    cout << "Array B setelah ditukar:" << endl;
    tampilArray(B);

    cout << "Nilai sebelum tukar pointer: x=" << x << ", y=" << y << endl;
    tukarPointer(ptr1, ptr2);
    cout << "Nilai setelah tukar pointer: x=" << x << ", y=" << y << endl;

    return 0;
}

### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/IkfinaKamaliaRahmah/103112400090-Ikfina-Kamalia-Rahmah/blob/main/103112400090-Ikfina-Kamalia-Rahmah/images3/Output-Unguided3-Modul3-4.png)

penjelasan unguided 3
Program diatas membuat dua array 2D berukuran 3x3 dan dua pointer integer. Fungsi tampilArray() digunakan untuk menampilkan isi array dengan perulangan bersarang. Fungsi tukarPosisi() berfungsi menukar nilai dari dua array 2D pada posisi tertentu, misalnya di (1,1) elemen array A dan B saling bertukar. Sementara tukarPointer() digunakan untuk menukar nilai dua variabel melalui pointer. Dari program ini bisa dipahami bahwa penggunaan array 2D dan pointer mempermudah manipulasi data langsung di memori dan jadi dasar penting dalam pengolahan data di C++.

## Kesimpulan
Dari praktikum Modul 3 ini yang sudah saya kerjakan, saya jadi paham bahwa Abstract Data Type (ADT) itu penting banget dalam pemrograman karena membantu kita membuat program yang lebih rapi, terstruktur, dan mudah dikelola. Dengan memisahkan antara bagian spesifikasi (apa yang bisa dilakukan) dan implementasi (bagaimana cara kerjanya), kita bisa bikin kode yang lebih fleksibel dan gampang dipakai ulang.

## Referensi
<br>[1] Triase. (2020). Diktat Edisi Revisi: Struktur Data. Medan: Universitas Islam Negeri Sumatera Utara.
[2] Indahyati, Uce & Rahmawati, Yunianita. (2020). Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++. Umsida Press.
[3] Agung Wijoyo et al. (2024). “Evaluasi Efisiensi Struktur Data Linked List pada Implementasi Sistem Antrian.” JRIIN: Jurnal Riset Informatika dan Inovasi.
[4] Lucky E. Santoso. (2022). “Standard Template Library C++ untuk Mengajarkan Struktur Data.” Jurnal JIK. Universitas Esa Unggul.
[5] Risky Dwi Setiyawan et al. (2024). “Penggunaan Struktur Data Stack dalam Pemrograman C++ dengan Pendekatan Array dan Linked List.” Jurnal JUTECH.
[6] Bambang Sujatmiko et al. (2023). “Pengembangan Aplikasi Kamus Bahasa Pemrograman C++ (SiKamus).” Jurnal IT-EDU, Universitas Negeri Surabaya.
