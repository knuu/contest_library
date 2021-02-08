---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import sys\nimport ctypes\n\n\ndef popcount(N):\n    if sys.platform.startswith('linux'):\n\
    \        libc = ctypes.cdll.LoadLibrary('libc.so.6')\n        return libc.__sched_cpucount(ctypes.sizeof(ctypes.c_long),\
    \ (ctypes.c_long * 1)(N))\n    elif sys.platform == 'darwin':\n        libc =\
    \ ctypes.cdll.LoadLibrary('libSystem.dylib')\n        return libc.__popcountdi2(N)\n\
    \    else:\n        assert(False)\n"
  dependsOn: []
  isVerificationFile: false
  path: python_library/misc/popcount.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: python_library/misc/popcount.py
layout: document
redirect_from:
- /library/python_library/misc/popcount.py
- /library/python_library/misc/popcount.py.html
title: python_library/misc/popcount.py
---
