---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"c++-library/minimum_ratio_spanning_tree.cpp\"\n#include\
    \ <bits/stdc++.h>\n\nusing namespace std;\ntypedef long long int ll;\ntypedef\
    \ pair<int, int> P;\ntypedef pair<ll, ll> Pll;\ntypedef vector<int> Vi;\n// typedef\
    \ tuple<int, int, int> T;\n#define FOR(i, s, x) for (int i = s; i < (int)(x);\
    \ i++)\n#define REP(i, x) FOR(i, 0, x)\n#define ALL(c) c.begin(), c.end()\n#define\
    \ DUMP(x) cerr << #x << \" = \" << (x) << endl\n#define UNIQUE(c) sort(ALL(c)),\
    \ c.erase(unique(ALL(c)), c.end())\n\nconst int dr[4] = {-1, 0, 1, 0};\nconst\
    \ int dc[4] = {0, 1, 0, -1};\n\nstruct DisjointSet {\n  std::vector<int> parent,\
    \ rank;\n\n  DisjointSet(int N) {\n    parent.resize(N), rank.resize(N, 0);\n\
    \    for (int i = 0; i < N; i++) parent[i] = i;\n  }\n\n  int find(int x) {\n\
    \    if (parent[x] == x) {\n      return x;\n    } else {\n      return parent[x]\
    \ = find(parent[x]);\n    }\n  }\n\n  void unite(int x, int y) {\n    x = find(x),\
    \ y = find(y);\n    if (x == y) return;\n    if (rank[x] < rank[y]) {\n      parent[x]\
    \ = y;\n    } else {\n      parent[y] = x;\n      if (rank[x] == rank[y]) rank[x]++;\n\
    \    }\n  }\n\n  bool same(int x, int y) { return find(x) == find(y); }\n};\n\n\
    template <typename T>\nstruct Edge {\n  int src, dst;\n  T weight1, weight2;\n\
    \n  Edge(int src, int dst, T weight1, T weight2)\n      : src(src), dst(dst),\
    \ weight1(weight1), weight2(weight2) {}\n};\n\ntemplate <typename T>\nstruct Graph\
    \ {\n  int V;\n  std::vector<Edge<T>> E;\n\n  Graph(int V) : V(V) {}\n\n  void\
    \ add_edge(int src, int dst, T weight1, T weight2) {\n    E.emplace_back(src,\
    \ dst, weight1, weight2);\n  }\n};\n\ntemplate <typename T>\nstruct MinimumRatioSpanningTree\
    \ {\n  Graph<T> g;\n  std::vector<Edge<T>> mst;\n  T mincost;\n\n  MinimumRatioSpanningTree(const\
    \ Graph<T> &g) : g(g) {}\n\n  T run_mst(double &fcost, double &gcost) {\n    fcost\
    \ = gcost = 0;\n    sort(g.E.begin(), g.E.end(), [&](Edge<T> e1, Edge<T> e2) {\n\
    \      return e1.weight1 - mincost * e1.weight2 <\n             e2.weight1 - mincost\
    \ * e2.weight2;\n    });\n    DisjointSet uf(g.V);\n    for (int i = 0, edge_count\
    \ = g.V - 1; edge_count; i++) {\n      Edge<T> e = g.E[i];\n      if (!uf.same(e.src,\
    \ e.dst)) {\n        uf.unite(e.src, e.dst);\n        mst.emplace_back(e);\n \
    \       fcost += e.weight1;\n        gcost += e.weight2;\n        edge_count--;\n\
    \      }\n    }\n    return fcost - mincost * gcost;\n  }\n\n  T run() {\n   \
    \ // Dinkelbach algorithm\n    double fcost, gcost;\n    for (mincost = 0.0;;\
    \ mincost = fcost / gcost) {\n      if (std::fabs(run_mst(fcost, gcost)) < 1e-8)\
    \ {\n        break;\n      }\n    }\n    return mincost;\n  }\n};\n\nint main()\
    \ {\n  // use scanf in CodeForces!\n  cin.tie(0);\n  ios_base::sync_with_stdio(false);\n\
    \  int N, M;\n  cin >> N >> M;\n  Graph<double> g(N);\n  REP(i, M) {\n    int\
    \ a, b;\n    double c, t;\n    cin >> a >> b >> c >> t;\n    g.add_edge(a, b,\
    \ c, t);\n  }\n  MinimumRatioSpanningTree<double> mrst(g);\n\n  std::cout << std::fixed\
    \ << std::setprecision(20) << mrst.run() << std::endl;\n  return 0;\n}\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\ntypedef long long int ll;\n\
    typedef pair<int, int> P;\ntypedef pair<ll, ll> Pll;\ntypedef vector<int> Vi;\n\
    // typedef tuple<int, int, int> T;\n#define FOR(i, s, x) for (int i = s; i < (int)(x);\
    \ i++)\n#define REP(i, x) FOR(i, 0, x)\n#define ALL(c) c.begin(), c.end()\n#define\
    \ DUMP(x) cerr << #x << \" = \" << (x) << endl\n#define UNIQUE(c) sort(ALL(c)),\
    \ c.erase(unique(ALL(c)), c.end())\n\nconst int dr[4] = {-1, 0, 1, 0};\nconst\
    \ int dc[4] = {0, 1, 0, -1};\n\nstruct DisjointSet {\n  std::vector<int> parent,\
    \ rank;\n\n  DisjointSet(int N) {\n    parent.resize(N), rank.resize(N, 0);\n\
    \    for (int i = 0; i < N; i++) parent[i] = i;\n  }\n\n  int find(int x) {\n\
    \    if (parent[x] == x) {\n      return x;\n    } else {\n      return parent[x]\
    \ = find(parent[x]);\n    }\n  }\n\n  void unite(int x, int y) {\n    x = find(x),\
    \ y = find(y);\n    if (x == y) return;\n    if (rank[x] < rank[y]) {\n      parent[x]\
    \ = y;\n    } else {\n      parent[y] = x;\n      if (rank[x] == rank[y]) rank[x]++;\n\
    \    }\n  }\n\n  bool same(int x, int y) { return find(x) == find(y); }\n};\n\n\
    template <typename T>\nstruct Edge {\n  int src, dst;\n  T weight1, weight2;\n\
    \n  Edge(int src, int dst, T weight1, T weight2)\n      : src(src), dst(dst),\
    \ weight1(weight1), weight2(weight2) {}\n};\n\ntemplate <typename T>\nstruct Graph\
    \ {\n  int V;\n  std::vector<Edge<T>> E;\n\n  Graph(int V) : V(V) {}\n\n  void\
    \ add_edge(int src, int dst, T weight1, T weight2) {\n    E.emplace_back(src,\
    \ dst, weight1, weight2);\n  }\n};\n\ntemplate <typename T>\nstruct MinimumRatioSpanningTree\
    \ {\n  Graph<T> g;\n  std::vector<Edge<T>> mst;\n  T mincost;\n\n  MinimumRatioSpanningTree(const\
    \ Graph<T> &g) : g(g) {}\n\n  T run_mst(double &fcost, double &gcost) {\n    fcost\
    \ = gcost = 0;\n    sort(g.E.begin(), g.E.end(), [&](Edge<T> e1, Edge<T> e2) {\n\
    \      return e1.weight1 - mincost * e1.weight2 <\n             e2.weight1 - mincost\
    \ * e2.weight2;\n    });\n    DisjointSet uf(g.V);\n    for (int i = 0, edge_count\
    \ = g.V - 1; edge_count; i++) {\n      Edge<T> e = g.E[i];\n      if (!uf.same(e.src,\
    \ e.dst)) {\n        uf.unite(e.src, e.dst);\n        mst.emplace_back(e);\n \
    \       fcost += e.weight1;\n        gcost += e.weight2;\n        edge_count--;\n\
    \      }\n    }\n    return fcost - mincost * gcost;\n  }\n\n  T run() {\n   \
    \ // Dinkelbach algorithm\n    double fcost, gcost;\n    for (mincost = 0.0;;\
    \ mincost = fcost / gcost) {\n      if (std::fabs(run_mst(fcost, gcost)) < 1e-8)\
    \ {\n        break;\n      }\n    }\n    return mincost;\n  }\n};\n\nint main()\
    \ {\n  // use scanf in CodeForces!\n  cin.tie(0);\n  ios_base::sync_with_stdio(false);\n\
    \  int N, M;\n  cin >> N >> M;\n  Graph<double> g(N);\n  REP(i, M) {\n    int\
    \ a, b;\n    double c, t;\n    cin >> a >> b >> c >> t;\n    g.add_edge(a, b,\
    \ c, t);\n  }\n  MinimumRatioSpanningTree<double> mrst(g);\n\n  std::cout << std::fixed\
    \ << std::setprecision(20) << mrst.run() << std::endl;\n  return 0;\n}\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: c++-library/minimum_ratio_spanning_tree.cpp
  requiredBy: []
  timestamp: '2020-01-21 04:11:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: c++-library/minimum_ratio_spanning_tree.cpp
layout: document
redirect_from:
- /library/c++-library/minimum_ratio_spanning_tree.cpp
- /library/c++-library/minimum_ratio_spanning_tree.cpp.html
title: c++-library/minimum_ratio_spanning_tree.cpp
---
