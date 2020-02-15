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


# :heavy_check_mark: python_library/graph/tree_diameter.py

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#7e80885bc8a78dc63feed9f40126ba0e">python_library/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/python_library/graph/tree_diameter.py">View this file on GitHub</a>
    - Last commit date: 2020-02-16 07:49:55+09:00




## Depends on

* :heavy_check_mark: <a href="graph.py.html">python_library/graph/graph.py</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/tests/tree_diameter.test.py.html">tests/tree_diameter.test.py</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
# @import python_library/graph/graph.py
from python_library.graph.graph import Graph


class TreeDiameter:
    def __init__(self, graph: Graph) -> None:
        self.graph = graph
        self.diameter = None
        self.fathest_pair = None

    def run(self):
        _, v1 = self.calc_farthest(0, -1)
        diameter, v2 = self.calc_farthest(v1, -1)
        self.diameter = diameter
        self.fathest_pair = (v1, v2)
        return diameter

    def calc_farthest(self, target: int, par: int = -1):
        dists = [None] * self.graph.V
        stack = [(target, par)]

        while stack:
            v, par = stack[-1]
            if dists[v] is None:
                dists[v] = (0, v)
                for child in self.graph.E[v]:
                    if child.dst == par:
                        continue
                    stack.append((child.dst, v))
            else:
                stack.pop()
                ret_dist, ret_v = dists[v]
                for child in self.graph.E[v]:
                    if child.dst == par:
                        continue
                    cand_dist, cand_v = dists[child.dst]
                    if cand_dist + child.weight > ret_dist:
                        ret_dist = cand_dist + child.weight
                        ret_v = cand_v
                dists[v] = (ret_dist, ret_v)

        return dists[target]

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

