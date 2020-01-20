#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>

template <std::uint_fast64_t Modulus = 1'000'000'007>
class ModInt {
  using u64 = std::uint_fast64_t;

 public:
  using type = ModInt;

  u64 a;

  constexpr ModInt(const u64 x = 0) noexcept : a(x % Modulus) {}
  constexpr u64 &value() noexcept { return a; }
  constexpr const u64 &value() const noexcept { return a; }
  constexpr ModInt operator+(const ModInt rhs) const noexcept {
    return ModInt(*this) += rhs;
  }
  constexpr ModInt operator*(const ModInt rhs) const noexcept {
    return ModInt(*this) *= rhs;
  }
  constexpr ModInt &operator+=(const ModInt rhs) noexcept {
    a += rhs.a;
    if (a >= Modulus) {
      a -= Modulus;
    }
    return *this;
  }

  constexpr ModInt &operator*=(const ModInt rhs) noexcept {
    a = a * rhs.a % Modulus;
    return *this;
  }

  friend constexpr std::ostream &operator<<(std::ostream &os,
                                            const ModInt &x) noexcept {
    return os << x.a;
  }

  static ModInt identity_zero() { return ModInt(0); }
  static ModInt identity_one() { return ModInt(1); }
};

template <typename Semiring>
struct Matrix {
  using T = typename Semiring::type;
  size_t n_row, n_col;
  T zero = Semiring::identity_zero(), one = Semiring::identity_one();
  std::vector<std::vector<T>> data;

  Matrix() {}
  Matrix(size_t n, size_t m)
      : n_row(n), n_col(m), data(n, std::vector<T>(m, zero)) {}
  Matrix(size_t n) : n_row(n), n_col(n), data(n, std::vector<T>(n, zero)) {}
  Matrix(std::vector<std::vector<T>> &arr) : n_row(arr.size()) {
    n_col = arr.size() ? arr[0].size() : 0;
    data.resize(n_row);
    for (size_t row = 0; row < n_row; row++) data[row] = arr[row];
  }

  inline const std::vector<T> &operator[](const int k) const {
    return data.at(k);
  }
  inline std::vector<T> &operator[](const int k) { return data.at(k); }

  static Matrix<Semiring> identity(size_t n) {
    Matrix<Semiring> mat(n);
    for (size_t i = 0; i < n; i++) mat[i][i] = Semiring::identity_one();
    return mat;
  }
};

template <typename Semiring>
Matrix<Semiring> operator*(const Matrix<Semiring> &A,
                           const Matrix<Semiring> &B) {
  size_t n = A.n_row, m = B.n_col, p = A.n_col;
  assert(p == B.n_row);
  Matrix<Semiring> C(n, m);
  for (size_t i = 0; i < n; i++)
    for (size_t j = 0; j < m; j++)
      for (size_t k = 0; k < p; k++) C[i][j] = (C[i][j] + A[i][k] * B[k][j]);
  return C;
}

template <class Monoid>
struct SegmentTree {
  using T = typename Monoid::type;
  int N_, N;
  std::vector<T> dat;

  SegmentTree(const int N_) : N_(N_) {
    assert(N_ > 0);
    N = 1;
    while (N < N_) {
      N <<= 1;
    }
    dat.assign(2 * N - 1, Monoid::identity());
  }

  SegmentTree(const std::vector<T> &dat_) : N_(dat_.size()) {
    assert(N_ > 0);
    N = 1;
    while (N < N_) {
      N <<= 1;
    }
    dat.assign(2 * N - 1, Monoid::identity());
    std::copy(dat_.begin(), dat_.end(), dat.begin() + N - 1);
    for (int i = N - 2; i >= 0; i--) {
      dat[i] = Monoid::merge(dat[2 * i + 1], dat[2 * i + 2]);
    }
  }

  int size() { return N_; }

