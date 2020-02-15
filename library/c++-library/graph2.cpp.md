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


# :warning: c++-library/graph2.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#97d0d85922e0aae2441e69f2870930aa">c++-library</a>
* <a href="{{ site.github.repository_url }}/blob/master/c++-library/graph2.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-21 04:11:11+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "c++-library/graph2.cpp"
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

