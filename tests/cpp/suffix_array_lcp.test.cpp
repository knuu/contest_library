#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"
#include <iostream>
#include <string>

#include "c++-library/suffix_array.cpp"

void yosupo() {
  std::string S;
  std::cin >> S;
  SuffixArray sa(S);
  sa.construct_lcp();
  long long ans = 1LL * S.size() * (S.size() + 1) / 2;
  for (size_t i = 0; i < S.size(); i++) {
    ans -= sa.lcp[i];
  }
  std::cout << ans << std::endl;
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  yosupo();
  return 0;
}
