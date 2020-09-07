---
data:
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/nim.py\"\
    , line 86, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# import sequtils, strutils, strscans, algorithm, math, future, sets, queues,\
    \ tables # for yukicoder (0.17.1)\nimport sequtils, strutils, algorithm, math,\
    \ future, sets, queues, tables # for AtCoder (0.13.0)\ntemplate getLine: string\
    \ = stdin.readLine\ntemplate getInteger: int = getLine.parseInt\ntemplate getBiggestInteger:\
    \ int64 = getLine.parseBiggestInt\ntemplate getIntSeq: seq[int] = getLine.split.map(parseInt)\n\
    template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)\n\nproc\
    \ dfs(num_array: seq[int], left, right, center, rest: var seq[int]): void =\n\
    \  if rest.len == 0:\n    assert(left.len == right.len)\n    if num_array.len\
    \ mod 2 == 1:\n      assert(center.len == 1)\n\n    let generated_pairs = left.zip(right).mapIt((num_array[it[0]],\
    \ num_array[it[1]]))\n    generated_pairs.echo\n  elif center.len == 0 and num_array.len\
    \ mod 2 == 1:\n    center.add(rest.pop)\n    dfs(num_array, left, right, center,\
    \ rest)\n    for i in 0..<rest.len:\n      swap(center[0], rest[i])\n      dfs(num_array,\
    \ left, right, center, rest)\n      swap(center[0], rest[i])\n    rest.add(center.pop)\n\
    \  else:\n    left.add(rest.pop)\n    right.add(rest.pop)\n    dfs(num_array,\
    \ left, right, center, rest)\n    for i in 0..<rest.len:\n      swap(right[^1],\
    \ rest[i])\n      dfs(num_array, left, right, center, rest)\n      swap(right[^1],\
    \ rest[i])\n    rest.add(right.pop)\n    rest.add(left.pop)\n\nproc pair_enumeration(num_array:\
    \ seq[int]): void =\n  var\n    left, right, center = newSeq[int]()\n    rest\
    \ = toSeq(0..<num_array.len)\n  dfs(num_array, left, right, center, rest)\n\n\
    when isMainModule:\n  pair_enumeration(@[1, 2, 3, 4])\n  echo()\n  pair_enumeration(@[1,\
    \ 2, 3, 4, 5])\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: nim-library/pair_enum.nim
  requiredBy: []
  timestamp: '2019-04-11 03:52:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: nim-library/pair_enum.nim
layout: document
redirect_from:
- /library/nim-library/pair_enum.nim
- /library/nim-library/pair_enum.nim.html
title: nim-library/pair_enum.nim
---
