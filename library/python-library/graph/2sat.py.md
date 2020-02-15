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


# :warning: python-library/graph/2sat.py

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#5d2e77d5b1ea9b487eb85cc662584fbc">python-library/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/python-library/graph/2sat.py">View this file on GitHub</a>
    - Last commit date: 2020-01-21 04:11:11+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
import sys
input = sys.stdin.buffer.readline
sys.setrecursionlimit(10 ** 6 + 100)


class StronglyConnectedComponets:
    def __init__(self, n: int) -> None:
        self.n = n
        self.edges = [[] for _ in range(n)]
        self.rev_edeges = [[] for _ in range(n)]
        self.vs = []
        self.order = [0] * n
        self.used = [False] * n

    def add_edge(self, from_v: int, to_v: int) -> None:
        self.edges[from_v].append(to_v)
        self.rev_edeges[to_v].append(from_v)

    def dfs(self, v) -> None:
        self.used[v] = True
        for child in self.edges[v]:
            if not self.used[child]:
                self.dfs(child)
        self.vs.append(v)

    def rdfs(self, v, k) -> None:
        self.used[v] = True
        self.order[v] = k
        for child in self.rev_edeges[v]:
            if not self.used[child]:
                self.rdfs(child, k)

    def run(self) -> int:
        self.used = [False] * self.n
        self.vs.clear()
        for v in range(self.n):
            if not self.used[v]:
                self.dfs(v)
        self.used = [False] * self.n
        k = 0
        for v in reversed(self.vs):
            if not self.used[v]:
                self.rdfs(v, k)
                k += 1
        return k


class TwoSat(StronglyConnectedComponets):
    def __init__(self, num_var: int) -> None:
        super().__init__(2 * num_var + 1)
        self.num_var = num_var
        self.ans = []

    def add_constraint(self, a: int, b: int) -> None:
        super().add_edge(self._neg(a), self._pos(b))
        super().add_edge(self._neg(b), self._pos(a))

    def _pos(self, v: int) -> int:
        return v if v > 0 else self.num_var - v

    def _neg(self, v: int) -> int:
        return self.num_var + v if v > 0 else -v

    def run(self) -> bool:
        super().run()
        self.ans.clear()
        for i in range(self.num_var):
            if self.order[i + 1] == self.order[i + self.num_var + 1]:
                return False
            self.ans.append(self.order[i + 1] >
                            self.order[i + self.num_var + 1])
        return True


def yosupo():
    # https://judge.yosupo.jp/problem/two_sat
    _, _, *NM = input().split()
    N, M = map(int, NM)
    sat = TwoSat(N)
    for _ in range(M):
        u, v, _ = map(int, input().split())
        sat.add_constraint(u, v)
    if sat.run():
        print("s SATISFIABLE")
        print("v", *[i+1 if sat.ans[i] else -(i+1) for i in range(N)], 0)
    else:
        print("s UNSATISFIABLE")


if __name__ == "__main__":
    yosupo()

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

