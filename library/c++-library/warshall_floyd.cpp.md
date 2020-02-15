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


# :warning: c++-library/warshall_floyd.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#97d0d85922e0aae2441e69f2870930aa">c++-library</a>
* <a href="{{ site.github.repository_url }}/blob/master/c++-library/warshall_floyd.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-21 04:11:11+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

// graph by adjacency matrix
template <typename T>
struct Graph {
  int V;
  std::vector<std::vector<T>> adj;
  T inf;

  Graph(const int V, const T inf = std::numeric_limits<T>::max())
      : V(V), adj(V, std::vector<T>(V, inf)), inf(inf) {
    for (int i = 0; i < V; i++) adj[i][i] = 0;
  }

  void add_edge(const int src, const int dst, const T weight) {
    adj[src][dst] = weight;
  }
};

template <typename T>
struct AllPairsShortestPath {
  Graph<T> g;
  std::vector<std::vector<T>> dist;
  T inf;

  AllPairsShortestPath(const Graph<T> &g, T inf = std::numeric_limits<T>::max())
      : g(g), dist(g.V, std::vector<T>(g.V)), inf(inf) {
    for (int i = 0; i < g.V; i++) {
      for (int j = 0; j < g.V; j++) dist[i][j] = g.adj[i][j];
    }
  }

  void run() {
    for (int k = 0; k < g.V; k++) {
      for (int i = 0; i < g.V; i++) {
        for (int j = 0; j < g.V; j++) {
          if (dist[i][k] != inf and dist[k][j] != inf) {
            dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
          }
        }
      }
    }
  }

  bool has_negative_loop() const {
    for (int i = 0; i < g.V; i++) {
      if (dist[i][i] < 0) return true;
    }
    return false;
  }
};

void aoj() {
  // https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_C
  int V, E;
  std::cin >> V >> E;
  Graph<long long> g(V);
  for (int i = 0; i < E; i++) {
    int s, t, d;
    std::cin >> s >> t >> d;
    g.add_edge(s, t, d);
  }
  AllPairsShortestPath<long long> apsp(g);
  apsp.run();
  if (apsp.has_negative_loop()) {
    std::cout << "NEGATIVE CYCLE" << std::endl;
  } else {
    for (int i = 0; i < g.V; i++) {
      for (int j = 0; j < g.V; j++) {
        if (apsp.dist[i][j] == apsp.inf) {
          std::cout << "INF" << (j == g.V - 1 ? '\n' : ' ');
        } else {
          std::cout << apsp.dist[i][j] << (j == g.V - 1 ? '\n' : ' ');
        }
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
#line 1 "c++-library/warshall_floyd.cpp"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

// graph by adjacency matrix
template <typename T>
struct Graph {
  int V;
  std::vector<std::vector<T>> adj;
  T inf;

  Graph(const int V, const T inf = std::numeric_limits<T>::max())
      : V(V), adj(V, std::vector<T>(V, inf)), inf(inf) {
    for (int i = 0; i < V; i++) adj[i][i] = 0;
  }

  void add_edge(const int src, const int dst, const T weight) {
    adj[src][dst] = weight;
  }
};

template <typename T>
struct AllPairsShortestPath {
  Graph<T> g;
  std::vector<std::vector<T>> dist;
  T inf;

  AllPairsShortestPath(const Graph<T> &g, T inf = std::numeric_limits<T>::max())
      : g(g), dist(g.V, std::vector<T>(g.V)), inf(inf) {
    for (int i = 0; i < g.V; i++) {
      for (int j = 0; j < g.V; j++) dist[i][j] = g.adj[i][j];
    }
  }

  void run() {
    for (int k = 0; k < g.V; k++) {
      for (int i = 0; i < g.V; i++) {
        for (int j = 0; j < g.V; j++) {
          if (dist[i][k] != inf and dist[k][j] != inf) {
            dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
          }
        }
      }
    }
  }

  bool has_negative_loop() const {
    for (int i = 0; i < g.V; i++) {
      if (dist[i][i] < 0) return true;
    }
    return false;
  }
};

void aoj() {
  // https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_C
  int V, E;
  std::cin >> V >> E;
  Graph<long long> g(V);
  for (int i = 0; i < E; i++) {
    int s, t, d;
    std::cin >> s >> t >> d;
    g.add_edge(s, t, d);
  }
  AllPairsShortestPath<long long> apsp(g);
  apsp.run();
  if (apsp.has_negative_loop()) {
    std::cout << "NEGATIVE CYCLE" << std::endl;
  } else {
    for (int i = 0; i < g.V; i++) {
      for (int j = 0; j < g.V; j++) {
        if (apsp.dist[i][j] == apsp.inf) {
          std::cout << "INF" << (j == g.V - 1 ? '\n' : ' ');
        } else {
          std::cout << apsp.dist[i][j] << (j == g.V - 1 ? '\n' : ' ');
        }
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

