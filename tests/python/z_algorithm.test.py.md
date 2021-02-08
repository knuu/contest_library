---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: python_library/string/z_algorithm.py
    title: python_library/string/z_algorithm.py
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# verify-helper: PROBLEM https://judge.yosupo.jp/problem/zalgorithm\nimport\
    \ sys\n\nfrom python_library.string.z_algorithm import z_algorithm\n\ninput =\
    \ sys.stdin.buffer.readline\n\n\ndef main() -> None:\n    print(*z_algorithm(input().strip()))\n\
    \n\nif __name__ == \"__main__\":\n    main()\n"
  dependsOn:
  - python_library/string/z_algorithm.py
  isVerificationFile: true
  path: tests/python/z_algorithm.test.py
  requiredBy: []
  timestamp: '2020-09-08 04:10:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/python/z_algorithm.test.py
layout: document
redirect_from:
- /verify/tests/python/z_algorithm.test.py
- /verify/tests/python/z_algorithm.test.py.html
title: tests/python/z_algorithm.test.py
---
