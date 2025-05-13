---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-point-set-range-composite-large-array.test.cpp
    title: test/yosupo-point-set-range-composite-large-array.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"segtree/dynamic-segment-tree.cpp\"\n\ntemplate <typename\
    \ S, S (*op)(S, S), S (*e)(), long long WORD>\nstruct DynamicSegTree {\n    void\
    \ set(long long p, S x) { set(p, WORD - 1, x); }\n    S get(long long p) { return\
    \ get(p, WORD - 1); }\n    S all_prod() { return data; }\n    S prod(long long\
    \ l, long long r) { return prod(l, r, 0, 1LL << WORD); }\n\n    DynamicSegTree()\
    \ : data(e()) { cld[0] = cld[1] = nullptr; }\n\nprivate:\n    DynamicSegTree *cld[2];\n\
    \    S data;\n\n    DynamicSegTree *child(long long bit) {\n        if(cld[bit]\
    \ == nullptr) {\n            cld[bit] = new DynamicSegTree();\n        }\n   \
    \     return cld[bit];\n    }\n    S child_data(long long bit) {\n        if(cld[bit]\
    \ == nullptr)\n            return e();\n        else\n            return cld[bit]->data;\n\
    \    }\n\n    void update() { data = op(child_data(0), child_data(1)); }\n\n \
    \   void set(long long p, long long digit, S x) {\n        if(digit == -1) {\n\
    \            data = x;\n        } else {\n            long long bit = p >> digit\
    \ & 1;\n            child(bit)->set(p, digit - 1, x);\n            update();\n\
    \        }\n    }\n\n    S get(long long p, long long digit) {\n        if(digit\
    \ == -1) {\n            return data;\n        } else {\n            long long\
    \ bit = p >> digit & 1;\n            if(cld[bit] == nullptr)\n               \
    \ return e();\n            else\n                return cld[bit]->get(p, digit\
    \ - 1);\n        }\n    }\n\n    S prod(long long L, long long R, long long l,\
    \ long long r) {\n        if(r <= L || R <= l) {\n            return e();\n  \
    \      } else if(L <= l && r <= R) {\n            return data;\n        } else\
    \ {\n            S res = e();\n            if(cld[0] != nullptr) res = cld[0]->prod(L,\
    \ R, l, (l + r) / 2);\n            if(cld[1] != nullptr)\n                res\
    \ = op(res, cld[1]->prod(L, R, (l + r) / 2, r));\n            return res;\n  \
    \      }\n    }\n};\n"
  code: "#pragma once\n\ntemplate <typename S, S (*op)(S, S), S (*e)(), long long\
    \ WORD>\nstruct DynamicSegTree {\n    void set(long long p, S x) { set(p, WORD\
    \ - 1, x); }\n    S get(long long p) { return get(p, WORD - 1); }\n    S all_prod()\
    \ { return data; }\n    S prod(long long l, long long r) { return prod(l, r, 0,\
    \ 1LL << WORD); }\n\n    DynamicSegTree() : data(e()) { cld[0] = cld[1] = nullptr;\
    \ }\n\nprivate:\n    DynamicSegTree *cld[2];\n    S data;\n\n    DynamicSegTree\
    \ *child(long long bit) {\n        if(cld[bit] == nullptr) {\n            cld[bit]\
    \ = new DynamicSegTree();\n        }\n        return cld[bit];\n    }\n    S child_data(long\
    \ long bit) {\n        if(cld[bit] == nullptr)\n            return e();\n    \
    \    else\n            return cld[bit]->data;\n    }\n\n    void update() { data\
    \ = op(child_data(0), child_data(1)); }\n\n    void set(long long p, long long\
    \ digit, S x) {\n        if(digit == -1) {\n            data = x;\n        } else\
    \ {\n            long long bit = p >> digit & 1;\n            child(bit)->set(p,\
    \ digit - 1, x);\n            update();\n        }\n    }\n\n    S get(long long\
    \ p, long long digit) {\n        if(digit == -1) {\n            return data;\n\
    \        } else {\n            long long bit = p >> digit & 1;\n            if(cld[bit]\
    \ == nullptr)\n                return e();\n            else\n               \
    \ return cld[bit]->get(p, digit - 1);\n        }\n    }\n\n    S prod(long long\
    \ L, long long R, long long l, long long r) {\n        if(r <= L || R <= l) {\n\
    \            return e();\n        } else if(L <= l && r <= R) {\n            return\
    \ data;\n        } else {\n            S res = e();\n            if(cld[0] !=\
    \ nullptr) res = cld[0]->prod(L, R, l, (l + r) / 2);\n            if(cld[1] !=\
    \ nullptr)\n                res = op(res, cld[1]->prod(L, R, (l + r) / 2, r));\n\
    \            return res;\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: segtree/dynamic-segment-tree.cpp
  requiredBy: []
  timestamp: '2025-05-13 23:22:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-point-set-range-composite-large-array.test.cpp
documentation_of: segtree/dynamic-segment-tree.cpp
layout: document
redirect_from:
- /library/segtree/dynamic-segment-tree.cpp
- /library/segtree/dynamic-segment-tree.cpp.html
title: segtree/dynamic-segment-tree.cpp
---
