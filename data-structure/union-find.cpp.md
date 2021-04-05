---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ-DLS-1-A.test.cpp
    title: test/AOJ-DLS-1-A.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/union-find.md
    document_title: Union-Find
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data-structure/union-find.cpp: line 5: #pragma once found in a non-first line\n"
  code: "/*\n * @brief Union-Find\n * @docs docs/union-find.md\n */\n#pragma once\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\nstruct UnionFind {\n    vector<int>\
    \ data;\n\n    UnionFind() = default;\n\n    explicit UnionFind(size_t sz) : data(sz,\
    \ -1) {}\n\n    bool unite(int x, int y) {\n        x = find(x);\n        y =\
    \ find(y);\n        if(x == y) return false;\n        if(data[x] > data[y]) swap(x,\
    \ y);\n        data[x] += data[y];\n        data[y] = x;\n        return true;\n\
    \    }\n\n    int find(int x) { return data[x] < 0 ? x : data[x] = find(data[x]);\
    \ }\n\n    int size(int x) { return -data[x]; }\n\n    bool same(int x, int y)\
    \ { return find(x) == find(y); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/union-find.cpp
  requiredBy: []
  timestamp: '2021-04-05 20:06:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ-DLS-1-A.test.cpp
documentation_of: data-structure/union-find.cpp
layout: document
redirect_from:
- /library/data-structure/union-find.cpp
- /library/data-structure/union-find.cpp.html
title: Union-Find
---
## 説明

集合を扱うデータ構造

- `unite(x, y)`: 集合 `x` と `y` を併合する。未併合か否かを `bool` 値で返す。
- `find(x)`: 要素 `x` が属する集合を求める。
- `size(x)`: 要素 `x` が属する集合の要素数を求める。
- `same(x, y)`: 要素 `x,y` が同じ集合に属するか判定する。

## 計算量

- クエリ: 平均 $O(\alpha(N))$