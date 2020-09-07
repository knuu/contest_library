---
data:
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "class SegmentTree:\n    \"\"\"Segment Tree (Point Update & Range Query)\n\
    \n    Query\n        1. update(i, val): update i-th value to val\n        2. query(low,\
    \ high): find f(value) in [low, high)\n\n    Complexity\n        time complexity:\
    \ O(log n)\n        space complexity: O(n)\n    \"\"\"\n\n    def __init__(self,\
    \ N, f, default):\n        self.N = 1 << (N - 1).bit_length()\n        self.default\
    \ = default\n        self.f = f\n        self.segtree = [self.default] * ((self.N\
    \ << 1) - 1)\n\n    @classmethod\n    def create_from_array(cls, arr, f, default):\n\
    \        N = len(arr)\n        self = cls(N, f, default)\n        for i in range(N):\n\
    \            self.segtree[self.N - 1 + i] = arr[i]\n\n        for i in reversed(range(self.N\
    \ - 1)):\n            self.segtree[i] = self.f(\n                self.segtree[(i\
    \ << 1) + 1], self.segtree[(i << 1) + 2]\n            )\n        return self\n\
    \n    def update(self, i, val):\n        i += self.N - 1\n        self.segtree[i]\
    \ = val\n        while i > 0:\n            i = (i - 1) >> 1\n            self.segtree[i]\
    \ = self.f(\n                self.segtree[(i << 1) + 1], self.segtree[(i << 1)\
    \ + 2]\n            )\n\n    def __getitem__(self, k):\n        return self.segtree[self.N\
    \ - 1 + k]\n\n    def query(self, low, high):\n        # query [l, r)\n      \
    \  low, high = low + self.N, high + self.N\n        left_ret, right_ret = self.default,\
    \ self.default\n        while low < high:\n            if low & 1:\n         \
    \       left_ret = self.f(left_ret, self.segtree[low - 1])\n                low\
    \ += 1\n            if high & 1:\n                high -= 1\n                right_ret\
    \ = self.f(self.segtree[high - 1], right_ret)\n            low, high = low >>\
    \ 1, high >> 1\n        return self.f(left_ret, right_ret)\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/python/segment_tree_range_min_query.test.py
    title: tests/python/segment_tree_range_min_query.test.py
  - icon: ':heavy_check_mark:'
    path: tests/python/segment_tree_staticrmq.test.py
    title: tests/python/segment_tree_staticrmq.test.py
  - icon: ':heavy_check_mark:'
    path: tests/python/segment_tree_point_set_range_composite.test.py
    title: tests/python/segment_tree_point_set_range_composite.test.py
  isVerificationFile: false
  path: python_library/data_structures/segment_tree.py
  requiredBy: []
  timestamp: '2020-02-16 04:55:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith:
  - tests/python/segment_tree_range_min_query.test.py
  - tests/python/segment_tree_staticrmq.test.py
  - tests/python/segment_tree_point_set_range_composite.test.py
documentation_of: python_library/data_structures/segment_tree.py
layout: document
redirect_from:
- /library/python_library/data_structures/segment_tree.py
- /library/python_library/data_structures/segment_tree.py.html
title: python_library/data_structures/segment_tree.py
---
