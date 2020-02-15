---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: c++-library/suffix_array.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#97d0d85922e0aae2441e69f2870930aa">c++-library</a>
* <a href="{{ site.github.repository_url }}/blob/master/c++-library/suffix_array.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-21 04:11:11+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <functional>
#include <iostream>
#include <string>
#include <vector>

struct SuffixArray {
  int N, k;
  std::string S;
  std::vector<int> sa, rank, tmp;
  std::vector<int> lcp, rank_lcp;
  SuffixArray(std::string S)
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

  bool contain(std::string T) {
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
  std::string S;
  std::cin >> S;
  SuffixArray sa(S);
  for (int i = 1; i <= S.size(); i++) {
    std::cout << sa.sa[i] << (i == S.size() ? '\n' : ' ');
  }
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  yosupo();
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "c++-library/suffix_array.cpp"
#include <functional>
#include <iostream>
#include <string>
#include <vector>

struct SuffixArray {
  int N, k;
  std::string S;
  std::vector<int> sa, rank, tmp;
  std::vector<int> lcp, rank_lcp;
  SuffixArray(std::string S)
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

  bool contain(std::string T) {
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
  std::string S;
  std::cin >> S;
  SuffixArray sa(S);
  for (int i = 1; i <= S.size(); i++) {
    std::cout << sa.sa[i] << (i == S.size() ? '\n' : ' ');
  }
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  yosupo();
  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

