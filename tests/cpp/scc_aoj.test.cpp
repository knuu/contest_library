#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C"
#include <iostream>

#include "c++-library/scc.cpp"

void aoj() {
  int N, M;
  std::cin >> N >> M;
  StronglyConnectedComponents scc(N);
  for (int i = 0; i < M; i++) {
    int a, b;
    std::cin >> a >> b;
    scc.add_edge(a, b);
  }
  scc.run();
  int Q;
  std::cin >> Q;
  for (int i = 0; i < Q; i++) {
    int u, v;
    std::cin >> u >> v;
    std::cout << (scc.cmp[u] == scc.cmp[v]) << std::endl;
  }
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  aoj();
  return 0;
}
