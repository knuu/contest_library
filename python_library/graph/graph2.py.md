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
  code: "class Edge:\n    def __init__(self, src, dst):\n        self.src, self.dst\
    \ = src, dst\n\n\nclass WeightedEdge(Edge):\n    def __init__(self, src, dst,\
    \ weight):\n        self.src, self.dst, self.weight = src, dst, weight\n\n\nclass\
    \ ResidualEdge(Edge):\n    def __init__(self, src, dst, cap):\n        self.src,\
    \ self.dst, self.cap = src, dst, cap\n\n    def reverse(self):\n        return\
    \ ResidualEdge(self.dst, self.src, 0)\n\n\nclass Graph:\n    def __init__(self,\
    \ n, EdgeClass):\n        pass\n\n    def add_edge(self, *args):\n        pass\n\
    \n    def add_undirected_edge(self, *args):\n        pass\n\n\nclass AdjacencyList(Graph):\n\
    \    def __init__(self, n, EdgeClass):\n        self._graph = [[] for _ in range(n)]\n\
    \        self.EdgeClass = EdgeClass\n\n    def add_edge(self, *args):\n      \
    \  edge = self.EdgeClass(*args)\n        self._graph[edge.src].append(edge)\n\n\
    \    def add_undirected_edge(self, *args):\n        edge = self.EdgeClass(*args)\n\
    \        self._graph[edge.src].append(edge)\n        edge.src, edge.dst = edge.dst,\
    \ edge.src\n        self._graph[edge.src].append(edge)\n\n    def __getitem__(self,\
    \ key):\n        return self._graph[key]\n\n\nclass ResidualGraph(AdjacencyList):\n\
    \    def __init__(self, n):\n        super().__init__(n, ResidualEdge)\n\n   \
    \ def add_edge(self, *args):\n        edge = self.EdgeClass(*args)\n        edge.rev\
    \ = len(self._graph[edge.dst])\n        self._graph[edge.src].append(edge)\n \
    \       rev = edge.reverse()\n        rev.rev = len(self._graph[rev.dst]) - 1\n\
    \        self._graph[edge.src].append(rev)\n"
  dependsOn: []
  isVerificationFile: false
  path: python_library/graph/graph2.py
  requiredBy: []
  timestamp: '2020-02-16 02:53:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: python_library/graph/graph2.py
layout: document
redirect_from:
- /library/python_library/graph/graph2.py
- /library/python_library/graph/graph2.py.html
title: python_library/graph/graph2.py
---
