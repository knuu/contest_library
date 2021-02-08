---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://twitter.com/maspy_stars/status/1179226257982185472
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# see: https://twitter.com/maspy_stars/status/1179226257982185472\nimport\
    \ sys\nread = sys.stdin.buffer.read\nreadline = sys.stdin.buffer.readline\nreadlines\
    \ = sys.stdin.buffer.readlines\n\n\ndef use_fast_io():\n    global input\n   \
    \ import io\n    import sys\n    f = io.BytesIO(sys.stdin.buffer.read())\n   \
    \ input = f.readline\n"
  dependsOn: []
  isVerificationFile: false
  path: python_library/misc/fast_read.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: python_library/misc/fast_read.py
layout: document
redirect_from:
- /library/python_library/misc/fast_read.py
- /library/python_library/misc/fast_read.py.html
title: python_library/misc/fast_read.py
---
