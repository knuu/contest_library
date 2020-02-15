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


# :heavy_check_mark: tests/hld_vertex_add_subtree_sum.test.py

<a href="../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/tests/hld_vertex_add_subtree_sum.test.py">View this file on GitHub</a>
    - Last commit date: 2020-02-16 07:49:55+09:00




## Depends on

* :heavy_check_mark: <a href="../../library/python_library/data_structures/segment_tree.py.html">python_library/data_structures/segment_tree.py</a>
* :heavy_check_mark: <a href="../../library/python_library/graph/graph.py.html">python_library/graph/graph.py</a>
* :heavy_check_mark: <a href="../../library/python_library/graph/heavy_light_decomposition.py.html">python_library/graph/heavy_light_decomposition.py</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
# verify-helper: PROBLEM https://judge.yosupo.jp/problem/vertex_add_subtree_sum
# @import python_library/data_structures/segment_tree.py
# @import python_library/graph/graph.py
# @import python_library/graph/heavy_light_decomposition.py
import operator
import sys

sys.path.insert(0, ".")
input = sys.stdin.buffer.readline

from python_library.data_structures.segment_tree import SegmentTree
from python_library.graph.graph import Graph
from python_library.graph.heavy_light_decomposition import HeavyLightDecomposition


def main() -> None:
    N, Q = map(int, input().split())
    weights = [int(x) for x in input().split()]
    graph = Graph(N)
    for i, v in enumerate(map(int, input().split())):
        graph.add_edge(i + 1, v, 1)
        graph.add_edge(v, i + 1, 1)
    hld = HeavyLightDecomposition(graph, 0, True)
    new_weights = [0] * N
    for i in range(N):
        new_weights[hld.vid[i]] = weights[i]
    rsq = SegmentTree.create_from_array(new_weights, operator.add, 0)

    ans = []
    for _ in range(Q):
        query = [int(x) for x in input().split()]
        if query[0] == 0:
            a, b = query[1:]
            rsq.update(hld.vid[a], rsq[hld.vid[a]] + b)
        else:
            u = query[1]
            ans.append(rsq.query(hld.vid[u], hld.tail[u]))
    print(*ans, sep="\n")


if __name__ == "__main__":
    main()

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

<a href="../../index.html">Back to top page</a>

