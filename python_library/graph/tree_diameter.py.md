---
data:
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# @import python_library/graph/graph.py\nfrom python_library.graph.graph\
    \ import Graph\n\n\nclass TreeDiameter:\n    def __init__(self, graph: Graph)\
    \ -> None:\n        self.graph = graph\n        self.diameter = None\n       \
    \ self.fathest_pair = None\n\n    def run(self):\n        _, v1 = self.calc_farthest(0,\
    \ -1)\n        diameter, v2 = self.calc_farthest(v1, -1)\n        self.diameter\
    \ = diameter\n        self.fathest_pair = (v1, v2)\n        return diameter\n\n\
    \    def calc_farthest(self, target: int, par: int = -1):\n        dists = [None]\
    \ * self.graph.V\n        stack = [(target, par)]\n\n        while stack:\n  \
    \          v, par = stack[-1]\n            if dists[v] is None:\n            \
    \    dists[v] = (0, v)\n                for child in self.graph.E[v]:\n      \
    \              if child.dst == par:\n                        continue\n      \
    \              stack.append((child.dst, v))\n            else:\n             \
    \   stack.pop()\n                ret_dist, ret_v = dists[v]\n                for\
    \ child in self.graph.E[v]:\n                    if child.dst == par:\n      \
    \                  continue\n                    cand_dist, cand_v = dists[child.dst]\n\
    \                    if cand_dist + child.weight > ret_dist:\n               \
    \         ret_dist = cand_dist + child.weight\n                        ret_v =\
    \ cand_v\n                dists[v] = (ret_dist, ret_v)\n\n        return dists[target]\n"
  dependsOn:
  - python_library/graph/graph.py
  extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: python_library/graph/graph.py
    title: python_library/graph/graph.py
  extendedRequiredBy: []
  extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/python/tree_diameter.test.py
    title: tests/python/tree_diameter.test.py
  isVerificationFile: false
  path: python_library/graph/tree_diameter.py
  requiredBy: []
  timestamp: '2020-02-16 07:49:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith:
  - tests/python/tree_diameter.test.py
documentation_of: python_library/graph/tree_diameter.py
layout: document
redirect_from:
- /library/python_library/graph/tree_diameter.py
- /library/python_library/graph/tree_diameter.py.html
title: python_library/graph/tree_diameter.py
---
