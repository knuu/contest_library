---
data:
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# verify-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C\n\
    import sys\n\nfrom python_library.graph.scc import StronglyConnectedComponets\n\
    \ninput = sys.stdin.buffer.readline\nsys.setrecursionlimit(6 * 10 ** 5)\n\n\n\
    def main() -> None:\n    V, E = map(int, input().split())\n    scc = StronglyConnectedComponets(V)\n\
    \    for _ in range(E):\n        u, v = map(int, input().split())\n        scc.add_edge(u,\
    \ v)\n    scc.run()\n    for _ in range(int(input())):\n        u, v = map(int,\
    \ input().split())\n        print(int(scc.order[u] == scc.order[v]))\n\n\nif __name__\
    \ == \"__main__\":\n    main()\n"
  dependsOn:
  - python_library/graph/scc.py
  extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: python_library/graph/scc.py
    title: python_library/graph/scc.py
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: tests/python/scc_aoj.test.py
  requiredBy: []
  timestamp: '2020-09-08 06:49:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith: []
documentation_of: tests/python/scc_aoj.test.py
layout: document
redirect_from:
- /verify/tests/python/scc_aoj.test.py
- /verify/tests/python/scc_aoj.test.py.html
title: tests/python/scc_aoj.test.py
---
