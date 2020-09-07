---
data:
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/matrix_det
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# verify-helper: PROBLEM https://judge.yosupo.jp/problem/matrix_det\nimport\
    \ sys\n\nfrom python_library.data_structures.matrix import Matrix, det\n\ninput\
    \ = sys.stdin.buffer.readline\n\n\ndef main() -> None:\n    N = int(input())\n\
    \    mat = [[int(x) for x in input().split()] for _ in range(N)]\n    print(det(Matrix(mat)))\n\
    \n\nif __name__ == \"__main__\":\n    main()\n"
  dependsOn:
  - python_library/data_structures/matrix.py
  extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: python_library/data_structures/matrix.py
    title: python_library/data_structures/matrix.py
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: tests/python/matrix_determinant.test.py
  requiredBy: []
  timestamp: '2020-09-08 04:10:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith: []
documentation_of: tests/python/matrix_determinant.test.py
layout: document
redirect_from:
- /verify/tests/python/matrix_determinant.test.py
- /verify/tests/python/matrix_determinant.test.py.html
title: tests/python/matrix_determinant.test.py
---
