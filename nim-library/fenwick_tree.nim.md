---
data:
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/nim.py\"\
    , line 86, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import sequtils\n\ntype\n  FenwickTree[T] = object\n    dat: seq[T]\n   \
    \ size: Natural\n    initial: T\n\nproc initFenwickTree[T](size: Natural, initial:\
    \ T): FenwickTree[T] =\n  return FenwickTree[T](dat: newSeqWith(size, initial),\
    \ size: size, initial: initial)\n\nproc update[T](fwt: var FenwickTree[T], k:\
    \ Natural, val: T) =\n  assert(k < fwt.size)\n  var key = k\n  while key < fwt.size:\n\
    \    fwt.dat[key] += val\n    key = key or (key + 1)\n\nproc query[T](fwt: var\
    \ FenwickTree[T], k: int): T =\n  assert(k >= 0)\n  var key = k - 1\n  result\
    \ = fwt.initial\n  while key >= 0:\n    result += fwt.dat[key]\n    key = (key\
    \ and (key + 1)) - 1\n\nproc query[T](fwt: var FenwickTree[T], left, right: Natural):\
    \ T =\n  assert(left <= right and right <= fwt.size)\n  return fwt.query(right)\
    \ - fwt.query(left)\n\nproc index[T](fwt: var FenwickTree[T], k: Natural): T =\n\
    \  assert(k < fwt.size)\n  return fwt.query(k + 1) - fwt.index(k)\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: nim-library/fenwick_tree.nim
  requiredBy: []
  timestamp: '2019-04-11 03:52:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: nim-library/fenwick_tree.nim
layout: document
redirect_from:
- /library/nim-library/fenwick_tree.nim
- /library/nim-library/fenwick_tree.nim.html
title: nim-library/fenwick_tree.nim
---
