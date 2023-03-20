#pragma once

#include <bits/stdc++.h>
using namespace std;

struct CentroidDecomposition {
private:
    vector<bool> used;
    vector<int> sz;

    inline int calc_size(int u, int p) {
        sz[u] = 1;
        for(int v : tree[u])
            if(!used[v] && v != p) sz[u] += calc_size(v, u);
        return sz[u];
    }

    inline int find_centroid(int u, int p, const int mid) {
        for(int v : tree[u])
            if(!used[v] && v != p && sz[v] > mid)
                return find_centroid(v, u, mid);
        return u;
    }

    inline void belong_dfs(int u, int p, int centroid) {
        belong[u].push_back(centroid);
        for(int v : tree[u])
            if(!used[v] && v != p) belong_dfs(v, u, centroid);
    }

    inline int build(int u) {
        int centroid = find_centroid(u, -1, calc_size(u, -1) / 2);
        used[centroid] = true;
        belong_dfs(centroid, -1, centroid);
        for(int v : tree[centroid])
            if(!used[v]) cdtree[centroid].push_back(build(v));
        used[centroid] = false;
        return centroid;
    }

public:
    vector<vector<int>> tree, cdtree;
    vector<vector<int>> belong;  // belong[u]: u を含む連結成分の centroid たち
    int root = -1;               // root of cdtree

    explicit CentroidDecomposition(const vector<vector<int>> &g)
        : tree(g), root(-1) {}

    explicit CentroidDecomposition(int n) : tree(n), root(-1) {}

    inline void add_edge(int u, int v) {
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    // return root of cdtree
    inline int build() {
        cdtree.assign(tree.size(), {});
        used.assign(tree.size(), false);
        sz.resize(tree.size());
        belong.assign(tree.size(), {});
        return root = build(0);
    }
};
