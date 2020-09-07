---
data:
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/nim.py\"\
    , line 86, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "type\n  Heap[T]= object\n    data: seq[T]\n    size: int\n    comp: proc\
    \ (x: T, y: T): int\n  EmptyHeapError = object of Exception\n\nproc siftup[T](h:\
    \ var Heap[T]) =\n  var i = h.size - 1\n  while i > 0:\n    var par = (i-1) div\
    \ 2\n    if h.comp(h.data[par], h.data[i]) > 0:\n      swap(h.data[i], h.data[par])\n\
    \      i = par\n    else:\n      break\nproc siftdown[T](h: var Heap[T]) =\n \
    \ var par = 0\n  while par < h.size:\n    let (left, right) = (2*par+1, 2*par+2)\n\
    \    if right < h.size:\n      if h.comp(h.data[par], min(h.data[left], h.data[right]))\
    \ <= 0:\n        break\n      elif h.comp(h.data[left], h.data[right]) < 0:\n\
    \        swap(h.data[par], h.data[left])\n        par = left\n      else:\n  \
    \      swap(h.data[par], h.data[right])\n        par = right\n    elif left <\
    \ h.size:\n      if h.comp(h.data[left], h.data[par]) < 0:\n        swap(h.data[par],\
    \ h.data[left])\n        par = left\n      else:\n        break\n    else:\n \
    \     break\nproc initHeap[T](comparator: proc (x: T, y: T): int = cmp): Heap[T]\
    \ =\n  Heap[T](data: newSeq[T](), size: 0, comp: comparator)\nproc push[T](h:\
    \ var Heap[T], x: T) =\n  h.data.add(x)\n  h.size.inc\n  h.siftup\nproc pop[T](h:\
    \ var Heap[T]): T =\n  if h.size <= 0:\n    raise newException(EmptyHeapError,\
    \ \"cannot pop element, heap is empty\")\n  result = h.data[0]\n  h.data[0] =\
    \ h.data[^1]\n  h.size.dec\n  h.data.setlen(h.size)\n  h.siftdown\nproc empty[T](h:\
    \ var Heap[T]): bool {. inline .} = h.data.len == 0\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: nim-library/heap.nim
  requiredBy: []
  timestamp: '2019-04-11 03:52:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: nim-library/heap.nim
layout: document
redirect_from:
- /library/nim-library/heap.nim
- /library/nim-library/heap.nim.html
title: nim-library/heap.nim
---
