#pragma once

#include <bits/stdc++.h>
using namespace std;

// Knuth-Morris-Pratt algorithm
class KMP {
private:
    static vector<int> makeTable(const string &s) {
        int n = (int)s.size();
        vector<int> ret(n + 1);
        int j = -1;
        ret[0] = j;
        for(int i = 0; i < n; i++) {
            while(j >= 0 && s[i] != s[j]) j = ret[j];
            j++;
            if(i + 1 < n && ret[j] >= 0 && s[i + 1] == s[j])
                ret[i + 1] = ret[j];
            else
                ret[i + 1] = j;
        }
        return ret;
    }

public:
    // search "word" within "str"
    // O(|str|)
    static vector<int> search(const string &str, const string &word) {
        vector<int> table(makeTable(word)), ret;
        const int N = (int)str.size(), M = (int)word.size();
        int m = 0, i = 0;
        while(m + i < N) {
            if(word[i] == str[m + i]) {
                if(++i == M) {
                    ret.push_back(m);
                    m += i - table[i];
                    i = table[i];
                }
            } else {
                m += i - table[i];
                if(i > 0) i = table[i];
            }
        }
        return ret;
    }
};
/*
 * @brief KMP
 * @docs docs/kmp.md
 */