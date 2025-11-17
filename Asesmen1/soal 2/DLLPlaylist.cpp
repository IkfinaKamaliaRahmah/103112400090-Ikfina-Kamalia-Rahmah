#include "DLLPlaylist.h"

float PopularityScore(Song S) {
    return 0.8 * S.PlayCount + 20.0 * S.Rating;
}

bool isEmpty(List L) {
    return (L.head == nullptr);
}

void createList(List &L) {
    L.head = nullptr;
    L.tail = nullptr;
}

Node* allocate(Song S) {
    Node* N = new Node;
    N->info = S;
    N->prev = nullptr;
    N->next = nullptr;
    return N;
}

void deallocate(Node* P) {
    delete P;
}

void insertFirst(List &L, Song S) {
    Node* N = allocate(S);
    if (isEmpty(L)) {
        L.head = L.tail = N;
    } else {
        N->next = L.head;
        L.head->prev = N;
        L.head = N;
    }
}

void insertLast(List &L, Song S) {
    Node* N = allocate(S);
    if (isEmpty(L)) {
        L.head = L.tail = N;
    } else {
        L.tail->next = N;
        N->prev = L.tail;
        L.tail = N;
    }
}

void insertAfter(List &L, Node* Q, Song S) {
    if (Q != nullptr) {
        Node* N = allocate(S);
        N->next = Q->next;
        N->prev = Q;

        if (Q->next != nullptr)
            Q->next->prev = N;
        else
            L.tail = N;

        Q->next = N;
    }
}

void insertBefore(List &L, Node* Q, Song S) {
    if (Q != nullptr) {
        Node* N = allocate(S);
        N->prev = Q->prev;
        N->next = Q;

        if (Q->prev != nullptr)
            Q->prev->next = N;
        else
            L.head = N;

        Q->prev = N;
    }
}

void deleteFirst(List &L, Song &S) {
    if (!isEmpty(L)) {
        Node* temp = L.head;
        S = temp->info;

        if (L.head == L.tail) {
            L.head = L.tail = nullptr;
        } else {
            L.head = temp->next;
            L.head->prev = nullptr;
        }
        deallocate(temp);
    }
}

void deleteLast(List &L, Song &S) {
    if (!isEmpty(L)) {
        Node* temp = L.tail;
        S = temp->info;

        if (L.head == L.tail) {
            L.head = L.tail = nullptr;
        } else {
            L.tail = temp->prev;
            L.tail->next = nullptr;
        }
        deallocate(temp);
    }
}

void deleteAfter(List &L, Node* Q, Song &S) {
    if (Q != nullptr && Q->next != nullptr) {
        Node* temp = Q->next;
        S = temp->info;

        Q->next = temp->next;
        if (temp->next != nullptr)
            temp->next->prev = Q;
        else
            L.tail = Q;

        deallocate(temp);
    }
}

void deleteBefore(List &L, Node* Q, Song &S) {
    if (Q != nullptr && Q->prev != nullptr) {
        Node* temp = Q->prev;
        S = temp->info;

        Q->prev = temp->prev;
        if (temp->prev != nullptr)
            temp->prev->next = Q;
        else
            L.head = Q;

        deallocate(temp);
    }
}

void updateAtPosition(List &L, int posisi, Song S) {
    Node* temp = L.head;
    int idx = 1;

    while (temp != nullptr && idx < posisi) {
        temp = temp->next;
        idx++;
    }

    if (temp != nullptr)
        temp->info = S;
}

void viewList(List L) {
    if (isEmpty(L)) {
        cout << "List kosong.\n";
        return;
    }

    Node* temp = L.head;
    int index = 1;

    while (temp != nullptr) {
        cout << index << ". "
             << temp->info.Title << " | "
             << temp->info.Artist << " | "
             << temp->info.DurationSec << " sec | "
             << temp->info.PlayCount << " plays | "
             << "Rating: " << temp->info.Rating << " | "
             << "PopularityScore: " << PopularityScore(temp->info)
             << endl;

        temp = temp->next;
        index++;
    }
}

void searchByPopularityRange(List L, float minScore, float maxScore) {
    Node* temp = L.head;
    int index = 1;

    cout << "\nLagu dengan PopularityScore "
         << minScore << " - " << maxScore << ":\n";

    while (temp != nullptr) {
        float score = PopularityScore(temp->info);

        if (score >= minScore && score <= maxScore) {
            cout << index << ". "
                 << temp->info.Title << " | Score = " << score << endl;
        }

        temp = temp->next;
        index++;
    }
}
