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


# :warning: python-library/data_structures/segment_tree.py

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#74e532415b57ead1fa84cab4b59648ab">python-library/data_structures</a>
* <a href="{{ site.github.repository_url }}/blob/master/python-library/data_structures/segment_tree.py">View this file on GitHub</a>
    - Last commit date: 2020-01-21 04:11:11+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
import sys
input = sys.stdin.readline


class SegmentTree:
    """Segment Tree (Point Update & Range Query)

    Query
        1. update(i, val): update i-th value to val
        2. query(low, high): find f(value) in [low, high)

    Complexity
        time complexity: O(log n)
        space complexity: O(n)
    """

    def __init__(self, N, f, default):
        self.N = 1 << (N-1).bit_length()
        self.default = default
        self.f = f
        self.segtree = [self.default] * ((self.N << 1) - 1)

    @classmethod
    def create_from_array(cls, arr, f, default):
        N = len(arr)
        self = cls(N, f, default)
        for i in range(N):
            self.segtree[self.N - 1 + i] = arr[i]

        for i in reversed(range(self.N - 1)):
            self.segtree[i] = self.f(
                self.segtree[(i << 1) + 1], self.segtree[(i << 1) + 2])
        return self

    def update(self, i, val):
        i += self.N - 1
        self.segtree[i] = val
        while i > 0:
            i = (i - 1) >> 1
            self.segtree[i] = self.f(
                self.segtree[(i << 1) + 1], self.segtree[(i << 1) + 2])

    def __getitem__(self, k):
        return self.segtree[self.N - 1 + k]

    def query(self, low, high):
        # query [l, r)
        low, high = low + self.N, high + self.N
        ret = self.default
        while low < high:
            if low & 1:
                ret = self.f(ret, self.segtree[low-1])
                low += 1
            if high & 1:
                high -= 1
                ret = self.f(ret, self.segtree[high-1])
            low, high = low >> 1, high >> 1
        return ret


def yosupo1():
    # https://judge.yosupo.jp/problem/staticrmq
    _, Q = map(int, input().split())
    A = [int(x) for x in input().split()]
    rmq = SegmentTree.create_from_array(A, min, 10**9)
    ans = []
    for _ in range(Q):
        l, r = map(int, input().split())
        ans.append(rmq.query(l, r))
    print(*ans, sep="\n")


def yosupo2():
    # https://judge.yosupo.jp/problem/point_add_range_sum
    import operator
    _, Q = map(int, input().split())
    A = [int(x) for x in input().split()]
    rsq = SegmentTree.create_from_array(A, operator.add, 0)
    ans = []
    for _ in range(Q):
        type_, l, r = map(int, input().split())
        if type_ == 0:
            rsq.update(l, rsq[l] + r)
        else:
            ans.append(rsq.query(l, r))
    print(*ans, sep="\n")


def aoj():
    # https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
    N, Q = map(int, input().split())
    default = (1 << 31) - 1
    rmq = SegmentTree(N, min, default)
    for _ in range(Q):
        com, x, y = map(int, input().split())
        if com == 0:
            rmq.update(x, y)
        else:
            print(rmq.query(x, y+1))


if __name__ == '__main__':
    # yosupo1()
    yosupo2()
    # aoj()

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

