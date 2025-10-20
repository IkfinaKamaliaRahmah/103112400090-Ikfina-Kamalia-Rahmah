# <h1 align="center">Laporan Praktikum Modul 2- Pengenalan Bahas C++ (Bagian kedua)</h1>
<p align="center">Ikfina Kamalia Rahmah - 103112400090</p>

## Dasar Teori

### A. Bahasa Pemrograman C++ Bahasa Pemrograman C++<br/>
#### 1. Sejarah dan Karakteristik
        C++ muncul sebagai ekstensi bahasa C yang dikembangkan oleh Bjarne Stroustrup pada awal 1980-an, untuk menambahkan fitur pemrograman berorientasi objek ke bahasa C. C++ menggabungkan kemampuan pemrograman prosedural dan OOP, serta memungkinkan manipulasi memori langsung melalui pointer.
        Karakteristik utama C++ antara lain:
        Mendukung kelas dan objek, inheritance, polimorfisme, abstraksi, dan enkapsulasi.Mendukung template (generic programming) dan operator overloading.
        Kontrol tingkat rendah atas memori (alokasi & dealokasi manual dengan new / delete).Kompatibel sebagian dengan bahasa C, sehingga banyak library C bisa digunakan di C++.
#### 2. Keunggulan dan Kelemahan C++
        Keunggulan C++: Performa tinggi — cocok untuk aplikasi yang memerlukan efisiensi,Kontrol detail atas sumber daya dan memori.
        Fleksibilitas: bisa dipakai untuk pengembangan sistem, aplikasi desktop, game, embedded systems.
        Kekurangan C++: Kompleksitas sintaks dan fitur — lebih sulit dipelajari terutama konsep OOP dan pointer, Risiko kesalahan memori (memory leak, dangling pointer),Manajemen sumber daya harus hati-hati (tidak ada garbage collection otomatis).Berdasarkan penelitian “Penggunaan Bahasa C++ dalam Perkuliahan Jurusan Teknik Elektro” di Indonesia, bahasa C++ digunakan untuk membantu mahasiswa dalam tugas dasar pemrograman dan pengembangan proyek, meskipun mahasiswa mengeluhkan kurva belajar terutama pada aspek pointer dan abstraksi objek [1].
#### 3. Perbandingan dengan Bahasa Lain
        Dalam penelitian Komparasi Stabilitas dan Efektivitas Python dengan C++, ditemukan bahwa setiap bahasa memiliki kelebihan dan kelemahan: Python lebih mudah dipelajari dan digunakan untuk prototyping cepat, sedangkan C++ lebih efisien secara kinerja dan penggunaan sumber daya [2].
        Selain itu, dalam jurnal Penerapan Pemrograman C++ dalam Pengembangan Alat di Indonesia, C++ sering dipilih sebagai bahasa inti untuk mengendalikan perangkat keras atau embedded system, karena kemampuannya berinteraksi dekat dengan perangkat keras [3].

### B. IDE / Lingkungan Pemrograman: CodeBlocks (atau Dev-C++)<br/>
#### 1. Apa itu IDE?
        IDE (Integrated Development Environment) adalah lingkungan terpadu yang menyatukan editor kode, kompilator, debugger, dan utilitas pendukung lainnya dalam satu aplikasi. Dengan IDE, coder tidak perlu berpindah-pindah antara tool berbeda (editor, terminal, debugger) — semuanya tersedia dalam satu jendela.
#### 2. CodeBlocks & Fitur Utama
        CodeBlocks adalah salah satu IDE populer untuk bahasa C/C++. Fitur-fitur utamanya antara lain:
        Dukungan kompilator seperti GCC atau MinGW.
        Interface debugging (breakpoint, stepping, watch variables).
        Auto-completion sederhana dan highlighting.
        Manajemen proyek (project), build system (makefile integrasi).
        Compile & run langsung dari IDE tanpa perlu console manual.
