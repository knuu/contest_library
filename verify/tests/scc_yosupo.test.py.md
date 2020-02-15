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


# :heavy_check_mark: tests/scc_yosupo.test.py

<a href="../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/tests/scc_yosupo.test.py">View this file on GitHub</a>
    - Last commit date: 2020-02-16 07:49:55+09:00




## Depends on

* :heavy_check_mark: <a href="../../library/python_library/graph/scc.py.html">python_library/graph/scc.py</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
# verify-helper: PROBLEM https://judge.yosupo.jp/problem/scc
# @import python_library/graph/scc.py
import sys

sys.path.insert(0, ".")
input = sys.stdin.buffer.readline
sys.setrecursionlimit(6 * 10 ** 5)

from python_library.graph.scc import StronglyConnectedComponets


def main() -> None:
    N, M = map(int, input().split())
    scc = StronglyConnectedComponets(N)
    for _ in range(M):
        u, v = map(int, input().split())
        scc.add_edge(u, v)
    scc.run()
    ans_size = max(scc.order) + 1
    ans = [[] for _ in range(ans_size)]
    for i, c in enumerate(scc.order):
        ans[c].append(i)
    print(ans_size)
    for row in ans:
        print(len(row), *row)


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

