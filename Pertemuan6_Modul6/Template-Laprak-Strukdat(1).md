# <h1 align="center">Laporan Praktikum Modul 6 - DOUBLY LINKED LIST (BAGIAN PERTAMA)</h1>
<p align="center">Ikfina Kamalia Rahmah - 103112400090</p>

## Dasar Teori
### A. Bahasa Pemrograman C++ Doubly Linked List<br/>
#### 1. Sejarah dan Karakteristik Doubly Linked List
Struktur data Doubly Linked List merupakan pengembangan dari Singly Linked List yang memungkinkan penelusuran data secara dua arah. Setiap node memiliki dua pointer: next yang menunjuk ke elemen berikutnya, dan prev yang menunjuk ke elemen sebelumnya.
Struktur ini bersifat dinamis, artinya jumlah elemen dapat bertambah atau berkurang saat program berjalan tanpa harus menentukan ukuran awal seperti pada array. Doubly Linked List sangat berguna dalam aplikasi yang memerlukan navigasi dua arah seperti sistem antrian, browser history, serta fitur undo-redo [1].

Dalam bahasa C++, implementasi Doubly Linked List menggunakan konsep pointer dan struct. Dengan pointer, pengelolaan memori dilakukan secara manual untuk efisiensi dan kontrol penuh terhadap struktur data [2].
#### 2. Keunggulan dan Kelemahan Doubly Linked List
Keunggulan:
Dapat diakses dua arah (forward dan backward).
Operasi insert dan delete lebih efisien dibanding Singly Linked List karena tidak perlu traversal dari awal.
Memungkinkan fleksibilitas dalam penanganan data dinamis seperti navigasi data dua arah [3].
Kelemahan:
Menggunakan memori lebih banyak karena menyimpan dua pointer per node.
Implementasi lebih kompleks dan rentan kesalahan pointer.
Membutuhkan manajemen memori yang hati-hati untuk menghindari memory leak [4].
#### 3. Perbandingan dengan Bahasa Lain
Bahasa C++ unggul dalam hal efisiensi dan kontrol memori karena menggunakan pointer secara langsung. Berbeda dengan Java dan Python yang mengandalkan garbage collector, C++ memerlukan pengelolaan memori manual, yang menjadikannya lebih cepat namun berisiko jika tidak hati-hati [5].
C++ sangat cocok untuk aplikasi dengan kebutuhan performa tinggi seperti sistem operasi, kompilator, dan pengolahan data besar [6].

### B. IDE/ Lingkungan Pemrograman: Doubly Linked List<br/>
#### 1. Apa itu IDE?
IDE (Integrated Development Environment) adalah lingkungan pengembangan perangkat lunak terpadu yang menyediakan fasilitas lengkap bagi programmer untuk menulis, mengompilasi, dan men-debug kode secara efisien.
IDE menggabungkan berbagai komponen seperti text editor, compiler, linker, dan debugger dalam satu aplikasi terpadu. Hal ini memudahkan pengguna untuk mengembangkan program tanpa harus berpindah antar alat bantu terpisah [7].

Dalam konteks praktikum pemrograman C++, penggunaan IDE sangat penting karena membantu mahasiswa memahami struktur program, proses kompilasi, serta kesalahan sintaks (syntax error) dengan cepat dan visual.
#### 2. CodeBlocks & Fitur Utama
Code::Blocks adalah IDE open-source yang banyak digunakan untuk pemrograman C dan C++. IDE ini bersifat ringan, mudah digunakan, dan mendukung berbagai platform (Windows, Linux, dan macOS).
Fitur utama Code::Blocks meliputi:
Compiler Integration: Mendukung GNU GCC, MinGW, dan Clang compiler untuk membangun program C/C++.
Code Completion: Menyediakan saran otomatis saat mengetik kode untuk mempercepat proses penulisan.
Debugger (GDB): Membantu menemukan dan memperbaiki kesalahan logika dengan menjalankan program secara bertahap.
Multiple File Management: Mendukung proyek besar dengan banyak file (.cpp dan .h).
User Interface Modular: Tampilan antarmuka mudah disesuaikan dan ramah bagi pemula.

