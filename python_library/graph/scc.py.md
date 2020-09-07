---
data:
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "class StronglyConnectedComponets:\n    def __init__(self, n: int) -> None:\n\
    \        self.n = n\n        self.edges = [[] for _ in range(n)]\n        self.rev_edeges\
    \ = [[] for _ in range(n)]\n        self.vs = []\n        self.order = [0] * n\n\
    \        self.used = [False] * n\n\n    def add_edge(self, from_v: int, to_v:\
    \ int) -> None:\n        self.edges[from_v].append(to_v)\n        self.rev_edeges[to_v].append(from_v)\n\
    \n    def dfs(self, v) -> None:\n        self.used[v] = True\n        for child\
    \ in self.edges[v]:\n            if not self.used[child]:\n                self.dfs(child)\n\
    \        self.vs.append(v)\n\n    def rdfs(self, v, k) -> None:\n        self.used[v]\
    \ = True\n        self.order[v] = k\n        for child in self.rev_edeges[v]:\n\
    \            if not self.used[child]:\n                self.rdfs(child, k)\n\n\
    \    def run(self) -> int:\n        self.used = [False] * self.n\n        self.vs.clear()\n\
    \        for v in range(self.n):\n            if not self.used[v]:\n         \
    \       self.dfs(v)\n        self.used = [False] * self.n\n        k = 0\n   \
    \     for v in reversed(self.vs):\n            if not self.used[v]:\n        \
    \        self.rdfs(v, k)\n                k += 1\n        return k\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy:
  - icon: ':x:'
    path: python_library/graph/two_sat.py
    title: python_library/graph/two_sat.py
  extendedVerifiedWith:
  - icon: ':x:'
    path: tests/python/scc_aoj.test.py
    title: tests/python/scc_aoj.test.py
  - icon: ':x:'
    path: tests/python/scc_yosupo.test.py
    title: tests/python/scc_yosupo.test.py
  isVerificationFile: false
  path: python_library/graph/scc.py
  requiredBy:
  - python_library/graph/two_sat.py
  timestamp: '2020-02-16 07:49:55+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verificationStatusIcon: ':x:'
  verifiedWith:
  - tests/python/scc_aoj.test.py
  - tests/python/scc_yosupo.test.py
documentation_of: python_library/graph/scc.py
layout: document
redirect_from:
- /library/python_library/graph/scc.py
- /library/python_library/graph/scc.py.html
title: python_library/graph/scc.py
---
