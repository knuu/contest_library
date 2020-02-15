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


# :warning: c++-library/kruskal.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#97d0d85922e0aae2441e69f2870930aa">c++-library</a>
* <a href="{{ site.github.repository_url }}/blob/master/c++-library/kruskal.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-21 04:11:11+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <vector>

template <typename T>
struct Edge {
  int src, dst;
  T weight;

  Edge(int src, int dst, T weight) : src(src), dst(dst), weight(weight) {}

  bool operator<(const Edge<T> &e) const { return weight < e.weight; }
};

template <typename T>
struct Graph {
  int V;
  std::vector<Edge<T>> E;

  Graph(int V) : V(V) {}

  void add_edge(int src, int dst, T weight) {
    E.emplace_back(src, dst, weight);
  }
};

struct DisjointSet {
  std::vector<int> parent, rank;

  DisjointSet(int N) {
    parent.resize(N), rank.resize(N, 0);
    for (int i = 0; i < N; i++) parent[i] = i;
  }

  int find(int x) {
    if (parent[x] == x) {
      return x;
    } else {
      return parent[x] = find(parent[x]);
    }
  }

  void unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (rank[x] < rank[y]) {
      parent[x] = y;
    } else {
      parent[y] = x;
      if (rank[x] == rank[y]) rank[x]++;
    }
  }

  bool same(int x, int y) { return find(x) == find(y); }
};

template <typename T>
struct MinimumSpanningTree {
  Graph<T> g;
  std::vector<Edge<T>> mst;
  T mincost;

  MinimumSpanningTree(const Graph<T> &g) : g(g) {}

  T run() {
    mincost = 0;
    sort(g.E.begin(), g.E.end());

    DisjointSet uf(g.V);

    for (int i = 0, edge_count = g.V - 1; edge_count; i++) {
      assert(i < (int)g.E.size());
      Edge<T> e = g.E[i];
      if (!uf.same(e.src, e.dst)) {
        uf.unite(e.src, e.dst);
        mst.emplace_back(e);
        mincost += e.weight;
        edge_count--;
      }
    }
    return mincost;
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "c++-library/kruskal.cpp"
#include <vector>

template <typename T>
struct Edge {
  int src, dst;
  T weight;

  Edge(int src, int dst, T weight) : src(src), dst(dst), weight(weight) {}

  bool operator<(const Edge<T> &e) const { return weight < e.weight; }
};

template <typename T>
struct Graph {
  int V;
  std::vector<Edge<T>> E;

  Graph(int V) : V(V) {}

  void add_edge(int src, int dst, T weight) {
    E.emplace_back(src, dst, weight);
  }
};

struct DisjointSet {
  std::vector<int> parent, rank;

  DisjointSet(int N) {
    parent.resize(N), rank.resize(N, 0);
    for (int i = 0; i < N; i++) parent[i] = i;
  }

  int find(int x) {
    if (parent[x] == x) {
      return x;
    } else {
      return parent[x] = find(parent[x]);
    }
  }

  void unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (rank[x] < rank[y]) {
      parent[x] = y;
    } else {
      parent[y] = x;
      if (rank[x] == rank[y]) rank[x]++;
    }
  }

  bool same(int x, int y) { return find(x) == find(y); }
};

template <typename T>
struct MinimumSpanningTree {
  Graph<T> g;
  std::vector<Edge<T>> mst;
  T mincost;

  MinimumSpanningTree(const Graph<T> &g) : g(g) {}

  T run() {
    mincost = 0;
    sort(g.E.begin(), g.E.end());

    DisjointSet uf(g.V);

    for (int i = 0, edge_count = g.V - 1; edge_count; i++) {
      assert(i < (int)g.E.size());
      Edge<T> e = g.E[i];
      if (!uf.same(e.src, e.dst)) {
        uf.unite(e.src, e.dst);
        mst.emplace_back(e);
        mincost += e.weight;
        edge_count--;
      }
    }
    return mincost;
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