  void update(int key, T val) {
    assert(0 <= key && key < N_);

    key += N - 1;
    dat[key] = val;

    while (key > 0) {
      key = (key - 1) / 2;
      dat[key] =
          Monoid::merge(dat[2 * key + 1], dat[2 * key + 2]);  // rewrite here
    }
  }

  inline const T &operator[](const int k) const { return dat.at(N - 1 + k); }
  inline T &operator[](const int k) { return dat.at(N - 1 + k); }

  T query(int low, int high) const {
    T left_ret = Monoid::identity(), right_ret = Monoid::identity();
    for (low += N, high += N; low < high; low >>= 1, high >>= 1) {
      if (low & 1) {
        left_ret = Monoid::merge(left_ret, dat[low - 1]);
        low++;
      }
      if (high & 1) {
        high--;
        right_ret = Monoid::merge(dat[high - 1], right_ret);
      }
    }
    return Monoid::merge(left_ret, right_ret);
  }
};

template <typename T>
struct RangeSumQuery {
  using type = T;
  static type identity() { return T(0); }
  static type merge(const type &l, const type &r) { return l + r; }
};

template <typename T>
struct RangeMinQuery {
  using type = T;
  static type identity() { return std::numeric_limits<T>::max(); }
  static type merge(const type &l, const type &r) { return std::min(l, r); }
};

template <typename T>
struct RangeMaxQuery {
  using type = T;
  static type identity() { return T(0); }
  static type merge(const type &l, const type &r) { return std::max(l, r); }
};

template <typename T>
struct RangeMatrixMult {
  using type = T;
  static type identity() { return T::identity(2); }
  static type merge(const type &l, const type &r) { return l * r; }
};

// graph by adjacency list
template <typename T>
struct Edge {
  int dst;
  T weight;
  Edge(int dst, T weight) : dst(dst), weight(weight) {}
  bool operator<(const Edge<T> &e) const { return weight > e.weight; }
};

template <typename T>
struct Graph {
  int V;
  std::vector<std::vector<Edge<T>>> E;
  Graph(int V) : V(V) { E.resize(V); }
  void add_edge(int src, int dst, T weight) {
    E[src].emplace_back(dst, weight);
  }
};

template <typename T>
struct HeavyLightDecomposition {
  const Graph<T> g;
  // vid: 新しい頂点番号。root から heavy 枝で繋がる頂点に優先して
  // 番号が付けられ、さらに root に近い頂点に繋がる部分木で同じことが行われる
  // heavy: 各頂点に対する heavy 枝の端点
  // head: heavy 枝で繋がる頂点のうち最も root に近い頂点
  // parent: 各頂点の親頂点
  // tail:
  std::vector<int> vid, head, heavy, parent, tail;
  HeavyLightDecomposition(const Graph<T> &g, const int root = 0,
                          const bool need_subtree = false)
      : g(g), vid(g.V, -1), head(g.V), heavy(g.V, -1), parent(g.V), tail(g.V) {
    dfs(root, -1);
    need_subtree ? dfs2(root) : bfs(root);
  }

  int dfs(const int v, const int par) {
    // 部分木の頂点の数を求めて、最大の部分木の枝を heavy とする
    // 実装上は頂点ごとに heavy となる枝の端点を持っておく
    parent[v] = par;
    int sub = 1, max_sub = 0;
    for (Edge<T> child : g.E[v]) {
      if (child.dst != par) {
        int child_sub = dfs(child.dst, v);
        sub += child_sub;
        if (child_sub > max_sub) {
          max_sub = child_sub;
          heavy[v] = child.dst;
        }
      }
    }
    return sub;
  }

  void bfs(const int root = 0) {
    // heavy 枝でつながる頂点から番号を割り振っていく
    int k = 0;
    std::queue<int> que({root});
    while (not que.empty()) {
      int r = que.front();
      que.pop();
      for (int v = r; v != -1; v = heavy[v]) {
        vid[v] = k++;
        head[v] = r;
        for (Edge<T> child : g.E[v]) {
          if (child.dst != parent[v] and child.dst != heavy[v])
            que.emplace(child.dst);
        }
      }
    }
  }

