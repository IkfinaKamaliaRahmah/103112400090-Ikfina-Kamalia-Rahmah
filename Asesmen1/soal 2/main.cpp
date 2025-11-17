#include "DLLPlaylist.h"

int main() {
    List L;
    createList(L);

    Song S;

    S = {"Senja di Kota", "Nona Band", 210, 150, 4.2};
    insertLast(L, S);

    S = {"Langkahmu", "Delta", 185, 320, 4.8};
    insertLast(L, S);

    S = {"Hujan Minggu", "Arka", 240, 900, 3.9};
    insertLast(L, S);

    cout << "\n=== LIST AWAL ===\n";
    viewList(L);

    deleteLast(L, S);

    cout << "\n=== LIST SETELAH deleteLast ===\n";
    viewList(L);

    S = {"Pelita", "Luna", 200, 260, 4.5};
    updateAtPosition(L, 2, S);

    cout << "\n=== LIST SETELAH update posisi ke-2 ===\n";
    viewList(L);

    Node* nodePos2 = L.head->next;

    S = {"Senandung", "Mira", 175, 120, 4.0};
    insertBefore(L, nodePos2, S);

    cout << "\n=== LIST SETELAH insertBefore ===\n";
    viewList(L);

    Node* beforePos2 = nodePos2->prev;
    S = {"Melodi Baru", "agis", 190, 200, 3.5};
    beforePos2->info = S;

    cout << "\n=== LIST SETELAH updateBefore ===\n";
    viewList(L);

    Node* pos3 = L.head->next->next;
    deleteBefore(L, pos3, S);

    cout << "\n=== LIST SETELAH deleteBefore ===\n";
    viewList(L);

    cout << "\n=== SEARCH POPULARITY 150 - 300 ===\n";
    searchByPopularityRange(L, 150, 300);

    return 0;
}
