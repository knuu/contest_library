#include <iostream>
#include <vector>

struct DisjointSet {
  std::vector<size_t> parent, rank;

  DisjointSet(const size_t N) : parent(N), rank(N, 0) {
    for (size_t i = 0; i < N; i++) parent[i] = i;
  }

  size_t find(const size_t x) {
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

  bool same(const size_t x, const size_t y) { return find(x) == find(y); }
};

void yosupo_aoj() {
  // https://judge.yosupo.jp/problem/unionfind
  // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A&lang=ja
  int N, Q;
  std::cin >> N >> Q;
  DisjointSet uft(N);
  for (int i = 0; i < Q; i++) {
    int t, u, v;
    std::cin >> t >> u >> v;
    if (t == 0) {
      uft.unite(u, v);
    } else {
      std::cout << uft.same(u, v) << std::endl;
    }
  }
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  yosupo_aoj();
  return 0;
}
