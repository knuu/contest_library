---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/sort_points_by_argument
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import itertools\nimport sys\nfrom functools import cmp_to_key\nfrom typing\
    \ import Iterable, List, Tuple\n\n\ninput = sys.stdin.buffer.readline\n\n\ndef\
    \ argsort_numpy(points: List[Tuple[float, float]]\n                  ) -> List[Tuple[float,\
    \ float]]:\n    import numpy as np\n    args = [(np.arctan2(y, x, dtype=np.longdouble),\
    \ idx)\n            for idx, (x, y) in enumerate(points)]\n    args.sort()\n \
    \   return [points[i] for _, i in args]\n\n\ndef compare(p1, p2):\n    (x1, y1),\
    \ (x2, y2) = p1, p2\n    if x1 * y2 == x2 * y1:\n        return 0\n    return\
    \ 1 if x1 * y2 < x2 * y1 else -1\n\n\ndef argsort(points: List[Tuple[float, float]]\n\
    \            ) -> Iterable[Tuple[float, float]]:\n    lowers, uppers, origins\
    \ = [], [], []\n\n    for x, y in points:\n        if y < 0 or (y == 0 and x >\
    \ 0):\n            lowers.append((x, y))\n        elif y > 0 or (y == 0 and x\
    \ < 0):\n            uppers.append((x, y))\n        else:\n            origins.append((x,\
    \ y))\n    lowers.sort(key=cmp_to_key(compare))\n    uppers.sort(key=cmp_to_key(compare))\n\
    \    origins.sort(key=cmp_to_key(compare))\n    return itertools.chain(lowers,\
    \ origins, uppers)\n\n\ndef yosupo():\n    # https://judge.yosupo.jp/problem/sort_points_by_argument\n\
    \    N = int(input())\n    points = [tuple(int(val) for val in input().split())\
    \ for _ in range(N)]\n    for x, y in argsort_numpy(points):\n        print(x,\
    \ y)\n\n\ndef yosupo2():\n    # https://judge.yosupo.jp/problem/sort_points_by_argument\n\
    \    N = int(input())\n    points = [tuple(int(val) for val in input().split())\
    \ for _ in range(N)]\n    for x, y in argsort(points):\n        print(x, y)\n\n\
    \nif __name__ == \"__main__\":\n    # yosupo()\n    yosupo2()\n"
  dependsOn: []
  isVerificationFile: false
  path: python_library/geometry/argsort.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: python_library/geometry/argsort.py
layout: document
redirect_from:
- /library/python_library/geometry/argsort.py
- /library/python_library/geometry/argsort.py.html
title: python_library/geometry/argsort.py
---
