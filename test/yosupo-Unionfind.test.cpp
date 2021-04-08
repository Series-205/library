#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <bits/stdc++.h>
using namespace std;

#include "../data-structure/union-find.cpp"

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    UnionFind uf(n);

    for(int i = 0; i < q; i++) {
        int t, u, v;
        cin >> t >> u >> v;
        if(t)
            cout << uf.same(u, v) << "\n";
        else
            uf.unite(u, v);
    }

    return 0;
}