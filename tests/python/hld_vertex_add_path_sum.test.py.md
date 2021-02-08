---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# verify-helper: PROBLEM https://judge.yosupo.jp/problem/vertex_add_path_sum\n\
    import operator\nimport sys\n\nfrom python_library.data_structures.segment_tree\
    \ import SegmentTree\nfrom python_library.graph.graph import Graph\nfrom python_library.graph.heavy_light_decomposition\
    \ import \\\n    HeavyLightDecomposition\n\ninput = sys.stdin.buffer.readline\n\
    \n\ndef main() -> None:\n    N, Q = map(int, input().split())\n    weights = [int(x)\
    \ for x in input().split()]\n    graph = Graph(N)\n    for _ in range(N - 1):\n\
    \        u, v = map(int, input().split())\n        graph.add_edge(u, v, 1)\n \
    \       graph.add_edge(v, u, 1)\n    hld = HeavyLightDecomposition(graph)\n  \
    \  new_weights = [0] * N\n    for i in range(N):\n        new_weights[hld.vid[i]]\
    \ = weights[i]\n    rsq = SegmentTree.create_from_array(new_weights, operator.add,\
    \ 0)\n\n    ans = []\n    for _ in range(Q):\n        t, a, b = map(int, input().split())\n\
    \        if t == 0:\n            rsq[hld.vid[a]] = rsq[hld.vid[a]] + b\n     \
    \   else:\n            ans.append(hld.query_path(a, b, 0, rsq.query, operator.add))\n\
    \    print(*ans, sep=\"\\n\")\n\n\nif __name__ == \"__main__\":\n    main()\n"
  dependsOn: []
  isVerificationFile: true
  path: tests/python/hld_vertex_add_path_sum.test.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/python/hld_vertex_add_path_sum.test.py
layout: document
redirect_from:
- /verify/tests/python/hld_vertex_add_path_sum.test.py
- /verify/tests/python/hld_vertex_add_path_sum.test.py.html
title: tests/python/hld_vertex_add_path_sum.test.py
---
