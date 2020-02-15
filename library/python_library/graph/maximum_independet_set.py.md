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


# :heavy_check_mark: python_library/graph/maximum_independet_set.py

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#7e80885bc8a78dc63feed9f40126ba0e">python_library/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/python_library/graph/maximum_independet_set.py">View this file on GitHub</a>
    - Last commit date: 2020-02-16 07:26:24+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/tests/maximum_independet_set.test.py.html">tests/maximum_independet_set.test.py</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
from python_library.misc.popcount import popcount


def maximum_independet_set(v: int, bad: int, adj_mat):
    """最大独立集合
    v: 今調べている頂点
    bad: 使わないと決めた頂点 (bit)
    adj_mat: 隣接行列 (bit のリスト)

    最大独立集合のサイズと最大独立集合を返す
    """
    if v == len(adj_mat):
        return 0, 0

    ret, ret_set = 0, 0

    deg = popcount(adj_mat[v] & ~bad)

    # use v
    if (bad >> v & 1) == 0:
        new_bad = bad | (1 << v) | (adj_mat[v] & ~bad)
        cand, cand_set = maximum_independet_set(v + 1, new_bad, adj_mat)
        if cand + 1 > ret:
            ret, ret_set = cand + 1, cand_set | (1 << v)

    # do not use v
    if deg > 1 or (bad >> v & 1):
        new_bad = bad
        if (bad >> v & 1) == 0:
            new_bad |= 1 << v
        cand, cand_set = maximum_independet_set(v + 1, new_bad, adj_mat)
        if cand > ret:
            ret, ret_set = cand, cand_set

    return ret, ret_set

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

