# <h1 align="center">Laporan Praktikum Modul 8 - QUEUE</h1>
<p align="center">Ikfina Kamalia Rahmah - 103112400090</p>

## Dasar Teori
Queue merupakan struktur data linear yang menerapkan prinsip FIFO (First In First Out), yaitu elemen yang pertama masuk akan diproses terlebih dahulu. Queue dapat diimplementasikan menggunakan linked list maupun array sesuai kebutuhan. Dalam modul ini, fokus implementasi adalah pada queue berbasis pointer dan queue berbasis array menggunakan tiga alternatif mekanisme pergerakan indeks (Alternatif 1, 2, dan 3).

Queue banyak digunakan pada sistem antrean, penjadwalan proses, buffer komunikasi, manajemen printer, dan berbagai aplikasi yang membutuhkan mekanisme antrean teratur [1]. Menurut penelitian dalam jurnal nasional, struktur data queue terbukti meningkatkan efisiensi pemrosesan aliran data berurutan pada sistem informasi [2]. Queue juga menjadi pondasi sistem antrian modern seperti layanan publik, perbankan, dan layanan digital [3] [4].

### A. Konsep Dasar Queue<br/>
Queue adalah struktur data linear berprinsip FIFO: yang pertama masuk, itulah yang pertama keluar. Elemen baru disisipkan pada tail, dan elemen paling lama dihapus dari head. Queue mirip antrean manusia di kasir atau loket tiket.
Pada implementasi pointer, queue terdiri atas node berisi data dan pointer ke node berikutnya. Pada implementasi array, elemen disimpan dalam indeks tabel berkapasitas tetap.
#### 1. Queue sangat krusial dalam komputasi:
    Sistem antrean (bank, rumah sakit, bandara)
    CPU scheduling FCFS
    Buffer streaming dan jaringan
    Sistem cetak (printer queue)
    Message queue dan event-driven system

#### 2.Operasi dasar yang memastikan FIFO adalah:
 1. Enqueue → menambahkan elemen di tail.

 2. Dequeue → menghapus elemen dari head.
#### 3. Keunggulan queue:
Meminimalkan starvation
Menjamin fairness
Mengatur aliran data secara stabil
Cocok untuk sistem real-time

### B. Representasi Queue Menggunakan Array<br/>
Penggunaan array untuk queue bersifat statis — ukuran tabel ditentukan sejak awal. Modul 8 menjelaskan tiga alternatif model pergerakan head dan tail:
#### 1. Alternatif 1 (Head tetap, Tail bergerak)
- Head selalu berada di indeks 0.
- Tail bertambah setiap enqueue.
- Saat dequeue, semua elemen harus shift satu langkah ke depan.
Kelebihan: Implementasi paling sederhana.
Kekurangan: - Operasi dequeue → O(n) (tidak efisien untuk data besar).
            - Alternatif 1 cocok untuk pengenalan queue tetapi tidak optimal untuk aplikasi nyata.
#### 2. Alternatif 2 (Head dan Tail bergerak)
- Head bergerak maju setiap dequeue.
- Tail bertambah setiap enqueue.
- Tidak ada shifting.
Kelemahan:
Bisa terjadi “penuh semu” ketika tail sudah mencapai ujung tetapi slot depan masih kosong.
Pendekatan ini lebih efisien namun memerlukan penanganan ketika penuh semua.
#### 3. Alternatif 3 (Circular Queue)
Model queue terbaik:
 1. Head dan tail bergerak melingkar (modulo).
 2. Tidak ada shifting.
 3. Tidak terjadi penuh semu.
 4. Semua operasi O(1).
Circular queue umum pada router, buffer streaming, dan scheduler OS karena efisiensinya tinggi.