Dengan fitur-fitur tersebut, Code::Blocks menjadi IDE ideal dalam kegiatan praktikum pemrograman struktur data seperti Doubly Linked List karena stabil, efisien, dan mendukung proyek berorientasi modul.
#### 3. Kelebihan & Tantangan Penggunaan di Praktikum
Kelebihan:
Ringan, gratis, dan mudah digunakan.
Cocok untuk pembelajaran pemrograman dasar hingga lanjutan.
Mendukung proyek besar dengan struktur modular.

Tantangan:
Perlu konfigurasi manual pada beberapa versi untuk compiler.
Terkadang mengalami path error.
Hanya optimal untuk bahasa C/C++ [8].

## Guided 

### 1.1. ListMakanan.h

#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

#endif

### 1.2. ListMakanan.cpp
#include "listMakanan.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

### 1.3. main.cpp
#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeC);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    return 0;
}

penjelasan singkat guided 1 dengan 3 file :
Program ini merupakan implementasi doubly linked list untuk menyimpan dan mengelola data makanan. Pada file ListMakanan.h, didefinisikan struktur makanan yang berisi atribut seperti nama, jenis, harga, dan rating. Struktur node berfungsi sebagai elemen dari list yang menyimpan data makanan serta dua pointer (next dan prev) untuk menghubungkan node satu dengan yang lain. Struktur linkedlist berisi dua pointer utama yaitu first (penunjuk node pertama) dan last (penunjuk node terakhir). File ini juga mendeklarasikan berbagai fungsi dasar seperti membuat list, menambah node, mencetak isi list, dan mengubah data (update).

Pada file ListMakanan.cpp, fungsi-fungsi tersebut diimplementasikan. Fungsi createList membuat list kosong, sedangkan alokasi membuat node baru di memori dengan data yang dimasukkan, dan dealokasi menghapus node dari memori. Fungsi insertFirst, insertLast, insertAfter, dan insertBefore digunakan untuk menambahkan node di posisi tertentu dalam list. Fungsi printList menampilkan semua isi list dari node pertama hingga terakhir. Lalu, terdapat beberapa fungsi update seperti updateFirst, updateLast, updateAfter, dan updateBefore yang digunakan untuk memperbarui data pada node tertentu berdasarkan posisinya.

Pada file main.cpp, program utama dijalankan. Pertama, list dibuat kosong dengan createList, lalu lima node makanan dialokasikan dan dimasukkan ke list menggunakan berbagai metode insert hingga membentuk urutan tertentu. Setelah semua data masuk, program menampilkan seluruh isi list, lalu melakukan update data pada beberapa node (seperti node pertama, terakhir, sebelum, dan sesudah node tertentu). Setelah itu, list ditampilkan kembali untuk melihat hasil perubahannya.


### 2.1. listMakanan.h

#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

// Searching
void findByName(linkedlist List, string nama);
void findByJenis(linkedlist List, string jenis);
void findByMinRating(linkedlist List, float minRating);

// Delete
void deleteFirst(linkedlist &List);
void deleteLast(linkedlist &List);
void deleteAfter(linkedlist &List, address Prev);
void deleteBefore(linkedlist &List, address nodeNext);

void deleteNode(linkedlist &List, address target);
void deleteByName(linkedlist &List, string nama);

#endif

### 2.2. listMakanan.cpp
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

// Searching
void findByName(linkedlist List, string nama);
void findByJenis(linkedlist List, string jenis);
void findByMinRating(linkedlist List, float minRating);

// Delete
void deleteFirst(linkedlist &List);
void deleteLast(linkedlist &List);
void deleteAfter(linkedlist &List, address Prev);
void deleteBefore(linkedlist &List, address nodeNext);

void deleteNode(linkedlist &List, address target);
void deleteByName(linkedlist &List, string nama);

#endif

### 2.3. main.cpp
#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeA);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    cout << endl;

    findByName(List, "Nasgor");

    deleteByName(List, "Nasgor");
    deleteFirst(List);
    deleteBefore(List, nodeE);

    cout << endl << "--- Isi List Setelah Delete ---" << endl;
    printList(List);

    return 0;
}

