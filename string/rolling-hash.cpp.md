---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-zalgo-rollinghash.test.cpp
    title: test/yosupo-zalgo-rollinghash.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/rolling-hash.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nclass RollingHash {\nprivate:\n    const uint64_t MOD\
    \ = (1ull << 61) - 1;\n    const uint64_t POSITIVIZER = MOD * 7;\n    vector<uint64_t>\
    \ power{1};\n    uint64_t base = 0;\n\n    uint64_t mul(uint64_t l, uint64_t r)\
    \ {\n        __uint128_t t = l * r;\n        t = (t >> 61) + (t & MOD);\n    \
    \    if(t >= MOD) return t - MOD;\n        return t;\n    }\n    uint64_t get_base()\
    \ {\n        random_device engine;\n        uniform_int_distribution<uint64_t>\
    \ dist(129, MOD - 1);\n        return dist(engine);\n    }\n    uint64_t pow(size_t\
    \ p) {\n        if(power.size() <= p) {\n            size_t sz = power.size();\n\
    \            power.resize(p + 1);\n            while(sz <= p) {\n            \
    \    power[sz] = mul(power[sz - 1], base);\n                sz++;\n          \
    \  }\n        }\n        return power[p];\n    }\n\npublic:\n    explicit RollingHash()\
    \ : base(get_base()) {}\n    vector<uint64_t> build(const string &s) {\n     \
    \   vector<uint64_t> hashed(s.size() + 1);\n        for(size_t i = 0; i < s.size();\
    \ i++) {\n            hashed[i + 1] = mul(hashed[i], base) + s[i];\n         \
    \   if(hashed[i + 1] >= MOD) hashed[i + 1] -= MOD;\n        }\n        return\
    \ hashed;\n    }\n    uint64_t slice(const vector<uint64_t> &hashed, size_t l,\
    \ size_t r) {\n        uint64_t res = hashed[r] + MOD - mul(hashed[l], pow(r -\
    \ l));\n        if(res >= MOD) res -= MOD;\n        return res;\n    }\n};\n"
  code: "#pragma once\n\n#include <bits/stdc++.h>\nusing namespace std;\n\nclass RollingHash\
    \ {\nprivate:\n    const uint64_t MOD = (1ull << 61) - 1;\n    const uint64_t\
    \ POSITIVIZER = MOD * 7;\n    vector<uint64_t> power{1};\n    uint64_t base =\
    \ 0;\n\n    uint64_t mul(uint64_t l, uint64_t r) {\n        __uint128_t t = l\
    \ * r;\n        t = (t >> 61) + (t & MOD);\n        if(t >= MOD) return t - MOD;\n\
    \        return t;\n    }\n    uint64_t get_base() {\n        random_device engine;\n\
    \        uniform_int_distribution<uint64_t> dist(129, MOD - 1);\n        return\
    \ dist(engine);\n    }\n    uint64_t pow(size_t p) {\n        if(power.size()\
    \ <= p) {\n            size_t sz = power.size();\n            power.resize(p +\
    \ 1);\n            while(sz <= p) {\n                power[sz] = mul(power[sz\
    \ - 1], base);\n                sz++;\n            }\n        }\n        return\
    \ power[p];\n    }\n\npublic:\n    explicit RollingHash() : base(get_base()) {}\n\
    \    vector<uint64_t> build(const string &s) {\n        vector<uint64_t> hashed(s.size()\
    \ + 1);\n        for(size_t i = 0; i < s.size(); i++) {\n            hashed[i\
    \ + 1] = mul(hashed[i], base) + s[i];\n            if(hashed[i + 1] >= MOD) hashed[i\
    \ + 1] -= MOD;\n        }\n        return hashed;\n    }\n    uint64_t slice(const\
    \ vector<uint64_t> &hashed, size_t l, size_t r) {\n        uint64_t res = hashed[r]\
    \ + MOD - mul(hashed[l], pow(r - l));\n        if(res >= MOD) res -= MOD;\n  \
    \      return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/rolling-hash.cpp
  requiredBy: []
  timestamp: '2025-04-28 14:46:55+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-zalgo-rollinghash.test.cpp
documentation_of: string/rolling-hash.cpp
layout: document
redirect_from:
- /library/string/rolling-hash.cpp
- /library/string/rolling-hash.cpp.html
title: string/rolling-hash.cpp
---
