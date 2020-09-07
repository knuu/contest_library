---
data:
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/scc
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# verify-helper: PROBLEM https://judge.yosupo.jp/problem/scc\nimport sys\n\
    \nfrom python_library.graph.scc import StronglyConnectedComponets\n\ninput = sys.stdin.buffer.readline\n\
    sys.setrecursionlimit(6 * 10 ** 5)\n\n\ndef main() -> None:\n    N, M = map(int,\
    \ input().split())\n    scc = StronglyConnectedComponets(N)\n    for _ in range(M):\n\
    \        u, v = map(int, input().split())\n        scc.add_edge(u, v)\n    scc.run()\n\
    \    ans_size = max(scc.order) + 1\n    ans = [[] for _ in range(ans_size)]\n\
    \    for i, c in enumerate(scc.order):\n        ans[c].append(i)\n    print(ans_size)\n\
    \    for row in ans:\n        print(len(row), *row)\n\n\nif __name__ == \"__main__\"\
    :\n    main()\n"
  dependsOn:
  - python_library/graph/scc.py
  extendedDependsOn:
  - icon: ':x:'
    path: python_library/graph/scc.py
    title: python_library/graph/scc.py
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: tests/python/scc_yosupo.test.py
  requiredBy: []
  timestamp: '2020-09-08 04:10:45+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verificationStatusIcon: ':x:'
  verifiedWith: []
documentation_of: tests/python/scc_yosupo.test.py
layout: document
redirect_from:
- /verify/tests/python/scc_yosupo.test.py
- /verify/tests/python/scc_yosupo.test.py.html
title: tests/python/scc_yosupo.test.py
---
