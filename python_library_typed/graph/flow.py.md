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
  code: "from typing import List, TypeVar, Generic\nT = TypeVar('T', int, float)\n\
    \n\nclass ResidualEdge(Generic[T]):\n    def __init__(self, fr: int, to: int,\
    \ cap: int) -> None:\n        self.fr: int = fr\n        self.to: int = to\n \
    \       self.cap: T = cap\n\n\nclass ResidualGraph:\n    pass\n"
  dependsOn: []
  isVerificationFile: false
  path: python_library_typed/graph/flow.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: python_library_typed/graph/flow.py
layout: document
redirect_from:
- /library/python_library_typed/graph/flow.py
- /library/python_library_typed/graph/flow.py.html
title: python_library_typed/graph/flow.py
---
