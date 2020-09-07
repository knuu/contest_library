---
data:
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import heapq\n\n\nclass MinimumSpanningTree:\n    \"\"\" Prim's algorithm:\
    \ find minimum spanning tree\n        Complexity: O(E log(V))\n        used in\
    \ GRL2A(AOJ)\n    \"\"\"\n\n    def __init__(self, V, E, start=0, INF=10**9):\n\
    \        \"\"\" V: the number of vertexes\n            E: adjacency list (undirected\
    \ graph)\n            start: start vertex\n            INF: Infinity cost\n  \
    \      \"\"\"\n        self.prim(V, E, start, INF)\n\n    def prim(self, V, E,\
    \ start=0, INF=10**9):\n        used = [False] * V\n        self.mincost = 0\n\
    \        que = []\n        heapq.heappush(que, (0, 0))\n        while len(que)\
    \ > 0:\n            cost, v = heapq.heappop(que)\n            if used[v]:\n  \
    \              continue\n            used[v] = True\n            self.mincost\
    \ += cost\n            for to, c in E[v]:\n                heapq.heappush(que,\
    \ (c, to))\n\n    def minCost(self):\n        return self.mincost\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: python_library/graph/prim.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: python_library/graph/prim.py
layout: document
redirect_from:
- /library/python_library/graph/prim.py
- /library/python_library/graph/prim.py.html
title: python_library/graph/prim.py
---
