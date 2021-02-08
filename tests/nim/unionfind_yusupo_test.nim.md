---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: nim-library/union_find.nim
    title: nim-library/union_find.nim
  - icon: ':heavy_check_mark:'
    path: nim-library/union_find.nim
    title: nim-library/union_find.nim
  - icon: ':heavy_check_mark:'
    path: nim-library/utils.nim
    title: nim-library/utils.nim
  - icon: ':heavy_check_mark:'
    path: nim-library/utils.nim
    title: nim-library/utils.nim
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: nim
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/nim.py\"\
    , line 86, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# verify-helper: PROBLEM https://judge.yosupo.jp/problem/unionfind\n\ninclude\
    \ \"nim-library/utils.nim\"\ninclude \"nim-library/union_find.nim\"\n\nwhen isMainModule:\n\
    \  let (N, Q) = input(int, 2)\n  var dset = initUnionFindTree(N)\n  for i in 0..<Q:\n\
    \    let (t, u, v) = input(int, 3)\n    if t == 0:\n      dset.uniteNode(u, v)\n\
    \    else:\n      echo dset.hasSameRoot(u, v).int\n"
  dependsOn:
  - nim-library/utils.nim
  - nim-library/utils.nim
  - nim-library/union_find.nim
  - nim-library/union_find.nim
  isVerificationFile: true
  path: tests/nim/unionfind_yusupo_test.nim
  requiredBy: []
  timestamp: '2020-09-09 01:00:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/nim/unionfind_yusupo_test.nim
layout: document
redirect_from:
- /verify/tests/nim/unionfind_yusupo_test.nim
- /verify/tests/nim/unionfind_yusupo_test.nim.html
title: tests/nim/unionfind_yusupo_test.nim
---
