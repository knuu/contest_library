---
data:
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# verify-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E\n\
    import sys\n\nfrom python_library.math.extgcd import extgcd\n\ninput = sys.stdin.buffer.readline\n\
    \n\ndef main() -> None:\n    print(*extgcd(*map(int, input().split()))[:-1])\n\
    \n\nif __name__ == \"__main__\":\n    main()\n"
  dependsOn:
  - python_library/math/extgcd.py
  extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: python_library/math/extgcd.py
    title: python_library/math/extgcd.py
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: tests/python/extgcd.test.py
  requiredBy: []
  timestamp: '2020-09-08 04:10:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith: []
documentation_of: tests/python/extgcd.test.py
layout: document
redirect_from:
- /verify/tests/python/extgcd.test.py
- /verify/tests/python/extgcd.test.py.html
title: tests/python/extgcd.test.py
---
