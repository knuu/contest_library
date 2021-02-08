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
  code: "from typing import List\n\n\nclass Graph_AdjMat:\n    def __init__(self,\
    \ V: int, init: int = 10**9) -> None:\n        self.V: int = V\n        self.E:\
    \ List[List[int]] = [[init] * V for _ in range(V)]\n\n    def add_edge(self, src:\
    \ int, dst: int, weight: int) -> None:\n        self.E[src][dst] = weight\n\n\n\
    class WarshallFloyd():\n    def __init__(self, G: Graph_AdjMat, INF: int = 10**9)\
    \ -> None:\n        self.G: Graph_AdjMat = G\n        self.INF: int = INF\n  \
    \      self.distance: List[List[int]] = [[self.INF] * G.V for _ in range(G.V)]\n\
    \        for i in range(G.V):\n            self.distance[i][i] = 0\n        for\
    \ fr in range(G.V):\n            for to in range(G.V):\n                self.distance[fr][to]\
    \ = G.E[fr][to]\n\n    def run(self) -> None:\n        for k in range(self.G.V):\n\
    \            for i in range(self.G.V):\n                for j in range(self.G.V):\n\
    \                    if self.distance[i][k] != self.INF and \\\n             \
    \          self.distance[k][j] != self.INF:\n                        self.distance[i][j]\
    \ \\\n                            = min(self.distance[i][j],\n               \
    \                   self.distance[i][k] + self.distance[k][j])\n\n    def hasNegativeCycle(self)\
    \ -> bool:\n        for i in range(self.G.V):\n            if self.distance[i][i]\
    \ < 0:\n                return True\n        return False\n"
  dependsOn: []
  isVerificationFile: false
  path: python_library_typed/graph/warshall_floyd.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: python_library_typed/graph/warshall_floyd.py
layout: document
redirect_from:
- /library/python_library_typed/graph/warshall_floyd.py
- /library/python_library_typed/graph/warshall_floyd.py.html
title: python_library_typed/graph/warshall_floyd.py
---
