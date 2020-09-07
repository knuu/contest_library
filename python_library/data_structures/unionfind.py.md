---
data:
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "class UnionFindTree:\n    \"\"\"Disjoint-Set Data Structure\n\n    Union-Find\
    \ Tree\n\n    complexity:\n        - init: O(n)\n        - find, unite, same:\
    \ O(alpha(n))\n    \"\"\"\n\n    def __init__(self, n):\n        self.par = list(range(n))\
    \  # parent\n        self.rank = [0] * n  # depth of tree\n\n    def find(self,\
    \ x):\n        if self.par[x] == x:\n            return x\n        else:\n   \
    \         self.par[x] = self.find(self.par[x])\n            return self.par[x]\n\
    \n    def unite(self, x, y):\n        x, y = self.find(x), self.find(y)\n    \
    \    if x == y:\n            return\n        if self.rank[x] < self.rank[y]:\n\
    \            self.par[x] = y\n        else:\n            self.par[y] = x\n   \
    \         if self.rank[x] == self.rank[y]:\n                self.rank[x] += 1\n\
    \n    def is_same(self, x, y):\n        return self.find(x) == self.find(y)\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith:
  - icon: ':x:'
    path: tests/python/union_find.test.py
    title: tests/python/union_find.test.py
  isVerificationFile: false
  path: python_library/data_structures/unionfind.py
  requiredBy: []
  timestamp: '2020-02-16 04:55:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verificationStatusIcon: ':x:'
  verifiedWith:
  - tests/python/union_find.test.py
documentation_of: python_library/data_structures/unionfind.py
layout: document
redirect_from:
- /library/python_library/data_structures/unionfind.py
- /library/python_library/data_structures/unionfind.py.html
title: python_library/data_structures/unionfind.py
---
