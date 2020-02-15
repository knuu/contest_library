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


# :heavy_check_mark: tests/lca.test.cpp

<a href="../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/tests/lca.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-16 02:15:20+09:00


* see: <a href="https://judge.yosupo.jp/problem/lca">https://judge.yosupo.jp/problem/lca</a>


## Depends on

* :heavy_check_mark: <a href="../../library/c++-library/lca.cpp.html">c++-library/lca.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tests/lca.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include <iostream>

#line 1 "c++-library/lca.cpp"
#include <cmath>
#include <utility>
#include <vector>

struct LowestCommonAncestor {
  int V, log_V;
  std::vector<std::vector<int>> edge;

  std::vector<std::vector<int>> parent;
  std::vector<int> depth;

  LowestCommonAncestor(int V)
      : V(V),
        log_V(std::ceil(std::log2(V)) + 1),
        edge(V),
        parent(log_V),
        depth(V) {
    for (int i = 0; i < log_V; i++) parent[i].resize(V);
  }

  void add_edge(int a, int b) {
    edge[a].push_back(b);
    edge[b].push_back(a);
  }

  void dfs(int v, int par, int dep) {
    parent[0][v] = par;
    depth[v] = dep;
    for (auto child : edge[v]) {
      if (child != par) dfs(child, v, dep + 1);
    }
  }

  void build(int root = 0) {
    dfs(root, -1, 0);
    for (int k = 0; k + 1 < log_V; k++) {
      for (int v = 0; v < V; v++) {
        if (parent[k][v] < 0) {
          parent[k + 1][v] = -1;
        } else {
          parent[k + 1][v] = parent[k][parent[k][v]];
        }
      }
    }
  }

  int run(int u, int v) {
    if (depth[u] > depth[v]) std::swap(u, v);
    for (int k = 0; k < log_V; k++) {
      if ((depth[v] - depth[u]) >> k & 1) {
        v = parent[k][v];
      }
    }
    if (u == v) return u;

    for (int k = log_V - 1; k >= 0; k--) {
      if (parent[k][u] != parent[k][v]) {
        u = parent[k][u];
        v = parent[k][v];
      }
    }
    return parent[0][u];
  }

  // cnt 個上の親を取得する
  int get_cntup_node(int v, int cnt) {
    if (cnt <= 0) return v;
    for (int k = log_V - 1; k >= 0; k--) {
      if (cnt >> k & 1) {
        v = parent[k][v];
      }
    }
    return v;
  }
};
#line 5 "tests/lca.test.cpp"

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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

