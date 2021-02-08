---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: py
  _verificationStatusIcon: ':x:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# verify-helper: PROBLEM https://judge.yosupo.jp/problem/point_set_range_composite\n\
    import sys\n\nfrom python_library.data_structures.segment_tree import SegmentTree\n\
    \ninput = sys.stdin.buffer.readline\n\n\ndef main() -> None:\n    N, Q = map(int,\
    \ input().split())\n    A = [tuple(map(int, input().split())) for _ in range(N)]\n\
    \    mod = 998244353\n\n    def merge(l, r, mod=mod):\n        return l[0] * r[0]\
    \ % mod, (l[1] * r[0] + r[1]) % mod\n\n    segt = SegmentTree.create_from_array(A,\
    \ merge, (1, 0))\n    ans = []\n    for _ in range(Q):\n        t, a, b, c = map(int,\
    \ input().split())\n        if t == 0:\n            segt[a] = (b, c)\n       \
    \ else:\n            a1, a2 = segt.query(a, b)\n            ans.append((a1 * c\
    \ + a2) % mod)\n    print(*ans, sep=\"\\n\")\n\n\nif __name__ == \"__main__\"\
    :\n    main()\n"
  dependsOn: []
  isVerificationFile: true
  path: tests/python/segment_tree_point_set_range_composite.test.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/python/segment_tree_point_set_range_composite.test.py
layout: document
redirect_from:
- /verify/tests/python/segment_tree_point_set_range_composite.test.py
- /verify/tests/python/segment_tree_point_set_range_composite.test.py.html
title: tests/python/segment_tree_point_set_range_composite.test.py
---