### c. Primitif–Primitif Dalam Queue
#### 1. Primitif Queue Pointer (Linked List)
a. isEmpty(Q)
Memeriksa apakah queue kosong.
b. CreateQueue(Q)
Menginisialisasi head = tail = Nil.
c. alokasi(X)
Membuat node baru yang menyimpan X.
d. dealokasi(P)
Menghapus node dari memori untuk mencegah memory leak.
e. findElm(Q, X)
Mencari elemen X dalam queue.
f. fFindElm(Q, P)
Mengecek apakah alamat node P ada di queue.
g. insert(Q, P)
Operasi enqueue → menambahkan node P ke tail.
h. delete(Q, P)
Operasi dequeue → mengambil node dari head.
i. printInfo(Q)
Menampilkan isi queue dari head ke tail.
j. nbList(Q)
Menghitung jumlah elemen queue.
k. delAll(Q)
Menghapus seluruh elemen queue hingga kosong.
#### 2. Primitif Queue Tabel (Array)
a. isFull(Q)
Menentukan apakah array penuh.
b. isEmpty(Q)
Menentukan apakah queue kosong.
c. CreateQueue(Q)
Inisialisasi head = tail = -1.
d. enQueue(Q, X)
Menambahkan elemen ke tail.
e. deQueue(Q)
Menghapus elemen dari head.
f. viewQueue(Q)
Menampilkan elemen queue secara FIFO.

## Guided 

### 1.1. queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

struct queue {
    Node* head;
    Node* tail;
};

void createQueue(queue &Q);
bool isEmpty(queue Q);
bool isFull(queue Q);
void enQueue(queue &Q, const string &nama);
void deQueue(queue &Q);
void viewQueue(queue Q);
void clearQueue(queue &Q);

#endif

### 1.2. queue.cpp
#include "queue.h"
using namespace std;

void createQueue(queue &Q) {
    Q.head = nullptr;
    Q.tail = nullptr;
}

bool isEmpty(queue Q) {
    return Q.head == nullptr;
}

bool isFull(queue) {
    return false;
}

void enQueue(queue &Q, const string &nama) {
    Node* baru = new Node{nama, nullptr};
    if (isEmpty(Q)) {
        Q.head = Q.tail = baru;
    } else {
        Q.tail->next = baru;
        Q.tail = baru;
    }
    cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    Node* hapus = Q.head;
    cout << "Menghapus data " << hapus->nama << "..." << endl;
    Q.head = Q.head->next;
    if (Q.head == nullptr) {
        Q.tail = nullptr;
    }
    delete hapus;
}

void viewQueue(queue Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    int i = 1;
    for (Node* p = Q.head; p != nullptr; p = p->next) {
        cout << i++ << ". " << p->nama << endl;
    }
}

void clearQueue(queue &Q) {
    while (!isEmpty(Q)) {
        deQueue(Q);
    }
}

### 1.3. main.cpp
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    queue Q;
    createQueue (Q);

    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Atha");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    clearQueue(Q);
    return 0;
}

penjelasan singkat guided 1
Program ini mengimplementasikan struktur data Queue menggunakan linked list. Pada file queue.h, didefinisikan dua struktur utama, yaitu Node yang menyimpan data berupa nama dan pointer next, serta struktur queue yang berisi pointer head dan tail sebagai penanda elemen paling depan dan paling belakang dalam queue. Selain itu, dideklarasikan beberapa fungsi untuk mengelola queue seperti membuat queue baru, memeriksa apakah queue kosong, menambah elemen, menghapus elemen, menampilkan isi queue, dan mengosongkan queue. Pada file queue.cpp, seluruh fungsi tersebut diimplementasikan. Fungsi createQueue menginisialisasi queue agar kosong, sedangkan isEmpty mengecek apakah head bernilai null. Fungsi enQueue menambahkan node baru di bagian belakang queue; jika queue masih kosong, node tersebut menjadi head sekaligus tail. Fungsi deQueue menghapus node terdepan dan memindahkan head ke node berikutnya, serta memastikan tail juga di-set ke null jika queue menjadi kosong. Fungsi viewQueue menampilkan seluruh data mulai dari head hingga tail, dan clearQueue menghapus semua elemen dengan memanggil deQueue secara berulang.

Pada main.cpp, sebuah queue dibuat menggunakan createQueue, kemudian beberapa nama ditambahkan menggunakan enQueue. Setelah itu isi queue ditampilkan, lalu beberapa data terdepan dihapus menggunakan deQueue untuk menunjukkan cara kerja prinsip FIFO (First In First Out). Program kemudian menampilkan sisa elemen dalam queue dan menutup dengan mengosongkan seluruh isi queue menggunakan clearQueue. Penjelasan ini menunjukkan bagaimana queue berbasis linked list bekerja secara dinamis tanpa batasan ukuran dan memungkinkan operasi enqueue serta dequeue dilakukan secara efisien.

