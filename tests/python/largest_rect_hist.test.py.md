---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: python_library/dynamic_programming/largest_rect_hist.py
    title: python_library/dynamic_programming/largest_rect_hist.py
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# verify-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C\n\
    import sys\n\nfrom python_library.dynamic_programming.largest_rect_hist import\
    \ (\n    calc_largest_rect_in_hist,\n)\n\ninput = sys.stdin.buffer.readline\n\n\
    \ndef main() -> None:\n    input()\n    print(calc_largest_rect_in_hist([int(x)\
    \ for x in input().split()]))\n\n\nif __name__ == \"__main__\":\n    main()\n"
  dependsOn:
  - python_library/dynamic_programming/largest_rect_hist.py
  isVerificationFile: true
  path: tests/python/largest_rect_hist.test.py
  requiredBy: []
  timestamp: '2020-09-08 04:10:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/python/largest_rect_hist.test.py
layout: document
redirect_from:
- /verify/tests/python/largest_rect_hist.test.py
- /verify/tests/python/largest_rect_hist.test.py.html
title: tests/python/largest_rect_hist.test.py
---
