---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"c++-library/manhattan_mst.cpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <iostream>\n#include <limits>\n#include <numeric>\n\
    #include <tuple>\n#include <utility>\n#include <vector>\n\ntemplate <class Monoid>\n\
    struct SegmentTree {\n  using T = typename Monoid::type;\n  int N_, N;\n  std::vector<T>\
    \ dat;\n\n  SegmentTree(const int N_) : N_(N_) {\n    assert(N_ > 0);\n    N =\
    \ 1;\n    while (N < N_) {\n      N <<= 1;\n    }\n    dat.assign(2 * N - 1, Monoid::identity());\n\
    \  }\n\n  SegmentTree(const std::vector<T> &dat_) : N_(dat_.size()) {\n    assert(N_\
    \ > 0);\n    N = 1;\n    while (N < N_) {\n      N <<= 1;\n    }\n    dat.assign(2\
    \ * N - 1, Monoid::identity());\n    std::copy(dat_.begin(), dat_.end(), dat.begin()\
    \ + N - 1);\n    for (int i = N - 2; i >= 0; i--) {\n      dat[i] = Monoid::merge(dat[2\
    \ * i + 1], dat[2 * i + 2]);\n    }\n  }\n\n  int size() { return N_; }\n\n  void\
    \ update(int key, T val) {\n    assert(0 <= key && key < N_);\n\n    key += N\
    \ - 1;\n    dat[key] = val;\n\n    while (key > 0) {\n      key = (key - 1) /\
    \ 2;\n      dat[key] =\n          Monoid::merge(dat[2 * key + 1], dat[2 * key\
    \ + 2]);  // rewrite here\n    }\n  }\n\n  inline const T &operator[](const int\
    \ k) const { return dat.at(N - 1 + k); }\n  inline T &operator[](const int k)\
    \ { return dat.at(N - 1 + k); }\n\n  T query(int low, int high) const {\n    T\
    \ left_ret = Monoid::identity(), right_ret = Monoid::identity();\n    for (low\
    \ += N, high += N; low < high; low >>= 1, high >>= 1) {\n      if (low & 1) {\n\
    \        left_ret = Monoid::merge(left_ret, dat[low - 1]);\n        low++;\n \
    \     }\n      if (high & 1) {\n        high--;\n        right_ret = Monoid::merge(dat[high\
    \ - 1], right_ret);\n      }\n    }\n    return Monoid::merge(left_ret, right_ret);\n\
    \  }\n};\n\ntemplate <typename T>\nstruct RangeMinQuery {\n  using type = std::pair<T,\
    \ int>;\n  static type identity() {\n    return std::make_pair(std::numeric_limits<T>::max(),\
    \ 0);\n  }\n  static type merge(const type &l, const type &r) { return std::min(l,\
    \ r); }\n};\n\ntemplate <typename T>\nstruct Edge {\n  int src, dst;\n  T weight;\n\
    \n  Edge(int src, int dst, T weight) : src(src), dst(dst), weight(weight) {}\n\
    \n  bool operator<(const Edge<T> &e) const { return weight < e.weight; }\n};\n\
    \ntemplate <typename T>\nstruct Graph {\n  int V;\n  std::vector<Edge<T>> E;\n\
    \n  Graph(int V) : V(V) {}\n\n  void add_edge(int src, int dst, T weight) {\n\
    \    E.emplace_back(src, dst, weight);\n  }\n};\n\nstruct DisjointSet {\n  std::vector<int>\
    \ parent, rank;\n\n  DisjointSet(int N) {\n    parent.resize(N), rank.resize(N,\
    \ 0);\n    for (int i = 0; i < N; i++) parent[i] = i;\n  }\n\n  int find(int x)\
    \ {\n    if (parent[x] == x) {\n      return x;\n    } else {\n      return parent[x]\
    \ = find(parent[x]);\n    }\n  }\n\n  void unite(int x, int y) {\n    x = find(x),\
    \ y = find(y);\n    if (x == y) return;\n    if (rank[x] < rank[y]) {\n      parent[x]\
    \ = y;\n    } else {\n      parent[y] = x;\n      if (rank[x] == rank[y]) rank[x]++;\n\
    \    }\n  }\n\n  bool same(int x, int y) { return find(x) == find(y); }\n};\n\n\
    template <typename T>\nstruct MinimumSpanningTree {\n  Graph<T> g;\n  std::vector<Edge<T>>\
    \ mst;\n  T mincost;\n\n  MinimumSpanningTree(const Graph<T> &g) : g(g) {}\n\n\
    \  T run() {\n    mincost = 0;\n    sort(g.E.begin(), g.E.end());\n\n    DisjointSet\
    \ uf(g.V);\n\n    for (int i = 0, edge_count = g.V - 1; edge_count; i++) {\n \
    \     assert(i < (int)g.E.size());\n      Edge<T> e = g.E[i];\n      if (!uf.same(e.src,\
    \ e.dst)) {\n        uf.unite(e.src, e.dst);\n        mst.emplace_back(e);\n \
    \       mincost += e.weight;\n        edge_count--;\n      }\n    }\n    return\
    \ mincost;\n  }\n};\n\ntemplate <typename T>\nstruct ManhattanMinimumSpanningTree\
    \ {\n  int N;\n  std::vector<std::pair<T, T>> points;\n  Graph<T> graph;\n  std::vector<Edge<T>>\
    \ mst;\n  T mincost;\n\n  ManhattanMinimumSpanningTree(std::vector<std::pair<T,\
    \ T>> &points)\n      : N(points.size()), points(points), graph(N) {}\n\n  void\
    \ line_sweep() {\n    std::vector<int> ids(N);\n    std::iota(ids.begin(), ids.end(),\
    \ 0);\n\n    std::sort(ids.begin(), ids.end(), [&](int i, int j) {\n      return\
    \ (points[i].second - points[i].first <\n              points[j].second - points[j].first)\
    \ ||\n             (points[i].second - points[i].first ==\n                  points[j].second\
    \ - points[j].first &&\n              points[i].second > points[j].second) ||\n\
    \             (points[i].second - points[i].first ==\n                  points[j].second\
    \ - points[j].first &&\n              points[i].second == points[j].second &&\
    \ i > j);\n    });\n\n    std::vector<std::tuple<T, T, int>> y_idx;\n    for (int\
    \ i = 0; i < N; i++) {\n      int x, y;\n      std::tie(x, y) = points[i];\n \
    \     y_idx.emplace_back(y, x, i);\n    }\n    std::sort(y_idx.begin(), y_idx.end());\n\
    \n    // ids -> \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3067\u7BA1\u7406\u3059\u308B\
    \u5217\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n    std::vector<int> idx_to_idx(N);\n\
    \    for (int i = 0; i < N; i++) {\n      idx_to_idx[std::get<2>(y_idx[i])] =\
    \ i;\n    }\n\n    // \u30A4\u30D9\u30F3\u30C8\u70B9\u3054\u3068\u306E\u51E6\u7406\
    \n    SegmentTree<RangeMinQuery<T>> segt(N);\n    for (int i = 0; i < N; i++)\
    \ {\n      auto res = segt.query(idx_to_idx[ids[i]], N);\n      if (res != RangeMinQuery<T>::identity())\
    \ {\n        int idx;\n        std::tie(std::ignore, idx) = res;\n        T dist\
    \ = std::abs(points[ids[i]].first - points[idx].first) +\n                 std::abs(points[ids[i]].second\
    \ - points[idx].second);\n        graph.add_edge(ids[i], idx, dist);\n      }\n\
    \      segt.update(\n          idx_to_idx[ids[i]],\n          std::make_pair(points[ids[i]].first\
    \ + points[ids[i]].second, ids[i]));\n    }\n  }\n\n  void create_graph() {\n\
    \    for (int s = 0; s < 2; s++) {\n      for (int t = 0; t < 2; t++) {\n    \
    \    for (int u = 0; u < 2; u++) {\n          line_sweep();\n\n          for (auto\
    \ &p : points) std::swap(p.first, p.second);\n        }\n        for (auto &p\
    \ : points) p.first = -p.first;\n      }\n      for (auto &p : points) p.second\
    \ = -p.second;\n    }\n  }\n\n  T run() {\n    create_graph();\n    MinimumSpanningTree<T>\
    \ mst_(graph);\n    mincost = mst_.run();\n    mst = mst_.mst;\n    return mincost;\n\
    \  }\n};\n\nvoid yosupo() {\n  // https://judge.yosupo.jp/problem/manhattanmst\n\
    \  int N;\n  std::cin >> N;\n  std::vector<std::pair<long long, long long>> points;\n\
    \  for (int i = 0; i < N; i++) {\n    long long x, y;\n    std::cin >> x >> y;\n\
    \    points.emplace_back(x, y);\n  }\n  ManhattanMinimumSpanningTree<long long>\
    \ mst(points);\n  std::cout << mst.run() << '\\n';\n  for (auto &e : mst.mst)\
    \ {\n    std::cout << e.src << ' ' << e.dst << '\\n';\n  }\n}\n\nint main() {\n\
    \  std::cin.tie(0);\n  std::ios_base::sync_with_stdio(false);\n\n  yosupo();\n\
    \  return 0;\n}\n"
  code: "#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include <limits>\n\
    #include <numeric>\n#include <tuple>\n#include <utility>\n#include <vector>\n\n\
    template <class Monoid>\nstruct SegmentTree {\n  using T = typename Monoid::type;\n\
    \  int N_, N;\n  std::vector<T> dat;\n\n  SegmentTree(const int N_) : N_(N_) {\n\
    \    assert(N_ > 0);\n    N = 1;\n    while (N < N_) {\n      N <<= 1;\n    }\n\
    \    dat.assign(2 * N - 1, Monoid::identity());\n  }\n\n  SegmentTree(const std::vector<T>\
    \ &dat_) : N_(dat_.size()) {\n    assert(N_ > 0);\n    N = 1;\n    while (N <\
    \ N_) {\n      N <<= 1;\n    }\n    dat.assign(2 * N - 1, Monoid::identity());\n\
    \    std::copy(dat_.begin(), dat_.end(), dat.begin() + N - 1);\n    for (int i\
    \ = N - 2; i >= 0; i--) {\n      dat[i] = Monoid::merge(dat[2 * i + 1], dat[2\
    \ * i + 2]);\n    }\n  }\n\n  int size() { return N_; }\n\n  void update(int key,\
    \ T val) {\n    assert(0 <= key && key < N_);\n\n    key += N - 1;\n    dat[key]\
    \ = val;\n\n    while (key > 0) {\n      key = (key - 1) / 2;\n      dat[key]\
    \ =\n          Monoid::merge(dat[2 * key + 1], dat[2 * key + 2]);  // rewrite\
    \ here\n    }\n  }\n\n  inline const T &operator[](const int k) const { return\
    \ dat.at(N - 1 + k); }\n  inline T &operator[](const int k) { return dat.at(N\
    \ - 1 + k); }\n\n  T query(int low, int high) const {\n    T left_ret = Monoid::identity(),\
    \ right_ret = Monoid::identity();\n    for (low += N, high += N; low < high; low\
    \ >>= 1, high >>= 1) {\n      if (low & 1) {\n        left_ret = Monoid::merge(left_ret,\
    \ dat[low - 1]);\n        low++;\n      }\n      if (high & 1) {\n        high--;\n\
    \        right_ret = Monoid::merge(dat[high - 1], right_ret);\n      }\n    }\n\
    \    return Monoid::merge(left_ret, right_ret);\n  }\n};\n\ntemplate <typename\
    \ T>\nstruct RangeMinQuery {\n  using type = std::pair<T, int>;\n  static type\
    \ identity() {\n    return std::make_pair(std::numeric_limits<T>::max(), 0);\n\
    \  }\n  static type merge(const type &l, const type &r) { return std::min(l, r);\
    \ }\n};\n\ntemplate <typename T>\nstruct Edge {\n  int src, dst;\n  T weight;\n\
    \n  Edge(int src, int dst, T weight) : src(src), dst(dst), weight(weight) {}\n\
    \n  bool operator<(const Edge<T> &e) const { return weight < e.weight; }\n};\n\
    \ntemplate <typename T>\nstruct Graph {\n  int V;\n  std::vector<Edge<T>> E;\n\
    \n  Graph(int V) : V(V) {}\n\n  void add_edge(int src, int dst, T weight) {\n\
    \    E.emplace_back(src, dst, weight);\n  }\n};\n\nstruct DisjointSet {\n  std::vector<int>\
    \ parent, rank;\n\n  DisjointSet(int N) {\n    parent.resize(N), rank.resize(N,\
    \ 0);\n    for (int i = 0; i < N; i++) parent[i] = i;\n  }\n\n  int find(int x)\
    \ {\n    if (parent[x] == x) {\n      return x;\n    } else {\n      return parent[x]\
    \ = find(parent[x]);\n    }\n  }\n\n  void unite(int x, int y) {\n    x = find(x),\
    \ y = find(y);\n    if (x == y) return;\n    if (rank[x] < rank[y]) {\n      parent[x]\
    \ = y;\n    } else {\n      parent[y] = x;\n      if (rank[x] == rank[y]) rank[x]++;\n\
    \    }\n  }\n\n  bool same(int x, int y) { return find(x) == find(y); }\n};\n\n\
    template <typename T>\nstruct MinimumSpanningTree {\n  Graph<T> g;\n  std::vector<Edge<T>>\
    \ mst;\n  T mincost;\n\n  MinimumSpanningTree(const Graph<T> &g) : g(g) {}\n\n\
    \  T run() {\n    mincost = 0;\n    sort(g.E.begin(), g.E.end());\n\n    DisjointSet\
    \ uf(g.V);\n\n    for (int i = 0, edge_count = g.V - 1; edge_count; i++) {\n \
    \     assert(i < (int)g.E.size());\n      Edge<T> e = g.E[i];\n      if (!uf.same(e.src,\
    \ e.dst)) {\n        uf.unite(e.src, e.dst);\n        mst.emplace_back(e);\n \
    \       mincost += e.weight;\n        edge_count--;\n      }\n    }\n    return\
    \ mincost;\n  }\n};\n\ntemplate <typename T>\nstruct ManhattanMinimumSpanningTree\
    \ {\n  int N;\n  std::vector<std::pair<T, T>> points;\n  Graph<T> graph;\n  std::vector<Edge<T>>\
    \ mst;\n  T mincost;\n\n  ManhattanMinimumSpanningTree(std::vector<std::pair<T,\
    \ T>> &points)\n      : N(points.size()), points(points), graph(N) {}\n\n  void\
    \ line_sweep() {\n    std::vector<int> ids(N);\n    std::iota(ids.begin(), ids.end(),\
    \ 0);\n\n    std::sort(ids.begin(), ids.end(), [&](int i, int j) {\n      return\
    \ (points[i].second - points[i].first <\n              points[j].second - points[j].first)\
    \ ||\n             (points[i].second - points[i].first ==\n                  points[j].second\
    \ - points[j].first &&\n              points[i].second > points[j].second) ||\n\
    \             (points[i].second - points[i].first ==\n                  points[j].second\
    \ - points[j].first &&\n              points[i].second == points[j].second &&\
    \ i > j);\n    });\n\n    std::vector<std::tuple<T, T, int>> y_idx;\n    for (int\
    \ i = 0; i < N; i++) {\n      int x, y;\n      std::tie(x, y) = points[i];\n \
    \     y_idx.emplace_back(y, x, i);\n    }\n    std::sort(y_idx.begin(), y_idx.end());\n\
    \n    // ids -> \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3067\u7BA1\u7406\u3059\u308B\
    \u5217\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n    std::vector<int> idx_to_idx(N);\n\
    \    for (int i = 0; i < N; i++) {\n      idx_to_idx[std::get<2>(y_idx[i])] =\
    \ i;\n    }\n\n    // \u30A4\u30D9\u30F3\u30C8\u70B9\u3054\u3068\u306E\u51E6\u7406\
    \n    SegmentTree<RangeMinQuery<T>> segt(N);\n    for (int i = 0; i < N; i++)\
    \ {\n      auto res = segt.query(idx_to_idx[ids[i]], N);\n      if (res != RangeMinQuery<T>::identity())\
    \ {\n        int idx;\n        std::tie(std::ignore, idx) = res;\n        T dist\
    \ = std::abs(points[ids[i]].first - points[idx].first) +\n                 std::abs(points[ids[i]].second\
    \ - points[idx].second);\n        graph.add_edge(ids[i], idx, dist);\n      }\n\
    \      segt.update(\n          idx_to_idx[ids[i]],\n          std::make_pair(points[ids[i]].first\
    \ + points[ids[i]].second, ids[i]));\n    }\n  }\n\n  void create_graph() {\n\
    \    for (int s = 0; s < 2; s++) {\n      for (int t = 0; t < 2; t++) {\n    \
    \    for (int u = 0; u < 2; u++) {\n          line_sweep();\n\n          for (auto\
    \ &p : points) std::swap(p.first, p.second);\n        }\n        for (auto &p\
    \ : points) p.first = -p.first;\n      }\n      for (auto &p : points) p.second\
    \ = -p.second;\n    }\n  }\n\n  T run() {\n    create_graph();\n    MinimumSpanningTree<T>\
    \ mst_(graph);\n    mincost = mst_.run();\n    mst = mst_.mst;\n    return mincost;\n\
    \  }\n};\n\nvoid yosupo() {\n  // https://judge.yosupo.jp/problem/manhattanmst\n\
    \  int N;\n  std::cin >> N;\n  std::vector<std::pair<long long, long long>> points;\n\
    \  for (int i = 0; i < N; i++) {\n    long long x, y;\n    std::cin >> x >> y;\n\
    \    points.emplace_back(x, y);\n  }\n  ManhattanMinimumSpanningTree<long long>\
    \ mst(points);\n  std::cout << mst.run() << '\\n';\n  for (auto &e : mst.mst)\
    \ {\n    std::cout << e.src << ' ' << e.dst << '\\n';\n  }\n}\n\nint main() {\n\
    \  std::cin.tie(0);\n  std::ios_base::sync_with_stdio(false);\n\n  yosupo();\n\
    \  return 0;\n}\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: c++-library/manhattan_mst.cpp
  requiredBy: []
  timestamp: '2020-09-08 04:11:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: c++-library/manhattan_mst.cpp
layout: document
redirect_from:
- /library/c++-library/manhattan_mst.cpp
- /library/c++-library/manhattan_mst.cpp.html
title: c++-library/manhattan_mst.cpp
---
