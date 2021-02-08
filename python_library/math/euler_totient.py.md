---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/python/euler_totient.test.py
    title: tests/python/euler_totient.test.py
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "def euler_totient(n):\n    if n <= 0:\n        return 0\n    ans = n\n  \
    \  i = 2\n    while i * i <= n:\n        if n % i == 0:\n            ans -= ans\
    \ // i\n            while n % i == 0:\n                n //= i\n        i += 1\n\
    \    if n > 1:\n        ans -= ans // n\n    return ans\n"
  dependsOn: []
  isVerificationFile: false
  path: python_library/math/euler_totient.py
  requiredBy: []
  timestamp: '2020-02-16 06:11:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/python/euler_totient.test.py
documentation_of: python_library/math/euler_totient.py
layout: document
redirect_from:
- /library/python_library/math/euler_totient.py
- /library/python_library/math/euler_totient.py.html
title: python_library/math/euler_totient.py
---
