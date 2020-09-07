---
data:
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# @import python_library/graph/graph.py\nfrom collections import deque\n\n\
    from python_library.graph.graph import Graph\n\n\nclass HeavyLightDecomposition:\n\
    \    def __init__(self, g: Graph, root: int = 0, need_subtree: bool = False) ->\
    \ None:\n        self.g = g\n        self.vid, self.head = [-1] * g.V, [0] * g.V\n\
    \        self.heavy, self.parent = [-1] * g.V, [0] * g.V\n        self.dfs(root)\n\
    \        if not need_subtree:\n            self.bfs(root)\n        else:\n   \
    \         self.tail = [0] * g.V\n            self.dfs2(root)\n\n    def dfs(self,\
    \ root=-1):\n        stack = [(root, -1, False)]\n        sub, max_sub = [1] *\
    \ self.g.V, [(0, -1)] * self.g.V\n        while stack:\n            v, par, flag\
    \ = stack.pop()\n            if not flag:\n                self.parent[v] = par\n\
    \                stack.append((v, par, True))\n                stack.extend((e.dst,\
    \ v, False) for e in self.g.E[v] if e.dst != par)\n            else:\n       \
    \         if par != -1:\n                    sub[par] += sub[v]\n            \
    \        max_sub[par] = max(max_sub[par], (sub[v], v))\n                self.heavy[v]\
    \ = max_sub[v][1]\n\n    def bfs(self, root=0):\n        k, que = 0, deque([root])\n\
    \        while que:\n            r = v = que.popleft()\n            while v !=\
    \ -1:\n                self.vid[v], self.head[v] = k, r\n                k +=\
    \ 1\n                for e in self.g.E[v]:\n                    if e.dst != self.parent[v]\
    \ and e.dst != self.heavy[v]:\n                        que.append(e.dst)\n   \
    \             v = self.heavy[v]\n\n    def dfs2(self, root: int = 0) -> None:\n\
    \        stack = [(root, 0)]\n        k = 0\n        while stack:\n          \
    \  v, state = stack.pop()\n            if state == 0:\n                u = v\n\
    \                while u != -1:\n                    self.vid[u] = k\n       \
    \             k += 1\n                    self.head[u] = v\n                 \
    \   stack.append((u, 1))\n                    u = self.heavy[u]\n            elif\
    \ state == 1:\n                stack.append((v, 2))\n                for child\
    \ in self.g.E[v]:\n                    if child.dst not in [self.parent[v], self.heavy[v]]:\n\
    \                        stack.append((child.dst, 0))\n            else:\n   \
    \             self.tail[v] = k\n\n    def lca(self, u, v):\n        while self.head[u]\
    \ != self.head[v]:\n            if self.vid[u] > self.vid[v]:\n              \
    \  u, v = v, u\n            v = self.parent[self.head[v]]\n        else:\n   \
    \         if self.vid[u] > self.vid[v]:\n                u, v = v, u\n       \
    \ return u\n\n    def query_path(self, u, v, one, query, merge, edge: bool = False):\n\
    \        # u, v \u306E\u9593\u306E\u30D1\u30B9\u306B\u5BFE\u3059\u308B\u30AF\u30A8\
    \u30EA\u3092\u8A08\u7B97\u3059\u308B\n        # one \u306F\u5358\u4F4D\u5143\u3001\
    query \u306F\u5217\u306B\u5BFE\u3059\u308B\u30AF\u30A8\u30EA\u3001merge \u306F\
    \u30DE\u30FC\u30B8\u3059\u308B\u6F14\u7B97\n        left = right = one\n     \
    \   while True:\n            if self.vid[u] > self.vid[v]:\n                u,\
    \ v = v, u\n                left, right = right, left\n            if self.head[u]\
    \ == self.head[v]:\n                break\n            left = merge(query(self.vid[self.head[v]],\
    \ self.vid[v] + 1), left)\n            v = self.parent[self.head[v]]\n       \
    \ return merge(merge(query(self.vid[u] + edge, self.vid[v] + 1), left), right)\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/python/hld_lca.test.py
    title: tests/python/hld_lca.test.py
  isVerificationFile: false
  path: python_library/graph/heavy_light_decomposition.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith:
  - tests/python/hld_lca.test.py
documentation_of: python_library/graph/heavy_light_decomposition.py
layout: document
redirect_from:
- /library/python_library/graph/heavy_light_decomposition.py
- /library/python_library/graph/heavy_light_decomposition.py.html
title: python_library/graph/heavy_light_decomposition.py
---
