#include <iostream>
using namespace std;

// ===============================
// Fungsi Konversi Iteratif
// ===============================
void konversiIteratif(double angka[], int jumlah, double kurs) {
    cout << "\n=== Konversi Iteratif ===\n";
    for (int i = 0; i < jumlah; i++) {
        cout << angka[i] << " -> " << angka[i] * kurs << endl;
    }
}

// ===============================
// Fungsi Konversi Rekursif
// ===============================
void konversiRekursif(double angka[], int index, int jumlah, double kurs) {
    if (index == jumlah) return; // basis rekursi

    cout << angka[index] << " -> " << angka[index] * kurs << endl;

    konversiRekursif(angka, index + 1, jumlah, kurs); // pemanggilan diri
}

// ===============================
// MAIN PROGRAM
// ===============================
int main() {
    int n;
    double kurs;

    cout << "=== Program Konversi Mata Uang ===\n";
    cout << "Masukkan jumlah data uang: ";
    cin >> n;

    double nilai[100];

    for (int i = 0; i < n; i++) {
        cout << "Masukkan nilai ke-" << i+1 << ": ";
        cin >> nilai[i];
    }

    cout << "\nMasukkan nilai kurs: ";
    cin >> kurs;

    // Panggilan iteratif
    konversiIteratif(nilai, n, kurs);

    // Panggilan rekursif
    cout << "\n=== Konversi Rekursif ===\n";
    konversiRekursif(nilai, 0, n, kurs);

    return 0;
}
