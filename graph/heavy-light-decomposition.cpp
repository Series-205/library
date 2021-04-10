#pragma once

#include <bits/stdc++.h>
using namespace std;

class HeavyLightDecomposition {
private:
    vector<vector<int>> g;
    vector<int> sz, in, out, head, rev, par;
    bool built;

    void dfs_sz(int v, int p) {
        par[v] = p;
        sz[v] = 1;
        if(!g[v].empty() && g[v][0] == p) swap(g[v][0], g[v].back());
        for(auto &&u : g[v])
            if(u != p) {
                dfs_sz(u, v);
                sz[v] += sz[u];
                if(sz[u] > sz[g[v][0]]) swap(u, g[v][0]);
            }
    }

    void dfs_hld(int v, int p, int &t) {
        in[v] = t++;
        rev[in[v]] = v;
        for(auto &&u : g[v])
            if(u != p) {
                head[u] = (u == g[v][0] ? head[v] : u);
                dfs_hld(u, v, t);
            }
        out[v] = t;
    }

public:
    explicit HeavyLightDecomposition(int n)
        : g(n), sz(n), in(n), out(n), head(n), rev(n), par(n), built(false) {}
    explicit HeavyLightDecomposition(const vector<vector<int>> &g, int root = 0)
        : g(g),
          sz(g.size()),
          in(g.size()),
          out(g.size()),
          head(g.size()),
          rev(g.size()),
          par(g.size()) {
        build(root);
    }

    void add_edge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    void build(int r = 0) {
        dfs_sz(r, -1);
        int t = 0;
        head[r] = r;
        dfs_hld(r, -1, t);
        built = true;
    }

    int lca(int u, int v) {
        assert(built);
        while(true) {
            if(in[u] > in[v]) swap(u, v);
            if(head[u] == head[v]) return u;
            v = par[head[v]];
        }
    }

    pair<int, int> subtree_query(int u) {
        assert(built);
        return pair<int, int>{in[u], out[u]};
    }

    vector<pair<int, int>> node_query(int u, int v) {
        assert(built);
        vector<pair<int, int>> res;
        while(true) {
            if(in[u] > in[v]) swap(u, v);
            if(head[u] == head[v]) break;
            res.emplace_back(in[head[v]], in[v] + 1);
            v = par[head[v]];
        }
        res.emplace_back(in[u], in[v] + 1);
        return res;
    }

    vector<pair<int, int>> edge_query(int u, int v) {
        assert(built);
        vector<pair<int, int>> res;
        while(true) {
            if(in[u] > in[v]) swap(u, v);
            if(head[u] == head[v]) break;
            res.emplace_back(in[head[v]], in[v] + 1);
            v = par[head[v]];
        }
        res.emplace_back(in[u] + 1, in[v] + 1);
        return res;
    }

    int operator[](int u) {
        assert(built);
        return in[u];
    }
};
/*
 * @brief Heavy-Light-Decomposition
 * @docs docs/heavy-light-decomposition.md
 */