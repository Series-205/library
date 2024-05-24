---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/rolling-hash.cpp
    title: string/rolling-hash.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"test/yosupo-zalgo-rollinghash.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/zalgorithm\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 2 \"string/rolling-hash.cpp\"\n\n#line 4 \"string/rolling-hash.cpp\"\
    \nusing namespace std;\n\nclass RollingHash {\nprivate:\n    const uint64_t MOD\
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
    \ + POSITIVIZER - mul(hashed[l], pow(r - l)));\n    }\n};\n#line 7 \"test/yosupo-zalgo-rollinghash.test.cpp\"\
    \n\nint main() {\n    string s;\n    cin >> s;\n    int n = (int)s.size();\n\n\
    \    RollingHash rh;\n    auto hashed = rh.build(s);\n\n    for(int i = 0; i <\
    \ n; i++) {\n        int ok = 0, ng = n - i + 1;\n        while(ng - ok > 1) {\n\
    \            int mid = (ok + ng) / 2;\n            if(rh.slice(hashed, 0, mid)\
    \ == rh.slice(hashed, i, i + mid))\n                ok = mid;\n            else\n\
    \                ng = mid;\n        }\n\n        cout << ok << \" \\n\"[i + 1\
    \ == n];\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../string/rolling-hash.cpp\"\
    \n\nint main() {\n    string s;\n    cin >> s;\n    int n = (int)s.size();\n\n\
    \    RollingHash rh;\n    auto hashed = rh.build(s);\n\n    for(int i = 0; i <\
    \ n; i++) {\n        int ok = 0, ng = n - i + 1;\n        while(ng - ok > 1) {\n\
    \            int mid = (ok + ng) / 2;\n            if(rh.slice(hashed, 0, mid)\
    \ == rh.slice(hashed, i, i + mid))\n                ok = mid;\n            else\n\
    \                ng = mid;\n        }\n\n        cout << ok << \" \\n\"[i + 1\
    \ == n];\n    }\n}"
  dependsOn:
  - string/rolling-hash.cpp
  isVerificationFile: true
  path: test/yosupo-zalgo-rollinghash.test.cpp
  requiredBy: []
  timestamp: '2024-05-24 18:47:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-zalgo-rollinghash.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-zalgo-rollinghash.test.cpp
- /verify/test/yosupo-zalgo-rollinghash.test.cpp.html
title: test/yosupo-zalgo-rollinghash.test.cpp
---
