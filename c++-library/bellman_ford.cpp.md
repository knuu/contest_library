---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_B
  bundledCode: "#line 1 \"c++-library/bellman_ford.cpp\"\n#include <algorithm>\n#include\
    \ <iostream>\n#include <vector>\n\n// graph by adjacency list\ntemplate <typename\
    \ T>\nstruct Edge {\n  int src, dst;\n  T weight;\n  Edge(const int src, const\
    \ int dst, const T weight)\n      : src(src), dst(dst), weight(weight) {}\n  Edge(const\
    \ int dst, const T weight) : src(-1), dst(dst), weight(weight) {}\n  bool operator<(const\
    \ Edge<T> &e) const { return weight > e.weight; }\n};\n\ntemplate <typename T>\n\
    struct Graph {\n  int V;\n  std::vector<std::vector<Edge<T>>> E;\n  Graph(const\
    \ int V) : V(V) { E.resize(V); }\n  void add_edge(const int src, const int dst,\
    \ const T weight) {\n    E[src].emplace_back(src, dst, weight);\n  }\n};\n\ntemplate\
    \ <typename T>\nstruct ShortestPath {\n  Graph<T> g;\n  T inf;\n  std::vector<T>\
    \ dist;\n  std::vector<int> prev;\n  bool has_negative_cycle;\n\n  ShortestPath(const\
    \ Graph<T> g, const T inf = 1 << 30)\n      : g(g), inf(inf), dist(g.V), prev(g.V)\
    \ {}\n\n  void run(int start) {\n    std::fill(dist.begin(), dist.end(), inf);\n\
    \    dist[start] = 0;\n    prev[start] = -1;\n    has_negative_cycle = false;\n\
    \    for (int cnt = 0; cnt < g.V; cnt++) {\n      bool update = false;\n     \
    \ for (int i = 0; i < g.V; i++) {\n        for (Edge<T> e : g.E[i]) {\n      \
    \    if (dist[i] != inf && dist[i] + e.weight < dist[e.dst]) {\n            dist[e.dst]\
    \ = dist[i] + e.weight;\n            prev[e.dst] = i;\n            update = true;\n\
    \            if (cnt == g.V - 1) has_negative_cycle = true;\n          }\n   \
    \     }\n      }\n      if (!update) break;\n    }\n  }\n\n  std::vector<int>\
    \ build_path(const int goal) const {\n    std::vector<int> path;\n    for (int\
    \ v = goal; v != -1; v = prev[v]) {\n      path.emplace_back(v);\n    }\n    std::reverse(path.begin(),\
    \ path.end());\n    return path;\n  }\n};\n\nvoid aoj() {\n  // https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_B\n\
    \  int V, E, r;\n  std::cin >> V >> E >> r;\n  Graph<int> g(V);\n  for (int i\
    \ = 0; i < E; i++) {\n    int s, t, d;\n    std::cin >> s >> t >> d;\n    g.add_edge(s,\
    \ t, d);\n  }\n  ShortestPath<int> sp(g);\n  sp.run(r);\n  if (sp.has_negative_cycle)\
    \ {\n    std::cout << \"NEGATIVE CYCLE\" << std::endl;\n  } else {\n    for (int\
    \ i = 0; i < g.V; i++) {\n      if (sp.dist[i] == sp.inf) {\n        std::cout\
    \ << \"INF\" << std::endl;\n      } else {\n        std::cout << sp.dist[i] <<\
    \ std::endl;\n      }\n    }\n  }\n}\n\nint main() {\n  std::cin.tie(0);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  aoj();\n  return 0;\n}\n"
  code: "#include <algorithm>\n#include <iostream>\n#include <vector>\n\n// graph\
    \ by adjacency list\ntemplate <typename T>\nstruct Edge {\n  int src, dst;\n \
    \ T weight;\n  Edge(const int src, const int dst, const T weight)\n      : src(src),\
    \ dst(dst), weight(weight) {}\n  Edge(const int dst, const T weight) : src(-1),\
    \ dst(dst), weight(weight) {}\n  bool operator<(const Edge<T> &e) const { return\
    \ weight > e.weight; }\n};\n\ntemplate <typename T>\nstruct Graph {\n  int V;\n\
    \  std::vector<std::vector<Edge<T>>> E;\n  Graph(const int V) : V(V) { E.resize(V);\
    \ }\n  void add_edge(const int src, const int dst, const T weight) {\n    E[src].emplace_back(src,\
    \ dst, weight);\n  }\n};\n\ntemplate <typename T>\nstruct ShortestPath {\n  Graph<T>\
    \ g;\n  T inf;\n  std::vector<T> dist;\n  std::vector<int> prev;\n  bool has_negative_cycle;\n\
    \n  ShortestPath(const Graph<T> g, const T inf = 1 << 30)\n      : g(g), inf(inf),\
    \ dist(g.V), prev(g.V) {}\n\n  void run(int start) {\n    std::fill(dist.begin(),\
    \ dist.end(), inf);\n    dist[start] = 0;\n    prev[start] = -1;\n    has_negative_cycle\
    \ = false;\n    for (int cnt = 0; cnt < g.V; cnt++) {\n      bool update = false;\n\
    \      for (int i = 0; i < g.V; i++) {\n        for (Edge<T> e : g.E[i]) {\n \
    \         if (dist[i] != inf && dist[i] + e.weight < dist[e.dst]) {\n        \
    \    dist[e.dst] = dist[i] + e.weight;\n            prev[e.dst] = i;\n       \
    \     update = true;\n            if (cnt == g.V - 1) has_negative_cycle = true;\n\
    \          }\n        }\n      }\n      if (!update) break;\n    }\n  }\n\n  std::vector<int>\
    \ build_path(const int goal) const {\n    std::vector<int> path;\n    for (int\
    \ v = goal; v != -1; v = prev[v]) {\n      path.emplace_back(v);\n    }\n    std::reverse(path.begin(),\
    \ path.end());\n    return path;\n  }\n};\n\nvoid aoj() {\n  // https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_B\n\
    \  int V, E, r;\n  std::cin >> V >> E >> r;\n  Graph<int> g(V);\n  for (int i\
    \ = 0; i < E; i++) {\n    int s, t, d;\n    std::cin >> s >> t >> d;\n    g.add_edge(s,\
    \ t, d);\n  }\n  ShortestPath<int> sp(g);\n  sp.run(r);\n  if (sp.has_negative_cycle)\
    \ {\n    std::cout << \"NEGATIVE CYCLE\" << std::endl;\n  } else {\n    for (int\
    \ i = 0; i < g.V; i++) {\n      if (sp.dist[i] == sp.inf) {\n        std::cout\
    \ << \"INF\" << std::endl;\n      } else {\n        std::cout << sp.dist[i] <<\
    \ std::endl;\n      }\n    }\n  }\n}\n\nint main() {\n  std::cin.tie(0);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  aoj();\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: c++-library/bellman_ford.cpp
  requiredBy: []
  timestamp: '2020-01-21 04:11:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: c++-library/bellman_ford.cpp
layout: document
redirect_from:
- /library/c++-library/bellman_ford.cpp
- /library/c++-library/bellman_ford.cpp.html
title: c++-library/bellman_ford.cpp
---
