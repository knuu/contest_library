---
data:
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# verify-helper: PROBLEM https://judge.yosupo.jp/problem/unionfind\nimport\
    \ sys\n\nfrom python_library.data_structures.unionfind import UnionFindTree\n\n\
    input = sys.stdin.buffer.readline\n\n\ndef main() -> None:\n    N, Q = map(int,\
    \ input().split())\n    uft = UnionFindTree(N)\n    for _ in range(Q):\n     \
    \   t, u, v = map(int, input().split())\n        if t == 0:\n            uft.unite(u,\
    \ v)\n        else:\n            print(int(uft.is_same(u, v)))\n\n\nif __name__\
    \ == \"__main__\":\n    main()\n"
  dependsOn:
  - python_library/data_structures/unionfind.py
  extendedDependsOn:
  - icon: ':x:'
    path: python_library/data_structures/unionfind.py
    title: python_library/data_structures/unionfind.py
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: tests/python/union_find.test.py
  requiredBy: []
  timestamp: '2020-09-08 04:10:45+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verificationStatusIcon: ':x:'
  verifiedWith: []
documentation_of: tests/python/union_find.test.py
layout: document
redirect_from:
- /verify/tests/python/union_find.test.py
- /verify/tests/python/union_find.test.py.html
title: tests/python/union_find.test.py
---
