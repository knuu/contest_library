---
data:
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# @import python_library/misc/popcount.py\nfrom python_library.misc.popcount\
    \ import popcount\n\n\ndef maximum_independet_set(v: int, bad: int, adj_mat):\n\
    \    \"\"\"\u6700\u5927\u72EC\u7ACB\u96C6\u5408\n    v: \u4ECA\u8ABF\u3079\u3066\
    \u3044\u308B\u9802\u70B9\n    bad: \u4F7F\u308F\u306A\u3044\u3068\u6C7A\u3081\u305F\
    \u9802\u70B9 (bit)\n    adj_mat: \u96A3\u63A5\u884C\u5217 (bit \u306E\u30EA\u30B9\
    \u30C8)\n\n    \u6700\u5927\u72EC\u7ACB\u96C6\u5408\u306E\u30B5\u30A4\u30BA\u3068\
    \u6700\u5927\u72EC\u7ACB\u96C6\u5408\u3092\u8FD4\u3059\n    \"\"\"\n    if v ==\
    \ len(adj_mat):\n        return 0, 0\n\n    ret, ret_set = 0, 0\n\n    deg = popcount(adj_mat[v]\
    \ & ~bad)\n\n    # use v\n    if (bad >> v & 1) == 0:\n        new_bad = bad |\
    \ (1 << v) | (adj_mat[v] & ~bad)\n        cand, cand_set = maximum_independet_set(v\
    \ + 1, new_bad, adj_mat)\n        if cand + 1 > ret:\n            ret, ret_set\
    \ = cand + 1, cand_set | (1 << v)\n\n    # do not use v\n    if deg > 1 or (bad\
    \ >> v & 1):\n        new_bad = bad\n        if (bad >> v & 1) == 0:\n       \
    \     new_bad |= 1 << v\n        cand, cand_set = maximum_independet_set(v + 1,\
    \ new_bad, adj_mat)\n        if cand > ret:\n            ret, ret_set = cand,\
    \ cand_set\n\n    return ret, ret_set\n"
  dependsOn:
  - python_library/misc/popcount.py
  extendedDependsOn:
  - icon: ':warning:'
    path: python_library/misc/popcount.py
    title: python_library/misc/popcount.py
  extendedRequiredBy: []
  extendedVerifiedWith:
  - icon: ':x:'
    path: tests/python/maximum_independet_set.test.py
    title: tests/python/maximum_independet_set.test.py
  isVerificationFile: false
  path: python_library/graph/maximum_independet_set.py
  requiredBy: []
  timestamp: '2020-02-16 07:49:55+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verificationStatusIcon: ':x:'
  verifiedWith:
  - tests/python/maximum_independet_set.test.py
documentation_of: python_library/graph/maximum_independet_set.py
layout: document
redirect_from:
- /library/python_library/graph/maximum_independet_set.py
- /library/python_library/graph/maximum_independet_set.py.html
title: python_library/graph/maximum_independet_set.py
---
