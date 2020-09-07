---
data:
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "class WarshallFloyd():\n    \"\"\"Warshall-Floyd Algorithm:\n       find\
    \ the lengths of the shortest paths between all pairs of vertices\n       complexity:\
    \ O(V^3)\n       used in GRL1C(AOJ), aoj0189\n    \"\"\"\n\n    def __init__(self,\
    \ V, E, INF=10**9):\n        \"\"\" V: the number of vertexes\n            E:\
    \ adjacency list\n            INF: Infinity distance\n        \"\"\"\n       \
    \ self.V = V\n        self.E = E\n        self.warshall_floyd(INF)\n\n    def\
    \ warshall_floyd(self, INF):\n        self.distance = [[INF] * self.V for _ in\
    \ range(self.V)]\n        for i in range(self.V):\n            self.distance[i][i]\
    \ = 0\n        for fr in range(self.V):\n            for to, cost in self.E[fr]:\n\
    \                self.distance[fr][to] = cost\n        for k in range(self.V):\n\
    \            for i in range(self.V):\n                for j in range(self.V):\n\
    \                    if self.distance[i][k] != INF and \\\n                  \
    \     self.distance[k][j] != INF:\n                        self.distance[i][j]\
    \ \\\n                            = min(self.distance[i][j],\n               \
    \                   self.distance[i][k] + self.distance[k][j])\n\n    def hasNegativeCycle(self):\n\
    \        for i in range(self.V):\n            if self.distance[i][i] < 0:\n  \
    \              return True\n        else:\n            return False\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: python_library/graph/warshall_floyd.py
  requiredBy: []
  timestamp: '2020-02-16 02:53:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: python_library/graph/warshall_floyd.py
layout: document
redirect_from:
- /library/python_library/graph/warshall_floyd.py
- /library/python_library/graph/warshall_floyd.py.html
title: python_library/graph/warshall_floyd.py
---
