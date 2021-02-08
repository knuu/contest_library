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
    \ int, dst: int, weight: T) -> None:\n        self.E[src].append(Edge(dst, weight))\n"
  dependsOn: []
  isVerificationFile: false
  path: python_library_typed/graph/graph_adjlist.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: python_library_typed/graph/graph_adjlist.py
layout: document
redirect_from:
- /library/python_library_typed/graph/graph_adjlist.py
- /library/python_library_typed/graph/graph_adjlist.py.html
title: python_library_typed/graph/graph_adjlist.py
---
