---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/cpp/suffix_array.test.cpp
    title: tests/cpp/suffix_array.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/cpp/suffix_array_lcp.test.cpp
    title: tests/cpp/suffix_array_lcp.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"c++-library/suffix_array.cpp\"\n#include <functional>\n\
    #include <string>\n#include <vector>\n\nstruct SuffixArray {\n  int N, k;\n  std::string\
    \ S;\n  std::vector<int> sa, rank, tmp;\n  std::vector<int> lcp, rank_lcp;\n \
    \ SuffixArray(std::string &S)\n      : N(S.size()), S(S), sa(N + 1), rank(N +\
    \ 1), tmp(N + 1) {\n    construct();\n  }\n\n  void construct() {\n    for (int\
    \ i = 0; i <= N; i++) {\n      sa[i] = i;\n      rank[i] = i < N ? S[i] : -1;\n\
    \    }\n\n    std::function<bool(int, int)> compare = [&](int i, int j) {\n  \
    \    if (rank[i] != rank[j]) {\n        return rank[i] < rank[j];\n      } else\
    \ {\n        int ri = i + k <= N ? rank[i + k] : -1;\n        int rj = j + k <=\
    \ N ? rank[j + k] : -1;\n        return ri < rj;\n      }\n    };\n    for (k\
    \ = 1; k <= N; k *= 2) {\n      sort(sa.begin(), sa.end(), compare);\n\n     \
    \ tmp[sa[0]] = 0;\n      for (int i = 1; i <= N; i++) {\n        tmp[sa[i]] =\
    \ tmp[sa[i - 1]] + (compare(sa[i - 1], sa[i]) ? 1 : 0);\n      }\n      for (int\
    \ i = 0; i <= N; i++) rank[i] = tmp[i];\n    }\n  }\n\n  bool contain(const std::string\
    \ &T) const {\n    int left = 0, right = N;\n    while (left + 1 < right) {\n\
    \      int mid = (left + right) / 2;\n      (S.compare(sa[mid], T.length(), T)\
    \ < 0 ? left : right) = mid;\n    }\n    return S.compare(sa[right], T.length(),\
    \ T) == 0;\n  }\n\n  void construct_lcp() {\n    lcp.resize(N), rank_lcp.resize(N\
    \ + 1);\n    for (int i = 0; i <= N; i++) rank_lcp[sa[i]] = i;\n\n    int h =\
    \ 0;\n    lcp[0] = 0;\n    for (int i = 0; i < N; i++) {\n      int j = sa[rank[i]\
    \ - 1];\n\n      if (h > 0) h--;\n      for (; j + h < N and i + h < N; h++) {\n\
    \        if (S[j + h] != S[i + h]) break;\n      }\n\n      lcp[rank[i] - 1] =\
    \ h;\n    }\n  }\n};\n"
  code: "#include <functional>\n#include <string>\n#include <vector>\n\nstruct SuffixArray\
    \ {\n  int N, k;\n  std::string S;\n  std::vector<int> sa, rank, tmp;\n  std::vector<int>\
    \ lcp, rank_lcp;\n  SuffixArray(std::string &S)\n      : N(S.size()), S(S), sa(N\
    \ + 1), rank(N + 1), tmp(N + 1) {\n    construct();\n  }\n\n  void construct()\
    \ {\n    for (int i = 0; i <= N; i++) {\n      sa[i] = i;\n      rank[i] = i <\
    \ N ? S[i] : -1;\n    }\n\n    std::function<bool(int, int)> compare = [&](int\
    \ i, int j) {\n      if (rank[i] != rank[j]) {\n        return rank[i] < rank[j];\n\
    \      } else {\n        int ri = i + k <= N ? rank[i + k] : -1;\n        int\
    \ rj = j + k <= N ? rank[j + k] : -1;\n        return ri < rj;\n      }\n    };\n\
    \    for (k = 1; k <= N; k *= 2) {\n      sort(sa.begin(), sa.end(), compare);\n\
    \n      tmp[sa[0]] = 0;\n      for (int i = 1; i <= N; i++) {\n        tmp[sa[i]]\
    \ = tmp[sa[i - 1]] + (compare(sa[i - 1], sa[i]) ? 1 : 0);\n      }\n      for\
    \ (int i = 0; i <= N; i++) rank[i] = tmp[i];\n    }\n  }\n\n  bool contain(const\
    \ std::string &T) const {\n    int left = 0, right = N;\n    while (left + 1 <\
    \ right) {\n      int mid = (left + right) / 2;\n      (S.compare(sa[mid], T.length(),\
    \ T) < 0 ? left : right) = mid;\n    }\n    return S.compare(sa[right], T.length(),\
    \ T) == 0;\n  }\n\n  void construct_lcp() {\n    lcp.resize(N), rank_lcp.resize(N\
    \ + 1);\n    for (int i = 0; i <= N; i++) rank_lcp[sa[i]] = i;\n\n    int h =\
    \ 0;\n    lcp[0] = 0;\n    for (int i = 0; i < N; i++) {\n      int j = sa[rank[i]\
    \ - 1];\n\n      if (h > 0) h--;\n      for (; j + h < N and i + h < N; h++) {\n\
    \        if (S[j + h] != S[i + h]) break;\n      }\n\n      lcp[rank[i] - 1] =\
    \ h;\n    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: c++-library/suffix_array.cpp
  requiredBy: []
  timestamp: '2020-09-08 07:30:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/cpp/suffix_array_lcp.test.cpp
  - tests/cpp/suffix_array.test.cpp
documentation_of: c++-library/suffix_array.cpp
layout: document
redirect_from:
- /library/c++-library/suffix_array.cpp
- /library/c++-library/suffix_array.cpp.html
title: c++-library/suffix_array.cpp
---
