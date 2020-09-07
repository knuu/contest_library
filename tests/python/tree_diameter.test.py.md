---
data:
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# verify-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A\n\
    import sys\n\nfrom python_library.graph.graph import Graph\nfrom python_library.graph.tree_diameter\
    \ import TreeDiameter\n\n\ndef main() -> None:\n    N = int(input())\n    graph\
    \ = Graph(N)\n    for _ in range(N - 1):\n        s, t, w = map(int, input().split())\n\
    \        graph.add_edge(s, t, w)\n        graph.add_edge(t, s, w)\n    diam =\
    \ TreeDiameter(graph)\n    print(diam.run())\n\n\nif __name__ == \"__main__\"\
    :\n    main()\n"
  dependsOn:
  - python_library/graph/graph.py
  - python_library/graph/tree_diameter.py
  extendedDependsOn:
  - icon: ':question:'
    path: python_library/graph/graph.py
    title: python_library/graph/graph.py
  - icon: ':x:'
    path: python_library/graph/tree_diameter.py
    title: python_library/graph/tree_diameter.py
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: tests/python/tree_diameter.test.py
  requiredBy: []
  timestamp: '2020-09-08 04:10:45+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verificationStatusIcon: ':x:'
  verifiedWith: []
documentation_of: tests/python/tree_diameter.test.py
layout: document
redirect_from:
- /verify/tests/python/tree_diameter.test.py
- /verify/tests/python/tree_diameter.test.py.html
title: tests/python/tree_diameter.test.py
---
