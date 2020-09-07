---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"c++-library/segtree_pointupdate_rangemax.cpp\"\ntemplate<typename\
    \ T> struct RangeMaxQuery {\n  int N, _N;\n  vector<T> dat;\n  T initial;\n\n\
    \  RangeMaxQuery(int _N, T initial = 0) : _N(_N), initial(initial) {\n    assert(_N\
    \ > 0);\n    N = 1;\n    while (N < _N)\n      N <<= 1;\n    dat.assign(2 * N\
    \ - 1, initial);\n  }\n\n  void update(int k, T val) {\n    assert(0 <= k && k\
    \ < _N);\n    k += N - 1;\n    dat[k] = val;\n\n    while (k > 0) {\n      k =\
    \ (k - 1) / 2;\n      dat[k] = max(dat[2 * k + 1], dat[2 * k + 2]);\n    }\n \
    \ }\n\n  // [a, b)\n  T query(int a, int b) {\n    assert(0 <= a && a <= b &&\
    \ b <= _N);\n    return query(a, b, 0, 0, N);\n  }\n\n  T query(int a, int b,\
    \ int k, int l, int r) {\n    if (r <= a || b <= l) return initial;\n    if (a\
    \ <= l && r <= b) return dat[k];\n\n    int mid = (l + r) / 2;\n    return max(query(a,\
    \ b, 2 * k + 1, l, mid),\n               query(a, b, 2 * k + 2, mid, r));\n  }\n\
    };\n"
  code: "template<typename T> struct RangeMaxQuery {\n  int N, _N;\n  vector<T> dat;\n\
    \  T initial;\n\n  RangeMaxQuery(int _N, T initial = 0) : _N(_N), initial(initial)\
    \ {\n    assert(_N > 0);\n    N = 1;\n    while (N < _N)\n      N <<= 1;\n   \
    \ dat.assign(2 * N - 1, initial);\n  }\n\n  void update(int k, T val) {\n    assert(0\
    \ <= k && k < _N);\n    k += N - 1;\n    dat[k] = val;\n\n    while (k > 0) {\n\
    \      k = (k - 1) / 2;\n      dat[k] = max(dat[2 * k + 1], dat[2 * k + 2]);\n\
    \    }\n  }\n\n  // [a, b)\n  T query(int a, int b) {\n    assert(0 <= a && a\
    \ <= b && b <= _N);\n    return query(a, b, 0, 0, N);\n  }\n\n  T query(int a,\
    \ int b, int k, int l, int r) {\n    if (r <= a || b <= l) return initial;\n \
    \   if (a <= l && r <= b) return dat[k];\n\n    int mid = (l + r) / 2;\n    return\
    \ max(query(a, b, 2 * k + 1, l, mid),\n               query(a, b, 2 * k + 2, mid,\
    \ r));\n  }\n};\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: c++-library/segtree_pointupdate_rangemax.cpp
  requiredBy: []
  timestamp: '2019-04-11 03:52:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: c++-library/segtree_pointupdate_rangemax.cpp
layout: document
redirect_from:
- /library/c++-library/segtree_pointupdate_rangemax.cpp
- /library/c++-library/segtree_pointupdate_rangemax.cpp.html
title: c++-library/segtree_pointupdate_rangemax.cpp
---
