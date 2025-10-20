# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Ikfina Kamalia Rahmahh - 103112400090</p>

## Dasar Teori
### A. Pengertian Linked List<br/>
#### 1. Pengertian
Linked list atau senarai berantai merupakan struktur data dinamis yang terdiri dari serangkaian simpul (node) yang saling terhubung melalui pointer. Setiap node terdiri atas dua bagian utama, yaitu data (informasi yang disimpan) dan pointer (next) yang menunjuk ke node berikutnya [1]. Berbeda dengan array yang memiliki ukuran tetap, linked list memungkinkan penyimpanan data secara fleksibel tanpa perlu menentukan ukuran awal.

Struktur ini digunakan untuk menyimpan data yang ukurannya dapat berubah-ubah, sehingga efisien dalam hal penggunaan memori dibandingkan array [2]. Linked list juga sering digunakan untuk mengimplementasikan struktur data lain seperti stack, queue, dan graph.
#### 2.Keunggulan dan Kelemahan C++
Keunggulan:
Memiliki fleksibilitas tinggi karena dapat melakukan alokasi memori secara dinamis.
Mempermudah operasi manipulasi data seperti penambahan atau penghapusan elemen.
Mendukung implementasi struktur data kompleks seperti stack dan queue.

Kelemahan:
Akses data tidak dapat dilakukan secara langsung, harus melalui traversal dari awal.
Membutuhkan memori tambahan untuk menyimpan pointer.
Risiko kebocoran memori (memory leak) jika tidak dilakukan penghapusan node dengan benar.
#### 3. jenis-jenis Linked List
Dalam implementasi linked list, bahasa C++ unggul karena memiliki dukungan terhadap pointer dan pengelolaan memori manual menggunakan operator new dan delete, sehingga programmer memiliki kontrol penuh atas struktur data.
Sementara itu, bahasa seperti Java dan Python menggunakan garbage collector yang mengelola memori secara otomatis, membuat implementasi linked list lebih sederhana namun kurang efisien untuk pemrosesan berkecepatan tinggi [2].

### B. Singly Linked List dan IDE CodeBlocks<br/>
#### 1. Apa itu IDE?
IDE (Integrated Development Environment) adalah lingkungan pengembangan terpadu yang menyediakan berbagai alat untuk membantu programmer menulis, mengompilasi, men-debug, dan menjalankan program secara efisien. IDE menggabungkan editor kode, compiler, debugger, dan terminal dalam satu aplikasi untuk mempermudah proses pengembangan perangkat lunak [3].
#### 2. CodeBlocks & Fitur Utama
CodeBlocks merupakan IDE yang populer untuk bahasa pemrograman C dan C++. Fitur utamanya meliputi:
Editor kode dengan syntax highlighting dan auto-completion.
Compiler integration (seperti GCC atau MinGW) untuk mengompilasi kode secara langsung.
Debugger tools yang membantu menemukan kesalahan logika atau runtime.
Kemampuan membuat proyek multi-file dan menautkan library eksternal.
#### 3. Kelebihan & Tantangan Penggunaan di Praktikum
Kelebihan:
Tampilan CodeBlocks cukup simpel dan gampang dipahami, jadi cocok banget buat mahasiswa yang baru belajar ngoding.
Aplikasinya gratis, open-source, dan nggak berat dijalankan di laptop spesifikasi standar.
Bisa dipakai bareng banyak compiler, jadi fleksibel kalau mau ganti-ganti compiler sesuai kebutuhan praktikum.
Tantangan:
Waktu awal install, pengaturan compiler-nya agak ribet dan bisa bikin bingung kalau belum terbiasa.
Kadang debugging-nya suka nggak jalan di beberapa versi atau sistem operasi tertentu.
Kalau salah atur proyek atau file path, program bisa error pas dikompilasi dan lumayan bikin pusing nyari penyebabnya.

## Guided 

### 1.1. list.h

// Header guard digunakan untuk mencegah file header yang sama 
// di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; // Memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node* address;    // Mendefinisikan alias address sebagai pointer ke struct node

struct node { // Node untuk isi dari linked list-nya, isi setiap node adalah data & pointer next
    dataMahasiswa isiData;
    address next;
};

// Ini struct untuk linked list-nya
struct linkedList {
    address first;
};
// Semua function & prosedur yang akan dipakai
bool isEmpty(linkedList List);
void createList(linkedList &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedList List);
void insertFirst(linkedList &List, address nodeBaru);
void insertAfter(linkedList &List, address nodeBaru, address Prev);
void insertLast(linkedList &List, address nodeBaru);

