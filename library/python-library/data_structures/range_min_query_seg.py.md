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


# :warning: python-library/data_structures/range_min_query_seg.py

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#74e532415b57ead1fa84cab4b59648ab">python-library/data_structures</a>
* <a href="{{ site.github.repository_url }}/blob/master/python-library/data_structures/range_min_query_seg.py">View this file on GitHub</a>
    - Last commit date: 2019-04-11 03:52:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
import math


class RangeMinimumQuery:
    """
    RangeMinimumQuery by Segment Tree
    query:
    1. update(i, val): update i-th value to val
    2. query(low, high): find minimun value in [low, high)
    time complexity: O(log n)
    space complexity: O(2n)
    used in DSL2A(AOJ)
    """
    def __init__(self, N, INF=float('inf')):
        self.N = 1 << math.ceil(math.log(N, 2))
        self.INF = INF
        self.segtree = [self.INF] * (self.N * 2 - 1)

    def update(self, i, val):
        i += self.N - 1
        self.segtree[i] = val
        while i > 0:
            i = (i - 1) // 2
            self.segtree[i] = min(self.segtree[2*i+1], self.segtree[2*i+2])

    def query(self, low, high, k=0, left=0, right=-1):
        if right == -1:
            right = self.N
        if right <= low or high <= left:
            return self.INF

        if low <= left and right <= high:
            return self.segtree[k]
        else:
            mid = (left + right) // 2
            return min(self.query(low, high, 2*k+1, left, mid),
                       self.query(low, high, 2*k+2, mid, right))

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

