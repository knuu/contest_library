---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: c++-library/scc.cpp
    title: c++-library/scc.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C
  bundledCode: "#line 1 \"tests/cpp/scc_aoj.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C\"\
    \n#include <iostream>\n\n#line 1 \"c++-library/scc.cpp\"\n#include <algorithm>\n\
    #include <vector>\n\nstruct StronglyConnectedComponents {\n  int V;\n  std::vector<std::vector<int>>\
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
    \ {\n      order[cmp[i]] = i;\n    }\n    return order;\n  }\n};\n#line 5 \"tests/cpp/scc_aoj.test.cpp\"\
    \n\nvoid aoj() {\n  int N, M;\n  std::cin >> N >> M;\n  StronglyConnectedComponents\
    \ scc(N);\n  for (int i = 0; i < M; i++) {\n    int a, b;\n    std::cin >> a >>\
    \ b;\n    scc.add_edge(a, b);\n  }\n  scc.run();\n  int Q;\n  std::cin >> Q;\n\
    \  for (int i = 0; i < Q; i++) {\n    int u, v;\n    std::cin >> u >> v;\n   \
    \ std::cout << (scc.cmp[u] == scc.cmp[v]) << std::endl;\n  }\n}\n\nint main()\
    \ {\n  std::cin.tie(0);\n  std::ios_base::sync_with_stdio(false);\n\n  aoj();\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C\"\
    \n#include <iostream>\n\n#include \"c++-library/scc.cpp\"\n\nvoid aoj() {\n  int\
    \ N, M;\n  std::cin >> N >> M;\n  StronglyConnectedComponents scc(N);\n  for (int\
    \ i = 0; i < M; i++) {\n    int a, b;\n    std::cin >> a >> b;\n    scc.add_edge(a,\
    \ b);\n  }\n  scc.run();\n  int Q;\n  std::cin >> Q;\n  for (int i = 0; i < Q;\
    \ i++) {\n    int u, v;\n    std::cin >> u >> v;\n    std::cout << (scc.cmp[u]\
    \ == scc.cmp[v]) << std::endl;\n  }\n}\n\nint main() {\n  std::cin.tie(0);\n \
    \ std::ios_base::sync_with_stdio(false);\n\n  aoj();\n  return 0;\n}\n"
  dependsOn:
  - c++-library/scc.cpp
  isVerificationFile: true
  path: tests/cpp/scc_aoj.test.cpp
  requiredBy: []
  timestamp: '2020-09-08 22:17:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/cpp/scc_aoj.test.cpp
layout: document
redirect_from:
- /verify/tests/cpp/scc_aoj.test.cpp
- /verify/tests/cpp/scc_aoj.test.cpp.html
title: tests/cpp/scc_aoj.test.cpp
---
