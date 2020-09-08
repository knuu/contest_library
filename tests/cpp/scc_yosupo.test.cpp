#define PROBLEM "https://judge.yosupo.jp/problem/scc"
#include <iostream>
#include <map>

#include "c++-library/scc.cpp"

void yosupo() {
  int N, M;
  std::cin >> N >> M;
  StronglyConnectedComponents scc(N);
  for (int i = 0; i < M; i++) {
    int a, b;
    std::cin >> a >> b;
    scc.add_edge(a, b);
  }
  scc.run();
  std::map<int, std::vector<int>> ans;
  for (int i = N - 1; i >= 0; i--) {
    ans[scc.cmp[i]].emplace_back(i);
  }
  std::cout << ans.size() << std::endl;
  for (auto&& p : ans) {
    std::cout << p.second.size();
    for (int& i : p.second) std::cout << ' ' << i;
    std::cout << std::endl;
  }
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  yosupo();
  return 0;
}