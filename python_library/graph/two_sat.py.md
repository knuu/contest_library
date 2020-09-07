---
data:
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "from python_library.graph.scc import StronglyConnectedComponets\n\n\nclass\
    \ TwoSat(StronglyConnectedComponets):\n    def __init__(self, num_var: int) ->\
    \ None:\n        super().__init__(2 * num_var + 1)\n        self.num_var = num_var\n\
    \        self.ans = []\n\n    def add_constraint(self, a: int, b: int) -> None:\n\
    \        super().add_edge(self._neg(a), self._pos(b))\n        super().add_edge(self._neg(b),\
    \ self._pos(a))\n\n    def _pos(self, v: int) -> int:\n        return v if v >\
    \ 0 else self.num_var - v\n\n    def _neg(self, v: int) -> int:\n        return\
    \ self.num_var + v if v > 0 else -v\n\n    def run(self) -> bool:\n        super().run()\n\
    \        self.ans.clear()\n        for i in range(self.num_var):\n           \
    \ if self.order[i + 1] == self.order[i + self.num_var + 1]:\n                return\
    \ False\n            self.ans.append(self.order[i + 1] > self.order[i + self.num_var\
    \ + 1])\n        return True\n"
  dependsOn:
  - python_library/graph/scc.py
  extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: python_library/graph/scc.py
    title: python_library/graph/scc.py
  extendedRequiredBy: []
  extendedVerifiedWith:
  - icon: ':x:'
    path: tests/python/two_sat.test.py
    title: tests/python/two_sat.test.py
  isVerificationFile: false
  path: python_library/graph/two_sat.py
  requiredBy: []
  timestamp: '2020-09-08 06:49:11+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verificationStatusIcon: ':x:'
  verifiedWith:
  - tests/python/two_sat.test.py
documentation_of: python_library/graph/two_sat.py
layout: document
redirect_from:
- /library/python_library/graph/two_sat.py
- /library/python_library/graph/two_sat.py.html
title: python_library/graph/two_sat.py
---
