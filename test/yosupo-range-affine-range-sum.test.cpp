#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include <bits/stdc++.h>
using namespace std;

#include "../segtree/lazy-segment-tree.cpp"

constexpr int mod = 998244353;

struct S {
    int64_t sum;
    int sz;
};
S op(S l, S r) {
    l.sum += r.sum;
    l.sz += r.sz;
    if(l.sum >= mod) l.sum -= mod;
    return l;
}
S e() { return S{0, 0}; }

struct F {
    int64_t a, b;
};
S mapping(F f, S s) { return S{(s.sum * f.a + f.b * s.sz) % mod, s.sz}; }
F composition(F f, F g) { return F{f.a * g.a % mod, (f.a * g.b + f.b) % mod}; }
F id() { return F{1, 0}; }

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    vector<S> v(n);
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v[i] = S{a, 1};
    }

    LazySegmentTree<S, op, e, F, mapping, composition, id> seg(v);

    for(int i = 0; i < q; i++) {
        int c;
        cin >> c;
        if(c) {
            int l, r;
            cin >> l >> r;
            cout << seg.prod(l, r).sum << "\n";
        } else {
            int l, r, a, b;
            cin >> l >> r >> a >> b;
            seg.apply(l, r, F{a, b});
        }
    }

    return 0;
}