### 2.1. queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAKSIMAL = 5;

struct queue {
    string nama[MAKSIMAL];
    int head;
    int tail;
};

bool isFull(queue Q);
bool isEmpty(queue Q);
void createQueue(queue &Q); // terbentuk queue dengan head = -1 dan tail = -1
void enQueue(queue &Q, string nama);
void deQueue(queue &Q);
void viewQueue(queue Q);

#endif

### 2.2. queue.cpp
#include "queue.h"
#include <iostream>

using namespace std;

// NOTE : 
// Implementasi 1 = head diam, tail bergerak (Queue Linear Statis, kerana head nya tetap diam)
// Implementasi 2 = head bergerak, tail bergerak (Queue Linear Dinamis, karena head & tail nya sama-sama bergerak)
// Implementasi 3 = head dan tail berputar (Queue Circular, karena jika udh mentok tapi masih ada space, diputar sehingga tail bisa ada didepan head)

bool isEmpty(queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

//isFull implmenetasi 1 & 2
bool isFull(queue Q){
    if(Q.tail == MAKSIMAL - 1){
        return true;
    } else {
        return false;
    }
}

// //isFull implementasi 3
// bool isFull(queue Q){
//     if((Q.tail + 1) % MAKSIMAL == Q.head){
//         return true;
//     } else {
//         return false;
//     }
// }

void createQueue(queue &Q){ //terbentuk queue dengan head = -1 dan tail = -1 
    Q.head = -1;
    Q.tail = -1;
}
 

//enqueue implementasi 1 & 2
void enQueue(queue &Q, string nama){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.nama[Q.tail] = nama;
        cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
    }
}

// //enQueue implementasi 3
// void enQueue(queue &Q, string nama){
//     if(isFull(Q) == true){
//         cout << "Queue sudah penuh!" << endl;
//     } else {
//         if(isEmpty(Q) == true){
//             Q.head = Q.tail = 0;
//         } else {
//             Q.tail = (Q.tail + 1) % MAKSIMAL; // bergerak melingkar
//         }
//         Q.nama[Q.tail] = nama;
//         cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
//     }
// }

//dequeue implementasi 1
void deQueue(queue &Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
        for(int i = 0; i < Q.tail; i++){
            Q.nama[i] =  Q.nama[i+1];
        }
        Q.tail--;
        if(Q.tail < 0){ //kalo semua isi queue nya udh dikelaurin, set head & tail ke -1
            Q.head = -1;
            Q.tail = -1;
        }
    }
}

// //dequeue implementasi 2
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         Q.head++;
//         if(Q.head > Q.tail){ //kalo elemennya udh abis (head akan lebih 1 dari tail), maka reset ulang head & tail ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         }
//     }
// }

// //deQueue implementasi 3
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         if(Q.head == Q.tail){ //kalo elemennya tinggal 1, langsungkan saja head & tail nya reset ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         } else {
//             Q.head = (Q.head + 1) % MAKSIMAL; // bergerak melingkar
//         }
//     }
// }

//viewQueue implementasi 1 & 2
void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        for(int i = Q.head; i <= Q.tail; i++){
            cout << i -  Q.head + 1 << ". " << Q.nama[i] << endl;
        }
    }
    cout << endl;
}

// //viewQueue implementasi 3
// void viewQueue(queue Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         int i = Q.head;
//         int count = 1;
//         while(true){
//             cout << count << ". " << Q.nama[i] << endl;
//             if(i == Q.tail){
//                 break;
//             }
//             i = (i + 1) % MAKSIMAL;
//             count++;
//         }   
//     }
// }

### 2.3. main.cpp
#include "queue.h"
#include <iostream>

using namespace std;

int main(){
    queue Q;

    createQueue(Q);
    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Daffa");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    // deQueue(Q);
    // deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    return 0;
}

penjelasan singkat guided 2
Program ini adalah implementasi queue statis menggunakan array dengan kapasitas tetap (MAKSIMAL = 5). Pada file queue.h, struct queue berisi array nama[] untuk nyimpen data antrian, serta dua variabel head dan tail yang berfungsi sebagai penanda posisi awal dan akhir antrian. Queue dianggap kosong kalau head dan tail bernilai -1, dan dianggap penuh kalau tail sudah mencapai indeks MAKSIMAL - 1. Fungsi-fungsi seperti createQueue, isEmpty, isFull, enQueue, deQueue, dan viewQueue dideklarasikan untuk mengatur proses kerja queue.

