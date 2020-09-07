---
data:
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import bisect\nfrom typing import List, Tuple\n\n\nRangeType = Tuple[int,\
    \ int]\n\n\nclass RangeTreeNode:\n    def __init__(self, inf=10 ** 10):\n    \
    \    self._inf = inf\n        self.range_ = (inf, inf)\n        self.indices =\
    \ []\n        self.assoc = []\n\n    @classmethod\n    def merge(cls, node1: \"\
    RangeTreeNode\", node2: \"RangeTreeNode\", data):\n        merged_node = cls()\n\
    \        merged_node.range_ = (\n            min(node1.range_[0], node2.range_[0]),\n\
    \            max(node1.range_[1], node2.range_[1]),\n        )\n        sentinel\
    \ = node1._inf\n        node1.assoc.append(sentinel)\n        node2.assoc.append(sentinel)\n\
    \        i = j = 0\n        while min(node1.assoc[i], node2.assoc[j]) < sentinel:\n\
    \            if node1.assoc[i] < node2.assoc[j] or (\n                node1.assoc[i]\
    \ == node2.assoc[j]\n                and data[node1.indices[i]][0] < data[node2.indices[j]][0]\n\
    \            ):\n                merged_node.assoc.append(node1.assoc[i])\n  \
    \              merged_node.indices.append(node1.indices[i])\n                i\
    \ += 1\n            else:\n                merged_node.assoc.append(node2.assoc[j])\n\
    \                merged_node.indices.append(node2.indices[j])\n              \
    \  j += 1\n        node1.assoc.pop()\n        node2.assoc.pop()\n        return\
    \ merged_node\n\n\nclass RangeTree2D:\n    def __init__(self, inf=10 ** 10):\n\
    \        self._inf = inf\n\n    def build(self, points_: List[Tuple[int, int]])\
    \ -> None:\n        points = sorted([(x, y, i) for i, (x, y) in enumerate(points_)])\n\
    \        self._size = 1\n        while self._size < len(points):\n           \
    \ self._size <<= 1\n        self._data = [RangeTreeNode() for _ in range(self._size\
    \ * 2 - 1)]\n        for i, (x, y, idx) in enumerate(points):\n            self._data[self._size\
    \ - 1 + i].range_ = (x, x)\n            self._data[self._size - 1 + i].indices.append(idx)\n\
    \            self._data[self._size - 1 + i].assoc.append(y)\n        for i in\
    \ reversed(range(self._size - 1)):\n            self._data[i] = RangeTreeNode.merge(\n\
    \                self._data[2 * i + 1], self._data[2 * i + 2], points\n      \
    \      )\n\n    def query(\n        self, range_x: RangeType, range_y: RangeType,\
    \ output: List[int], idx: int = 0\n    ) -> None:\n        if idx >= 2 * self._size\
    \ - 1:\n            return\n        elif (\n            range_x[0] <= self._data[idx].range_[0]\n\
    \            and self._data[idx].range_[1] <= range_x[1]\n        ):\n       \
    \     low = bisect.bisect_left(self._data[idx].assoc, range_y[0])\n          \
    \  high = bisect.bisect_left(self._data[idx].assoc, range_y[1] + 1)\n\n      \
    \      for i in range(low, high):\n                output.append(self._data[idx].indices[i])\n\
    \            return\n        else:\n            self.query(range_x, range_y, output,\
    \ 2 * idx + 1)\n            self.query(range_x, range_y, output, 2 * idx + 2)\n\
    \n    def count(self, range_x, range_y, idx=0):\n        if idx >= 2 * self._size\
    \ - 1:\n            return 0\n        elif (\n            range_x[0] <= self._data[idx].range_[0]\n\
    \            and self._data[idx].range_[1] <= range_x[1]\n        ):\n       \
    \     low = bisect.bisect_left(self._data[idx].assoc, range_y[0])\n          \
    \  high = bisect.bisect_left(self._data[idx].assoc, range_y[1] + 1)\n        \
    \    return high - low\n        else:\n            return self.count(range_x,\
    \ range_y, 2 * idx + 1) + self.count(\n                range_x, range_y, 2 * idx\
    \ + 2\n            )\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith:
  - icon: ':x:'
    path: tests/python/range_tree_2d.test.py
    title: tests/python/range_tree_2d.test.py
  isVerificationFile: false
  path: python_library/data_structures/range_tree_2d.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_ALL_WA
  verificationStatusIcon: ':x:'
  verifiedWith:
  - tests/python/range_tree_2d.test.py
documentation_of: python_library/data_structures/range_tree_2d.py
layout: document
redirect_from:
- /library/python_library/data_structures/range_tree_2d.py
- /library/python_library/data_structures/range_tree_2d.py.html
title: python_library/data_structures/range_tree_2d.py
---
