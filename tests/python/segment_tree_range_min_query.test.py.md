---
data:
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# verify-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\n\
    import sys\n\nfrom python_library.data_structures.segment_tree import SegmentTree\n\
    \ninput = sys.stdin.buffer.readline\n\n\ndef main() -> None:\n    N, Q = map(int,\
    \ input().split())\n    default = (1 << 31) - 1\n    rmq = SegmentTree(N, min,\
    \ default)\n    for _ in range(Q):\n        com, x, y = map(int, input().split())\n\
    \        if com == 0:\n            rmq[x] = y\n        else:\n            print(rmq.query(x,\
    \ y + 1))\n\n\nif __name__ == \"__main__\":\n    main()\n"
  dependsOn:
  - python_library/data_structures/segment_tree.py
  extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: python_library/data_structures/segment_tree.py
    title: python_library/data_structures/segment_tree.py
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: tests/python/segment_tree_range_min_query.test.py
  requiredBy: []
  timestamp: '2020-09-08 22:41:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith: []
documentation_of: tests/python/segment_tree_range_min_query.test.py
layout: document
redirect_from:
- /verify/tests/python/segment_tree_range_min_query.test.py
- /verify/tests/python/segment_tree_range_min_query.test.py.html
title: tests/python/segment_tree_range_min_query.test.py
---