penjelasan singkat guided 2 dengan 3 file :
Program di atas adalah implementasi doubly linked list untuk mengelola data makanan. Pada file listMakanan.h, didefinisikan struktur data makanan yang berisi atribut nama, jenis, harga, dan rating. Struktur node digunakan sebagai elemen list yang menyimpan data makanan dan dua pointer (next dan prev) untuk menghubungkan antar node. Struktur linkedlist menyimpan dua pointer utama, yaitu first (elemen pertama) dan last (elemen terakhir). Di header ini juga dideklarasikan berbagai fungsi untuk operasi dasar seperti insert, update, searching, dan delete.

pada file listMakanan.cpp nantinya berisi implementasi dari semua fungsi tersebut, mulai dari membuat list baru (createList), menambah elemen (insertFirst, insertLast, insertAfter, insertBefore), menampilkan isi list (printList), mengubah data (update), mencari berdasarkan nama atau rating (findByName, findByMinRating), hingga menghapus data (deleteFirst, deleteByName, dan lain-lain).

Sedangkan pada file main.cpp, program utama dijalankan. Pertama, list dibuat kosong, lalu beberapa data makanan dialokasikan dan dimasukkan ke dalam list dengan berbagai posisi untuk membentuk urutan tertentu. Setelah itu, dilakukan beberapa update dan pencarian data berdasarkan nama makanan. Program juga menghapus beberapa elemen menggunakan fungsi delete, lalu menampilkan hasil akhir list.

## Unguided 

### 1.1 Doublylist.h

#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#include <iostream>
#include <string>
using namespace std;

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;

struct ElmList {
    infotype info;
    ElmList *next;
    ElmList *prev;
};

typedef ElmList* address;

struct List {
    address First;
    address Last;
};

// --- PROTOTYPE ---
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);
address findElm(List L, string nopol);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);

#endif

### 1.2 ListAngka.cpp

#include "Doublylist.h"

// Membuat list kosong
void createList(List &L) {
    L.First = NULL;
    L.Last = NULL;
}

// Alokasi node baru
address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

// Dealokasi node
void dealokasi(address &P) {
    delete P;
    P = NULL;
}

// Menampilkan isi list
void printInfo(List L) {
    address P = L.First;
    if (P == NULL) {
        cout << "List kosong" << endl;
    } else {
        while (P != NULL) {
            cout << "No Polisi : " << P->info.nopol << endl;
            cout << "Warna     : " << P->info.warna << endl;
            cout << "Tahun     : " << P->info.thnBuat << endl;
            cout << endl;
            P = P->next;
        }
    }
}

// Menyisipkan di akhir list
void insertLast(List &L, address P) {
    if (L.First == NULL) {
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

// Mencari elemen berdasarkan nomor polisi
address findElm(List L, string nopol) {
    address P = L.First;
    while (P != NULL && P->info.nopol != nopol) {
        P = P->next;
    }
    return P;
}

// Menghapus elemen pertama
void deleteFirst(List &L, address &P) {
    if (L.First != NULL) {
        P = L.First;
        if (L.First == L.Last) {
            L.First = NULL;
            L.Last = NULL;
        } else {
            L.First = L.First->next;
            L.First->prev = NULL;
        }
        P->next = NULL;
    }
}

// Menghapus elemen terakhir
void deleteLast(List &L, address &P) {
    if (L.Last != NULL) {
        P = L.Last;
        if (L.First == L.Last) {
            L.First = NULL;
            L.Last = NULL;
        } else {
            L.Last = L.Last->prev;
            L.Last->next = NULL;
        }
        P->prev = NULL;
    }
}

// Menghapus elemen setelah Prec
void deleteAfter(address Prec, address &P) {
    if (Prec != NULL && Prec->next != NULL) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != NULL) {
            P->next->prev = Prec;
        }
        P->next = NULL;
        P->prev = NULL;
    }
}

### 1.3 main.cpp

#include "Doublylist.h"

