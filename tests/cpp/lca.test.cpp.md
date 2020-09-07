---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"tests/cpp/lca.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\
    \n#include <iostream>\n\n#line 1 \"c++-library/lca.cpp\"\n#include <cmath>\n#include\
    \ <utility>\n#include <vector>\n\nstruct LowestCommonAncestor {\n  int V, log_V;\n\
    \  std::vector<std::vector<int>> edge;\n\n  std::vector<std::vector<int>> parent;\n\
    \  std::vector<int> depth;\n\n  LowestCommonAncestor(int V)\n      : V(V),\n \
    \       log_V(std::ceil(std::log2(V)) + 1),\n        edge(V),\n        parent(log_V),\n\
    \        depth(V) {\n    for (int i = 0; i < log_V; i++) parent[i].resize(V);\n\
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
    \   }\n    return v;\n  }\n};\n#line 5 \"tests/cpp/lca.test.cpp\"\n\nvoid yosupo()\
    \ {\n  int N, Q;\n  std::cin >> N >> Q;\n  LowestCommonAncestor lca(N);\n  for\
    \ (int i = 1; i < N; i++) {\n    int p;\n    std::cin >> p;\n    lca.add_edge(p,\
    \ i);\n  }\n  lca.build(0);\n  for (int i = 0; i < Q; i++) {\n    int u, v;\n\
    \    std::cin >> u >> v;\n    std::cout << lca.run(u, v) << '\\n';\n  }\n}\n\n\
    int main() {\n  std::cin.tie(0);\n  std::ios_base::sync_with_stdio(false);\n \
    \ yosupo();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#include <iostream>\n\
    \n#include \"c++-library/lca.cpp\"\n\nvoid yosupo() {\n  int N, Q;\n  std::cin\
    \ >> N >> Q;\n  LowestCommonAncestor lca(N);\n  for (int i = 1; i < N; i++) {\n\
    \    int p;\n    std::cin >> p;\n    lca.add_edge(p, i);\n  }\n  lca.build(0);\n\
    \  for (int i = 0; i < Q; i++) {\n    int u, v;\n    std::cin >> u >> v;\n   \
    \ std::cout << lca.run(u, v) << '\\n';\n  }\n}\n\nint main() {\n  std::cin.tie(0);\n\
    \  std::ios_base::sync_with_stdio(false);\n  yosupo();\n  return 0;\n}\n"
  dependsOn:
  - c++-library/lca.cpp
  extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: c++-library/lca.cpp
    title: c++-library/lca.cpp
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: tests/cpp/lca.test.cpp
  requiredBy: []
  timestamp: '2020-09-08 03:58:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith: []
documentation_of: tests/cpp/lca.test.cpp
layout: document
redirect_from:
- /verify/tests/cpp/lca.test.cpp
- /verify/tests/cpp/lca.test.cpp.html
title: tests/cpp/lca.test.cpp
---
