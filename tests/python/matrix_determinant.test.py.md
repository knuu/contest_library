---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: py
  _verificationStatusIcon: ':x:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/matrix_det
    links:
    - https://judge.yosupo.jp/problem/matrix_det
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# verify-helper: PROBLEM https://judge.yosupo.jp/problem/matrix_det\nimport\
    \ sys\n\nfrom python_library.data_structures.matrix import Matrix, det\n\ninput\
    \ = sys.stdin.buffer.readline\n\n\ndef main() -> None:\n    N = int(input())\n\
    \    mat = [[int(x) for x in input().split()] for _ in range(N)]\n    print(det(Matrix(mat)))\n\
    \n\nif __name__ == \"__main__\":\n    main()\n"
  dependsOn: []
  isVerificationFile: true
  path: tests/python/matrix_determinant.test.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/python/matrix_determinant.test.py
layout: document
redirect_from:
- /verify/tests/python/matrix_determinant.test.py
- /verify/tests/python/matrix_determinant.test.py.html
title: tests/python/matrix_determinant.test.py
---