#### 3. Kelebihan & Tantangan Penggunaan di Praktikum
        Kelebihan:
        Memudahkan penulisan dan pengujian kode karena integrasi fitur.
        Visualisasi kesalahan (error) dan debugging secara interaktif.
        Menjadikan praktikum lebih fokus ke logika program, bukan konfigurasi teknis.Tantangan:
        Konfigurasi awal (misalnya pengaturan path ke compiler) bisa memakan waktu.
        Masalah linker atau library eksternal kadang muncul.
        Tampilan dan performa bisa berbeda antar sistem operasi.
        Bagi pemula, antarmuka IDE mungkin terasa kompleks pada awalnya.
        Jurnal Model Pembelajaran Pemrograman Bahasa C++ di Indonesia menyebut bahwa buku panduan penggunaan IDE penting agar mahasiswa (termasuk yang berkebutuhan khusus) bisa lebih mudah memahami struktur kode dan debugging [4].
## Guided 

### 1. Array

#include<iostream>
using namespace std;

int main(){
    int arr[5];

    for (int i = 0; i < 5; i++){
        cout << "masukkan value indeks ke-" << i << " : ";
        cin >> arr[i];
    }

    int j = 0;
    while(j < 5){
        cout << "isi indekss ke-" << j << " ; " << arr[j] << endl;
        j++;
    }

    return 0;
}

penjelasan singkat guided 1
Program di atas adalah contoh dasar penggunaan array dan perulangan dalam bahasa C++. Program ini meminta pengguna untuk menginput lima angka, yang kemudian disimpan di dalam array menggunakan perulangan for. Setelah semua data dimasukkan, program menampilkan kembali isi array tersebut satu per satu dengan perulangan while. Variabel j dipakai sebagai penghitung indeks agar setiap elemen bisa ditampilkan sesuai urutannya. Secara sederhana, program ini membantu mahasiswa memahami cara kerja array dan loop untuk menyimpan serta menampilkan data di C++.

### 2. Array 2 Dimensi

#include<iostream>
using namespace std;

