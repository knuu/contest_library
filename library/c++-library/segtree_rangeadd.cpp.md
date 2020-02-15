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


# :warning: c++-library/segtree_rangeadd.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#97d0d85922e0aae2441e69f2870930aa">c++-library</a>
* <a href="{{ site.github.repository_url }}/blob/master/c++-library/segtree_rangeadd.cpp">View this file on GitHub</a>
    - Last commit date: 2019-04-11 03:52:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <typename T>
struct RangeSumQuery {
  int N, _N;
  vector<T> data, datb;

  RangeSumQuery(int _N) : _N(_N) {
    assert(_N > 0);
    N = 1;
    while (N < _N) N <<= 1;
    data.assign(2 * N - 1, 0);
    datb.assign(2 * N - 1, 0);
  }

  void add(int a, int b, T x) { add(a, b, x, 0, 0, N); }
  void add(int a, int b, T x, int k, int l, int r) {
    if (a <= l and r <= b) {
      data[k] += x;
    } else if (l < b and a < r) {
      datb[k] += (min(r, b) - max(l, a)) * x;
      add(a, b, x, 2 * k + 1, l, (l + r) / 2);
      add(a, b, x, 2 * k + 2, (l + r) / 2, r);
    }
  }

  T sum(int a, int b) { return sum(a, b, 0, 0, N); }
  T sum(int a, int b, int k, int l, int r) {
    if (b <= l or r <= a) {
      return 0;
    } else if (a <= l and r <= b) {
      return data[k] * (r - l) + datb[k];
    } else {
      T res = data[k] * (min(r, b) - max(l, a));
      res += sum(a, b, 2 * k + 1, l, (l + r) / 2);
      res += sum(a, b, 2 * k + 2, (l + r) / 2, r);
      return res;
    }
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "c++-library/segtree_rangeadd.cpp"
template <typename T>
struct RangeSumQuery {
  int N, _N;
  vector<T> data, datb;

  RangeSumQuery(int _N) : _N(_N) {
    assert(_N > 0);
    N = 1;
    while (N < _N) N <<= 1;
    data.assign(2 * N - 1, 0);
    datb.assign(2 * N - 1, 0);
  }

  void add(int a, int b, T x) { add(a, b, x, 0, 0, N); }
  void add(int a, int b, T x, int k, int l, int r) {
    if (a <= l and r <= b) {
      data[k] += x;
    } else if (l < b and a < r) {
      datb[k] += (min(r, b) - max(l, a)) * x;
      add(a, b, x, 2 * k + 1, l, (l + r) / 2);
      add(a, b, x, 2 * k + 2, (l + r) / 2, r);
    }
  }

  T sum(int a, int b) { return sum(a, b, 0, 0, N); }
  T sum(int a, int b, int k, int l, int r) {
    if (b <= l or r <= a) {
      return 0;
    } else if (a <= l and r <= b) {
      return data[k] * (r - l) + datb[k];
    } else {
      T res = data[k] * (min(r, b) - max(l, a));
      res += sum(a, b, 2 * k + 1, l, (l + r) / 2);
      res += sum(a, b, 2 * k + 2, (l + r) / 2, r);
      return res;
    }
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

