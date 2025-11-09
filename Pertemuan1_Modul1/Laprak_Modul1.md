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
![Screenshot Output Unguided 1_1](https://github.com/IkfinaKamaliaRahmah/103112400090-Ikfina-Kamalia-Rahmah/blob/main/!03112400090-Ikfina-Kamalia-Rahmah/images/Output-Unguided1-Modul1-1.png)

contoh :
![Screenshot Output Unguided 1_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided1-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/IkfinaKamaliaRahmah/103112400090-Ikfina-Kamalia-Rahmah/blob/main/!03112400090-Ikfina-Kamalia-Rahmah/images/Output-Unguided1-Modul1-2.png)

penjelasan unguided 1 
Program di atas merupakan program sederhana dalam bahasa C++ yang digunakan untuk melakukan operasi aritmatika dasar, yaitu penjumlahan, pengurangan, perkalian, dan pembagian. Program ini meminta pengguna memasukkan dua bilangan bertipe float, kemudian hasil dari setiap operasi ditampilkan ke layar. Untuk operasi pembagian, program menggunakan percabangan if-else agar lebih aman. Jika bilangan kedua tidak sama dengan nol, hasil pembagian akan ditampilkan, namun jika bilangan kedua bernilai nol, maka program akan memberikan pesan bahwa pembagian tidak dapat dilakukan. Dengan demikian, program ini memperlihatkan penggunaan input/output dasar dengan cin dan cout, serta contoh penerapan percabangan if-else untuk mengantisipasi error seperti pembagian dengan nol.

### 2. (buat program yang menerima input angka (0–100) lalu mengeluarkan output nilai angka)

#include <iostream>
using namespace std;

string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", 
                   "enam", "tujuh", "delapan", "sembilan"};

string angkaKeTulisan(int n) {
    if (n == 0) return "nol";
    if (n == 10) return "sepuluh";
    if (n == 11) return "sebelas";
    if (n < 10) return satuan[n];
    if (n < 20) return satuan[n % 10] + " belas";
    if (n < 100) {
        int puluhan = n / 10;
        int sisaan = n % 10;
        string hasil = satuan[puluhan] + " puluh";
        if (sisaan > 0) hasil += " " + satuan[sisaan];
        return hasil;
    }
    if (n == 100) return "seratus";
    return "";
}

int main() {
    int angka;
    cout << "Masukkan angka (0 - 100): ";
    cin >> angka;

    if (angka < 0 || angka > 100) {
        cout << "Input di luar jangkauan!" << endl;
    } else {
        cout << angka << " : " << angkaKeTulisan(angka) << endl;
    }
    return 0;
}


### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/IkfinaKamaliaRahmah/103112400090-Ikfina-Kamalia-Rahmah/blob/main/!03112400090-Ikfina-Kamalia-Rahmah/images/Output-Unguided2-Modul1-3.png)

contoh :
![Screenshot Output Unguided 2_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided2-1.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/IkfinaKamaliaRahmah/103112400090-Ikfina-Kamalia-Rahmah/blob/main/!03112400090-Ikfina-Kamalia-Rahmah/images/Output-Unguided2-Modul1-4.png)

