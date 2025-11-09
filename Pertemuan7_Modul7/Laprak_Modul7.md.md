# <h1 align="center">Laporan Praktikum Modul 7 - STACK</h1>
<p align="center">Ikfina Kamalia Rahmah- 103112400090</p>

## Dasar Teori
Struktur data merupakan cara untuk menyimpan dan mengorganisir data agar dapat diakses serta digunakan secara efisien. Salah satu struktur data linier yang penting adalah Stack, yang berperan besar dalam berbagai aplikasi seperti manajemen memori, proses rekursi, evaluasi ekspresi, serta sistem navigasi balik (backtracking).

Stack merupakan struktur data linier dengan prinsip LIFO (Last In First Out), di mana elemen terakhir yang dimasukkan akan menjadi elemen pertama yang dihapus [1]. Stack dapat diimplementasikan menggunakan array (statis) atau linked list (dinamis) tergantung pada kebutuhan efisiensi memori dan fleksibilitas data.
Penggunaan stack sangat penting dalam pengelolaan data temporer seperti proses undo/redo, backtracking, dan pengelolaan histori sistem [2].
Konsep stack juga menjadi dasar penting dalam pembelajaran algoritma dan struktur data, terutama dalam pemrograman bahasa C++ dan bahasa tingkat tinggi lainnya [3].

### A. Pengertian Stack<br/>
Stack adalah struktur data yang bekerja berdasarkan prinsip LIFO (Last In First Out). Konsep ini berarti bahwa data yang terakhir dimasukkan akan menjadi data pertama yang dikeluarkan. Stack dapat dianalogikan seperti tumpukan piring, di mana piring yang terakhir diletakkan di atas merupakan piring pertama yang akan diambil.

Dalam implementasi stack, terdapat dua pendekatan utama yaitu representasi pointer (dinamis) dan representasi array (statis). Representasi pointer menggunakan linked list dengan alokasi memori dinamis, sedangkan representasi array menggunakan indeks tetap dengan ukuran tertentu.
Stack memiliki satu penunjuk utama yaitu TOP, yang berfungsi untuk menunjukkan elemen paling atas dalam tumpukan. Semua operasi penyisipan dan penghapusan hanya dilakukan pada posisi TOP [1].

#### 1. Prinsip dan Operasi Stack
Prinsip kerja stack mengikuti sistem LIFO, yaitu elemen yang terakhir dimasukkan akan menjadi elemen pertama yang diambil. Operasi dasar dalam stack meliputi:
    1. Push: Menambahkan data baru di bagian atas stack.
    2. Pop: Menghapus elemen teratas dari stack.
    3. Peek: Melihat nilai elemen teratas tanpa menghapusnya.
Contohnya, dalam program pemanggilan fungsi (function call), setiap fungsi yang dipanggil akan dimasukkan ke dalam stack. Ketika fungsi selesai dieksekusi, fungsi tersebut akan dihapus dari stack terlebih dahulu sebelum fungsi sebelumnya dilanjutkan [3].

#### 2. Komponen-Komponen Stack
Stack terdiri dari beberapa komponen utama yaitu:
    1. Top → penunjuk ke elemen paling atas
    2. Node (pada linked list) → menyimpan data dan alamat elemen berikutnya.
    3. Array (pada representasi tabel) → menyimpan elemen dengan indeks terurut.
    4. Nil / NULL → penanda bahwa stack kosong atau akhir dari elemen.

Hanya elemen pada posisi Top yang dapat diakses langsung, sehingga operasi pada stack menjadi lebih sederhana namun terbatas [1].

#### 3. Contoh Penerapan Stack
Stack banyak digunakan dalam berbagai kasus komputasi, di antaranya:
    1. Penyimpanan data sementara dalam proses rekursi.
    2. Evaluasi ekspresi matematika seperti postfix dan prefix.
    3. Undo/Redo pada aplikasi pengolah kata.
    4. Backtracking pada algoritma pencarian jalur.
    5. Navigasi halaman web (fungsi Back dan Forward) [2].

