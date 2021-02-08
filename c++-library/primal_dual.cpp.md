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
  bundledCode: "#line 1 \"c++-library/primal_dual.cpp\"\nconst int INF = 1e7;\n\n\
    template <typename T>\nstruct MinCostFlow {\n  struct Edge {\n    int to, rev;\
    \ T cap, cost;\n    Edge(int to, int rev, T cap, T cost) : to(to), rev(rev), cap(cap),\
    \ cost(cost) { }\n  };\n\n  struct Node {\n    int v; T dist;\n    Node(int v,\
    \ T dist) : v(v), dist(dist) { };\n    bool operator < (const Node &n) const {\n\
    \      return dist > n.dist; // reverse\n    }\n  };\n\n  typedef vector<Edge>\
    \ Edges;\n  vector<Edges> G;\n  int V;\n  vector<int> dist, h, prevv, preve;\n\
    \n  MinCostFlow(int V) : V(V) { G.resize(V); }\n\n  void add_edge(int from, int\
    \ to, T cap, T cost) {\n    G[from].emplace_back(to, G[to].size(), cap, cost);\n\
    \    G[to].emplace_back(from, (int)G[from].size()-1, 0, -cost);\n  }\n\n  T run(int\
    \ source, int sink, T f) {\n    T res = 0;\n    h.resize(V, 0);\n    prevv.resize(V),\
    \ preve.resize(V);\n    while (f > 0) {\n      priority_queue<Node> pque;\n  \
    \    dist.assign(V, INF);\n      dist[source] = 0;\n      pque.emplace(source,\
    \ 0);\n      while (not pque.empty()) {\n        Node n = pque.top(); pque.pop();\n\
    \        int v = n.v; T cost = n.dist;\n        if (dist[v] < cost) continue;\n\
    \        for (int i = 0; i < (int)G[v].size(); i++) {\n          Edge e = G[v][i];\n\
    \          if (e.cap > 0 and dist[v] - h[e.to] < dist[e.to] - e.cost - h[v]) {\n\
    \            dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];\n            prevv[e.to]\
    \ = v, preve[e.to] = i;\n            pque.emplace(e.to, dist[e.to]);\n       \
    \   }\n        }\n      }\n      if (dist[sink] == INF) return -1;\n      for\
    \ (int v = 0; v < V; v++) h[v] += dist[v];\n\n      T d = f;\n      for (int v\
    \ = sink; v != source; v = prevv[v]) {\n        d = min(d, G[prevv[v]][preve[v]].cap);\n\
    \      }\n      f -= d;\n      res += d * h[sink];\n      for (int v = sink; v\
    \ != source; v = prevv[v]) {\n        Edge &e = G[prevv[v]][preve[v]];\n     \
    \   e.cap -= d;\n        G[v][e.rev].cap += d;\n      }\n    }\n    return res;\n\
    \  }\n};\n"
  code: "const int INF = 1e7;\n\ntemplate <typename T>\nstruct MinCostFlow {\n  struct\
    \ Edge {\n    int to, rev; T cap, cost;\n    Edge(int to, int rev, T cap, T cost)\
    \ : to(to), rev(rev), cap(cap), cost(cost) { }\n  };\n\n  struct Node {\n    int\
    \ v; T dist;\n    Node(int v, T dist) : v(v), dist(dist) { };\n    bool operator\
    \ < (const Node &n) const {\n      return dist > n.dist; // reverse\n    }\n \
    \ };\n\n  typedef vector<Edge> Edges;\n  vector<Edges> G;\n  int V;\n  vector<int>\
    \ dist, h, prevv, preve;\n\n  MinCostFlow(int V) : V(V) { G.resize(V); }\n\n \
    \ void add_edge(int from, int to, T cap, T cost) {\n    G[from].emplace_back(to,\
    \ G[to].size(), cap, cost);\n    G[to].emplace_back(from, (int)G[from].size()-1,\
    \ 0, -cost);\n  }\n\n  T run(int source, int sink, T f) {\n    T res = 0;\n  \
    \  h.resize(V, 0);\n    prevv.resize(V), preve.resize(V);\n    while (f > 0) {\n\
    \      priority_queue<Node> pque;\n      dist.assign(V, INF);\n      dist[source]\
    \ = 0;\n      pque.emplace(source, 0);\n      while (not pque.empty()) {\n   \
    \     Node n = pque.top(); pque.pop();\n        int v = n.v; T cost = n.dist;\n\
    \        if (dist[v] < cost) continue;\n        for (int i = 0; i < (int)G[v].size();\
    \ i++) {\n          Edge e = G[v][i];\n          if (e.cap > 0 and dist[v] - h[e.to]\
    \ < dist[e.to] - e.cost - h[v]) {\n            dist[e.to] = dist[v] + e.cost +\
    \ h[v] - h[e.to];\n            prevv[e.to] = v, preve[e.to] = i;\n           \
    \ pque.emplace(e.to, dist[e.to]);\n          }\n        }\n      }\n      if (dist[sink]\
    \ == INF) return -1;\n      for (int v = 0; v < V; v++) h[v] += dist[v];\n\n \
    \     T d = f;\n      for (int v = sink; v != source; v = prevv[v]) {\n      \
    \  d = min(d, G[prevv[v]][preve[v]].cap);\n      }\n      f -= d;\n      res +=\
    \ d * h[sink];\n      for (int v = sink; v != source; v = prevv[v]) {\n      \
    \  Edge &e = G[prevv[v]][preve[v]];\n        e.cap -= d;\n        G[v][e.rev].cap\
    \ += d;\n      }\n    }\n    return res;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: c++-library/primal_dual.cpp
  requiredBy: []
  timestamp: '2019-04-11 03:52:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: c++-library/primal_dual.cpp
layout: document
redirect_from:
- /library/c++-library/primal_dual.cpp
- /library/c++-library/primal_dual.cpp.html
title: c++-library/primal_dual.cpp
---
