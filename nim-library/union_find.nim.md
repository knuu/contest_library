---
data:
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/nim.py\"\
    , line 86, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import sequtils\n\ntype\n  UnionFind = object\n    parent, rank: seq[int]\n\
    \nproc initUnionFindTree(size: Natural): UnionFind =\n  return UnionFind(parent:\
    \ newSeqWith(size, -1), rank: newSeqWith(size, 0))\n\nproc findRoot(uf: var UnionFind,\
    \ x: int): int =\n  if uf.parent[x] == -1:\n    return x\n  else:\n    uf.parent[x]\
    \ = uf.findRoot(uf.parent[x])\n    return uf.parent[x]\n\nproc uniteNode(uf: var\
    \ UnionFind, x, y: int) =\n  let\n    x = uf.findRoot(x)\n    y = uf.findRoot(y)\n\
    \  if x == y:\n    return\n  elif uf.rank[x] < uf.rank[y]:\n    uf.parent[x] =\
    \ y\n  else:\n    uf.parent[y] = x\n    if (uf.rank[x] == uf.rank[y]): uf.rank[x].inc\n\
    \nproc hasSameRoot(uf: var UnionFind, x, y: int): bool =\n  return uf.findRoot(x)\
    \ == uf.findRoot(y)\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith:
  - icon: ':x:'
    path: tests/nim/unionfind_yusupo_test.nim
    title: tests/nim/unionfind_yusupo_test.nim
  - icon: ':x:'
    path: tests/nim/unionfind_yusupo_test.nim
    title: tests/nim/unionfind_yusupo_test.nim
  isVerificationFile: false
  path: nim-library/union_find.nim
  requiredBy: []
  timestamp: '2019-04-11 03:52:18+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verificationStatusIcon: ':x:'
  verifiedWith:
  - tests/nim/unionfind_yusupo_test.nim
  - tests/nim/unionfind_yusupo_test.nim
documentation_of: nim-library/union_find.nim
layout: document
redirect_from:
- /library/nim-library/union_find.nim
- /library/nim-library/union_find.nim.html
title: nim-library/union_find.nim
---
