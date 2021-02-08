---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"c++-library/segtree_rangeadd.cpp\"\ntemplate <typename T>\n\
    struct RangeSumQuery {\n  int N, _N;\n  vector<T> data, datb;\n\n  RangeSumQuery(int\
    \ _N) : _N(_N) {\n    assert(_N > 0);\n    N = 1;\n    while (N < _N) N <<= 1;\n\
    \    data.assign(2 * N - 1, 0);\n    datb.assign(2 * N - 1, 0);\n  }\n\n  void\
    \ add(int a, int b, T x) { add(a, b, x, 0, 0, N); }\n  void add(int a, int b,\
    \ T x, int k, int l, int r) {\n    if (a <= l and r <= b) {\n      data[k] +=\
    \ x;\n    } else if (l < b and a < r) {\n      datb[k] += (min(r, b) - max(l,\
    \ a)) * x;\n      add(a, b, x, 2 * k + 1, l, (l + r) / 2);\n      add(a, b, x,\
    \ 2 * k + 2, (l + r) / 2, r);\n    }\n  }\n\n  T sum(int a, int b) { return sum(a,\
    \ b, 0, 0, N); }\n  T sum(int a, int b, int k, int l, int r) {\n    if (b <= l\
    \ or r <= a) {\n      return 0;\n    } else if (a <= l and r <= b) {\n      return\
    \ data[k] * (r - l) + datb[k];\n    } else {\n      T res = data[k] * (min(r,\
    \ b) - max(l, a));\n      res += sum(a, b, 2 * k + 1, l, (l + r) / 2);\n     \
    \ res += sum(a, b, 2 * k + 2, (l + r) / 2, r);\n      return res;\n    }\n  }\n\
    };\n"
  code: "template <typename T>\nstruct RangeSumQuery {\n  int N, _N;\n  vector<T>\
    \ data, datb;\n\n  RangeSumQuery(int _N) : _N(_N) {\n    assert(_N > 0);\n   \
    \ N = 1;\n    while (N < _N) N <<= 1;\n    data.assign(2 * N - 1, 0);\n    datb.assign(2\
    \ * N - 1, 0);\n  }\n\n  void add(int a, int b, T x) { add(a, b, x, 0, 0, N);\
    \ }\n  void add(int a, int b, T x, int k, int l, int r) {\n    if (a <= l and\
    \ r <= b) {\n      data[k] += x;\n    } else if (l < b and a < r) {\n      datb[k]\
    \ += (min(r, b) - max(l, a)) * x;\n      add(a, b, x, 2 * k + 1, l, (l + r) /\
    \ 2);\n      add(a, b, x, 2 * k + 2, (l + r) / 2, r);\n    }\n  }\n\n  T sum(int\
    \ a, int b) { return sum(a, b, 0, 0, N); }\n  T sum(int a, int b, int k, int l,\
    \ int r) {\n    if (b <= l or r <= a) {\n      return 0;\n    } else if (a <=\
    \ l and r <= b) {\n      return data[k] * (r - l) + datb[k];\n    } else {\n \
    \     T res = data[k] * (min(r, b) - max(l, a));\n      res += sum(a, b, 2 * k\
    \ + 1, l, (l + r) / 2);\n      res += sum(a, b, 2 * k + 2, (l + r) / 2, r);\n\
    \      return res;\n    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: c++-library/segtree_rangeadd.cpp
  requiredBy: []
  timestamp: '2019-04-11 03:52:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: c++-library/segtree_rangeadd.cpp
layout: document
redirect_from:
- /library/c++-library/segtree_rangeadd.cpp
- /library/c++-library/segtree_rangeadd.cpp.html
title: c++-library/segtree_rangeadd.cpp
---
