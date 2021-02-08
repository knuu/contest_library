---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: py
  _verificationStatusIcon: ':x:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/maximum_independent_set
    links:
    - https://judge.yosupo.jp/problem/maximum_independent_set
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# verify-helper: PROBLEM https://judge.yosupo.jp/problem/maximum_independent_set\n\
    import sys\n\nfrom python_library.graph.maximum_independet_set import maximum_independet_set\n\
    \ninput = sys.stdin.buffer.readline\n\n\ndef main() -> None:\n    N, M = map(int,\
    \ input().split())\n    adj_mat = [0] * N\n    for _ in range(M):\n        u,\
    \ v = map(int, input().split())\n        adj_mat[u] |= 1 << v\n        adj_mat[v]\
    \ |= 1 << u\n    size, mis = maximum_independet_set(0, 0, adj_mat)\n    print(size)\n\
    \    print(*[i for i in range(N) if mis >> i & 1])\n\n\nif __name__ == \"__main__\"\
    :\n    main()\n"
  dependsOn: []
  isVerificationFile: true
  path: tests/python/maximum_independet_set.test.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/python/maximum_independet_set.test.py
layout: document
redirect_from:
- /verify/tests/python/maximum_independet_set.test.py
- /verify/tests/python/maximum_independet_set.test.py.html
title: tests/python/maximum_independet_set.test.py
---