### B. Operasi–Operasi dalam Stack<br/>
Operasi-operasi dasar dalam stack terdiri dari beberapa fungsi penting seperti:
#### 1.createStack()
Fungsi untuk menginisialisasi stack agar siap digunakan. Stack yang baru dibuat memiliki nilai top = NULL (pada pointer) atau top = -1 (pada array), menandakan bahwa stack masih kosong [4].

#### 2. isEmpty()
Berfungsi untuk memeriksa apakah stack kosong. Jika pointer top bernilai NULL atau indeks top bernilai -1, maka stack dianggap kosong [4].
#### 3. isFull()
Digunakan pada representasi array untuk mengecek apakah stack telah mencapai kapasitas maksimum. Jika top == MAX - 1, maka tidak bisa menambah elemen baru [4].

4. push()
#### 4. push()
Menambahkan elemen baru ke dalam stack. Pada representasi pointer, elemen baru dialokasikan dengan fungsi new, lalu dihubungkan ke node sebelumnya melalui next. Pada array, data disimpan pada indeks berikutnya dari top [1].

#### 5. pop()
Menghapus elemen paling atas dari stack dan mengembalikannya. Pada pointer, node teratas dihapus dengan delete, sedangkan pada array nilai top dikurangi satu [1].

#### 6. update()
Mengubah nilai dari elemen tertentu di dalam stack berdasarkan posisi dari atas. Fungsinya untuk memperbarui data yang sudah tersimpan tanpa mengubah struktur stack [2].

#### 7. view()
Menampilkan seluruh isi stack dari posisi top ke bawah agar pengguna dapat melihat urutan elemen saat ini [2].

#### 8. searchData()
Mencari data tertentu di dalam stack. Jika ditemukan, sistem menampilkan posisi data tersebut berdasarkan urutan dari atas [2].

Operasi-operasi dasar ini berfungsi menjaga efisiensi manajemen data sementara, terutama dalam proses-proses logika bertingkat dan pemrosesan memori [3].

## Guided 

### 1.1. stack.h
#ifndef STACK
#define STACK
#define Nil NULL

#include<iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);

void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif

### 1.2. stack.cpp
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}

### 1.3. main.cpp
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}

penjelasan singkat guided 1
Program stack menggunakan pointer ini merupakan implementasi struktur data stack (tumpukan) dengan pendekatan linked list. Stack sendiri bekerja dengan prinsip LIFO (Last In First Out), yaitu data yang terakhir dimasukkan akan menjadi data pertama yang diambil. Konsepnya mirip seperti tumpukan piring, di mana piring terakhir yang diletakkan di atas adalah piring pertama yang diambil. Pada program ini, data disimpan dalam bentuk node yang saling terhubung satu sama lain, dan hanya bagian atas tumpukan (top) yang dapat diakses secara langsung.

Di bagian header file (stack.h), dideklarasikan dua struktur utama yaitu node dan stack. Struktur node memiliki dua elemen penting: dataAngka untuk menyimpan nilai integer, dan next yang berfungsi sebagai pointer ke elemen berikutnya. Sedangkan struktur stack hanya memiliki satu pointer bernama top yang menunjuk ke elemen paling atas dari stack. Jika top bernilai NULL, artinya stack masih kosong. Selain itu, di dalam file ini juga terdapat deklarasi beberapa fungsi penting seperti createStack, isEmpty, push, pop, update, view, dan searchData, yang masing-masing akan diimplementasikan di file stack.cpp.

Dalam file stack.cpp, seluruh fungsi tersebut diimplementasikan secara detail. Fungsi createStack() digunakan untuk menginisialisasi stack agar kosong dengan mengatur top = NULL. Fungsi isEmpty() berfungsi untuk mengecek apakah stack kosong dengan melihat nilai top. Fungsi alokasi() digunakan untuk membuat node baru di memori menggunakan perintah new, dan dealokasi() digunakan untuk menghapus node tersebut dari memori saat tidak dibutuhkan lagi agar tidak terjadi kebocoran memori. Selanjutnya, push() berfungsi untuk menambahkan elemen baru ke bagian atas stack dengan cara menghubungkan node baru ke top lama dan menjadikannya top yang baru. Fungsi pop() digunakan untuk menghapus elemen paling atas, kemudian memindahkan pointer top ke elemen di bawahnya. Namun, jika stack kosong, fungsi ini akan menampilkan pesan “Stack kosong!”.

