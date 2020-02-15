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


# :warning: python-library/math/disc_log.py

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#46135b5961b59dd324f9733fc6b28247">python-library/math</a>
* <a href="{{ site.github.repository_url }}/blob/master/python-library/math/disc_log.py">View this file on GitHub</a>
    - Last commit date: 2020-01-21 04:11:11+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
def solve_discrete_logarithm(g: int, y: int, m: int) -> int:
    """find x >= 0 s.t. g^x≡y (mod m) by baby-step giant-step
    """
    if m == 1:
        return 0
    if y == 1:
        return 0
    if g == 0 and y == 0:
        return 1

    sqrt_m = int(pow(m, 0.5) + 100)

    # Baby-step
    memo = {}
    baby = 1
    for b in range(sqrt_m):
        if baby == y:
            return b
        memo[baby * y % m] = b
        baby = baby * g % m

    # Giant-step
    giant = 1
    for a in range(1, sqrt_m + 3):
        giant = giant * baby % m
        b = memo.get(giant, -1)
        if b >= 0:
            x = a * sqrt_m - b
            return x if pow(g, x, m) == y else -1
    return -1


def yosupo():
    # https://judge.yosupo.jp/problem/discrete_logarithm_mod
    for _ in range(int(input())):
        print(solve_discrete_logarithm(*map(int, input().split())))


if __name__ == "__main__":
    yosupo()

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

