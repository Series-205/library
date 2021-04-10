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

    HeavyLightDecomposition tree(n);

    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree.add_edge(u, v);
    }

    tree.build();
    vector<ll> b(n);
    for(int i = 0; i < n; i++) b[tree[i]] = a[i];

    SegmentTree<S, op, e> seg(b);

    for(int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if(t) {
            int u, v;
            cin >> u >> v;
            S res = e();
            for(auto [l, r] : tree.node_query(u, v))
                res = op(res, seg.prod(l, r));
            cout << res << "\n";
        } else {
            int p, x;
            cin >> p >> x;
            seg.set(tree[p], seg.get(tree[p]) + x);
        }
    }

    return 0;
}