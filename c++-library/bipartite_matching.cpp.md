---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"c++-library/bipartite_matching.cpp\"\n#include <algorithm>\n\
    #include <iostream>\n#include <numeric>\n#include <queue>\n#include <vector>\n\
    \ntemplate <typename T>\nstruct BipartiteMatching {\n  struct Edge {\n    int\
    \ to, rev;\n    T cap;\n    Edge(int to, int rev, T cap) : to(to), rev(rev), cap(cap)\
    \ {}\n  };\n\n  typedef std::vector<Edge> Edges;\n  std::vector<Edges> G;\n  int\
    \ V, source, sink;\n  std::vector<int> level, iter;\n  T inf;\n\n  BipartiteMatching(const\
    \ int V1, const int V2,\n                    const T inf = std::numeric_limits<T>::max())\n\
    \      : V(V1 + V2 + 2), inf(inf) {\n    source = V - 2, sink = V - 1;\n    G.resize(V);\n\
    \    add_sink_source(V1, V2);\n  }\n\n  void add_edge(const int from, const int\
    \ to) {\n    G[from].emplace_back(to, G[to].size(), 1);\n    G[to].emplace_back(from,\
    \ static_cast<int>(G[from].size() - 1), 0);\n  }\n\n  void add_sink_source(const\
    \ int V1, const int V2) {\n    for (int i = 0; i < V1; i++) add_edge(source, i);\n\
    \    for (int i = V1; i < V1 + V2; i++) add_edge(i, sink);\n  }\n\n  void bfs(const\
    \ int source) {\n    level.assign(V, -1);\n    std::queue<int> que;\n    que.emplace(source);\n\
    \    level[source] = 0;\n    while (!que.empty()) {\n      int v = que.front();\n\
    \      que.pop();\n      for (int i = 0; i < (int)G[v].size(); i++) {\n      \
    \  Edge &e = G[v][i];\n        if (e.cap > 0 && level[e.to] < 0) {\n         \
    \ level[e.to] = level[v] + 1;\n          que.emplace(e.to);\n        }\n     \
    \ }\n    }\n  }\n\n  T dfs(const int v, const int sink, const T flow) {\n    if\
    \ (v == sink) return flow;\n    for (int &i = iter[v]; i < static_cast<int>(G[v].size());\
    \ i++) {\n      Edge &e = G[v][i];\n      if (e.cap > 0 && level[v] < level[e.to])\
    \ {\n        T d = dfs(e.to, sink, std::min(e.cap, flow));\n        if (d > 0)\
    \ {\n          e.cap -= d;\n          G[e.to][e.rev].cap += d;\n          return\
    \ d;\n        }\n      }\n    }\n    return 0;\n  }\n\n  T run() {\n    T flow\
    \ = 0;\n    while (true) {\n      bfs(source);\n      if (level[sink] < 0) return\
    \ flow;\n      iter.assign(V, 0);\n      T f;\n      while ((f = dfs(source, sink,\
    \ inf)) > 0) {\n        flow += f;\n      }\n    }\n  }\n};\n\nvoid yosupo_bm()\
    \ {\n  // https://judge.yosupo.jp/problem/bipartitematching\n  int L, R, M;\n\
    \  std::cin >> L >> R >> M;\n  BipartiteMatching<int> bm(L, R);\n  for (int i\
    \ = 0; i < M; i++) {\n    int a, b;\n    std::cin >> a >> b;\n    bm.add_edge(a,\
    \ b + L);\n  }\n  std::cout << bm.run() << '\\n';\n  for (int i = 0; i < L; i++)\
    \ {\n    for (auto e : bm.G[i]) {\n      if (e.cap == 0 and e.to < L + R) {\n\
    \        std::cout << i << ' ' << e.to - L << '\\n';\n      }\n    }\n  }\n}\n\
    \nint main() {\n  std::cin.tie(0);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  yosupo_bm();\n  return 0;\n}\n"
  code: "#include <algorithm>\n#include <iostream>\n#include <numeric>\n#include <queue>\n\
    #include <vector>\n\ntemplate <typename T>\nstruct BipartiteMatching {\n  struct\
    \ Edge {\n    int to, rev;\n    T cap;\n    Edge(int to, int rev, T cap) : to(to),\
    \ rev(rev), cap(cap) {}\n  };\n\n  typedef std::vector<Edge> Edges;\n  std::vector<Edges>\
    \ G;\n  int V, source, sink;\n  std::vector<int> level, iter;\n  T inf;\n\n  BipartiteMatching(const\
    \ int V1, const int V2,\n                    const T inf = std::numeric_limits<T>::max())\n\
    \      : V(V1 + V2 + 2), inf(inf) {\n    source = V - 2, sink = V - 1;\n    G.resize(V);\n\
    \    add_sink_source(V1, V2);\n  }\n\n  void add_edge(const int from, const int\
    \ to) {\n    G[from].emplace_back(to, G[to].size(), 1);\n    G[to].emplace_back(from,\
    \ static_cast<int>(G[from].size() - 1), 0);\n  }\n\n  void add_sink_source(const\
    \ int V1, const int V2) {\n    for (int i = 0; i < V1; i++) add_edge(source, i);\n\
    \    for (int i = V1; i < V1 + V2; i++) add_edge(i, sink);\n  }\n\n  void bfs(const\
    \ int source) {\n    level.assign(V, -1);\n    std::queue<int> que;\n    que.emplace(source);\n\
    \    level[source] = 0;\n    while (!que.empty()) {\n      int v = que.front();\n\
    \      que.pop();\n      for (int i = 0; i < (int)G[v].size(); i++) {\n      \
    \  Edge &e = G[v][i];\n        if (e.cap > 0 && level[e.to] < 0) {\n         \
    \ level[e.to] = level[v] + 1;\n          que.emplace(e.to);\n        }\n     \
    \ }\n    }\n  }\n\n  T dfs(const int v, const int sink, const T flow) {\n    if\
    \ (v == sink) return flow;\n    for (int &i = iter[v]; i < static_cast<int>(G[v].size());\
    \ i++) {\n      Edge &e = G[v][i];\n      if (e.cap > 0 && level[v] < level[e.to])\
    \ {\n        T d = dfs(e.to, sink, std::min(e.cap, flow));\n        if (d > 0)\
    \ {\n          e.cap -= d;\n          G[e.to][e.rev].cap += d;\n          return\
    \ d;\n        }\n      }\n    }\n    return 0;\n  }\n\n  T run() {\n    T flow\
    \ = 0;\n    while (true) {\n      bfs(source);\n      if (level[sink] < 0) return\
    \ flow;\n      iter.assign(V, 0);\n      T f;\n      while ((f = dfs(source, sink,\
    \ inf)) > 0) {\n        flow += f;\n      }\n    }\n  }\n};\n\nvoid yosupo_bm()\
    \ {\n  // https://judge.yosupo.jp/problem/bipartitematching\n  int L, R, M;\n\
    \  std::cin >> L >> R >> M;\n  BipartiteMatching<int> bm(L, R);\n  for (int i\
    \ = 0; i < M; i++) {\n    int a, b;\n    std::cin >> a >> b;\n    bm.add_edge(a,\
    \ b + L);\n  }\n  std::cout << bm.run() << '\\n';\n  for (int i = 0; i < L; i++)\
    \ {\n    for (auto e : bm.G[i]) {\n      if (e.cap == 0 and e.to < L + R) {\n\
    \        std::cout << i << ' ' << e.to - L << '\\n';\n      }\n    }\n  }\n}\n\
    \nint main() {\n  std::cin.tie(0);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  yosupo_bm();\n  return 0;\n}"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: c++-library/bipartite_matching.cpp
  requiredBy: []
  timestamp: '2020-09-08 04:11:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: c++-library/bipartite_matching.cpp
layout: document
redirect_from:
- /library/c++-library/bipartite_matching.cpp
- /library/c++-library/bipartite_matching.cpp.html
title: c++-library/bipartite_matching.cpp
---
