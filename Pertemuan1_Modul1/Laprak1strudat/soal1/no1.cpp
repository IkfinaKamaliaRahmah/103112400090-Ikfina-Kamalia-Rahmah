#include <iostream>
using namespace std;

int main() {
    float a, b;

    // Input
    cout << "Masukkan bilangan pertama: ";
    cin >> a;
    cout << "Masukkan bilangan kedua: ";
    cin >> b;

    // Proses & Output
    cout << "\n=== Hasil Operasi Aritmatika ===" << endl;
    cout << "Penjumlahan: " << a + b << endl;
    cout << "Pengurangan: " << a - b << endl;
    cout << "Perkalian  : " << a * b << endl;

    if (b != 0) {
        cout << "Pembagian  : " << a / b << endl;
    } else {
        cout << "Pembagian  : Tidak dapat dilakukan (pembagi nol)" << endl;
    }

    return 0;
}

