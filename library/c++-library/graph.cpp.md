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


# :warning: c++-library/graph.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#97d0d85922e0aae2441e69f2870930aa">c++-library</a>
* <a href="{{ site.github.repository_url }}/blob/master/c++-library/graph.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-21 04:11:11+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <vector>

// graph by adjacency list
template <typename T>
struct Edge {
  int src, dst;
  T weight;
  Edge(const int src, const int dst, const T weight)
      : src(src), dst(dst), weight(weight) {}
  Edge(const int dst, const T weight) : src(-1), dst(dst), weight(weight) {}
  Edge(const int dst) : src(-1), dst(dst), weight(T(1)) {}
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "c++-library/graph.cpp"
#include <vector>

// graph by adjacency list
template <typename T>
struct Edge {
  int src, dst;
  T weight;
  Edge(const int src, const int dst, const T weight)
      : src(src), dst(dst), weight(weight) {}
  Edge(const int dst, const T weight) : src(-1), dst(dst), weight(weight) {}
  Edge(const int dst) : src(-1), dst(dst), weight(T(1)) {}
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

