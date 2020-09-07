---
data:
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "def solve_discrete_logarithm(g: int, y: int, m: int) -> int:\n    \"\"\"\
    find x >= 0 s.t. g^x\u2261y (mod m) by baby-step giant-step\n    \"\"\"\n    if\
    \ m == 1:\n        return 0\n    if y == 1:\n        return 0\n    if g == 0 and\
    \ y == 0:\n        return 1\n\n    sqrt_m = int(pow(m, 0.5) + 100)\n\n    # Baby-step\n\
    \    memo = {}\n    baby = 1\n    for b in range(sqrt_m):\n        if baby ==\
    \ y:\n            return b\n        memo[baby * y % m] = b\n        baby = baby\
    \ * g % m\n\n    # Giant-step\n    giant = 1\n    for a in range(1, sqrt_m + 3):\n\
    \        giant = giant * baby % m\n        b = memo.get(giant, -1)\n        if\
    \ b >= 0:\n            x = a * sqrt_m - b\n            return x if pow(g, x, m)\
    \ == y else -1\n    return -1\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/python/disc_log.test.py
    title: tests/python/disc_log.test.py
  isVerificationFile: false
  path: python_library/math/disc_log.py
  requiredBy: []
  timestamp: '2020-02-16 06:11:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith:
  - tests/python/disc_log.test.py
documentation_of: python_library/math/disc_log.py
layout: document
redirect_from:
- /library/python_library/math/disc_log.py
- /library/python_library/math/disc_log.py.html
title: python_library/math/disc_log.py
---
