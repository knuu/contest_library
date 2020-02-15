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


# :warning: c++-library/bellman_ford.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#97d0d85922e0aae2441e69f2870930aa">c++-library</a>
* <a href="{{ site.github.repository_url }}/blob/master/c++-library/bellman_ford.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-21 04:11:11+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <algorithm>
#include <iostream>
#include <vector>

// graph by adjacency list
template <typename T>
struct Edge {
  int src, dst;
  T weight;
  Edge(const int src, const int dst, const T weight)
      : src(src), dst(dst), weight(weight) {}
  Edge(const int dst, const T weight) : src(-1), dst(dst), weight(weight) {}
  bool operator<(const Edge<T> &e) const { return weight > e.weight; }
};

template <typename T>
struct Graph {
  int V;
  std::vector<std::vector<Edge<T>>> E;
  Graph(const int V) : V(V) { E.resize(V); }
  void add_edge(const int src, const int dst, const T weight) {
    E[src].emplace_back(src, dst, weight);
  }
};

template <typename T>
struct ShortestPath {
  Graph<T> g;
  T inf;
  std::vector<T> dist;
  std::vector<int> prev;
  bool has_negative_cycle;

  ShortestPath(const Graph<T> g, const T inf = 1 << 30)
      : g(g), inf(inf), dist(g.V), prev(g.V) {}

  void run(int start) {
    std::fill(dist.begin(), dist.end(), inf);
    dist[start] = 0;
    prev[start] = -1;
    has_negative_cycle = false;
    for (int cnt = 0; cnt < g.V; cnt++) {
      bool update = false;
      for (int i = 0; i < g.V; i++) {
        for (Edge<T> e : g.E[i]) {
          if (dist[i] != inf && dist[i] + e.weight < dist[e.dst]) {
            dist[e.dst] = dist[i] + e.weight;
            prev[e.dst] = i;
            update = true;
            if (cnt == g.V - 1) has_negative_cycle = true;
          }
        }
      }
      if (!update) break;
    }
  }

  std::vector<int> build_path(const int goal) const {
    std::vector<int> path;
    for (int v = goal; v != -1; v = prev[v]) {
      path.emplace_back(v);
    }
    std::reverse(path.begin(), path.end());
    return path;
  }
};

void aoj() {
  // https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_B
  int V, E, r;
  std::cin >> V >> E >> r;
  Graph<int> g(V);
  for (int i = 0; i < E; i++) {
    int s, t, d;
    std::cin >> s >> t >> d;
    g.add_edge(s, t, d);
  }
  ShortestPath<int> sp(g);
  sp.run(r);
  if (sp.has_negative_cycle) {
    std::cout << "NEGATIVE CYCLE" << std::endl;
  } else {
    for (int i = 0; i < g.V; i++) {
      if (sp.dist[i] == sp.inf) {
        std::cout << "INF" << std::endl;
      } else {
        std::cout << sp.dist[i] << std::endl;
      }
    }
  }
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  aoj();
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "c++-library/bellman_ford.cpp"
#include <algorithm>
#include <iostream>
#include <vector>

// graph by adjacency list
template <typename T>
struct Edge {
  int src, dst;
  T weight;
  Edge(const int src, const int dst, const T weight)
      : src(src), dst(dst), weight(weight) {}
  Edge(const int dst, const T weight) : src(-1), dst(dst), weight(weight) {}
  bool operator<(const Edge<T> &e) const { return weight > e.weight; }
};

template <typename T>
struct Graph {
  int V;
  std::vector<std::vector<Edge<T>>> E;
  Graph(const int V) : V(V) { E.resize(V); }
  void add_edge(const int src, const int dst, const T weight) {
    E[src].emplace_back(src, dst, weight);
  }
};

template <typename T>
struct ShortestPath {
  Graph<T> g;
  T inf;
  std::vector<T> dist;
  std::vector<int> prev;
  bool has_negative_cycle;

  ShortestPath(const Graph<T> g, const T inf = 1 << 30)
      : g(g), inf(inf), dist(g.V), prev(g.V) {}

  void run(int start) {
    std::fill(dist.begin(), dist.end(), inf);
    dist[start] = 0;
    prev[start] = -1;
    has_negative_cycle = false;
    for (int cnt = 0; cnt < g.V; cnt++) {
      bool update = false;
      for (int i = 0; i < g.V; i++) {
        for (Edge<T> e : g.E[i]) {
          if (dist[i] != inf && dist[i] + e.weight < dist[e.dst]) {
            dist[e.dst] = dist[i] + e.weight;
            prev[e.dst] = i;
            update = true;
            if (cnt == g.V - 1) has_negative_cycle = true;
          }
        }
      }
      if (!update) break;
    }
  }

  std::vector<int> build_path(const int goal) const {
    std::vector<int> path;
    for (int v = goal; v != -1; v = prev[v]) {
      path.emplace_back(v);
    }
    std::reverse(path.begin(), path.end());
    return path;
  }
};

void aoj() {
  // https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_B
  int V, E, r;
  std::cin >> V >> E >> r;
  Graph<int> g(V);
  for (int i = 0; i < E; i++) {
    int s, t, d;
    std::cin >> s >> t >> d;
    g.add_edge(s, t, d);
  }
  ShortestPath<int> sp(g);
  sp.run(r);
  if (sp.has_negative_cycle) {
    std::cout << "NEGATIVE CYCLE" << std::endl;
  } else {
    for (int i = 0; i < g.V; i++) {
      if (sp.dist[i] == sp.inf) {
        std::cout << "INF" << std::endl;
      } else {
        std::cout << sp.dist[i] << std::endl;
      }
    }
  }
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  aoj();
  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

