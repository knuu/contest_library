---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "eps = 1e-10\n\n\ndef add(a, b):\n    return 0 if abs(a + b) < eps * (abs(a)\
    \ + abs(b)) else a + b\n\n\nclass Point:\n    def __init__(self, x, y):\n    \
    \    self.x = x\n        self.y = y\n\n    def __add__(self, p):\n        return\
    \ Point(add(self.x, p.x), add(self.y, p.y))\n\n    def __sub__(self, p):\n   \
    \     return Point(add(self.x, -p.x), add(self.y, -p.y))\n\n    def __mul__(self,\
    \ d):\n        return Point(self.x * d, self.y * d)\n\n    def dot(self, p):\n\
    \        return add(self.x * p.x, self.y * p.y)\n\n    def det(self, p):\n   \
    \     return add(self.x * p.y, -self.y * p.x)\n\n    def __str__(self):\n    \
    \    return \"({}, {})\".format(self.x, self.y)\n"
  dependsOn: []
  isVerificationFile: false
  path: python_library_typed/geometry/geometry.py
  requiredBy: []
  timestamp: '2020-02-16 02:53:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: python_library_typed/geometry/geometry.py
layout: document
redirect_from:
- /library/python_library_typed/geometry/geometry.py
- /library/python_library_typed/geometry/geometry.py.html
title: python_library_typed/geometry/geometry.py
---
