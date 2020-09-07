---
data:
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "from typing import List\n\n\nclass FenwickTree:\n    \"\"\"FenwickTree (Binary\
    \ Indexed Tree, 0-index)\n\n    Queries:\n        1. add(i, val): add val to i-th\
    \ value\n        2. sum(n): sum(bit[0] + ... + bit[n-1])\n\n    complexity: O(log\
    \ n)\n\n    See: http://hos.ac/slides/20140319_bit.pdf\n    \"\"\"\n\n    def\
    \ __init__(self, a_list: List[int], default: int = 0) -> None:\n        self.N\
    \ = len(a_list)\n        self.bit = a_list[:]\n        for _ in range(self.N,\
    \ 1 << (self.N - 1).bit_length()):\n            self.bit.append(0)\n        for\
    \ i in range(self.N - 1):\n            self.bit[i | (i + 1)] += self.bit[i]\n\n\
    \    def add(self, i: int, val: int) -> None:\n        while i < self.N:\n   \
    \         self.bit[i] += val\n            i |= i + 1\n\n    def sum(self, n: int)\
    \ -> int:\n        ret = 0\n        while n >= 0:\n            ret += self.bit[n]\n\
    \            n = (n & (n + 1)) - 1\n        return ret\n\n    def query(self,\
    \ low: int, high: int) -> int:\n        return self.sum(high) - self.sum(low)\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/python/fenwick_tree_aoj.test.py
    title: tests/python/fenwick_tree_aoj.test.py
  - icon: ':heavy_check_mark:'
    path: tests/python/fenwick_tree_yosupo.test.py
    title: tests/python/fenwick_tree_yosupo.test.py
  isVerificationFile: false
  path: python_library/data_structures/fenwick_tree.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith:
  - tests/python/fenwick_tree_aoj.test.py
  - tests/python/fenwick_tree_yosupo.test.py
documentation_of: python_library/data_structures/fenwick_tree.py
layout: document
redirect_from:
- /library/python_library/data_structures/fenwick_tree.py
- /library/python_library/data_structures/fenwick_tree.py.html
title: python_library/data_structures/fenwick_tree.py
---
