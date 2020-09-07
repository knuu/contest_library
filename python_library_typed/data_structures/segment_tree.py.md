---
data:
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import math\nfrom typing import Generic, TypeVar, Callable, List\n\nT = TypeVar(\"\
    T\", int, float)\n\n\n\nclass SegmentTree(Generic[T]):\n    \"\"\"\n    Segment\
    \ Tree\n    query:\n    1. update(i, val): update i-th value to val\n    2. query(low,\
    \ high): find f(value) in [low, high)\n    time complexity: O(log n)\n    space\
    \ complexity: O(2n)\n    \"\"\"\n    def __init__(self, N: int, f: Callable[[T,\
    \ T], T], default: T) -> None:\n        self.N = 1 << math.ceil(math.log(N, 2))\n\
    \        self.default: T = default\n        self.f: Callable[[T, T], T] = f\n\
    \        self.segtree: List[T] = [self.default] * (self.N * 2 - 1)\n\n    def\
    \ update(self, i: int, val: T) -> None:\n        i += self.N - 1\n        self.segtree[i]\
    \ = val\n        while i > 0:\n            i = (i - 1) // 2\n            self.segtree[i]\
    \ = self.f(self.segtree[2*i+1], self.segtree[2*i+2])\n\n    def query(self, low:\
    \ int, high: int, k: int = 0, left: int = 0, right: int = -1) -> T:\n        if\
    \ right == -1:\n            right = self.N\n        if right <= low or high <=\
    \ left:\n            return self.default\n\n        if low <= left and right <=\
    \ high:\n            return self.segtree[k]\n        else:\n            mid =\
    \ (left + right) // 2\n            return self.f(self.query(low, high, 2*k+1,\
    \ left, mid),\n                          self.query(low, high, 2*k+2, mid, right))\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: python_library_typed/data_structures/segment_tree.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: python_library_typed/data_structures/segment_tree.py
layout: document
redirect_from:
- /library/python_library_typed/data_structures/segment_tree.py
- /library/python_library_typed/data_structures/segment_tree.py.html
title: python_library_typed/data_structures/segment_tree.py
---
