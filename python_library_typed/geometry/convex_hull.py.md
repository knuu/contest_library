---
data:
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# used in AOJ No.68, yukicoder No.199\n# complexity: O(n^(1/2))\n\n\ndef\
    \ convex_hull(ps):\n    ps = [Point(x, y) for x, y in sorted([(p.x, p.y) for p\
    \ in ps])]\n    lower_hull = get_bounds(ps)\n    ps.reverse()\n    upper_hull\
    \ = get_bounds(ps)\n    del upper_hull[-1]\n    del lower_hull[-1]\n    lower_hull.extend(upper_hull)\n\
    \    return lower_hull\n\n\ndef get_bounds(ps):\n    qs = [ps[0], ps[1]]\n   \
    \ for p in ps[2:]:\n        while len(qs) > 1 and (qs[-1] - qs[-2]).det(p - qs[-1])\
    \ <= 0:\n            del qs[-1]\n        qs.append(p)\n    return qs\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: python_library_typed/geometry/convex_hull.py
  requiredBy: []
  timestamp: '2020-02-16 02:53:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: python_library_typed/geometry/convex_hull.py
layout: document
redirect_from:
- /library/python_library_typed/geometry/convex_hull.py
- /library/python_library_typed/geometry/convex_hull.py.html
title: python_library_typed/geometry/convex_hull.py
---
