---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: ange Sum Query by FenwickTree(Binary Indexed Tree)
  bundledCode: "#line 1 \"c++-library/fenwick_tree.cpp\"\n/**\n * @brief ange Sum\
    \ Query by FenwickTree(Binary Indexed Tree)\n *\n * total number: n\n * queries:\n\
    \ *    1. add(i, val): bit[i] += val\n *    2. sum(n): sum(bit[0] + ... + bit[n-1])\n\
    \ * query time complexity: O(log n)\n * space complexity: O(N)\n *\n * Self-balancing\
    \ binary search tree or Segment Tree can do the same, it takes\n * longer to program\
    \ and complexity also increases.\n\n * Thanks: http://hos.ac/slides/20140319_bit.pdf\n\
    \ * used in ARC031 C, indeednow finalB E, DSL2B(AOJ), ARC033 C, yukicoder No.59\n\
    \ */\n\n#include <cassert>\n#include <iostream>\n#include <vector>\n\ntemplate\
    \ <typename T>\nstruct RangeSumQuery {\n  int N;\n  std::vector<T> dat;\n\n  RangeSumQuery(int\
    \ N) : N(N) {\n    assert(N > 0);\n    dat.resize(N, 0);\n  }\n\n  void add(int\
    \ k, T val) {\n    assert(0 <= k && k < N);\n    for (int x = k; x < N; x |= x\
    \ + 1) {\n      dat[x] += val;\n    }\n  }\n\n  // [0, k)\n  T sum(int k) const\
    \ {\n    assert(k >= 0);\n    T ret = 0;\n    for (int x = k - 1; x >= 0; x =\
    \ (x & (x + 1)) - 1) {\n      ret += dat[x];\n    }\n    return ret;\n  }\n  //\
    \ [l, r)\n  T sum(int l, int r) const {\n    assert(0 <= l && l <= r && r <= N);\n\
    \    return sum(r) - sum(l);\n  }\n\n  T index(int k) const {\n    assert(0 <=\
    \ k && k < N);\n    return sum(k + 1) - sum(k);\n  }\n};\n\nvoid yosupo() {\n\
    \  int N, Q;\n  std::cin >> N >> Q;\n  RangeSumQuery<long long> rsq(N);\n  for\
    \ (int i = 0; i < N; i++) {\n    long long v;\n    std::cin >> v;\n    rsq.add(i,\
    \ v);\n  }\n\n  for (int i = 0; i < Q; i++) {\n    int t;\n    long long x, y;\n\
    \    std::cin >> t >> x >> y;\n    if (t == 0) {\n      rsq.add(x, y);\n    }\
    \ else {\n      std::cout << rsq.sum(x, y) << '\\n';\n    }\n  }\n}\n\nint main()\
    \ {\n  std::cin.tie(0);\n  std::ios_base::sync_with_stdio(false);\n\n  yosupo();\n\
    \n  return 0;\n}\n"
  code: "/**\n * @brief ange Sum Query by FenwickTree(Binary Indexed Tree)\n *\n *\
    \ total number: n\n * queries:\n *    1. add(i, val): bit[i] += val\n *    2.\
    \ sum(n): sum(bit[0] + ... + bit[n-1])\n * query time complexity: O(log n)\n *\
    \ space complexity: O(N)\n *\n * Self-balancing binary search tree or Segment\
    \ Tree can do the same, it takes\n * longer to program and complexity also increases.\n\
    \n * Thanks: http://hos.ac/slides/20140319_bit.pdf\n * used in ARC031 C, indeednow\
    \ finalB E, DSL2B(AOJ), ARC033 C, yukicoder No.59\n */\n\n#include <cassert>\n\
    #include <iostream>\n#include <vector>\n\ntemplate <typename T>\nstruct RangeSumQuery\
    \ {\n  int N;\n  std::vector<T> dat;\n\n  RangeSumQuery(int N) : N(N) {\n    assert(N\
    \ > 0);\n    dat.resize(N, 0);\n  }\n\n  void add(int k, T val) {\n    assert(0\
    \ <= k && k < N);\n    for (int x = k; x < N; x |= x + 1) {\n      dat[x] += val;\n\
    \    }\n  }\n\n  // [0, k)\n  T sum(int k) const {\n    assert(k >= 0);\n    T\
    \ ret = 0;\n    for (int x = k - 1; x >= 0; x = (x & (x + 1)) - 1) {\n      ret\
    \ += dat[x];\n    }\n    return ret;\n  }\n  // [l, r)\n  T sum(int l, int r)\
    \ const {\n    assert(0 <= l && l <= r && r <= N);\n    return sum(r) - sum(l);\n\
    \  }\n\n  T index(int k) const {\n    assert(0 <= k && k < N);\n    return sum(k\
    \ + 1) - sum(k);\n  }\n};\n\nvoid yosupo() {\n  int N, Q;\n  std::cin >> N >>\
    \ Q;\n  RangeSumQuery<long long> rsq(N);\n  for (int i = 0; i < N; i++) {\n  \
    \  long long v;\n    std::cin >> v;\n    rsq.add(i, v);\n  }\n\n  for (int i =\
    \ 0; i < Q; i++) {\n    int t;\n    long long x, y;\n    std::cin >> t >> x >>\
    \ y;\n    if (t == 0) {\n      rsq.add(x, y);\n    } else {\n      std::cout <<\
    \ rsq.sum(x, y) << '\\n';\n    }\n  }\n}\n\nint main() {\n  std::cin.tie(0);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  yosupo();\n\n  return 0;\n}"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: c++-library/fenwick_tree.cpp
  requiredBy: []
  timestamp: '2020-01-21 04:11:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: c++-library/fenwick_tree.cpp
layout: document
redirect_from:
- /library/c++-library/fenwick_tree.cpp
- /library/c++-library/fenwick_tree.cpp.html
title: ange Sum Query by FenwickTree(Binary Indexed Tree)
---
