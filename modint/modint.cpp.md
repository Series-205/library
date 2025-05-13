---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-bitwise_xor_convolution.test.cpp
    title: test/yosupo-bitwise_xor_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-point-set-range-composite-large-array.test.cpp
    title: test/yosupo-point-set-range-composite-large-array.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"modint/modint.cpp\"\n\ntemplate <long long MOD>\nstruct\
    \ Modint {\n    long long x;\n    Modint(long long x_ = 0) : x(x_ % MOD) {\n \
    \       if(x < 0) x += MOD;\n    }\n    friend Modint operator+(Modint a, Modint\
    \ b) { return a.x + b.x; }\n    friend Modint operator-(Modint a, Modint b) {\
    \ return a.x - b.x; }\n    friend Modint operator*(Modint a, Modint b) { return\
    \ a.x * b.x; }\n    friend Modint operator/(Modint a, Modint b) { return a * b.inv();\
    \ }\n    // 4 \u884C\u30B3\u30D4\u30DA  Alt + Shift + \u30AF\u30EA\u30C3\u30AF\
    \u3067\u8907\u6570\u30AB\u30FC\u30BD\u30EB\n    friend Modint& operator+=(Modint&\
    \ a, Modint b) { return a = a.x + b.x; }\n    friend Modint& operator-=(Modint&\
    \ a, Modint b) { return a = a.x - b.x; }\n    friend Modint& operator*=(Modint&\
    \ a, Modint b) { return a = a.x * b.x; }\n    friend Modint& operator/=(Modint&\
    \ a, Modint b) { return a = a * b.inv(); }\n    Modint inv() const { return pow(MOD\
    \ - 2); }\n    Modint pow(long long b) const {\n        Modint a = *this, c =\
    \ 1;\n        while(b) {\n            if(b & 1) c *= a;\n            a *= a;\n\
    \            b >>= 1;\n        }\n        return c;\n    }\n};\n"
  code: "#pragma once\n\ntemplate <long long MOD>\nstruct Modint {\n    long long\
    \ x;\n    Modint(long long x_ = 0) : x(x_ % MOD) {\n        if(x < 0) x += MOD;\n\
    \    }\n    friend Modint operator+(Modint a, Modint b) { return a.x + b.x; }\n\
    \    friend Modint operator-(Modint a, Modint b) { return a.x - b.x; }\n    friend\
    \ Modint operator*(Modint a, Modint b) { return a.x * b.x; }\n    friend Modint\
    \ operator/(Modint a, Modint b) { return a * b.inv(); }\n    // 4 \u884C\u30B3\
    \u30D4\u30DA  Alt + Shift + \u30AF\u30EA\u30C3\u30AF\u3067\u8907\u6570\u30AB\u30FC\
    \u30BD\u30EB\n    friend Modint& operator+=(Modint& a, Modint b) { return a =\
    \ a.x + b.x; }\n    friend Modint& operator-=(Modint& a, Modint b) { return a\
    \ = a.x - b.x; }\n    friend Modint& operator*=(Modint& a, Modint b) { return\
    \ a = a.x * b.x; }\n    friend Modint& operator/=(Modint& a, Modint b) { return\
    \ a = a * b.inv(); }\n    Modint inv() const { return pow(MOD - 2); }\n    Modint\
    \ pow(long long b) const {\n        Modint a = *this, c = 1;\n        while(b)\
    \ {\n            if(b & 1) c *= a;\n            a *= a;\n            b >>= 1;\n\
    \        }\n        return c;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: modint/modint.cpp
  requiredBy: []
  timestamp: '2025-05-13 23:20:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-bitwise_xor_convolution.test.cpp
  - test/yosupo-point-set-range-composite-large-array.test.cpp
documentation_of: modint/modint.cpp
layout: document
redirect_from:
- /library/modint/modint.cpp
- /library/modint/modint.cpp.html
title: modint/modint.cpp
---
