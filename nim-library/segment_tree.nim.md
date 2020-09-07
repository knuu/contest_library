---
data:
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/nim.py\"\
    , line 86, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "type\n  SegTree[T] = object\n    dat: seq[T]\n    size: Natural\n    real_size:\
    \ Natural\n    merge: proc (x, y: T): T\n    default: T\n\nproc max_merge[T](x,\
    \ y: T): T =\n  result = if x > y: x else: y\n\nproc min_merge[T](x, y: T): T\
    \ =\n  result = if x > y: y else: x\n\nproc sum_merge[T](x, y: T): T = x + y\n\
    \nproc initSegTree[T](size: Natural, merge: proc (x, y: T): T = max_merge, default\
    \ = 0): SegTree[T] =\n  var real_size = 1\n  while real_size < size: real_size\
    \ = real_size shl 1\n  return SegTree[T](\n    dat: newSeqWith(2 * real_size -\
    \ 1, default),\n    size: size,\n    real_size: real_size,\n    merge: merge,\n\
    \    default: default\n  )\n\nproc update[T](segt: var Segtree[T], k: Natural,\
    \ val: T) =\n  assert(k < segt.size)\n  var key = k + segt.real_size - 1\n  segt.dat[key]\
    \ = val\n  while key > 0:\n    key = (key - 1) div 2\n    segt.dat[key] = segt.merge(segt.dat[2\
    \ * key + 1], segt.dat[2 * key + 2])\n\nproc query[T](segt: var SegTree[T], a,\
    \ b, k, left, right: Natural): T =\n  if right <= a or b <= left: return segt.default\n\
    \  if a <= left and right <= b: return segt.dat[k]\n  let mid = (left + right)\
    \ div 2\n  return segt.merge(segt.query(a, b, 2 * k + 1, left, mid),\n       \
    \            segt.query(a, b, 2 * k + 2, mid, right))\n\nproc query[T](segt: var\
    \ SegTree[T], a, b: Natural): T =\n  return segt.query(a, b, 0, 0, segt.real_size)\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: nim-library/segment_tree.nim
  requiredBy: []
  timestamp: '2019-04-11 03:52:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: nim-library/segment_tree.nim
layout: document
redirect_from:
- /library/nim-library/segment_tree.nim
- /library/nim-library/segment_tree.nim.html
title: nim-library/segment_tree.nim
---
