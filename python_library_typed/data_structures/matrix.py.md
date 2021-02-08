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
  code: "from copy import deepcopy\nfrom typing import List, TypeVar, Generic\n\n\
    T = TypeVar('T', int, float, complex)\n\n\nclass Matrix(Generic[T]):\n    def\
    \ __init__(self, mat: List[List[T]], ZERO: T = 0, ONE: T = 1) -> None:\n     \
    \   assert(len(mat) and len(mat[0]))\n        self.ZERO: T = ZERO\n        self.ONE:\
    \ T = ONE\n        self.mat: List[List[T]] = deepcopy(mat)\n\n    def __mult__(self,\
    \ other: 'Matrix') -> 'Matrix':\n        ret: List[List[T]] = [[self.ZERO] * len(other.mat[0])\
    \ for _ in range(len(self.mat))]\n        for i in range(len(self.mat)):\n   \
    \         for j in range(len(self.mat[0])):\n                for k in range(len(self.mat[0])):\n\
    \                    ret[i][j] += self.mat[i][k] * other.mat[k][j]\n        return\
    \ Matrix(ret)\n\n    def __pow__(self, k: int) -> 'Matrix':\n        ret: 'Matrix'\
    \ = Matrix([[self.ZERO] * len(self.mat[0]) for _ in range(len(self.mat))])\n \
    \       for i in range(len(self.mat)):\n            ret.mat[i][i] = self.ONE\n\
    \        n: 'Matrix' = Matrix(deepcopy(self.mat))\n\n        while k:\n      \
    \      if k & 1:\n                ret = ret.__mult__(n)\n            n = n.__mult__(n)\n\
    \            k >>= 1\n        return ret\n\n    def __str__(self) -> str:\n  \
    \      return '[{}]\\n'.format('\\n'.join(str(row) for row in self.mat))\n"
  dependsOn: []
  isVerificationFile: false
  path: python_library_typed/data_structures/matrix.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: python_library_typed/data_structures/matrix.py
layout: document
redirect_from:
- /library/python_library_typed/data_structures/matrix.py
- /library/python_library_typed/data_structures/matrix.py.html
title: python_library_typed/data_structures/matrix.py
---
