---
data:
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import collections\n\n\nclass MaxFlow:\n    \"\"\"Calculate max flow by Dinic's\
    \ algorithm\n       complexity: O(EV^2)\n       used in GRL6A(AOJ)\n    \"\"\"\
    \n\n    class Edge:\n        \"\"\"edge in flow networks\"\"\"\n\n        def\
    \ __init__(self, to, cap, rev):\n            self.to, self.cap, self.rev = to,\
    \ cap, rev\n\n    def __init__(self, V):\n        \"\"\" V: the number of vertexes\n\
    \            E: adjacency list\n            source: start point\n            sink:\
    \ goal point\n        \"\"\"\n        self.V = V\n        self.E = [[] for _ in\
    \ range(V)]\n\n    def add_edge(self, fr, to, cap):\n        self.E[fr].append(self.Edge(to,\
    \ cap, len(self.E[to])))\n        self.E[to].append(self.Edge(fr, 0, len(self.E[fr])\
    \ - 1))\n\n    def run(self, source, sink, INF=10 ** 9):\n        \"\"\"find max-flow\"\
    \"\"\n        maxflow = 0\n        while True:\n            self.bfs(source)\n\
    \            if self.level[sink] < 0:\n                return maxflow\n      \
    \      self.itr = [0] * self.V\n            while True:\n                flow\
    \ = self.dfs(source, sink, INF)\n                if flow > 0:\n              \
    \      maxflow += flow\n                else:\n                    break\n\n \
    \   def dfs(self, vertex, sink, flow):\n        \"\"\"find augmenting path\"\"\
    \"\n        if vertex == sink:\n            return flow\n        for i in range(self.itr[vertex],\
    \ len(self.E[vertex])):\n            self.itr[vertex] = i\n            e = self.E[vertex][i]\n\
    \            if e.cap > 0 and self.level[vertex] < self.level[e.to]:\n       \
    \         d = self.dfs(e.to, sink, min(flow, e.cap))\n                if d > 0:\n\
    \                    e.cap -= d\n                    self.E[e.to][e.rev].cap +=\
    \ d\n                    return d\n        return 0\n\n    def bfs(self, start):\n\
    \        \"\"\"find shortest path from start\"\"\"\n        que = collections.deque()\n\
    \        self.level = [-1] * self.V\n        que.append(start)\n        self.level[start]\
    \ = 0\n\n        while que:\n            fr = que.popleft()\n            for e\
    \ in self.E[fr]:\n                if e.cap > 0 and self.level[e.to] < 0:\n   \
    \                 self.level[e.to] = self.level[fr] + 1\n                    que.append(e.to)\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/python/dinic_bimatch.test.py
    title: tests/python/dinic_bimatch.test.py
  - icon: ':heavy_check_mark:'
    path: tests/python/dinic_max_flow.test.py
    title: tests/python/dinic_max_flow.test.py
  isVerificationFile: false
  path: python_library/graph/dinic.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith:
  - tests/python/dinic_bimatch.test.py
  - tests/python/dinic_max_flow.test.py
documentation_of: python_library/graph/dinic.py
layout: document
redirect_from:
- /library/python_library/graph/dinic.py
- /library/python_library/graph/dinic.py.html
title: python_library/graph/dinic.py
---
