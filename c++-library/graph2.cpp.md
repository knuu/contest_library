---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"c++-library/graph2.cpp\"\n#include <numeric>\n#include <vector>\n\
    \n// graph by adjacency matrix\ntemplate <typename T>\nstruct Graph {\n  int V;\n\
    \  std::vector<std::vector<T>> adj;\n  T inf;\n\n  Graph(const int V, const T\
    \ inf = std::numeric_limits<T>::max())\n      : V(V), adj(V, std::vector<T>(V,\
    \ inf)), inf(inf) {\n    for (int i = 0; i < V; i++) adj[i][i] = 0;\n  }\n\n \
    \ void add_edge(const int src, const int dst, const T weight) {\n    adj[src][dst]\
    \ = weight;\n  }\n};\n"
  code: "#include <numeric>\n#include <vector>\n\n// graph by adjacency matrix\ntemplate\
    \ <typename T>\nstruct Graph {\n  int V;\n  std::vector<std::vector<T>> adj;\n\
    \  T inf;\n\n  Graph(const int V, const T inf = std::numeric_limits<T>::max())\n\
    \      : V(V), adj(V, std::vector<T>(V, inf)), inf(inf) {\n    for (int i = 0;\
    \ i < V; i++) adj[i][i] = 0;\n  }\n\n  void add_edge(const int src, const int\
    \ dst, const T weight) {\n    adj[src][dst] = weight;\n  }\n};\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: c++-library/graph2.cpp
  requiredBy: []
  timestamp: '2020-01-21 04:11:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: c++-library/graph2.cpp
layout: document
redirect_from:
- /library/c++-library/graph2.cpp
- /library/c++-library/graph2.cpp.html
title: c++-library/graph2.cpp
---
