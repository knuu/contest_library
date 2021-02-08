---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: py
  _verificationStatusIcon: ':x:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# verify-helper: PROBLEM https://judge.yosupo.jp/problem/staticrmq\nimport\
    \ sys\n\nfrom python_library.data_structures.segment_tree import SegmentTree\n\
    \ninput = sys.stdin.buffer.readline\n\n\ndef main() -> None:\n    _, Q = map(int,\
    \ input().split())\n    A = [int(x) for x in input().split()]\n    rmq = SegmentTree.create_from_array(A,\
    \ min, 10 ** 9)\n    ans = []\n    for _ in range(Q):\n        l, r = map(int,\
    \ input().split())\n        ans.append(rmq.query(l, r))\n    print(*ans, sep=\"\
    \\n\")\n\n\nif __name__ == \"__main__\":\n    main()\n"
  dependsOn: []
  isVerificationFile: true
  path: tests/python/segment_tree_staticrmq.test.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/python/segment_tree_staticrmq.test.py
layout: document
redirect_from:
- /verify/tests/python/segment_tree_staticrmq.test.py
- /verify/tests/python/segment_tree_staticrmq.test.py.html
title: tests/python/segment_tree_staticrmq.test.py
---
