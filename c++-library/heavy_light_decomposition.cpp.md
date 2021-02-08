---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    - https://judge.yosupo.jp/problem/vertex_set_path_composite
  bundledCode: "#line 1 \"c++-library/heavy_light_decomposition.cpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <iostream>\n#include <queue>\n#include <stack>\n\
    #include <tuple>\n#include <utility>\n#include <vector>\n\ntemplate <std::uint_fast64_t\
    \ Modulus = 1'000'000'007>\nclass ModInt {\n  using u64 = std::uint_fast64_t;\n\
    \n public:\n  using type = ModInt;\n\n  u64 a;\n\n  constexpr ModInt(const u64\
    \ x = 0) noexcept : a(x % Modulus) {}\n  constexpr u64 &value() noexcept { return\
    \ a; }\n  constexpr const u64 &value() const noexcept { return a; }\n  constexpr\
    \ ModInt operator+(const ModInt rhs) const noexcept {\n    return ModInt(*this)\
    \ += rhs;\n  }\n  constexpr ModInt operator*(const ModInt rhs) const noexcept\
    \ {\n    return ModInt(*this) *= rhs;\n  }\n  constexpr ModInt &operator+=(const\
    \ ModInt rhs) noexcept {\n    a += rhs.a;\n    if (a >= Modulus) {\n      a -=\
    \ Modulus;\n    }\n    return *this;\n  }\n\n  constexpr ModInt &operator*=(const\
    \ ModInt rhs) noexcept {\n    a = a * rhs.a % Modulus;\n    return *this;\n  }\n\
    \n  friend constexpr std::ostream &operator<<(std::ostream &os,\n            \
    \                                const ModInt &x) noexcept {\n    return os <<\
    \ x.a;\n  }\n\n  static ModInt identity_zero() { return ModInt(0); }\n  static\
    \ ModInt identity_one() { return ModInt(1); }\n};\n\ntemplate <typename Semiring>\n\
    struct Matrix {\n  using T = typename Semiring::type;\n  size_t n_row, n_col;\n\
    \  T zero = Semiring::identity_zero(), one = Semiring::identity_one();\n  std::vector<std::vector<T>>\
    \ data;\n\n  Matrix() {}\n  Matrix(size_t n, size_t m)\n      : n_row(n), n_col(m),\
    \ data(n, std::vector<T>(m, zero)) {}\n  Matrix(size_t n) : n_row(n), n_col(n),\
    \ data(n, std::vector<T>(n, zero)) {}\n  Matrix(std::vector<std::vector<T>> &arr)\
    \ : n_row(arr.size()) {\n    n_col = arr.size() ? arr[0].size() : 0;\n    data.resize(n_row);\n\
    \    for (size_t row = 0; row < n_row; row++) data[row] = arr[row];\n  }\n\n \
    \ inline const std::vector<T> &operator[](const int k) const {\n    return data.at(k);\n\
    \  }\n  inline std::vector<T> &operator[](const int k) { return data.at(k); }\n\
    \n  static Matrix<Semiring> identity(size_t n) {\n    Matrix<Semiring> mat(n);\n\
    \    for (size_t i = 0; i < n; i++) mat[i][i] = Semiring::identity_one();\n  \
    \  return mat;\n  }\n};\n\ntemplate <typename Semiring>\nMatrix<Semiring> operator*(const\
    \ Matrix<Semiring> &A,\n                           const Matrix<Semiring> &B)\
    \ {\n  size_t n = A.n_row, m = B.n_col, p = A.n_col;\n  assert(p == B.n_row);\n\
    \  Matrix<Semiring> C(n, m);\n  for (size_t i = 0; i < n; i++)\n    for (size_t\
    \ j = 0; j < m; j++)\n      for (size_t k = 0; k < p; k++) C[i][j] = (C[i][j]\
    \ + A[i][k] * B[k][j]);\n  return C;\n}\n\ntemplate <class Monoid>\nstruct SegmentTree\
    \ {\n  using T = typename Monoid::type;\n  int N_, N;\n  std::vector<T> dat;\n\
    \n  SegmentTree(const int N_) : N_(N_) {\n    assert(N_ > 0);\n    N = 1;\n  \
    \  while (N < N_) {\n      N <<= 1;\n    }\n    dat.assign(2 * N - 1, Monoid::identity());\n\
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
    \  }\n};\n\ntemplate <typename T>\nstruct RangeSumQuery {\n  using type = T;\n\
    \  static type identity() { return T(0); }\n  static type merge(const type &l,\
    \ const type &r) { return l + r; }\n};\n\ntemplate <typename T>\nstruct RangeMinQuery\
    \ {\n  using type = T;\n  static type identity() { return std::numeric_limits<T>::max();\
    \ }\n  static type merge(const type &l, const type &r) { return std::min(l, r);\
    \ }\n};\n\ntemplate <typename T>\nstruct RangeMaxQuery {\n  using type = T;\n\
    \  static type identity() { return T(0); }\n  static type merge(const type &l,\
    \ const type &r) { return std::max(l, r); }\n};\n\ntemplate <typename T>\nstruct\
    \ RangeMatrixMult {\n  using type = T;\n  static type identity() { return T::identity(2);\
    \ }\n  static type merge(const type &l, const type &r) { return l * r; }\n};\n\
    \n// graph by adjacency list\ntemplate <typename T>\nstruct Edge {\n  int dst;\n\
    \  T weight;\n  Edge(int dst, T weight) : dst(dst), weight(weight) {}\n  bool\
    \ operator<(const Edge<T> &e) const { return weight > e.weight; }\n};\n\ntemplate\
    \ <typename T>\nstruct Graph {\n  int V;\n  std::vector<std::vector<Edge<T>>>\
    \ E;\n  Graph(int V) : V(V) { E.resize(V); }\n  void add_edge(int src, int dst,\
    \ T weight) {\n    E[src].emplace_back(dst, weight);\n  }\n};\n\ntemplate <typename\
    \ T>\nstruct HeavyLightDecomposition {\n  const Graph<T> g;\n  // vid: \u65B0\u3057\
    \u3044\u9802\u70B9\u756A\u53F7\u3002root \u304B\u3089 heavy \u679D\u3067\u7E4B\
    \u304C\u308B\u9802\u70B9\u306B\u512A\u5148\u3057\u3066\n  // \u756A\u53F7\u304C\
    \u4ED8\u3051\u3089\u308C\u3001\u3055\u3089\u306B root \u306B\u8FD1\u3044\u9802\
    \u70B9\u306B\u7E4B\u304C\u308B\u90E8\u5206\u6728\u3067\u540C\u3058\u3053\u3068\
    \u304C\u884C\u308F\u308C\u308B\n  // heavy: \u5404\u9802\u70B9\u306B\u5BFE\u3059\
    \u308B heavy \u679D\u306E\u7AEF\u70B9\n  // head: heavy \u679D\u3067\u7E4B\u304C\
    \u308B\u9802\u70B9\u306E\u3046\u3061\u6700\u3082 root \u306B\u8FD1\u3044\u9802\
    \u70B9\n  // parent: \u5404\u9802\u70B9\u306E\u89AA\u9802\u70B9\n  // tail:\n\
    \  std::vector<int> vid, head, heavy, parent, tail;\n  HeavyLightDecomposition(const\
    \ Graph<T> &g, const int root = 0,\n                          const bool need_subtree\
    \ = false)\n      : g(g), vid(g.V, -1), head(g.V), heavy(g.V, -1), parent(g.V),\
    \ tail(g.V) {\n    dfs(root, -1);\n    need_subtree ? dfs2(root) : bfs(root);\n\
    \  }\n\n  int dfs(const int v, const int par) {\n    // \u90E8\u5206\u6728\u306E\
    \u9802\u70B9\u306E\u6570\u3092\u6C42\u3081\u3066\u3001\u6700\u5927\u306E\u90E8\
    \u5206\u6728\u306E\u679D\u3092 heavy \u3068\u3059\u308B\n    // \u5B9F\u88C5\u4E0A\
    \u306F\u9802\u70B9\u3054\u3068\u306B heavy \u3068\u306A\u308B\u679D\u306E\u7AEF\
    \u70B9\u3092\u6301\u3063\u3066\u304A\u304F\n    parent[v] = par;\n    int sub\
    \ = 1, max_sub = 0;\n    for (Edge<T> child : g.E[v]) {\n      if (child.dst !=\
    \ par) {\n        int child_sub = dfs(child.dst, v);\n        sub += child_sub;\n\
    \        if (child_sub > max_sub) {\n          max_sub = child_sub;\n        \
    \  heavy[v] = child.dst;\n        }\n      }\n    }\n    return sub;\n  }\n\n\
    \  void bfs(const int root = 0) {\n    // heavy \u679D\u3067\u3064\u306A\u304C\
    \u308B\u9802\u70B9\u304B\u3089\u756A\u53F7\u3092\u5272\u308A\u632F\u3063\u3066\
    \u3044\u304F\n    int k = 0;\n    std::queue<int> que({root});\n    while (not\
    \ que.empty()) {\n      int r = que.front();\n      que.pop();\n      for (int\
    \ v = r; v != -1; v = heavy[v]) {\n        vid[v] = k++;\n        head[v] = r;\n\
    \        for (Edge<T> child : g.E[v]) {\n          if (child.dst != parent[v]\
    \ and child.dst != heavy[v])\n            que.emplace(child.dst);\n        }\n\
    \      }\n    }\n  }\n\n  void dfs2(const int root = 0) {\n    std::stack<std::pair<int,\
    \ int>> st;\n    st.emplace(root, 0);\n    int k = 0;\n\n    while (not st.empty())\
    \ {\n      int v, state;\n      std::tie(v, state) = st.top();\n      st.pop();\n\
    \      if (state == 0) {\n        // heavy \u679D\u3067\u7D50\u3070\u308C\u305F\
    \u9802\u70B9\u306E push\n        for (int u = v; u != -1; u = heavy[u]) {\n  \
    \        vid[u] = k++;\n          head[u] = v;\n          st.emplace(u, 1);\n\
    \        }\n      } else if (state == 1) {\n        // heavy \u679D\u4EE5\u5916\
    \u3067\u7D50\u3070\u308C\u305F\u9802\u70B9\u306E push\n        st.emplace(v, 2);\n\
    \        for (Edge<T> child : g.E[v]) {\n          if (child.dst != parent[v]\
    \ and child.dst != heavy[v]) {\n            st.emplace(child.dst, 0);\n      \
    \    }\n        }\n      } else if (state == 2) {\n        // tail \u306E\u8A18\
    \u9332\n        tail[v] = k;\n      }\n    }\n  }\n\n  int lca(int u, int v) const\
    \ {\n    while (head[u] != head[v]) {\n      if (vid[u] > vid[v]) std::swap(u,\
    \ v);\n      v = parent[head[v]];\n    }\n    if (vid[u] > vid[v]) std::swap(u,\
    \ v);\n    return u;\n  }\n\n  template <typename Ret, typename Query, typename\
    \ Merge>\n  Ret query_path(int u, int v, const Ret &one, const Query &query,\n\
    \                 const Merge &merge, bool edge = false) const {\n    // u, v\
    \ \u306E\u9593\u306E\u30D1\u30B9\u306B\u5BFE\u3059\u308B\u30AF\u30A8\u30EA\u3092\
    \u8A08\u7B97\u3059\u308B\n    // one \u306F\u5358\u4F4D\u5143\u3001query \u306F\
    \u5217\u306B\u5BFE\u3059\u308B\u30AF\u30A8\u30EA\u3001merge \u306F\u30DE\u30FC\
    \u30B8\u3059\u308B\u6F14\u7B97\n    Ret left = one, right = one;\n    for (;;\
    \ v = parent[head[v]]) {\n      if (vid[u] > vid[v]) std::swap(u, v), std::swap(left,\
    \ right);\n      if (head[u] == head[v]) break;\n      left = merge(query(vid[head[v]],\
    \ vid[v] + 1), left);\n    }\n    return merge(merge(query(vid[u] + edge, vid[v]\
    \ + 1), left), right);\n  }\n\n  template <typename Q>\n  void add(int u, int\
    \ v, const Q &q, bool edge = false) {\n    for (;; v = parent[head[v]]) {\n  \
    \    if (vid[u] > vid[v]) std::swap(u, v);\n      if (head[u] == head[v]) break;\n\
    \      q(vid[head[v]], vid[v] + 1);\n    }\n    q(vid[u] + edge, vid[v] + 1);\n\
    \  }\n};\n\nvoid yosupo() {\n  int N, Q;\n  std::cin >> N >> Q;\n  Graph<int>\
    \ g(N);\n  for (int i = 1; i < N; i++) {\n    int p;\n    std::cin >> p;\n   \
    \ g.add_edge(p, i, 1);\n  }\n\n  HeavyLightDecomposition<int> hld(g);\n  for (int\
    \ i = 0; i < Q; i++) {\n    int u, v;\n    std::cin >> u >> v;\n    std::cout\
    \ << hld.lca(u, v) << '\\n';\n  }\n}\n\nvoid spoj_qtree() {\n  int T;\n  std::cin\
    \ >> T;\n  for (int t = 0; t < T; t++) {\n    int N;\n    std::cin >> N;\n   \
    \ Graph<int> g(N);\n    std::vector<std::tuple<int, int, int>> edges(N - 1);\n\
    \    for (int i = 0; i < N - 1; i++) {\n      int a, b, w;\n      std::cin >>\
    \ a >> b >> w;\n      a--, b--;\n      edges[i] = std::make_tuple(a, b, w);\n\
    \      g.add_edge(a, b, w);\n      g.add_edge(b, a, w);\n    }\n    HeavyLightDecomposition<int>\
    \ hld(g);\n    SegmentTree<RangeMaxQuery<int>> rmq(N);\n    for (auto &&e : edges)\
    \ {\n      int a, b, w;\n      std::tie(a, b, w) = e;\n      rmq.update(std::max(hld.vid[a],\
    \ hld.vid[b]), w);\n    }\n\n    while (true) {\n      std::string s;\n      std::cin\
    \ >> s;\n      if (s == \"DONE\") break;\n      if (s == \"QUERY\") {\n      \
    \  int a, b;\n        std::cin >> a >> b;\n        a--, b--;\n        std::cout\
    \ << hld.query_path(\n                         a, b, 0, [&](int a, int b) { return\
    \ rmq.query(a, b); },\n                         RangeMaxQuery<int>::merge, true)\n\
    \                  << '\\n';\n      } else {\n        int idx, w;\n        std::cin\
    \ >> idx >> w;\n        idx--;\n        int a, b;\n        std::tie(a, b, std::ignore)\
    \ = edges[idx];\n        rmq.update(std::max(hld.vid[a], hld.vid[b]), w);\n  \
    \    }\n    }\n  }\n}\n\nvoid yosupo2() {\n  // https://judge.yosupo.jp/problem/vertex_add_path_sum\n\
    \  int N, Q;\n  std::cin >> N >> Q;\n  std::vector<long long> weights(N);\n  for\
    \ (int i = 0; i < N; i++) std::cin >> weights[i];\n  Graph<int> g(N);\n  for (int\
    \ i = 0; i < N - 1; i++) {\n    int u, v;\n    std::cin >> u >> v;\n    g.add_edge(u,\
    \ v, 1);\n    g.add_edge(v, u, 1);\n  }\n  HeavyLightDecomposition<int> hld(g);\n\
    \  SegmentTree<RangeSumQuery<long long>> rsq(N);\n  for (int i = 0; i < N; i++)\
    \ {\n    rsq.update(hld.vid[i], weights[i]);\n  }\n  for (int i = 0; i < Q; i++)\
    \ {\n    int t;\n    long long a, b;\n    std::cin >> t >> a >> b;\n    if (t\
    \ == 0) {\n      rsq.update(hld.vid[a], rsq[hld.vid[a]] + b);\n    } else {\n\
    \      std::cout << hld.query_path(\n                       a, b, 0LL, [&](int\
    \ a, int b) { return rsq.query(a, b); },\n                       RangeSumQuery<long\
    \ long>::merge)\n                << '\\n';\n    }\n  }\n}\n\nvoid yosupo3() {\n\
    \  // https://judge.yosupo.jp/problem/vertex_add_subtree_sum\n  int N, Q;\n  std::cin\
    \ >> N >> Q;\n  std::vector<long long> weights(N);\n  for (int i = 0; i < N; i++)\
    \ std::cin >> weights[i];\n  Graph<int> g(N);\n  for (int i = 0; i < N - 1; i++)\
    \ {\n    int p;\n    std::cin >> p;\n    g.add_edge(p, i + 1, 1);\n    g.add_edge(i\
    \ + 1, p, 1);\n  }\n  HeavyLightDecomposition<int> hld(g, 0, true);\n  SegmentTree<RangeSumQuery<long\
    \ long>> rsq(N);\n  for (int i = 0; i < N; i++) {\n    rsq.update(hld.vid[i],\
    \ weights[i]);\n  }\n  for (int i = 0; i < Q; i++) {\n    int t;\n    std::cin\
    \ >> t;\n    if (t == 0) {\n      int u;\n      long long x;\n      std::cin >>\
    \ u >> x;\n      rsq.update(hld.vid[u], rsq[hld.vid[u]] + x);\n    } else {\n\
    \      int u;\n      std::cin >> u;\n      std::cout << rsq.query(hld.vid[u],\
    \ hld.tail[u]) << '\\n';\n    }\n  }\n}\n\ntemplate <typename T>\nstruct RangeCompositeQuery\
    \ {\n  using type = std::pair<T, T>;\n  static type identity() { return type{1,\
    \ 0}; }\n  static type merge(const type &l, const type &r) {\n    return type{l.first\
    \ * r.first, l.second * r.first + r.second};\n  }\n};\n\nusing mint = ModInt<998'244'353>;\n\
    using mint_p = std::pair<mint, mint>;\n\nvoid yosupo4() {\n  // https://judge.yosupo.jp/problem/vertex_set_path_composite\n\
    \  // \u901A\u3063\u3066\u3044\u306A\u3044\u3002\u591A\u5206 reverse \u304C\u3069\
    \u3046\u3068\u304B\u3002\n  int N, Q;\n  std::cin >> N >> Q;\n  std::vector<mint_p>\
    \ funcs;\n  funcs.reserve(N);\n  for (int i = 0; i < N; i++) {\n    int a, b;\n\
    \    std::cin >> a >> b;\n    funcs.emplace_back(mint(a), mint(b));\n  }\n\n \
    \ Graph<int> g(N);\n  for (int i = 0; i < N - 1; i++) {\n    int a, b;\n    std::cin\
    \ >> a >> b;\n    g.add_edge(a, b, 1);\n    g.add_edge(b, a, 1);\n  }\n  HeavyLightDecomposition<int>\
    \ hld(g);\n  SegmentTree<RangeCompositeQuery<mint>> rcq(N);\n  for (int i = 0;\
    \ i < N; i++) {\n    rcq.update(hld.vid[i], funcs[i]);\n  }\n\n  for (int i =\
    \ 0; i < Q; i++) {\n    int t, a, b, c;\n    std::cin >> t >> a >> b >> c;\n \
    \   if (t == 0) {\n      rcq.update(hld.vid[a], mint_p{b, c});\n    } else {\n\
    \      mint_p func = hld.query_path(\n          a, b, RangeCompositeQuery<mint>::identity(),\n\
    \          [&](int a, int b) { return rcq.query(a, b); },\n          RangeCompositeQuery<mint>::merge);\n\
    \      std::cout << func.first * c + func.second << '\\n';\n    }\n  }\n}\n\n\
    void yuki650() {\n  int N;\n  std::cin >> N;\n  Graph<int> g(N);\n  std::vector<std::pair<int,\
    \ int>> edges(N - 1);\n  for (int i = 0; i < N - 1; i++) {\n    int a, b;\n  \
    \  std::cin >> a >> b;\n    g.add_edge(a, b, 1);\n    g.add_edge(b, a, 1);\n \
    \   edges[i] = std::make_pair(a, b);\n  }\n  HeavyLightDecomposition<int> hld(g);\n\
    \  SegmentTree<RangeMatrixMult<Matrix<ModInt<>>>> segt(N);\n  int Q;\n  std::cin\
    \ >> Q;\n  for (int i = 0; i < Q; i++) {\n    char t;\n    std::cin >> t;\n  \
    \  if (t == 'x') {\n      int idx, x00, x01, x10, x11;\n      std::cin >> idx\
    \ >> x00 >> x01 >> x10 >> x11;\n      Matrix<ModInt<>> mat(2, 2);\n      mat[0][0]\
    \ = x00, mat[0][1] = x01, mat[1][0] = x10, mat[1][1] = x11;\n      int a, b;\n\
    \      std::tie(a, b) = edges[idx];\n      segt.update(std::max(hld.vid[a], hld.vid[b]),\
    \ mat);\n    } else {\n      int u, v;\n      std::cin >> u >> v;\n      Matrix<ModInt<>>\
    \ mat = Matrix<ModInt<>>::identity(2);\n      Matrix<ModInt<>> res = hld.query_path(\n\
    \          u, v, mat, [&](int a, int b) { return segt.query(a, b); },\n      \
    \    RangeMatrixMult<Matrix<ModInt<>>>::merge, true);\n      std::cout << res[0][0]\
    \ << ' ' << res[0][1] << ' ' << res[1][0] << ' '\n                << res[1][1]\
    \ << '\\n';\n    }\n  }\n}\n\nint main() {\n  std::cin.tie(0);\n  std::ios_base::sync_with_stdio(false);\n\
    \  // yosupo();\n  // spoj_qtree();\n  // yuki650();\n  // yosupo2();\n  // yosupo3();\n\
    \  yosupo4();\n  return 0;\n}\n"
  code: "#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include <queue>\n\
    #include <stack>\n#include <tuple>\n#include <utility>\n#include <vector>\n\n\
    template <std::uint_fast64_t Modulus = 1'000'000'007>\nclass ModInt {\n  using\
    \ u64 = std::uint_fast64_t;\n\n public:\n  using type = ModInt;\n\n  u64 a;\n\n\
    \  constexpr ModInt(const u64 x = 0) noexcept : a(x % Modulus) {}\n  constexpr\
    \ u64 &value() noexcept { return a; }\n  constexpr const u64 &value() const noexcept\
    \ { return a; }\n  constexpr ModInt operator+(const ModInt rhs) const noexcept\
    \ {\n    return ModInt(*this) += rhs;\n  }\n  constexpr ModInt operator*(const\
    \ ModInt rhs) const noexcept {\n    return ModInt(*this) *= rhs;\n  }\n  constexpr\
    \ ModInt &operator+=(const ModInt rhs) noexcept {\n    a += rhs.a;\n    if (a\
    \ >= Modulus) {\n      a -= Modulus;\n    }\n    return *this;\n  }\n\n  constexpr\
    \ ModInt &operator*=(const ModInt rhs) noexcept {\n    a = a * rhs.a % Modulus;\n\
    \    return *this;\n  }\n\n  friend constexpr std::ostream &operator<<(std::ostream\
    \ &os,\n                                            const ModInt &x) noexcept\
    \ {\n    return os << x.a;\n  }\n\n  static ModInt identity_zero() { return ModInt(0);\
    \ }\n  static ModInt identity_one() { return ModInt(1); }\n};\n\ntemplate <typename\
    \ Semiring>\nstruct Matrix {\n  using T = typename Semiring::type;\n  size_t n_row,\
    \ n_col;\n  T zero = Semiring::identity_zero(), one = Semiring::identity_one();\n\
    \  std::vector<std::vector<T>> data;\n\n  Matrix() {}\n  Matrix(size_t n, size_t\
    \ m)\n      : n_row(n), n_col(m), data(n, std::vector<T>(m, zero)) {}\n  Matrix(size_t\
    \ n) : n_row(n), n_col(n), data(n, std::vector<T>(n, zero)) {}\n  Matrix(std::vector<std::vector<T>>\
    \ &arr) : n_row(arr.size()) {\n    n_col = arr.size() ? arr[0].size() : 0;\n \
    \   data.resize(n_row);\n    for (size_t row = 0; row < n_row; row++) data[row]\
    \ = arr[row];\n  }\n\n  inline const std::vector<T> &operator[](const int k) const\
    \ {\n    return data.at(k);\n  }\n  inline std::vector<T> &operator[](const int\
    \ k) { return data.at(k); }\n\n  static Matrix<Semiring> identity(size_t n) {\n\
    \    Matrix<Semiring> mat(n);\n    for (size_t i = 0; i < n; i++) mat[i][i] =\
    \ Semiring::identity_one();\n    return mat;\n  }\n};\n\ntemplate <typename Semiring>\n\
    Matrix<Semiring> operator*(const Matrix<Semiring> &A,\n                      \
    \     const Matrix<Semiring> &B) {\n  size_t n = A.n_row, m = B.n_col, p = A.n_col;\n\
    \  assert(p == B.n_row);\n  Matrix<Semiring> C(n, m);\n  for (size_t i = 0; i\
    \ < n; i++)\n    for (size_t j = 0; j < m; j++)\n      for (size_t k = 0; k <\
    \ p; k++) C[i][j] = (C[i][j] + A[i][k] * B[k][j]);\n  return C;\n}\n\ntemplate\
    \ <class Monoid>\nstruct SegmentTree {\n  using T = typename Monoid::type;\n \
    \ int N_, N;\n  std::vector<T> dat;\n\n  SegmentTree(const int N_) : N_(N_) {\n\
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
    \ T>\nstruct RangeSumQuery {\n  using type = T;\n  static type identity() { return\
    \ T(0); }\n  static type merge(const type &l, const type &r) { return l + r; }\n\
    };\n\ntemplate <typename T>\nstruct RangeMinQuery {\n  using type = T;\n  static\
    \ type identity() { return std::numeric_limits<T>::max(); }\n  static type merge(const\
    \ type &l, const type &r) { return std::min(l, r); }\n};\n\ntemplate <typename\
    \ T>\nstruct RangeMaxQuery {\n  using type = T;\n  static type identity() { return\
    \ T(0); }\n  static type merge(const type &l, const type &r) { return std::max(l,\
    \ r); }\n};\n\ntemplate <typename T>\nstruct RangeMatrixMult {\n  using type =\
    \ T;\n  static type identity() { return T::identity(2); }\n  static type merge(const\
    \ type &l, const type &r) { return l * r; }\n};\n\n// graph by adjacency list\n\
    template <typename T>\nstruct Edge {\n  int dst;\n  T weight;\n  Edge(int dst,\
    \ T weight) : dst(dst), weight(weight) {}\n  bool operator<(const Edge<T> &e)\
    \ const { return weight > e.weight; }\n};\n\ntemplate <typename T>\nstruct Graph\
    \ {\n  int V;\n  std::vector<std::vector<Edge<T>>> E;\n  Graph(int V) : V(V) {\
    \ E.resize(V); }\n  void add_edge(int src, int dst, T weight) {\n    E[src].emplace_back(dst,\
    \ weight);\n  }\n};\n\ntemplate <typename T>\nstruct HeavyLightDecomposition {\n\
    \  const Graph<T> g;\n  // vid: \u65B0\u3057\u3044\u9802\u70B9\u756A\u53F7\u3002\
    root \u304B\u3089 heavy \u679D\u3067\u7E4B\u304C\u308B\u9802\u70B9\u306B\u512A\
    \u5148\u3057\u3066\n  // \u756A\u53F7\u304C\u4ED8\u3051\u3089\u308C\u3001\u3055\
    \u3089\u306B root \u306B\u8FD1\u3044\u9802\u70B9\u306B\u7E4B\u304C\u308B\u90E8\
    \u5206\u6728\u3067\u540C\u3058\u3053\u3068\u304C\u884C\u308F\u308C\u308B\n  //\
    \ heavy: \u5404\u9802\u70B9\u306B\u5BFE\u3059\u308B heavy \u679D\u306E\u7AEF\u70B9\
    \n  // head: heavy \u679D\u3067\u7E4B\u304C\u308B\u9802\u70B9\u306E\u3046\u3061\
    \u6700\u3082 root \u306B\u8FD1\u3044\u9802\u70B9\n  // parent: \u5404\u9802\u70B9\
    \u306E\u89AA\u9802\u70B9\n  // tail:\n  std::vector<int> vid, head, heavy, parent,\
    \ tail;\n  HeavyLightDecomposition(const Graph<T> &g, const int root = 0,\n  \
    \                        const bool need_subtree = false)\n      : g(g), vid(g.V,\
    \ -1), head(g.V), heavy(g.V, -1), parent(g.V), tail(g.V) {\n    dfs(root, -1);\n\
    \    need_subtree ? dfs2(root) : bfs(root);\n  }\n\n  int dfs(const int v, const\
    \ int par) {\n    // \u90E8\u5206\u6728\u306E\u9802\u70B9\u306E\u6570\u3092\u6C42\
    \u3081\u3066\u3001\u6700\u5927\u306E\u90E8\u5206\u6728\u306E\u679D\u3092 heavy\
    \ \u3068\u3059\u308B\n    // \u5B9F\u88C5\u4E0A\u306F\u9802\u70B9\u3054\u3068\u306B\
    \ heavy \u3068\u306A\u308B\u679D\u306E\u7AEF\u70B9\u3092\u6301\u3063\u3066\u304A\
    \u304F\n    parent[v] = par;\n    int sub = 1, max_sub = 0;\n    for (Edge<T>\
    \ child : g.E[v]) {\n      if (child.dst != par) {\n        int child_sub = dfs(child.dst,\
    \ v);\n        sub += child_sub;\n        if (child_sub > max_sub) {\n       \
    \   max_sub = child_sub;\n          heavy[v] = child.dst;\n        }\n      }\n\
    \    }\n    return sub;\n  }\n\n  void bfs(const int root = 0) {\n    // heavy\
    \ \u679D\u3067\u3064\u306A\u304C\u308B\u9802\u70B9\u304B\u3089\u756A\u53F7\u3092\
    \u5272\u308A\u632F\u3063\u3066\u3044\u304F\n    int k = 0;\n    std::queue<int>\
    \ que({root});\n    while (not que.empty()) {\n      int r = que.front();\n  \
    \    que.pop();\n      for (int v = r; v != -1; v = heavy[v]) {\n        vid[v]\
    \ = k++;\n        head[v] = r;\n        for (Edge<T> child : g.E[v]) {\n     \
    \     if (child.dst != parent[v] and child.dst != heavy[v])\n            que.emplace(child.dst);\n\
    \        }\n      }\n    }\n  }\n\n  void dfs2(const int root = 0) {\n    std::stack<std::pair<int,\
    \ int>> st;\n    st.emplace(root, 0);\n    int k = 0;\n\n    while (not st.empty())\
    \ {\n      int v, state;\n      std::tie(v, state) = st.top();\n      st.pop();\n\
    \      if (state == 0) {\n        // heavy \u679D\u3067\u7D50\u3070\u308C\u305F\
    \u9802\u70B9\u306E push\n        for (int u = v; u != -1; u = heavy[u]) {\n  \
    \        vid[u] = k++;\n          head[u] = v;\n          st.emplace(u, 1);\n\
    \        }\n      } else if (state == 1) {\n        // heavy \u679D\u4EE5\u5916\
    \u3067\u7D50\u3070\u308C\u305F\u9802\u70B9\u306E push\n        st.emplace(v, 2);\n\
    \        for (Edge<T> child : g.E[v]) {\n          if (child.dst != parent[v]\
    \ and child.dst != heavy[v]) {\n            st.emplace(child.dst, 0);\n      \
    \    }\n        }\n      } else if (state == 2) {\n        // tail \u306E\u8A18\
    \u9332\n        tail[v] = k;\n      }\n    }\n  }\n\n  int lca(int u, int v) const\
    \ {\n    while (head[u] != head[v]) {\n      if (vid[u] > vid[v]) std::swap(u,\
    \ v);\n      v = parent[head[v]];\n    }\n    if (vid[u] > vid[v]) std::swap(u,\
    \ v);\n    return u;\n  }\n\n  template <typename Ret, typename Query, typename\
    \ Merge>\n  Ret query_path(int u, int v, const Ret &one, const Query &query,\n\
    \                 const Merge &merge, bool edge = false) const {\n    // u, v\
    \ \u306E\u9593\u306E\u30D1\u30B9\u306B\u5BFE\u3059\u308B\u30AF\u30A8\u30EA\u3092\
    \u8A08\u7B97\u3059\u308B\n    // one \u306F\u5358\u4F4D\u5143\u3001query \u306F\
    \u5217\u306B\u5BFE\u3059\u308B\u30AF\u30A8\u30EA\u3001merge \u306F\u30DE\u30FC\
    \u30B8\u3059\u308B\u6F14\u7B97\n    Ret left = one, right = one;\n    for (;;\
    \ v = parent[head[v]]) {\n      if (vid[u] > vid[v]) std::swap(u, v), std::swap(left,\
    \ right);\n      if (head[u] == head[v]) break;\n      left = merge(query(vid[head[v]],\
    \ vid[v] + 1), left);\n    }\n    return merge(merge(query(vid[u] + edge, vid[v]\
    \ + 1), left), right);\n  }\n\n  template <typename Q>\n  void add(int u, int\
    \ v, const Q &q, bool edge = false) {\n    for (;; v = parent[head[v]]) {\n  \
    \    if (vid[u] > vid[v]) std::swap(u, v);\n      if (head[u] == head[v]) break;\n\
    \      q(vid[head[v]], vid[v] + 1);\n    }\n    q(vid[u] + edge, vid[v] + 1);\n\
    \  }\n};\n\nvoid yosupo() {\n  int N, Q;\n  std::cin >> N >> Q;\n  Graph<int>\
    \ g(N);\n  for (int i = 1; i < N; i++) {\n    int p;\n    std::cin >> p;\n   \
    \ g.add_edge(p, i, 1);\n  }\n\n  HeavyLightDecomposition<int> hld(g);\n  for (int\
    \ i = 0; i < Q; i++) {\n    int u, v;\n    std::cin >> u >> v;\n    std::cout\
    \ << hld.lca(u, v) << '\\n';\n  }\n}\n\nvoid spoj_qtree() {\n  int T;\n  std::cin\
    \ >> T;\n  for (int t = 0; t < T; t++) {\n    int N;\n    std::cin >> N;\n   \
    \ Graph<int> g(N);\n    std::vector<std::tuple<int, int, int>> edges(N - 1);\n\
    \    for (int i = 0; i < N - 1; i++) {\n      int a, b, w;\n      std::cin >>\
    \ a >> b >> w;\n      a--, b--;\n      edges[i] = std::make_tuple(a, b, w);\n\
    \      g.add_edge(a, b, w);\n      g.add_edge(b, a, w);\n    }\n    HeavyLightDecomposition<int>\
    \ hld(g);\n    SegmentTree<RangeMaxQuery<int>> rmq(N);\n    for (auto &&e : edges)\
    \ {\n      int a, b, w;\n      std::tie(a, b, w) = e;\n      rmq.update(std::max(hld.vid[a],\
    \ hld.vid[b]), w);\n    }\n\n    while (true) {\n      std::string s;\n      std::cin\
    \ >> s;\n      if (s == \"DONE\") break;\n      if (s == \"QUERY\") {\n      \
    \  int a, b;\n        std::cin >> a >> b;\n        a--, b--;\n        std::cout\
    \ << hld.query_path(\n                         a, b, 0, [&](int a, int b) { return\
    \ rmq.query(a, b); },\n                         RangeMaxQuery<int>::merge, true)\n\
    \                  << '\\n';\n      } else {\n        int idx, w;\n        std::cin\
    \ >> idx >> w;\n        idx--;\n        int a, b;\n        std::tie(a, b, std::ignore)\
    \ = edges[idx];\n        rmq.update(std::max(hld.vid[a], hld.vid[b]), w);\n  \
    \    }\n    }\n  }\n}\n\nvoid yosupo2() {\n  // https://judge.yosupo.jp/problem/vertex_add_path_sum\n\
    \  int N, Q;\n  std::cin >> N >> Q;\n  std::vector<long long> weights(N);\n  for\
    \ (int i = 0; i < N; i++) std::cin >> weights[i];\n  Graph<int> g(N);\n  for (int\
    \ i = 0; i < N - 1; i++) {\n    int u, v;\n    std::cin >> u >> v;\n    g.add_edge(u,\
    \ v, 1);\n    g.add_edge(v, u, 1);\n  }\n  HeavyLightDecomposition<int> hld(g);\n\
    \  SegmentTree<RangeSumQuery<long long>> rsq(N);\n  for (int i = 0; i < N; i++)\
    \ {\n    rsq.update(hld.vid[i], weights[i]);\n  }\n  for (int i = 0; i < Q; i++)\
    \ {\n    int t;\n    long long a, b;\n    std::cin >> t >> a >> b;\n    if (t\
    \ == 0) {\n      rsq.update(hld.vid[a], rsq[hld.vid[a]] + b);\n    } else {\n\
    \      std::cout << hld.query_path(\n                       a, b, 0LL, [&](int\
    \ a, int b) { return rsq.query(a, b); },\n                       RangeSumQuery<long\
    \ long>::merge)\n                << '\\n';\n    }\n  }\n}\n\nvoid yosupo3() {\n\
    \  // https://judge.yosupo.jp/problem/vertex_add_subtree_sum\n  int N, Q;\n  std::cin\
    \ >> N >> Q;\n  std::vector<long long> weights(N);\n  for (int i = 0; i < N; i++)\
    \ std::cin >> weights[i];\n  Graph<int> g(N);\n  for (int i = 0; i < N - 1; i++)\
    \ {\n    int p;\n    std::cin >> p;\n    g.add_edge(p, i + 1, 1);\n    g.add_edge(i\
    \ + 1, p, 1);\n  }\n  HeavyLightDecomposition<int> hld(g, 0, true);\n  SegmentTree<RangeSumQuery<long\
    \ long>> rsq(N);\n  for (int i = 0; i < N; i++) {\n    rsq.update(hld.vid[i],\
    \ weights[i]);\n  }\n  for (int i = 0; i < Q; i++) {\n    int t;\n    std::cin\
    \ >> t;\n    if (t == 0) {\n      int u;\n      long long x;\n      std::cin >>\
    \ u >> x;\n      rsq.update(hld.vid[u], rsq[hld.vid[u]] + x);\n    } else {\n\
    \      int u;\n      std::cin >> u;\n      std::cout << rsq.query(hld.vid[u],\
    \ hld.tail[u]) << '\\n';\n    }\n  }\n}\n\ntemplate <typename T>\nstruct RangeCompositeQuery\
    \ {\n  using type = std::pair<T, T>;\n  static type identity() { return type{1,\
    \ 0}; }\n  static type merge(const type &l, const type &r) {\n    return type{l.first\
    \ * r.first, l.second * r.first + r.second};\n  }\n};\n\nusing mint = ModInt<998'244'353>;\n\
    using mint_p = std::pair<mint, mint>;\n\nvoid yosupo4() {\n  // https://judge.yosupo.jp/problem/vertex_set_path_composite\n\
    \  // \u901A\u3063\u3066\u3044\u306A\u3044\u3002\u591A\u5206 reverse \u304C\u3069\
    \u3046\u3068\u304B\u3002\n  int N, Q;\n  std::cin >> N >> Q;\n  std::vector<mint_p>\
    \ funcs;\n  funcs.reserve(N);\n  for (int i = 0; i < N; i++) {\n    int a, b;\n\
    \    std::cin >> a >> b;\n    funcs.emplace_back(mint(a), mint(b));\n  }\n\n \
    \ Graph<int> g(N);\n  for (int i = 0; i < N - 1; i++) {\n    int a, b;\n    std::cin\
    \ >> a >> b;\n    g.add_edge(a, b, 1);\n    g.add_edge(b, a, 1);\n  }\n  HeavyLightDecomposition<int>\
    \ hld(g);\n  SegmentTree<RangeCompositeQuery<mint>> rcq(N);\n  for (int i = 0;\
    \ i < N; i++) {\n    rcq.update(hld.vid[i], funcs[i]);\n  }\n\n  for (int i =\
    \ 0; i < Q; i++) {\n    int t, a, b, c;\n    std::cin >> t >> a >> b >> c;\n \
    \   if (t == 0) {\n      rcq.update(hld.vid[a], mint_p{b, c});\n    } else {\n\
    \      mint_p func = hld.query_path(\n          a, b, RangeCompositeQuery<mint>::identity(),\n\
    \          [&](int a, int b) { return rcq.query(a, b); },\n          RangeCompositeQuery<mint>::merge);\n\
    \      std::cout << func.first * c + func.second << '\\n';\n    }\n  }\n}\n\n\
    void yuki650() {\n  int N;\n  std::cin >> N;\n  Graph<int> g(N);\n  std::vector<std::pair<int,\
    \ int>> edges(N - 1);\n  for (int i = 0; i < N - 1; i++) {\n    int a, b;\n  \
    \  std::cin >> a >> b;\n    g.add_edge(a, b, 1);\n    g.add_edge(b, a, 1);\n \
    \   edges[i] = std::make_pair(a, b);\n  }\n  HeavyLightDecomposition<int> hld(g);\n\
    \  SegmentTree<RangeMatrixMult<Matrix<ModInt<>>>> segt(N);\n  int Q;\n  std::cin\
    \ >> Q;\n  for (int i = 0; i < Q; i++) {\n    char t;\n    std::cin >> t;\n  \
    \  if (t == 'x') {\n      int idx, x00, x01, x10, x11;\n      std::cin >> idx\
    \ >> x00 >> x01 >> x10 >> x11;\n      Matrix<ModInt<>> mat(2, 2);\n      mat[0][0]\
    \ = x00, mat[0][1] = x01, mat[1][0] = x10, mat[1][1] = x11;\n      int a, b;\n\
    \      std::tie(a, b) = edges[idx];\n      segt.update(std::max(hld.vid[a], hld.vid[b]),\
    \ mat);\n    } else {\n      int u, v;\n      std::cin >> u >> v;\n      Matrix<ModInt<>>\
    \ mat = Matrix<ModInt<>>::identity(2);\n      Matrix<ModInt<>> res = hld.query_path(\n\
    \          u, v, mat, [&](int a, int b) { return segt.query(a, b); },\n      \
    \    RangeMatrixMult<Matrix<ModInt<>>>::merge, true);\n      std::cout << res[0][0]\
    \ << ' ' << res[0][1] << ' ' << res[1][0] << ' '\n                << res[1][1]\
    \ << '\\n';\n    }\n  }\n}\n\nint main() {\n  std::cin.tie(0);\n  std::ios_base::sync_with_stdio(false);\n\
    \  // yosupo();\n  // spoj_qtree();\n  // yuki650();\n  // yosupo2();\n  // yosupo3();\n\
    \  yosupo4();\n  return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: c++-library/heavy_light_decomposition.cpp
  requiredBy: []
  timestamp: '2020-09-08 04:11:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: c++-library/heavy_light_decomposition.cpp
layout: document
redirect_from:
- /library/c++-library/heavy_light_decomposition.cpp
- /library/c++-library/heavy_light_decomposition.cpp.html
title: c++-library/heavy_light_decomposition.cpp
---
