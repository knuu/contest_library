#include <vector>

#include "c++-library/scc.cpp"

struct TwoSat : StronglyConnectedComponents {
  int N;
  std::vector<bool> ans;
  TwoSat(const int N) : StronglyConnectedComponents(2 * N + 1), N(N), ans(N) {}

  void add_constraint(int a, int b) {
    add_edge(neg(a), pos(b));
    add_edge(neg(b), pos(a));
  }
  int pos(const int v) { return v > 0 ? v : N - v; }
  int neg(const int v) { return v > 0 ? N + v : -v; }

  bool run() {
    StronglyConnectedComponents::run();
    for (int i = 1; i <= N; i++) {
      if (cmp[i] == cmp[i + N]) {
        return false;
      }
    }

    for (int i = 1; i <= N; i++) {
      ans[i - 1] = cmp[i] > cmp[i + N];
    }
    return true;
  }
};
