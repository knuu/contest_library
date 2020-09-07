---
data:
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# verify-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A\n\
    import sys\n\nfrom python_library.geometry.convex_hull import ConvexHull\nfrom\
    \ python_library.geometry.geometry import Point\n\ninput = sys.stdin.buffer.readline\n\
    \n\ndef main() -> None:\n    N = int(input())\n    ps = []\n    for _ in range(N):\n\
    \        x, y = map(int, input().split())\n        ps.append(Point(x, y))\n  \
    \  hull = ConvexHull(ps)\n    convex = hull.run()\n    print(len(convex))\n  \
    \  min_idx = -1\n    min_x, min_y = 10001, 10001\n    for i, p in enumerate(convex):\n\
    \        if p.y < min_y or (p.y == min_y and p.x < min_x):\n            min_idx\
    \ = i\n            min_x, min_y = p.x, p.y\n    for p in convex[min_idx:]:\n \
    \       print(p.x, p.y)\n    for p in convex[:min_idx]:\n        print(p.x, p.y)\n\
    \n\nif __name__ == \"__main__\":\n    main()\n"
  dependsOn:
  - python_library/geometry/convex_hull.py
  - python_library/geometry/geometry.py
  extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: python_library/geometry/convex_hull.py
    title: python_library/geometry/convex_hull.py
  - icon: ':heavy_check_mark:'
    path: python_library/geometry/geometry.py
    title: python_library/geometry/geometry.py
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: tests/python/convex_hull.test.py
  requiredBy: []
  timestamp: '2020-09-08 04:10:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith: []
documentation_of: tests/python/convex_hull.test.py
layout: document
redirect_from:
- /verify/tests/python/convex_hull.test.py
- /verify/tests/python/convex_hull.test.py.html
title: tests/python/convex_hull.test.py
---
