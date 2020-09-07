---
data:
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "class BellmanFord:\n    \"\"\"Bellman-Ford algorithm : find the shortest\
    \ path from a vertex\n       Complexity: O(VE)\n       used in GRL1A(AOJ)\n  \
    \  \"\"\"\n\n    def __init__(self, V, E, start, INF=10**9):\n        \"\"\" V:\
    \ the number of vertexes\n            E: adjacency list\n            start: start\
    \ vertex\n            INF: Infinity distance\n        \"\"\"\n        self.V =\
    \ V\n        self.E = E\n        self.bellman_ford(start, INF)\n\n    def bellman_ford(self,\
    \ start, INF):\n        self.distance = [INF] * self.V  # distance from start\n\
    \        self.prev = [-1] * self.V  # prev vertex of shortest path\n        self.distance[start]\
    \ = 0\n        self.negativeCycle = False\n\n        for i in range(self.V):\n\
    \            update = False\n            for fr in range(self.V):\n          \
    \      for to, cost in self.E[fr]:\n                    if self.distance[fr] !=\
    \ INF and \\\n                       self.distance[fr] + cost < self.distance[to]:\n\
    \                        self.distance[to] = self.distance[fr] + cost\n      \
    \                  self.prev[to] = fr\n                        update = True\n\
    \                        if i == self.V - 1:\n                            self.negativeCycle\
    \ = True\n            if update:\n                break\n\n    def getPath(self,\
    \ end):\n        assert self.hasNegativeCycle() == False\n        path = [end]\n\
    \        while self.prev[end] != -1:\n            end = self.prev[end]\n     \
    \   return path[::-1]\n\n    def hasNegativeCycle(self):\n        return self.negativeCycle\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: python_library/graph/bellman_ford.py
  requiredBy: []
  timestamp: '2020-02-16 02:53:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: python_library/graph/bellman_ford.py
layout: document
redirect_from:
- /library/python_library/graph/bellman_ford.py
- /library/python_library/graph/bellman_ford.py.html
title: python_library/graph/bellman_ford.py
---
