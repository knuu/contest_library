---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: An implementation of range tree
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C)
  bundledCode: "#line 1 \"c++-library/range_tree_inner.cpp\"\n/**\n * @file range_tree.cpp\n\
    \ * @brief An implementation of range tree\n * @author knuu\n * @date 2018/09/16\n\
    \ *\n */\n\n#include <algorithm>\n#include <array>\n#include <cassert>\n#include\
    \ <cstddef>\n#include <iostream>\n#include <limits>\n#include <numeric>\n#include\
    \ <vector>\n\n/**\n * @brief type for input data\n */\ntemplate <typename T>\n\
    struct Data {\n  using type = T;\n  type data;\n\n  /**\n   * Constructor for\
    \ Data\n   * @param data Data should be std::array\n   */\n  Data(type &data)\
    \ : data(data) {}\n\n  /**\n   * Comparing function for data.\n   * This function\
    \ compares two data in lexicographical order.\n   *\n   * @param data1 First data\
    \ for comparing\n   * @param data2 Second data for comparing\n   * @param base\
    \ Start dimension for comparing.\n   *\n   * @return If data1 < data1 in lexicographical\
    \ order, then true, otherwise\n   * false.\n   */\n  static bool compare(const\
    \ Data<type> &data1, const Data<type> &data2,\n                      size_t base\
    \ = 1) {\n    const size_t dim = data1.data.size();\n    for (size_t i = 0; i\
    \ < dim; i++) {\n      if (data1.data[(i + base) % dim] != data2.data[(i + base)\
    \ % dim]) {\n        return data1.data[(i + base) % dim] < data2.data[(i + base)\
    \ % dim];\n      }\n    }\n    return false;\n  }\n  /**\n   * == operator for\
    \ data\n   */\n  bool operator==(const Data<type> &data) const {\n    return this->data\
    \ == data.data;\n  }\n};\n\n/**\n * Orthogonal Region for range tree\n */\ntemplate\
    \ <typename T>\nstruct Region {\n  T low, high;\n  /**\n   * Constructor for struct\
    \ Region\n   * If d = low.size(), then corresponding orthogonal region R is following.\n\
    \   * R = [low[0], high[0]] * [low[1], high[1]] * ... * [low[d-1], high[d-1]]\n\
    \   *\n   * @param low lower borders of orthogonal region\n   * @param high higher\
    \ borders of orthogonal region\n   */\n  Region(T &low, T &high) : low(low), high(high){};\n\
    \n  /**\n   * Checking Function of Inclusion for Data and Region.\n   *\n   *\
    \ @param data A data\n   * @return If this region include the data, then return\
    \ true, otherwise return\n   * false.\n   */\n  bool include(T data) const {\n\
    \    size_t dim = this->low.size();\n    for (size_t i = 0; i < dim; i++) {\n\
    \      if (data[i] < low[i] or high[i] < data[i]) {\n        return false;\n \
    \     }\n    }\n    return true;\n  }\n\n  /**\n   * Checking Function of Inclusion\
    \ for Two Regions.\n   *\n   * @param region A region.\n   * @return If this region\
    \ include the given region, then return true,\n   * otherwise return false.\n\
    \   */\n  bool include(const Region<T> &region) const {\n    size_t dim = this->low.size();\n\
    \    for (size_t bit = 0; bit < (1U << dim); bit++) {\n      T data;\n      for\
    \ (size_t i = 0; i < dim; i++) {\n        if (bit >> i & 1) {\n          data[i]\
    \ = region.low[i];\n        } else {\n          data[i] = region.high[i];\n  \
    \      }\n      }\n      if (not this->include(data)) {\n        return false;\n\
    \      }\n    }\n    return true;\n  }\n\n  /**\n   * Cheking Function of Overlapping\
    \ for Two Regions.\n   *\n   * @param region A region.\n   * @return If this region\
    \ overlaps the given region, then return true,\n   * otherwise return false.\n\
    \   */\n  bool overlap(Region<T> &region) const {\n    size_t dim = this->low.size();\n\
    \    for (size_t bit = 0; bit < (1U << dim); bit++) {\n      T data;\n      for\
    \ (size_t i = 0; i < dim; i++) {\n        if (bit >> i & 1) {\n          data[i]\
    \ = region.low[i];\n        } else {\n          data[i] = region.high[i];\n  \
    \      }\n      }\n      if (this->include(data)) {\n        return true;\n  \
    \    }\n    }\n    return false;\n  }\n\n  /**\n   * overloading of << operator\n\
    \   */\n  friend std::ostream &operator<<(std::ostream &os, const Region<T> &region)\
    \ {\n    for (size_t i = 0; i < region.low.size(); i++) {\n      if (i > 0) {\n\
    \        os << 'x';\n      }\n      os << '[' << region.low[i] << ',' << region.high[i]\
    \ << ']';\n    }\n    return os;\n  }\n};\n\nstruct RangeTreeNode {\n  size_t\
    \ idx;                  /**< Node index */\n  RangeTreeNode *assoc;        /**<\
    \ Pointer of associated structure */\n  RangeTreeNode *left, *right; /**< Pointer\
    \ of left & right node */\n  RangeTreeNode(size_t idx)\n      : idx(idx), assoc(nullptr),\
    \ left(nullptr), right(nullptr) {}\n  bool is_leaf_node() const { return left\
    \ == nullptr and right == nullptr; }\n};\n\ntemplate <typename DataType>\nstruct\
    \ RangeTree {\n  using T = typename DataType::type;\n  using VT = typename T::value_type;\n\
    \  size_t dim;                 /**< Dimension of Data */\n  std::vector<DataType>\
    \ data; /**< Data in range tree */\n  VT min_range, max_range;    /**< Initial\
    \ Range for range enumerate */\n  RangeTreeNode *root;        /**< Root Node */\n\
    \n  RangeTree(size_t dim = 2, VT min_range = std::numeric_limits<VT>::min(),\n\
    \            VT max_range = std::numeric_limits<VT>::max())\n      : dim(dim),\
    \ min_range(min_range), max_range(max_range) {}\n\n  RangeTreeNode *build_1d(std::vector<size_t>\
    \ &data, size_t low, size_t high) {\n    if (low + 1 == high) {\n      return\
    \ new RangeTreeNode(data[low]);\n    }\n    size_t median = (low + high) / 2;\n\
    \    RangeTreeNode *node = new RangeTreeNode(data[median]);\n    if (low < median)\
    \ node->left = build_1d(data, low, median);\n    if (median + 1 < high) node->right\
    \ = build_1d(data, median + 1, high);\n    return node;\n  }\n\n  RangeTreeNode\
    \ *build(std::vector<std::vector<size_t>> &data, size_t depth) {\n    RangeTreeNode\
    \ *assoc;\n    if (depth + 2 == this->dim) {\n      assoc = build_1d(data[depth\
    \ + 1], 0, data[0].size());\n    } else {\n      assoc = build(data, depth + 1);\n\
    \    }\n\n    if (data[0].size() == 1) {\n      RangeTreeNode *node = new RangeTreeNode(data[0][0]);\n\
    \      node->assoc = new RangeTreeNode(data[0][0]);\n      return node;\n    }\n\
    \    std::vector<std::vector<size_t>> left_data(this->dim),\n        right_data(this->dim);\n\
    \    size_t median_idx =\n        static_cast<size_t>(static_cast<int>(data[0].size())\
    \ / 2);\n    size_t median = data[depth % this->dim][median_idx];\n    for (size_t\
    \ i = 0; i < this->dim; i++) {\n      for (size_t j : data[i]) {\n        if (DataType::compare(this->data[j],\
    \ this->data[median],\n                              depth % this->dim)) {\n \
    \         left_data[i].emplace_back(j);\n        } else if (not(this->data[j]\
    \ == this->data[median])) {\n          right_data[i].emplace_back(j);\n      \
    \  }\n      }\n    }\n    RangeTreeNode *node = new RangeTreeNode(median);\n \
    \   if (left_data[0].size()) node->left = build(left_data, depth);\n    if (right_data[0].size())\
    \ node->right = build(right_data, depth);\n    node->assoc = assoc;\n    return\
    \ node;\n  }\n\n  void build(std::vector<DataType> &data) {\n    assert(data.size()\
    \ > 0);\n    std::vector<std::vector<size_t>> _data(this->dim,\n             \
    \                              std::vector<size_t>(data.size()));\n    this->data\
    \ = std::move(data);\n    for (size_t i = 0; i < this->dim; i++) {\n      std::iota(_data[i].begin(),\
    \ _data[i].end(), 0);\n      sort(_data[i].begin(), _data[i].end(),\n        \
    \   [&](const size_t &a, const size_t &b) {\n             return DataType::compare(this->data[a],\
    \ this->data[b], i);\n           });\n    }\n    this->root = build(_data, 0);\n\
    \  }\n\n  void output(bool assoc = true) const { output(this->root, assoc); }\n\
    \n  void output(RangeTreeNode *node, bool assoc = true) const {\n    if (node\
    \ == nullptr) return;\n    std::cout << \"idx: \" << node->idx << \", (\";\n \
    \   for (size_t i = 0; i < this->dim; i++) {\n      if (i > 0) {\n        std::cout\
    \ << ',';\n      }\n      std::cout << this->data[node->idx].data[i];\n    }\n\
    \    std::cout << \") \";\n    if (not node->is_leaf_node()) {\n      std::cout\
    \ << \"(left, right) = (\"\n                << (node->left == nullptr ? -1 : (int)node->left->idx)\
    \ << ','\n                << (node->right == nullptr ? -1 : (int)node->right->idx)\
    \ << ')'\n                << std::endl;\n      if (node->assoc != nullptr and\
    \ assoc) {\n        std::cout << \"assoc start\" << std::endl;\n        output(node->assoc,\
    \ assoc);\n        std::cout << \"assoc end\" << std::endl;\n      }\n      output(node->left,\
    \ assoc);\n      output(node->right, assoc);\n\n    } else {\n      std::cout\
    \ << std::endl;\n    }\n  }\n\n  /**\n   * @brief find the shallowest node n s.t.\
    \ low <= n < high\n   */\n  RangeTreeNode *find_split_node(RangeTreeNode *node,\
    \ size_t dim, DataType &low,\n                                 DataType &high)\
    \ const {\n    while (node != nullptr and\n           (DataType::compare(this->data[node->idx],\
    \ low, dim) or\n            not DataType::compare(this->data[node->idx], high,\
    \ dim))) {\n      if (DataType::compare(this->data[node->idx], low, dim)) {\n\
    \        node = node->right;\n      } else {\n        node = node->left;\n   \
    \   }\n    }\n    return node;\n  }\n\n  void report_subtree(RangeTreeNode *node,\
    \ std::vector<size_t> &output) const {\n    if (node == nullptr) return;\n   \
    \ output.emplace_back(node->idx);\n    report_subtree(node->left, output);\n \
    \   report_subtree(node->right, output);\n  }\n\n  void enumerate(Region<T> &query_region,\
    \ std::vector<size_t> &output) const {\n    enumerate(this->root, query_region,\
    \ 0, output);\n  }\n\n  // enumerate all points in query_region\n  void enumerate(RangeTreeNode\
    \ *node, Region<T> &query_region, size_t dim,\n                 std::vector<size_t>\
    \ &output) const {\n    if (node == nullptr) return;\n\n    T low_, high_;\n \
    \   low_.fill(this->min_range), high_.fill(this->max_range);\n    low_[dim] =\
    \ query_region.low[dim], high_[dim] = query_region.high[dim];\n    DataType low(low_),\
    \ high(high_);\n\n    RangeTreeNode *split_node = this->find_split_node(node,\
    \ dim, low, high);\n\n    if (split_node == nullptr) {\n      return;\n    }\n\
    \n    if (query_region.include(this->data[split_node->idx].data)) {\n      output.emplace_back(split_node->idx);\n\
    \    }\n\n    // search left side of tree\n    node = split_node->left;\n    while\
    \ (node != nullptr) {\n      if (query_region.include(this->data[node->idx].data))\
    \ {\n        output.emplace_back(node->idx);\n      }\n\n      if (DataType::compare(this->data[node->idx],\
    \ low, dim)) {\n        node = node->right;\n      } else {\n        if (dim +\
    \ 1 == this->dim) {\n          report_subtree(node->right, output);\n        }\
    \ else if (node->right != nullptr) {\n          enumerate(node->right->assoc,\
    \ query_region, dim + 1, output);\n        }\n        node = node->left;\n   \
    \   }\n    }\n\n    // search right side of tree\n    node = split_node->right;\n\
    \    while (node != nullptr) {\n      if (query_region.include(this->data[node->idx].data))\
    \ {\n        output.emplace_back(node->idx);\n      }\n      if (DataType::compare(this->data[node->idx],\
    \ high, dim)) {\n        if (dim + 1 == this->dim) {\n          report_subtree(node->left,\
    \ output);\n        } else if (node->left != nullptr) {\n          enumerate(node->left->assoc,\
    \ query_region, dim + 1, output);\n        }\n        node = node->right;\n  \
    \    } else {\n        node = node->left;\n      }\n    }\n  }\n};\n\n/*\n * Example\
    \ of Usage (AOJ DSL_2_C)\n * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C)\n\
    \ */\nint main() {\n  using DataType = Data<std::array<int, 2>>;\n  RangeTree<DataType>\
    \ range_tree;\n  std::vector<DataType> points;\n  int N;\n  scanf(\"%d\", &N);\n\
    \  for (size_t i = 0; (int)i < N; i++) {\n    int x, y;\n    scanf(\"%d %d\",\
    \ &x, &y);\n    DataType::type tmp = {x, y};\n    points.emplace_back(DataType(tmp));\n\
    \  }\n  range_tree.build(points);\n  // range_tree.output(true);\n\n  ///*\n \
    \ int Q;\n  scanf(\"%d\", &Q);\n  for (size_t i = 0; (int)i < Q; i++) {\n    int\
    \ sx, tx, sy, ty;\n    scanf(\"%d %d %d %d\", &sx, &tx, &sy, &ty);\n    DataType::type\
    \ low = {sx, sy}, high = {tx, ty};\n    Region<DataType::type> query_region(low,\
    \ high);\n    std::vector<size_t> out;\n    range_tree.enumerate(query_region,\
    \ out);\n    std::sort(out.begin(), out.end());\n    for (size_t i : out) printf(\"\
    %lu\\n\", i);\n    printf(\"\\n\");\n  }\n  //*/\n  return 0;\n}\n"
  code: "/**\n * @file range_tree.cpp\n * @brief An implementation of range tree\n\
    \ * @author knuu\n * @date 2018/09/16\n *\n */\n\n#include <algorithm>\n#include\
    \ <array>\n#include <cassert>\n#include <cstddef>\n#include <iostream>\n#include\
    \ <limits>\n#include <numeric>\n#include <vector>\n\n/**\n * @brief type for input\
    \ data\n */\ntemplate <typename T>\nstruct Data {\n  using type = T;\n  type data;\n\
    \n  /**\n   * Constructor for Data\n   * @param data Data should be std::array\n\
    \   */\n  Data(type &data) : data(data) {}\n\n  /**\n   * Comparing function for\
    \ data.\n   * This function compares two data in lexicographical order.\n   *\n\
    \   * @param data1 First data for comparing\n   * @param data2 Second data for\
    \ comparing\n   * @param base Start dimension for comparing.\n   *\n   * @return\
    \ If data1 < data1 in lexicographical order, then true, otherwise\n   * false.\n\
    \   */\n  static bool compare(const Data<type> &data1, const Data<type> &data2,\n\
    \                      size_t base = 1) {\n    const size_t dim = data1.data.size();\n\
    \    for (size_t i = 0; i < dim; i++) {\n      if (data1.data[(i + base) % dim]\
    \ != data2.data[(i + base) % dim]) {\n        return data1.data[(i + base) % dim]\
    \ < data2.data[(i + base) % dim];\n      }\n    }\n    return false;\n  }\n  /**\n\
    \   * == operator for data\n   */\n  bool operator==(const Data<type> &data) const\
    \ {\n    return this->data == data.data;\n  }\n};\n\n/**\n * Orthogonal Region\
    \ for range tree\n */\ntemplate <typename T>\nstruct Region {\n  T low, high;\n\
    \  /**\n   * Constructor for struct Region\n   * If d = low.size(), then corresponding\
    \ orthogonal region R is following.\n   * R = [low[0], high[0]] * [low[1], high[1]]\
    \ * ... * [low[d-1], high[d-1]]\n   *\n   * @param low lower borders of orthogonal\
    \ region\n   * @param high higher borders of orthogonal region\n   */\n  Region(T\
    \ &low, T &high) : low(low), high(high){};\n\n  /**\n   * Checking Function of\
    \ Inclusion for Data and Region.\n   *\n   * @param data A data\n   * @return\
    \ If this region include the data, then return true, otherwise return\n   * false.\n\
    \   */\n  bool include(T data) const {\n    size_t dim = this->low.size();\n \
    \   for (size_t i = 0; i < dim; i++) {\n      if (data[i] < low[i] or high[i]\
    \ < data[i]) {\n        return false;\n      }\n    }\n    return true;\n  }\n\
    \n  /**\n   * Checking Function of Inclusion for Two Regions.\n   *\n   * @param\
    \ region A region.\n   * @return If this region include the given region, then\
    \ return true,\n   * otherwise return false.\n   */\n  bool include(const Region<T>\
    \ &region) const {\n    size_t dim = this->low.size();\n    for (size_t bit =\
    \ 0; bit < (1U << dim); bit++) {\n      T data;\n      for (size_t i = 0; i <\
    \ dim; i++) {\n        if (bit >> i & 1) {\n          data[i] = region.low[i];\n\
    \        } else {\n          data[i] = region.high[i];\n        }\n      }\n \
    \     if (not this->include(data)) {\n        return false;\n      }\n    }\n\
    \    return true;\n  }\n\n  /**\n   * Cheking Function of Overlapping for Two\
    \ Regions.\n   *\n   * @param region A region.\n   * @return If this region overlaps\
    \ the given region, then return true,\n   * otherwise return false.\n   */\n \
    \ bool overlap(Region<T> &region) const {\n    size_t dim = this->low.size();\n\
    \    for (size_t bit = 0; bit < (1U << dim); bit++) {\n      T data;\n      for\
    \ (size_t i = 0; i < dim; i++) {\n        if (bit >> i & 1) {\n          data[i]\
    \ = region.low[i];\n        } else {\n          data[i] = region.high[i];\n  \
    \      }\n      }\n      if (this->include(data)) {\n        return true;\n  \
    \    }\n    }\n    return false;\n  }\n\n  /**\n   * overloading of << operator\n\
    \   */\n  friend std::ostream &operator<<(std::ostream &os, const Region<T> &region)\
    \ {\n    for (size_t i = 0; i < region.low.size(); i++) {\n      if (i > 0) {\n\
    \        os << 'x';\n      }\n      os << '[' << region.low[i] << ',' << region.high[i]\
    \ << ']';\n    }\n    return os;\n  }\n};\n\nstruct RangeTreeNode {\n  size_t\
    \ idx;                  /**< Node index */\n  RangeTreeNode *assoc;        /**<\
    \ Pointer of associated structure */\n  RangeTreeNode *left, *right; /**< Pointer\
    \ of left & right node */\n  RangeTreeNode(size_t idx)\n      : idx(idx), assoc(nullptr),\
    \ left(nullptr), right(nullptr) {}\n  bool is_leaf_node() const { return left\
    \ == nullptr and right == nullptr; }\n};\n\ntemplate <typename DataType>\nstruct\
    \ RangeTree {\n  using T = typename DataType::type;\n  using VT = typename T::value_type;\n\
    \  size_t dim;                 /**< Dimension of Data */\n  std::vector<DataType>\
    \ data; /**< Data in range tree */\n  VT min_range, max_range;    /**< Initial\
    \ Range for range enumerate */\n  RangeTreeNode *root;        /**< Root Node */\n\
    \n  RangeTree(size_t dim = 2, VT min_range = std::numeric_limits<VT>::min(),\n\
    \            VT max_range = std::numeric_limits<VT>::max())\n      : dim(dim),\
    \ min_range(min_range), max_range(max_range) {}\n\n  RangeTreeNode *build_1d(std::vector<size_t>\
    \ &data, size_t low, size_t high) {\n    if (low + 1 == high) {\n      return\
    \ new RangeTreeNode(data[low]);\n    }\n    size_t median = (low + high) / 2;\n\
    \    RangeTreeNode *node = new RangeTreeNode(data[median]);\n    if (low < median)\
    \ node->left = build_1d(data, low, median);\n    if (median + 1 < high) node->right\
    \ = build_1d(data, median + 1, high);\n    return node;\n  }\n\n  RangeTreeNode\
    \ *build(std::vector<std::vector<size_t>> &data, size_t depth) {\n    RangeTreeNode\
    \ *assoc;\n    if (depth + 2 == this->dim) {\n      assoc = build_1d(data[depth\
    \ + 1], 0, data[0].size());\n    } else {\n      assoc = build(data, depth + 1);\n\
    \    }\n\n    if (data[0].size() == 1) {\n      RangeTreeNode *node = new RangeTreeNode(data[0][0]);\n\
    \      node->assoc = new RangeTreeNode(data[0][0]);\n      return node;\n    }\n\
    \    std::vector<std::vector<size_t>> left_data(this->dim),\n        right_data(this->dim);\n\
    \    size_t median_idx =\n        static_cast<size_t>(static_cast<int>(data[0].size())\
    \ / 2);\n    size_t median = data[depth % this->dim][median_idx];\n    for (size_t\
    \ i = 0; i < this->dim; i++) {\n      for (size_t j : data[i]) {\n        if (DataType::compare(this->data[j],\
    \ this->data[median],\n                              depth % this->dim)) {\n \
    \         left_data[i].emplace_back(j);\n        } else if (not(this->data[j]\
    \ == this->data[median])) {\n          right_data[i].emplace_back(j);\n      \
    \  }\n      }\n    }\n    RangeTreeNode *node = new RangeTreeNode(median);\n \
    \   if (left_data[0].size()) node->left = build(left_data, depth);\n    if (right_data[0].size())\
    \ node->right = build(right_data, depth);\n    node->assoc = assoc;\n    return\
    \ node;\n  }\n\n  void build(std::vector<DataType> &data) {\n    assert(data.size()\
    \ > 0);\n    std::vector<std::vector<size_t>> _data(this->dim,\n             \
    \                              std::vector<size_t>(data.size()));\n    this->data\
    \ = std::move(data);\n    for (size_t i = 0; i < this->dim; i++) {\n      std::iota(_data[i].begin(),\
    \ _data[i].end(), 0);\n      sort(_data[i].begin(), _data[i].end(),\n        \
    \   [&](const size_t &a, const size_t &b) {\n             return DataType::compare(this->data[a],\
    \ this->data[b], i);\n           });\n    }\n    this->root = build(_data, 0);\n\
    \  }\n\n  void output(bool assoc = true) const { output(this->root, assoc); }\n\
    \n  void output(RangeTreeNode *node, bool assoc = true) const {\n    if (node\
    \ == nullptr) return;\n    std::cout << \"idx: \" << node->idx << \", (\";\n \
    \   for (size_t i = 0; i < this->dim; i++) {\n      if (i > 0) {\n        std::cout\
    \ << ',';\n      }\n      std::cout << this->data[node->idx].data[i];\n    }\n\
    \    std::cout << \") \";\n    if (not node->is_leaf_node()) {\n      std::cout\
    \ << \"(left, right) = (\"\n                << (node->left == nullptr ? -1 : (int)node->left->idx)\
    \ << ','\n                << (node->right == nullptr ? -1 : (int)node->right->idx)\
    \ << ')'\n                << std::endl;\n      if (node->assoc != nullptr and\
    \ assoc) {\n        std::cout << \"assoc start\" << std::endl;\n        output(node->assoc,\
    \ assoc);\n        std::cout << \"assoc end\" << std::endl;\n      }\n      output(node->left,\
    \ assoc);\n      output(node->right, assoc);\n\n    } else {\n      std::cout\
    \ << std::endl;\n    }\n  }\n\n  /**\n   * @brief find the shallowest node n s.t.\
    \ low <= n < high\n   */\n  RangeTreeNode *find_split_node(RangeTreeNode *node,\
    \ size_t dim, DataType &low,\n                                 DataType &high)\
    \ const {\n    while (node != nullptr and\n           (DataType::compare(this->data[node->idx],\
    \ low, dim) or\n            not DataType::compare(this->data[node->idx], high,\
    \ dim))) {\n      if (DataType::compare(this->data[node->idx], low, dim)) {\n\
    \        node = node->right;\n      } else {\n        node = node->left;\n   \
    \   }\n    }\n    return node;\n  }\n\n  void report_subtree(RangeTreeNode *node,\
    \ std::vector<size_t> &output) const {\n    if (node == nullptr) return;\n   \
    \ output.emplace_back(node->idx);\n    report_subtree(node->left, output);\n \
    \   report_subtree(node->right, output);\n  }\n\n  void enumerate(Region<T> &query_region,\
    \ std::vector<size_t> &output) const {\n    enumerate(this->root, query_region,\
    \ 0, output);\n  }\n\n  // enumerate all points in query_region\n  void enumerate(RangeTreeNode\
    \ *node, Region<T> &query_region, size_t dim,\n                 std::vector<size_t>\
    \ &output) const {\n    if (node == nullptr) return;\n\n    T low_, high_;\n \
    \   low_.fill(this->min_range), high_.fill(this->max_range);\n    low_[dim] =\
    \ query_region.low[dim], high_[dim] = query_region.high[dim];\n    DataType low(low_),\
    \ high(high_);\n\n    RangeTreeNode *split_node = this->find_split_node(node,\
    \ dim, low, high);\n\n    if (split_node == nullptr) {\n      return;\n    }\n\
    \n    if (query_region.include(this->data[split_node->idx].data)) {\n      output.emplace_back(split_node->idx);\n\
    \    }\n\n    // search left side of tree\n    node = split_node->left;\n    while\
    \ (node != nullptr) {\n      if (query_region.include(this->data[node->idx].data))\
    \ {\n        output.emplace_back(node->idx);\n      }\n\n      if (DataType::compare(this->data[node->idx],\
    \ low, dim)) {\n        node = node->right;\n      } else {\n        if (dim +\
    \ 1 == this->dim) {\n          report_subtree(node->right, output);\n        }\
    \ else if (node->right != nullptr) {\n          enumerate(node->right->assoc,\
    \ query_region, dim + 1, output);\n        }\n        node = node->left;\n   \
    \   }\n    }\n\n    // search right side of tree\n    node = split_node->right;\n\
    \    while (node != nullptr) {\n      if (query_region.include(this->data[node->idx].data))\
    \ {\n        output.emplace_back(node->idx);\n      }\n      if (DataType::compare(this->data[node->idx],\
    \ high, dim)) {\n        if (dim + 1 == this->dim) {\n          report_subtree(node->left,\
    \ output);\n        } else if (node->left != nullptr) {\n          enumerate(node->left->assoc,\
    \ query_region, dim + 1, output);\n        }\n        node = node->right;\n  \
    \    } else {\n        node = node->left;\n      }\n    }\n  }\n};\n\n/*\n * Example\
    \ of Usage (AOJ DSL_2_C)\n * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C)\n\
    \ */\nint main() {\n  using DataType = Data<std::array<int, 2>>;\n  RangeTree<DataType>\
    \ range_tree;\n  std::vector<DataType> points;\n  int N;\n  scanf(\"%d\", &N);\n\
    \  for (size_t i = 0; (int)i < N; i++) {\n    int x, y;\n    scanf(\"%d %d\",\
    \ &x, &y);\n    DataType::type tmp = {x, y};\n    points.emplace_back(DataType(tmp));\n\
    \  }\n  range_tree.build(points);\n  // range_tree.output(true);\n\n  ///*\n \
    \ int Q;\n  scanf(\"%d\", &Q);\n  for (size_t i = 0; (int)i < Q; i++) {\n    int\
    \ sx, tx, sy, ty;\n    scanf(\"%d %d %d %d\", &sx, &tx, &sy, &ty);\n    DataType::type\
    \ low = {sx, sy}, high = {tx, ty};\n    Region<DataType::type> query_region(low,\
    \ high);\n    std::vector<size_t> out;\n    range_tree.enumerate(query_region,\
    \ out);\n    std::sort(out.begin(), out.end());\n    for (size_t i : out) printf(\"\
    %lu\\n\", i);\n    printf(\"\\n\");\n  }\n  //*/\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: c++-library/range_tree_inner.cpp
  requiredBy: []
  timestamp: '2019-04-11 03:52:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: c++-library/range_tree_inner.cpp
layout: document
redirect_from:
- /library/c++-library/range_tree_inner.cpp
- /library/c++-library/range_tree_inner.cpp.html
title: An implementation of range tree
---
