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
  code: "from copy import deepcopy\nfrom typing import List\n\n\ndef linear_recursion_solver(a:\
    \ List[int], x: List[int], k: int, e0: int = 0, e1: int = 1) -> int:\n    def\
    \ rec(k: int) -> List[int]:\n        c = [e0] * n\n        if k < n:\n       \
    \     c[k] = e1\n            return c[:]\n        b = rec(k // 2)\n        t =\
    \ [e0] * (2 * n + 1)\n        for i in range(n):\n            for j in range(n):\n\
    \                t[i + j + (k & 1)] += b[i] * b[j]\n        for i in reversed(range(n,\
    \ 2*n)):\n            for j in range(n):\n                t[i - n + j] += a[j]\
    \ * t[i]\n        for i in range(n):\n            c[i] = t[i]\n        return\
    \ c[:]\n    n = len(a)\n    c = rec(k)\n    return sum(ci * xi for ci, xi in zip(c,\
    \ x))\n\nassert(linear_recursion_solver([1, 2, 3], [6, 5, 4], 10) == 220696)\n"
  dependsOn: []
  isVerificationFile: false
  path: python_library_typed/math/linear_recursion_solver.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: python_library_typed/math/linear_recursion_solver.py
layout: document
redirect_from:
- /library/python_library_typed/math/linear_recursion_solver.py
- /library/python_library_typed/math/linear_recursion_solver.py.html
title: python_library_typed/math/linear_recursion_solver.py
---
