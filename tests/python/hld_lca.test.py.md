---
data:
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/lca
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# verify-helper: PROBLEM https://judge.yosupo.jp/problem/lca\nimport sys\n\
    \nfrom python_library.graph.graph import Graph\nfrom python_library.graph.heavy_light_decomposition\
    \ import HeavyLightDecomposition\n\ninput = sys.stdin.buffer.readline\n\n\ndef\
    \ main() -> None:\n    N, Q = map(int, input().split())\n    graph = Graph(N)\n\
    \    for i, p in enumerate(map(int, input().split())):\n        graph.add_edge(p,\
    \ i + 1, 1)\n    hld = HeavyLightDecomposition(graph)\n    ans = [hld.lca(*map(int,\
    \ input().split())) for _ in range(Q)]\n    print(*ans, sep=\"\\n\")\n\n\nif __name__\
    \ == \"__main__\":\n    main()\n"
  dependsOn:
  - python_library/graph/graph.py
  - python_library/graph/heavy_light_decomposition.py
  extendedDependsOn:
  - icon: ':question:'
    path: python_library/graph/graph.py
    title: python_library/graph/graph.py
  - icon: ':heavy_check_mark:'
    path: python_library/graph/heavy_light_decomposition.py
    title: python_library/graph/heavy_light_decomposition.py
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: tests/python/hld_lca.test.py
  requiredBy: []
  timestamp: '2020-09-08 04:10:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith: []
documentation_of: tests/python/hld_lca.test.py
layout: document
redirect_from:
- /verify/tests/python/hld_lca.test.py
- /verify/tests/python/hld_lca.test.py.html
title: tests/python/hld_lca.test.py
---