Selain itu, terdapat juga fungsi update() yang digunakan untuk mengubah nilai dari elemen tertentu berdasarkan posisi yang dimasukkan pengguna. Program akan menelusuri stack dari atas hingga mencapai posisi yang dimaksud, lalu memperbarui nilainya sesuai input user. Fungsi view() menampilkan seluruh isi stack dari elemen paling atas ke bawah, sedangkan searchData() digunakan untuk mencari nilai tertentu di dalam stack dan menampilkan posisi data tersebut jika ditemukan. Jika data yang dicari tidak ada, maka akan muncul pesan “Data tidak ditemukan di dalam stack”.

Pada bagian main.cpp, semua fungsi tadi diuji untuk memastikan stack berjalan sesuai konsepnya. Program dimulai dengan membuat stack kosong menggunakan createStack(), lalu lima node (nodeA sampai nodeE) dialokasikan dan dimasukkan ke dalam stack menggunakan fungsi push(). Karena sistemnya LIFO, data yang terakhir dimasukkan (angka 5) akan berada di posisi paling atas. Setelah itu, program menampilkan isi stack menggunakan view(), kemudian menghapus dua elemen teratas dengan pop(). Stack yang awalnya berisi 5 4 3 2 1 menjadi 3 2 1 setelah dua kali pop dilakukan. Berikutnya, fungsi update() dijalankan untuk mengubah nilai elemen pada posisi tertentu dari atas, dan hasilnya ditampilkan kembali. Fungsi searchData() kemudian digunakan untuk mencari elemen tertentu dalam stack, misalnya angka 4 (jika ditemukan akan menampilkan posisi) dan angka 9 (akan menampilkan pesan tidak ditemukan).

Secara keseluruhan, program ini menunjukkan bagaimana struktur data stack bekerja dengan konsep pointer yang dinamis. Keunggulan implementasi ini adalah stack tidak memiliki batasan ukuran tetap, karena setiap data dialokasikan langsung di memori saat dibutuhkan. Melalui program ini, kita bisa memahami bahwa stack berbasis pointer memungkinkan pengelolaan data yang lebih fleksibel dan efisien, serta mencerminkan cara kerja tumpukan data dalam sistem komputer seperti pemanggilan fungsi (function call stack) di bahasa pemrograman modern.

### 2.1. stack.h
#ifndef STACK_TABLE
#define STACK_TABLE

#include <iostream>
using namespace std;

//ubah kapasitas sesuai kebutuhan
const int MAX = 10;

struct stackTable{
    int data[MAX];
    int top; // -1 = kosong
};

bool isEmpty(stackTable s);
bool isFull(stackTable s);
void createStack(stackTable &s);

void push(stackTable &s, int angka);
void pop(stackTable &s);
void update(stackTable &s, int posisi);
void view(stackTable s);
void searchData(stackTable s, int data);

#endif

### 2.2. stack.cpp
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stackTable s){
    if(s.top == -1){
        return true;
    } else {
        return false;
    }
    //return s.top == -1;
}

bool isFull(stackTable s){
    if(s.top == MAX - 1){
        return true;
    } else {
        return false;
    }
    //return s.top == MAX - 1;
}

void createStack(stackTable &s){
    s.top = -1;
}

void push(stackTable &s, int angka){
    if(isFull(s) == true){
        cout << "Stack penuh!" << endl;
    } else {
        s.top++;
        s.data[s.top] = angka;
        cout << "Data " << angka << " berhasil ditambahkan kedalam stack!" << endl;
    }
}

