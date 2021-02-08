---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/bipartitematching
    links:
    - https://judge.yosupo.jp/problem/bipartitematching
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# verify-helper: PROBLEM https://judge.yosupo.jp/problem/bipartitematching\n\
    import sys\n\nfrom python_library.graph.dinic import MaxFlow\n\ninput = sys.stdin.buffer.readline\n\
    \n\ndef main() -> None:\n    L, R, M = map(int, input().split())\n    source,\
    \ sink = L + R, L + R + 1\n    mf = MaxFlow(L + R + 2)\n    for _ in range(M):\n\
    \        a, b = map(int, input().split())\n        mf.add_edge(a, L + b, 1)\n\
    \    for i in range(L):\n        mf.add_edge(source, i, 1)\n    for i in range(R):\n\
    \        mf.add_edge(L + i, sink, 1)\n    print(mf.run(source, sink))\n\n    for\
    \ i in range(L):\n        for e in mf.E[i]:\n            if e.cap == 0 and e.to\
    \ < L + R:\n                print(i, e.to - L)\n\n\nif __name__ == \"__main__\"\
    :\n    main()\n"
  dependsOn: []
  isVerificationFile: true
  path: tests/python/dinic_bimatch.test.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/python/dinic_bimatch.test.py
layout: document
redirect_from:
- /verify/tests/python/dinic_bimatch.test.py
- /verify/tests/python/dinic_bimatch.test.py.html
title: tests/python/dinic_bimatch.test.py
---
