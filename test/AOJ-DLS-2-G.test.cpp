#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G"

#include <bits/stdc++.h>
using namespace std;

#include "../segtree/lazy-segment-tree.cpp"

struct S {
    int64_t val;
    int sz;
};
S op(S l, S r) { return S{l.val + r.val, l.sz + r.sz}; }
S e() { return S{0, 0}; }

using F = int64_t;
S mapping(F f, S s) { return S{s.val + f * s.sz, s.sz}; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    LazySegmentTree<S, op, e, F, mapping, composition, id> seg(
        vector<S>(n, S{0, 1}));

    for(int i = 0; i < q; i++) {
        int c;
        cin >> c;
        if(c) {
            int l, r;
            cin >> l >> r;
            cout << seg.prod(l - 1, r).val << "\n";
        } else {
            int l, r, x;
            cin >> l >> r >> x;
            seg.apply(l - 1, r, x);
        }
    }

    return 0;
}