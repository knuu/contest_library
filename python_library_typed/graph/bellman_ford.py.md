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
  code: "from typing import List, TypeVar, Generic\nT = TypeVar('T', int, float)\n\
    \n\nclass Edge(Generic[T]):\n    def __init__(self, dst: int, weight: T) -> None:\n\
    \        self.dst: int = dst\n        self.weight: T = weight\n\n    def __lt__(self,\
    \ e: 'Edge') -> bool:\n        return self.weight > e.weight\n\n\nclass Graph(Generic[T]):\n\
    \    def __init__(self, V: int) -> None:\n        self.V: int = V\n        self.E:\
    \ List[List[Edge[T]]] = [[] for _ in range(V)]\n\n    def add_edge(self, src:\
    \ int, dst: int, weight: T) -> None:\n        self.E[src].append(Edge(dst, weight))\n\
    \n\nclass BellmanFord(Generic[T]):\n    def __init__(self, G: Graph[T]) -> None:\n\
    \        self.G: Graph[T] = G\n\n    def run(self, start: int = 0, INF: T = 10**9)\
    \ -> None:\n        self.distance: List[T] = [INF] * self.G.V  # distance from\
    \ start\n        self.prev: List[int] = [-1] * self.G.V  # prev vertex of shortest\
    \ path\n        self.distance[start] = 0\n        self.negativeCycle: bool = False\n\
    \n        for i in range(self.G.V):\n            update: bool = False\n      \
    \      for fr in range(self.G.V):\n                for e in self.G.E[fr]:\n  \
    \                  if self.distance[fr] != INF and \\\n                      \
    \ self.distance[fr] + e.weight < self.distance[e.dst]:\n                     \
    \   self.distance[e.dst] = self.distance[fr] + e.weight\n                    \
    \    self.prev[e.dst] = fr\n                        update = True\n          \
    \              if i == self.G.V - 1:\n                            self.negativeCycle\
    \ = True\n            if update:\n                break\n\n    def getPath(self,\
    \ end: int) -> List[int]:\n        assert(not self.hasNegativeCycle())\n     \
    \   path: List[int] = [end]\n        while self.prev[end] != -1:\n           \
    \ end = self.prev[end]\n        return path[::-1]\n\n    def hasNegativeCycle(self)\
    \ -> bool:\n        return self.negativeCycle\n"
  dependsOn: []
  isVerificationFile: false
  path: python_library_typed/graph/bellman_ford.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: python_library_typed/graph/bellman_ford.py
layout: document
redirect_from:
- /library/python_library_typed/graph/bellman_ford.py
- /library/python_library_typed/graph/bellman_ford.py.html
title: python_library_typed/graph/bellman_ford.py
---
