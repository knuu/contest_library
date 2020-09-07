---
data:
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/nim.py\"\
    , line 86, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "type\n  Point[T] = object\n    x, y: T\n\nproc initPoint[T](x, y: T): Point[T]\
    \ =\n  Point[T](x: x, y: y)\n\nproc `+`[T](a, b: Point[T]): Point[T] =\n  initPoint(a.x\
    \ + b.x, a.y + b.y)\n\nproc `-`[T](a, b: Point[T]): Point[T] =\n  initPoint(a.x\
    \ - b.x, a.y - b.y)\n\nproc det[T](a, b: Point[T]): T =\n  a.x * b.y - a.y * b.x\n\
    \nproc convex_hull[T](points: seq[Point[T]]): seq[Point[T]] =\n  var sorted_points\
    \ = points\n  sorted_points.sort do (p1, p2: Point[T]) -> int:\n    result = cmp(p1.x,\
    \ p2.x)\n    if result == 0:\n      result = cmp(p1.y, p2.y)\n  var lower_hull\
    \ = sorted_points.get_bounds\n  sorted_points.reverse\n  result = sorted_points.get_bounds\n\
    \  discard lower_hull.pop\n  discard result.pop\n  for point in lower_hull:\n\
    \    result.add(point)\n\nproc get_bounds[T](points: var seq[Point[T]]): seq[Point[T]]\
    \ =\n  result = @[points[0], points[1]]\n  for point in points[2..^1]:\n    while\
    \ result.len > 1 and (result[^1] - result[^2]).det(point - result[^1]) <= 0:\n\
    \      discard result.pop\n    result.add(point)\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: nim-library/convex_hull.nim
  requiredBy: []
  timestamp: '2019-04-11 03:52:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: nim-library/convex_hull.nim
layout: document
redirect_from:
- /library/nim-library/convex_hull.nim
- /library/nim-library/convex_hull.nim.html
title: nim-library/convex_hull.nim
---
