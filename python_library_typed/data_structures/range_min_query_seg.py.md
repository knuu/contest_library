---
data:
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import math\nfrom typing import List, Generic, TypeVar\n\nT = TypeVar('T',\
    \ int, float, complex)\n\n\nclass RangeMinimumQuery(Generic[T]):\n    def __init__(self,\
    \ N: int, INF: T = 10**9) -> None:\n        self.N: int = 1 << math.ceil(math.log(N,\
    \ 2))\n        self.INF: T = INF\n        self.segtree: List[T] = [self.INF] *\
    \ (self.N * 2 - 1)\n\n    def update(self, idx: int, val: int) -> None:\n    \
    \    idx += self.N - 1\n        self.segtree[idx] = val\n        while idx > 0:\n\
    \            idx = (idx - 1) // 2\n            self.segtree[idx] = min(self.segtree[2\
    \ * idx + 1], self.segtree[2 * idx + 2])\n\n    def query(self, low: int, high:\
    \ int, k: int = 0, left: int = 0, right: int = -1) -> T:\n        if right ==\
    \ -1:\n            right = self.N\n        if right <= low or high <= left:\n\
    \            return self.INF\n\n        if low <= left and right <= high:\n  \
    \          return self.segtree[k]\n        else:\n            mid: int = (left\
    \ + right) // 2\n            return min(self.query(low, high, 2*k+1, left, mid),\n\
    \                       self.query(low, high, 2*k+2, mid, right))\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: python_library_typed/data_structures/range_min_query_seg.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: python_library_typed/data_structures/range_min_query_seg.py
layout: document
redirect_from:
- /library/python_library_typed/data_structures/range_min_query_seg.py
- /library/python_library_typed/data_structures/range_min_query_seg.py.html
title: python_library_typed/data_structures/range_min_query_seg.py
---
