---
data:
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/nim.py\"\
    , line 86, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "proc powmod[T](x: T, k: Natural, m: T): T =\n  if k == 0:\n    result = 1\n\
    \  elif k mod 2 == 0:\n    let x = powmod(x, k shr 1, m)\n    result = x * x mod\
    \ m\n  else:\n    result = powmod(x, k-1, m) * x mod m\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: nim-library/powmod.nim
  requiredBy: []
  timestamp: '2019-04-11 03:52:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: nim-library/powmod.nim
layout: document
redirect_from:
- /library/nim-library/powmod.nim
- /library/nim-library/powmod.nim.html
title: nim-library/powmod.nim
---
