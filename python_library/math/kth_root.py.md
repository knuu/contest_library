---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/python/kth_root.test.py
    title: tests/python/kth_root.test.py
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "def kth_root(n: int, k: int) -> int:\n    ret = int(pow(n, 1/k))\n    while\
    \ pow(ret, k) > n:\n        ret -= 1\n    while pow(ret + 1, k) <= n:\n      \
    \  ret += 1\n    return ret\n"
  dependsOn: []
  isVerificationFile: false
  path: python_library/math/kth_root.py
  requiredBy: []
  timestamp: '2020-09-08 04:11:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/python/kth_root.test.py
documentation_of: python_library/math/kth_root.py
layout: document
redirect_from:
- /library/python_library/math/kth_root.py
- /library/python_library/math/kth_root.py.html
title: python_library/math/kth_root.py
---
