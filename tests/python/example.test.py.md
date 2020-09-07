---
data:
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# verify-helper: PROBLEM https://judge.yosupo.jp/problem/aplusb\n\n\ndef\
    \ main() -> None:\n    A, B = map(int, input().split())\n    print(A + B)\n\n\n\
    if __name__ == '__main__':\n    main()\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: tests/python/example.test.py
  requiredBy: []
  timestamp: '2020-09-08 03:58:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith: []
documentation_of: tests/python/example.test.py
layout: document
redirect_from:
- /verify/tests/python/example.test.py
- /verify/tests/python/example.test.py.html
title: tests/python/example.test.py
---