void tampilkanHasil(int arr[2][2]){
    for(int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int arrA[2][2] = {
        {1, 2},
        {3, 4}
    };
    int arrB[2][2] = {
        {2, 3},
        {4, 5}
    };
    int arrC[2][2] = {0};
    int arrD[2][2] = {0};

    //penjumlahan matriks 2x2
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    cout << "Hasil penjumlahan : " << endl;
    tampilkanHasil(arrC);

    cout << endl;

    //perkalian matriks 2x2
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                arrD[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }

    cout << "Hasil perkalian : " << endl;
    tampilkanHasil(arrD);

    return 0;
}


penjelasan singkat guided 2
Program di atas adalah contoh operasi matriks 2x2 menggunakan C++. Dua matriks awal (arrA dan arrB) dijumlahkan dan dikalikan dengan bantuan perulangan bersarang (for). Hasil penjumlahan disimpan di arrC, sedangkan hasil perkalian di arrD. Fungsi tampilkanHasil() digunakan untuk menampilkan hasil ke layar. Secara sederhana, program ini menunjukkan cara melakukan operasi dasar matriks dengan array dua dimensi dan loop bersarang.

### 3. Funtion


#include<iostream>
using namespace std;

int cariMAX(int arr[], int ukuran){
    int MAX = arr[0];
    for(int i = 1; i < ukuran; i++){
        if(arr[i] > MAX){
            MAX = arr[i];
        }
    }
    return MAX;
}

void operasiAritmetika(int arr[], int ukuran){
    int totalJumlah = 0;
    for(int i = 0; i < ukuran; i++){
        totalJumlah += arr[i];
    }
    cout << "total penjumalahan : " << totalJumlah << endl;

    int totalKali = 1;
    for (int i = 0; i < ukuran; i++){
        totalKali =  arr[i];
    }
    cout << "Total perkalian : " << totalKali << endl
    ;
}

int main(){
    const int ukuran = 5;
    int arr[ukuran];
    for(int i = 0; i < ukuran; i++){
        cout << "masukkan nilai array ke-" << i << " : ";
        cin >> arr[i];
    }
    cout << endl;
    cout << "nilai terbesar dalam array : " << cariMAX(arr, ukuran) << endl;

    operasiAritmetika(arr, ukuran);
    return 0;
}

penjelasan singkat guided 3
Program di atas adalah fungsi untuk mengolah data dalam array. Pengguna memasukkan lima nilai, lalu fungsi cariMAX() mencari nilai terbesar, sedangkan operasiAritmetika() menghitung total penjumlahan dan perkalian elemen array. Secara singkat, program ini menunjukkan cara memakai fungsi untuk memproses data array dengan lebih terstruktur dan efisien.

### 4. Referenc


#include<iostream>
using namespace std;

void tukar(int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main(){
    int a = 20, b = 30;
    int& ref = a;

    cout << "Nilai a : " << a  << endl;
    cout << "alamat a (&a) : " << &a  << endl;
    cout << "Nilai ref (alias a) : " << ref  << endl;
    cout << "Almat ref (&ref) : " << &ref << endl;

    //menukar nilai a lewat reference
    ref = 50;
    cout << "\nsetelah ref = 50;" << a  << endl;
    cout << "Nilai a : " << a  << endl;
    cout << "Nilai ref : " << ref  << endl;
    

    tukar(a, b);
    cout << "After swapping, value of a=" << a << "and b=" << b << endl;

    return 0;
}


penjelasan singkat guided 4
Program di atas adalah contoh penggunaan reference dalam C++. Variabel ref adalah alias dari a, sehingga ketika nilai ref diubah, nilai a juga ikut berubah. Fungsi tukar() adalah fungsi yang menggunakan parameter reference untuk menukar nilai antara a dan b tanpa menggunakan pointer. Secara singkat, program ini adalah contoh cara kerja reference sebagai pengganti pointer untuk memudahkan manipulasi nilai variabel.

### 5. Pointer


#include<iostream>
using namespace std;

void tukar(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    int a = 20, b = 30;
    int  *ptr;

    ptr = &a;

    cout << "value of a : " << a  << endl;
    cout << "addres of a : " << &a  << endl;
    cout << "value stored in ptr (addres of a) : " << ptr  << endl;
    cout << "value pointed to by ptr : " << *ptr << endl;

    tukar(&a, &b);
    cout << "After swapping, value of a=" << a << "and b=" << b << endl;

    return 0;
}


penjelasan singkat guided 3
Program di atas adalah program sederhana untuk menentukan apakah seorang mahasiswa lulus atau tidak berdasarkan nilai yang diinput, sekaligus menjadi contoh penggunaan percabangan (if-else) dalam C++ untuk mengkategorikan hasil lulus atau tidak lulus sesuai dengan input nilai.

## Unguided 

### 1. Perkalian matrik 3x3

#include <iostream>
using namespace std;

void tampilMatriks(int A[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
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
    int C[3][3];

    cout << "=== Penjumlahan Matriks ===" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    tampilMatriks(C);

    cout << "\n=== Pengurangan Matriks ===" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    tampilMatriks(C);

    cout << "\n=== Perkalian Matriks ===" << endl;
    int D[3][3] = {0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                D[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    tampilMatriks(D);

    return 0;
}

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/IkfinaKamaliaRahmah/103112400090-Ikfina-Kamalia-Rahmah/blob/main/!03112400090-Ikfina-Kamalia-Rahmah/images2/Output-Unguided1-Modul2-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/IkfinaKamaliaRahmah/103112400090-Ikfina-Kamalia-Rahmah/blob/main/!03112400090-Ikfina-Kamalia-Rahmah/images2/Output-Unguided1-Modul2-2.png)

penjelasan unguided 1 
Program di atas merupakan program sederhana dalam bahasa C++ yang digunakan untuk melakukan operasi aritmatika dasar, yaitu penjumlahan, pengurangan, perkalian, dan pembagian. Program ini meminta pengguna memasukkan dua bilangan bertipe float, kemudian hasil dari setiap operasi ditampilkan ke layar. Untuk operasi pembagian, program menggunakan percabangan if-else agar lebih aman. Jika bilangan kedua tidak sama dengan nol, hasil pembagian akan ditampilkan, namun jika bilangan kedua bernilai nol, maka program akan memberikan pesan bahwa pembagian tidak dapat dilakukan. Dengan demikian, program ini memperlihatkan penggunaan input/output dasar dengan cin dan cout, serta contoh penerapan percabangan if-else untuk mengantisipasi error seperti pembagian dengan nol.

### 2. nilai dari 3 variable

#include <iostream>
using namespace std;

// Versi Pointer
void tukarPointer(int *x, int *y, int *z) {
    int temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}

// Versi Reference
void tukarReference(int &x, int &y, int &z) {
    int temp = x;
    x = y;
    y = z;
    z = temp;
}

int main() {
    int a = 10, b = 20, c = 30;

    cout << "=== Sebelum Ditukar ===" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    tukarPointer(&a, &b, &c);
    cout << "\n=== Setelah Tukar (Pointer) ===" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    tukarReference(a, b, c);
    cout << "\n=== Setelah Tukar Lagi (Reference) ===" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    return 0;
}



### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/IkfinaKamaliaRahmah/103112400090-Ikfina-Kamalia-Rahmah/blob/main/!03112400090-Ikfina-Kamalia-Rahmah/images2/Output-Unguided2-Modul2-3.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/IkfinaKamaliaRahmah/103112400090-Ikfina-Kamalia-Rahmah/blob/main/!03112400090-Ikfina-Kamalia-Rahmah/images2/Output-Unguided2-Modul2-4.png)

penjelasan unguided 2
Program ini adalah implementasi konsep pointer dan reference untuk menukar nilai tiga variabel (a, b, dan c). Fungsi tukarPointer() menggunakan alamat memori (&) untuk menukar nilai variabel dengan bantuan pointer, sedangkan fungsi tukarReference() menggunakan reference (&x) yang bertindak sebagai alias dari variabel aslinya. Hasilnya, nilai-nilai dari ketiga variabel tersebut akan saling bertukar posisi tanpa perlu menggunakan variabel tambahan di luar fungsi. Program ini menunjukkan perbedaan antara penggunaan pointer dan reference, di mana reference lebih sederhana dan langsung, sementara pointer memberikan kontrol lebih dalam terhadap alamat memori.

### 3. Array 1 Dimensi

#include <iostream>
using namespace std;

int cariMaksimum(int arr[], int n) {
    int maks = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maks) maks = arr[i];
    }
    return maks;
}

int cariMinimum(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
    }
    return min;
}

float hitungRataRata(int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) total += arr[i];
    return (float)total / n;
}

void tampilkanArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arrA[] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int n = sizeof(arrA) / sizeof(arrA[0]);
    int pilihan;

    do {
        cout << "\n--- Menu Program Array ---\n";
        cout << "1. Tampilkan isi array\n";
        cout << "2. Cari nilai maksimum\n";
        cout << "3. Cari nilai minimum\n";
        cout << "4. Hitung nilai rata-rata\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Isi array: ";
                tampilkanArray(arrA, n);
                break;
            case 2:
                cout << "Nilai maksimum: " << cariMaksimum(arrA, n) << endl;
                break;
            case 3:
                cout << "Nilai minimum: " << cariMinimum(arrA, n) << endl;
                break;
            case 4:
                cout << "Nilai rata-rata: " << hitungRataRata(arrA, n) << endl;
                break;
            case 5:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 5);

    return 0;
}

### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/IkfinaKamaliaRahmah/103112400090-Ikfina-Kamalia-Rahmah/blob/main/103112400090-Ikfina-Kamalia-Rahmah/images2/Output-Unguided3-Modul2-5.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/IkfinaKamaliaRahmah/103112400090-Ikfina-Kamalia-Rahmah/blob/main/!03112400090-Ikfina-Kamalia-Rahmah/images2/Output-Unguided3-Modul2-6.png)

