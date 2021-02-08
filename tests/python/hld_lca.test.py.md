---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# verify-helper: PROBLEM https://judge.yosupo.jp/problem/lca\nimport sys\n\
    \nfrom python_library.graph.graph import Graph\nfrom python_library.graph.heavy_light_decomposition\
    \ import HeavyLightDecomposition\n\ninput = sys.stdin.buffer.readline\n\n\ndef\
    \ main() -> None:\n    N, Q = map(int, input().split())\n    graph = Graph(N)\n\
    \    for i, p in enumerate(map(int, input().split())):\n        graph.add_edge(p,\
    \ i + 1, 1)\n    hld = HeavyLightDecomposition(graph)\n    ans = [hld.lca(*map(int,\
    \ input().split())) for _ in range(Q)]\n    print(*ans, sep=\"\\n\")\n\n\nif __name__\
    \ == \"__main__\":\n    main()\n"
  dependsOn: []
  isVerificationFile: true
  path: tests/python/hld_lca.test.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/python/hld_lca.test.py
layout: document
redirect_from:
- /verify/tests/python/hld_lca.test.py
- /verify/tests/python/hld_lca.test.py.html
title: tests/python/hld_lca.test.py
---
