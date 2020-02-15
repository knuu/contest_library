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


# :warning: c++-library/prim.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#97d0d85922e0aae2441e69f2870930aa">c++-library</a>
* <a href="{{ site.github.repository_url }}/blob/master/c++-library/prim.cpp">View this file on GitHub</a>
    - Last commit date: 2019-04-11 03:52:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <typename T>
struct Node {
  int v, src; T dist;
  Node(int v, int src, T dist) : v(v), src(src), dist(dist) { };
  bool operator < (const Node<T> &n) const {
    return dist > n.dist; // reverse
  }
};

template <typename T>
struct MinimumSpanningTree {
  Graph<T> g;
  vector<Node<T>> mst;
  int mincost;

  MinimumSpanningTree(const Graph<T> &g) : g(g) { }

  int run() {
    mincost = 0;

    vector<bool> used(g.V, false);

    priority_queue<Node<T>> que;
    que.emplace(0, -1, 0);

    while (!que.empty()) {
      Node<T> n = que.top(); que.pop();
      int v = n.v; T cost = n.dist;
      if (used[v]) continue;
      if (n.src != -1) mst.push_back(n);
      used[v] = true;
      mincost += cost;
      for (Edge<T> e : g.E[v]) {
        if (!used[e.dst]) que.emplace(e.dst, v, e.weight);
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
#line 1 "c++-library/prim.cpp"
template <typename T>
struct Node {
  int v, src; T dist;
  Node(int v, int src, T dist) : v(v), src(src), dist(dist) { };
  bool operator < (const Node<T> &n) const {
    return dist > n.dist; // reverse
  }
};

template <typename T>
struct MinimumSpanningTree {
  Graph<T> g;
  vector<Node<T>> mst;
  int mincost;

  MinimumSpanningTree(const Graph<T> &g) : g(g) { }

  int run() {
    mincost = 0;

    vector<bool> used(g.V, false);

    priority_queue<Node<T>> que;
    que.emplace(0, -1, 0);

    while (!que.empty()) {
      Node<T> n = que.top(); que.pop();
      int v = n.v; T cost = n.dist;
      if (used[v]) continue;
      if (n.src != -1) mst.push_back(n);
      used[v] = true;
      mincost += cost;
      for (Edge<T> e : g.E[v]) {
        if (!used[e.dst]) que.emplace(e.dst, v, e.weight);
      }
    }
    return mincost;
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

