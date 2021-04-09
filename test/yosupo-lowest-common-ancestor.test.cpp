#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include <bits/stdc++.h>
using namespace std;

#include "../graph/heavy-light-decomposition.cpp"

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    vector<vector<int>> g(n);
    HeavyLightDecomposition tree(g);
    for(int i = 1; i < n; i++) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }

    tree.build();

    for(int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        cout << tree.lca(u, v) << "\n";
    }

    return 0;
}