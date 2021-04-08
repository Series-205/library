#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include <bits/stdc++.h>
using namespace std;

#include "../segtree/fenwick-tree.cpp"

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    FenwickTree<int64_t> bit(n);

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        bit.add(i, a);
    }

    for(int i = 0; i < q; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a)
            cout << bit.sum(b, c) << "\n";
        else
            bit.add(b, c);
    }

    return 0;
}