---
data:
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# verify-helper: PROBLEM https://judge.yosupo.jp/problem/point_add_range_sum\n\
    import operator\nimport sys\n\nfrom python_library.data_structures.segment_tree\
    \ import SegmentTree\n\ninput = sys.stdin.buffer.readline\n\n\ndef main() -> None:\n\
    \    _, Q = map(int, input().split())\n    A = [int(x) for x in input().split()]\n\
    \    rsq = SegmentTree.create_from_array(A, operator.add, 0)\n    ans = []\n \
    \   for _ in range(Q):\n        type_, l, r = map(int, input().split())\n    \
    \    if type_ == 0:\n            rsq.update(l, rsq[l] + r)\n        else:\n  \
    \          ans.append(rsq.query(l, r))\n    print(*ans, sep=\"\\n\")\n\n\nif __name__\
    \ == \"__main__\":\n    main()\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: tests/python/segment_tree_point_add_range_sum.test.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verificationStatusIcon: ':x:'
  verifiedWith: []
documentation_of: tests/python/segment_tree_point_add_range_sum.test.py
layout: document
redirect_from:
- /verify/tests/python/segment_tree_point_add_range_sum.test.py
- /verify/tests/python/segment_tree_point_add_range_sum.test.py.html
title: tests/python/segment_tree_point_add_range_sum.test.py
---