Di file queue.cpp, fungsi createQueue menginisialisasi queue supaya kosong. isEmpty mengecek apakah antrian belum punya data, dan isFull memastikan apakah antrian sudah mencapai kapasitas maksimal. Fungsi enQueue digunakan untuk menambahkan data ke belakang antrian. Kalau queue masih kosong, data pertama dimasukkan ke indeks 0 dan head serta tail diset ke 0. Kalau queue sudah terisi, maka tail digeser satu langkah ke kanan dan data baru dimasukkan ke posisi tersebut. Sebaliknya, fungsi deQueue bertugas menghapus data paling depan. Setelah menghapus data di indeks head, seluruh elemen digeser satu posisi ke kiri supaya struktur antrian tetap rapi. Kalau setelah penghapusan tidak ada lagi elemen, maka head dan tail dikembalikan ke -1.

Fungsi viewQueue hanya menampilkan isi queue dari indeks head sampai tail lengkap dengan nomor urut tampilannya. Di main.cpp, queue dibuat dan diisi beberapa nama menggunakan enQueue. Karena kapasitas hanya lima elemen, saat data keenam dimasukkan, program akan memberi tahu bahwa queue sudah penuh. Program kemudian menunjukkan isi queue, melakukan beberapa deQueue, lalu menampilkan kembali isi queue setelah beberapa elemen keluar. Secara keseluruhan, program ini menunjukkan cara kerja queue linear statis yang menggunakan konsep FIFO (First In First Out), di mana elemen masuk dari belakang dan keluar dari depan.

## Unguided 
### 1.1. queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAKSIMAL = 5;
typedef int infotype;

// STRUKTUR QUEUE
struct Queue {
    infotype info[MAKSIMAL];
    int head;
    int tail;
};

// ============== ALTERNATIF 1 ==============
void CreateQueue1(Queue &Q);
bool isEmptyQueue1(Queue Q);
bool isFullQueue1(Queue Q);
void enqueue1(Queue &Q, infotype x);
infotype dequeue1(Queue &Q);
void printInfo1(Queue Q);

// ============== ALTERNATIF 2 ==============
void CreateQueue2(Queue &Q);
bool isEmptyQueue2(Queue Q);
bool isFullQueue2(Queue Q);
void enqueue2(Queue &Q, infotype x);
infotype dequeue2(Queue &Q);
void printInfo2(Queue Q);

// ============== ALTERNATIF 3 (Circular) ==============
void CreateQueue3(Queue &Q);
bool isEmptyQueue3(Queue Q);
bool isFullQueue3(Queue Q);
void enqueue3(Queue &Q, infotype x);
infotype dequeue3(Queue &Q);
void printInfo3(Queue Q);

#endif

### 1.2. queue.cpp
#include "queue.h"

//
// ====================== ALTERNATIF 1 ======================
// head diam, tail bergerak
//

