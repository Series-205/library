#pragma once

#include <bits/stdc++.h>
using namespace std;

// Manber and Myers O(n log^2 n)
class SuffixArray {
private:
    const string s;
    int n;
    vector<int> sa;
    bool low_comp(const string& t, int si = 0, int ti = 0) {
        int tn = t.size();
        while(si < n && ti < tn) {
            if(s[si] != t[ti]) return s[si] < t[ti];
            si++;
            ti++;
        }
        return si >= n && ti < tn;
    }

public:
    explicit SuffixArray(const string& str) : s(str), n(str.size()), sa(n) {
        vector<int> rank(n), tmp(n);
        for(int i = 0; i < n; i++) {
            sa[i] = i;
            rank[i] = str[i];
        }

        int k;
        auto comp = [&](int i, int j) -> bool {
            if(rank[i] != rank[j])
                return rank[i] < rank[j];
            else {
                int ri = i + k < n ? rank[i + k] : -1;
                int rj = j + k < n ? rank[j + k] : -1;
                return ri < rj;
            }
        };

        for(k = 1; k <= n; k *= 2) {
            sort(sa.begin(), sa.end(), comp);

            tmp[sa[0]] = 0;
            for(int i = 1; i < n; i++)
                tmp[sa[i]] = tmp[sa[i - 1]] + comp(sa[i - 1], sa[i]);
            rank.swap(tmp);
        }
    }

    int operator[](int i) const {
        assert(0 <= i && i <= n);
        return sa[i];
    }

    int lower_bound(const string& t) {
        int l = -1, r = n;
        while(r - l > 1) {
            int mid = (l + r) / 2;
            (low_comp(t, sa[mid]) ? l : r) = mid;
        }
        return r;
    }

    int upper_bound(string& t) {
        t.back()++;
        int res = lower_bound(t);
        t.back()--;
        return res;
    }
};