#include<bits/stdc++.h>
using namespace std;
#define MAX 100005

int a[MAX];
int tree[4*MAX];

void build(int no, int l, int r){
    if(l == r){
        tree[no] = a[l];
        return;
    }

    int mid = l + (r - l)/ 2;

    build(2*no+1,l,mid);
    build(2*no+2,mid+1,r);

    tree[no] = tree[2*no+1] + tree[2*no+2];
}


void update(int no, int l, int r, int idx, int v){
    if(l == r){
        tree[no] = v;
        a[l] = v;
        return;
    }

    int mid = l + (r - l)/ 2;

    if(l <= idx && idx <= mid) update(2*no+1,l,mid,idx,v);
    else update(2*no+2,mid+1,r,idx,v);

    tree[no] = tree[2*no+1] + tree[2*no+2];
}


int query(int no, int l, int r, int ql, int qr){
    if(qr < l || ql > r) return 0;

    if(ql <= l && r <= qr) return tree[no];
    int mid = l + (r-l)/2;

    return query(2*no+1,l,mid,ql,qr) + query(2*no+2,mid+1,r,ql,qr);
}

