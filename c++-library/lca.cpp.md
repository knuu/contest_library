---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"c++-library/lca.cpp\"\n#include <cmath>\n#include <utility>\n\
    #include <vector>\n\nstruct LowestCommonAncestor {\n  int V, log_V;\n  std::vector<std::vector<int>>\
    \ edge;\n\n  std::vector<std::vector<int>> parent;\n  std::vector<int> depth;\n\
    \n  LowestCommonAncestor(int V)\n      : V(V),\n        log_V(std::ceil(std::log2(V))\
    \ + 1),\n        edge(V),\n        parent(log_V),\n        depth(V) {\n    for\
    \ (int i = 0; i < log_V; i++) parent[i].resize(V);\n  }\n\n  void add_edge(int\
    \ a, int b) {\n    edge[a].push_back(b);\n    edge[b].push_back(a);\n  }\n\n \
    \ void dfs(int v, int par, int dep) {\n    parent[0][v] = par;\n    depth[v] =\
    \ dep;\n    for (auto child : edge[v]) {\n      if (child != par) dfs(child, v,\
    \ dep + 1);\n    }\n  }\n\n  void build(int root = 0) {\n    dfs(root, -1, 0);\n\
    \    for (int k = 0; k + 1 < log_V; k++) {\n      for (int v = 0; v < V; v++)\
    \ {\n        if (parent[k][v] < 0) {\n          parent[k + 1][v] = -1;\n     \
    \   } else {\n          parent[k + 1][v] = parent[k][parent[k][v]];\n        }\n\
    \      }\n    }\n  }\n\n  int run(int u, int v) {\n    if (depth[u] > depth[v])\
    \ std::swap(u, v);\n    for (int k = 0; k < log_V; k++) {\n      if ((depth[v]\
    \ - depth[u]) >> k & 1) {\n        v = parent[k][v];\n      }\n    }\n    if (u\
    \ == v) return u;\n\n    for (int k = log_V - 1; k >= 0; k--) {\n      if (parent[k][u]\
    \ != parent[k][v]) {\n        u = parent[k][u];\n        v = parent[k][v];\n \
    \     }\n    }\n    return parent[0][u];\n  }\n\n  // cnt \u500B\u4E0A\u306E\u89AA\
    \u3092\u53D6\u5F97\u3059\u308B\n  int get_cntup_node(int v, int cnt) {\n    if\
    \ (cnt <= 0) return v;\n    for (int k = log_V - 1; k >= 0; k--) {\n      if (cnt\
    \ >> k & 1) {\n        v = parent[k][v];\n      }\n    }\n    return v;\n  }\n\
    };\n"
  code: "#include <cmath>\n#include <utility>\n#include <vector>\n\nstruct LowestCommonAncestor\
    \ {\n  int V, log_V;\n  std::vector<std::vector<int>> edge;\n\n  std::vector<std::vector<int>>\
    \ parent;\n  std::vector<int> depth;\n\n  LowestCommonAncestor(int V)\n      :\
    \ V(V),\n        log_V(std::ceil(std::log2(V)) + 1),\n        edge(V),\n     \
    \   parent(log_V),\n        depth(V) {\n    for (int i = 0; i < log_V; i++) parent[i].resize(V);\n\
    \  }\n\n  void add_edge(int a, int b) {\n    edge[a].push_back(b);\n    edge[b].push_back(a);\n\
    \  }\n\n  void dfs(int v, int par, int dep) {\n    parent[0][v] = par;\n    depth[v]\
    \ = dep;\n    for (auto child : edge[v]) {\n      if (child != par) dfs(child,\
    \ v, dep + 1);\n    }\n  }\n\n  void build(int root = 0) {\n    dfs(root, -1,\
    \ 0);\n    for (int k = 0; k + 1 < log_V; k++) {\n      for (int v = 0; v < V;\
    \ v++) {\n        if (parent[k][v] < 0) {\n          parent[k + 1][v] = -1;\n\
    \        } else {\n          parent[k + 1][v] = parent[k][parent[k][v]];\n   \
    \     }\n      }\n    }\n  }\n\n  int run(int u, int v) {\n    if (depth[u] >\
    \ depth[v]) std::swap(u, v);\n    for (int k = 0; k < log_V; k++) {\n      if\
    \ ((depth[v] - depth[u]) >> k & 1) {\n        v = parent[k][v];\n      }\n   \
    \ }\n    if (u == v) return u;\n\n    for (int k = log_V - 1; k >= 0; k--) {\n\
    \      if (parent[k][u] != parent[k][v]) {\n        u = parent[k][u];\n      \
    \  v = parent[k][v];\n      }\n    }\n    return parent[0][u];\n  }\n\n  // cnt\
    \ \u500B\u4E0A\u306E\u89AA\u3092\u53D6\u5F97\u3059\u308B\n  int get_cntup_node(int\
    \ v, int cnt) {\n    if (cnt <= 0) return v;\n    for (int k = log_V - 1; k >=\
    \ 0; k--) {\n      if (cnt >> k & 1) {\n        v = parent[k][v];\n      }\n \
    \   }\n    return v;\n  }\n};\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/cpp/lca.test.cpp
    title: tests/cpp/lca.test.cpp
  isVerificationFile: false
  path: c++-library/lca.cpp
  requiredBy: []
  timestamp: '2020-02-16 02:15:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith:
  - tests/cpp/lca.test.cpp
documentation_of: c++-library/lca.cpp
layout: document
redirect_from:
- /library/c++-library/lca.cpp
- /library/c++-library/lca.cpp.html
title: c++-library/lca.cpp
---
