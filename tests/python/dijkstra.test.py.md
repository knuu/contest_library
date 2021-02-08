---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: py
  _verificationStatusIcon: ':x:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# verify-helper: PROBLEM https://judge.yosupo.jp/problem/shortest_path\n\
    import sys\n\nfrom python_library.graph.dijkstra import ShortestPath\n\ninput\
    \ = sys.stdin.buffer.readline\n\n\ndef yosupo_sp():\n    N, M, start, goal = map(int,\
    \ input().split())\n    g = Graph(N)\n    for _ in range(M):\n        a, b, c\
    \ = map(int, input().split())\n        g.add_edge(a, b, c)\n    sp = ShortestPath(g,\
    \ 10**18)\n    sp.dijkstra(start, goal)\n    if sp.dist[goal] == sp.INF:\n   \
    \     print(-1)\n    else:\n        path = sp.getPath(goal)\n        print(sp.dist[goal],\
    \ len(path) - 1)\n        for s, t in zip(path, path[1:]):\n            print(s,\
    \ t)\n\n\nif __name__ == \"__main__\":\n    yosupo_sp()"
  dependsOn: []
  isVerificationFile: true
  path: tests/python/dijkstra.test.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/python/dijkstra.test.py
layout: document
redirect_from:
- /verify/tests/python/dijkstra.test.py
- /verify/tests/python/dijkstra.test.py.html
title: tests/python/dijkstra.test.py
---
