#include <functional>
#include <iostream>
#include <string>
#include <vector>

struct SuffixArray {
  int N, k;
  std::string S;
  std::vector<int> sa, rank, tmp;
  std::vector<int> lcp, rank_lcp;
  SuffixArray(std::string &S)
      : N(S.size()), S(S), sa(N + 1), rank(N + 1), tmp(N + 1) {
    construct();
  }

  void construct() {
    for (int i = 0; i <= N; i++) {
      sa[i] = i;
      rank[i] = i < N ? S[i] : -1;
    }

    std::function<bool(int, int)> compare = [&](int i, int j) {
      if (rank[i] != rank[j]) {
        return rank[i] < rank[j];
      } else {
        int ri = i + k <= N ? rank[i + k] : -1;
        int rj = j + k <= N ? rank[j + k] : -1;
        return ri < rj;
      }
    };
    for (k = 1; k <= N; k *= 2) {
      sort(sa.begin(), sa.end(), compare);

      tmp[sa[0]] = 0;
      for (int i = 1; i <= N; i++) {
        tmp[sa[i]] = tmp[sa[i - 1]] + (compare(sa[i - 1], sa[i]) ? 1 : 0);
      }
      for (int i = 0; i <= N; i++) rank[i] = tmp[i];
    }
  }

  bool contain(const std::string &T) const {
    int left = 0, right = N;
    while (left + 1 < right) {
      int mid = (left + right) / 2;
      (S.compare(sa[mid], T.length(), T) < 0 ? left : right) = mid;
    }
    return S.compare(sa[right], T.length(), T) == 0;
  }

  void construct_lcp() {
    lcp.resize(N), rank_lcp.resize(N + 1);
    for (int i = 0; i <= N; i++) rank_lcp[sa[i]] = i;

    int h = 0;
    lcp[0] = 0;
    for (int i = 0; i < N; i++) {
      int j = sa[rank[i] - 1];

      if (h > 0) h--;
      for (; j + h < N and i + h < N; h++) {
        if (S[j + h] != S[i + h]) break;
      }

      lcp[rank[i] - 1] = h;
    }
  }
};

void yosupo() {
  // https://judge.yosupo.jp/problem/suffixarray
  std::string S;
  std::cin >> S;
  SuffixArray sa(S);
  for (size_t i = 1; i <= S.size(); i++) {
    std::cout << sa.sa[i] << (i == S.size() ? '\n' : ' ');
  }
}

void yosupo2() {
  // https://judge.yosupo.jp/problem/number_of_substrings
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

  // yosupo();
  yosupo2();
  return 0;
}
