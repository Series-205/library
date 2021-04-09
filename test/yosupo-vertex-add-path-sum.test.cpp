#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include <bits/stdc++.h>
using namespace std;

#include "../graph/heavy-light-decomposition.cpp"
#include "../segtree/segment-tree.cpp"

using ll = long long;

using S = ll;
S op(S l, S r) { return l + r; }
S e() { return 0; }

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> g(n);
    HeavyLightDecomposition tree(g);

    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    tree.build();
    vector<ll> b(n);
    for(int i = 0; i < n; i++) b[tree.in[i]] = a[i];

    SegmentTree<S, op, e> seg(b);

    for(int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if(t) {
            int u, v;
            cin >> u >> v;
            cout << tree.query(
                        u, v, e(), [&](int l, int r) { return seg.prod(l, r); },
                        op)
                 << "\n";
        } else {
            int p, x;
            cin >> p >> x;
            seg.set(tree.in[p], seg.get(tree.in[p]) + x);
        }
    }

    return 0;
}