  void dfs2(const int root = 0) {
    std::stack<std::pair<int, int>> st;
    st.emplace(root, 0);
    int k = 0;

    while (not st.empty()) {
      int v, state;
      std::tie(v, state) = st.top();
      st.pop();
      if (state == 0) {
        // heavy 枝で結ばれた頂点の push
        for (int u = v; u != -1; u = heavy[u]) {
          vid[u] = k++;
          head[u] = v;
          st.emplace(u, 1);
        }
      } else if (state == 1) {
        // heavy 枝以外で結ばれた頂点の push
        st.emplace(v, 2);
        for (Edge<T> child : g.E[v]) {
          if (child.dst != parent[v] and child.dst != heavy[v]) {
            st.emplace(child.dst, 0);
          }
        }
      } else if (state == 2) {
        // tail の記録
        tail[v] = k;
      }
    }
  }

  int lca(int u, int v) const {
    while (head[u] != head[v]) {
      if (vid[u] > vid[v]) std::swap(u, v);
      v = parent[head[v]];
    }
    if (vid[u] > vid[v]) std::swap(u, v);
    return u;
  }

  template <typename Ret, typename Query, typename Merge>
  Ret query_path(int u, int v, const Ret &one, const Query &query,
                 const Merge &merge, bool edge = false) const {
    // u, v の間のパスに対するクエリを計算する
    // one は単位元、query は列に対するクエリ、merge はマージする演算
    Ret left = one, right = one;
    for (;; v = parent[head[v]]) {
      if (vid[u] > vid[v]) std::swap(u, v), std::swap(left, right);
      if (head[u] == head[v]) break;
      left = merge(query(vid[head[v]], vid[v] + 1), left);
    }
    return merge(merge(query(vid[u] + edge, vid[v] + 1), left), right);
  }

  template <typename Q>
  void add(int u, int v, const Q &q, bool edge = false) {
    for (;; v = parent[head[v]]) {
      if (vid[u] > vid[v]) std::swap(u, v);
      if (head[u] == head[v]) break;
      q(vid[head[v]], vid[v] + 1);
    }
    q(vid[u] + edge, vid[v] + 1);
  }
};

void yosupo() {
  int N, Q;
  std::cin >> N >> Q;
  Graph<int> g(N);
  for (int i = 1; i < N; i++) {
    int p;
    std::cin >> p;
    g.add_edge(p, i, 1);
  }

  HeavyLightDecomposition<int> hld(g);
  for (int i = 0; i < Q; i++) {
    int u, v;
    std::cin >> u >> v;
    std::cout << hld.lca(u, v) << '\n';
  }
}

void spoj_qtree() {
  int T;
  std::cin >> T;
  for (int t = 0; t < T; t++) {
    int N;
    std::cin >> N;
    Graph<int> g(N);
    std::vector<std::tuple<int, int, int>> edges(N - 1);
    for (int i = 0; i < N - 1; i++) {
      int a, b, w;
      std::cin >> a >> b >> w;
      a--, b--;
      edges[i] = std::make_tuple(a, b, w);
      g.add_edge(a, b, w);
      g.add_edge(b, a, w);
    }
    HeavyLightDecomposition<int> hld(g);
    SegmentTree<RangeMaxQuery<int>> rmq(N);
    for (auto &&e : edges) {
      int a, b, w;
      std::tie(a, b, w) = e;
      rmq.update(std::max(hld.vid[a], hld.vid[b]), w);
    }

    while (true) {
      std::string s;
      std::cin >> s;
      if (s == "DONE") break;
      if (s == "QUERY") {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        std::cout << hld.query_path(
                         a, b, 0, [&](int a, int b) { return rmq.query(a, b); },
                         RangeMaxQuery<int>::merge, true)
                  << '\n';
      } else {
        int idx, w;
        std::cin >> idx >> w;
        idx--;
        int a, b;
        std::tie(a, b, std::ignore) = edges[idx];
        rmq.update(std::max(hld.vid[a], hld.vid[b]), w);
      }
    }
  }
}

