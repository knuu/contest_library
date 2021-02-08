---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: py
  _verificationStatusIcon: ':x:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# verify-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A\n\
    import sys\n\nfrom python_library.math.divisor import Divisor\n\ninput = sys.stdin.buffer.readline\n\
    \n\ndef main() -> None:\n    N = int(input())\n    p = Divisor(N)\n    print(\"\
    {}: \".format(N), end=\"\")\n    print(*[d for d, cnt in sorted(p.primeFactors().items())\
    \ for i in range(cnt)])\n\n\nif __name__ == \"__main__\":\n    main()\n"
  dependsOn: []
  isVerificationFile: true
  path: tests/python/prime_factorization.test.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/python/prime_factorization.test.py
layout: document
redirect_from:
- /verify/tests/python/prime_factorization.test.py
- /verify/tests/python/prime_factorization.test.py.html
title: tests/python/prime_factorization.test.py
---