void CreateQueue1(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue1(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue1(Queue Q) {
    return (Q.tail == MAKSIMAL - 1);
}

void enqueue1(Queue &Q, infotype x) {
    if (isFullQueue1(Q)) {
        cout << "Queue penuh\n";
        return;
    }
    if (isEmptyQueue1(Q)) {
        Q.head = Q.tail = 0;
    } else {
        Q.tail++;
    }
    Q.info[Q.tail] = x;
}

infotype dequeue1(Queue &Q) {
    if (isEmptyQueue1(Q)) {
        cout << "Queue kosong\n";
        return -1;
    }
    infotype val = Q.info[Q.head];
    if (Q.head == Q.tail)
        CreateQueue1(Q);
    else
        Q.head++;
    return val;
}

void printInfo1(Queue Q) {
    cout << Q.head << " - " << Q.tail << " | ";
    if (isEmptyQueue1(Q)) {
        cout << "empty queue\n";
        return;
    }
    for (int i = Q.head; i <= Q.tail; i++)
        cout << Q.info[i] << " ";
    cout << endl;
}


//
// ====================== ALTERNATIF 2 ======================
// head bergerak, tail bergerak, tidak circular
//

void CreateQueue2(Queue &Q) {
    Q.head = 0;
    Q.tail = -1;
}

bool isEmptyQueue2(Queue Q) {
    return (Q.tail < Q.head);
}

bool isFullQueue2(Queue Q) {
    return (Q.tail == MAKSIMAL - 1);
}

void enqueue2(Queue &Q, infotype x) {
    if (isFullQueue2(Q)) {
        cout << "Queue penuh\n";
        return;
    }
    Q.tail++;
    Q.info[Q.tail] = x;
}

infotype dequeue2(Queue &Q) {
    if (isEmptyQueue2(Q)) {
        cout << "Queue kosong\n";
        return -1;
    }

    infotype val = Q.info[Q.head];
    Q.head++;

    if (Q.head > Q.tail)
        CreateQueue2(Q);

    return val;
}

void printInfo2(Queue Q) {
    cout << Q.head << " - " << Q.tail << " | ";
    if (isEmptyQueue2(Q)) {
        cout << "empty queue\n";
        return;
    }
    for (int i = Q.head; i <= Q.tail; i++)
        cout << Q.info[i] << " ";
    cout << endl;
}


//
// ====================== ALTERNATIF 3 (Circular Queue) ======================
// head dan tail berputar mod MAKSIMAL
//

void CreateQueue3(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue3(Queue Q) {
    return (Q.head == -1);
}

bool isFullQueue3(Queue Q) {
    return ((Q.tail + 1) % MAKSIMAL == Q.head);
}

void enqueue3(Queue &Q, infotype x) {
    if (isFullQueue3(Q)) {
        cout << "Queue penuh\n";
        return;
    }

    if (isEmptyQueue3(Q)) {
        Q.head = Q.tail = 0;
    } else {
        Q.tail = (Q.tail + 1) % MAKSIMAL;
    }

    Q.info[Q.tail] = x;
}

infotype dequeue3(Queue &Q) {
    if (isEmptyQueue3(Q)) {
        cout << "Queue kosong\n";
        return -1;
    }

    infotype val = Q.info[Q.head];

    if (Q.head == Q.tail)
        CreateQueue3(Q);
    else
        Q.head = (Q.head + 1) % MAKSIMAL;

    return val;
}

void printInfo3(Queue Q) {
    cout << Q.head << " - " << Q.tail << " | ";
    if (isEmptyQueue3(Q)) {
        cout << "empty queue\n";
        return;
    }

    int i = Q.head;
    while (true) {
        cout << Q.info[i] << " ";
        if (i == Q.tail) break;
        i = (i + 1) % MAKSIMAL;
    }
    cout << endl;
}

### 1.3. main.cpp
#include <iostream>
#include "queue.h"
using namespace std;

int main() {

    cout << "Hello World" << endl;
    cout << "--------------------------" << endl;
    cout << "H - T \t| Queue info" << endl;
    cout << "--------------------------" << endl;

    // =============================
    // ALTERNATIF 1
    // =============================
    cout << "\n=== ALTERNATIF 1 (head diam, tail bergerak) ===" << endl;

    Queue Q1;
    CreateQueue1(Q1);

    printInfo1(Q1); // kondisi awal

    enqueue1(Q1, 5); printInfo1(Q1);
    enqueue1(Q1, 3); printInfo1(Q1);
    enqueue1(Q1, 7); printInfo1(Q1);
    dequeue1(Q1); printInfo1(Q1);
    dequeue1(Q1); printInfo1(Q1);


    // =============================
    // ALTERNATIF 2
    // =============================
    cout << "\n=== ALTERNATIF 2 (head-tail bergerak, non circular) ===" << endl;

    Queue Q2;
    CreateQueue2(Q2);

    printInfo2(Q2); // kondisi awal

    enqueue2(Q2, 5); printInfo2(Q2);
    enqueue2(Q2, 3); printInfo2(Q2);
    enqueue2(Q2, 7); printInfo2(Q2);
    dequeue2(Q2); printInfo2(Q2);
    dequeue2(Q2); printInfo2(Q2);


    // =============================
    // ALTERNATIF 3
    // =============================
    cout << "\n=== ALTERNATIF 3 (Circular Queue) ===" << endl;

    Queue Q3;
    CreateQueue3(Q3);

    printInfo3(Q3); // kondisi awal

    enqueue3(Q3, 5); printInfo3(Q3);
    enqueue3(Q3, 3); printInfo3(Q3);
    enqueue3(Q3, 7); printInfo3(Q3);
    dequeue3(Q3); printInfo3(Q3);
    enqueue3(Q3, 9); printInfo3(Q3);

    return 0;
}


### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/IkfinaKamaliaRahmah/103112400090-Ikfina-Kamalia-Rahmah/blob/main/!03112400090-Ikfina-Kamalia-Rahmah/images8/Output-Unguided1-Modul8-1.png)

##### Output 2
![Screenshot Output Unguided 1_1](https://github.com/IkfinaKamaliaRahmah/103112400090-Ikfina-Kamalia-Rahmah/blob/main/!03112400090-Ikfina-Kamalia-Rahmah/images8/Output-Unguided1-Modul8-2.png)

penjelasan unguided 1 
Program queue yang kamu buat sebenarnya menunjukkan tiga cara berbeda dalam mengimplementasikan struktur data antrian menggunakan array statis. Ketiga alternatif tersebut memanfaatkan konsep dasar antrian FIFO (First In First Out), yaitu data yang masuk lebih dulu akan keluar lebih dulu. Pada file queue.h, struktur Queue didefinisikan berisi array info untuk menampung elemen antrian serta dua indeks, yaitu head dan tail, yang berfungsi sebagai penanda posisi elemen terdepan dan elemen terakhir. Kapasitas queue dibatasi oleh konstanta MAKSIMAL = 5, sehingga antrian hanya bisa menyimpan lima data. File header tersebut juga memisahkan fungsi-fungsi operasi queue menjadi tiga kelompok: Alternatif 1, Alternatif 2, dan Alternatif 3 (circular queue), yang masing-masing menerapkan logika pergerakan head dan tail yang berbeda.

Pada Alternatif 1, queue diimplementasikan dengan konsep bahwa head tidak pernah bergerak mundur, hanya tail yang bertambah setiap kali dilakukan enqueue. Ketika antrian kosong, nilai awal head dan tail adalah -1. Saat elemen pertama masuk, keduanya berubah menjadi 0, dan selanjutnya hanya tail yang naik hingga indeks terakhir. Ketika elemen dikeluarkan, head akan naik, tetapi ruang kosong di bagian kiri array tidak digunakan kembali, sehingga ketika tail sudah mencapai MAKSIMAL - 1, antrian dianggap penuh walaupun sebenarnya masih ada ruang kosong di depan. Metode ini cocok untuk pemahaman dasar queue, tetapi kurang efisien karena menghasilkan wasted space.

Berbeda dengan itu, Alternatif 2 membuat head dan tail sama-sama bergerak ke kanan tetapi tetap dalam pola non-circular. Pada implementasi ini queue dimulai pada posisi head = 0 dan tail = -1. Setiap data yang dienqueue akan meningkatkan nilai tail, dan setiap dequeue akan meningkatkan nilai head. Begitu head melewati tail, queue dianggap kosong dan direset ke kondisi awal. Alternatif ini sedikit lebih rapi dibanding Alternatif 1, tetapi masih memiliki masalah yang sama: ruang kosong di bagian awal array tidak bisa digunakan kembali. Dengan kata lain, queue tetap bisa dianggap penuh meskipun masih ada area kosong di sebelah kiri.

Solusi paling efisien ditunjukkan pada Alternatif 3, yaitu implementasi Circular Queue. Pada metode ini, seluruh ruang array benar-benar dimanfaatkan karena head dan tail akan berputar menggunakan operasi modulo. Ketika queue kosong, head dan tail bernilai -1. Saat enqueue pertama, keduanya menjadi 0. Jika tail mencapai ujung array, ia kembali ke indeks awal (0) selama masih ada ruang. Deteksi queue penuh dilakukan menggunakan kondisi (tail + 1) % MAKSIMAL == head, sedangkan queue kosong jika head == -1. Circular queue sangat efisien untuk penggunaan jangka panjang, terutama ketika operasi enqueue dan dequeue terjadi secara berulang-ulang.

Pada file main.cpp, ketiga alternatif tersebut didemokan dengan urutan enqueue dan dequeue yang sama. Setiap langkah memanggil fungsi printInfoX() untuk menampilkan posisi head, tail, dan isi queue, sehingga perbedaan perilaku antara implementasi non-circular dan circular terlihat jelas. Alternatif 1 dan 2 akan cepat mencapai kondisi penuh meskipun ada ruang kosong di dalam array, sementara Alternatif 3 mampu terus memanfaatkan ruang tersebut dengan memutar indeks.

Secara keseluruhan, ketiga alternatif ini membantu mahasiswa memahami berbagai cara mengelola queue menggunakan array. Alternatif 1 dan 2 sederhana dan cocok sebagai pengenalan konsep dasar queue, tetapi Alternatif 3 merupakan implementasi yang paling efisien dan paling mendekati penggunaan di dunia nyata. Meskipun begitu, semua operasi enqueue dan dequeue pada ketiga alternatif tetap memiliki kompleksitas waktu O(1), karena hanya melibatkan manipulasi indeks, bukan pergeseran elemen. Dengan perbandingan ini, mahasiswa bisa memahami bagaimana desain struktur data mempengaruhi efisiensi memori dan perilaku program saat digunakan secara terus-menerus.

## Kesimpulan
Setelah ngerjain praktikum Modul 8 tentang Queue, saya jadi lebih paham gimana sebenarnya cara kerja antrian di dalam program. Intinya, queue itu pakai konsep FIFO, jadi yang masuk duluan harus keluar duluan. Dari percobaan yang saya lakukan, saya coba tiga jenis implementasi queue pakai array, dan di situ keliatan banget perbedaan cara kerja masing-masing. Queue biasa yang linear ternyata kurang efisien karena kalau head maju, ruang kosong di depan nggak bisa dipakai lagi. Sedangkan kalau pakai circular queue, penggunaan memori jauh lebih optimal karena head dan tail bisa muter balik ke awal array tanpa ribet.

Melalui praktikum ini juga saya jadi ngerti fungsi–fungsi dasar queue seperti enqueue, dequeue, ngecek penuh atau kosong, sampai cara nampilin isi queue. Secara keseluruhan, praktikum ini ngebantu banget buat ngejelasin konsep antrian secara nyata, bukan cuma teori. Jadi saya bisa tahu mana implementasi yang paling efisien dan kenapa circular queue biasanya lebih dipakai dibanding queue linear biasa. Praktikum ini benar-benar ngebantu buat memperjelas pemahaman saya tentang struktur data queue secara keseluruhan.

## Referensi
<br>[1] A. Purwanto, “Implementasi Struktur Data Queue Pada Sistem Komputasi,” Jurnal Informatika, vol. 7, no. 2, 2020.
<br>[2] S. Wibowo, “Analisis Efisiensi Queue Pada Sistem Antrian Digital,” Jurnal Teknologi dan Sistem Informasi, vol. 9, no. 1, 2021.
<br>[3] R. Prasetyo, “Penerapan Struktur Data Antrian pada Sistem Layanan Publik,” Jurnal Ilmiah Teknologi Informasi, vol. 5, no. 3, 2019.
<br>[4] M. Kurniawan dan F. Hidayat, “Simulasi dan Analisis Sistem Antrian Menggunakan Struktur Data Circular Queue,” Jurnal Ilmiah Informatika dan Komputer, vol. 12, no. 1, 2020.
<br>[5] L. Sari dan D. Prabowo, “Penerapan FIFO Queue pada Sistem Pengolahan Data Transaksi,” Jurnal Sistem Informasi dan Rekayasa Perangkat Lunak, vol. 6, no. 2, 2021.
<br>[6] B. Nugroho, “Pengembangan Sistem Antrian Berbasis ADT Queue untuk Optimalisasi Pelayanan,” Jurnal Teknologi Informasi dan Terapan, vol. 8, no. 4, 2020.
<br>[7] H. Putra dan N. Rahmawati, “Rancang Bangun Sistem Antrian Otomatis Menggunakan Metode Queue FIFO,” Jurnal Sains dan Teknologi Komputer, vol. 10, no. 1, 2022.
<br>[8] D. Santoso, “Evaluasi Kinerja Struktur Data Queue pada Proses Buffering Data,” Jurnal Pengembangan Teknologi Informasi dan Ilmu Komputer, vol. 5, no. 7, 2021.
<br>