void yosupo2() {
  // https://judge.yosupo.jp/problem/vertex_add_path_sum
  int N, Q;
  std::cin >> N >> Q;
  std::vector<long long> weights(N);
  for (int i = 0; i < N; i++) std::cin >> weights[i];
  Graph<int> g(N);
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    std::cin >> u >> v;
    g.add_edge(u, v, 1);
    g.add_edge(v, u, 1);
  }
  HeavyLightDecomposition<int> hld(g);
  SegmentTree<RangeSumQuery<long long>> rsq(N);
  for (int i = 0; i < N; i++) {
    rsq.update(hld.vid[i], weights[i]);
  }
  for (int i = 0; i < Q; i++) {
    int t;
    long long a, b;
    std::cin >> t >> a >> b;
    if (t == 0) {
      rsq.update(hld.vid[a], rsq[hld.vid[a]] + b);
    } else {
      std::cout << hld.query_path(
                       a, b, 0LL, [&](int a, int b) { return rsq.query(a, b); },
                       RangeSumQuery<long long>::merge)
                << '\n';
    }
  }
}

void yosupo3() {
  // https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  int N, Q;
  std::cin >> N >> Q;
  std::vector<long long> weights(N);
  for (int i = 0; i < N; i++) std::cin >> weights[i];
  Graph<int> g(N);
  for (int i = 0; i < N - 1; i++) {
    int p;
    std::cin >> p;
    g.add_edge(p, i + 1, 1);
    g.add_edge(i + 1, p, 1);
  }
  HeavyLightDecomposition<int> hld(g, 0, true);
  SegmentTree<RangeSumQuery<long long>> rsq(N);
  for (int i = 0; i < N; i++) {
    rsq.update(hld.vid[i], weights[i]);
  }
  for (int i = 0; i < Q; i++) {
    int t;
    std::cin >> t;
    if (t == 0) {
      int u;
      long long x;
      std::cin >> u >> x;
      rsq.update(hld.vid[u], rsq[hld.vid[u]] + x);
    } else {
      int u;
      std::cin >> u;
      std::cout << rsq.query(hld.vid[u], hld.tail[u]) << '\n';
    }
  }
}

void yuki650() {
  int N;
  std::cin >> N;
  Graph<int> g(N);
  std::vector<std::pair<int, int>> edges(N - 1);
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    std::cin >> a >> b;
    g.add_edge(a, b, 1);
    g.add_edge(b, a, 1);
    edges[i] = std::make_pair(a, b);
  }
  HeavyLightDecomposition<int> hld(g);
  SegmentTree<RangeMatrixMult<Matrix<ModInt<>>>> segt(N);
  int Q;
  std::cin >> Q;
  for (int i = 0; i < Q; i++) {
    char t;
    std::cin >> t;
    if (t == 'x') {
      int idx, x00, x01, x10, x11;
      std::cin >> idx >> x00 >> x01 >> x10 >> x11;
      Matrix<ModInt<>> mat(2, 2);
      mat[0][0] = x00, mat[0][1] = x01, mat[1][0] = x10, mat[1][1] = x11;
      int a, b;
      std::tie(a, b) = edges[idx];
      segt.update(std::max(hld.vid[a], hld.vid[b]), mat);
    } else {
      int u, v;
      std::cin >> u >> v;
      Matrix<ModInt<>> mat = Matrix<ModInt<>>::identity(2);
      Matrix<ModInt<>> res = hld.query_path(
          u, v, mat, [&](int a, int b) { return segt.query(a, b); },
          RangeMatrixMult<Matrix<ModInt<>>>::merge, true);
      std::cout << res[0][0] << ' ' << res[0][1] << ' ' << res[1][0] << ' '
                << res[1][1] << '\n';
    }
  }
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);
  // yosupo();
  // spoj_qtree();
  // yuki650();
  // yosupo2();
  yosupo3();
  return 0;
}