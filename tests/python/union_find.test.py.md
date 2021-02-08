---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: python_library/data_structures/unionfind.py
    title: python_library/data_structures/unionfind.py
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# verify-helper: PROBLEM https://judge.yosupo.jp/problem/unionfind\nimport\
    \ sys\n\nfrom python_library.data_structures.unionfind import UnionFindTree\n\n\
    input = sys.stdin.buffer.readline\n\n\ndef main() -> None:\n    N, Q = map(int,\
    \ input().split())\n    uft = UnionFindTree(N)\n    ans = []\n    for _ in range(Q):\n\
    \        t, u, v = map(int, input().split())\n        if t == 0:\n           \
    \ uft.unite(u, v)\n        else:\n            ans.append(int(uft.is_same(u, v)))\n\
    \    print(*ans, sep=\"\\n\")\n\n\nif __name__ == \"__main__\":\n    main()\n"
  dependsOn:
  - python_library/data_structures/unionfind.py
  isVerificationFile: true
  path: tests/python/union_find.test.py
  requiredBy: []
  timestamp: '2020-09-08 06:49:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/python/union_find.test.py
layout: document
redirect_from:
- /verify/tests/python/union_find.test.py
- /verify/tests/python/union_find.test.py.html
title: tests/python/union_find.test.py
---
