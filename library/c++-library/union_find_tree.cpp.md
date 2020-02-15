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


# :warning: c++-library/union_find_tree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#97d0d85922e0aae2441e69f2870930aa">c++-library</a>
* <a href="{{ site.github.repository_url }}/blob/master/c++-library/union_find_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-21 04:11:11+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "c++-library/union_find_tree.cpp"
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