penjelasan unguided 3
Program ini adalah contoh penerapan array satu dimensi dan fungsi-fungsi terpisah untuk mengolah data numerik. Array arrA berisi 10 angka, dan program menyediakan menu interaktif menggunakan switch-case agar pengguna bisa memilih operasi yang diinginkan, seperti: 
1️. Menampilkan isi array 
2️. Mencari nilai maksimum (cariMaksimum()) 
3️. Mencari nilai minimum (cariMinimum()) 
4️. Menghitung nilai rata-rata (hitungRataRata()) 
Perhitungan dilakukan dengan perulangan sederhana, sedangkan perintah do-while digunakan untuk mengulang menu sampai pengguna memilih keluar.

## Kesimpulan
praktikum ini dapat disimpulkan bahwa bahasa pemrograman C++ merupakan bahasa yang kuat dan fleksibel karena mendukung pemrograman prosedural maupun berorientasi objek. Melalui penggunaan IDE Code::Blocks, mahasiswa dapat lebih mudah menulis, menjalankan, dan mempelajari struktur program C++ tanpa harus melakukan kompilasi manual.

Pada bagian guided, mahasiswa sudah diajarkan saat pratikum bersama asisten dosen belajar berbagai konsep dasar pemrograman seperti penggunaan array satu dimensi dan dua dimensi, fungsi, pointer, serta reference. Setiap konsep memiliki peran penting — array digunakan untuk menyimpan banyak data, fungsi membantu membuat kode lebih terstruktur, pointer dan reference memberikan cara berbeda untuk mengakses dan memanipulasi data secara efisien.

Sedangkan pada bagian unguided, mahasiswa mengembangkan pemahaman tersebut ke tingkat yang lebih kompleks dengan mengimplementasikan operasi matriks, pertukaran nilai variabel menggunakan pointer dan reference, serta pengolahan data array menggunakan fungsi terpisah. Bagian ini melatih kemampuan logika, penggunaan perulangan, kondisi, dan struktur program yang lebih dinamis.

Secara keseluruhan, praktikum ini membantu mahasiswa memahami konsep dasar hingga menengah dalam pemrograman C++, sekaligus meningkatkan keterampilan dalam menulis kode yang rapi, efisien, dan mudah dibaca. Penguasaan materi ini menjadi pondasi penting untuk memahami topik lanjutan seperti struktur data, algoritma, dan pemrograman berorientasi objek pada pertemuan berikutnya.

## Referensi
<br>[1] “Penggunaan Bahasa C++ dalam Perkuliahan Jurusan Teknik Elektro,” Jurnal Majemuk, Vol. 3 No. 1, 2024. 
<br>[2] “Komparasi Stabilitas dan Efektivitas Python dengan C++,” Jurnal Arjuna, (2023). 
<br>[3] “Penerapan Pemrograman C++ dalam Pengembangan Alat,” Jurnal Majemuk. 
<br>[4] “Model Pembelajaran Pemrograman Bahasa C++,” Jurnal Maklumatika Vol. 8, No. 2, 2022. 
<br>[5] “Pengembangan Aplikasi Kamus Bahasa Pemrograman C++ (SiKamus),” UNESA. 
<br>[6] “Pelatihan Pemrograman C++ Melalui Tinkercad Guna Meningkatkan Kemampuan Computational Thinking Siswa SMK,” Jurnal Pengabdian, 2024. 
<br>[7] “Peningkatan Kompetensi Algoritma dan Pemrograman C/C++ bagi Siswa SMK YADIKA 4,” Jurnal Kacanegara, 2023. 