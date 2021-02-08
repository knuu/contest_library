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
  bundledCode: "#line 1 \"c++-library/maximum_clique.cpp\"\n#include <cassert>\n#include\
    \ <iostream>\n#include <numeric>\n#include <vector>\n\nstd::vector<int> maximum_clique_naive(\n\
    \    const std::vector<int> &vs, const std::vector<std::vector<int>> &adj_mat)\
    \ {\n  assert(vs.size() < 31);\n  std::vector<int> adj_bits(vs.size());\n  for\
    \ (size_t i = 0; i < vs.size(); i++) {\n    for (size_t j = i + 1; j < vs.size();\
    \ j++) {\n      if (adj_mat[vs[i]][vs[j]]) {\n        adj_bits[i] |= 1 << j;\n\
    \        adj_bits[j] |= 1 << i;\n      }\n    }\n  }\n\n  size_t ans_bit = 0,\
    \ ans_count = 0;\n  for (size_t bit = 0; bit < (1U << vs.size()); bit++) {\n \
    \   bool flag = true;\n    size_t bit_count = __builtin_popcount(bit);\n    for\
    \ (size_t i = 0; i < vs.size(); i++) {\n      if ((bit >> i & 1) and\n       \
    \   __builtin_popcount(adj_bits[i] & bit) + 1U != bit_count) {\n        flag =\
    \ false;\n        break;\n      }\n    }\n    if (flag and bit_count > ans_count)\
    \ {\n      ans_bit = bit;\n      ans_count = bit_count;\n    }\n  }\n\n  std::vector<int>\
    \ ret;\n  for (size_t i = 0; i < vs.size(); i++) {\n    if (ans_bit >> i & 1)\
    \ ret.emplace_back(vs[i]);\n  }\n  return ret;\n}\n\nvoid abc002_d() {\n  int\
    \ N, M;\n  std::cin >> N >> M;\n  std::vector<std::vector<int>> adj_mat(N, std::vector<int>(N,\
    \ 0));\n  for (int i = 0; i < M; i++) {\n    int x, y;\n    std::cin >> x >> y;\n\
    \    x--, y--;\n    adj_mat[x][y] = adj_mat[y][x] = 1;\n  }\n  std::vector<int>\
    \ vs(N);\n  std::iota(vs.begin(), vs.end(), 0);\n  std::cout << maximum_clique_naive(vs,\
    \ adj_mat).size() << std::endl;\n}\n\nint main() {\n  std::cin.tie(0);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  abc002_d();\n  return 0;\n}\n"
  code: "#include <cassert>\n#include <iostream>\n#include <numeric>\n#include <vector>\n\
    \nstd::vector<int> maximum_clique_naive(\n    const std::vector<int> &vs, const\
    \ std::vector<std::vector<int>> &adj_mat) {\n  assert(vs.size() < 31);\n  std::vector<int>\
    \ adj_bits(vs.size());\n  for (size_t i = 0; i < vs.size(); i++) {\n    for (size_t\
    \ j = i + 1; j < vs.size(); j++) {\n      if (adj_mat[vs[i]][vs[j]]) {\n     \
    \   adj_bits[i] |= 1 << j;\n        adj_bits[j] |= 1 << i;\n      }\n    }\n \
    \ }\n\n  size_t ans_bit = 0, ans_count = 0;\n  for (size_t bit = 0; bit < (1U\
    \ << vs.size()); bit++) {\n    bool flag = true;\n    size_t bit_count = __builtin_popcount(bit);\n\
    \    for (size_t i = 0; i < vs.size(); i++) {\n      if ((bit >> i & 1) and\n\
    \          __builtin_popcount(adj_bits[i] & bit) + 1U != bit_count) {\n      \
    \  flag = false;\n        break;\n      }\n    }\n    if (flag and bit_count >\
    \ ans_count) {\n      ans_bit = bit;\n      ans_count = bit_count;\n    }\n  }\n\
    \n  std::vector<int> ret;\n  for (size_t i = 0; i < vs.size(); i++) {\n    if\
    \ (ans_bit >> i & 1) ret.emplace_back(vs[i]);\n  }\n  return ret;\n}\n\nvoid abc002_d()\
    \ {\n  int N, M;\n  std::cin >> N >> M;\n  std::vector<std::vector<int>> adj_mat(N,\
    \ std::vector<int>(N, 0));\n  for (int i = 0; i < M; i++) {\n    int x, y;\n \
    \   std::cin >> x >> y;\n    x--, y--;\n    adj_mat[x][y] = adj_mat[y][x] = 1;\n\
    \  }\n  std::vector<int> vs(N);\n  std::iota(vs.begin(), vs.end(), 0);\n  std::cout\
    \ << maximum_clique_naive(vs, adj_mat).size() << std::endl;\n}\n\nint main() {\n\
    \  std::cin.tie(0);\n  std::ios_base::sync_with_stdio(false);\n\n  abc002_d();\n\
    \  return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: c++-library/maximum_clique.cpp
  requiredBy: []
  timestamp: '2020-09-08 04:11:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: c++-library/maximum_clique.cpp
layout: document
redirect_from:
- /library/c++-library/maximum_clique.cpp
- /library/c++-library/maximum_clique.cpp.html
title: c++-library/maximum_clique.cpp
---
