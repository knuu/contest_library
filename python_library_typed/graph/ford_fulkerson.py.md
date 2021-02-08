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
  code: "class FordFulkerson:\n    \"\"\"Ford-Fulkerson Algorithm: find max-flow\n\
    \       complexity: O(FE) (F: max flow)\n       used in GRL6A(AOJ)\n    \"\"\"\
    \n    class edge:\n        def __init__(self, to, cap, rev):\n            self.to,\
    \ self.cap, self.rev = to, cap, rev\n\n    def __init__(self, V, E, source, sink):\n\
    \        \"\"\" V: the number of vertexes\n            E: adjacency list\n   \
    \         source: start point\n            sink: goal point\n        \"\"\"\n\
    \        self.V = V\n        self.E = [[] for _ in range(V)]\n        for fr in\
    \ range(V):\n            for to, cap in E[fr]:\n                self.E[fr].append(self.edge(to,\
    \ cap, len(self.E[to])))\n                self.E[to].append(self.edge(fr, 0, len(self.E[fr])-1))\n\
    \        self.maxflow = self.ford_fulkerson(source, sink)\n\n    def ford_fulkerson(self,\
    \ source, sink, INF=10**9):\n        \"\"\"find max-flow\"\"\"\n        maxflow\
    \ = 0\n        while True:\n            self.used = [False] * self.V\n       \
    \     flow = self.dfs(source, sink, INF)\n            if flow == 0:\n        \
    \        return maxflow\n            else:\n                maxflow += flow\n\n\
    \    def dfs(self, vertex, sink, flow):\n        \"\"\"find augmenting path\"\"\
    \"\n        if vertex == sink:\n            return flow\n        self.used[vertex]\
    \ = True\n        for e in self.E[vertex]:\n            if not self.used[e.to]\
    \ and e.cap > 0:\n                d = self.dfs(e.to, sink, min(flow, e.cap))\n\
    \                if d > 0:\n                    e.cap -= d\n                 \
    \   self.E[e.to][e.rev].cap += d\n                    return d\n        return\
    \ 0\n"
  dependsOn: []
  isVerificationFile: false
  path: python_library_typed/graph/ford_fulkerson.py
  requiredBy: []
  timestamp: '2020-02-16 02:53:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: python_library_typed/graph/ford_fulkerson.py
layout: document
redirect_from:
- /library/python_library_typed/graph/ford_fulkerson.py
- /library/python_library_typed/graph/ford_fulkerson.py.html
title: python_library_typed/graph/ford_fulkerson.py
---
