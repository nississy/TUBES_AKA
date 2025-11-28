#ifndef PELUANG_H_INCLUDED
#define PELUANG_H_INCLUDED

float pangkat(float x, int y);

// Faktorial

int faktorialIteratif(int n);
int faktorialRekursif(int n);

// Kombinasi

long long kombinasiIteratif(int n, int k);
long long kombinasiRekursif(int n, int k);

// Distribusi Khusus Peubah Acak Diskret

float peluangBernoulli(int k, float p);
float peluangBinomial(int n, int k, float p);
float peluangHiperGeometrik(int N, int r, int n, int x);

#endif // PELUANG_H_INCLUDED
