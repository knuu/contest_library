---
data:
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# verify-helper: PROBLEM https://judge.yosupo.jp/problem/two_sat\nimport\
    \ sys\n\nfrom python_library.graph.two_sat import TwoSat\n\ninput = sys.stdin.buffer.readline\n\
    sys.setrecursionlimit(10 ** 6 + 100)\n\n\ndef main() -> None:\n    _, _, *NM =\
    \ input().split()\n    N, M = map(int, NM)\n    sat = TwoSat(N)\n    for _ in\
    \ range(M):\n        u, v, _ = map(int, input().split())\n        sat.add_constraint(u,\
    \ v)\n    if sat.run():\n        print(\"s SATISFIABLE\")\n        print(\"v\"\
    , *[i + 1 if sat.ans[i] else -(i + 1) for i in range(N)], 0)\n    else:\n    \
    \    print(\"s UNSATISFIABLE\")\n\n\nif __name__ == \"__main__\":\n    main()\n"
  dependsOn:
  - python_library/graph/two_sat.py
  extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: python_library/graph/two_sat.py
    title: python_library/graph/two_sat.py
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: tests/python/two_sat.test.py
  requiredBy: []
  timestamp: '2020-09-08 06:49:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith: []
documentation_of: tests/python/two_sat.test.py
layout: document
redirect_from:
- /verify/tests/python/two_sat.test.py
- /verify/tests/python/two_sat.test.py.html
title: tests/python/two_sat.test.py
---
