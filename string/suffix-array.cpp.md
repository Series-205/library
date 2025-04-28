---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ-ALDS1-14-D.test.cpp
    title: test/AOJ-ALDS1-14-D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-suffixarray.test.cpp
    title: test/yosupo-suffixarray.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/suffix-array.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n// Manber and Myers O(n log^2 n)\nclass SuffixArray {\n\
    private:\n    const string s;\n    int n;\n    vector<int> sa;\n    bool low_comp(const\
    \ string& t, int si = 0, int ti = 0) {\n        int tn = t.size();\n        while(si\
    \ < n && ti < tn) {\n            if(s[si] != t[ti]) return s[si] < t[ti];\n  \
    \          si++;\n            ti++;\n        }\n        return si >= n && ti <\
    \ tn;\n    }\n\npublic:\n    explicit SuffixArray(const string& str) : s(str),\
    \ n(str.size()), sa(n) {\n        vector<int> rank(n), tmp(n);\n        for(int\
    \ i = 0; i < n; i++) {\n            sa[i] = i;\n            rank[i] = str[i];\n\
    \        }\n\n        int k;\n        auto comp = [&](int i, int j) -> bool {\n\
    \            if(rank[i] != rank[j])\n                return rank[i] < rank[j];\n\
    \            else {\n                int ri = i + k < n ? rank[i + k] : -1;\n\
    \                int rj = j + k < n ? rank[j + k] : -1;\n                return\
    \ ri < rj;\n            }\n        };\n\n        for(k = 1; k <= n; k *= 2) {\n\
    \            sort(sa.begin(), sa.end(), comp);\n\n            tmp[sa[0]] = 0;\n\
    \            for(int i = 1; i < n; i++)\n                tmp[sa[i]] = tmp[sa[i\
    \ - 1]] + comp(sa[i - 1], sa[i]);\n            rank.swap(tmp);\n        }\n  \
    \  }\n\n    int operator[](int i) const {\n        assert(0 <= i && i <= n);\n\
    \        return sa[i];\n    }\n\n    int lower_bound(const string& t) {\n    \
    \    int l = -1, r = n;\n        while(r - l > 1) {\n            int mid = (l\
    \ + r) / 2;\n            (low_comp(t, sa[mid]) ? l : r) = mid;\n        }\n  \
    \      return r;\n    }\n\n    int upper_bound(string& t) {\n        t.back()++;\n\
    \        int res = lower_bound(t);\n        t.back()--;\n        return res;\n\
    \    }\n};\n"
  code: "#pragma once\n\n#include <bits/stdc++.h>\nusing namespace std;\n\n// Manber\
    \ and Myers O(n log^2 n)\nclass SuffixArray {\nprivate:\n    const string s;\n\
    \    int n;\n    vector<int> sa;\n    bool low_comp(const string& t, int si =\
    \ 0, int ti = 0) {\n        int tn = t.size();\n        while(si < n && ti < tn)\
    \ {\n            if(s[si] != t[ti]) return s[si] < t[ti];\n            si++;\n\
    \            ti++;\n        }\n        return si >= n && ti < tn;\n    }\n\npublic:\n\
    \    explicit SuffixArray(const string& str) : s(str), n(str.size()), sa(n) {\n\
    \        vector<int> rank(n), tmp(n);\n        for(int i = 0; i < n; i++) {\n\
    \            sa[i] = i;\n            rank[i] = str[i];\n        }\n\n        int\
    \ k;\n        auto comp = [&](int i, int j) -> bool {\n            if(rank[i]\
    \ != rank[j])\n                return rank[i] < rank[j];\n            else {\n\
    \                int ri = i + k < n ? rank[i + k] : -1;\n                int rj\
    \ = j + k < n ? rank[j + k] : -1;\n                return ri < rj;\n         \
    \   }\n        };\n\n        for(k = 1; k <= n; k *= 2) {\n            sort(sa.begin(),\
    \ sa.end(), comp);\n\n            tmp[sa[0]] = 0;\n            for(int i = 1;\
    \ i < n; i++)\n                tmp[sa[i]] = tmp[sa[i - 1]] + comp(sa[i - 1], sa[i]);\n\
    \            rank.swap(tmp);\n        }\n    }\n\n    int operator[](int i) const\
    \ {\n        assert(0 <= i && i <= n);\n        return sa[i];\n    }\n\n    int\
    \ lower_bound(const string& t) {\n        int l = -1, r = n;\n        while(r\
    \ - l > 1) {\n            int mid = (l + r) / 2;\n            (low_comp(t, sa[mid])\
    \ ? l : r) = mid;\n        }\n        return r;\n    }\n\n    int upper_bound(string&\
    \ t) {\n        t.back()++;\n        int res = lower_bound(t);\n        t.back()--;\n\
    \        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/suffix-array.cpp
  requiredBy: []
  timestamp: '2021-07-08 21:14:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-suffixarray.test.cpp
  - test/AOJ-ALDS1-14-D.test.cpp
documentation_of: string/suffix-array.cpp
layout: document
redirect_from:
- /library/string/suffix-array.cpp
- /library/string/suffix-array.cpp.html
title: string/suffix-array.cpp
---
