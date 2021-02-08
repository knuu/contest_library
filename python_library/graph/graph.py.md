---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: python_library/graph/tree_diameter.py
    title: python_library/graph/tree_diameter.py
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
  code: "class Edge:\n    def __init__(self, dst, weight):\n        self.dst, self.weight\
    \ = dst, weight\n\n    def __lt__(self, e):\n        return self.weight > e.weight\n\
    \n\nclass Graph:\n    def __init__(self, V):\n        self.V = V\n        self.E\
    \ = [[] for _ in range(V)]\n\n    def add_edge(self, src, dst, weight):\n    \
    \    self.E[src].append(Edge(dst, weight))\n"
  dependsOn: []
  isVerificationFile: false
  path: python_library/graph/graph.py
  requiredBy:
  - python_library/graph/tree_diameter.py
  timestamp: '2020-02-16 02:53:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: python_library/graph/graph.py
layout: document
redirect_from:
- /library/python_library/graph/graph.py
- /library/python_library/graph/graph.py.html
title: python_library/graph/graph.py
---
