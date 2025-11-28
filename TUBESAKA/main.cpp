#include <iostream>
#include "peluang.h"

using namespace std;

// Variabel penghitung operasi
long long operasiIteratif = 0;
long long operasiRekursif = 0;

// Faktorial iteratif dengan penghitung
int faktorialIteratifCount(int n) {
    operasiIteratif = 0;
    int hasil = 1;
    for (int i = 1; i <= n; i++) {
        hasil *= i;
        operasiIteratif++;     // hitung operasi
    }
    return hasil;
}

// Faktorial rekursif dengan penghitung
int faktorialRekursifCount(int n) {
    operasiRekursif++;
    if (n <= 1) return 1;
    return n * faktorialRekursifCount(n - 1);
}

void menu() {
    cout << "\n=== PROGRAM PELUANG ===\n";
    cout << "1. Peluang Bernoulli\n";
    cout << "2. Peluang Binomial\n";
    cout << "3. Peluang Hipergeometrik\n";
    cout << "4. Bandingkan Iteratif vs Rekursif\n";
    cout << "0. Keluar\n";
    cout << "Pilih menu: ";
}

int main() {
    int pilihan;

    do {
        menu();
        cin >> pilihan;

        if (pilihan == 1) {
            int k;
            float p;
            cout << "k (0/1): "; cin >> k;
            cout << "p: "; cin >> p;
            cout << "Hasil = " << peluangBernoulli(k, p) << endl;
        }

        else if (pilihan == 2) {
            int n, k;
            float p;
            cout << "n: "; cin >> n;
            cout << "k: "; cin >> k;
            cout << "p: "; cin >> p;
            cout << "Hasil = " << peluangBinomial(n, k, p) << endl;
        }

        else if (pilihan == 3) {
            int N, r, n, x;
            cout << "N: "; cin >> N;
            cout << "r: "; cin >> r;
            cout << "n: "; cin >> n;
            cout << "x: "; cin >> x;
            cout << "Hasil = " << peluangHiperGeometrik(N, r, n, x) << endl;
        }

        else if (pilihan == 4) {
            int n;
            cout << "Masukkan n (contoh 10/15/20): ";
            cin >> n;

            // Iteratif
            faktorialIteratifCount(n);
            long long iterOps = operasiIteratif;

            // Rekursif
            operasiRekursif = 0;
            faktorialRekursifCount(n);
            long long rekOps = operasiRekursif;

            cout << "\n--- PERBANDINGAN ---\n";
            cout << "Operasi Iteratif  : " << iterOps << endl;
            cout << "Operasi Rekursif : " << rekOps << endl;

            cout << "\nKesimpulan: ";
            if (iterOps < rekOps)
                cout << "Iteratif lebih efisien.\n";
            else
                cout << "Rekursif lebih banyak operasi.\n";
        }

        else if (pilihan == 0) {
            cout << "Program selesai.\n";
        }

        else {
            cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 0);

    return 0;
}
