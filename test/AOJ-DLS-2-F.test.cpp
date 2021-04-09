#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F"

#include <bits/stdc++.h>
using namespace std;

#include "../segtree/lazy-segment-tree.cpp"

using S = int;
S op(S l, S r) { return min(l, r); }
S e() { return (1LL << 31) - 1; }

using F = int;
F id() { return -1; }
S mapping(F f, S s) { return f == id() ? s : f; }
F composition(F f, F g) { return f == id() ? g : f; }

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    LazySegmentTree<S, op, e, F, mapping, composition, id> seg(n);

    for(int i = 0; i < q; i++) {
        int c;
        cin >> c;
        if(c) {
            int l, r;
            cin >> l >> r;
            cout << seg.prod(l, r + 1) << "\n";
        } else {
            int l, r, x;
            cin >> l >> r >> x;
            seg.apply(l, r + 1, x);
        }
    }

    return 0;
}