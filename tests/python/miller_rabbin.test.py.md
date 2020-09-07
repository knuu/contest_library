---
data:
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# verify-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\n\
    import sys\n\nfrom python_library.math.prime import miller_rabin\n\ninput = sys.stdin.buffer.readline\n\
    \n\ndef main() -> None:\n    N = int(input())\n    print(sum(miller_rabin(int(input()))\
    \ for _ in range(N)))\n\n\nif __name__ == \"__main__\":\n    main()\n"
  dependsOn:
  - python_library/math/prime.py
  extendedDependsOn:
  - icon: ':x:'
    path: python_library/math/prime.py
    title: python_library/math/prime.py
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: tests/python/miller_rabbin.test.py
  requiredBy: []
  timestamp: '2020-09-08 04:10:45+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verificationStatusIcon: ':x:'
  verifiedWith: []
documentation_of: tests/python/miller_rabbin.test.py
layout: document
redirect_from:
- /verify/tests/python/miller_rabbin.test.py
- /verify/tests/python/miller_rabbin.test.py.html
title: tests/python/miller_rabbin.test.py
---
