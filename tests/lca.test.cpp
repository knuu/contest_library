#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include <iostream>

#include "c++-library/lca.cpp"

void yosupo() {
  int N, Q;
  std::cin >> N >> Q;
  LowestCommonAncestor lca(N);
  for (int i = 1; i < N; i++) {
    int p;
    std::cin >> p;
    lca.add_edge(p, i);
  }
  lca.build(0);
  for (int i = 0; i < Q; i++) {
    int u, v;
    std::cin >> u >> v;
    std::cout << lca.run(u, v) << '\n';
  }
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);
  yosupo();
  return 0;
}
