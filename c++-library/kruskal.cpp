#include <vector>

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
