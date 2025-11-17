#include <iostream>
#include "StackMahasiswa.h"
using namespace std;

bool isEmpty(StackMahasiswa &S) {
    return S.Top == -1;
}

bool isFull(StackMahasiswa &S) {
    return S.Top == MAX - 1;
}

void createStack(StackMahasiswa &S) {
    S.Top = -1;
}

float HitungNilaiAkhir(Mahasiswa M) {
    return (0.2 * M.NilaiTugas) + (0.4 * M.NilaiUTS) + (0.4 * M.NilaiUAS);
}

void Push(StackMahasiswa &S, Mahasiswa M) {
    if (isFull(S)) {
        cout << "Stack penuh!\n";
    } else {
        S.Top++;
        S.dataMahasiswa[S.Top] = M;
    }
}

void Pop(StackMahasiswa &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!\n";
    } else {
        S.Top--;
    }
}

void Update(StackMahasiswa &S, int posisi, Mahasiswa M) {
    if (posisi < 1 || posisi > S.Top + 1) {
        cout << "Posisi tidak valid!\n";
    } else {
        S.dataMahasiswa[posisi - 1] = M;
    }
}

void View(StackMahasiswa &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!\n";
        return;
    }

    cout << "\n=== DATA STACK ===\n";
    for (int i = S.Top; i >= 0; i--) {
        cout << i + 1 << ". " << S.dataMahasiswa[i].Nama
             << " | NIM: " << S.dataMahasiswa[i].NIM
             << " | Tugas: " << S.dataMahasiswa[i].NilaiTugas
             << " | UTS: " << S.dataMahasiswa[i].NilaiUTS
             << " | UAS: " << S.dataMahasiswa[i].NilaiUAS
             << " | NA: " << HitungNilaiAkhir(S.dataMahasiswa[i])
             << endl;
    }
}

void SearchNilaiAkhir(StackMahasiswa &S, float Min, float Max) {
    cout << "\n=== HASIL SEARCH NILAI AKHIR ===\n";
    bool ditemukan = false;

    for (int i = 0; i <= S.Top; i++) {
        float NA = HitungNilaiAkhir(S.dataMahasiswa[i]);
        if (NA >= Min && NA <= Max) {
            cout << "Posisi " << i + 1 << ": " << S.dataMahasiswa[i].Nama
                 << " | NA: " << NA << endl;
            ditemukan = true;
        }
    }

    if (!ditemukan) cout << "Tidak ada data dalam rentang nilai.\n";
}

void MaxNilaiAkhir(StackMahasiswa &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!\n";
        return;
    }

    float maxNA = HitungNilaiAkhir(S.dataMahasiswa[0]);
    int posisi = 1;

    for (int i = 1; i <= S.Top; i++) {
        float NA = HitungNilaiAkhir(S.dataMahasiswa[i]);
        if (NA > maxNA) {
            maxNA = NA;
            posisi = i + 1;
        }
    }

    cout << "\n=== NILAI AKHIR TERTINGGI ===\n";
    cout << "Posisi: " << posisi << endl;
    cout << "Nama: " << S.dataMahasiswa[posisi - 1].Nama << endl;
    cout << "NIM: " << S.dataMahasiswa[posisi - 1].NIM << endl;
    cout << "Nilai Akhir: " << maxNA << endl;
}
