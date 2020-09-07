#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <numeric>
#include <tuple>
#include <utility>
#include <vector>

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
struct RangeMinQuery {
  using type = std::pair<T, int>;
  static type identity() {
    return std::make_pair(std::numeric_limits<T>::max(), 0);
  }
  static type merge(const type &l, const type &r) { return std::min(l, r); }
};

template <typename T>
struct Edge {
  int src, dst;
  T weight;

  Edge(int src, int dst, T weight) : src(src), dst(dst), weight(weight) {}

  bool operator<(const Edge<T> &e) const { return weight < e.weight; }
};

template <typename T>
struct Graph {
  int V;
  std::vector<Edge<T>> E;

  Graph(int V) : V(V) {}

  void add_edge(int src, int dst, T weight) {
    E.emplace_back(src, dst, weight);
  }
};

struct DisjointSet {
  std::vector<int> parent, rank;

  DisjointSet(int N) {
    parent.resize(N), rank.resize(N, 0);
    for (int i = 0; i < N; i++) parent[i] = i;
  }

  int find(int x) {
    if (parent[x] == x) {
      return x;
    } else {
      return parent[x] = find(parent[x]);
    }
  }

  void unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (rank[x] < rank[y]) {
      parent[x] = y;
    } else {
      parent[y] = x;
      if (rank[x] == rank[y]) rank[x]++;
    }
  }

  bool same(int x, int y) { return find(x) == find(y); }
};

template <typename T>
struct MinimumSpanningTree {
  Graph<T> g;
  std::vector<Edge<T>> mst;
  T mincost;

  MinimumSpanningTree(const Graph<T> &g) : g(g) {}

  T run() {
    mincost = 0;
    sort(g.E.begin(), g.E.end());

    DisjointSet uf(g.V);

    for (int i = 0, edge_count = g.V - 1; edge_count; i++) {
      assert(i < (int)g.E.size());
      Edge<T> e = g.E[i];
      if (!uf.same(e.src, e.dst)) {
        uf.unite(e.src, e.dst);
        mst.emplace_back(e);
        mincost += e.weight;
        edge_count--;
      }
    }
    return mincost;
  }
};

template <typename T>
struct ManhattanMinimumSpanningTree {
  int N;
  std::vector<std::pair<T, T>> points;
  Graph<T> graph;
  std::vector<Edge<T>> mst;
  T mincost;

  ManhattanMinimumSpanningTree(std::vector<std::pair<T, T>> &points)
      : N(points.size()), points(points), graph(N) {}

  void line_sweep() {
    std::vector<int> ids(N);
    std::iota(ids.begin(), ids.end(), 0);

    std::sort(ids.begin(), ids.end(), [&](int i, int j) {
      return (points[i].second - points[i].first <
              points[j].second - points[j].first) ||
             (points[i].second - points[i].first ==
                  points[j].second - points[j].first &&
              points[i].second > points[j].second) ||
             (points[i].second - points[i].first ==
                  points[j].second - points[j].first &&
              points[i].second == points[j].second && i > j);
    });

    std::vector<std::tuple<T, T, int>> y_idx;
    for (int i = 0; i < N; i++) {
      int x, y;
      std::tie(x, y) = points[i];
      y_idx.emplace_back(y, x, i);
    }
    std::sort(y_idx.begin(), y_idx.end());

    // ids -> セグメント木で管理する列のインデックス
    std::vector<int> idx_to_idx(N);
    for (int i = 0; i < N; i++) {
      idx_to_idx[std::get<2>(y_idx[i])] = i;
    }

    // イベント点ごとの処理
    SegmentTree<RangeMinQuery<T>> segt(N);
    for (int i = 0; i < N; i++) {
      auto res = segt.query(idx_to_idx[ids[i]], N);
      if (res != RangeMinQuery<T>::identity()) {
        int idx;
        std::tie(std::ignore, idx) = res;
        T dist = std::abs(points[ids[i]].first - points[idx].first) +
                 std::abs(points[ids[i]].second - points[idx].second);
        graph.add_edge(ids[i], idx, dist);
      }
      segt.update(
          idx_to_idx[ids[i]],
          std::make_pair(points[ids[i]].first + points[ids[i]].second, ids[i]));
    }
  }

  void create_graph() {
    for (int s = 0; s < 2; s++) {
      for (int t = 0; t < 2; t++) {
        for (int u = 0; u < 2; u++) {
          line_sweep();

          for (auto &p : points) std::swap(p.first, p.second);
        }
        for (auto &p : points) p.first = -p.first;
      }
      for (auto &p : points) p.second = -p.second;
    }
  }

  T run() {
    create_graph();
    MinimumSpanningTree<T> mst_(graph);
    mincost = mst_.run();
    mst = mst_.mst;
    return mincost;
  }
};

void yosupo() {
  // https://judge.yosupo.jp/problem/manhattanmst
  int N;
  std::cin >> N;
  std::vector<std::pair<long long, long long>> points;
  for (int i = 0; i < N; i++) {
    long long x, y;
    std::cin >> x >> y;
    points.emplace_back(x, y);
  }
  ManhattanMinimumSpanningTree<long long> mst(points);
  std::cout << mst.run() << '\n';
  for (auto &e : mst.mst) {
    std::cout << e.src << ' ' << e.dst << '\n';
  }
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  yosupo();
  return 0;
}