void pop(stackTable &s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        int val = s.data[s.top];
        s.top--;
        cout << "Data " << val << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stackTable &s, int posisi){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    
    }
    if(posisi <= 0){
            cout << "Posisi tidak valid!" << endl;
            return;
    }

    //indek = top - (posisi + 1)
    int idx = s.top - (posisi - 1);
    if(idx < 0 || idx > s.top){
        cout << "Posisi " << posisi << "tidak valid!" << endl;
        return;
    }

    cout << "update data pposisi ke- " << posisi << endl;
    cout << "Masukkan angka : ";
    cin >> s.data[idx];
    cout << "Data berhasil diupdate!" << endl;
    cout << endl;
}

void view(stackTable s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        for(int i = s.top; i >= 0; i--){
            cout << "Posisi " << (s.top - i + 1) << " : " << s.data[i] << endl;
        }
    }
    cout << endl;
}

void searchData(stackTable s, int data){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
        return;
    }
    cout << "Mencari data " << data << " dalam stack..." << endl;
    int posisi = 1;
    bool found = false;

    for(int i = s.top; i >= 0; i--){
         if(s.data[i] == data){
            cout << "Data " << data << " ditemukan pada posisi ke-" << (s.top - i + 1) << endl;
            found = true;
            break;
            }
            posisi++;
        }

        if(!found){
            cout << "Data " << data << " tidak ditemukan dalam stack!" << endl;
            cout << endl;
        }
    }



### 2.3. main.cpp
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stackTable s;
    createStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(s);
    cout << endl;

    pop(s);
    pop(s);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(s);
    cout << endl;

    //posisi dihitung dari Top (1-based)

    update(s, 2);
    update(s, 1);
    update(s, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(s);
    cout << endl;

    searchData(s, 4);
    searchData(s, 9);

    return 0;
}

penjelasan singkat guided 2
Program ini merupakan implementasi dari struktur data stack (tumpukan) menggunakan array berkapasitas tetap, berbeda dengan program guided 1 yang menggunakan pointer atau linked list. Stack pada program ini tetap bekerja berdasarkan prinsip LIFO (Last In First Out), yaitu data yang terakhir dimasukkan akan menjadi data pertama yang dikeluarkan. Karena menggunakan array, ukuran stack sudah ditentukan sejak awal dan tidak dapat berubah selama program berjalan. Program ini berfokus pada bagaimana operasi dasar seperti push, pop, update, view, dan search dijalankan dalam stack berbasis array secara efisien dan terstruktur.

Pada bagian header file (stack.h), struktur stack didefinisikan dalam struct bernama stackTable yang berisi dua elemen utama, yaitu array data[MAX] untuk menyimpan nilai integer dan variabel top yang menunjukkan posisi elemen paling atas dalam stack. Nilai top diinisialisasi dengan -1 untuk menandakan bahwa stack masih kosong. Di dalam file ini juga terdapat deklarasi fungsi-fungsi yang mengatur operasi stack, seperti isEmpty() untuk mengecek apakah stack kosong, isFull() untuk memeriksa apakah stack sudah penuh, serta fungsi push(), pop(), update(), view(), dan searchData() yang mengatur manipulasi datanya.

Pada file stack.cpp, semua fungsi tadi diimplementasikan satu per satu. Fungsi createStack() digunakan untuk menginisialisasi stack dalam keadaan kosong dengan mengatur top = -1. Fungsi isEmpty() mengembalikan nilai true jika stack kosong, sedangkan isFull() akan bernilai true jika jumlah elemen sudah mencapai kapasitas maksimum (MAX - 1). Fungsi push() berfungsi untuk menambahkan data baru ke dalam stack dengan cara menaikkan nilai top dan menyimpan data baru di posisi tersebut. Jika stack sudah penuh, program akan menampilkan pesan “Stack penuh!”. Fungsi pop() digunakan untuk menghapus elemen paling atas dengan cara menurunkan nilai top. Jika stack kosong, maka program akan menampilkan pesan “Stack kosong!”.

