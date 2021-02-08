---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: python_library/math/euler_totient.py
    title: python_library/math/euler_totient.py
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# verify-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D\n\
    import sys\n\nfrom python_library.math.euler_totient import euler_totient\n\n\
    input = sys.stdin.buffer.readline\n\n\ndef main() -> None:\n    print(euler_totient(int(input())))\n\
    \n\nif __name__ == \"__main__\":\n    main()\n"
  dependsOn:
  - python_library/math/euler_totient.py
  isVerificationFile: true
  path: tests/python/euler_totient.test.py
  requiredBy: []
  timestamp: '2020-09-08 04:10:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/python/euler_totient.test.py
layout: document
redirect_from:
- /verify/tests/python/euler_totient.test.py
- /verify/tests/python/euler_totient.test.py.html
title: tests/python/euler_totient.test.py
---
