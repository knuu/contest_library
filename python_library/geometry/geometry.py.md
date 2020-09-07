---
data:
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "def add(a, b, eps=1e-10):\n    return 0 if abs(a + b) < eps * (abs(a) + abs(b))\
    \ else a + b\n\n\nclass Point:\n    def __init__(self, x, y):\n        self.x\
    \ = x\n        self.y = y\n\n    def __add__(self, p):\n        return Point(add(self.x,\
    \ p.x), add(self.y, p.y))\n\n    def __sub__(self, p):\n        return Point(add(self.x,\
    \ -p.x), add(self.y, -p.y))\n\n    def __mul__(self, d):\n        return Point(self.x\
    \ * d, self.y * d)\n\n    def __lt__(self, p):\n        return (self.x, self.y)\
    \ < (p.x, p.y)\n\n    def dot(self, p):\n        return add(self.x * p.x, self.y\
    \ * p.y)\n\n    def det(self, p):\n        return add(self.x * p.y, -self.y *\
    \ p.x)\n\n    def __str__(self):\n        return \"({}, {})\".format(self.x, self.y)\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: python_library/geometry/convex_hull.py
    title: python_library/geometry/convex_hull.py
  extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/python/convex_hull.test.py
    title: tests/python/convex_hull.test.py
  isVerificationFile: false
  path: python_library/geometry/geometry.py
  requiredBy:
  - python_library/geometry/convex_hull.py
  timestamp: '2020-02-16 06:44:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith:
  - tests/python/convex_hull.test.py
documentation_of: python_library/geometry/geometry.py
layout: document
redirect_from:
- /library/python_library/geometry/geometry.py
- /library/python_library/geometry/geometry.py.html
title: python_library/geometry/geometry.py
---
