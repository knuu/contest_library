---
data:
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# verify-helper: PROBLEM https://judge.yosupo.jp/problem/staticrmq\nimport\
    \ sys\n\nfrom python_library.data_structures.segment_tree import SegmentTree\n\
    \ninput = sys.stdin.buffer.readline\n\n\ndef main() -> None:\n    _, Q = map(int,\
    \ input().split())\n    A = [int(x) for x in input().split()]\n    rmq = SegmentTree.create_from_array(A,\
    \ min, 10 ** 9)\n    ans = []\n    for _ in range(Q):\n        l, r = map(int,\
    \ input().split())\n        ans.append(rmq.query(l, r))\n    print(*ans, sep=\"\
    \\n\")\n\n\nif __name__ == \"__main__\":\n    main()\n"
  dependsOn:
  - python_library/data_structures/segment_tree.py
  extendedDependsOn:
  - icon: ':x:'
    path: python_library/data_structures/segment_tree.py
    title: python_library/data_structures/segment_tree.py
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: tests/python/segment_tree_staticrmq.test.py
  requiredBy: []
  timestamp: '2020-09-08 04:10:45+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verificationStatusIcon: ':x:'
  verifiedWith: []
documentation_of: tests/python/segment_tree_staticrmq.test.py
layout: document
redirect_from:
- /verify/tests/python/segment_tree_staticrmq.test.py
- /verify/tests/python/segment_tree_staticrmq.test.py.html
title: tests/python/segment_tree_staticrmq.test.py
---
