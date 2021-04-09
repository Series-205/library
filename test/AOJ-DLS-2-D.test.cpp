#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D"

#include <bits/stdc++.h>
using namespace std;

#include "../segtree/dual-segment-tree.cpp"

using S = int;
using F = int;
F id() { return -1; }
S mapping(F f, S s) { return f == id() ? s : f; }
F composition(F f, F g) { return f == id() ? g : f; }

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    DualSegmentTree<S, F, mapping, composition, id> seg(vector<S>(n, INT_MAX));

    for(int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if(t) {
            int p;
            cin >> p;
            cout << seg.get(p) << "\n";
        } else {
            int l, r, x;
            cin >> l >> r >> x;
            seg.apply(l, r + 1, x);
        }
    }

    return 0;
}