int main() {
    List L;
    createList(L);
    infotype x;
    address P;

    int n;
    cout << "Masukkan jumlah kendaraan: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        cout << "Masukkan nomor polisi: ";
        getline(cin, x.nopol);
        cout << "Masukkan warna kendaraan: ";
        getline(cin, x.warna);
        cout << "Masukkan tahun kendaraan: ";
        cin >> x.thnBuat;
        cin.ignore();

        // Cek apakah nopol sudah ada
        if (findElm(L, x.nopol) != NULL) {
            cout << "Nomor polisi sudah terdaftar.\n\n";
        } else {
            P = alokasi(x);
            insertLast(L, P);
            cout << "Data berhasil ditambahkan.\n\n";
        }
    }

    cout << "DATA LIST 1\n";
    printInfo(L);

    // Mencari kendaraan
    string cari;
    cout << "Masukkan Nomor Polisi yang dicari: ";
    getline(cin, cari);
    P = findElm(L, cari);
    if (P != NULL) {
        cout << "\nNomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan.\n";
    }

    // Menghapus data
    string hapus;
    cout << "\nMasukkan Nomor Polisi yang akan dihapus: ";
    getline(cin, hapus);
    P = findElm(L, hapus);
    if (P != NULL) {
        address Q;
        if (P == L.First) {
            deleteFirst(L, Q);
        } else if (P == L.Last) {
            deleteLast(L, Q);
        } else {
            deleteAfter(P->prev, Q);
        }
        dealokasi(Q);
        cout << "Data dengan nomor polisi " << hapus << " berhasil dihapus.\n";
    } else {
        cout << "Data tidak ditemukan.\n";
    }

    cout << "\nDATA LIST 1 setelah dihapus:\n";
    printInfo(L);

    return 0;
}



penjelasan unguided 1
Program ini merupakan implementasi ADT (Abstract Data Type) Doubly Linked List yang digunakan untuk menyimpan dan memanipulasi data kendaraan, dengan atribut berupa "nomor polisi", "warna kendaraan", dan "tahun pembuatan". Struktur data ini memungkinkan setiap elemen saling terhubung dua arah — ke elemen sebelumnya dan elemen sesudahnya — sehingga memudahkan proses penelusuran dan penghapusan data dari kedua sisi list.

Pada file Doublylist.h, didefinisikan beberapa struktur utama. Struktur "kendaraan" berfungsi sebagai tipe data informasi (infotype) yang menyimpan detail kendaraan. Struktur "ElmList" digunakan untuk mendefinisikan satu simpul (node) pada list, yang berisi "info" bertipe "kendaraan" serta dua pointer "next" dan "prev" untuk menghubungkan antar elemen. Struktur "List" menyimpan dua pointer utama, yaitu "First" dan "Last", yang masing-masing menunjuk ke elemen pertama dan terakhir dari list. Selain itu, pada file ini juga dideklarasikan berbagai prosedur dan fungsi yang akan diimplementasikan pada file ".cpp".

Selanjutnya, file "Doublylist.cpp" berisi implementasi dari fungsi-fungsi tersebut. Fungsi "createList" digunakan untuk menginisialisasi list agar kosong dengan mengatur "First" dan "Last" menjadi "NULL". Fungsi "alokasi" berfungsi untuk membuat node baru di memori heap dengan data kendaraan yang diinputkan pengguna, sedangkan "dealokasi" digunakan untuk menghapus node dari memori agar tidak terjadi kebocoran memori. Prosedur "insertLast" digunakan untuk menambahkan node baru di akhir list, baik pada kondisi list kosong maupun sudah berisi elemen. Fungsi "findElm" digunakan untuk mencari node berdasarkan "nomor polisi" kendaraan; jika ditemukan, fungsi ini mengembalikan alamat node tersebut. Prosedur "printInfo" menampilkan seluruh data kendaraan dalam list secara berurutan. Sementara itu, prosedur "deleteFirst", "deleteLast", dan "deleteAfter" masing-masing digunakan untuk menghapus elemen pertama, terakhir, atau elemen di tengah list setelah node tertentu, dengan tetap menjaga keterhubungan antar node agar struktur list tetap konsisten.

Terakhir, pada file "main.cpp", program utama berjalan. Pengguna diminta untuk memasukkan beberapa data kendaraan. Setiap data yang dimasukkan akan dicek terlebih dahulu menggunakan fungsi "findElm" untuk memastikan bahwa "nomor polisi belum pernah terdaftar". Jika belum ada, data akan disimpan menggunakan prosedur "insertLas" . Setelah semua data dimasukkan, program akan menampilkan seluruh isi list menggunakan "printInfo". Selanjutnya, pengguna dapat mencari kendaraan berdasarkan nomor polisi untuk melihat detail informasinya. Program juga memungkinkan pengguna untuk menghapus data kendaraan tertentu dengan mencocokkan nomor polisi dan memanggil prosedur delete yang sesuai (apakah di awal, akhir, atau tengah list). Setelah penghapusan, list akan diperbarui dan ditampilkan kembali untuk menunjukkan hasil akhirnya.

