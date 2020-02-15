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


# :x: tests/two_sat.test.py

<a href="../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/tests/two_sat.test.py">View this file on GitHub</a>
    - Last commit date: 2020-02-16 04:55:42+09:00




## Depends on

* :x: <a href="../../library/python_library/graph/two_sat.py.html">python_library/graph/two_sat.py</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
# verify-helper: PROBLEM https://judge.yosupo.jp/problem/two_sat
# @import python_library/graph/two_sat.py
import sys

sys.path.insert(0, ".")

input = sys.stdin.buffer.readline
sys.setrecursionlimit(10 ** 6 + 100)

from python_library.graph.two_sat import TwoSat


def main() -> None:
    _, _, *NM = input().split()
    N, M = map(int, NM)
    sat = TwoSat(N)
    for _ in range(M):
        u, v, _ = map(int, input().split())
        sat.add_constraint(u, v)
    if sat.run():
        print("s SATISFIABLE")
        print("v", *[i + 1 if sat.ans[i] else -(i + 1) for i in range(N)], 0)
    else:
        print("s UNSATISFIABLE")


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

