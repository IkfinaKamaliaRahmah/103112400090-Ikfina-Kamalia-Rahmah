#include <iostream>
using namespace std;

// Versi Pointer
void tukarPointer(int *x, int *y, int *z) {
    int temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}

// Versi Reference
void tukarReference(int &x, int &y, int &z) {
    int temp = x;
    x = y;
    y = z;
    z = temp;
}

int main() {
    int a = 10, b = 20, c = 30;

    cout << "=== Sebelum Ditukar ===" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    tukarPointer(&a, &b, &c);
    cout << "\n=== Setelah Tukar (Pointer) ===" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    tukarReference(a, b, c);
    cout << "\n=== Setelah Tukar Lagi (Reference) ===" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    return 0;
}
