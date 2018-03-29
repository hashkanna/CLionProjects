#include <iostream>
#include <vector>
using namespace std;

//ios::sync_with_stdio(false);
//cin.tie(NULL);

/*
 * http://codeforces.com/group/K8KexP52bs/contest/219775/problem/A
 */

int n;
vector<int> a;
vector<int> segtree;

void put(int i,int L,int R,int pos,int x) {
    if (L==R) {
        segtree[i] = a[L] = x;
    }
    else {
        int M = (L+R)/2;
        if (pos<=M)
            put(2*i+1,L,M,pos,x);
        else
            put(2*i+2,M+1,R,pos,x);
        segtree[i] = min(segtree[2*i+1], segtree[2*i+2]);
    }
}

int build(int i,int L, int R) {
    if (L==R) {
        segtree[i] = a[L];
    }
    else {
        int M = (L+R)/2;
        segtree[i] = min(build(2*i+1,L,M), build(2*i+2,M+1,R));
    }
    return segtree[i];
}

int rmq(int i, int L, int R, int l, int r) {
    if (L==l && R==r) {
        return segtree[i];
    }
    else {
        int M = (L + R) / 2;
        int res = INT_MAX;
        if (l<=M)
            res = min(res,rmq(2*i+1,L,M,l,min(M,r)));
        if (r>M)
            res = min(res,rmq(2*i+2,M+1,R,max(M+1,l),r));
        return res;
    }

}


int main() {
    scanf("%d", &n);
    a.resize(n);
    for (int j=0; j<n; j++) {
        scanf("%d", &a[j]);
    }
    segtree=vector<int>(4*n,INT_MAX);

    build(0,0,n-1);

    // execute the input
    int m;
    scanf("%d", &m);
    for (int j=0;j<m;j++) {
        int t,x,y;
        scanf("%d %d %d", &t, &x, &y);
        if (t==1) {
            put(0,0,n-1,x-1,y);
        }
        else if (t==2)
            printf("%d\n", rmq(0,0,n-1,x-1,y-1));
    }
}