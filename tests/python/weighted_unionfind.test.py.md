---
data:
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# verify-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B\n\
    import sys\n\nfrom python_library.data_structures.weighted_unionfind import WeightedUnionFindTree\n\
    \ninput = sys.stdin.buffer.readline\n\n\ndef main() -> None:\n    N, Q = map(int,\
    \ input().split())\n    uft = WeightedUnionFindTree(N)\n    ans = []\n    for\
    \ _ in range(Q):\n        type_, u, v, *weight = map(int, input().split())\n \
    \       if type_ == 0:\n            uft.unite(u, v, weight[0])\n        else:\n\
    \            ans.append(uft.diff(u, v) if uft.is_same(u, v) else \"?\")\n    print(\"\
    \\n\".join(map(str, ans)))\n\n\nif __name__ == \"__main__\":\n    main()\n"
  dependsOn:
  - python_library/data_structures/weighted_unionfind.py
  extendedDependsOn:
  - icon: ':x:'
    path: python_library/data_structures/weighted_unionfind.py
    title: python_library/data_structures/weighted_unionfind.py
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: tests/python/weighted_unionfind.test.py
  requiredBy: []
  timestamp: '2020-09-08 04:10:45+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verificationStatusIcon: ':x:'
  verifiedWith: []
documentation_of: tests/python/weighted_unionfind.test.py
layout: document
redirect_from:
- /verify/tests/python/weighted_unionfind.test.py
- /verify/tests/python/weighted_unionfind.test.py.html
title: tests/python/weighted_unionfind.test.py
---