Fungsi update() digunakan untuk mengganti nilai data pada posisi tertentu dari atas ke bawah. Posisi dihitung dari elemen paling atas (misalnya posisi 1 berarti top, posisi 2 berarti di bawah top, dan seterusnya). Program menggunakan rumus idx = s.top - (posisi - 1) untuk menentukan indeks array yang sesuai dengan posisi stack yang ingin diubah. Jika posisi valid, user akan diminta memasukkan nilai baru, dan data pada posisi tersebut akan diperbarui. Fungsi view() menampilkan seluruh isi stack dari atas ke bawah, lengkap dengan posisi tiap data agar pengguna tahu urutan tumpukannya. Sementara itu, searchData() digunakan untuk mencari data tertentu dalam stack dengan cara memeriksa setiap elemen mulai dari yang paling atas. Jika data ditemukan, program akan menampilkan posisi datanya; jika tidak, akan muncul pesan bahwa data tidak ditemukan dalam stack.

Bagian main.cpp digunakan untuk menguji semua fungsi tersebut. Program diawali dengan membuat stack kosong melalui createStack(s). Kemudian data 1 sampai 5 dimasukkan secara berurutan menggunakan fungsi push(). Karena sistem stack adalah LIFO, maka data terakhir yang dimasukkan (angka 5) akan berada di posisi paling atas. Setelah semua data dimasukkan, isi stack ditampilkan menggunakan view(), menghasilkan urutan 5, 4, 3, 2, 1 dari atas ke bawah. Dua elemen teratas (5 dan 4) kemudian dihapus menggunakan pop(), sehingga stack tersisa 3, 2, 1. Setelah itu, fungsi update() dijalankan untuk mengubah beberapa data berdasarkan posisi tertentu, dan hasilnya ditampilkan kembali menggunakan view(). Terakhir, fungsi searchData() digunakan untuk mencari data tertentu (misalnya angka 4 dan 9) agar terlihat bagaimana program menampilkan hasil pencarian baik ketika data ditemukan maupun tidak.

## Unguided 

### 1.1. stack.h
#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

const int MAX = 20;

struct Stack {
    int info[MAX];
    int top;
};

void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, int x);
int pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif



### 1.2. stack.cpp
#include "stack.h"
#include <iostream>
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

bool isEmpty(Stack S) {
    return (S.top == -1);
}

bool isFull(Stack S) {
    return (S.top == MAX - 1);
}

void push(Stack &S, int x) {
    if (isFull(S)) {
        cout << "Stack penuh!" << endl;
    } else {
        S.top++;
        S.info[S.top] = x;
    }
}

int pop(Stack &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!" << endl;
        return -1;
    } else {
        int temp = S.info[S.top];
        S.top--;
        return temp;
    }
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!" << endl;
    } else {
        cout << "Isi Stack: ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);
    while (!isEmpty(S)) {
        push(temp, pop(S));
    }
    S = temp;
}


### 1.3. main.cpp
#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    Stack S;
    createStack(S);

    cout << "=== UNGUIDED 1: STACK DASAR ===" << endl;

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    cout << "\nStack sebelum dibalik:" << endl;
    printInfo(S);

    cout << "\nBalik stack..." << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}


### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/IkfinaKamaliaRahmah/103112400090-Ikfina-Kamalia-Rahmah/blob/main/!03112400090-Ikfina-Kamalia-Rahmah/images7/Output-Unguided1-Modul7-1.png)


penjelasan unguided 1 
Pada program diatas atau Unguided 1, kita diminta untuk membuat implementasi stack menggunakan array sebagai tempat penyimpanan data. Stack ini menggunakan prinsip LIFO (Last In First Out), yang artinya data yang terakhir dimasukkan akan menjadi data pertama yang keluar. Program ini memiliki beberapa fungsi penting seperti createStack(), push(), pop(), printInfo(), dan balikStack(). Fungsi createStack() digunakan untuk menginisialisasi stack agar bisa digunakan. Lalu, push() berfungsi untuk menambahkan data ke tumpukan (stack), sedangkan pop() digunakan untuk menghapus data yang ada di posisi paling atas. Kemudian ada printInfo() yang menampilkan seluruh isi stack dari atas ke bawah.

