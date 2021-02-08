---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: py
  _verificationStatusIcon: ':x:'
  attributes:
    IGNORE: ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# verify-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C\n\
    # verify-helper: IGNORE\nimport sys\n\nfrom python_library.data_structures.range_tree_2d\
    \ import RangeTree2D\n\ninput = sys.stdin.buffer.readline\n\n\ndef main() -> None:\n\
    \    N = int(input())\n    points = [tuple(map(int, input().split())) for _ in\
    \ range(N)]\n    rt = RangeTree2D()\n    rt.build(points)\n    for _ in range(int(input())):\n\
    \        x1, x2, y1, y2 = map(int, input().split())\n        output = []\n   \
    \     rt.query((x1, x2), (y1, y2), output)\n        if output:\n            output.sort()\n\
    \            print(*output, sep=\"\\n\")\n        print()\n\n\nif __name__ ==\
    \ \"__main__\":\n    main()\n"
  dependsOn: []
  isVerificationFile: true
  path: tests/python/range_tree_2d.test.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/python/range_tree_2d.test.py
layout: document
redirect_from:
- /verify/tests/python/range_tree_2d.test.py
- /verify/tests/python/range_tree_2d.test.py.html
title: tests/python/range_tree_2d.test.py
---
