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
  code: "from typing import List, TypeVar, Generic, Tuple\nT = TypeVar('T', int, float)\n\
    \n\nclass Edge(Generic[T]):\n    def __init__(self, dst: int, weight: T) -> None:\n\
    \        self.dst: int = dst\n        self.weight: T = weight\n\n    def __lt__(self,\
    \ e: 'Edge') -> bool:\n        return self.weight > e.weight\n\n\nclass Graph(Generic[T]):\n\
    \    def __init__(self, V: int) -> None:\n        self.V: int = V\n        self.E:\
    \ List[List[Edge[T]]] = [[] for _ in range(V)]\n        self.edge_size: int =\
    \ 0\n\n    def add_edge(self, src: int, dst: int, weight: T) -> None:\n      \
    \  self.E[src].append(Edge(dst, weight))\n        self.edge_size += 1\n\n\nclass\
    \ UnionFindTree:\n    def __init__(self, N: int) -> None:\n        self.par: List[int]\
    \ = list(range(N))  # parent\n        self.rank: List[int] = [0] * N  # depth\
    \ of tree\n\n    def find(self, x: int) -> int:\n        if self.par[x] == x:\n\
    \            return x\n        else:\n            self.par[x] = self.find(self.par[x])\n\
    \            return self.par[x]\n\n    def unite(self, x: int, y: int) -> None:\n\
    \        x, y = self.find(x), self.find(y)\n        if x == y:\n            return\n\
    \        if self.rank[x] < self.rank[y]:\n            self.par[x] = y\n      \
    \  else:\n            self.par[y] = x\n            if self.rank[x] == self.rank[y]:\n\
    \                self.rank[x] += 1\n\n    def same(self, x: int, y: int) -> bool:\n\
    \        return self.find(x) == self.find(y)\n\n\nclass MinimumSpanningTree(Generic[T]):\n\
    \    def __init__(self, G: Graph) -> None:\n        self.G = G\n\n    def run(self)\
    \ -> None:\n        edges: List[Tuple[T, int, int]] = []\n        for v1 in range(self.G.V):\n\
    \            for e in self.G.E[v1]:\n                v2: int = e.dst\n       \
    \         if v1 < v2:\n                    edges.append((e.weight, v1, v2))\n\
    \        edges.sort(reverse=True)\n\n        self.mincost: T = 0\n        self.minSpanningTree:\
    \ Graph[T] = Graph(self.G.V)\n        uf: UnionFindTree = UnionFindTree(self.G.V)\n\
    \n        while self.minSpanningTree.edge_size < self.G.V - 1:\n            cost,\
    \ v1, v2 = edges.pop()\n            if not uf.same(v1, v2):\n                self.mincost\
    \ += cost\n                uf.unite(v1, v2)\n                self.minSpanningTree.add_edge(v1,\
    \ v2, cost)\n                self.minSpanningTree.add_edge(v2, v1, cost)\n\n \
    \   def minCost(self) -> T:\n        return self.mincost\n\n    def getMinSpanningTree(self)\
    \ -> Graph[T]:\n        return self.minSpanningTree\n"
  dependsOn: []
  isVerificationFile: false
  path: python_library_typed/graph/kruskal.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: python_library_typed/graph/kruskal.py
layout: document
redirect_from:
- /library/python_library_typed/graph/kruskal.py
- /library/python_library_typed/graph/kruskal.py.html
title: python_library_typed/graph/kruskal.py
---
