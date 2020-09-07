---
data:
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "def calc_largest_rect_in_hist(heights):\n    heights.append(0)\n    stack\
    \ = []\n    left = [0] * len(heights)\n    ans = 0\n    for i, height in enumerate(heights):\n\
    \        while stack and heights[stack[-1]] >= height:\n            idx = stack.pop()\n\
    \            ans = max(ans, (i - left[idx] - 1) * heights[idx])\n        left[i]\
    \ = stack[-1] if stack else -1\n        stack.append(i)\n    heights.pop()\n \
    \   return ans\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith:
  - icon: ':x:'
    path: tests/python/largest_rect_hist.test.py
    title: tests/python/largest_rect_hist.test.py
  - icon: ':x:'
    path: tests/python/largest_rect_rect.test.py
    title: tests/python/largest_rect_rect.test.py
  isVerificationFile: false
  path: python_library/dynamic_programming/largest_rect_hist.py
  requiredBy: []
  timestamp: '2020-02-16 05:33:07+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verificationStatusIcon: ':x:'
  verifiedWith:
  - tests/python/largest_rect_hist.test.py
  - tests/python/largest_rect_rect.test.py
documentation_of: python_library/dynamic_programming/largest_rect_hist.py
layout: document
redirect_from:
- /library/python_library/dynamic_programming/largest_rect_hist.py
- /library/python_library/dynamic_programming/largest_rect_hist.py.html
title: python_library/dynamic_programming/largest_rect_hist.py
---