yang menarik di bagian ini adalah fungsi balikStack(). Fungsinya yaitu untuk membalik urutan elemen-elemen yang ada di dalam stack dengan cara membuat stack baru sementara, lalu memindahkan semua elemen dari stack utama ke stack sementara tersebut. Karena sifat stack adalah LIFO, maka saat semua elemen dipindahkan, otomatis urutannya jadi kebalik. Misalnya sebelum dibalik urutannya 9 2 4 3, maka setelah dibalik menjadi 3 4 2 9. Jadi, bisa disimpulkan bahwa pada percobaan pertama ini, kita belajar dasar dari cara kerja stack serta bagaimana cara memanipulasi isinya menggunakan operasi dasar dan tambahan.

### 2.1. stack.h
#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

const int MAX = 20;

struct Stack {
    int info[MAX];
    int top;
};

void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, int x);
int pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, int x);

#endif


### 2.2. stack.cpp
#include "stack.h"
#include <iostream>
using namespace std;

void createStack(Stack &S) { S.top = -1; }
bool isEmpty(Stack S) { return (S.top == -1); }
bool isFull(Stack S) { return (S.top == MAX - 1); }

void push(Stack &S, int x) {
    if (isFull(S)) {
        cout << "Stack penuh!" << endl;
    } else {
        S.top++;
        S.info[S.top] = x;
    }
}

int pop(Stack &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!" << endl;
        return -1;
    } else {
        int temp = S.info[S.top];
        S.top--;
        return temp;
    }
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!" << endl;
    } else {
        cout << "Isi Stack: ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);
    while (!isEmpty(S)) {
        push(temp, pop(S));
    }
    S = temp;
}

void pushAscending(Stack &S, int x) {
    if (isFull(S)) {
        cout << "Stack penuh!" << endl;
        return;
    }
    if (isEmpty(S)) {
        push(S, x);
        return;
    }
    if (x >= S.info[S.top]) {
        push(S, x);
    } else {
        int temp = pop(S);
        pushAscending(S, x);
        push(S, temp);
    }
}


### 2.3. main.cpp
#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    Stack S;
    createStack(S);

    cout << "=== UNGUIDED 2: PUSH ASCENDING ===" << endl;

    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);

    cout << "\nStack setelah push ascending:" << endl;
    printInfo(S);

    cout << "\nBalik stack ascending..." << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}


### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/IkfinaKamaliaRahmah/103112400090-Ikfina-Kamalia-Rahmah/blob/main/!03112400090-Ikfina-Kamalia-Rahmah/images7/Output-Unguided2-Modul7-2.png)

penjelasan unguided 2
program ini merupakan mengembangkan stack dasar menjadi versi yang lebih “pintar” yaitu dengan menambahkan fungsi pushAscending(). Tujuan dari fungsi ini adalah supaya setiap data yang dimasukkan ke dalam stack tersusun secara menaik (ascending), tanpa harus mengurutkannya lagi secara manual. Cara kerjanya adalah dengan membandingkan data baru dengan elemen paling atas (top) pada stack. Jika data baru lebih besar atau sama dengan elemen paling atas, maka data langsung ditambahkan di atas. Tapi kalau data baru lebih kecil, program akan sementara “mengeluarkan” (pop) elemen dari stack hingga menemukan posisi yang cocok, baru kemudian memasukkan data baru ke tempat yang tepat, lalu mengembalikan lagi elemen-elemen yang sudah di-pop tadi.

