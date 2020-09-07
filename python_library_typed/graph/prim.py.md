---
data:
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import heapq\nfrom typing import List, TypeVar, Generic\nT = TypeVar('T',\
    \ int, float)\n\n\nclass Edge(Generic[T]):\n    def __init__(self, dst: int, weight:\
    \ T) -> None:\n        self.dst: int = dst\n        self.weight: T = weight\n\n\
    \    def __lt__(self, e: 'Edge') -> bool:\n        return self.weight > e.weight\n\
    \n\nclass Graph(Generic[T]):\n    def __init__(self, V: int) -> None:\n      \
    \  self.V: int = V\n        self.E: List[List[Edge[T]]] = [[] for _ in range(V)]\n\
    \n    def add_edge(self, src: int, dst: int, weight: T) -> None:\n        self.E[src].append(Edge(dst,\
    \ weight))\n\n\nclass Node(Generic[T]):\n    def __init__(self, v: int, cost:\
    \ T) -> None:\n        self.v: int = v\n        self.cost: T = cost\n\n    def\
    \ __lt__(self, n: 'Node') -> bool:\n        return self.cost < n.cost\n\n\nclass\
    \ MinimumSpanningTree(Generic[T]):\n    def __init__(self, G: Graph[T]) -> None:\n\
    \        self.G: Graph[T] = G\n        self.mincost: T = 0\n\n    def run(self,\
    \ start: int = 0) -> None:\n        used: List[bool] = [False] * self.G.V\n  \
    \      que: List[Node] = []\n        heapq.heappush(que, Node[T](start, 0))\n\
    \        while que:\n            node: Node = heapq.heappop(que)\n           \
    \ if used[node.v]:\n                continue\n            used[node.v] = True\n\
    \            self.mincost += node.cost\n            for edge in self.G.E[node.v]:\n\
    \                heapq.heappush(que, Node[T](edge.dst, edge.weight))\n\n    def\
    \ minCost(self) -> T:\n        return self.mincost\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: python_library_typed/graph/prim.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: python_library_typed/graph/prim.py
layout: document
redirect_from:
- /library/python_library_typed/graph/prim.py
- /library/python_library_typed/graph/prim.py.html
title: python_library_typed/graph/prim.py
---
