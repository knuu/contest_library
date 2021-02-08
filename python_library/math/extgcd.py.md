---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/python/extgcd.test.py
    title: tests/python/extgcd.test.py
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "def extgcd(a, b):\n    \"\"\"solve ax + by = gcd(a, b)\n       return x,\
    \ y, gcd(a, b)\n       used in NTL1E(AOJ)\n    \"\"\"\n    g = a\n    if b ==\
    \ 0:\n        x, y = 1, 0\n    else:\n        x, y, g = extgcd(b, a % b)\n   \
    \     x, y = y,  x - a // b * y\n    return x, y, g\n"
  dependsOn: []
  isVerificationFile: false
  path: python_library/math/extgcd.py
  requiredBy: []
  timestamp: '2020-02-16 02:53:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/python/extgcd.test.py
documentation_of: python_library/math/extgcd.py
layout: document
redirect_from:
- /library/python_library/math/extgcd.py
- /library/python_library/math/extgcd.py.html
title: python_library/math/extgcd.py
---
