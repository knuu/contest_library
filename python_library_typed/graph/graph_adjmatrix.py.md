---
data:
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "from typing import List\n\n\nclass Graph_AdjMat:\n    def __init__(self,\
    \ V: int, init: int = 10**9) -> None:\n        self.V: int = V\n        self.E:\
    \ List[List[int]] = [[init] * V for _ in range(V)]\n\n    def add_edge(self, src:\
    \ int, dst: int, weight: int) -> None:\n        self.E[src][dst] = weight\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: python_library_typed/graph/graph_adjmatrix.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: python_library_typed/graph/graph_adjmatrix.py
layout: document
redirect_from:
- /library/python_library_typed/graph/graph_adjmatrix.py
- /library/python_library_typed/graph/graph_adjmatrix.py.html
title: python_library_typed/graph/graph_adjmatrix.py
---