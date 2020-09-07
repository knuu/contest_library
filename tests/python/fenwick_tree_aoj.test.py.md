---
data:
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# verify-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\n\
    import sys\n\nfrom python_library.data_structures.fenwick_tree import FenwickTree\n\
    \ninput = sys.stdin.buffer.readline\n\n\ndef main() -> None:\n    N, Q = map(int,\
    \ input().split())\n    fwt = FenwickTree([0] * N)\n    ans = []\n    for _ in\
    \ range(Q):\n        type_, l, r = map(int, input().split())\n        if type_\
    \ == 0:\n            fwt.add(l - 1, r)\n        else:\n            ans.append(fwt.query(l\
    \ - 2, r - 1))\n    print(*ans, sep=\"\\n\")\n\n\nif __name__ == \"__main__\"\
    :\n    main()\n"
  dependsOn:
  - python_library/data_structures/fenwick_tree.py
  extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: python_library/data_structures/fenwick_tree.py
    title: python_library/data_structures/fenwick_tree.py
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: tests/python/fenwick_tree_aoj.test.py
  requiredBy: []
  timestamp: '2020-09-08 06:49:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith: []
documentation_of: tests/python/fenwick_tree_aoj.test.py
layout: document
redirect_from:
- /verify/tests/python/fenwick_tree_aoj.test.py
- /verify/tests/python/fenwick_tree_aoj.test.py.html
title: tests/python/fenwick_tree_aoj.test.py
---
