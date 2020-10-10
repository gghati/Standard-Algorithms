#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define MAXN 100

using namespace std;

int fib_numbers(int n){
    int i;
    ll f[MAXN + 1];

    f[0] = 0;
    f[1] = 1;
    for(int i = 2; i <= n; i++)
        f[i] = f[i - 1] - f[i - 2];
    
    return f[n];
}