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
  code: "from typing import List, TypeVar, Generic, Type, Any\n# WeightType = Union[int,\
    \ float]\nWeightType = TypeVar(\"WeightType\", int, float)\n\n\nclass Edge(Generic[WeightType]):\n\
    \    def __init__(self, src: int, dst: int) -> None:\n        self.src: int =\
    \ src\n        self.dst: int = dst\n\n\nclass WeightedEdge(Edge[WeightType]):\n\
    \    def __init__(self, src: int, dst: int, weight: WeightType) -> None:\n   \
    \     self.src: int = src\n        self.dst: int = dst\n        self.weight: WeightType\
    \ = weight\n\n\nclass ResidualEdge(Edge[WeightType]):\n    def __init__(self,\
    \ src: int, dst: int, cap: WeightType) -> None:\n        self.src: int = src\n\
    \        self.dst: int = dst\n        self.cap: WeightType = cap\n        self.rev:\
    \ int\n\n    def reverse(self) -> \"ResidualEdge\":\n        return ResidualEdge(self.dst,\
    \ self.src, 0)\n\n\n# EdgeType = Union[Edge, WeightedEdge, ResidualEdge]\nEdgeType\
    \ = TypeVar(\"EdgeType\", Edge, WeightedEdge, ResidualEdge)\n\n\nclass Graph(Generic[WeightType,\
    \ EdgeType]):\n    def __init__(self, n: int, EdgeClass: Type[EdgeType]) -> None:\n\
    \        pass\n\n    def add_edge(self, *args: Any) -> None:\n        pass\n\n\
    \    def add_undirected_edge(self, *args: Any) -> None:\n        pass\n\n\nclass\
    \ AdjacencyList(Graph[WeightType, EdgeType]):\n    def __init__(self, n: int,\
    \ EdgeClass: Type[EdgeType]) -> None:\n        self._graph: List[List[EdgeType]]\
    \ = [[] for _ in range(n)]\n        self.EdgeClass: Type[EdgeType] = EdgeClass\n\
    \n    def add_edge(self, *args: Any) -> None:\n        edge: EdgeType = self.EdgeClass(*args)\n\
    \        self._graph[edge.src].append(edge)\n\n    def add_undirected_edge(self,\
    \ *args: Any) -> None:\n        edge: EdgeType = self.EdgeClass(*args)\n     \
    \   self._graph[edge.src].append(edge)\n        edge.src, edge.dst = edge.dst,\
    \ edge.src\n        self._graph[edge.src].append(edge)\n\n    def __getitem__(self,\
    \ key: int) -> List[EdgeType]:\n        return self._graph[key]\n\n\nclass ResidualGraph(AdjacencyList[WeightType,\
    \ ResidualEdge]):\n    def __init__(self, n: int) -> None:\n        super().__init__(n,\
    \ ResidualEdge)\n\n    def add_edge(self, *args: Any) -> None:\n        edge:\
    \ ResidualEdge = self.EdgeClass(*args)\n        edge.rev = len(self._graph[edge.dst])\n\
    \        self._graph[edge.src].append(edge)\n        rev: ResidualEdge = edge.reverse()\n\
    \        rev.rev = len(self._graph[rev.dst]) - 1\n        self._graph[edge.src].append(rev)\n"
  dependsOn: []
  isVerificationFile: false
  path: python_library_typed/graph/graph.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: python_library_typed/graph/graph.py
layout: document
redirect_from:
- /library/python_library_typed/graph/graph.py
- /library/python_library_typed/graph/graph.py.html
title: python_library_typed/graph/graph.py
---
