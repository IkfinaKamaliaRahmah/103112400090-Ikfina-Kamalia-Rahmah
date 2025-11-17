#include "SLLInventory.h"

bool isEmpty(List L) {
    return L.head == nullptr;
}

void createList(List &L) {
    L.head = nullptr;
}

Node* allocate(Product P) {
    Node* N = new Node;
    N->info = P;
    N->next = nullptr;
    return N;
}

void deallocate(Node* P) {
    delete P;
}

void insertFirst(List &L, Product P) {
    Node* N = allocate(P);
    N->next = L.head;
    L.head = N;
}

void insertLast(List &L, Product P) {
    Node* N = allocate(P);

    if (isEmpty(L)) {
        L.head = N;
    } else {
        Node* temp = L.head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = N;
    }
}

void insertAfter(List &L, Node* Q, Product P) {
    if (Q != nullptr) {
        Node* N = allocate(P);
        N->next = Q->next;
        Q->next = N;
    }
}

void deleteFirst(List &L, Product &P) {
    if (!isEmpty(L)) {
        Node* temp = L.head;
        P = temp->info;
        L.head = temp->next;
        deallocate(temp);
    }
}

void deleteLast(List &L, Product &P) {
    if (!isEmpty(L)) {
        Node *temp = L.head, *prev = nullptr;

        while (temp->next != nullptr) {
            prev = temp;
            temp = temp->next;
        }

        P = temp->info;

        if (prev == nullptr)
            L.head = nullptr;
        else
            prev->next = nullptr;

        deallocate(temp);
    }
}

void deleteAfter(List &L, Node* Q, Product &P) {
    if (Q != nullptr && Q->next != nullptr) {
        Node* temp = Q->next;
        P = temp->info;
        Q->next = temp->next;
        deallocate(temp);
    }
}

void updateAtPosition(List &L, int posisi, Product P) {
    Node* temp = L.head;
    int idx = 1;

    while (temp != nullptr && idx < posisi) {
        temp = temp->next;
        idx++;
    }

    if (temp != nullptr) {
        temp->info = P;
    }
}

float finalPrice(Product P) {
    return P.HargaSatuan * (1 - (P.DiskonPersen / 100));
}

void viewList(List L) {
    Node* temp = L.head;
    int index = 1;

    while (temp != nullptr) {
        cout << index << ". "
             << temp->info.Nama << " | "
             << temp->info.SKU << " | "
             << temp->info.Jumlah << " | "
             << temp->info.HargaSatuan << " | "
             << temp->info.DiskonPersen << " | "
             << "HargaAkhir = " << finalPrice(temp->info)
             << endl;

        temp = temp->next;
        index++;
    }
}

void searchByFinalPriceRange(List L, float minPrice, float maxPrice) {
    Node* temp = L.head;
    int index = 1;

    cout << "Produk dengan HargaAkhir dalam rentang "
         << minPrice << " - " << maxPrice << ":\n";

    while (temp != nullptr) {
        float hargaAkhir = finalPrice(temp->info);

        if (hargaAkhir >= minPrice && hargaAkhir <= maxPrice) {
            cout << index << ". "
                 << temp->info.Nama << " | HRG_AKHIR = " << hargaAkhir
                 << endl;
        }

        temp = temp->next;
        index++;
    }
}


// Bagian B – MaxHargaAkhir

void MaxHargaAkhir(List L) {
    if (isEmpty(L)) {
        cout << "List kosong.\n";
        return;
    }

    Node* temp = L.head;
    float maxHarga = finalPrice(temp->info);

    // Cari harga maksimum
    while (temp != nullptr) {
        float hargaAkhir = finalPrice(temp->info);
        if (hargaAkhir > maxHarga) {
            maxHarga = hargaAkhir;
        }
        temp = temp->next;
    }

    // Tampilkan semua yang harganya = maxHarga
    cout << "\n=== PRODUK DENGAN HARGA AKHIR MAKSIMUM ===\n";
    cout << "Harga Akhir Maksimum: " << maxHarga << endl;

    temp = L.head;
    int index = 1;

    while (temp != nullptr) {
        if (finalPrice(temp->info) == maxHarga) {
            cout << "\nPosisi : " << index << endl;
            cout << "Nama         : " << temp->info.Nama << endl;
            cout << "SKU          : " << temp->info.SKU << endl;
            cout << "Jumlah       : " << temp->info.Jumlah << endl;
            cout << "HargaSatuan  : " << temp->info.HargaSatuan << endl;
            cout << "DiskonPersen : " << temp->info.DiskonPersen << endl;
            cout << "HargaAkhir   : " << maxHarga << endl;
        }
        temp = temp->next;
        index++;
    }
}
