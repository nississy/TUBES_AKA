#ifndef PELUANG_H_INCLUDED
#define PELUANG_H_INCLUDED
#include <iostream>
using namespace std;

int faktorialIteratif(int n);
int faktorialRekursif(int n);

long long kombinasiIteratif(int n, int k);
long long kombinasiRekursif(int n, int k);

float peluangBinomialIteratif(int n, int k, float p);
float peluangBinomialRekursif(int n, int k, float p);

#endif
