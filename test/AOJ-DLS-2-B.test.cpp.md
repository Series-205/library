---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: segtree/fenwick-tree.cpp
    title: Fenwick-Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ segtree/fenwick-tree.cpp: line 5: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../segtree/fenwick-tree.cpp\"\
    \n\nint main() {\n    int n, q;\n    cin >> n >> q;\n\n    FenwickTree<int> bit(n);\n\
    \n    for(int i = 0; i < q; i++) {\n        int c, x, y;\n        cin >> c >>\
    \ x >> y;\n        if(c)\n            cout << bit.sum(x - 1, y) << \"\\n\";\n\
    \        else\n            bit.add(x - 1, y);\n    }\n}"
  dependsOn:
  - segtree/fenwick-tree.cpp
  isVerificationFile: true
  path: test/AOJ-DLS-2-B.test.cpp
  requiredBy: []
  timestamp: '2021-04-05 20:06:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ-DLS-2-B.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ-DLS-2-B.test.cpp
- /verify/test/AOJ-DLS-2-B.test.cpp.html
title: test/AOJ-DLS-2-B.test.cpp
---