Proses ini membuat data di dalam stack selalu terurut dari bawah ke atas dalam urutan menaik. Contohnya, kalau kita masukkan data secara acak seperti 3, 4, 8, 2, 3, 9, maka hasil akhirnya di stack akan menjadi 9 8 4 3 3 2 (dari atas ke bawah), dan setelah dibalik urutannya akan jadi 2 3 3 4 8 9. Dengan adanya fungsi ini, kita bisa menambahkan elemen ke dalam stack tanpa khawatir urutannya berantakan. Percobaan ini ngajarin kita kalau stack bisa dimodifikasi dengan logika tambahan sehingga fungsinya lebih fleksibel dan bisa menyesuaikan kebutuhan program.

### 3.1. stack.h
#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

const int MAX = 20;

struct Stack {
    char info[MAX];
    int top;
};

void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, char x);
char pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void getInputStream(Stack &S);

#endif


### 3.2. stack.cpp
#include "stack.h"
#include <iostream>
using namespace std;

void createStack(Stack &S) { S.top = -1; }
bool isEmpty(Stack S) { return (S.top == -1); }
bool isFull(Stack S) { return (S.top == MAX - 1); }

void push(Stack &S, char x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

char pop(Stack &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!" << endl;
        return '\0';
    } else {
        char temp = S.info[S.top];
        S.top--;
        return temp;
    }
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!" << endl;
    } else {
        cout << "Isi Stack: ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);
    while (!isEmpty(S)) {
        push(temp, pop(S));
    }
    S = temp;
}

void getInputStream(Stack &S) {
    char ch;
    cout << "Masukkan karakter (tekan ENTER untuk berhenti): ";
    cin.get(ch);
    while (ch != '\n') {
        push(S, ch);
        cin.get(ch);
    }
}


### 3.3. main.cpp
#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    Stack S;
    createStack(S);

    cout << "=== INPUT STREAM ===" << endl;

    getInputStream(S);

    cout << "\nStack setelah input stream:" << endl;
    printInfo(S);

    cout << "\nBalik stack hasil input:" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}


### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/IkfinaKamaliaRahmah/103112400090-Ikfina-Kamalia-Rahmah/blob/main/!03112400090-Ikfina-Kamalia-Rahmah/images7/Output-Unguided3-Modul7-3.png)

penjelasan unguided 3
program diatas diminta membuat fungsi getInputStream() yang memungkinkan pengguna untuk memasukkan data secara langsung dari keyboard (real-time input). Program akan membaca input satu per satu menggunakan cin.get() dan memasukkannya ke dalam stack sampai pengguna menekan tombol Enter. Karena stack bekerja dengan sistem LIFO, maka karakter yang terakhir diketik akan berada di paling atas. Misalnya, kalau kita mengetik abc, maka yang pertama masuk adalah a, kemudian b, dan terakhir c. Kalau ditampilkan sebelum dibalik, urutannya jadi c b a.

Tapi setelah kita jalankan fungsi balikStack(), urutannya jadi a b c, sesuai urutan aslinya. Jadi di sini kita bisa lihat bagaimana konsep tumpukan data bekerja dalam konteks input dari user. Percobaan ini sekaligus menunjukkan bahwa stack bisa digunakan untuk menangani input secara dinamis dan berguna banget untuk kasus seperti membalik string, mendeteksi urutan karakter, atau bahkan membalik kata dalam kalimat. Dari sini, kita belajar bahwa konsep stack tidak cuma terbatas pada angka atau data biasa, tapi juga bisa diterapkan untuk memproses input teks dan karakter dari pengguna.

