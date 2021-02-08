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
  code: "mod = 10**9+7\n\n\ndef inv(x):\n    return pow(x, mod - 2, mod)\n\n\ndef\
    \ nCk(n, k):\n    assert 0 <= k <= n\n    k = min(k, n - k)\n    ret = 1\n   \
    \ for i in range(k):\n        ret *= n - i\n        ret %= mod\n        ret *=\
    \ inv(i + 1)\n        ret %= mod\n    return ret\n\n\ndef nHk(n, k):\n    assert\
    \ 1 <= k <= n\n    return nCk(n + k - 1, k - 1)\n"
  dependsOn: []
  isVerificationFile: false
  path: python_library/math/combinations.py
  requiredBy: []
  timestamp: '2020-02-16 02:53:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: python_library/math/combinations.py
layout: document
redirect_from:
- /library/python_library/math/combinations.py
- /library/python_library/math/combinations.py.html
title: python_library/math/combinations.py
---
