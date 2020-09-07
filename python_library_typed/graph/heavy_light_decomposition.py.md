---
data:
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "from typing import List, TypeVar, Generic, Tuple\nT = TypeVar('T', int, float)\n\
    \n\nclass Edge(Generic[T]):\n    def __init__(self, dst: int, weight: T) -> None:\n\
    \        self.dst: int = dst\n        self.weight: T = weight\n\n    def __lt__(self,\
    \ e: 'Edge') -> bool:\n        return self.weight > e.weight\n\n\nclass Graph(Generic[T]):\n\
    \    def __init__(self, V: int) -> None:\n        self.V: int = V\n        self.E:\
    \ List[List[Edge[T]]] = [[] for _ in range(V)]\n        self.edge_size: int =\
    \ 0\n\n    def add_edge(self, src: int, dst: int, weight: T) -> None:\n      \
    \  self.E[src].append(Edge(dst, weight))\n        self.edge_size += 1\n\n\nclass\
    \ HeavyLightDecomposition(Generic[T]):\n    def __init__(self, G: Graph[T]) ->\
    \ None:\n        self.G: Graph[T] = G\n        self.vid: List[int] = [0] * G.V\n\
    \        self.head: List[int] = [0] * G.V\n        self.heavy: List[int] = [-1]\
    \ * G.V\n        self.parent: List[int] = [0] * G.V\n\n    def run(self, root:\
    \ int = 0) -> None:\n        self.dfs(root)\n        self.bfs(root)\n\n    def\
    \ dfs(self, root: int = 0) -> None:\n        stack: List[Tuple[int, int, bool]]\
    \ = [(root, -1, False)]\n        sub: List[int] = [1] * self.G.V\n        max_sub:\
    \ List[Tuple[int, int]] = [(0, -1)] * self.G.V\n        while stack:\n       \
    \     v: int\n            par: int\n            flag: bool\n            v, par,\
    \ flag = stack.pop()\n            if not flag:\n                self.parent[v]\
    \ = par\n                stack.append((v, par, True))\n                stack.extend((e.dst,\
    \ v, False) for e in self.G.E[v] if e.dst != par)\n            else:\n       \
    \         if par != -1:\n                    sub[par] += sub[v]\n            \
    \        max_sub[par] = max(max_sub[par], (sub[v], v))\n                self.heavy[v]\
    \ = max_sub[v][1]\n\n    def bfs(self, root: int = 0) -> None:\n        from collections\
    \ import deque\n        k: int\n        que: deque\n        k, que = 0, deque([root])\n\
    \        while que:\n            r: int\n            v: int\n            r = v\
    \ = que.popleft()\n            while v != -1:\n                self.vid[v], self.head[v]\
    \ = k, r\n                for e in self.G.E[v]:\n                    if e.dst\
    \ != self.parent[v] and e.dst != self.heavy[v]:\n                        que.append(v)\n\
    \                k += 1\n                v = self.heavy[v]\n\n    def lca(self,\
    \ u: int, v: int) -> int:\n        while self.head[u] != self.head[v]:\n     \
    \       if self.vid[u] > self.vid[v]:\n                u, v = v, u\n         \
    \   v = self.parent[self.head[v]]\n        else:\n            if self.vid[u] >\
    \ self.vid[v]:\n                u, v = v, u\n        return u\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: python_library_typed/graph/heavy_light_decomposition.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: python_library_typed/graph/heavy_light_decomposition.py
layout: document
redirect_from:
- /library/python_library_typed/graph/heavy_light_decomposition.py
- /library/python_library_typed/graph/heavy_light_decomposition.py.html
title: python_library_typed/graph/heavy_light_decomposition.py
---
