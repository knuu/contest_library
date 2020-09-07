---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"c++-library/range_tree_2d.cpp\"\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\ntypedef long long int ll;\ntypedef pair<int, int> P;\n\
    typedef pair<ll, ll> Pll;\ntypedef vector<int> Vi;\n// typedef tuple<int, int,\
    \ int> T;\n#define FOR(i, s, x) for (int i = s; i < (int)(x); i++)\n#define REP(i,\
    \ x) FOR(i, 0, x)\n#define ALL(c) c.begin(), c.end()\n#define DUMP(x) cerr <<\
    \ #x << \" = \" << (x) << endl\n#define UNIQUE(c) sort(ALL(c)), c.erase(unique(ALL(c)),\
    \ c.end())\n\nconst int dr[4] = {-1, 0, 1, 0};\nconst int dc[4] = {0, 1, 0, -1};\n\
    \ntemplate <typename T>\nstruct Point2D {\n  T x, y;\n  size_t idx;  // original\
    \ index\n  Point2D(T x, T y, size_t idx) : x(x), y(y), idx(idx) {}\n  bool operator<(const\
    \ Point2D<T> &other) const {\n    return this->x < other.x or (this->x == other.x\
    \ and this->y < other.y);\n  }\n};\n\ntemplate <typename T>\nstruct RangeTreeNode\
    \ {\n  T low, high;\n  std::vector<T> assoc;\n  std::vector<size_t> indices;\n\
    \  RangeTreeNode(T inf = std::numeric_limits<T>::max())\n      : low(inf), high(inf),\
    \ assoc(), indices() {}\n};\n\ntemplate <typename T>\nstruct RangeTree2D {\n \
    \ size_t size_;\n  std::vector<Point2D<T>> points;\n  std::vector<RangeTreeNode<T>>\
    \ nodes;\n  T inf;\n  RangeTree2D(T inf = std::numeric_limits<T>::max()) : inf(inf)\
    \ {}\n\n  void build(std::vector<Point2D<T>> points) {\n    this->points = points;\n\
    \    std::sort(this->points.begin(), this->points.end());\n    this->size_ = 1;\n\
    \    while (this->size_ < points.size()) {\n      this->size_ <<= 1;\n    }\n\
    \    nodes.assign(2 * this->size_ - 1, RangeTreeNode<T>());\n    for (size_t i\
    \ = 0; i < this->points.size(); i++) {\n      size_t idx = this->size_ - 1 + i;\n\
    \      nodes[idx].low = nodes[idx].high = this->points[i].x;\n      nodes[idx].assoc.emplace_back(this->points[i].y);\n\
    \      nodes[idx].indices.emplace_back(this->points[i].idx);\n    }\n    for (int\
    \ i = (int)this->size_ - 2; i >= 0; i--) {\n      merge(nodes[2 * i + 1], nodes[2\
    \ * i + 2], nodes[i]);\n    }\n  }\n\n  void merge(RangeTreeNode<T> &node1, RangeTreeNode<T>\
    \ &node2,\n             RangeTreeNode<T> &merged) {\n    merged.low = std::min(node1.low,\
    \ node2.low);\n    merged.high = std::max(node1.high, node2.high);\n    merged.assoc.resize(node1.assoc.size()\
    \ + node2.assoc.size());\n    merged.indices.resize(merged.assoc.size());\n\n\
    \    node1.assoc.push_back(this->inf), node2.assoc.push_back(this->inf);\n   \
    \ for (size_t i = 0, l = 0, r = 0; i < merged.assoc.size(); i++) {\n      if (node1.assoc[l]\
    \ < node2.assoc[r] or\n          (node1.assoc[l] == node2.assoc[r] and\n     \
    \      points[node1.indices[l]].x < points[node2.indices[r]].x)) {\n        merged.assoc[i]\
    \ = node1.assoc[l];\n        merged.indices[i] = node1.indices[l];\n        l++;\n\
    \      } else {\n        merged.assoc[i] = node2.assoc[r];\n        merged.indices[i]\
    \ = node2.indices[r];\n        r++;\n      }\n    }\n    node1.assoc.pop_back(),\
    \ node2.assoc.pop_back();\n  }\n\n  void enumerate(T x_low, T x_high, T y_low,\
    \ T y_high,\n                 std::vector<size_t> &output, size_t idx = 0) const\
    \ {\n    if (idx >= 2 * size_ - 1 or x_high < nodes[idx].low or\n        nodes[idx].high\
    \ < x_low) {\n      return;\n    } else if (x_low <= nodes[idx].low and nodes[idx].high\
    \ <= x_high) {\n      size_t lb = std::lower_bound(nodes[idx].assoc.begin(),\n\
    \                                   nodes[idx].assoc.end(), y_low) -\n       \
    \           nodes[idx].assoc.begin();\n      size_t ub = std::lower_bound(nodes[idx].assoc.begin(),\n\
    \                                   nodes[idx].assoc.end(), y_high + 1) -\n  \
    \                nodes[idx].assoc.begin();\n      for (size_t i = lb; i < ub;\
    \ i++) {\n        output.emplace_back(nodes[idx].indices[i]);\n      }\n     \
    \ return;\n    }\n    enumerate(x_low, x_high, y_low, y_high, output, 2 * idx\
    \ + 1);\n    enumerate(x_low, x_high, y_low, y_high, output, 2 * idx + 2);\n \
    \ }\n\n  int count(T x_low, T x_high, T y_low, T y_high, size_t idx = 0) const\
    \ {\n    if (idx >= 2 * size_ - 1 or x_high < nodes[idx].low or\n        nodes[idx].high\
    \ < x_low) {\n      return 0;\n    } else if (x_low <= nodes[idx].low and nodes[idx].high\
    \ <= x_high) {\n      size_t lb = std::lower_bound(nodes[idx].assoc.begin(),\n\
    \                                   nodes[idx].assoc.end(), y_low) -\n       \
    \           nodes[idx].assoc.begin();\n      size_t ub = std::lower_bound(nodes[idx].assoc.begin(),\n\
    \                                   nodes[idx].assoc.end(), y_high + 1) -\n  \
    \                nodes[idx].assoc.begin();\n      return ub - lb;\n    }\n   \
    \ return count(x_low, x_high, y_low, y_high, 2 * idx + 1) +\n           count(x_low,\
    \ x_high, y_low, y_high, 2 * idx + 2);\n  }\n};\n\nint main() {\n  int N;\n  scanf(\"\
    %d\", &N);\n  std::vector<Point2D<int>> points;\n  REP(i, N) {\n    int x, y;\n\
    \    scanf(\"%d %d\", &x, &y);\n    points.emplace_back(Point2D<int>(x, y, i));\n\
    \  }\n  RangeTree2D<int> rt2d;\n  rt2d.build(points);\n  int Q;\n  scanf(\"%d\"\
    , &Q);\n  REP(i, Q) {\n    int sx, tx, sy, ty;\n    scanf(\"%d %d %d %d\", &sx,\
    \ &tx, &sy, &ty);\n    std::vector<size_t> output;\n    rt2d.enumerate(sx, tx,\
    \ sy, ty, output);\n    std::sort(output.begin(), output.end());\n    for (size_t\
    \ i : output) printf(\"%lu\\n\", i);\n    printf(\"\\n\");\n  }\n  return 0;\n\
    }\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\ntypedef long long int ll;\n\
    typedef pair<int, int> P;\ntypedef pair<ll, ll> Pll;\ntypedef vector<int> Vi;\n\
    // typedef tuple<int, int, int> T;\n#define FOR(i, s, x) for (int i = s; i < (int)(x);\
    \ i++)\n#define REP(i, x) FOR(i, 0, x)\n#define ALL(c) c.begin(), c.end()\n#define\
    \ DUMP(x) cerr << #x << \" = \" << (x) << endl\n#define UNIQUE(c) sort(ALL(c)),\
    \ c.erase(unique(ALL(c)), c.end())\n\nconst int dr[4] = {-1, 0, 1, 0};\nconst\
    \ int dc[4] = {0, 1, 0, -1};\n\ntemplate <typename T>\nstruct Point2D {\n  T x,\
    \ y;\n  size_t idx;  // original index\n  Point2D(T x, T y, size_t idx) : x(x),\
    \ y(y), idx(idx) {}\n  bool operator<(const Point2D<T> &other) const {\n    return\
    \ this->x < other.x or (this->x == other.x and this->y < other.y);\n  }\n};\n\n\
    template <typename T>\nstruct RangeTreeNode {\n  T low, high;\n  std::vector<T>\
    \ assoc;\n  std::vector<size_t> indices;\n  RangeTreeNode(T inf = std::numeric_limits<T>::max())\n\
    \      : low(inf), high(inf), assoc(), indices() {}\n};\n\ntemplate <typename\
    \ T>\nstruct RangeTree2D {\n  size_t size_;\n  std::vector<Point2D<T>> points;\n\
    \  std::vector<RangeTreeNode<T>> nodes;\n  T inf;\n  RangeTree2D(T inf = std::numeric_limits<T>::max())\
    \ : inf(inf) {}\n\n  void build(std::vector<Point2D<T>> points) {\n    this->points\
    \ = points;\n    std::sort(this->points.begin(), this->points.end());\n    this->size_\
    \ = 1;\n    while (this->size_ < points.size()) {\n      this->size_ <<= 1;\n\
    \    }\n    nodes.assign(2 * this->size_ - 1, RangeTreeNode<T>());\n    for (size_t\
    \ i = 0; i < this->points.size(); i++) {\n      size_t idx = this->size_ - 1 +\
    \ i;\n      nodes[idx].low = nodes[idx].high = this->points[i].x;\n      nodes[idx].assoc.emplace_back(this->points[i].y);\n\
    \      nodes[idx].indices.emplace_back(this->points[i].idx);\n    }\n    for (int\
    \ i = (int)this->size_ - 2; i >= 0; i--) {\n      merge(nodes[2 * i + 1], nodes[2\
    \ * i + 2], nodes[i]);\n    }\n  }\n\n  void merge(RangeTreeNode<T> &node1, RangeTreeNode<T>\
    \ &node2,\n             RangeTreeNode<T> &merged) {\n    merged.low = std::min(node1.low,\
    \ node2.low);\n    merged.high = std::max(node1.high, node2.high);\n    merged.assoc.resize(node1.assoc.size()\
    \ + node2.assoc.size());\n    merged.indices.resize(merged.assoc.size());\n\n\
    \    node1.assoc.push_back(this->inf), node2.assoc.push_back(this->inf);\n   \
    \ for (size_t i = 0, l = 0, r = 0; i < merged.assoc.size(); i++) {\n      if (node1.assoc[l]\
    \ < node2.assoc[r] or\n          (node1.assoc[l] == node2.assoc[r] and\n     \
    \      points[node1.indices[l]].x < points[node2.indices[r]].x)) {\n        merged.assoc[i]\
    \ = node1.assoc[l];\n        merged.indices[i] = node1.indices[l];\n        l++;\n\
    \      } else {\n        merged.assoc[i] = node2.assoc[r];\n        merged.indices[i]\
    \ = node2.indices[r];\n        r++;\n      }\n    }\n    node1.assoc.pop_back(),\
    \ node2.assoc.pop_back();\n  }\n\n  void enumerate(T x_low, T x_high, T y_low,\
    \ T y_high,\n                 std::vector<size_t> &output, size_t idx = 0) const\
    \ {\n    if (idx >= 2 * size_ - 1 or x_high < nodes[idx].low or\n        nodes[idx].high\
    \ < x_low) {\n      return;\n    } else if (x_low <= nodes[idx].low and nodes[idx].high\
    \ <= x_high) {\n      size_t lb = std::lower_bound(nodes[idx].assoc.begin(),\n\
    \                                   nodes[idx].assoc.end(), y_low) -\n       \
    \           nodes[idx].assoc.begin();\n      size_t ub = std::lower_bound(nodes[idx].assoc.begin(),\n\
    \                                   nodes[idx].assoc.end(), y_high + 1) -\n  \
    \                nodes[idx].assoc.begin();\n      for (size_t i = lb; i < ub;\
    \ i++) {\n        output.emplace_back(nodes[idx].indices[i]);\n      }\n     \
    \ return;\n    }\n    enumerate(x_low, x_high, y_low, y_high, output, 2 * idx\
    \ + 1);\n    enumerate(x_low, x_high, y_low, y_high, output, 2 * idx + 2);\n \
    \ }\n\n  int count(T x_low, T x_high, T y_low, T y_high, size_t idx = 0) const\
    \ {\n    if (idx >= 2 * size_ - 1 or x_high < nodes[idx].low or\n        nodes[idx].high\
    \ < x_low) {\n      return 0;\n    } else if (x_low <= nodes[idx].low and nodes[idx].high\
    \ <= x_high) {\n      size_t lb = std::lower_bound(nodes[idx].assoc.begin(),\n\
    \                                   nodes[idx].assoc.end(), y_low) -\n       \
    \           nodes[idx].assoc.begin();\n      size_t ub = std::lower_bound(nodes[idx].assoc.begin(),\n\
    \                                   nodes[idx].assoc.end(), y_high + 1) -\n  \
    \                nodes[idx].assoc.begin();\n      return ub - lb;\n    }\n   \
    \ return count(x_low, x_high, y_low, y_high, 2 * idx + 1) +\n           count(x_low,\
    \ x_high, y_low, y_high, 2 * idx + 2);\n  }\n};\n\nint main() {\n  int N;\n  scanf(\"\
    %d\", &N);\n  std::vector<Point2D<int>> points;\n  REP(i, N) {\n    int x, y;\n\
    \    scanf(\"%d %d\", &x, &y);\n    points.emplace_back(Point2D<int>(x, y, i));\n\
    \  }\n  RangeTree2D<int> rt2d;\n  rt2d.build(points);\n  int Q;\n  scanf(\"%d\"\
    , &Q);\n  REP(i, Q) {\n    int sx, tx, sy, ty;\n    scanf(\"%d %d %d %d\", &sx,\
    \ &tx, &sy, &ty);\n    std::vector<size_t> output;\n    rt2d.enumerate(sx, tx,\
    \ sy, ty, output);\n    std::sort(output.begin(), output.end());\n    for (size_t\
    \ i : output) printf(\"%lu\\n\", i);\n    printf(\"\\n\");\n  }\n  return 0;\n\
    }\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: c++-library/range_tree_2d.cpp
  requiredBy: []
  timestamp: '2019-04-11 03:52:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: c++-library/range_tree_2d.cpp
layout: document
redirect_from:
- /library/c++-library/range_tree_2d.cpp
- /library/c++-library/range_tree_2d.cpp.html
title: c++-library/range_tree_2d.cpp
---
