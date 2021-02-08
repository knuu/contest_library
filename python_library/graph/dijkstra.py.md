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
  code: "import heapq\n\n\nclass Edge:\n    def __init__(self, dst, weight):\n   \
    \     self.dst, self.weight = dst, weight\n\n    def __lt__(self, e):\n      \
    \  return self.weight > e.weight\n\n\nclass Graph:\n    def __init__(self, V):\n\
    \        self.V = V\n        self.E = [[] for _ in range(V)]\n\n    def add_edge(self,\
    \ src, dst, weight):\n        self.E[src].append(Edge(dst, weight))\n\n\nclass\
    \ ShortestPath:\n    \"\"\"Dijkstra's algorithm : find the shortest path from\
    \ a vertex\n       Complexity: O(E + log(V))\n       used in GRL1A(AOJ)\n    \"\
    \"\"\n\n    def __init__(self, G, INF=10**9):\n        \"\"\" V: the number of\
    \ vertexes\n            E: adjacency list (all edge in E must be 0 or positive)\n\
    \            start: start vertex\n            INF: Infinity distance\n       \
    \ \"\"\"\n        self.G, self.INF = G, INF\n\n    class Node:\n        def __init__(self,\
    \ v, cost):\n            self.v, self.cost = v, cost\n\n        def __lt__(self,\
    \ n):\n            return self.cost < n.cost\n\n    def dijkstra(self, start,\
    \ goal=None):\n        que = list()\n        self.dist = [self.INF] * self.G.V\
    \  # distance from start\n        self.prev = [-1] * self.G.V  # prev vertex of\
    \ shortest path\n        self.dist[start] = 0\n        heapq.heappush(que, self.Node(start,\
    \ 0))\n\n        while len(que) > 0:\n            n = heapq.heappop(que)\n   \
    \         if self.dist[n.v] < n.cost:\n                continue\n            if\
    \ goal is not None and n.v == goal:\n                return\n            for e\
    \ in self.G.E[n.v]:\n                if self.dist[n.v] + e.weight < self.dist[e.dst]:\n\
    \                    self.dist[e.dst] = self.dist[n.v] + e.weight\n          \
    \          heapq.heappush(que, self.Node(e.dst, self.dist[e.dst]))\n         \
    \           self.prev[e.dst] = n.v\n\n    def getPath(self, end):\n        path\
    \ = [end]\n        while self.prev[end] != -1:\n            end = self.prev[end]\n\
    \            path.append(end)\n        return path[::-1]\n\n\ndef yosupo_sp():\n\
    \    N, M, start, goal = map(int, input().split())\n    g = Graph(N)\n    for\
    \ _ in range(M):\n        a, b, c = map(int, input().split())\n        g.add_edge(a,\
    \ b, c)\n    sp = ShortestPath(g, 10**18)\n    sp.dijkstra(start, goal)\n    if\
    \ sp.dist[goal] == sp.INF:\n        print(-1)\n    else:\n        path = sp.getPath(goal)\n\
    \        print(sp.dist[goal], len(path) - 1)\n        for s, t in zip(path, path[1:]):\n\
    \            print(s, t)\n\n\nif __name__ == \"__main__\":\n    yosupo_sp()"
  dependsOn: []
  isVerificationFile: false
  path: python_library/graph/dijkstra.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: python_library/graph/dijkstra.py
layout: document
redirect_from:
- /library/python_library/graph/dijkstra.py
- /library/python_library/graph/dijkstra.py.html
title: python_library/graph/dijkstra.py
---