penjelasan unguided 2
Program di atas merupakan program C++ yang berfungsi mengubah angka menjadi bentuk tulisan bahasa Indonesia untuk rentang 0 sampai 100. Program ini menggunakan array satuan untuk menyimpan kata dasar angka satu sampai sembilan, kemudian fungsi angkaKeTulisan(int n) dipakai untuk menentukan hasil tulisan berdasarkan kondisi tertentu, seperti angka 0 menjadi "nol", 10 "sepuluh", 11 "sebelas", belasan dengan format “... belas”, puluhan dengan format “... puluh ...”, dan angka 100 menjadi "seratus". Di bagian main, pengguna diminta memasukkan angka, lalu dicek apakah input valid. Jika benar, program menampilkan angka sekaligus tulisannya. Program ini juga memanfaatkan cin dan cout untuk input/output serta percabangan if-else untuk mengatur kondisi angka yang berbeda.

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
![Screenshot Output Unguided 3_1](https://github.com/IkfinaKamaliaRahmah/103112400090-Ikfina-Kamalia-Rahmah/blob/main/103112400090-Ikfina-Kamalia-Rahmah/images/Output-Unguided3-Modul1-5.png)

contoh :
![Screenshot Output Unguided 3_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided3-1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/IkfinaKamaliaRahmah/103112400090-Ikfina-Kamalia-Rahmah/blob/main/!03112400090-Ikfina-Kamalia-Rahmah/images/Output-Unguided3-Modul1-6.png)

penjelasan unguided 3
Program di atas adalah program C++ yang digunakan untuk menampilkan pola angka simetris dengan tambahan tanda bintang (*) di tengah. Pertama, program meminta input bilangan bulat n dari pengguna. Kemudian menggunakan perulangan for, program mencetak angka secara menurun dari n hingga 1 di sisi kiri, menampilkan tanda * di tengah, lalu mencetak angka secara menaik dari 1 hingga i di sisi kanan. Proses ini diulang dari baris pertama hingga i = 1, sehingga terbentuk pola baris angka yang semakin mengecil. Setelah selesai, program mencetak satu baris terakhir yang hanya berisi tanda *. Program ini memanfaatkan perulangan bersarang (nested loop) untuk mengatur posisi angka kiri dan kanan, serta cout untuk menampilkan hasil pola ke layar.

## Kesimpulan
Dari praktikum Modul 1 yang sudah saya kerjakan ini dapat disimpulkan bahwa penggunaan bahasa C++ menjadi dasar penting dalam mempelajari pemrograman karena menawarkan fleksibilitas, kecepatan eksekusi, serta mendukung konsep prosedural maupun berorientasi objek. Melalui latihan guided dan unguided, mahasiswa dapat memahami cara kerja input-output, struktur kontrol (if-else), operasi aritmatika, hingga implementasi pola dengan perulangan bersarang. Selain itu, pemanfaatan IDE seperti Code::Blocks sangat membantu proses belajar karena mempermudah penulisan, kompilasi, dan debugging program sehingga mahasiswa bisa lebih fokus pada logika pemrograman daripada konfigurasi teknis. Praktikum ini juga memperlihatkan bahwa setiap permasalahan pemrograman dapat diselesaikan dengan pendekatan yang sistematis, mulai dari perencanaan algoritma hingga implementasi kode. Dengan demikian, praktikum ini tidak hanya melatih keterampilan teknis mahasiswa dalam menulis program C++, tetapi juga menumbuhkan pemahaman konsep dasar pemrograman yang akan bermanfaat untuk praktikum maupun proyek yang lebih kompleks di tahap selanjutnya.

## Referensi
<br>[1] Qobus Muhammad Fayazz Zhafar Effendi et al. (2024). “Implementasi Penggunaan Bahasa C++ dalam Perkuliahan Jurusan Teknik Elektro.” Jurnal Majemuk, Vol. 3, No 1.
[2] Yusuffahreza et al. (2024). “Comparative Study of C++ and C# Programming Languages.” Jurnal Syntax Admiration. 
[3] Agung Wijoyo et al. (2024). “Evaluasi Efisiensi Struktur Data Linked List pada Implementasi Sistem Antrian.” JRIIN: Jurnal Riset Informatika dan Inovasi. 
[4] F. Septian (2022). “Model Pembelajaran Pemrograman Bahasa C++.” Jurnal Maklumatika, Vol. 8, No 2.
[5] “Implementasi Stack dan Array pada Pengurutan Lagu Menggunakan Metode Selection Sort.” Jurnal Teknologi dan Sistem Informasi Bisnis (JTEKSIS). 
[6] Bambang Sujatmiko dkk. “Pengembangan aplikasi kamus bahasa pemrograman C++ (SiKamus).” Jurnal IT-EDU, Universitas Negeri Surabaya.
