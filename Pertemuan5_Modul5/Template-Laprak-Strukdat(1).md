# <h1 align="center">Laporan Praktikum Modul  5- Singly Linked list (Bagian kedua)</h1>
<p align="center">Ikfina Kamalia Rahmah - 103112400090</p>

## Dasar Teori

### A. Pengertian dan Struktur Singly Linked List<br/>
Struktur data linked list atau senarai berantai adalah struktur data dinamis yang terdiri atas simpul-simpul (nodes) yang terhubung secara sekuensial melalui pointer atau referensi. Setiap node biasanya berisi dua bagian, yaitu data dan pointer yang menunjuk ke node berikutnya. Node terakhir menunjuk ke NULL sebagai penanda akhir daftar. Linked list memungkinkan ukuran data berubah-ubah (dinamis) selama program berjalan, tidak seperti array yang memiliki ukuran tetap [1].

Singly Linked List (senarai berantai tunggal) merupakan jenis paling sederhana dari linked list, di mana setiap node hanya menyimpan satu pointer menuju node berikutnya. Operasi traversing hanya dapat dilakukan searah, dari node pertama (head) ke node terakhir (tail) [2].

Struktur dasar node dalam singly linked list dapat digambarkan sebagai berikut:
#### 1. Karakteristik Singly Linked List
    Bersifat dinamis, ukuran dapat bertambah atau berkurang sesuai kebutuhan.
    Menggunakan pointer untuk menghubungkan antar node.
    Akses data searah, dari awal menuju akhir.
    Efisien untuk operasi penyisipan dan penghapusan dibanding array, karena tidak perlu menggeser elemen [3].
#### 2. Komponen Utama
    Node — berisi data dan pointer next.
    Head — pointer yang menunjuk ke node pertama.
    NULL — penanda akhir list.
#### 3. Kelebihan dan Kekurangan
    Kelebihan:
    Memori digunakan secara fleksibel dan efisien.
    Penambahan/penghapusan data cepat tanpa perlu menggeser seluruh elemen.

    Kekurangan:
    Tidak mendukung akses acak seperti array.
    Membutuhkan memori tambahan untuk pointer.
    Akses dua arah tidak dimungkinkan (hanya satu arah) [4].

### B. Operasi-Operasi pada Singly Linked List<br/>
...
#### 1. Operasi Dasar
    Operasi dasar yang biasa dilakukan pada singly linked list meliputi:
    createList() — membuat list kosong.
    isEmpty() — memeriksa apakah list kosong.
    alokasi() — membuat node baru dan mengalokasikan memori.
    dealokasi() — menghapus node dan membebaskan memori.
    insertFirst(), insertAfter(), insertLast() — menambah node di awal, tengah, atau akhir list.
    delFirst(), delAfter(), delLast() — menghapus node di posisi awal, setelah node tertentu, atau di akhir [1][2].
#### 2. Operasi Update
    Operasi update bertujuan mengubah data yang tersimpan di node tertentu tanpa menghapus node tersebut. Fungsi yang umum digunakan:
    updateFirst() — memperbarui data pada node pertama.
    updateLast() — memperbarui data pada node terakhir.
    updateAfter() — memperbarui data setelah node tertentu.
#### 3. Operasi Searching
    Operasi searching digunakan untuk mencari node dengan kriteria tertentu, baik berdasarkan data, alamat node, maupun range nilai.
    FindNodeByData() — mencari node berdasarkan isi data.
    FindNodeByAddress() — mencari node berdasarkan alamat memori node.
    FindNodeByRange() — mencari node berdasarkan rentang nilai tertentu (misalnya harga) [3].

## Guided 

### 1.1. listBuah.h

//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include<iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah; 
    float harga;
};

typedef buah dataBuah; //Memberikan nama alias databuah untuk struct buah.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataBuah isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
//Materi modul 4
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5 (part 1 - update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

//materi modul 5 (part 2 - searching)
void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, float hargaAwal, float HargaAkhir);

#endif

###1.2. listBuah.cpp

#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 2 (SEARCHING) -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}


### 1.3. main.cpp

#include "listBuah.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    FindNodeByData(List, "kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}

