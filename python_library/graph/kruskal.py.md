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
  code: "class MinimumSpanningTree:\n    \"\"\" Kruskal's algorithm: find minimum\
    \ spanning tree\n        Complexity: O(E log(V))\n        used in GRL2A(AOJ)\n\
    \    \"\"\"\n\n    def __init__(self, V, E, start=0, INF=10**9):\n        \"\"\
    \" V: the number of vertexes\n            E: adjacency list (undirected graph)\n\
    \        \"\"\"\n        self.kruskal(V, E)\n\n    def kruskal(self, V, E):\n\
    \        edges = []\n        for v1 in range(V):\n            for v2, cost in\
    \ E[v1]:\n                if v1 < v2:\n                    edges.append((cost,\
    \ v1, v2))\n        edges.sort(reverse=True)\n        self.mincost = 0\n     \
    \   self.minSpanningTree = []\n        uf = UnionFindTree(V)\n        while len(self.minSpanningTree)\
    \ < V-1:\n            cost, v1, v2 = edges.pop()\n            if uf.same(v1, v2)\
    \ == False:\n                self.mincost += cost\n                uf.unite(v1,\
    \ v2)\n                self.minSpanningTree.append((v1, v2, cost))\n\n    def\
    \ minCost(self):\n        return self.mincost\n\n    def getMinSpanningTree(self):\n\
    \        return sorted(self.minSpanningTree)\n"
  dependsOn: []
  isVerificationFile: false
  path: python_library/graph/kruskal.py
  requiredBy: []
  timestamp: '2020-02-16 02:53:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: python_library/graph/kruskal.py
layout: document
redirect_from:
- /library/python_library/graph/kruskal.py
- /library/python_library/graph/kruskal.py.html
title: python_library/graph/kruskal.py
---
