---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: py
  _verificationStatusIcon: ':x:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_D
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# verify-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_D\n\
    import sys\n\nfrom python_library.data_structures.matrix import Matrix\n\ninput\
    \ = sys.stdin.buffer.readline\n\n\ndef main() -> None:\n    N, M, _ = map(int,\
    \ input().split())\n    mat1, mat2 = [], []\n    for _ in range(N):\n        mat1.append([int(x)\
    \ for x in input().split()])\n    for _ in range(M):\n        mat2.append([int(x)\
    \ for x in input().split()])\n    A, B = Matrix(mat1, False), Matrix(mat2, False)\n\
    \    for row in (A @ B).mat:\n        print(*row)\n\n\nif __name__ == \"__main__\"\
    :\n    main()\n"
  dependsOn: []
  isVerificationFile: true
  path: tests/python/matrix_mult.test.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/python/matrix_mult.test.py
layout: document
redirect_from:
- /verify/tests/python/matrix_mult.test.py
- /verify/tests/python/matrix_mult.test.py.html
title: tests/python/matrix_mult.test.py
---
