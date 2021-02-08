---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: python_library/graph/graph.py
    title: python_library/graph/graph.py
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "from python_library.graph.graph import Graph\n\n\nclass TreeDiameter:\n \
    \   def __init__(self, graph: Graph) -> None:\n        self.graph = graph\n  \
    \      self.diameter = None\n        self.fathest_pair = None\n\n    def run(self):\n\
    \        _, v1 = self.calc_farthest(0, -1)\n        diameter, v2 = self.calc_farthest(v1,\
    \ -1)\n        self.diameter = diameter\n        self.fathest_pair = (v1, v2)\n\
    \        return diameter\n\n    def calc_farthest(self, target: int, par: int\
    \ = -1):\n        dists = [None] * self.graph.V\n        stack = [(target, par)]\n\
    \n        while stack:\n            v, par = stack[-1]\n            if dists[v]\
    \ is None:\n                dists[v] = (0, v)\n                for child in self.graph.E[v]:\n\
    \                    if child.dst == par:\n                        continue\n\
    \                    stack.append((child.dst, v))\n            else:\n       \
    \         stack.pop()\n                ret_dist, ret_v = dists[v]\n          \
    \      for child in self.graph.E[v]:\n                    if child.dst == par:\n\
    \                        continue\n                    cand_dist, cand_v = dists[child.dst]\n\
    \                    if cand_dist + child.weight > ret_dist:\n               \
    \         ret_dist = cand_dist + child.weight\n                        ret_v =\
    \ cand_v\n                dists[v] = (ret_dist, ret_v)\n\n        return dists[target]\n"
  dependsOn:
  - python_library/graph/graph.py
  isVerificationFile: false
  path: python_library/graph/tree_diameter.py
  requiredBy: []
  timestamp: '2021-02-09 04:27:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: python_library/graph/tree_diameter.py
layout: document
redirect_from:
- /library/python_library/graph/tree_diameter.py
- /library/python_library/graph/tree_diameter.py.html
title: python_library/graph/tree_diameter.py
---
