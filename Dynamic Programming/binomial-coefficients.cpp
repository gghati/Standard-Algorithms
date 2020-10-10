#include <iostream>
#include <bits/stdc++.h>
#define MAXN 100
#define ll long long

using namespace std;

ll bin_coeff(int n, int k){
    int i,j;
    ll bc[MAXN][MAXN];
    for(int i = 0; i <= n; i++)
        bc[i][0] = 1;

    for(int j = 0; j <= n; j++)
        bc[j][j] = 1;
    
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++){
            bc[i][j] = bc[i - 1][j - 1] + bc[i - 1][j];
        }
    }
    return bc[n][k];
}