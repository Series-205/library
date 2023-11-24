#pragma once

#include <bits/stdc++.h>
using namespace std;

template <class DP>
class ReRooting {
    int size;

private:
    vector<vector<int>> G;
    vector<DP> dp;

    DP id;
    function<DP(DP, DP)> merge;
    function<DP(DP)> add_root;

public:
    ReRooting(int n, DP _id, function<DP(DP, DP)> _merge,
              function<DP(DP)> _add_root)
        : size(n), G(n), dp(n), id(_id), merge(_merge), add_root(_add_root) {}

    ReRooting(vector<vector<int>> _g, DP _id, function<DP(DP, DP)> _merge,
              function<DP(DP)> _add_root)
        : size(_g.size()),
          G(_g),
          dp(_g.size()),
          id(_id),
          merge(_merge),
          add_root(_add_root) {}

    void add_edge(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    }

    void build(int root = 0) {
        dfs1(root, -1);
        dfs2(root, -1, id);
    }

    const DP operator[](size_t n) const { return dp[n]; }

private:
    DP dfs1(int v, int p) {
        dp[v] = id;
        for(int u : G[v]) {
            if(u != p) {
                dp[v] = merge(dp[v], dfs1(u, v));
            }
        }
        return dp[v] = add_root(dp[v]);
    }

    void dfs2(int v, int p, DP dp_p) {
        size_t n = G[v].size();
        if(n == 0) {
            dp[v] = add_root(id);
            return;
        }
        vector<DP> l(n, id);
        for(int i = 0; i < n; i++) {
            int u = G[v][i];
            if(u == p) {
                l[i] = dp_p;
            } else {
                l[i] = dp[u];
            }
        }
        auto r = l;

        for(int i = 0; i + 1 < n; i++) l[i + 1] = merge(l[i], l[i + 1]);
        for(int i = n - 1; i > 0; i--) r[i - 1] = merge(r[i - 1], r[i]);

        dp[v] = add_root(r[0]);

        for(int i = 0; i < n; i++) {
            int u = G[v][i];
            if(u != p) {
                DP a = (i ? l[i - 1] : id);
                DP b = (i + 1 < (ll)n ? r[i + 1] : id);
                dfs2(u, v, add_root(merge(a, b)));
            }
        }
    }
};