Secara keseluruhan, program ini menunjukkan cara kerja "doubly linked list" dalam manajemen data dinamis, di mana pengguna dapat menambah, mencari, menampilkan, dan menghapus data dengan fleksibilitas tinggi karena setiap elemen memiliki dua arah pointer yang saling terhubung.

### Output Unguided 1 :

##### Output 1.1
![Screenshot Output Unguided 1_1](https://github.com/IkfinaKamaliaRahmah/103112400090-Ikfina-Kamalia-Rahmah/blob/main/!03112400090-Ikfina-Kamalia-Rahmah/images6/Output-Unguided1-Modul6-1.png)

##### Output 1.2
![Screenshot Output Unguided 1_1](https://github.com/IkfinaKamaliaRahmah/103112400090-Ikfina-Kamalia-Rahmah/blob/main/!03112400090-Ikfina-Kamalia-Rahmah/images6/Output-Unguided1-Modul6-2.png)


## Kesimpulan
Pada pratikum modul 6 ini, kita belajar tentang implementasi Doubly Linked List menggunakan bahasa pemrograman C++. Struktur data ini merupakan versi lanjutan dari Singly Linked List karena setiap node memiliki dua pointer, yaitu next dan prev, sehingga data bisa diakses dari dua arah, baik maju maupun mundur. Dalam praktikum ini, kita diajarkan cara membuat list, menambah data, mengupdate, dan menampilkan isi list dengan menggunakan konsep node dan pointer. Selain itu, kita juga belajar bagaimana mengatur penggunaan memori di C++ agar setiap node yang sudah tidak dipakai bisa dihapus dengan benar menggunakan fungsi dealokasi. Pada bagian guided, program dibuat untuk mengelola data makanan, sedangkan pada bagian unguided konsepnya diterapkan pada data kendaraan dengan tambahan fitur pencarian dan penghapusan data. Dengan bantuan IDE Code::Blocks, proses kompilasi dan pengecekan error jadi lebih mudah. Secara keseluruhan, praktikum ini membantu kita memahami bagaimana cara kerja struktur data dinamis dan melatih kemampuan dalam mengelola data secara efisien menggunakan Doubly Linked List.

## Referensi

<br>[1] Haryanto, A., & Yuliana, N. (2021). Implementasi Struktur Data Linked List pada Sistem Antrian Pelayanan. Jurnal Teknologi dan Sistem Informasi, 9(2), 45–52.
[2] Setiawan, I., & Rahmad, D. (2020). Analisis dan Implementasi Doubly Linked List pada Pengelolaan Data Mahasiswa. Jurnal Ilmiah Informatika, 8(1), 33–40.
[3] Nugroho, A. (2022). Penerapan Struktur Data Doubly Linked List dalam Sistem Manajemen Parkir. Jurnal Komputasi dan Sistem Informasi, 10(3), 65–73.
[4] Pratama, F., & Siregar, H. (2023). Optimasi Struktur Data Linked List untuk Efisiensi Memori pada Bahasa C++. Jurnal Teknologi dan Komputasi, 7(1), 11–19.
[5] Wibowo, S. (2022). Perbandingan Efisiensi Implementasi Linked List pada Bahasa Pemrograman C++, Java, dan Python. Jurnal Sistem Informasi dan Teknologi, 6(4), 77–84.
[6] Siregar, T., & Lestari, N. (2021). Evaluasi Kinerja Implementasi Struktur Data pada Bahasa C++ dan Python. Jurnal Ilmiah Teknologi Informasi, 9(2), 25–33.
[7] Rahmawati, N. (2021). Pemanfaatan IDE dalam Pembelajaran Pemrograman C++ di Perguruan Tinggi. Jurnal Pendidikan Teknologi Informasi, 5(2), 121–130.
[8] Alamsyah, R. (2020). Analisis Efektivitas Penggunaan IDE Code::Blocks pada Praktikum Pemrograman Dasar. Jurnal Rekayasa dan Teknologi, 4(1), 59–66.
