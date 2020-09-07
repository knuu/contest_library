---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"c++-library/warshall_floyd.cpp\"\n#include <algorithm>\n\
    #include <iostream>\n#include <numeric>\n#include <vector>\n\n// graph by adjacency\
    \ matrix\ntemplate <typename T>\nstruct Graph {\n  int V;\n  std::vector<std::vector<T>>\
    \ adj;\n  T inf;\n\n  Graph(const int V, const T inf = std::numeric_limits<T>::max())\n\
    \      : V(V), adj(V, std::vector<T>(V, inf)), inf(inf) {\n    for (int i = 0;\
    \ i < V; i++) adj[i][i] = 0;\n  }\n\n  void add_edge(const int src, const int\
    \ dst, const T weight) {\n    adj[src][dst] = weight;\n  }\n};\n\ntemplate <typename\
    \ T>\nstruct AllPairsShortestPath {\n  Graph<T> g;\n  std::vector<std::vector<T>>\
    \ dist;\n  T inf;\n\n  AllPairsShortestPath(const Graph<T> &g, T inf = std::numeric_limits<T>::max())\n\
    \      : g(g), dist(g.V, std::vector<T>(g.V)), inf(inf) {\n    for (int i = 0;\
    \ i < g.V; i++) {\n      for (int j = 0; j < g.V; j++) dist[i][j] = g.adj[i][j];\n\
    \    }\n  }\n\n  void run() {\n    for (int k = 0; k < g.V; k++) {\n      for\
    \ (int i = 0; i < g.V; i++) {\n        for (int j = 0; j < g.V; j++) {\n     \
    \     if (dist[i][k] != inf and dist[k][j] != inf) {\n            dist[i][j] =\
    \ std::min(dist[i][j], dist[i][k] + dist[k][j]);\n          }\n        }\n   \
    \   }\n    }\n  }\n\n  bool has_negative_loop() const {\n    for (int i = 0; i\
    \ < g.V; i++) {\n      if (dist[i][i] < 0) return true;\n    }\n    return false;\n\
    \  }\n};\n\nvoid aoj() {\n  // https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_C\n\
    \  int V, E;\n  std::cin >> V >> E;\n  Graph<long long> g(V);\n  for (int i =\
    \ 0; i < E; i++) {\n    int s, t, d;\n    std::cin >> s >> t >> d;\n    g.add_edge(s,\
    \ t, d);\n  }\n  AllPairsShortestPath<long long> apsp(g);\n  apsp.run();\n  if\
    \ (apsp.has_negative_loop()) {\n    std::cout << \"NEGATIVE CYCLE\" << std::endl;\n\
    \  } else {\n    for (int i = 0; i < g.V; i++) {\n      for (int j = 0; j < g.V;\
    \ j++) {\n        if (apsp.dist[i][j] == apsp.inf) {\n          std::cout << \"\
    INF\" << (j == g.V - 1 ? '\\n' : ' ');\n        } else {\n          std::cout\
    \ << apsp.dist[i][j] << (j == g.V - 1 ? '\\n' : ' ');\n        }\n      }\n  \
    \  }\n  }\n}\n\nint main() {\n  std::cin.tie(0);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  aoj();\n  return 0;\n}\n"
  code: "#include <algorithm>\n#include <iostream>\n#include <numeric>\n#include <vector>\n\
    \n// graph by adjacency matrix\ntemplate <typename T>\nstruct Graph {\n  int V;\n\
    \  std::vector<std::vector<T>> adj;\n  T inf;\n\n  Graph(const int V, const T\
    \ inf = std::numeric_limits<T>::max())\n      : V(V), adj(V, std::vector<T>(V,\
    \ inf)), inf(inf) {\n    for (int i = 0; i < V; i++) adj[i][i] = 0;\n  }\n\n \
    \ void add_edge(const int src, const int dst, const T weight) {\n    adj[src][dst]\
    \ = weight;\n  }\n};\n\ntemplate <typename T>\nstruct AllPairsShortestPath {\n\
    \  Graph<T> g;\n  std::vector<std::vector<T>> dist;\n  T inf;\n\n  AllPairsShortestPath(const\
    \ Graph<T> &g, T inf = std::numeric_limits<T>::max())\n      : g(g), dist(g.V,\
    \ std::vector<T>(g.V)), inf(inf) {\n    for (int i = 0; i < g.V; i++) {\n    \
    \  for (int j = 0; j < g.V; j++) dist[i][j] = g.adj[i][j];\n    }\n  }\n\n  void\
    \ run() {\n    for (int k = 0; k < g.V; k++) {\n      for (int i = 0; i < g.V;\
    \ i++) {\n        for (int j = 0; j < g.V; j++) {\n          if (dist[i][k] !=\
    \ inf and dist[k][j] != inf) {\n            dist[i][j] = std::min(dist[i][j],\
    \ dist[i][k] + dist[k][j]);\n          }\n        }\n      }\n    }\n  }\n\n \
    \ bool has_negative_loop() const {\n    for (int i = 0; i < g.V; i++) {\n    \
    \  if (dist[i][i] < 0) return true;\n    }\n    return false;\n  }\n};\n\nvoid\
    \ aoj() {\n  // https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_C\n\
    \  int V, E;\n  std::cin >> V >> E;\n  Graph<long long> g(V);\n  for (int i =\
    \ 0; i < E; i++) {\n    int s, t, d;\n    std::cin >> s >> t >> d;\n    g.add_edge(s,\
    \ t, d);\n  }\n  AllPairsShortestPath<long long> apsp(g);\n  apsp.run();\n  if\
    \ (apsp.has_negative_loop()) {\n    std::cout << \"NEGATIVE CYCLE\" << std::endl;\n\
    \  } else {\n    for (int i = 0; i < g.V; i++) {\n      for (int j = 0; j < g.V;\
    \ j++) {\n        if (apsp.dist[i][j] == apsp.inf) {\n          std::cout << \"\
    INF\" << (j == g.V - 1 ? '\\n' : ' ');\n        } else {\n          std::cout\
    \ << apsp.dist[i][j] << (j == g.V - 1 ? '\\n' : ' ');\n        }\n      }\n  \
    \  }\n  }\n}\n\nint main() {\n  std::cin.tie(0);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  aoj();\n  return 0;\n}\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: c++-library/warshall_floyd.cpp
  requiredBy: []
  timestamp: '2020-01-21 04:11:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: c++-library/warshall_floyd.cpp
layout: document
redirect_from:
- /library/c++-library/warshall_floyd.cpp
- /library/c++-library/warshall_floyd.cpp.html
title: c++-library/warshall_floyd.cpp
---
