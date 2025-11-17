#include "SLLInventory.h"

int main() {
    List L;
    createList(L);

    Product P;

    // Insert Last Pulpen
    P = {"Pulpen", "A001", 20, 2500, 0};
    insertLast(L, P);

    // Insert Last Buku Tulis
    P = {"Buku Tulis", "A002", 15, 5000, 10};
    insertLast(L, P);

    // Insert Last Penghapus
    P = {"Penghapus", "A003", 30, 1500, 0};
    insertLast(L, P);

    cout << "\n=== LIST AWAL ===\n";
    viewList(L);

    // Delete First
    Product removed;
    deleteFirst(L, removed);

    cout << "\n=== LIST SETELAH deleteFirst ===\n";
    viewList(L);

    // Update posisi ke-2
    Product dataBaru = {"Stabilo", "A010", 40, 9000, 5};
    updateAtPosition(L, 2, dataBaru);

    cout << "\n=== LIST SETELAH UPDATE POSISI 2 ===\n";
    viewList(L);

    cout << "\n=== SEARCH HARGA AKHIR 2000 - 7000 ===\n";
    searchByFinalPriceRange(L, 2000, 7000);

    // BAGIAN B: MaxHargaAkhir
    cout << "\n=== MAKSIMUM HARGA AKHIR ===\n";
    MaxHargaAkhir(L);

    return 0;
}
