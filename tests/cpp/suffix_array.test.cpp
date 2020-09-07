#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"
#include <iostream>
#include <string>

#include "c++-library/suffix_array.cpp"


void yosupo() {
  // https://judge.yosupo.jp/problem/suffixarray
  std::string S;
  std::cin >> S;
  SuffixArray sa(S);
  for (size_t i = 1; i <= S.size(); i++) {
    std::cout << sa.sa[i] << (i == S.size() ? '\n' : ' ');
  }
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  yosupo();
  return 0;
}