void delFirst(linkedList &List);
void delLast(linkedList &List);
void delAfter(linkedList &List, address nodeHapus, address nodePrev);
int nbList(linkedList List);
void deleteList(linkedList &List);

#endif

###1.2. list.cpp

#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedList List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedList &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isiData.nama = nama;
    nodeBaru->isiData.nim = nim; 
    nodeBaru->isiData.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
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

//prosedur untuk menampilkan isi list
void printList(linkedList List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isiData.nama << ", NIM : " << nodeBantu->isiData.nim 
            << ", Usia : " << nodeBantu->isiData.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

### 1.3. main.cpp

#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}

penjelasan singkat guided 1 dengan 3 file
1.1. list.h
Berisi deklarasi:
Struct (mahasiswa, node, linkedList)
typedef
Semua fungsi & prosedur (prototype) yang digunakan oleh file lain.
→ File ini menjadi “kontrak” atau “header” agar file lain tahu fungsi apa yang tersedia.

1.2️. list.cpp
Berisi implementasi dari fungsi-fungsi yang dideklarasikan di list.h
Misalnya:
bool isEmpty(linkedList List) { ... }
void createList(linkedList &List) { ... }
→ Karena di awal ada #include "list.h", maka compiler tahu bahwa fungsi ini merupakan implementasi dari deklarasi di header.

1.3. main.cpp
Berisi program utama (fungsi main()) yang:
Memanggil fungsi-fungsi dari list.cpp
Menggunakan tipe data & struct dari list.h
→ Di sini kamu sudah menulis:
#include "list.h"
yang artinya main.cpp akan mengenal semua deklarasi dari header dan otomatis bisa memakai fungsi dari list.cpp. dan bisa dijalankan lewat main.cpp.

### 2.1. list.h

// Header guard digunakan untuk mencegah file header yang sama 
// di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; // Memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node* address;    // Mendefinisikan alias address sebagai pointer ke struct node

struct node { // Node untuk isi dari linked list-nya, isi setiap node adalah data & pointer next
    dataMahasiswa isiData;
    address next;
};

struct linkedList { // Ini linked list-nya
    address first;
};

// semua function & prosedur yang akan dipakai
bool isEmpty(linkedList list);
void createList(linkedList &list);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedList list);
void insertFirst(linkedList &list, address nodeBaru);
void insertAfter(linkedList &list, address nodeBaru, address Prev);
void insertLast(linkedList &list, address nodeBaru);

void delFirst(linkedList &list);
void delLast(linkedList &list);
void delAfter(linkedList &list, address nodeHapus, address nodePrev);
int nbList(linkedList list);
void deleteList(linkedList &list);

#endif

### 2.2. list.cpp

#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedList List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedList &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isiData.nama = nama;
    nodeBaru->isiData.nim = nim; 
    nodeBaru->isiData.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
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

