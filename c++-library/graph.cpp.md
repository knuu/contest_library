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
  bundledCode: "#line 1 \"c++-library/graph.cpp\"\n#include <vector>\n\n// graph by\
    \ adjacency list\ntemplate <typename T>\nstruct Edge {\n  int src, dst;\n  T weight;\n\
    \  Edge(const int src, const int dst, const T weight)\n      : src(src), dst(dst),\
    \ weight(weight) {}\n  Edge(const int dst, const T weight) : src(-1), dst(dst),\
    \ weight(weight) {}\n  Edge(const int dst) : src(-1), dst(dst), weight(T(1)) {}\n\
    \  bool operator<(const Edge<T> &e) const { return weight > e.weight; }\n};\n\n\
    template <typename T>\nstruct Graph {\n  int V;\n  std::vector<std::vector<Edge<T>>>\
    \ E;\n  Graph(const int V) : V(V) { E.resize(V); }\n  void add_edge(const int\
    \ src, const int dst, const T weight) {\n    E[src].emplace_back(src, dst, weight);\n\
    \  }\n};\n"
  code: "#include <vector>\n\n// graph by adjacency list\ntemplate <typename T>\n\
    struct Edge {\n  int src, dst;\n  T weight;\n  Edge(const int src, const int dst,\
    \ const T weight)\n      : src(src), dst(dst), weight(weight) {}\n  Edge(const\
    \ int dst, const T weight) : src(-1), dst(dst), weight(weight) {}\n  Edge(const\
    \ int dst) : src(-1), dst(dst), weight(T(1)) {}\n  bool operator<(const Edge<T>\
    \ &e) const { return weight > e.weight; }\n};\n\ntemplate <typename T>\nstruct\
    \ Graph {\n  int V;\n  std::vector<std::vector<Edge<T>>> E;\n  Graph(const int\
    \ V) : V(V) { E.resize(V); }\n  void add_edge(const int src, const int dst, const\
    \ T weight) {\n    E[src].emplace_back(src, dst, weight);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: c++-library/graph.cpp
  requiredBy: []
  timestamp: '2020-01-21 04:11:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: c++-library/graph.cpp
layout: document
redirect_from:
- /library/c++-library/graph.cpp
- /library/c++-library/graph.cpp.html
title: c++-library/graph.cpp
---
