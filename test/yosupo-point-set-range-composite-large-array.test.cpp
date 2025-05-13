#define PROBLEM \
    "https://judge.yosupo.jp/problem/point_set_range_composite_large_array"

#include <bits/stdc++.h>
using namespace std;

#include "../modint/modint.cpp"
#include "../segtree/dynamic-segment-tree.cpp"

using mint = Modint<998244353>;
using ll = long long;

struct S {
    mint a, b;
    mint f(mint x) { return a * x + b; }
};
S op(S l, S r) { return S{l.a * r.a, l.b * r.a + r.b}; }
S e() { return S{1, 0}; }

int main() {
    ll n, q;
    cin >> n >> q;

    DynamicSegTree<S, op, e, 30> seg;
    while(q--) {
        int t;
        cin >> t;
        if(t == 0) {
            ll p, c, d;
            cin >> p >> c >> d;
            seg.set(p, S{c, d});
        } else {
            ll l, r, x;
            cin >> l >> r >> x;
            cout << seg.prod(l, r).f(x).x << endl;
        }
    }
}