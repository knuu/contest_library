#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"
#include <iostream>
#include <string>

#include "c++-library/2sat.cpp"


void yosupo() {
  std::string s;
  std::cin >> s >> s;
  int N, M;
  std::cin >> N >> M;
  TwoSat sat(N);
  for (int i = 0; i < M; i++) {
    int a, b, c;
    std::cin >> a >> b >> c;
    sat.add_constraint(a, b);
  }
  if (!sat.run()) {
    std::cout << "s UNSATISFIABLE" << std::endl;
  } else {
    std::cout << "s SATISFIABLE\nv ";
    for (int i = 0; i < N; i++) {
      std::cout << (sat.ans[i] ? i + 1 : -(i + 1)) << ' ';
    }
    std::cout << '0' << std::endl;
  }
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  yosupo();
  return 0;
}