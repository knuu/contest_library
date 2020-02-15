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


# :warning: c++-library/scc.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#97d0d85922e0aae2441e69f2870930aa">c++-library</a>
* <a href="{{ site.github.repository_url }}/blob/master/c++-library/scc.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-21 04:11:11+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

struct StronglyConnectedComponents {
  int V;
  std::vector<std::vector<int>> G, rG;
  std::vector<int> vs, cmp;
  std::vector<bool> used;

  StronglyConnectedComponents(const int V)
      : V(V), G(V), rG(V), cmp(V), used(V) {}

  void add_edge(const int from, const int to) {
    G[from].push_back(to);
    rG[to].push_back(from);
  }

  void dfs(const int v) {
    used[v] = true;
    for (int c : G[v])
      if (not used[c]) dfs(c);
    vs.push_back(v);
  }

  void rdfs(const int v, const int k) {
    used[v] = true;
    cmp[v] = k;
    for (int c : rG[v])
      if (not used[c]) rdfs(c, k);
  }

  int run() {
    std::fill(used.begin(), used.end(), false);
    vs.clear();
    for (int v = 0; v < V; v++)
      if (!used[v]) dfs(v);
    std::fill(used.begin(), used.end(), false);
    int k = 0;
    for (int i = vs.size() - 1; i >= 0; i--)
      if (!used[vs[i]]) rdfs(vs[i], k++);
    return k;
  }

  std::vector<int> create_order() {
    std::vector<int> order(V);
    for (std::size_t i = 0; i < cmp.size(); i++) {
      order[cmp[i]] = i;
    }
    return order;
  }
};

void yosupo() {
  // https://judge.yosupo.jp/problem/scc
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

  // yosupo();
  aoj();
  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "c++-library/scc.cpp"
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

struct StronglyConnectedComponents {
  int V;
  std::vector<std::vector<int>> G, rG;
  std::vector<int> vs, cmp;
  std::vector<bool> used;

  StronglyConnectedComponents(const int V)
      : V(V), G(V), rG(V), cmp(V), used(V) {}

  void add_edge(const int from, const int to) {
    G[from].push_back(to);
    rG[to].push_back(from);
  }

  void dfs(const int v) {
    used[v] = true;
    for (int c : G[v])
      if (not used[c]) dfs(c);
    vs.push_back(v);
  }

  void rdfs(const int v, const int k) {
    used[v] = true;
    cmp[v] = k;
    for (int c : rG[v])
      if (not used[c]) rdfs(c, k);
  }

  int run() {
    std::fill(used.begin(), used.end(), false);
    vs.clear();
    for (int v = 0; v < V; v++)
      if (!used[v]) dfs(v);
    std::fill(used.begin(), used.end(), false);
    int k = 0;
    for (int i = vs.size() - 1; i >= 0; i--)
      if (!used[vs[i]]) rdfs(vs[i], k++);
    return k;
  }

  std::vector<int> create_order() {
    std::vector<int> order(V);
    for (std::size_t i = 0; i < cmp.size(); i++) {
      order[cmp[i]] = i;
    }
    return order;
  }
};

void yosupo() {
  // https://judge.yosupo.jp/problem/scc
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

  // yosupo();
  aoj();
  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

