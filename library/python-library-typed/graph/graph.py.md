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


# :warning: python-library-typed/graph/graph.py

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#e3e389e7cc07e0499572b6cf762b37a8">python-library-typed/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/python-library-typed/graph/graph.py">View this file on GitHub</a>
    - Last commit date: 2019-04-11 03:52:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
from typing import List, TypeVar, Generic, Type, Any
# WeightType = Union[int, float]
WeightType = TypeVar("WeightType", int, float)


class Edge(Generic[WeightType]):
    def __init__(self, src: int, dst: int) -> None:
        self.src: int = src
        self.dst: int = dst


class WeightedEdge(Edge[WeightType]):
    def __init__(self, src: int, dst: int, weight: WeightType) -> None:
        self.src: int = src
        self.dst: int = dst
        self.weight: WeightType = weight


class ResidualEdge(Edge[WeightType]):
    def __init__(self, src: int, dst: int, cap: WeightType) -> None:
        self.src: int = src
        self.dst: int = dst
        self.cap: WeightType = cap
        self.rev: int

    def reverse(self) -> "ResidualEdge":
        return ResidualEdge(self.dst, self.src, 0)


# EdgeType = Union[Edge, WeightedEdge, ResidualEdge]
EdgeType = TypeVar("EdgeType", Edge, WeightedEdge, ResidualEdge)


class Graph(Generic[WeightType, EdgeType]):
    def __init__(self, n: int, EdgeClass: Type[EdgeType]) -> None:
        pass

    def add_edge(self, *args: Any) -> None:
        pass

    def add_undirected_edge(self, *args: Any) -> None:
        pass


class AdjacencyList(Graph[WeightType, EdgeType]):
    def __init__(self, n: int, EdgeClass: Type[EdgeType]) -> None:
        self._graph: List[List[EdgeType]] = [[] for _ in range(n)]
        self.EdgeClass: Type[EdgeType] = EdgeClass

    def add_edge(self, *args: Any) -> None:
        edge: EdgeType = self.EdgeClass(*args)
        self._graph[edge.src].append(edge)

    def add_undirected_edge(self, *args: Any) -> None:
        edge: EdgeType = self.EdgeClass(*args)
        self._graph[edge.src].append(edge)
        edge.src, edge.dst = edge.dst, edge.src
        self._graph[edge.src].append(edge)

    def __getitem__(self, key: int) -> List[EdgeType]:
        return self._graph[key]


class ResidualGraph(AdjacencyList[WeightType, ResidualEdge]):
    def __init__(self, n: int) -> None:
        super().__init__(n, ResidualEdge)

    def add_edge(self, *args: Any) -> None:
        edge: ResidualEdge = self.EdgeClass(*args)
        edge.rev = len(self._graph[edge.dst])
        self._graph[edge.src].append(edge)
        rev: ResidualEdge = edge.reverse()
        rev.rev = len(self._graph[rev.dst]) - 1
        self._graph[edge.src].append(rev)

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
Exception: 1 tests failed: ['tests/tree_diameter.test.py']

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

