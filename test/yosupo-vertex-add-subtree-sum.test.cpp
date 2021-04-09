#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

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
    vector<S> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> g(n);
    HeavyLightDecomposition tree(g);
    for(int i = 1; i < n; i++) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }
    tree.build(0);

    vector<S> b(n);
    for(int i = 0; i < n; i++) b[tree.in[i]] = a[i];
    SegmentTree<S, op, e> seg(b);

    for(int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if(t) {
            int u;
            cin >> u;
            cout << seg.prod(tree.in[u], tree.out[u]) << "\n";
        } else {
            int u, x;
            cin >> u >> x;
            seg.set(tree.in[u], seg.get(tree.in[u]) + x);
        }
    }

    return 0;
}