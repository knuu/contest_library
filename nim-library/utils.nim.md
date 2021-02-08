---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/nim/unionfind_yusupo_test.nim
    title: tests/nim/unionfind_yusupo_test.nim
  - icon: ':heavy_check_mark:'
    path: tests/nim/unionfind_yusupo_test.nim
    title: tests/nim/unionfind_yusupo_test.nim
  _isVerificationFailed: false
  _pathExtension: nim
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/nim.py\"\
    , line 86, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# import for 1.0.6 (AtCoder)\nimport algorithm, bitops, complex, deques,\
    \ heapqueue, lenientops, macros, math, rationals, sets, sequtils, strformat, strscans,\
    \ strutils, sugar, tables\n# ----- input macro by nimon -----\n\nmacro unpack*(input:\
    \ seq; count: static[int]): untyped =\n  result = quote do: ()\n  for i in 0..<count:\
    \ result.add quote do: `input`[`i`]\n\n## count == 0 \u306E\u3068\u304D unpack\u3057\
    \u306A\u3044(seq)\n## count >  0 \u306E\u3068\u304D count\u500B\u5206 unpack \u3057\
    \u305F\u7D50\u679C\u306E tuple \u3092\u8FD4\u3059\ntype UnselectableTypeError\
    \ = object of Exception\ntemplate input*(typ: typedesc; count: Natural = 0): untyped\
    \ =\n  let line = stdin.readLine.split\n  when count == 0:\n    when typ is int:\
    \    line.map(parseInt)\n    elif typ is float:  line.map(parseFloat)\n    elif\
    \ typ is string: line\n    else: raise newException(UnselectableTypeError, \"\
    You selected a type other than int, float or string\")\n  else:\n    when typ\
    \ is int:    line.map(parseInt).unpack(count)\n    elif typ is float:  line.map(parseFloat).unpack(count)\n\
    \    elif typ is string: line.unpack(count)\n    else: raise newException(UnselectableTypeError,\
    \ \"You selected a type other than int, float or string\")\n\n# 2-dim table\n\
    template inputs*(typ: typedesc; count = 0; rows = 1): untyped =\n  (1..rows).mapIt(input(typ,\
    \ count))\n\n# ----- end input macro -----\n\nconst MOD = 10^9 + 7\nconst INF\
    \ = high(int)"
  dependsOn: []
  isVerificationFile: false
  path: nim-library/utils.nim
  requiredBy: []
  timestamp: '2020-09-08 23:52:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/nim/unionfind_yusupo_test.nim
  - tests/nim/unionfind_yusupo_test.nim
documentation_of: nim-library/utils.nim
layout: document
redirect_from:
- /library/nim-library/utils.nim
- /library/nim-library/utils.nim.html
title: nim-library/utils.nim
---
