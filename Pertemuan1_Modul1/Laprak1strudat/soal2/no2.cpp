#include <iostream>
using namespace std;

string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", 
                   "enam", "tujuh", "delapan", "sembilan"};

string angkaKeTulisan(int n) {
    if (n == 0) return "nol";
    if (n == 10) return "sepuluh";
    if (n == 11) return "sebelas";
    if (n < 10) return satuan[n];
    if (n < 20) return satuan[n % 10] + " belas";
    if (n < 100) {
        int puluhan = n / 10;
        int sisaan = n % 10;
        string hasil = satuan[puluhan] + " puluh";
        if (sisaan > 0) hasil += " " + satuan[sisaan];
        return hasil;
    }
    if (n == 100) return "seratus";
    return "";
}

int main() {
    int angka;
    cout << "Masukkan angka (0 - 100): ";
    cin >> angka;

    if (angka < 0 || angka > 100) {
        cout << "Input di luar jangkauan!" << endl;
    } else {
        cout << angka << " : " << angkaKeTulisan(angka) << endl;
    }
    return 0;
}