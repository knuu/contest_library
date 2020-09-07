---
data:
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/kth_root_integer
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# verify-helper: PROBLEM https://judge.yosupo.jp/problem/kth_root_integer\n\
    import sys\n\nfrom python_library.math.kth_root import kth_root\n\ninput = sys.stdin.buffer.readline\n\
    \n\ndef main() -> None:\n    ans = [kth_root(*map(int, input().split())) for _\
    \ in range(int(input()))]\n    print(*ans, sep=\"\\n\")\n\n\nif __name__ == \"\
    __main__\":\n    main()\n"
  dependsOn:
  - python_library/math/kth_root.py
  extendedDependsOn:
  - icon: ':x:'
    path: python_library/math/kth_root.py
    title: python_library/math/kth_root.py
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: tests/python/kth_root.test.py
  requiredBy: []
  timestamp: '2020-09-08 04:11:21+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verificationStatusIcon: ':x:'
  verifiedWith: []
documentation_of: tests/python/kth_root.test.py
layout: document
redirect_from:
- /verify/tests/python/kth_root.test.py
- /verify/tests/python/kth_root.test.py.html
title: tests/python/kth_root.test.py
---
