---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: python_library/math/disc_log.py
    title: python_library/math/disc_log.py
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/discrete_logarithm_mod
    links:
    - https://judge.yosupo.jp/problem/discrete_logarithm_mod
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# verify-helper: PROBLEM https://judge.yosupo.jp/problem/discrete_logarithm_mod\n\
    import sys\n\nfrom python_library.math.disc_log import solve_discrete_logarithm\n\
    \ninput = sys.stdin.buffer.readline\n\n\ndef main() -> None:\n    for _ in range(int(input())):\n\
    \        print(solve_discrete_logarithm(*map(int, input().split())))\n\n\nif __name__\
    \ == \"__main__\":\n    main()\n"
  dependsOn:
  - python_library/math/disc_log.py
  isVerificationFile: true
  path: tests/python/disc_log.test.py
  requiredBy: []
  timestamp: '2020-09-08 04:10:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/python/disc_log.test.py
layout: document
redirect_from:
- /verify/tests/python/disc_log.test.py
- /verify/tests/python/disc_log.test.py.html
title: tests/python/disc_log.test.py
---
