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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_B
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# verify-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_B\n\
    import sys\n\nfrom python_library.dynamic_programming.largest_rect_hist import\
    \ (\n    calc_largest_rect_in_hist,\n)\n\ninput = sys.stdin.buffer.readline\n\n\
    \ndef main() -> None:\n    H, W = map(int, input().split())\n    board = [[int(x)\
    \ for x in input().split()] for _ in range(H)]\n    dp = [0] * W\n    ret = 0\n\
    \    for r in range(H):\n        for c in range(W):\n            dp[c] = dp[c]\
    \ + 1 if board[r][c] == 0 else 0\n        ret = max(ret, calc_largest_rect_in_hist(dp))\n\
    \    print(ret)\n\n\nif __name__ == \"__main__\":\n    main()\n"
  dependsOn:
  - python_library/dynamic_programming/largest_rect_hist.py
  isVerificationFile: true
  path: tests/python/largest_rect_rect.test.py
  requiredBy: []
  timestamp: '2020-09-08 04:10:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/python/largest_rect_rect.test.py
layout: document
redirect_from:
- /verify/tests/python/largest_rect_rect.test.py
- /verify/tests/python/largest_rect_rect.test.py.html
title: tests/python/largest_rect_rect.test.py
---
