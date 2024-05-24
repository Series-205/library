---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-zalgo-rollinghash.test.cpp
    title: test/yosupo-zalgo-rollinghash.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/rolling-hash.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nclass RollingHash {\nprivate:\n    const uint64_t MOD\
    \ = (1ull << 61) - 1;\n    const uint64_t MASK30 = (1ull << 30) - 1;\n    const\
    \ uint64_t MASK31 = (1ull << 31) - 1;\n    const uint64_t POSITIVIZER = MOD *\
    \ 7;\n    vector<uint64_t> power{1};\n    uint64_t base = 0;\n\n    inline uint64_t\
    \ mul(uint64_t l, uint64_t r) {\n        uint64_t lu = l >> 31;\n        uint64_t\
    \ ld = l & MASK31;\n        uint64_t ru = r >> 31;\n        uint64_t rd = r &\
    \ MASK31;\n        uint64_t mid = ld * ru + lu * rd;\n        return ((lu * ru)\
    \ << 1) + ld * rd + ((mid & MASK30) << 31) +\n               (mid >> 30);\n  \
    \  }\n    inline uint64_t calcMod(uint64_t x) {\n        x = (x & MOD) + (x >>\
    \ 61);\n        if(x >= MOD) x -= MOD;\n        return x;\n    }\n    inline uint64_t\
    \ get_base() {\n        random_device engine;\n        uniform_int_distribution<uint64_t>\
    \ dist(129, MOD - 1);\n        return dist(engine);\n    }\n    inline uint64_t\
    \ pow(size_t p) {\n        if(power.size() <= p) {\n            size_t sz = power.size();\n\
    \            power.resize(p + 1);\n            while(sz <= p) {\n            \
    \    power[sz] = calcMod(mul(power[sz - 1], base));\n                sz++;\n \
    \           }\n        }\n        return power[p];\n    }\n\npublic:\n    explicit\
    \ RollingHash() : base(get_base()) {}\n    vector<uint64_t> build(const string\
    \ &s) {\n        vector<uint64_t> hashed(s.size() + 1);\n        for(size_t i\
    \ = 0; i < s.size(); i++)\n            hashed[i + 1] = calcMod(mul(hashed[i],\
    \ base) + s[i]);\n        return hashed;\n    }\n    inline uint64_t slice(const\
    \ vector<uint64_t> &hashed, size_t l, size_t r) {\n        return calcMod(hashed[r]\
    \ + POSITIVIZER - mul(hashed[l], pow(r - l)));\n    }\n};\n"
  code: "#pragma once\n\n#include <bits/stdc++.h>\nusing namespace std;\n\nclass RollingHash\
    \ {\nprivate:\n    const uint64_t MOD = (1ull << 61) - 1;\n    const uint64_t\
    \ MASK30 = (1ull << 30) - 1;\n    const uint64_t MASK31 = (1ull << 31) - 1;\n\
    \    const uint64_t POSITIVIZER = MOD * 7;\n    vector<uint64_t> power{1};\n \
    \   uint64_t base = 0;\n\n    inline uint64_t mul(uint64_t l, uint64_t r) {\n\
    \        uint64_t lu = l >> 31;\n        uint64_t ld = l & MASK31;\n        uint64_t\
    \ ru = r >> 31;\n        uint64_t rd = r & MASK31;\n        uint64_t mid = ld\
    \ * ru + lu * rd;\n        return ((lu * ru) << 1) + ld * rd + ((mid & MASK30)\
    \ << 31) +\n               (mid >> 30);\n    }\n    inline uint64_t calcMod(uint64_t\
    \ x) {\n        x = (x & MOD) + (x >> 61);\n        if(x >= MOD) x -= MOD;\n \
    \       return x;\n    }\n    inline uint64_t get_base() {\n        random_device\
    \ engine;\n        uniform_int_distribution<uint64_t> dist(129, MOD - 1);\n  \
    \      return dist(engine);\n    }\n    inline uint64_t pow(size_t p) {\n    \
    \    if(power.size() <= p) {\n            size_t sz = power.size();\n        \
    \    power.resize(p + 1);\n            while(sz <= p) {\n                power[sz]\
    \ = calcMod(mul(power[sz - 1], base));\n                sz++;\n            }\n\
    \        }\n        return power[p];\n    }\n\npublic:\n    explicit RollingHash()\
    \ : base(get_base()) {}\n    vector<uint64_t> build(const string &s) {\n     \
    \   vector<uint64_t> hashed(s.size() + 1);\n        for(size_t i = 0; i < s.size();\
    \ i++)\n            hashed[i + 1] = calcMod(mul(hashed[i], base) + s[i]);\n  \
    \      return hashed;\n    }\n    inline uint64_t slice(const vector<uint64_t>\
    \ &hashed, size_t l, size_t r) {\n        return calcMod(hashed[r] + POSITIVIZER\
    \ - mul(hashed[l], pow(r - l)));\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/rolling-hash.cpp
  requiredBy: []
  timestamp: '2024-05-24 18:26:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-zalgo-rollinghash.test.cpp
documentation_of: string/rolling-hash.cpp
layout: document
redirect_from:
- /library/string/rolling-hash.cpp
- /library/string/rolling-hash.cpp.html
title: string/rolling-hash.cpp
---
