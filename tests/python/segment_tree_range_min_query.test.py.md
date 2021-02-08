---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: py
  _verificationStatusIcon: ':x:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# verify-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\n\
    import sys\n\nfrom python_library.data_structures.segment_tree import SegmentTree\n\
    \ninput = sys.stdin.buffer.readline\n\n\ndef main() -> None:\n    N, Q = map(int,\
    \ input().split())\n    default = (1 << 31) - 1\n    rmq = SegmentTree(N, min,\
    \ default)\n    for _ in range(Q):\n        com, x, y = map(int, input().split())\n\
    \        if com == 0:\n            rmq[x] = y\n        else:\n            print(rmq.query(x,\
    \ y + 1))\n\n\nif __name__ == \"__main__\":\n    main()\n"
  dependsOn: []
  isVerificationFile: true
  path: tests/python/segment_tree_range_min_query.test.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/python/segment_tree_range_min_query.test.py
layout: document
redirect_from:
- /verify/tests/python/segment_tree_range_min_query.test.py
- /verify/tests/python/segment_tree_range_min_query.test.py.html
title: tests/python/segment_tree_range_min_query.test.py
---
