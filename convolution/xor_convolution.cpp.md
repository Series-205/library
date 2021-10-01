---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-bitwise_xor_convolution.test.cpp
    title: test/yosupo-bitwise_xor_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convolution/xor_convolution.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nclass xorConvolution {\n    template <typename T>\n  \
    \  static void FWT(vector<T>& f) {\n        int n = f.size();\n        for(int\
    \ i = 1; i < n; i <<= 1)\n            for(int j = 0; j < n; j++)\n           \
    \     if((j & i) == 0) {\n                    T x = f[j], y = f[j | i];\n    \
    \                f[j] = x + y, f[j | i] = x - y;\n                }\n    }\n\n\
    public:\n    template <typename T>\n    static vector<T> convolution(vector<T>\
    \ f, vector<T> g) {\n        int sz = 1, n = max(f.size(), g.size());\n      \
    \  while(sz < n) sz <<= 1;\n        f.resize(sz);\n        g.resize(sz);\n   \
    \     FWT(f);\n        FWT(g);\n        for(int i = 0; i < sz; i++) f[i] *= g[i];\n\
    \        FWT(f);\n        for(int i = 0; i < sz; i++) f[i] /= sz;\n        return\
    \ f;\n    }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nclass xorConvolution\
    \ {\n    template <typename T>\n    static void FWT(vector<T>& f) {\n        int\
    \ n = f.size();\n        for(int i = 1; i < n; i <<= 1)\n            for(int j\
    \ = 0; j < n; j++)\n                if((j & i) == 0) {\n                    T\
    \ x = f[j], y = f[j | i];\n                    f[j] = x + y, f[j | i] = x - y;\n\
    \                }\n    }\n\npublic:\n    template <typename T>\n    static vector<T>\
    \ convolution(vector<T> f, vector<T> g) {\n        int sz = 1, n = max(f.size(),\
    \ g.size());\n        while(sz < n) sz <<= 1;\n        f.resize(sz);\n       \
    \ g.resize(sz);\n        FWT(f);\n        FWT(g);\n        for(int i = 0; i <\
    \ sz; i++) f[i] *= g[i];\n        FWT(f);\n        for(int i = 0; i < sz; i++)\
    \ f[i] /= sz;\n        return f;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: convolution/xor_convolution.cpp
  requiredBy: []
  timestamp: '2021-10-02 08:42:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-bitwise_xor_convolution.test.cpp
documentation_of: convolution/xor_convolution.cpp
layout: document
redirect_from:
- /library/convolution/xor_convolution.cpp
- /library/convolution/xor_convolution.cpp.html
title: convolution/xor_convolution.cpp
---
