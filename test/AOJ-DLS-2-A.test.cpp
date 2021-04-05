#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A"

#include <bits/stdc++.h>
using namespace std;

#include "../data-structure/segment-tree.cpp"

int op(int a, int b) { return min(a, b); }
int e() { return (1LL << 31) - 1; }

int main() {
    int n, q;
    cin >> n >> q;

    SegmentTree<int, op, e> seg(n);

    for(int i = 0; i < q; i++) {
        int c, x, y;
        cin >> c >> x >> y;
        if(c)
            cout << seg.prod(x, y + 1) << "\n";
        else
            seg.set(x, y);
    }

    return 0;
}