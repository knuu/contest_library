---
data:
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# verify-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B\n\
    import sys\n\nfrom python_library.graph.primal_dual import MinCostFlow\n\ninput\
    \ = sys.stdin.buffer.readline\n\n\ndef main() -> None:\n    V, E, F = map(int,\
    \ input().split())\n    mcf = MinCostFlow(V)\n    for _ in range(E):\n       \
    \ u, v, c, d = map(int, input().split())\n        mcf.add_edge(u, v, c, d)\n \
    \   print(mcf.run(0, V - 1, F))\n\n\nif __name__ == \"__main__\":\n    main()\n"
  dependsOn:
  - python_library/graph/primal_dual.py
  extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: python_library/graph/primal_dual.py
    title: python_library/graph/primal_dual.py
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: tests/python/primal_dual.test.py
  requiredBy: []
  timestamp: '2020-09-08 04:10:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith: []
documentation_of: tests/python/primal_dual.test.py
layout: document
redirect_from:
- /verify/tests/python/primal_dual.test.py
- /verify/tests/python/primal_dual.test.py.html
title: tests/python/primal_dual.test.py
---
