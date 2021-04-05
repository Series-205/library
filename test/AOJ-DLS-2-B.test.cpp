#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"

#include <bits/stdc++.h>
using namespace std;

#include "../data-structure/fenwick-tree.cpp"

int main() {
    int n, q;
    cin >> n >> q;

    FenwickTree<int> bit(n);

    for(int i = 0; i < q; i++) {
        int c, x, y;
        cin >> c >> x >> y;
        if(c)
            cout << bit.sum(x - 1, y) << "\n";
        else
            bit.add(x - 1, y);
    }
}