//prosedur untuk menampilkan isi list
void printList(linkedList List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isiData.nama << ", NIM : " << nodeBantu->isiData.nim 
            << ", Usia : " << nodeBantu->isiData.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

### 2.3. main.cpp

#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
penjelasan singkat guided 2
2.1. File list.h
File ini berisi deklarasi struktur dan fungsi untuk program linked list. Di dalamnya terdapat struct mahasiswa, node, dan linkedList, serta prototype fungsi seperti createList, isEmpty, insertFirst, dan printList. Tujuannya agar file lain dapat menggunakan tipe data dan fungsi ini tanpa menulis ulang.

2.2 File list.cpp
File list.cpp merupakan tempat implementasi dari semua fungsi yang telah dideklarasikan di list.h. Di sini terdapat kode yang menjelaskan cara kerja setiap operasi dalam linked list. Misalnya, createList membuat list kosong dengan mengatur pointer first ke Nil, isEmpty memeriksa apakah list kosong, alokasi digunakan untuk membuat node baru di memori, dan dealokasi untuk menghapus node agar memori tidak bocor. Fungsi insertFirst, insertAfter, dan insertLast digunakan untuk menambahkan node di awal, tengah, dan akhir list, sedangkan printList berfungsi menampilkan semua data mahasiswa di dalam list. Intinya, file list.cpp berisi seluruh logika utama dan algoritma pengelolaan data dalam linked list.

2.3. File main.cpp
File ini berisi program utama yang menjalankan semua fungsi dari list.cpp. Program membuat list, menambahkan beberapa data mahasiswa, lalu menampilkan hasilnya ke layar. File ini berfungsi sebagai penguji dan demonstrasi cara kerja linked list.

## Unguided 

### 1.1. list.h

// Header guard digunakan untuk mencegah file header yang sama 
// di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; // Memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node* address;    // Mendefinisikan alias address sebagai pointer ke struct node

struct node { // Node untuk isi dari linked list-nya, isi setiap node adalah data & pointer next
    dataMahasiswa isiData;
    address next;
};

// Ini struct untuk linked list-nya
struct linkedList {
    address first;
};
// Semua function & prosedur yang akan dipakai
bool isEmpty(linkedList List);
void createList(linkedList &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedList List);
void insertFirst(linkedList &List, address nodeBaru);
void insertAfter(linkedList &List, address nodeBaru, address Prev);
void insertLast(linkedList &List, address nodeBaru);

void delFirst(linkedList &List);
void delLast(linkedList &List);
void delAfter(linkedList &List, address nodeHapus, address nodePrev);
int nbList(linkedList List);
void deleteList(linkedList &List);

#endif

### 1.2. list.cpp

#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedList List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedList &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isiData.nama = nama;
    nodeBaru->isiData.nim = nim; 
    nodeBaru->isiData.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
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

//prosedur untuk menampilkan isi list
void printList(linkedList List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isiData.nama << ", NIM : " << nodeBantu->isiData.nim 
            << ", Usia : " << nodeBantu->isiData.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

### 1.3. main.cpp

#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/IkfinaKamaliaRahmah/103112400090-Ikfina-Kamalia-Rahmah/blob/main/!03112400090-Ikfina-Kamalia-Rahmah/images4/Output-Unguided1-Modul4-1.png)


penjelasan unguided 1 
Program di atas merupakan implementasi Singly Linked List dalam bahasa C++ yang digunakan untuk menyimpan dan menampilkan data mahasiswa secara dinamis. Pada file list.h, didefinisikan beberapa struktur penting seperti mahasiswa, node, dan linkedList. Struktur mahasiswa berisi atribut nama, nim, dan umur, sedangkan node berfungsi sebagai simpul (elemen) dalam linked list yang menyimpan satu data mahasiswa serta pointer next yang menunjuk ke node berikutnya. Struktur linkedList memiliki satu pointer bernama first yang menjadi penanda awal dari list. Pada file list.cpp, diimplementasikan berbagai fungsi seperti createList() untuk membuat list kosong, alokasi() untuk membuat node baru, serta insertFirst(), insertAfter(), dan insertLast() yang digunakan untuk menambah node di awal, di tengah, dan di akhir list. Fungsi printList() digunakan untuk menampilkan seluruh isi list ke layar.
Dalam file main.cpp, program utama dimulai dengan membuat list kosong menggunakan createList(List), kemudian dialokasikan lima node berisi data mahasiswa bernama Dhimas, Arvin, Rizal, Satrio, dan Joshua. Node-node ini kemudian disisipkan ke dalam list menggunakan berbagai metode insert agar membentuk urutan tertentu. Setelah semua data dimasukkan, program menampilkan isi list dengan memanggil fungsi printList(List). Hasil akhirnya adalah daftar mahasiswa lengkap dengan nama, NIM, dan usia mereka yang tersimpan secara berurutan di dalam linked list. Program ini menunjukkan bagaimana linked list dapat digunakan untuk menyimpan data secara fleksibel tanpa harus menentukan ukuran awal seperti pada array.

### 2.1. Singlylist.h

#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct List {
    Node* head;
};

// Fungsi dasar
void createList(List &L);
Node* alokasi(int x);
void insertFirst(List &L, Node* newNode);
void insertLast(List &L, Node* newNode);
void insertAfter(Node* prevNode, Node* newNode);

// Operasi penghapusan
void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(Node* prevNode);

// Operasi tambahan
int nbList(List L);
void deleteList(List &L);
void printList(List L);

#endif

### 2.2. Singlylist.cpp

#include "Singlylist.h"

void createList(List &L) {
    L.head = nullptr;
}

Node* alokasi(int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = nullptr;
    return newNode;
}

void insertFirst(List &L, Node* newNode) {
    newNode->next = L.head;
    L.head = newNode;
}

void insertLast(List &L, Node* newNode) {
    if (L.head == nullptr) {
        L.head = newNode;
    } else {
        Node* temp = L.head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
}

void insertAfter(Node* prevNode, Node* newNode) {
    if (prevNode != nullptr) {
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }
}

void deleteFirst(List &L) {
    if (L.head != nullptr) {
        Node* temp = L.head;
        L.head = L.head->next;
        delete temp;
    }
}

void deleteLast(List &L) {
    if (L.head == nullptr) return;

    if (L.head->next == nullptr) {
        delete L.head;
        L.head = nullptr;
    } else {
        Node* temp = L.head;
        while (temp->next->next != nullptr)
            temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }
}

void deleteAfter(Node* prevNode) {
    if (prevNode != nullptr && prevNode->next != nullptr) {
        Node* temp = prevNode->next;
        prevNode->next = temp->next;
        delete temp;
    }
}

int nbList(List L) {
    int count = 0;
    Node* temp = L.head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

void deleteList(List &L) {
    while (L.head != nullptr) {
        deleteFirst(L);
    }
}

void printList(List L) {
    Node* temp = L.head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

### 2.3. main.cpp

#include "Singlylist.h"

int main() {
    List L;
    createList(L);

    // Membuat list awal seperti soal 1: 9 -> 12 -> 0 -> 8 -> 2
    insertFirst(L, alokasi(9));
    insertLast(L, alokasi(8));
    insertLast(L, alokasi(2));

    Node* temp = L.head;
    insertAfter(temp, alokasi(12));     // setelah 9
    insertAfter(temp->next, alokasi(0)); // setelah 12

    // Hasil awal: 9 -> 12 -> 0 -> 8 -> 2

    // ====== NOMOR 2 ======
    // 1. Hapus node 9
    deleteFirst(L);

    // 2. Hapus node 2
    deleteLast(L);

    // 3. Hapus node 8 menggunakan deleteAfter
    Node* prev = L.head;
    while (prev != nullptr && prev->next != nullptr) {
        if (prev->next->data == 8)
            break;
        prev = prev->next;
    }
    deleteAfter(prev);

    // Cetak hasil akhir
    printList(L);
    cout << "Jumlah node : " << nbList(L) << endl;
    cout << endl;

    // 4. Hapus seluruh node
    deleteList(L);
    cout << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/IkfinaKamaliaRahmah/103112400090-Ikfina-Kamalia-Rahmah/blob/main/!03112400090-Ikfina-Kamalia-Rahmah/images4/Output-Unguided2-Modul4-2.png)

penjelasan unguided 2
Program diatas merupakan implementasi Singly Linked List dalam C++ yang digunakan untuk menambah, menampilkan, dan menghapus data secara dinamis. Pada file Singlylist.h didefinisikan struktur Node yang menyimpan data dan pointer next, serta struktur List yang memiliki pointer head sebagai penunjuk node pertama. Di file Singlylist.cpp, terdapat fungsi untuk membuat list, menambah node (insertFirst, insertLast, insertAfter), menghapus node (deleteFirst, deleteLast, deleteAfter), menghitung jumlah node (nbList), dan menghapus seluruh list (deleteList). Pada main.cpp, program membuat list awal 9 → 12 → 0 → 8 → 2, lalu menghapus node 9, 2, dan 8 sesuai perintah soal hingga tersisa 12 → 0. Terakhir, semua node dihapus hingga list kosong. Program ini menunjukkan bagaimana linked list dapat menyimpan dan mengelola data dengan cara yang fleksibel tanpa harus menentukan ukuran tetap seperti array.

## Kesimpulan
Dari praktikum ini dapat disimpulkan bahwa Linked List merupakan salah satu struktur data dinamis yang sangat berguna untuk menyimpan dan mengelola data yang jumlahnya dapat berubah-ubah tanpa harus menentukan ukuran tetap seperti pada array. Melalui implementasi program menggunakan bahasa C++ dan IDE CodeBlocks, saya dapat memahami bagaimana setiap node saling terhubung melalui pointer dan bagaimana operasi dasar seperti insert, delete, dan traversal (print) bekerja secara manual. Pada bagian guided maupun unguided, mahasiswa belajar membuat fungsi untuk menambah node di awal, tengah, dan akhir list, serta menghapus node dengan berbagai cara. Selain itu, penggunaan pointer dan manajemen memori dengan new dan delete juga melatih pemahaman terhadap konsep alokasi dan dealokasi memori secara dinamis. Secara keseluruhan, praktikum ini sangat membantu mahasiswa memahami konsep dasar struktur data Singly Linked List, cara implementasinya dalam C++, serta pentingnya pengelolaan memori yang efisien dalam pemrograman berbasis struktur data.

## Referensi
[1] A. Hidayat, “Implementasi Struktur Data Linked List Dalam Bahasa Pemrograman C++,” Jurnal Teknologi dan Sistem Informasi, vol. 8, no. 2, 2022.
[2] F. Nurfalah, “Perbandingan Kinerja Struktur Data Array dan Linked List,” Jurnal Informatika UIN Syarif Hidayatullah Jakarta, 2021.
[3] A. P. Pratama dan I. D. Putra, “Analisis dan Implementasi Struktur Data Linked List Pada Aplikasi Penyimpanan Data,” Jurnal Nasional Informatika dan Teknologi, vol. 7, no. 1, 2020.<br>
