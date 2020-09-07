---
data:
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# @import python_library/geometry/geometry.py\nfrom python_library.geometry.geometry\
    \ import Point\n\n\nclass ConvexHull:\n    def __init__(self, points) -> None:\n\
    \        self.ps = points\n\n    def run(self):\n        ps = sorted(self.ps)\n\
    \        lower_hull = self.get_bounds(ps)\n        ps = ps[::-1]\n        upper_hull\
    \ = self.get_bounds(ps)\n        del upper_hull[-1]\n        del lower_hull[-1]\n\
    \        lower_hull.extend(upper_hull)\n        return lower_hull\n\n    def get_bounds(self,\
    \ ps):\n        qs = [ps[0], ps[1]]\n        for p in ps[2:]:\n            while\
    \ len(qs) > 1 and (qs[-1] - qs[-2]).det(p - qs[-1]) < 0:\n                del\
    \ qs[-1]\n            qs.append(p)\n        return qs\n"
  dependsOn:
  - python_library/geometry/geometry.py
  extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: python_library/geometry/geometry.py
    title: python_library/geometry/geometry.py
  extendedRequiredBy: []
  extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/python/convex_hull.test.py
    title: tests/python/convex_hull.test.py
  isVerificationFile: false
  path: python_library/geometry/convex_hull.py
  requiredBy: []
  timestamp: '2020-02-16 07:49:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith:
  - tests/python/convex_hull.test.py
documentation_of: python_library/geometry/convex_hull.py
layout: document
redirect_from:
- /library/python_library/geometry/convex_hull.py
- /library/python_library/geometry/convex_hull.py.html
title: python_library/geometry/convex_hull.py
---
