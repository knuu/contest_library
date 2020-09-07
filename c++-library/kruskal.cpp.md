---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"c++-library/kruskal.cpp\"\n#include <vector>\n\ntemplate\
    \ <typename T>\nstruct Edge {\n  int src, dst;\n  T weight;\n\n  Edge(int src,\
    \ int dst, T weight) : src(src), dst(dst), weight(weight) {}\n\n  bool operator<(const\
    \ Edge<T> &e) const { return weight < e.weight; }\n};\n\ntemplate <typename T>\n\
    struct Graph {\n  int V;\n  std::vector<Edge<T>> E;\n\n  Graph(int V) : V(V) {}\n\
    \n  void add_edge(int src, int dst, T weight) {\n    E.emplace_back(src, dst,\
    \ weight);\n  }\n};\n\nstruct DisjointSet {\n  std::vector<int> parent, rank;\n\
    \n  DisjointSet(int N) {\n    parent.resize(N), rank.resize(N, 0);\n    for (int\
    \ i = 0; i < N; i++) parent[i] = i;\n  }\n\n  int find(int x) {\n    if (parent[x]\
    \ == x) {\n      return x;\n    } else {\n      return parent[x] = find(parent[x]);\n\
    \    }\n  }\n\n  void unite(int x, int y) {\n    x = find(x), y = find(y);\n \
    \   if (x == y) return;\n    if (rank[x] < rank[y]) {\n      parent[x] = y;\n\
    \    } else {\n      parent[y] = x;\n      if (rank[x] == rank[y]) rank[x]++;\n\
    \    }\n  }\n\n  bool same(int x, int y) { return find(x) == find(y); }\n};\n\n\
    template <typename T>\nstruct MinimumSpanningTree {\n  Graph<T> g;\n  std::vector<Edge<T>>\
    \ mst;\n  T mincost;\n\n  MinimumSpanningTree(const Graph<T> &g) : g(g) {}\n\n\
    \  T run() {\n    mincost = 0;\n    sort(g.E.begin(), g.E.end());\n\n    DisjointSet\
    \ uf(g.V);\n\n    for (int i = 0, edge_count = g.V - 1; edge_count; i++) {\n \
    \     assert(i < (int)g.E.size());\n      Edge<T> e = g.E[i];\n      if (!uf.same(e.src,\
    \ e.dst)) {\n        uf.unite(e.src, e.dst);\n        mst.emplace_back(e);\n \
    \       mincost += e.weight;\n        edge_count--;\n      }\n    }\n    return\
    \ mincost;\n  }\n};\n"
  code: "#include <vector>\n\ntemplate <typename T>\nstruct Edge {\n  int src, dst;\n\
    \  T weight;\n\n  Edge(int src, int dst, T weight) : src(src), dst(dst), weight(weight)\
    \ {}\n\n  bool operator<(const Edge<T> &e) const { return weight < e.weight; }\n\
    };\n\ntemplate <typename T>\nstruct Graph {\n  int V;\n  std::vector<Edge<T>>\
    \ E;\n\n  Graph(int V) : V(V) {}\n\n  void add_edge(int src, int dst, T weight)\
    \ {\n    E.emplace_back(src, dst, weight);\n  }\n};\n\nstruct DisjointSet {\n\
    \  std::vector<int> parent, rank;\n\n  DisjointSet(int N) {\n    parent.resize(N),\
    \ rank.resize(N, 0);\n    for (int i = 0; i < N; i++) parent[i] = i;\n  }\n\n\
    \  int find(int x) {\n    if (parent[x] == x) {\n      return x;\n    } else {\n\
    \      return parent[x] = find(parent[x]);\n    }\n  }\n\n  void unite(int x,\
    \ int y) {\n    x = find(x), y = find(y);\n    if (x == y) return;\n    if (rank[x]\
    \ < rank[y]) {\n      parent[x] = y;\n    } else {\n      parent[y] = x;\n   \
    \   if (rank[x] == rank[y]) rank[x]++;\n    }\n  }\n\n  bool same(int x, int y)\
    \ { return find(x) == find(y); }\n};\n\ntemplate <typename T>\nstruct MinimumSpanningTree\
    \ {\n  Graph<T> g;\n  std::vector<Edge<T>> mst;\n  T mincost;\n\n  MinimumSpanningTree(const\
    \ Graph<T> &g) : g(g) {}\n\n  T run() {\n    mincost = 0;\n    sort(g.E.begin(),\
    \ g.E.end());\n\n    DisjointSet uf(g.V);\n\n    for (int i = 0, edge_count =\
    \ g.V - 1; edge_count; i++) {\n      assert(i < (int)g.E.size());\n      Edge<T>\
    \ e = g.E[i];\n      if (!uf.same(e.src, e.dst)) {\n        uf.unite(e.src, e.dst);\n\
    \        mst.emplace_back(e);\n        mincost += e.weight;\n        edge_count--;\n\
    \      }\n    }\n    return mincost;\n  }\n};\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: c++-library/kruskal.cpp
  requiredBy: []
  timestamp: '2020-01-21 04:11:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: c++-library/kruskal.cpp
layout: document
redirect_from:
- /library/c++-library/kruskal.cpp
- /library/c++-library/kruskal.cpp.html
title: c++-library/kruskal.cpp
---
