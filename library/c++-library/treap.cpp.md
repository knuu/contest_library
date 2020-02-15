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


# :warning: c++-library/treap.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#97d0d85922e0aae2441e69f2870930aa">c++-library</a>
* <a href="{{ site.github.repository_url }}/blob/master/c++-library/treap.cpp">View this file on GitHub</a>
    - Last commit date: 2019-04-11 03:52:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <typename T>
struct Node {
  using type = T;
  T val;
  Node *left, *right;
  int priority;

  Node() {}
  Node(T val) : val(val), left(nullptr), right(nullptr) {}
  bool operator<(const Node<T> &n) const { return val < n.val; }
};

template <class Node>
struct Treap {
  using T = typename Node::type;
  Node *root, *nil;
  Treap();

  Node *find_last()

      bool add_node(T val) {
    Node *node = root, *parent = nil;
    while (node != nil) {
      if (val <= node->val) {
        node = node->left, parent = node;
      } else {
        node = node->right, parent = node;
      }
    }

    node = new Node(val);
    node->left = node->right = nil;
    if (parent == nil) {
      // treap が空の場合
      root = node;
    } else if (val <= parent->val) {
      parent->left = node;
    } else {
      parent->right = node;
    }
    return true;
  }
};

template <class Node>
Treap<Node>::Treap() : root(nullptr), nil(nullptr) {}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "c++-library/treap.cpp"
template <typename T>
struct Node {
  using type = T;
  T val;
  Node *left, *right;
  int priority;

  Node() {}
  Node(T val) : val(val), left(nullptr), right(nullptr) {}
  bool operator<(const Node<T> &n) const { return val < n.val; }
};

template <class Node>
struct Treap {
  using T = typename Node::type;
  Node *root, *nil;
  Treap();

  Node *find_last()

      bool add_node(T val) {
    Node *node = root, *parent = nil;
    while (node != nil) {
      if (val <= node->val) {
        node = node->left, parent = node;
      } else {
        node = node->right, parent = node;
      }
    }

    node = new Node(val);
    node->left = node->right = nil;
    if (parent == nil) {
      // treap が空の場合
      root = node;
    } else if (val <= parent->val) {
      parent->left = node;
    } else {
      parent->right = node;
    }
    return true;
  }
};

template <class Node>
Treap<Node>::Treap() : root(nullptr), nil(nullptr) {}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

