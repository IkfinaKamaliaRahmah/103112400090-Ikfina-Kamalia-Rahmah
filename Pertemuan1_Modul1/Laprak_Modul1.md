# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Ikfina Kamalia Rahmah - 103112400090</p>

## Dasar Teori

### A. Bahasa Pemrograman C++ Bahasa Pemrograman C++<br/>
#### 1. Sejarah dan Karakteristik C++
      C++ adalah bahasa pemrograman tingkat menengah yang dikembangkan oleh Bjarne Stroustrup sebagai ekstensi dari bahasa C, dengan tambahan konsep pemrograman berorientasi objek. C++ memungkinkan pemrogram untuk mengelola memori secara langsung melalui pointer, menyediakan inheritance, polimorfisme, dan abstraksi data [lihat juga buku “Algoritma & Pemrograman C++”].
      Misalnya, C++ mendukung fitur seperti class, objek, overloading, dan template, yang tidak tersedia di C murni.
#### 2. Keunggulan dan Kelemahan C++
        Keunggulan: Kecepatan eksekusi yang tinggi, fleksibilitas manajemen memori, dan kemampuan untuk pemrograman sistem/perangkat keras.
        Kekurangan: Kompleksitas, risiko kesalahan manajemen memori (memory leak, dangling pointer), kurva belajar yang cukup tinggi.
        Dalam konteks pendidikan di Indonesia, sebuah artikel “Implementasi Penggunaan Bahasa C++ dalam Perkuliahan Teknik Elektro” menyebutkan bahwa mahasiswa merasakan bahwa bahasa C++ membantu pemahaman konsep pemrograman, namun banyak yang mengalami kesulitan dalam memahami konsep dasar objek dan pointer [1].
#### 3. Perbandingan dengan Bahasa Lain
        Dalam sebuah studi perbandingan C++ vs C#, ditemukan bahwa C++ memiliki keunggulan dalam kontrol memori dan performa, tetapi C# menawarkan kemudahan penggunaan dan manajemen memori otomatis (garbage collection) [2].

### B. IDE / Lingkungan Pemrograman: CodeBlocks (atau Dev-C++)<br/>
#### 1. Apa itu IDE?
        IDE (Integrated Development Environment) adalah perangkat lunak yang menyediakan fasilitas pengeditan kode, kompilasi, debugging dalam satu lingkungan terpadu.
#### 2. CodeBlocks & Fitur Utama
        Mendukung kompilator seperti GCC, menyediakan debugging interface, auto-completion sederhana, integrasi makefile.
        Memudahkan pengguna untuk compile, run, dan debugging tanpa perlu menyusun perintah secara manual di terminal.
#### 3. Kelebihan & Tantangan Penggunaan di Praktikum
        Kelebihan: Kemudahan dalam visualisasi error, satu klik compile-run, tampilan yang user friendly.
        Tantangan: Konfigurasi awal (path compiler), error linkage library, serta perbedaan tampilan antar platform OS.
        Dalam jurnal “Model Pembelajaran Pemrograman Bahasa C++” dibahas bagaimana buku panduan menggunakan Dev-C++ untuk memfasilitasi mahasiswa tuna netra dalam memahami konsep C++ di IDE tersebut.

## Guided 

### 1. Hellow World

#include <iostream>
using namespace std;

int main() {
    cout << "Hello, world!" << endl;
    return 0;
}

penjelasan singkat guided 1
Program diatas ini untuk mencetak teks “Hello, world!” ke layar. #include <iostream> digunakan untuk input/output, cout untuk menampilkan, endl memberi newline.

### 2. Input dan Output

#include <iostream>
using namespace std;

int main() {
    int angka;
    cout << "Masukkan sebuah angka: ";
    cin >> angka;
    cout << "Angka yang dimasukkan: " << angka << endl;
    return 0;
}


penjelasan singkat guided 2
Program diatas untuk latihan dasar input dan output di C++. User disuruh memasukkan angka, lalu angka itu langsung diprint ulang ke layar.

### 3. Struktur Kontrol If-Else


#include <iostream>
using namespace std;

int main() {
    int nilai;
    cout << "Masukkan nilai: ";
    cin >> nilai;

    if (nilai >= 60) {
        cout << "Lulus" << endl;
    } else {
        cout << "Tidak Lulus" << endl;
    }
    return 0;
}


penjelasan singkat guided 3
Program di atas adalah program sederhana untuk menentukan apakah seorang mahasiswa lulus atau tidak berdasarkan nilai yang diinput, sekaligus menjadi contoh penggunaan percabangan (if-else) dalam C++ untuk mengkategorikan hasil lulus atau tidak lulus sesuai dengan input nilai.

## Unguided 

### 1. (Program menerima 2 bilangan float lalu menampilkan hasil penjumlahan, pengurangan, perkalian, dan pembagian)

#include <iostream>
using namespace std;

int main() {
    float a, b;d
    cout << "Masukkan bilangan pertama: ";
    cin >> a;
    cout << "Masukkan bilangan kedua: ";
    cin >> b;
    cout << "\n=== Hasil Operasi Aritmatika ===" << endl;
    cout << "Penjumlahan: " << a + b << endl;
    cout << "Pengurangan: " << a - b << endl;
    cout << "Perkalian  : " << a * b << endl;

    if (b != 0) {
        cout << "Pembagian  : " << a / b << endl;
    } else {
        cout << "Pembagian  : Tidak dapat dilakukan (pembagi nol)" << endl;
    }

    return 0;
}

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 1_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided1-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 1 

### 2. (buat program yang menerima input angka (0–100) lalu mengeluarkan output nilai angka)

#include <iostream>
using namespace std;

int main() {
    float a, b;

    // Input
    cout << "Masukkan bilangan pertama: ";
    cin >> a;
    cout << "Masukkan bilangan kedua: ";
    cin >> b;

    // Proses & Output
    cout << "\n=== Hasil Operasi Aritmatika ===" << endl;
    cout << "Penjumlahan: " << a + b << endl;
    cout << "Pengurangan: " << a - b << endl;
    cout << "Perkalian  : " << a * b << endl;

    if (b != 0) {
        cout << "Pembagian  : " << a / b << endl;
    } else {
        cout << "Pembagian  : Tidak dapat dilakukan (pembagi nol)" << endl;
    }

    return 0;
}


### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 2_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided2-1.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 2

### 3. (Program Pola Angka Simetris (Pattern Printing))
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Input: ";
    cin >> n;

    cout << "Output:" << endl;
    for (int i = n; i >= 1; i--) {
        // bagian kiri
        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        // tanda *
        cout << "* ";

        // bagian kanan
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }

        cout << endl;
    }

    // baris terakhir hanya *
    cout << "*" << endl;

    return 0;
}

### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 3_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided3-1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 3

## Kesimpulan
...

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
