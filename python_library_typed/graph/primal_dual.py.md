---
data:
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import heapq\n\n\nclass MinCostFlow:\n    class Edge:\n        def __init__(self,\
    \ to, cap, rev, cost):\n            self.to, self.cap, self.rev, self.cost = to,\
    \ cap, rev, cost\n\n    def __init__(self, V):\n        self.V = V\n        self.E\
    \ = [[] for _ in range(V)]\n\n    def add_edge(self, fr, to, cap, cost):\n   \
    \     self.E[fr].append(self.Edge(to, cap, len(self.E[to]), cost))\n        self.E[to].append(self.Edge(fr,\
    \ 0, len(self.E[fr])-1, -cost))\n\n    def run(self, source, sink, f, INF=10**5):\n\
    \        res = 0\n        h, prevv, preve = [0] * self.V, [0] * self.V, [0] *\
    \ self.V\n        while (f > 0):\n            pque = []\n            dist = [INF]\
    \ * self.V\n            dist[source] = 0\n            heapq.heappush(pque, (0,\
    \ source))\n            while pque:\n                cost, v = heapq.heappop(pque)\n\
    \                cost = -cost\n                if dist[v] < cost:\n          \
    \          continue\n                for i, e in enumerate(self.E[v]):\n     \
    \               if e.cap > 0 and dist[v] - h[e.to] < dist[e.to] - e.cost - h[v]:\n\
    \                        dist[e.to] = dist[v] + e.cost + h[v] - h[e.to]\n    \
    \                    prevv[e.to], preve[e.to] = v, i\n                       \
    \ heapq.heappush(pque, (-dist[e.to], e.to))\n            if dist[sink] == INF:\n\
    \                return -1\n            for v in range(self.V):\n            \
    \    h[v] += dist[v]\n\n            d, v = f, sink\n            while v != source:\n\
    \                d = min(d, self.E[prevv[v]][preve[v]].cap)\n                v\
    \ = prevv[v]\n            f -= d\n            res += d * h[sink]\n           \
    \ v = sink\n            while v != source:\n                self.E[prevv[v]][preve[v]].cap\
    \ -= d\n                self.E[v][self.E[prevv[v]][preve[v]].rev].cap += d\n \
    \               v = prevv[v]\n        return res\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: python_library_typed/graph/primal_dual.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: python_library_typed/graph/primal_dual.py
layout: document
redirect_from:
- /library/python_library_typed/graph/primal_dual.py
- /library/python_library_typed/graph/primal_dual.py.html
title: python_library_typed/graph/primal_dual.py
---
