---
data:
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/nim.py\"\
    , line 86, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# verify-helper: PROBLEM https://judge.yosupo.jp/problem/unionfind\n\ninclude\
    \ \"nim-library/utils.nim\"\ninclude \"nim-library/union_find.nim\"\n\nwhen isMainModule:\n\
    \  let (N, Q) = input(int, 2)\n  var dset = initUnionFindTree(N)\n  for i in 0..<Q:\n\
    \    let (t, u, v) = input(int, 2)\n    if t == 0:\n      dset.uniteNode(u, v)\n\
    \    else:\n      echo dset.hasSameRoot(u, v).int\n"
  dependsOn:
  - nim-library/utils.nim
  - nim-library/utils.nim
  - nim-library/union_find.nim
  - nim-library/union_find.nim
  extendedDependsOn:
  - icon: ':x:'
    path: nim-library/utils.nim
    title: nim-library/utils.nim
  - icon: ':x:'
    path: nim-library/utils.nim
    title: nim-library/utils.nim
  - icon: ':x:'
    path: nim-library/union_find.nim
    title: nim-library/union_find.nim
  - icon: ':x:'
    path: nim-library/union_find.nim
    title: nim-library/union_find.nim
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: tests/nim/unionfind_yusupo_test.nim
  requiredBy: []
  timestamp: '2020-09-08 23:52:11+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verificationStatusIcon: ':x:'
  verifiedWith: []
documentation_of: tests/nim/unionfind_yusupo_test.nim
layout: document
redirect_from:
- /verify/tests/nim/unionfind_yusupo_test.nim
- /verify/tests/nim/unionfind_yusupo_test.nim.html
title: tests/nim/unionfind_yusupo_test.nim
---
