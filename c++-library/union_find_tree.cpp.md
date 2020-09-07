---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"c++-library/union_find_tree.cpp\"\n#include <iostream>\n\
    #include <vector>\n\nstruct DisjointSet {\n  std::vector<size_t> parent, rank;\n\
    \n  DisjointSet(const size_t N) : parent(N), rank(N, 0) {\n    for (size_t i =\
    \ 0; i < N; i++) parent[i] = i;\n  }\n\n  size_t find(const size_t x) {\n    if\
    \ (parent[x] == x) {\n      return x;\n    } else {\n      return parent[x] =\
    \ find(parent[x]);\n    }\n  }\n\n  void unite(size_t x, size_t y) {\n    x =\
    \ find(x), y = find(y);\n    if (x == y) return;\n    if (rank[x] < rank[y]) {\n\
    \      parent[x] = y;\n    } else {\n      parent[y] = x;\n      if (rank[x] ==\
    \ rank[y]) rank[x]++;\n    }\n  }\n\n  bool same(const size_t x, const size_t\
    \ y) { return find(x) == find(y); }\n};\n\nvoid yosupo_aoj() {\n  // https://judge.yosupo.jp/problem/unionfind\n\
    \  // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A&lang=ja\n\
    \  int N, Q;\n  std::cin >> N >> Q;\n  DisjointSet uft(N);\n  for (int i = 0;\
    \ i < Q; i++) {\n    int t, u, v;\n    std::cin >> t >> u >> v;\n    if (t ==\
    \ 0) {\n      uft.unite(u, v);\n    } else {\n      std::cout << uft.same(u, v)\
    \ << std::endl;\n    }\n  }\n}\n\nint main() {\n  std::cin.tie(0);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  yosupo_aoj();\n  return 0;\n}\n"
  code: "#include <iostream>\n#include <vector>\n\nstruct DisjointSet {\n  std::vector<size_t>\
    \ parent, rank;\n\n  DisjointSet(const size_t N) : parent(N), rank(N, 0) {\n \
    \   for (size_t i = 0; i < N; i++) parent[i] = i;\n  }\n\n  size_t find(const\
    \ size_t x) {\n    if (parent[x] == x) {\n      return x;\n    } else {\n    \
    \  return parent[x] = find(parent[x]);\n    }\n  }\n\n  void unite(size_t x, size_t\
    \ y) {\n    x = find(x), y = find(y);\n    if (x == y) return;\n    if (rank[x]\
    \ < rank[y]) {\n      parent[x] = y;\n    } else {\n      parent[y] = x;\n   \
    \   if (rank[x] == rank[y]) rank[x]++;\n    }\n  }\n\n  bool same(const size_t\
    \ x, const size_t y) { return find(x) == find(y); }\n};\n\nvoid yosupo_aoj() {\n\
    \  // https://judge.yosupo.jp/problem/unionfind\n  // http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A&lang=ja\n\
    \  int N, Q;\n  std::cin >> N >> Q;\n  DisjointSet uft(N);\n  for (int i = 0;\
    \ i < Q; i++) {\n    int t, u, v;\n    std::cin >> t >> u >> v;\n    if (t ==\
    \ 0) {\n      uft.unite(u, v);\n    } else {\n      std::cout << uft.same(u, v)\
    \ << std::endl;\n    }\n  }\n}\n\nint main() {\n  std::cin.tie(0);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  yosupo_aoj();\n  return 0;\n}\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: c++-library/union_find_tree.cpp
  requiredBy: []
  timestamp: '2020-01-21 04:11:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: c++-library/union_find_tree.cpp
layout: document
redirect_from:
- /library/c++-library/union_find_tree.cpp
- /library/c++-library/union_find_tree.cpp.html
title: c++-library/union_find_tree.cpp
---
