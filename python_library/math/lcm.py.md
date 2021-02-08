---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/python/lcm.test.py
    title: tests/python/lcm.test.py
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "from math import gcd\n\n\ndef lcm(arr):\n    ret = 1\n    for a in arr:\n\
    \        ret = ret * a // gcd(ret, a)\n    return ret\n"
  dependsOn: []
  isVerificationFile: false
  path: python_library/math/lcm.py
  requiredBy: []
  timestamp: '2020-02-16 06:11:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/python/lcm.test.py
documentation_of: python_library/math/lcm.py
layout: document
redirect_from:
- /library/python_library/math/lcm.py
- /library/python_library/math/lcm.py.html
title: python_library/math/lcm.py
---
