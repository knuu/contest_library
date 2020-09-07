---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"c++-library/prim.cpp\"\ntemplate <typename T>\nstruct Node\
    \ {\n  int v, src; T dist;\n  Node(int v, int src, T dist) : v(v), src(src), dist(dist)\
    \ { };\n  bool operator < (const Node<T> &n) const {\n    return dist > n.dist;\
    \ // reverse\n  }\n};\n\ntemplate <typename T>\nstruct MinimumSpanningTree {\n\
    \  Graph<T> g;\n  vector<Node<T>> mst;\n  int mincost;\n\n  MinimumSpanningTree(const\
    \ Graph<T> &g) : g(g) { }\n\n  int run() {\n    mincost = 0;\n\n    vector<bool>\
    \ used(g.V, false);\n\n    priority_queue<Node<T>> que;\n    que.emplace(0, -1,\
    \ 0);\n\n    while (!que.empty()) {\n      Node<T> n = que.top(); que.pop();\n\
    \      int v = n.v; T cost = n.dist;\n      if (used[v]) continue;\n      if (n.src\
    \ != -1) mst.push_back(n);\n      used[v] = true;\n      mincost += cost;\n  \
    \    for (Edge<T> e : g.E[v]) {\n        if (!used[e.dst]) que.emplace(e.dst,\
    \ v, e.weight);\n      }\n    }\n    return mincost;\n  }\n};\n"
  code: "template <typename T>\nstruct Node {\n  int v, src; T dist;\n  Node(int v,\
    \ int src, T dist) : v(v), src(src), dist(dist) { };\n  bool operator < (const\
    \ Node<T> &n) const {\n    return dist > n.dist; // reverse\n  }\n};\n\ntemplate\
    \ <typename T>\nstruct MinimumSpanningTree {\n  Graph<T> g;\n  vector<Node<T>>\
    \ mst;\n  int mincost;\n\n  MinimumSpanningTree(const Graph<T> &g) : g(g) { }\n\
    \n  int run() {\n    mincost = 0;\n\n    vector<bool> used(g.V, false);\n\n  \
    \  priority_queue<Node<T>> que;\n    que.emplace(0, -1, 0);\n\n    while (!que.empty())\
    \ {\n      Node<T> n = que.top(); que.pop();\n      int v = n.v; T cost = n.dist;\n\
    \      if (used[v]) continue;\n      if (n.src != -1) mst.push_back(n);\n    \
    \  used[v] = true;\n      mincost += cost;\n      for (Edge<T> e : g.E[v]) {\n\
    \        if (!used[e.dst]) que.emplace(e.dst, v, e.weight);\n      }\n    }\n\
    \    return mincost;\n  }\n};\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: c++-library/prim.cpp
  requiredBy: []
  timestamp: '2019-04-11 03:52:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: c++-library/prim.cpp
layout: document
redirect_from:
- /library/c++-library/prim.cpp
- /library/c++-library/prim.cpp.html
title: c++-library/prim.cpp
---
