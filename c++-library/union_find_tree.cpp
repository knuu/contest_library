#include <vector>

struct DisjointSet {
  std::vector<size_t> parent, rank;

  DisjointSet(size_t N) {
    parent.resize(N), rank.resize(N, 0);
    for (size_t i = 0; i < N; i++) parent[i] = i;
  }

  size_t find(size_t x) {
    if (parent[x] == x) {
      return x;
    } else {
      return parent[x] = find(parent[x]);
    }
  }

  void unite(size_t x, size_t y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (rank[x] < rank[y]) {
      parent[x] = y;
    } else {
      parent[y] = x;
      if (rank[x] == rank[y]) rank[x]++;
    }
  }

  bool same(size_t x, size_t y) { return find(x) == find(y); }
};
