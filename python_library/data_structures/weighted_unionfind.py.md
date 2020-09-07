---
data:
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "class WeightedUnionFindTree:\n    \"\"\"Disjoint-Set Data Structure with\
    \ weight\n\n    complexity:\n        - init: O(n)\n        - find, unite, same:\
    \ O(alpha(n))\n    \"\"\"\n\n    def __init__(self, n_nodes):\n        self.par\
    \ = [i for i in range(n_nodes)]  # parent\n        self.rank = [0] * n_nodes \
    \ # depth of tree\n        self.weights = [0] * n_nodes\n\n    def find(self,\
    \ x):\n        if self.par[x] == x:\n            return x\n        root = self.find(self.par[x])\n\
    \        self.weights[x] += self.weights[self.par[x]]\n        self.par[x] = root\n\
    \        return root\n\n    def unite(self, x, y, weight=0):\n        root_x,\
    \ root_y = self.find(x), self.find(y)\n        if root_x == root_y:\n        \
    \    return\n        if self.rank[root_x] < self.rank[root_y]:\n            self.par[root_x]\
    \ = root_y\n            self.weights[root_x] = weight - self.weights[x] + self.weights[y]\n\
    \        else:\n            self.par[root_y] = root_x\n            self.weights[root_y]\
    \ = -weight - self.weights[y] + self.weights[x]\n            if self.rank[root_x]\
    \ == self.rank[root_y]:\n                self.rank[root_x] += 1\n\n    def is_same(self,\
    \ x, y):\n        return self.find(x) == self.find(y)\n\n    def diff(self, x,\
    \ y):\n        return self.weights[x] - self.weights[y]\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith:
  - icon: ':x:'
    path: tests/python/weighted_unionfind.test.py
    title: tests/python/weighted_unionfind.test.py
  isVerificationFile: false
  path: python_library/data_structures/weighted_unionfind.py
  requiredBy: []
  timestamp: '2020-02-16 04:55:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verificationStatusIcon: ':x:'
  verifiedWith:
  - tests/python/weighted_unionfind.test.py
documentation_of: python_library/data_structures/weighted_unionfind.py
layout: document
redirect_from:
- /library/python_library/data_structures/weighted_unionfind.py
- /library/python_library/data_structures/weighted_unionfind.py.html
title: python_library/data_structures/weighted_unionfind.py
---
