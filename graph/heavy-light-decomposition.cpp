#pragma once

#include <bits/stdc++.h>
using namespace std;

struct HeavyLightDecomposition {
    vector<vector<int>> &g;
    vector<int> sz, in, out, head, rev, par;

    explicit HeavyLightDecomposition(vector<vector<int>> &g)
        : g(g),
          sz(g.size()),
          in(g.size()),
          out(g.size()),
          head(g.size()),
          rev(g.size()),
          par(g.size()) {}

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

    void build(int r = 0) {
        dfs_sz(r, -1);
        int t = 0;
        dfs_hld(r, -1, t);
    }

    int lca(int u, int v) {
        while(true) {
            if(in[u] > in[v]) swap(u, v);
            if(head[u] == head[v]) return u;
            v = par[head[v]];
        }
    }

    template <typename Q>
    void add(int u, int v, const Q &q, bool edge = false) {
        while(true) {
            if(in[u] > in[v]) swap(u, v);
            if(head[u] == head[v]) break;
            q(in[head[v]], in[v] + 1);
            v = par[head[v]];
        }
        q(in[u] + edge, in[v] + 1);
    }

    template <typename T, typename Q, typename F>
    T query(int u, int v, const T &ti, const Q &q, const F &f,
            bool edge = false) {
        T l = ti, r = ti;
        while(true) {
            if(in[u] > in[v]) {
                swap(u, v);
                swap(l, r);
            }
            if(head[u] == head[v]) break;
            l = f(q(in[head[v]], in[v] + 1), l);
            v = par[head[v]];
        }
        return f(f(q(in[u] + edge, in[v] + 1), l), r);
    }
};
/*
 * @brief Heavy-Light-Decomposition
 * @docs docs/heavy-light-decomposition.md
 */