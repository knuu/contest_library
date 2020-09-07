---
data:
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "from copy import deepcopy\n\n\nclass Matrix:\n    ZERO = 0\n    ONE = 1\n\
    \n    def __init__(self, mat, copy: bool = True):\n        assert len(mat) and\
    \ len(mat[0])\n        if copy:\n            self.mat = deepcopy(mat)\n      \
    \  else:\n            self.mat = mat\n\n    def __matmul__(self, other):\n   \
    \     ret = [[self.ZERO] * len(other.mat[0]) for _ in range(len(self.mat))]\n\
    \        for i in range(len(self.mat)):\n            for k in range(len(self.mat[0])):\n\
    \                for j in range(len(other.mat[0])):\n                    ret[i][j]\
    \ += self.mat[i][k] * other.mat[k][j]\n        return Matrix(ret)\n\n    def __pow__(self,\
    \ k):\n        ret = Matrix([[self.ZERO] * len(self.mat[0]) for _ in range(len(self.mat))])\n\
    \        for i in range(len(self.mat)):\n            ret.mat[i][i] = self.ONE\n\
    \        n = Matrix(deepcopy(self.mat))\n\n        while k:\n            if k\
    \ & 1:\n                ret = ret.__matmul__(n)\n            n = n.__matmul__(n)\n\
    \            k >>= 1\n        return ret\n\n    @property\n    def shape(self):\n\
    \        return len(self.mat), len(self.mat[0])\n\n    def __str__(self):\n  \
    \      return \"[{}]\\n\".format(\"\\n\".join(str(row) for row in self.mat))\n\
    \n\ndef det(mat: Matrix, mod: int = 998244353) -> int:\n    # mat \u306F\u5909\
    \u66F4\u3055\u308C\u308B\u3053\u3068\u306B\u6CE8\u610F\u3002\n    ret = 1\n  \
    \  N = mat.shape[0]\n    for i in range(N):\n        pivot = i\n        for j\
    \ in range(i + 1, N):\n            if abs(mat.mat[j][i]) > abs(mat.mat[pivot][i]):\n\
    \                pivot = j\n        mat.mat[i], mat.mat[pivot] = mat.mat[pivot],\
    \ mat.mat[i]\n        ret *= mat.mat[i][i] * (-1 if i != pivot else 1)\n     \
    \   ret %= mod\n        if not mat.mat[i][i]:\n            break\n        inv\
    \ = pow(mat.mat[i][i], mod - 2, mod)\n        for j in range(i + 1, N):\n    \
    \        for k in reversed(range(i, N)):\n                mat.mat[j][k] += mod\
    \ - mat.mat[i][k] * mat.mat[j][i] % mod * inv % mod\n                mat.mat[j][k]\
    \ %= mod\n    return ret\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/python/matrix_determinant.test.py
    title: tests/python/matrix_determinant.test.py
  - icon: ':x:'
    path: tests/python/matrix_mult.test.py
    title: tests/python/matrix_mult.test.py
  isVerificationFile: false
  path: python_library/data_structures/matrix.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_SOME_WA
  verificationStatusIcon: ':question:'
  verifiedWith:
  - tests/python/matrix_determinant.test.py
  - tests/python/matrix_mult.test.py
documentation_of: python_library/data_structures/matrix.py
layout: document
redirect_from:
- /library/python_library/data_structures/matrix.py
- /library/python_library/data_structures/matrix.py.html
title: python_library/data_structures/matrix.py
---
