---
data:
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "class Edge:\n    def __init__(self, dst, weight):\n        self.dst, self.weight\
    \ = dst, weight\n\n    def __lt__(self, e):\n        return self.weight > e.weight\n\
    \n\nclass Graph:\n    def __init__(self, V):\n        self.V = V\n        self.E\
    \ = [[] for _ in range(V)]\n\n    def add_edge(self, src, dst, weight):\n    \
    \    self.E[src].append(Edge(dst, weight))\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy:
  - icon: ':x:'
    path: python_library/graph/tree_diameter.py
    title: python_library/graph/tree_diameter.py
  extendedVerifiedWith:
  - icon: ':x:'
    path: tests/python/tree_diameter.test.py
    title: tests/python/tree_diameter.test.py
  - icon: ':heavy_check_mark:'
    path: tests/python/hld_lca.test.py
    title: tests/python/hld_lca.test.py
  isVerificationFile: false
  path: python_library/graph/graph.py
  requiredBy:
  - python_library/graph/tree_diameter.py
  timestamp: '2020-02-16 02:53:38+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verificationStatusIcon: ':question:'
  verifiedWith:
  - tests/python/tree_diameter.test.py
  - tests/python/hld_lca.test.py
documentation_of: python_library/graph/graph.py
layout: document
redirect_from:
- /library/python_library/graph/graph.py
- /library/python_library/graph/graph.py.html
title: python_library/graph/graph.py
---
