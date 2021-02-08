---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: c++-library/scc.cpp
    title: c++-library/scc.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/cpp/2sat.test.cpp
    title: tests/cpp/2sat.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"c++-library/2sat.cpp\"\n#include <vector>\n\n#line 1 \"\
    c++-library/scc.cpp\"\n#include <algorithm>\n#line 3 \"c++-library/scc.cpp\"\n\
    \nstruct StronglyConnectedComponents {\n  int V;\n  std::vector<std::vector<int>>\
    \ G, rG;\n  std::vector<int> vs, cmp;\n  std::vector<bool> used;\n\n  StronglyConnectedComponents(const\
    \ int V)\n      : V(V), G(V), rG(V), cmp(V), used(V) {}\n\n  void add_edge(const\
    \ int from, const int to) {\n    G[from].push_back(to);\n    rG[to].push_back(from);\n\
    \  }\n\n  void dfs(const int v) {\n    used[v] = true;\n    for (int c : G[v])\n\
    \      if (not used[c]) dfs(c);\n    vs.push_back(v);\n  }\n\n  void rdfs(const\
    \ int v, const int k) {\n    used[v] = true;\n    cmp[v] = k;\n    for (int c\
    \ : rG[v])\n      if (not used[c]) rdfs(c, k);\n  }\n\n  int run() {\n    std::fill(used.begin(),\
    \ used.end(), false);\n    vs.clear();\n    for (int v = 0; v < V; v++)\n    \
    \  if (!used[v]) dfs(v);\n    std::fill(used.begin(), used.end(), false);\n  \
    \  int k = 0;\n    for (int i = vs.size() - 1; i >= 0; i--)\n      if (!used[vs[i]])\
    \ rdfs(vs[i], k++);\n    return k;\n  }\n\n  std::vector<int> create_order() {\n\
    \    std::vector<int> order(V);\n    for (std::size_t i = 0; i < cmp.size(); i++)\
    \ {\n      order[cmp[i]] = i;\n    }\n    return order;\n  }\n};\n#line 4 \"c++-library/2sat.cpp\"\
    \n\nstruct TwoSat : StronglyConnectedComponents {\n  int N;\n  std::vector<bool>\
    \ ans;\n  TwoSat(const int N) : StronglyConnectedComponents(2 * N + 1), N(N),\
    \ ans(N) {}\n\n  void add_constraint(int a, int b) {\n    add_edge(neg(a), pos(b));\n\
    \    add_edge(neg(b), pos(a));\n  }\n  int pos(const int v) { return v > 0 ? v\
    \ : N - v; }\n  int neg(const int v) { return v > 0 ? N + v : -v; }\n\n  bool\
    \ run() {\n    StronglyConnectedComponents::run();\n    for (int i = 1; i <= N;\
    \ i++) {\n      if (cmp[i] == cmp[i + N]) {\n        return false;\n      }\n\
    \    }\n\n    for (int i = 1; i <= N; i++) {\n      ans[i - 1] = cmp[i] > cmp[i\
    \ + N];\n    }\n    return true;\n  }\n};\n"
  code: "#include <vector>\n\n#include \"c++-library/scc.cpp\"\n\nstruct TwoSat :\
    \ StronglyConnectedComponents {\n  int N;\n  std::vector<bool> ans;\n  TwoSat(const\
    \ int N) : StronglyConnectedComponents(2 * N + 1), N(N), ans(N) {}\n\n  void add_constraint(int\
    \ a, int b) {\n    add_edge(neg(a), pos(b));\n    add_edge(neg(b), pos(a));\n\
    \  }\n  int pos(const int v) { return v > 0 ? v : N - v; }\n  int neg(const int\
    \ v) { return v > 0 ? N + v : -v; }\n\n  bool run() {\n    StronglyConnectedComponents::run();\n\
    \    for (int i = 1; i <= N; i++) {\n      if (cmp[i] == cmp[i + N]) {\n     \
    \   return false;\n      }\n    }\n\n    for (int i = 1; i <= N; i++) {\n    \
    \  ans[i - 1] = cmp[i] > cmp[i + N];\n    }\n    return true;\n  }\n};\n"
  dependsOn:
  - c++-library/scc.cpp
  isVerificationFile: false
  path: c++-library/2sat.cpp
  requiredBy: []
  timestamp: '2020-09-08 22:17:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/cpp/2sat.test.cpp
documentation_of: c++-library/2sat.cpp
layout: document
redirect_from:
- /library/c++-library/2sat.cpp
- /library/c++-library/2sat.cpp.html
title: c++-library/2sat.cpp
---
