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


# :warning: python_library_typed/graph/bellman_ford.py

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#2a7e3e97022ce18b59747afed7368880">python_library_typed/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/python_library_typed/graph/bellman_ford.py">View this file on GitHub</a>
    - Last commit date: 2020-02-16 02:53:38+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
from typing import List, TypeVar, Generic
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

    def add_edge(self, src: int, dst: int, weight: T) -> None:
        self.E[src].append(Edge(dst, weight))


class BellmanFord(Generic[T]):
    def __init__(self, G: Graph[T]) -> None:
        self.G: Graph[T] = G

    def run(self, start: int = 0, INF: T = 10**9) -> None:
        self.distance: List[T] = [INF] * self.G.V  # distance from start
        self.prev: List[int] = [-1] * self.G.V  # prev vertex of shortest path
        self.distance[start] = 0
        self.negativeCycle: bool = False

        for i in range(self.G.V):
            update: bool = False
            for fr in range(self.G.V):
                for e in self.G.E[fr]:
                    if self.distance[fr] != INF and \
                       self.distance[fr] + e.weight < self.distance[e.dst]:
                        self.distance[e.dst] = self.distance[fr] + e.weight
                        self.prev[e.dst] = fr
                        update = True
                        if i == self.G.V - 1:
                            self.negativeCycle = True
            if update:
                break

    def getPath(self, end: int) -> List[int]:
        assert(not self.hasNegativeCycle())
        path: List[int] = [end]
        while self.prev[end] != -1:
            end = self.prev[end]
        return path[::-1]

    def hasNegativeCycle(self) -> bool:
        return self.negativeCycle

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

