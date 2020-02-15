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


# :heavy_check_mark: python_library/geometry/convex_hull.py

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#bb1189d107afaf50a8d799c22c656ecc">python_library/geometry</a>
* <a href="{{ site.github.repository_url }}/blob/master/python_library/geometry/convex_hull.py">View this file on GitHub</a>
    - Last commit date: 2020-02-16 07:26:24+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/tests/convex_hull.test.py.html">tests/convex_hull.test.py</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
# used in AOJ No.68, yukicoder No.199
# complexity: O(n^(1/2))

from python_library.geometry.geometry import Point


class ConvexHull:
    def __init__(self, points) -> None:
        self.ps = points

    def run(self):
        ps = sorted(self.ps)
        lower_hull = self.get_bounds(ps)
        ps = ps[::-1]
        upper_hull = self.get_bounds(ps)
        del upper_hull[-1]
        del lower_hull[-1]
        lower_hull.extend(upper_hull)
        return lower_hull

    def get_bounds(self, ps):
        qs = [ps[0], ps[1]]
        for p in ps[2:]:
            while len(qs) > 1 and (qs[-1] - qs[-2]).det(p - qs[-1]) < 0:
                del qs[-1]
            qs.append(p)
        return qs

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

