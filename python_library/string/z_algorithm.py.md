---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/python/z_algorithm.test.py
    title: tests/python/z_algorithm.test.py
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "def z_algorithm(S: str):\n    ret = [0] * len(S)\n    ret[0] = len(S)\n \
    \   i, j = 1, 0\n    while i < len(S):\n        while i + j < len(S) and S[j]\
    \ == S[i + j]:\n            j += 1\n        ret[i] = j\n        if j == 0:\n \
    \           i += 1\n            continue\n        k = 1\n        while i + k <\
    \ len(S) and k + ret[k] < j:\n            ret[i + k] = ret[k]\n            k +=\
    \ 1\n        i, j = i + k, j - k\n    return ret\n"
  dependsOn: []
  isVerificationFile: false
  path: python_library/string/z_algorithm.py
  requiredBy: []
  timestamp: '2020-02-16 05:33:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/python/z_algorithm.test.py
documentation_of: python_library/string/z_algorithm.py
layout: document
redirect_from:
- /library/python_library/string/z_algorithm.py
- /library/python_library/string/z_algorithm.py.html
title: python_library/string/z_algorithm.py
---
