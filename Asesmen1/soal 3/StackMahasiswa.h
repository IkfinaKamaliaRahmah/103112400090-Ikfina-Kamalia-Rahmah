#ifndef STACKMAHASISWA_H
#define STACKMAHASISWA_H

#include <string>
using namespace std;

const int MAX = 6;

typedef struct {
    string Nama;
    string NIM;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
} Mahasiswa;

typedef struct {
    Mahasiswa dataMahasiswa[MAX];
    int Top;
} StackMahasiswa;

bool isEmpty(StackMahasiswa &S);
bool isFull(StackMahasiswa &S);
void createStack(StackMahasiswa &S);
void Push(StackMahasiswa &S, Mahasiswa M);
void Pop(StackMahasiswa &S);
void Update(StackMahasiswa &S, int posisi, Mahasiswa M);
void View(StackMahasiswa &S);
void SearchNilaiAkhir(StackMahasiswa &S, float Min, float Max);
void MaxNilaiAkhir(StackMahasiswa &S);

float HitungNilaiAkhir(Mahasiswa M);

#endif
