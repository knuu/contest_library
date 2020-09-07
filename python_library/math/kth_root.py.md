---
data:
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "def kth_root(n: int, k: int) -> int:\n    ret = int(pow(n, 1/k))\n    while\
    \ pow(ret, k) > n:\n        ret -= 1\n    while pow(ret + 1, k) <= n:\n      \
    \  ret += 1\n    return ret\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith:
  - icon: ':x:'
    path: tests/python/kth_root.test.py
    title: tests/python/kth_root.test.py
  isVerificationFile: false
  path: python_library/math/kth_root.py
  requiredBy: []
  timestamp: '2020-09-08 04:11:21+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verificationStatusIcon: ':x:'
  verifiedWith:
  - tests/python/kth_root.test.py
documentation_of: python_library/math/kth_root.py
layout: document
redirect_from:
- /library/python_library/math/kth_root.py
- /library/python_library/math/kth_root.py.html
title: python_library/math/kth_root.py
---
