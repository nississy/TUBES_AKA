#include <iostream>
#include "peluang.h"
using namespace std;

void menuUtama() {
    cout << "\n=== PROGRAM PELUANG ===\n";
    cout << "1. Peluang Binomial\n";
    cout << "0. Keluar\n";
    cout << "Pilih menu: ";
}

void menuOperator() {
    cout << "\n=== PILIH OPERASI ===\n";
    cout << "1. P(X = x)\n";
    cout << "2. P(X <= x)\n";
    cout << "3. P(X >= x)\n";
    cout << "4. P(X < x)\n";
    cout << "5. P(X > x)\n";
    cout << "6. P(a < X < b)\n";
    cout << "7. P(a <= X <= b)\n";
    cout << "Pilih: ";
}

int main() {
    int pilihan;

    while (true) {
        menuUtama();
        cin >> pilihan;

        if (pilihan == 0) {
            cout << "Program selesai.\n";
            break;
        }

        switch (pilihan) {

        case 1: {
            int n, k;
            float p;
            int op;

            cout << "Masukkan n: "; cin >> n;
            cout << "Masukkan p: "; cin >> p;

            menuOperator();
            cin >> op;

            switch (op) {
            case 1: // P(X = x)
                cout << "Masukkan x: "; cin >> k;
                cout << "Iteratif  = " << peluangBinomialIteratif(n, k, p) << endl;
                cout << "Rekursif  = " << peluangBinomialRekursif(n, k, p) << endl;
                break;

            case 2: // P(X <= x)
                cout << "Masukkan x: "; cin >> k;
                {
                    float total1 = 0, total2 = 0;
                    for (int i = 0; i <= k; i++) {
                        total1 += peluangBinomialIteratif(n, i, p);
                        total2 += peluangBinomialRekursif(n, i, p);
                    }
                    cout << "Iteratif  = " << total1 << endl;
                    cout << "Rekursif  = " << total2 << endl;
                }
                break;

            case 3: // P(X >= x)
                cout << "Masukkan x: "; cin >> k;
                {
                    float total1 = 0, total2 = 0;
                    for (int i = k; i <= n; i++) {
                        total1 += peluangBinomialIteratif(n, i, p);
                        total2 += peluangBinomialRekursif(n, i, p);
                    }
                    cout << "Iteratif  = " << total1 << endl;
                    cout << "Rekursif  = " << total2 << endl;
                }
                break;

            case 4: // P(X < x)
                cout << "Masukkan x: "; cin >> k;
                {
                    float total1 = 0, total2 = 0;
                    for (int i = 0; i < k; i++) {
                        total1 += peluangBinomialIteratif(n, i, p);
                        total2 += peluangBinomialRekursif(n, i, p);
                    }
                    cout << "Iteratif  = " << total1 << endl;
                    cout << "Rekursif  = " << total2 << endl;
                }
                break;

            case 5: // P(X > x)
                cout << "Masukkan x: "; cin >> k;
                {
                    float total1 = 0, total2 = 0;
                    for (int i = k+1; i <= n; i++) {
                        total1 += peluangBinomialIteratif(n, i, p);
                        total2 += peluangBinomialRekursif(n, i, p);
                    }
                    cout << "Iteratif  = " << total1 << endl;
                    cout << "Rekursif  = " << total2 << endl;
                }
                break;

            case 6: { // P(a < X < b)
                int a, b;
                cout << "Masukkan a: "; cin >> a;
                cout << "Masukkan b: "; cin >> b;

                float total1 = 0, total2 = 0;
                for (int i = a+1; i < b; i++) {
                    total1 += peluangBinomialIteratif(n, i, p);
                    total2 += peluangBinomialRekursif(n, i, p);
                }

                cout << "Iteratif  = " << total1 << endl;
                cout << "Rekursif  = " << total2 << endl;
                break;
            }

            case 7: { // P(a <= X <= b)
                int a, b;
                cout << "Masukkan a: "; cin >> a;
                cout << "Masukkan b: "; cin >> b;

                float total1 = 0, total2 = 0;
                for (int i = a; i <= b; i++) {
                    total1 += peluangBinomialIteratif(n, i, p);
                    total2 += peluangBinomialRekursif(n, i, p);
                }

                cout << "Iteratif  = " << total1 << endl;
                cout << "Rekursif  = " << total2 << endl;
                break;
            }

            default:
                cout << "Pilihan tidak valid.\n";
            }
            break;
        }

        default:
            cout << "Pilihan tidak valid.\n";
        }
    }

    return 0;
}
