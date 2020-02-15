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


# :warning: python_library_typed/graph/heavy_light_decomposition.py

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#2a7e3e97022ce18b59747afed7368880">python_library_typed/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/python_library_typed/graph/heavy_light_decomposition.py">View this file on GitHub</a>
    - Last commit date: 2020-02-16 02:53:38+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
from typing import List, TypeVar, Generic, Tuple
T = TypeVar('T', int, float)


class Edge(Generic[T]):
    def __init__(self, dst: int, weight: T) -> None:
        self.dst: int = dst
        self.weight: T = weight

    def __lt__(self, e: 'Edge') -> bool:
        return self.weight > e.weight


class Graph(Generic[T]):
    def __init__(self, V: int) -> None:
        self.V: int = V
        self.E: List[List[Edge[T]]] = [[] for _ in range(V)]
        self.edge_size: int = 0

    def add_edge(self, src: int, dst: int, weight: T) -> None:
        self.E[src].append(Edge(dst, weight))
        self.edge_size += 1


class HeavyLightDecomposition(Generic[T]):
    def __init__(self, G: Graph[T]) -> None:
        self.G: Graph[T] = G
        self.vid: List[int] = [0] * G.V
        self.head: List[int] = [0] * G.V
        self.heavy: List[int] = [-1] * G.V
        self.parent: List[int] = [0] * G.V

    def run(self, root: int = 0) -> None:
        self.dfs(root)
        self.bfs(root)

    def dfs(self, root: int = 0) -> None:
        stack: List[Tuple[int, int, bool]] = [(root, -1, False)]
        sub: List[int] = [1] * self.G.V
        max_sub: List[Tuple[int, int]] = [(0, -1)] * self.G.V
        while stack:
            v: int
            par: int
            flag: bool
            v, par, flag = stack.pop()
            if not flag:
                self.parent[v] = par
                stack.append((v, par, True))
                stack.extend((e.dst, v, False) for e in self.G.E[v] if e.dst != par)
            else:
                if par != -1:
                    sub[par] += sub[v]
                    max_sub[par] = max(max_sub[par], (sub[v], v))
                self.heavy[v] = max_sub[v][1]

    def bfs(self, root: int = 0) -> None:
        from collections import deque
        k: int
        que: deque
        k, que = 0, deque([root])
        while que:
            r: int
            v: int
            r = v = que.popleft()
            while v != -1:
                self.vid[v], self.head[v] = k, r
                for e in self.G.E[v]:
                    if e.dst != self.parent[v] and e.dst != self.heavy[v]:
                        que.append(v)
                k += 1
                v = self.heavy[v]

    def lca(self, u: int, v: int) -> int:
        while self.head[u] != self.head[v]:
            if self.vid[u] > self.vid[v]:
                u, v = v, u
            v = self.parent[self.head[v]]
        else:
            if self.vid[u] > self.vid[v]:
                u, v = v, u
        return u

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/main.py", line 181, in main
    subcommand_run(paths=[], jobs=parsed.jobs)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/main.py", line 59, in subcommand_run
    onlinejudge_verify.verify.main(paths, marker=marker, timeout=timeout, jobs=jobs)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/verify.py", line 133, in main
    raise Exception('{} tests failed: {}'.format(len(failed_test_paths), [str(path.relative_to(pathlib.Path.cwd())) for path in failed_test_paths]))
Exception: 1 tests failed: ['tests/range_tree_2d.test.py']

During handling of the above exception, another exception occurred:

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