## Kesimpulan
Dari keseluruhan percobaan yang dilakukan pada Modul 7 – Stack, dapat disimpulkan bahwa stack merupakan salah satu struktur data linier yang sangat penting dalam pemrograman karena cara kerjanya yang sederhana namun efisien, yaitu mengikuti prinsip LIFO (Last In First Out). Melalui berbagai guided dan unguided yang dilakukan, kita dapat memahami secara menyeluruh bagaimana operasi dasar stack bekerja serta bagaimana stack bisa diterapkan untuk berbagai keperluan komputasi.
Pada guided 1, stack diimplementasikan menggunakan pointer (linked list), yang bersifat dinamis karena ukuran stack dapat berubah sesuai kebutuhan memori. Pendekatan ini memberikan fleksibilitas tinggi karena tidak dibatasi oleh ukuran tetap, sehingga cocok digunakan untuk kasus di mana jumlah data tidak dapat diprediksi. Operasi seperti push(), pop(), update(), view(), dan searchData() dijalankan dengan mengelola pointer antar node, memperlihatkan bagaimana data dapat dialokasikan dan dihapus secara efisien di memori.
Kemudian pada guided 2, stack diimplementasikan menggunakan array (statis) dengan ukuran tetap yang sudah ditentukan sebelumnya. Pendekatan ini lebih sederhana dan efisien dalam penggunaan memori karena data disimpan dalam indeks terurut. Namun, kekurangannya adalah kapasitas stack tidak dapat berubah. Melalui percobaan ini, kita memahami perbedaan mendasar antara stack dinamis dan statis, serta bagaimana setiap metode memiliki kelebihan dan kekurangannya masing-masing tergantung pada konteks penggunaan program.
Selanjutnya, pada bagian unguided, tiga eksperimen dilakukan untuk memperdalam pemahaman konsep stack:


Unguided 1 menunjukkan implementasi stack dasar menggunakan array, beserta fungsi tambahan balikStack() yang berfungsi untuk membalik urutan elemen di dalam stack. Dari percobaan ini, dapat dipahami bahwa operasi dasar stack bisa dimodifikasi untuk berbagai kebutuhan, seperti membalik data tanpa harus menulis ulang algoritma baru.

Unguided 2 mengembangkan stack dasar menjadi lebih kompleks dengan menambahkan fungsi pushAscending(), yang mampu menempatkan data dalam urutan menaik secara otomatis. Hal ini menunjukkan bahwa konsep stack dapat dikombinasikan dengan logika tambahan untuk menciptakan sistem penyimpanan yang lebih terstruktur.

Unguided 3 memperlihatkan penggunaan stack dalam konteks input stream, di mana pengguna dapat memasukkan karakter satu per satu dan hasilnya dapat dibalik menggunakan stack. Percobaan ini memperluas pemahaman bahwa stack tidak hanya digunakan untuk data numerik, tetapi juga untuk pemrosesan teks, seperti membalik string atau mendeteksi pola urutan karakter.


Secara keseluruhan, dari semua percobaan yang dilakukan dapat disimpulkan bahwa stack merupakan struktur data yang sangat berguna untuk pengelolaan data sementara dan pemrosesan berurutan secara terbalik. Implementasinya bisa dilakukan dengan array (statis) maupun pointer (dinamis) sesuai kebutuhan program. Konsep ini tidak hanya menjadi dasar dalam pembelajaran algoritma dan struktur data, tetapi juga banyak digunakan dalam kehidupan nyata seperti pada sistem undo/redo, rekursi fungsi, backtracking, serta navigasi halaman web. Dengan memahami cara kerja stack dan berbagai operasinya, kita dapat mengimplementasikan solusi yang lebih efisien dan terstruktur dalam pemrograman komputer.

## Referensi
<br>[1] Setiyawan, B., Suryadi, D., & Pramono, R. (2024). Implementasi Struktur Data Stack untuk Manajemen Memori Dinamis pada Bahasa C++. Jurnal Teknologi dan Sistem Komputer Indonesia, 12(2), 45–52.
<br>[2] Wijoyo, H., Nuraini, L., & Handoko, A. (2024). Pemanfaatan Stack dalam Pemrosesan Data Temporer dan Backtracking. Jurnal Ilmu Komputer Terapan Indonesia, 8(1), 33–40.
<br>[3] Zen, R., Rahmadani, S., & Putri, D. (2021). Penerapan Konsep Stack dan Queue dalam Pembelajaran Algoritma dan Pemrograman. Jurnal Pendidikan Informatika Indonesia, 5(3), 112–120.
<br>[4] Modul Praktikum Struktur Data – Modul 7: Stack. Fakultas Teknologi Informasi, Universitas Dian Nuswantoro (2024).
