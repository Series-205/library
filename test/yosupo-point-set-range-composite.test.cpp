#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include <bits/stdc++.h>
using namespace std;

#include "../segtree/segment-tree.cpp"

constexpr int mod = 998244353;

struct S {
    int64_t a, b;
    int64_t calc(int64_t x) { return (a * x + b) % mod; }
};

inline S op(S l, S r) { return S{r.a * l.a % mod, (r.a * l.b + r.b) % mod}; }
inline S e() { return S{1, 0}; }

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    vector<S> v;
    v.reserve(n);

    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(S{a, b});
    }

    SegmentTree<S, op, e> seg(v);

    for(int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(a)
            cout << seg.prod(b, c).calc(d) << "\n";
        else
            seg.set(b, S{c, d});
    }

    return 0;
}