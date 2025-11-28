#include <iostream>
#include "peluang.h"

using namespace std;

float pangkat(float x, int y) {
    float hasil = 1.0;
    for (int i = 0; i < y; i++) {
        hasil = hasil  * x;
    }
    return hasil;
}

int faktorialIteratif(int n) {
    int hasil = 1;
    for (int i = 1; i <= n; i++) hasil *= i;
    return hasil;
}

int faktorialRekursif(int n) {
    if (n <= 1){
      return 1;
    }
    return n * faktorialRekursif(n - 1);
}

long long kombinasiIteratif(int n, int k) {
    return faktorialIteratif(n) / (faktorialIteratif(k) * faktorialIteratif(n - k));
}

long long kombinasiRekursif(int n, int k) {
    if (k == 0 || k == n){
        return 1;
    }
    return kombinasiRekursif(n - 1, k - 1) + kombinasiRekursif(n - 1, k);
}

float peluangBernoulli(int k, float p) {
    if (k == 1){
        return p;
    } else {
        return 1 - p;
    }
}

float peluangBinomial(int n, int k, float p) {
    float C;
    C = kombinasiIteratif(n, k);
    return C * pangkat(p, k) * pangkat(1 - p, n - k);
}

float peluangHiperGeometrik(int N, int r, int n, int x) {
    int atas  = kombinasiIteratif(r, x) * kombinasiIteratif(N - r, n - x);
    int bawah = kombinasiIteratif(N, n);
    return (float)atas / (float)bawah;
}


