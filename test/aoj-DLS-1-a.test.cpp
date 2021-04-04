#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A"

#include <bits/stdc++.h>
using namespace std;

#include "../data-structure/union-find.cpp"

int main() {
    int n, q;
    cin >> n >> q;

    UnionFind uf(n);
    for(int i = 0; i < q; i++) {
        int c, x, y;
        cin >> c >> x >> y;
        if(c)
            cout << uf.same(x, y) << "\n";
        else
            uf.unite(x, y);
    }

    return 0;
}