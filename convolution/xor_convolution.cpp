#pragma once
#include <bits/stdc++.h>
using namespace std;

class xorConvolution {
    template <typename T>
    static void FWT(vector<T>& f) {
        int n = f.size();
        for(int i = 1; i < n; i <<= 1)
            for(int j = 0; j < n; j++)
                if((j & i) == 0) {
                    T x = f[j], y = f[j | i];
                    f[j] = x + y, f[j | i] = x - y;
                }
    }

public:
    template <typename T>
    static vector<T> convolution(vector<T> f, vector<T> g) {
        int sz = 1, n = max(f.size(), g.size());
        while(sz < n) sz <<= 1;
        f.resize(sz);
        g.resize(sz);
        FWT(f);
        FWT(g);
        for(int i = 0; i < sz; i++) f[i] *= g[i];
        FWT(f);
        for(int i = 0; i < sz; i++) f[i] /= sz;
        return f;
    }
};