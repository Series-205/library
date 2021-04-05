/*
 * @brief Union-Find
 * @docs docs/union-find.md
 */
#pragma once
#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> data;

    UnionFind() = default;

    explicit UnionFind(size_t sz) : data(sz, -1) {}

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return false;
        if(data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }

    int find(int x) { return data[x] < 0 ? x : data[x] = find(data[x]); }

    int size(int x) { return -data[x]; }

    bool same(int x, int y) { return find(x) == find(y); }
};