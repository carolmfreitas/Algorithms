#include <bits/stdc++.h>
#define MAX 1000000

using namespace std;

int BIT[MAX], n;

int query(int x){
    int s = 0;
    while(x > 0){
        s += BIT[x];
        x -= (x & -x);
    }
    return s;
}

void update(int x, int v){
    while(x <= n){
        BIT[x] += v;
        x += (x & -x);
    }
}