---
data:
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import math\nfrom typing import List\n\n\nclass FenwickTree1:\n    \"\"\"\
    \n    FenwickTree(Binary Indexed Tree)\n    total number: n\n    queries:\n  \
    \  1. add(i, val): add val to i-th value\n    2. sum(n): sum(bit[1] + ... + bit[n])\n\
    \    complexity: O(log n)\n\n    Self-balancing binary search tree or Segment\
    \ Tree can do the same,\n    it takes longer to program and complexity also increases.\n\
    \    Thanks: http://hos.ac/slides/20140319_bit.pdf\n\n    used in ARC031 C, indeednow\
    \ finalB E\n    \"\"\"\n    def __init__(self, a_list: List[int]) -> None:\n \
    \       # 1-index\n        self.N: int = len(a_list)\n        self.bit: List[int]\
    \ = a_list[:]\n        for i in range(1, self.N):\n            self.bit[i + (i\
    \ & -i)] += self.bit[i]\n\n    def add(self, idx: int, val: int) -> None:\n  \
    \      while idx <= self.N:\n            self.bit[idx] += val\n            idx\
    \ += idx & -idx\n\n    def sum(self, n: int) -> int:\n        ret: int = 0\n \
    \       while n > 0:\n            ret += self.bit[n]\n            n -= n & -n\n\
    \        return ret\n\n\nclass FenwickTree:\n    def __init__(self, a_list: List[int])\
    \ -> None:\n        # 0-indexed\n        self.N: int = len(a_list)\n        self.bit:\
    \ List[int] = a_list[:]\n        for _ in range(self.N, 1 << (math.ceil(math.log(self.N,\
    \ 2)))):\n            self.bit.append(0)\n        for i in range(self.N-1):\n\
    \            self.bit[i | (i+1)] += self.bit[i]\n\n    def add(self, i: int, val:\
    \ int) -> None:\n        while i < self.N:\n            self.bit[i] += val\n \
    \           i |= i + 1\n\n    def sum(self, n: int) -> int:\n        ret: int\
    \ = 0\n        while n >= 0:\n            ret += self.bit[n]\n            n =\
    \ (n & (n + 1)) - 1\n        return ret\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: python_library_typed/data_structures/fenwick_tree.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: python_library_typed/data_structures/fenwick_tree.py
layout: document
redirect_from:
- /library/python_library_typed/data_structures/fenwick_tree.py
- /library/python_library_typed/data_structures/fenwick_tree.py.html
title: python_library_typed/data_structures/fenwick_tree.py
---