penjelasan singkat guided 1 dengan 3 file

1.1 listBuah.h (Header File)
File listBuah.h ini isinya semua deklarasi dari struktur data dan fungsi yang bakal dipakai di program utama. Di bagian awal ada header guard (#ifndef, #define, #endif) biar file ini gak ke-include dua kali pas dijalankan. Di dalamnya ada beberapa struktur penting, yaitu struct buah, struct node, dan struct linkedlist. Struktur buah nyimpen data kayak nama, jumlah, dan harga buah. Terus struct node itu semacam “kotak” yang isinya data buah sama pointer next yang nyambung ke node berikutnya. Nah, struct linkedlist cuma punya satu pointer first yang nunjuk ke node pertama dalam list.
Selain itu, ada juga typedef buat bikin alias biar penulisan kode lebih simple, kayak dataBuah dan address. Di bagian bawah file ini dideklarasiin semua fungsi yang bakal dipakai buat bikin list, nambah atau hapus node, update data, sampai cari data. Secara garis besar, isinya dibagi jadi tiga bagian utama: fungsi dasar linked list (modul 4), update data (modul 5 part 1), dan searching atau pencarian data (modul 5 part 2).

1.2 listBuah.cpp (Implementasi Fungsi)
File listBuah.cpp ini bagian tempat semua fungsi yang dideklarasiin di header tadi diisi logikanya. Di sini program bener-bener “jalan”. Fungsi dasar kayak createList() dipakai buat bikin list kosong, sedangkan isEmpty() buat ngecek apakah list-nya kosong. Terus ada alokasi() buat bikin node baru dan dealokasi() buat hapus node dari memori biar gak leak. Fungsi insertFirst(), insertAfter(), dan insertLast() dipakai buat nambah node di posisi awal, tengah, atau akhir list, sedangkan delFirst(), delAfter(), dan delLast() buat ngapus node dari posisi-posisi itu.
Buat nampilin semua isi list, ada printList(), dan kalau mau tau jumlah node di dalam list bisa pakai nbList(). Kalau mau hapus semua isi list sekaligus, pakai deleteList().
Di bagian update data , ada updateFirst(), updateLast(), dan updateAfter() yang fungsinya buat ngubah data buah langsung lewat input user. Sedangkan di bagian searching , ada FindNodeByData() buat cari buah berdasarkan nama, FindNodeByAddress() buat cari node berdasarkan alamat memori, dan FindNodeByRange() buat nyari buah yang harganya ada di antara dua nilai tertentu. Semua fungsi udah dikasih pengecekan list kosong, biar program gak error pas dijalankan.

1.3 main.cpp (Program Utama)
File main.cpp ini bagian utamanya, tempat semua fungsi dari dua file sebelumnya dipakai bareng-bareng. Pertama, program bikin list kosong dengan createList(List). Lalu, dibuat beberapa node buah (kayak Jeruk, Apel, Pir, Semangka, dan Durian) pakai fungsi alokasi(). Setelah itu, semua node dimasukin ke list dengan berbagai cara — ada yang ditambah di awal (insertFirst()), di tengah (insertAfter()), dan di akhir (insertLast()). Setelah semua dimasukin, program bakal nampilin isi list dan jumlah node yang ada.
Lanjut, program nyoba update data pada node pertama, terakhir, dan setelah node tertentu lewat fungsi updateFirst(), updateLast(), dan updateAfter(). Setelah update, masuk ke bagian searching buat nyari data buah berdasarkan nama, alamat node, dan range harga lewat FindNodeByData(), FindNodeByAddress(), dan FindNodeByRange(). Setelah itu dilakukan penghapusan node satu per satu lewat delFirst(), delLast(), dan delAfter() biar bisa lihat perubahannya di list. Di akhir, program pakai deleteList() buat hapus semua data, lalu nampilin lagi list yang udah kosong.
Secara keseluruhan, program ini ngajarin cara kerja dasar Singly Linked List mulai dari bikin, nambah, ubah, hapus, sampai nyari data. Lewat latihan ini, kita jadi ngerti gimana data bisa nyambung satu sama lain pakai pointer tanpa harus tergantung sama ukuran tetap kayak array.

## Unguided 

### 1.1 ListAngka.h

#ifndef LISTANGKA_H
#define LISTANGKA_H
#define Nil NULL
#include <iostream>
using namespace std;

typedef int dataAngka;
typedef struct node *address;

struct node {
    dataAngka angka;
    address next;
};

struct linkedList {
    address first;
};

// Fungsi dasar
void createList(linkedList &L);
bool isEmpty(linkedList L);
address alokasi(int x);
void dealokasi(address &P);
void printList(linkedList L);
void insertFirst(linkedList &L, address P);
void insertLast(linkedList &L, address P);
void insertAfter(linkedList &L, address P, address Prec);
int nbList(linkedList L);
void delAfter(linkedList &L, address &P, address Prec);

// Bagian 1 - Update
void updateFirst(linkedList &L, int newVal);
void updateLast(linkedList &L, int newVal);
void updateAfter(linkedList &L, address Prec, int newVal);

// Bagian 2 - Searching
void SearchByData(linkedList L, int data);
void SearchByAddress(linkedList L, address node);
void SearchByRange(linkedList L, int nilaiMin);

// Bagian 3 - Operasi Aritmetika
int sumList(linkedList L);
int subList(linkedList L);
int multList(linkedList L);

#endif

penjelasan unguided 1 

### 1.2 ListAngka.cpp

#include "ListAngka.h"
using namespace std;

// ===================== DASAR LIST ===================== //
void createList(linkedList &L) { L.first = Nil; }

bool isEmpty(linkedList L) { return (L.first == Nil); }

address alokasi(int x) {
    address P = new node;
    P->angka = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printList(linkedList L) {
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
    } else {
        address P = L.first;
        while (P != Nil) {
            cout << P->angka << " ";
            P = P->next;
        }
        cout << endl;
    }
}

void insertFirst(linkedList &L, address P) {
    P->next = L.first;
    L.first = P;
}

void insertLast(linkedList &L, address P) {
    if (isEmpty(L)) {
        L.first = P;
    } else {
        address Q = L.first;
        while (Q->next != Nil) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void insertAfter(linkedList &L, address P, address Prec) {
    if (Prec != Nil) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

int nbList(linkedList L) {
    int count = 0;
    address P = L.first;
    while (P != Nil) {
        count++;
        P = P->next;
    }
    return count;
}

void delAfter(linkedList &L, address &P, address Prec) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = Nil;
        dealokasi(P);
    }
}

// ===================== BAGIAN 1 - UPDATE ===================== //
void updateFirst(linkedList &L, int newVal) {
    if (!isEmpty(L)) {
        L.first->angka = newVal;
    }
}

void updateLast(linkedList &L, int newVal) {
    if (!isEmpty(L)) {
        address P = L.first;
        while (P->next != Nil) {
            P = P->next;
        }
        P->angka = newVal;
    }
}

void updateAfter(linkedList &L, address Prec, int newVal) {
    if (Prec != Nil && Prec->next != Nil) {
        Prec->next->angka = newVal;
    }
}

// ===================== BAGIAN 2 - SEARCHING ===================== //
void SearchByData(linkedList L, int data) {
    address P = L.first;
    int posisi = 0;
    bool found = false;

    while (P != Nil) {
        posisi++;
        if (P->angka == data) {
            cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
            found = true;
            break;
        }
        P = P->next;
    }
    if (!found) cout << "Data " << data << " tidak ditemukan." << endl;
}

void SearchByAddress(linkedList L, address node) {
    address P = L.first;
    int posisi = 0;
    while (P != Nil) {
        posisi++;
        if (P == node) {
            cout << "Alamat node ditemukan di posisi ke-" << posisi
                 << " dengan nilai " << P->angka << endl;
            return;
        }
        P = P->next;
    }
    cout << "Alamat node tidak ditemukan dalam list." << endl;
}

void SearchByRange(linkedList L, int nilaiMin) {
    cout << "Data dengan nilai >= " << nilaiMin << ": ";
    address P = L.first;
    bool found = false;

    while (P != Nil) {
        if (P->angka >= nilaiMin) {
            cout << P->angka << " ";
            found = true;
        }
        P = P->next;
    }

    if (!found) cout << "Tidak ada data dalam rentang tersebut.";
    cout << endl;
}

// ===================== BAGIAN 3 - OPERASI ARITMETIKA ===================== //
int sumList(linkedList L) {
    int sum = 0;
    for (address P = L.first; P != Nil; P = P->next)
        sum += P->angka;
    return sum;
}

int subList(linkedList L) {
    if (isEmpty(L)) return 0;
    int result = L.first->angka;
    address P = L.first->next;
    while (P != Nil) {
        result -= P->angka;
        P = P->next;
    }
    return result;
}

int multList(linkedList L) {
    int result = 1;
    for (address P = L.first; P != Nil; P = P->next)
        result *= P->angka;
    return result;
}


### 1.3 main.cpp

#include "ListAngka.h"
#include <iostream>
using namespace std;

int main() {
    linkedList L;
    createList(L);

    // Membuat node
    address nodeA = alokasi(8);
    address nodeB = alokasi(13);
    address nodeC = alokasi(18);
    address nodeD = alokasi(25);
    address nodeE = alokasi(33);
    address nodeF = alokasi(40);

    // Operasi insert sesuai soal
    insertFirst(L, nodeB);
    insertLast(L, nodeA);
    insertAfter(L, nodeD, nodeB);
    insertFirst(L, nodeC);
    insertLast(L, nodeE);
    insertFirst(L, nodeF);

    // delete setelah nodeC
    address hapus;
    delAfter(L, hapus, nodeC);

    cout << "--- Isi List Setelah Insert dan Delete ---" << endl;
    printList(L);
    cout << endl;

    // ====================== BAGIAN 1: UPDATE ====================== //
    updateFirst(L, 50);        // Update 40 -> 50
    updateAfter(L, nodeC, 29); // Update 8 -> 29
    updateLast(L, 45);         // Update 33 -> 45
    updateAfter(L, nodeB, 20); // Update 18 -> 20

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(L);
    cout << endl;

    // ====================== BAGIAN 2: SEARCHING ====================== //
    cout << "--- Hasil Searching ---" << endl;
    SearchByData(L, 20);
    SearchByData(L, 55);
    SearchByAddress(L, nodeB);
    SearchByAddress(L, nodeA);
    SearchByRange(L, 40);
    cout << endl;

    // ====================== BAGIAN 3: OPERASI ARITMETIKA ====================== //
    cout << "--- Operasi Aritmetika ---" << endl;
    cout << "Penjumlahan : " << sumList(L) << endl;
    cout << "Pengurangan : " << subList(L) << endl;
    cout << "Perkalian   : " << multList(L) << endl;

    return 0;
}


penjelasan unguided 1
Program ini merupakan penerapan dari struktur data Singly Linked List menggunakan bahasa C++. Program dibagi menjadi tiga file utama, yaitu ListAngka.h, ListAngka.cpp, dan main.cpp. File ListAngka.h berisi deklarasi struktur data dan fungsi-fungsi utama seperti createList, insertFirst, insertAfter, insertLast, delAfter, printList, serta fungsi tambahan seperti update, searching, dan operasi aritmetika. Struktur utamanya terdiri dari node, yang menyimpan data integer dan pointer next, serta linkedList, yang memiliki pointer first sebagai penunjuk node pertama.

File ListAngka.cpp berisi implementasi dari semua fungsi yang ada di header. Fungsi-fungsi dasarnya digunakan untuk membuat list, menambah, menampilkan, dan menghapus node. Fungsi update (updateFirst, updateAfter, updateLast) digunakan untuk mengubah nilai data pada node tertentu, sedangkan fungsi searching (SearchByData, SearchByAddress, SearchByRange) digunakan untuk mencari data berdasarkan nilai, alamat, atau rentang nilai tertentu. Selain itu, terdapat fungsi operasi aritmetika seperti sumList, subList, dan multList untuk menghitung penjumlahan, pengurangan, dan perkalian dari semua elemen dalam list.

Pada file main.cpp, program menjalankan semua fungsi tersebut secara berurutan. Pertama dibuat enam node dengan nilai 8, 13, 18, 25, 33, dan 40, kemudian dimasukkan ke dalam list. Setelah dilakukan penghapusan node tertentu, list berisi 40 → 18 → 25 → 8 → 33. Nilai-nilai di dalam list kemudian diperbarui menjadi 50 → 20 → 25 → 29 → 45 melalui fungsi update. Fungsi searching digunakan untuk mencari data dan menampilkan hasil sesuai kondisi. Bagian akhir program melakukan operasi aritmetika untuk menghitung total penjumlahan, pengurangan, dan perkalian seluruh elemen list.

### Output Unguided 1 :

##### Output 1.1
![Screenshot Output Unguided 1_1](https://github.com/IkfinaKamaliaRahmah/103112400090-Ikfina-Kamalia-Rahmah/blob/main/!03112400090-Ikfina-Kamalia-Rahmah/images5/Output-Unguided1-Modul5-1.png)


## Kesimpulan
Dari keseluruhan kegiatan praktikum Modul 5: Singly Linked List (Bagian Kedua), dapat disimpulkan bahwa Singly Linked List merupakan salah satu struktur data dinamis yang sangat penting dalam pemrograman karena mampu menyimpan dan mengelola data secara fleksibel menggunakan konsep pointer. Melalui praktikum ini, mahasiswa memahami bagaimana cara kerja node yang saling terhubung satu arah, serta bagaimana setiap operasi seperti insert, delete, update, dan searching dilakukan tanpa perlu menggeser elemen seperti pada array.

Pada bagian guided, mahasiswa belajar mengimplementasikan linked list yang berisi data kompleks berupa informasi buah, lengkap dengan atribut nama, jumlah, dan harga. Program mampu menambahkan, menghapus, memperbarui, serta mencari data berdasarkan berbagai kriteria. Implementasi fungsi seperti updateFirst, updateLast, dan updateAfter menunjukkan bagaimana perubahan nilai dilakukan secara langsung pada node tertentu, sedangkan fungsi pencarian seperti FindNodeByData, FindNodeByAddress, dan FindNodeByRange membantu memahami cara traversal dan akses data menggunakan pointer.

Sedangkan pada bagian unguided, mahasiswa mengembangkan konsep yang sama dalam bentuk list angka. Program menunjukkan penerapan yang lebih sederhana, namun mencakup semua fungsi penting dalam manipulasi data — mulai dari pembuatan list, penambahan, penghapusan, pembaruan nilai, hingga operasi aritmetika seperti penjumlahan, pengurangan, dan perkalian antar node. Hal ini memperkuat pemahaman mahasiswa terhadap konsep traversal, pointer manipulation, serta efisiensi memori dalam struktur data dinamis.

Secara keseluruhan, praktikum ini mengajarkan bahwa Singly Linked List sangat berguna dalam pengelolaan data yang sering berubah-ubah ukurannya. Struktur ini lebih efisien dalam hal penambahan dan penghapusan dibandingkan array, meskipun memiliki keterbatasan karena akses data hanya bisa dilakukan searah. Dengan memahami konsep dan implementasinya, mahasiswa dapat mengembangkan struktur data yang lebih kompleks seperti Doubly Linked List atau Circular Linked List di tahap berikutnya.

## Referensi
[1] A. Chrismono & D. H. Untari Ningsih, “Single Linked List Method for Selection of SMA/SMK in Semarang,” Journal of Electrical Engineering and Embedded Systems, Universitas Muhammadiyah Sidoarjo, 2022.
[2] A. Nursikuwagus, “11 Single Linked List,” Materi Algoritma dan Struktur Data, Universitas Komputer Indonesia, 2018.
[3] Fikti UMSU, “Pengertian Linked List: Struktur Data dalam Pemrograman,” Fakultas Ilmu Komputer dan Teknologi Informasi, Universitas Muhammadiyah Sumatera Utara, 2023.
[4] R. K. Sari et al., “Implementasi Struktur Data Linked List pada Aplikasi Manajemen Data,” Jurnal Teknologi Informasi dan Komputer, Vol. 5 No. 2, 2021.
[5] I. A. Nugraha, “Analisis dan Implementasi Linked List pada Representasi Graf,” Jurnal Teknika Informatika UNS, 2020.<br>
