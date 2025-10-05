#include <iostream>
using namespace std;

void tampilMatriks(int A[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int B[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    int C[3][3];

    cout << "=== Penjumlahan Matriks ===" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    tampilMatriks(C);

    cout << "\n=== Pengurangan Matriks ===" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    tampilMatriks(C);

    cout << "\n=== Perkalian Matriks ===" << endl;
    int D[3][3] = {0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                D[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    tampilMatriks(D);

    return 0;
}
