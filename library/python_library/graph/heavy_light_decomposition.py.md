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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: python_library/graph/heavy_light_decomposition.py

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#7e80885bc8a78dc63feed9f40126ba0e">python_library/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/python_library/graph/heavy_light_decomposition.py">View this file on GitHub</a>
    - Last commit date: 2020-02-16 07:49:55+09:00




## Depends on

* :heavy_check_mark: <a href="graph.py.html">python_library/graph/graph.py</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/tests/hld_lca.test.py.html">tests/hld_lca.test.py</a>
* :heavy_check_mark: <a href="../../../verify/tests/hld_vertex_add_path_sum.test.py.html">tests/hld_vertex_add_path_sum.test.py</a>
* :heavy_check_mark: <a href="../../../verify/tests/hld_vertex_add_subtree_sum.test.py.html">tests/hld_vertex_add_subtree_sum.test.py</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
# @import python_library/graph/graph.py
from collections import deque

from python_library.graph.graph import Graph


class HeavyLightDecomposition:
    def __init__(self, g: Graph, root: int = 0, need_subtree: bool = False) -> None:
        self.g = g
        self.vid, self.head = [-1] * g.V, [0] * g.V
        self.heavy, self.parent = [-1] * g.V, [0] * g.V
        self.dfs(root)
        if not need_subtree:
            self.bfs(root)
        else:
            self.tail = [0] * g.V
            self.dfs2(root)

    def dfs(self, root=-1):
        stack = [(root, -1, False)]
        sub, max_sub = [1] * self.g.V, [(0, -1)] * self.g.V
        while stack:
            v, par, flag = stack.pop()
            if not flag:
                self.parent[v] = par
                stack.append((v, par, True))
                stack.extend((e.dst, v, False) for e in self.g.E[v] if e.dst != par)
            else:
                if par != -1:
                    sub[par] += sub[v]
                    max_sub[par] = max(max_sub[par], (sub[v], v))
                self.heavy[v] = max_sub[v][1]

    def bfs(self, root=0):
        k, que = 0, deque([root])
        while que:
            r = v = que.popleft()
            while v != -1:
                self.vid[v], self.head[v] = k, r
                k += 1
                for e in self.g.E[v]:
                    if e.dst != self.parent[v] and e.dst != self.heavy[v]:
                        que.append(e.dst)
                v = self.heavy[v]

    def dfs2(self, root: int = 0) -> None:
        stack = [(root, 0)]
        k = 0
        while stack:
            v, state = stack.pop()
            if state == 0:
                u = v
                while u != -1:
                    self.vid[u] = k
                    k += 1
                    self.head[u] = v
                    stack.append((u, 1))
                    u = self.heavy[u]
            elif state == 1:
                stack.append((v, 2))
                for child in self.g.E[v]:
                    if child.dst not in [self.parent[v], self.heavy[v]]:
                        stack.append((child.dst, 0))
            else:
                self.tail[v] = k

    def lca(self, u, v):
        while self.head[u] != self.head[v]:
            if self.vid[u] > self.vid[v]:
                u, v = v, u
            v = self.parent[self.head[v]]
        else:
            if self.vid[u] > self.vid[v]:
                u, v = v, u
        return u

    def query_path(self, u, v, one, query, merge, edge: bool = False):
        # u, v の間のパスに対するクエリを計算する
        # one は単位元、query は列に対するクエリ、merge はマージする演算
        left = right = one
        while True:
            if self.vid[u] > self.vid[v]:
                u, v = v, u
                left, right = right, left
            if self.head[u] == self.head[v]:
                break
            left = merge(query(self.vid[self.head[v]], self.vid[v] + 1), left)
            v = self.parent[self.head[v]]
        return merge(merge(query(self.vid[u] + edge, self.vid[v] + 1), left), right)

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 347, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=self.cpp_source_path)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/other.py", line 48, in bundle
    return subprocess.check_output(shlex.split(command))
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/subprocess.py", line 411, in check_output
    return run(*popenargs, stdout=PIPE, timeout=timeout, check=True,
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/subprocess.py", line 512, in run
    raise CalledProcessError(retcode, process.args,
subprocess.CalledProcessError: Command '['false']' returned non-zero exit status 1.

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

