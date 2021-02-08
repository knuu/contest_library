---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "from typing import List\n\n\nclass UnionFindTree:\n    \"\"\"Disjoint-Set\
    \ Data Structure\n       Union-Find Tree\n       complexity:\n          init:\
    \ O(n)\n          find, unite, same: O(alpha(n))\n       used in SRM505 div.2\
    \ 900, ATC001 A, DSL1A(AOJ)\n    \"\"\"\n    def __init__(self, N: int) -> None:\n\
    \        self.par: List[int] = list(range(N))  # parent\n        self.rank: List[int]\
    \ = [0] * N  # depth of tree\n\n    def find(self, x: int) -> int:\n        if\
    \ self.par[x] == x:\n            return x\n        else:\n            self.par[x]\
    \ = self.find(self.par[x])\n            return self.par[x]\n\n    def unite(self,\
    \ x: int, y: int) -> None:\n        x, y = self.find(x), self.find(y)\n      \
    \  if x == y:\n            return\n        if self.rank[x] < self.rank[y]:\n \
    \           self.par[x] = y\n        else:\n            self.par[y] = x\n    \
    \        if self.rank[x] == self.rank[y]:\n                self.rank[x] += 1\n\
    \n    def same(self, x: int, y: int) -> bool:\n        return self.find(x) ==\
    \ self.find(y)\n"
  dependsOn: []
  isVerificationFile: false
  path: python_library_typed/data_structures/unionfind.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: python_library_typed/data_structures/unionfind.py
layout: document
redirect_from:
- /library/python_library_typed/data_structures/unionfind.py
- /library/python_library_typed/data_structures/unionfind.py.html
title: python_library_typed/data_structures/unionfind.py
---
