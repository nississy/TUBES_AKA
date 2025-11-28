#include <cmath>
#include "peluang.h"

int faktorialIteratif(int n) {
    int hasil = 1;
    for (int i = 1; i <= n; i++){
        hasil *= i;
    }
    return hasil;
}

int faktorialRekursif(int n) {
    if (n <= 1){
        return 1;
    } else {
        return n * faktorialRekursif(n - 1);
    }
}

long long kombinasiIteratif(int n, int k) {
    return faktorialIteratif(n) / (faktorialIteratif(k) * faktorialIteratif(n - k));
}

long long kombinasiRekursif(int n, int k) {
    if (k == 0 || k == n){
        return 1;
    } else {
        return kombinasiRekursif(n - 1, k - 1) + kombinasiRekursif(n - 1, k);
    }
}

float peluangBinomialIteratif(int n, int k, float p) {
    float C = kombinasiIteratif(n, k);
    return C * pow(p, k) * pow(1 - p, n - k);
}

float peluangBinomialRekursif(int n, int k, float p) {
    long long C = kombinasiRekursif(n, k);
    return C * pow(p, k) * pow(1 - p, n - k);
}
