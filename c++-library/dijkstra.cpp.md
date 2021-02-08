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
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A
  bundledCode: "#line 1 \"c++-library/dijkstra.cpp\"\n#include <algorithm>\n#include\
    \ <iostream>\n#include <numeric>\n#include <queue>\n#include <vector>\n\n// graph\
    \ by adjacency list\ntemplate <typename T>\nstruct Edge {\n  int src, dst;\n \
    \ T weight;\n  Edge(const int src, const int dst, const T weight)\n      : src(src),\
    \ dst(dst), weight(weight) {}\n  Edge(const int dst, const T weight) : src(-1),\
    \ dst(dst), weight(weight) {}\n  bool operator<(const Edge<T> &e) const { return\
    \ weight > e.weight; }\n};\n\ntemplate <typename T>\nstruct Graph {\n  int V;\n\
    \  std::vector<std::vector<Edge<T>>> E;\n  Graph(const int V) : V(V) { E.resize(V);\
    \ }\n  void add_edge(const int src, const int dst, const T weight) {\n    E[src].emplace_back(src,\
    \ dst, weight);\n  }\n};\n\ntemplate <typename T>\nstruct Node {\n  int v;\n \
    \ T dist;\n  Node(int v, T dist) : v(v), dist(dist){};\n  bool operator<(const\
    \ Node<T> &n) const {\n    return dist > n.dist;  // reverse\n  }\n};\n\ntemplate\
    \ <typename T>\nstruct ShortestPath {\n  Graph<T> g;\n  std::vector<T> dist;\n\
    \  std::vector<int> prev;\n  T inf;\n\n  ShortestPath(const Graph<T> g, T inf\
    \ = std::numeric_limits<T>::max())\n      : g(g), dist(g.V), prev(g.V), inf(inf)\
    \ {}\n\n  void run(int start, int goal = -1) {\n    std::priority_queue<Node<T>>\
    \ que;\n    std::fill(dist.begin(), dist.end(), inf);\n\n    dist[start] = 0;\n\
    \    que.emplace(start, 0);\n    prev[start] = -1;\n\n    while (!que.empty())\
    \ {\n      Node<T> n = que.top();\n      que.pop();\n      int v = n.v;\n    \
    \  if (v == goal) return;\n      T cost = n.dist;\n      if (dist[v] < cost) continue;\n\
    \      for (Edge<T> e : g.E[v]) {\n        if (dist[v] < dist[e.dst] - e.weight)\
    \ {\n          dist[e.dst] = dist[v] + e.weight;\n          prev[e.dst] = v;\n\
    \          que.emplace(e.dst, dist[e.dst]);\n        }\n      }\n    }\n  }\n\n\
    \  std::vector<int> build_path(int goal) {\n    std::vector<int> path;\n    for\
    \ (int v = goal; v != -1; v = prev[v]) {\n      path.emplace_back(v);\n    }\n\
    \    std::reverse(path.begin(), path.end());\n    return path;\n  }\n};\n\nvoid\
    \ aoj() {\n  // https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A\n\
    \n  int V, E, r;\n  std::cin >> V >> E >> r;\n  Graph<int> g(V);\n  for (int i\
    \ = 0; i < E; i++) {\n    int s, t, d;\n    std::cin >> s >> t >> d;\n    g.add_edge(s,\
    \ t, d);\n  }\n  ShortestPath<int> sp(g);\n  sp.run(r);\n  for (int i = 0; i <\
    \ g.V; i++) {\n    if (sp.dist[i] == sp.inf) {\n      std::cout << \"INF\" <<\
    \ std::endl;\n    } else {\n      std::cout << sp.dist[i] << std::endl;\n    }\n\
    \  }\n}\n\nint main() {\n  std::cin.tie(0);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  aoj();\n  return 0;\n}\n"
  code: "#include <algorithm>\n#include <iostream>\n#include <numeric>\n#include <queue>\n\
    #include <vector>\n\n// graph by adjacency list\ntemplate <typename T>\nstruct\
    \ Edge {\n  int src, dst;\n  T weight;\n  Edge(const int src, const int dst, const\
    \ T weight)\n      : src(src), dst(dst), weight(weight) {}\n  Edge(const int dst,\
    \ const T weight) : src(-1), dst(dst), weight(weight) {}\n  bool operator<(const\
    \ Edge<T> &e) const { return weight > e.weight; }\n};\n\ntemplate <typename T>\n\
    struct Graph {\n  int V;\n  std::vector<std::vector<Edge<T>>> E;\n  Graph(const\
    \ int V) : V(V) { E.resize(V); }\n  void add_edge(const int src, const int dst,\
    \ const T weight) {\n    E[src].emplace_back(src, dst, weight);\n  }\n};\n\ntemplate\
    \ <typename T>\nstruct Node {\n  int v;\n  T dist;\n  Node(int v, T dist) : v(v),\
    \ dist(dist){};\n  bool operator<(const Node<T> &n) const {\n    return dist >\
    \ n.dist;  // reverse\n  }\n};\n\ntemplate <typename T>\nstruct ShortestPath {\n\
    \  Graph<T> g;\n  std::vector<T> dist;\n  std::vector<int> prev;\n  T inf;\n\n\
    \  ShortestPath(const Graph<T> g, T inf = std::numeric_limits<T>::max())\n   \
    \   : g(g), dist(g.V), prev(g.V), inf(inf) {}\n\n  void run(int start, int goal\
    \ = -1) {\n    std::priority_queue<Node<T>> que;\n    std::fill(dist.begin(),\
    \ dist.end(), inf);\n\n    dist[start] = 0;\n    que.emplace(start, 0);\n    prev[start]\
    \ = -1;\n\n    while (!que.empty()) {\n      Node<T> n = que.top();\n      que.pop();\n\
    \      int v = n.v;\n      if (v == goal) return;\n      T cost = n.dist;\n  \
    \    if (dist[v] < cost) continue;\n      for (Edge<T> e : g.E[v]) {\n       \
    \ if (dist[v] < dist[e.dst] - e.weight) {\n          dist[e.dst] = dist[v] + e.weight;\n\
    \          prev[e.dst] = v;\n          que.emplace(e.dst, dist[e.dst]);\n    \
    \    }\n      }\n    }\n  }\n\n  std::vector<int> build_path(int goal) {\n   \
    \ std::vector<int> path;\n    for (int v = goal; v != -1; v = prev[v]) {\n   \
    \   path.emplace_back(v);\n    }\n    std::reverse(path.begin(), path.end());\n\
    \    return path;\n  }\n};\n\nvoid aoj() {\n  // https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A\n\
    \n  int V, E, r;\n  std::cin >> V >> E >> r;\n  Graph<int> g(V);\n  for (int i\
    \ = 0; i < E; i++) {\n    int s, t, d;\n    std::cin >> s >> t >> d;\n    g.add_edge(s,\
    \ t, d);\n  }\n  ShortestPath<int> sp(g);\n  sp.run(r);\n  for (int i = 0; i <\
    \ g.V; i++) {\n    if (sp.dist[i] == sp.inf) {\n      std::cout << \"INF\" <<\
    \ std::endl;\n    } else {\n      std::cout << sp.dist[i] << std::endl;\n    }\n\
    \  }\n}\n\nint main() {\n  std::cin.tie(0);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  aoj();\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: c++-library/dijkstra.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:27:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: c++-library/dijkstra.cpp
layout: document
redirect_from:
- /library/c++-library/dijkstra.cpp
- /library/c++-library/dijkstra.cpp.html
title: c++-library/dijkstra.cpp
---
