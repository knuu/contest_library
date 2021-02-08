---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"c++-library/dinic.cpp\"\n#define INF 1<<29\n\ntemplate <typename\
    \ T>\nstruct MaxFlow {\n  struct Edge {\n    int to, rev; T cap;\n    Edge(int\
    \ to, int rev, T cap) : to(to), rev(rev), cap(cap) { }\n  };\n\n  typedef vector<Edge>\
    \ Edges;\n  vector<Edges> G;\n  int V;\n  vector<int> level, iter;\n\n  MaxFlow(int\
    \ V) : V(V) { G.resize(V); }\n\n  void add_edge(int from, int to, T cap) {\n \
    \   G[from].emplace_back(to, G[to].size(), cap);\n    G[to].emplace_back(from,\
    \ (int)G[from].size()-1, 0);\n  }\n\n  void bfs(int source) {\n    level.assign(V,\
    \ -1);\n    queue<int> que;\n    que.emplace(source);\n    level[source] = 0;\n\
    \    while (!que.empty()) {\n      int v = que.front(); que.pop();\n      for\
    \ (int i = 0; i < (int)G[v].size(); i++) {\n        Edge &e = G[v][i];\n     \
    \   if (e.cap > 0 && level[e.to] < 0) {\n          level[e.to] = level[v] + 1;\n\
    \          que.emplace(e.to);\n        }\n      }\n    }\n  }\n\n  T dfs(int v,\
    \ int sink, T flow) {\n    if (v == sink) return flow;\n    for (int &i = iter[v];\
    \ i < (int)G[v].size(); i++) {\n      Edge &e = G[v][i];\n      if (e.cap > 0\
    \ && level[v] < level[e.to]) {\n        T d = dfs(e.to, sink, min(e.cap, flow));\n\
    \        if (d > 0) {\n          e.cap -= d;\n          G[e.to][e.rev].cap +=\
    \ d;\n          return d;\n        }\n      }\n    }\n    return 0;\n  }\n\n \
    \ T run(int source, int sink) {\n    T flow = 0;\n    while (true) {\n      bfs(source);\n\
    \      if (level[sink] < 0) return flow;\n      iter.assign(V, 0);\n      T f;\n\
    \      while ((f = dfs(source, sink, INF)) > 0) flow += f;\n    }\n  }\n};\n"
  code: "#define INF 1<<29\n\ntemplate <typename T>\nstruct MaxFlow {\n  struct Edge\
    \ {\n    int to, rev; T cap;\n    Edge(int to, int rev, T cap) : to(to), rev(rev),\
    \ cap(cap) { }\n  };\n\n  typedef vector<Edge> Edges;\n  vector<Edges> G;\n  int\
    \ V;\n  vector<int> level, iter;\n\n  MaxFlow(int V) : V(V) { G.resize(V); }\n\
    \n  void add_edge(int from, int to, T cap) {\n    G[from].emplace_back(to, G[to].size(),\
    \ cap);\n    G[to].emplace_back(from, (int)G[from].size()-1, 0);\n  }\n\n  void\
    \ bfs(int source) {\n    level.assign(V, -1);\n    queue<int> que;\n    que.emplace(source);\n\
    \    level[source] = 0;\n    while (!que.empty()) {\n      int v = que.front();\
    \ que.pop();\n      for (int i = 0; i < (int)G[v].size(); i++) {\n        Edge\
    \ &e = G[v][i];\n        if (e.cap > 0 && level[e.to] < 0) {\n          level[e.to]\
    \ = level[v] + 1;\n          que.emplace(e.to);\n        }\n      }\n    }\n \
    \ }\n\n  T dfs(int v, int sink, T flow) {\n    if (v == sink) return flow;\n \
    \   for (int &i = iter[v]; i < (int)G[v].size(); i++) {\n      Edge &e = G[v][i];\n\
    \      if (e.cap > 0 && level[v] < level[e.to]) {\n        T d = dfs(e.to, sink,\
    \ min(e.cap, flow));\n        if (d > 0) {\n          e.cap -= d;\n          G[e.to][e.rev].cap\
    \ += d;\n          return d;\n        }\n      }\n    }\n    return 0;\n  }\n\n\
    \  T run(int source, int sink) {\n    T flow = 0;\n    while (true) {\n      bfs(source);\n\
    \      if (level[sink] < 0) return flow;\n      iter.assign(V, 0);\n      T f;\n\
    \      while ((f = dfs(source, sink, INF)) > 0) flow += f;\n    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: c++-library/dinic.cpp
  requiredBy: []
  timestamp: '2019-04-11 03:52:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: c++-library/dinic.cpp
layout: document
redirect_from:
- /library/c++-library/dinic.cpp
- /library/c++-library/dinic.cpp.html
title: c++-library/dinic.cpp
---
