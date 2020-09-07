---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: An implementation of kd-tree
  bundledCode: "#line 1 \"c++-library/kd_tree.cpp\"\n/**\n * @file kd_tree.cpp\n *\
    \ @brief An implementation of kd-tree\n * @author knuu\n * @date 2018/09/16\n\
    \ *\n * Usage:\n * 1. Define struct Data for Input data, comparing function, and\
    \ == operator.\n * 2. Construct KD-tree.build(Array of Data)\n * 3. Use KDTree.range_query(Array\
    \ of Region).\n */\n\n#include <algorithm>\n#include <array>\n#include <cassert>\n\
    #include <cstddef>\n#include <iostream>\n#include <limits>\n#include <numeric>\n\
    #include <vector>\n\n/**\n * @brief type for input data of kd-tree\n */\ntemplate\
    \ <typename T>\nstruct Data {\n  using type = T;\n  type data;\n\n  /**\n   *\
    \ Constructor for Data\n   * @param data Data should be std::array or std::vector.\n\
    \   */\n  Data(type data) : data(data) {}\n\n  /**\n   * Comparing function for\
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
    \ {\n    return this->data == data.data;\n  }\n  const T &operator[](const size_t\
    \ i) const {\n    return *(this->data.begin() + i);\n  }\n  T &operator[](const\
    \ size_t i) { return *(this->data.begin() + i); }\n};\n\n/**\n * Orthogonal Region\
    \ for kd-tree\n */\ntemplate <typename T>\nstruct Region {\n  T low, high;\n \
    \ /**\n   * Constructor for struct Region\n   * If d = low.size(), then corresponding\
    \ orthogonal region R is following.\n   * R = [low[0], high[0]] * [low[1], high[1]]\
    \ * ... * [low[d-1], high[d-1]]\n   *\n   * @param low lower borders of orthogonal\
    \ region\n   * @param high higher borders of orthogonal region\n   */\n  Region(T\
    \ low, T high) : low(low), high(high){};\n\n  /**\n   * Checking Function of Inclusion\
    \ for Data and Region.\n   *\n   * @param data A data\n   * @return If this region\
    \ include the data, then return true, otherwise return\n   * false.\n   */\n \
    \ bool include(T data) const {\n    size_t dim = this->low.size();\n    for (size_t\
    \ i = 0; i < dim; i++) {\n      if (data[i] < low[i] or high[i] < data[i]) {\n\
    \        return false;\n      }\n    }\n    return true;\n  }\n\n  /**\n   * Checking\
    \ Function of Inclusion for Two Regions.\n   *\n   * @param region A region.\n\
    \   * @return If this region include the given region, then return true,\n   *\
    \ otherwise return false.\n   */\n  bool include(Region<T> region) const {\n \
    \   size_t dim = this->low.size();\n    for (size_t bit = 0; bit < (1U << dim);\
    \ bit++) {\n      T data;\n      for (size_t i = 0; i < dim; i++) {\n        if\
    \ (bit >> i & 1) {\n          data[i] = region.low[i];\n        } else {\n   \
    \       data[i] = region.high[i];\n        }\n      }\n      if (not this->include(data))\
    \ {\n        return false;\n      }\n    }\n    return true;\n  }\n\n  /**\n \
    \  * Cheking Function of Overlapping for Two Regions.\n   *\n   * @param region\
    \ A region.\n   * @return If this region overlaps the given region, then return\
    \ true,\n   * otherwise return false.\n   */\n  bool overlap(Region<T> region)\
    \ const {\n    size_t dim = this->low.size();\n    for (size_t bit = 0; bit <\
    \ (1U << dim); bit++) {\n      T data;\n      for (size_t i = 0; i < dim; i++)\
    \ {\n        if (bit >> i & 1) {\n          data[i] = region.low[i];\n       \
    \ } else {\n          data[i] = region.high[i];\n        }\n      }\n      if\
    \ (this->include(data)) {\n        return true;\n      }\n    }\n    return false;\n\
    \  }\n\n  /**\n   * overloading of << operator\n   */\n  friend std::ostream &operator<<(std::ostream\
    \ &os, const Region<T> &region) {\n    for (size_t i = 0; i < region.low.size();\
    \ i++) {\n      if (i > 0) {\n        os << 'x';\n      }\n      os << '[' <<\
    \ region.low[i] << ',' << region.high[i] << ']';\n    }\n    return os;\n  }\n\
    };\n\n/**\n * Node for kd-tree\n */\nstruct KDTreeNode {\n  /// The axis for splitting\n\
    \  size_t axis;\n  /// The index of data for splitting\n  size_t idx;\n  /// Children\
    \ of the node\n  KDTreeNode *left, *right;\n\n  KDTreeNode(size_t axis, size_t\
    \ idx)\n      : axis(axis), idx(idx), left(nullptr), right(nullptr) {}\n  bool\
    \ is_leaf_node() const {\n    return this->left == nullptr and this->right ==\
    \ nullptr;\n  }\n};\n\n/**\n * class KDTree\n */\ntemplate <typename DataType>\n\
    struct KDTree {\n  using T = typename DataType::type;\n  using VT = typename T::value_type;\n\
    \  size_t dim;                 /**< Dimension of Data */\n  std::vector<DataType>\
    \ data; /**< Data in kd-tree */\n  VT min_range, max_range;    /**< Initial Range\
    \ for range query */\n  KDTreeNode *root;           /**< Root Node of kd-tree\
    \ */\n\n  /**\n   * Constructor for kd-tree\n   *\n   * @param dim Dimension of\
    \ each data\n   * @param min_range Minimun value of query range\n   * @param max_range\
    \ Maximun value of query range\n   */\n  KDTree(size_t dim = 2, VT min_range =\
    \ std::numeric_limits<VT>::min(),\n         VT max_range = std::numeric_limits<VT>::max())\n\
    \      : dim(dim), min_range(min_range), max_range(max_range) {}\n\n  /**\n  \
    \ * Recursive Builder of kd-tree\n   *\n   * @param data Array of data\n   * @param\
    \ depth Depth for data dividing\n   *\n   * @return Pointer for kd-tree node\n\
    \   */\n  KDTreeNode *build(std::vector<std::vector<size_t>> &data, size_t depth)\
    \ {\n    if (data[0].size() == 1) {\n      return new KDTreeNode(this->dim, data[0][0]);\n\
    \    } else {\n      std::vector<std::vector<size_t>> left_data(this->dim),\n\
    \          right_data(this->dim);\n      size_t median_idx =\n          static_cast<size_t>(static_cast<int>(data[0].size()\
    \ - 1) / 2);\n      size_t median = data[depth % this->dim][median_idx];\n   \
    \   for (size_t i = 0; i < this->dim; i++) {\n        for (size_t j : data[i])\
    \ {\n          if (this->data[j] == this->data[median] or\n              DataType::compare(this->data[j],\
    \ this->data[median],\n                                depth % this->dim)) {\n\
    \            left_data[i].emplace_back(j);\n          } else {\n            right_data[i].emplace_back(j);\n\
    \          }\n        }\n      }\n      assert(left_data[0].size() > 0 and right_data[0].size()\
    \ > 0);\n      KDTreeNode *node = new KDTreeNode(depth % this->dim, median);\n\
    \      node->left = build(left_data, depth + 1);\n      node->right = build(right_data,\
    \ depth + 1);\n      return node;\n    }\n  }\n\n  /**\n   * Builder for kd-tree\n\
    \   *\n   * @param data Array of input data\n   */\n  void build(std::vector<DataType>\
    \ &data) {\n    assert(data.size() > 0);\n\n    this->data = data;\n\n    std::vector<std::vector<size_t>>\
    \ _data(this->dim,\n                                           std::vector<size_t>(data.size()));\n\
    \    for (size_t i = 0; i < this->dim; i++) {\n      std::iota(_data[i].begin(),\
    \ _data[i].end(), 0);\n      sort(_data[i].begin(), _data[i].end(),\n        \
    \   [&](const size_t &a, const size_t &b) {\n             return DataType::compare(this->data[a],\
    \ this->data[b], i);\n           });\n    }\n    this->root = build(_data, 0);\n\
    \  }\n\n  /**\n   * Reporting Function for kd-tree\n   * This function report\
    \ all leafs of subtree whose root is given node.\n   *\n   * @param node root\
    \ of subtree for reporting\n   * @param output array of reported data\n   */\n\
    \  void report_subtree(KDTreeNode *node, std::vector<size_t> &output) const {\n\
    \    if (node->is_leaf_node()) {\n      output.emplace_back(node->idx);\n    }\
    \ else {\n      report_subtree(node->left, output);\n      report_subtree(node->right,\
    \ output);\n    }\n  }\n\n  /**\n   * Range Query for kd-tree\n   *\n   * @param\
    \ query_region Given query\n   *\n   * @return Reported indices\n   */\n  void\
    \ query(Region<T> query_region, std::vector<size_t> &output) const {\n    T node_low,\
    \ node_high;\n    node_low.fill(this->min_range);\n    node_high.fill(this->max_range);\n\
    \    Region<T> node_region(node_low, node_high);\n    query(this->root, query_region,\
    \ node_region, output);\n  }\n\n  /**\n   *\n   * @param node\n   * @param query_region\n\
    \   * @param node_region\n   * @param output\n   */\n  void query(KDTreeNode *node,\
    \ Region<T> query_region, Region<T> node_region,\n             std::vector<size_t>\
    \ &output) const {\n    T data = this->data[node->idx].data;\n    if (node->is_leaf_node())\
    \ {\n      if (query_region.include(data)) {\n        output.emplace_back(node->idx);\n\
    \      }\n    } else {\n      Region<T> left_region = node_region, right_region\
    \ = node_region;\n      Region<T> left_query_region = query_region,\n        \
    \        right_query_region = query_region;\n\n      left_region.high[node->axis]\
    \ = data[node->axis];\n      right_region.low[node->axis] = data[node->axis];\n\
    \      if (query_region.low[node->axis] <= data[node->axis] and\n          data[node->axis]\
    \ < query_region.high[node->axis]) {\n        left_query_region.high[node->axis]\
    \ = data[node->axis];\n      }\n      if (data[node->axis] <= query_region.high[node->axis]\
    \ and\n          query_region.low[node->axis] < data[node->axis]) {\n        right_query_region.low[node->axis]\
    \ = data[node->axis];\n      }\n      if (left_query_region.include(left_region))\
    \ {\n        report_subtree(node->left, output);\n      } else if (left_region.overlap(left_query_region))\
    \ {\n        query(node->left, left_query_region, left_region, output);\n    \
    \  }\n\n      if (right_query_region.include(right_region)) {\n        report_subtree(node->right,\
    \ output);\n      } else if (right_region.overlap(right_query_region)) {\n   \
    \     query(node->right, right_query_region, right_region, output);\n      }\n\
    \    }\n  }\n\n  /**\n   *\n   */\n  void output() const { output_kdtree(this->root);\
    \ }\n\n  /**\n   *\n   *\n   * @param node\n   */\n  void output_kdtree(KDTreeNode\
    \ *node) const {\n    std::cout << \"idx: \" << node->idx << \", (\";\n    for\
    \ (size_t i = 0; i < this->dim; i++) {\n      if (i > 0) {\n        std::cout\
    \ << ',';\n      }\n      std::cout << this->data[node->idx][i];\n    }\n    std::cout\
    \ << \") \";\n    if (not node->is_leaf_node()) {\n      std::cout << \"(left,\
    \ right) = (\" << node->left->idx << ','\n                << node->right->idx\
    \ << ')' << std::endl;\n      output_kdtree(node->left);\n      output_kdtree(node->right);\n\
    \    } else {\n      std::cout << std::endl;\n    }\n  }\n};\n\n/*\n * Example\
    \ of Usage (AOJ DSL_2_C\n * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C)\n\
    \ */\n\nvoid aoj() {\n  using DataType = Data<std::array<int, 2>>;\n  KDTree<DataType>\
    \ kdtree;\n  std::vector<DataType> points;\n  int N;\n  scanf(\"%d\", &N);\n \
    \ for (size_t i = 0; (int)i < N; i++) {\n    int x, y;\n    scanf(\"%d %d\", &x,\
    \ &y);\n    DataType::type tmp = {x, y};\n    points.emplace_back(DataType(tmp));\n\
    \  }\n  kdtree.build(points);\n\n  int Q;\n  scanf(\"%d\", &Q);\n  for (size_t\
    \ i = 0; (int)i < Q; i++) {\n    int sx, tx, sy, ty;\n    scanf(\"%d %d %d %d\"\
    , &sx, &tx, &sy, &ty);\n    DataType::type low = {sx, sy}, high = {tx, ty};\n\
    \    Region<DataType::type> query_region(low, high);\n    std::vector<size_t>\
    \ out;\n    kdtree.query(query_region, out);\n    std::sort(out.begin(), out.end());\n\
    \    for (size_t i : out) printf(\"%lu\\n\", i);\n    printf(\"\\n\");\n  }\n\
    }\n\nint main() {\n  std::cin.tie(0);\n  std::ios_base::sync_with_stdio(false);\n\
    \  aoj();\n  return 0;\n}\n"
  code: "/**\n * @file kd_tree.cpp\n * @brief An implementation of kd-tree\n * @author\
    \ knuu\n * @date 2018/09/16\n *\n * Usage:\n * 1. Define struct Data for Input\
    \ data, comparing function, and == operator.\n * 2. Construct KD-tree.build(Array\
    \ of Data)\n * 3. Use KDTree.range_query(Array of Region).\n */\n\n#include <algorithm>\n\
    #include <array>\n#include <cassert>\n#include <cstddef>\n#include <iostream>\n\
    #include <limits>\n#include <numeric>\n#include <vector>\n\n/**\n * @brief type\
    \ for input data of kd-tree\n */\ntemplate <typename T>\nstruct Data {\n  using\
    \ type = T;\n  type data;\n\n  /**\n   * Constructor for Data\n   * @param data\
    \ Data should be std::array or std::vector.\n   */\n  Data(type data) : data(data)\
    \ {}\n\n  /**\n   * Comparing function for data.\n   * This function compares\
    \ two data in lexicographical order.\n   *\n   * @param data1 First data for comparing\n\
    \   * @param data2 Second data for comparing\n   * @param base Start dimension\
    \ for comparing.\n   *\n   * @return If data1 < data1 in lexicographical order,\
    \ then true, otherwise\n   * false.\n   */\n  static bool compare(const Data<type>\
    \ &data1, const Data<type> &data2,\n                      size_t base = 1) {\n\
    \    const size_t dim = data1.data.size();\n    for (size_t i = 0; i < dim; i++)\
    \ {\n      if (data1.data[(i + base) % dim] != data2.data[(i + base) % dim]) {\n\
    \        return data1.data[(i + base) % dim] < data2.data[(i + base) % dim];\n\
    \      }\n    }\n    return false;\n  }\n  /**\n   * == operator for data\n  \
    \ */\n  bool operator==(const Data<type> &data) const {\n    return this->data\
    \ == data.data;\n  }\n  const T &operator[](const size_t i) const {\n    return\
    \ *(this->data.begin() + i);\n  }\n  T &operator[](const size_t i) { return *(this->data.begin()\
    \ + i); }\n};\n\n/**\n * Orthogonal Region for kd-tree\n */\ntemplate <typename\
    \ T>\nstruct Region {\n  T low, high;\n  /**\n   * Constructor for struct Region\n\
    \   * If d = low.size(), then corresponding orthogonal region R is following.\n\
    \   * R = [low[0], high[0]] * [low[1], high[1]] * ... * [low[d-1], high[d-1]]\n\
    \   *\n   * @param low lower borders of orthogonal region\n   * @param high higher\
    \ borders of orthogonal region\n   */\n  Region(T low, T high) : low(low), high(high){};\n\
    \n  /**\n   * Checking Function of Inclusion for Data and Region.\n   *\n   *\
    \ @param data A data\n   * @return If this region include the data, then return\
    \ true, otherwise return\n   * false.\n   */\n  bool include(T data) const {\n\
    \    size_t dim = this->low.size();\n    for (size_t i = 0; i < dim; i++) {\n\
    \      if (data[i] < low[i] or high[i] < data[i]) {\n        return false;\n \
    \     }\n    }\n    return true;\n  }\n\n  /**\n   * Checking Function of Inclusion\
    \ for Two Regions.\n   *\n   * @param region A region.\n   * @return If this region\
    \ include the given region, then return true,\n   * otherwise return false.\n\
    \   */\n  bool include(Region<T> region) const {\n    size_t dim = this->low.size();\n\
    \    for (size_t bit = 0; bit < (1U << dim); bit++) {\n      T data;\n      for\
    \ (size_t i = 0; i < dim; i++) {\n        if (bit >> i & 1) {\n          data[i]\
    \ = region.low[i];\n        } else {\n          data[i] = region.high[i];\n  \
    \      }\n      }\n      if (not this->include(data)) {\n        return false;\n\
    \      }\n    }\n    return true;\n  }\n\n  /**\n   * Cheking Function of Overlapping\
    \ for Two Regions.\n   *\n   * @param region A region.\n   * @return If this region\
    \ overlaps the given region, then return true,\n   * otherwise return false.\n\
    \   */\n  bool overlap(Region<T> region) const {\n    size_t dim = this->low.size();\n\
    \    for (size_t bit = 0; bit < (1U << dim); bit++) {\n      T data;\n      for\
    \ (size_t i = 0; i < dim; i++) {\n        if (bit >> i & 1) {\n          data[i]\
    \ = region.low[i];\n        } else {\n          data[i] = region.high[i];\n  \
    \      }\n      }\n      if (this->include(data)) {\n        return true;\n  \
    \    }\n    }\n    return false;\n  }\n\n  /**\n   * overloading of << operator\n\
    \   */\n  friend std::ostream &operator<<(std::ostream &os, const Region<T> &region)\
    \ {\n    for (size_t i = 0; i < region.low.size(); i++) {\n      if (i > 0) {\n\
    \        os << 'x';\n      }\n      os << '[' << region.low[i] << ',' << region.high[i]\
    \ << ']';\n    }\n    return os;\n  }\n};\n\n/**\n * Node for kd-tree\n */\nstruct\
    \ KDTreeNode {\n  /// The axis for splitting\n  size_t axis;\n  /// The index\
    \ of data for splitting\n  size_t idx;\n  /// Children of the node\n  KDTreeNode\
    \ *left, *right;\n\n  KDTreeNode(size_t axis, size_t idx)\n      : axis(axis),\
    \ idx(idx), left(nullptr), right(nullptr) {}\n  bool is_leaf_node() const {\n\
    \    return this->left == nullptr and this->right == nullptr;\n  }\n};\n\n/**\n\
    \ * class KDTree\n */\ntemplate <typename DataType>\nstruct KDTree {\n  using\
    \ T = typename DataType::type;\n  using VT = typename T::value_type;\n  size_t\
    \ dim;                 /**< Dimension of Data */\n  std::vector<DataType> data;\
    \ /**< Data in kd-tree */\n  VT min_range, max_range;    /**< Initial Range for\
    \ range query */\n  KDTreeNode *root;           /**< Root Node of kd-tree */\n\
    \n  /**\n   * Constructor for kd-tree\n   *\n   * @param dim Dimension of each\
    \ data\n   * @param min_range Minimun value of query range\n   * @param max_range\
    \ Maximun value of query range\n   */\n  KDTree(size_t dim = 2, VT min_range =\
    \ std::numeric_limits<VT>::min(),\n         VT max_range = std::numeric_limits<VT>::max())\n\
    \      : dim(dim), min_range(min_range), max_range(max_range) {}\n\n  /**\n  \
    \ * Recursive Builder of kd-tree\n   *\n   * @param data Array of data\n   * @param\
    \ depth Depth for data dividing\n   *\n   * @return Pointer for kd-tree node\n\
    \   */\n  KDTreeNode *build(std::vector<std::vector<size_t>> &data, size_t depth)\
    \ {\n    if (data[0].size() == 1) {\n      return new KDTreeNode(this->dim, data[0][0]);\n\
    \    } else {\n      std::vector<std::vector<size_t>> left_data(this->dim),\n\
    \          right_data(this->dim);\n      size_t median_idx =\n          static_cast<size_t>(static_cast<int>(data[0].size()\
    \ - 1) / 2);\n      size_t median = data[depth % this->dim][median_idx];\n   \
    \   for (size_t i = 0; i < this->dim; i++) {\n        for (size_t j : data[i])\
    \ {\n          if (this->data[j] == this->data[median] or\n              DataType::compare(this->data[j],\
    \ this->data[median],\n                                depth % this->dim)) {\n\
    \            left_data[i].emplace_back(j);\n          } else {\n            right_data[i].emplace_back(j);\n\
    \          }\n        }\n      }\n      assert(left_data[0].size() > 0 and right_data[0].size()\
    \ > 0);\n      KDTreeNode *node = new KDTreeNode(depth % this->dim, median);\n\
    \      node->left = build(left_data, depth + 1);\n      node->right = build(right_data,\
    \ depth + 1);\n      return node;\n    }\n  }\n\n  /**\n   * Builder for kd-tree\n\
    \   *\n   * @param data Array of input data\n   */\n  void build(std::vector<DataType>\
    \ &data) {\n    assert(data.size() > 0);\n\n    this->data = data;\n\n    std::vector<std::vector<size_t>>\
    \ _data(this->dim,\n                                           std::vector<size_t>(data.size()));\n\
    \    for (size_t i = 0; i < this->dim; i++) {\n      std::iota(_data[i].begin(),\
    \ _data[i].end(), 0);\n      sort(_data[i].begin(), _data[i].end(),\n        \
    \   [&](const size_t &a, const size_t &b) {\n             return DataType::compare(this->data[a],\
    \ this->data[b], i);\n           });\n    }\n    this->root = build(_data, 0);\n\
    \  }\n\n  /**\n   * Reporting Function for kd-tree\n   * This function report\
    \ all leafs of subtree whose root is given node.\n   *\n   * @param node root\
    \ of subtree for reporting\n   * @param output array of reported data\n   */\n\
    \  void report_subtree(KDTreeNode *node, std::vector<size_t> &output) const {\n\
    \    if (node->is_leaf_node()) {\n      output.emplace_back(node->idx);\n    }\
    \ else {\n      report_subtree(node->left, output);\n      report_subtree(node->right,\
    \ output);\n    }\n  }\n\n  /**\n   * Range Query for kd-tree\n   *\n   * @param\
    \ query_region Given query\n   *\n   * @return Reported indices\n   */\n  void\
    \ query(Region<T> query_region, std::vector<size_t> &output) const {\n    T node_low,\
    \ node_high;\n    node_low.fill(this->min_range);\n    node_high.fill(this->max_range);\n\
    \    Region<T> node_region(node_low, node_high);\n    query(this->root, query_region,\
    \ node_region, output);\n  }\n\n  /**\n   *\n   * @param node\n   * @param query_region\n\
    \   * @param node_region\n   * @param output\n   */\n  void query(KDTreeNode *node,\
    \ Region<T> query_region, Region<T> node_region,\n             std::vector<size_t>\
    \ &output) const {\n    T data = this->data[node->idx].data;\n    if (node->is_leaf_node())\
    \ {\n      if (query_region.include(data)) {\n        output.emplace_back(node->idx);\n\
    \      }\n    } else {\n      Region<T> left_region = node_region, right_region\
    \ = node_region;\n      Region<T> left_query_region = query_region,\n        \
    \        right_query_region = query_region;\n\n      left_region.high[node->axis]\
    \ = data[node->axis];\n      right_region.low[node->axis] = data[node->axis];\n\
    \      if (query_region.low[node->axis] <= data[node->axis] and\n          data[node->axis]\
    \ < query_region.high[node->axis]) {\n        left_query_region.high[node->axis]\
    \ = data[node->axis];\n      }\n      if (data[node->axis] <= query_region.high[node->axis]\
    \ and\n          query_region.low[node->axis] < data[node->axis]) {\n        right_query_region.low[node->axis]\
    \ = data[node->axis];\n      }\n      if (left_query_region.include(left_region))\
    \ {\n        report_subtree(node->left, output);\n      } else if (left_region.overlap(left_query_region))\
    \ {\n        query(node->left, left_query_region, left_region, output);\n    \
    \  }\n\n      if (right_query_region.include(right_region)) {\n        report_subtree(node->right,\
    \ output);\n      } else if (right_region.overlap(right_query_region)) {\n   \
    \     query(node->right, right_query_region, right_region, output);\n      }\n\
    \    }\n  }\n\n  /**\n   *\n   */\n  void output() const { output_kdtree(this->root);\
    \ }\n\n  /**\n   *\n   *\n   * @param node\n   */\n  void output_kdtree(KDTreeNode\
    \ *node) const {\n    std::cout << \"idx: \" << node->idx << \", (\";\n    for\
    \ (size_t i = 0; i < this->dim; i++) {\n      if (i > 0) {\n        std::cout\
    \ << ',';\n      }\n      std::cout << this->data[node->idx][i];\n    }\n    std::cout\
    \ << \") \";\n    if (not node->is_leaf_node()) {\n      std::cout << \"(left,\
    \ right) = (\" << node->left->idx << ','\n                << node->right->idx\
    \ << ')' << std::endl;\n      output_kdtree(node->left);\n      output_kdtree(node->right);\n\
    \    } else {\n      std::cout << std::endl;\n    }\n  }\n};\n\n/*\n * Example\
    \ of Usage (AOJ DSL_2_C\n * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C)\n\
    \ */\n\nvoid aoj() {\n  using DataType = Data<std::array<int, 2>>;\n  KDTree<DataType>\
    \ kdtree;\n  std::vector<DataType> points;\n  int N;\n  scanf(\"%d\", &N);\n \
    \ for (size_t i = 0; (int)i < N; i++) {\n    int x, y;\n    scanf(\"%d %d\", &x,\
    \ &y);\n    DataType::type tmp = {x, y};\n    points.emplace_back(DataType(tmp));\n\
    \  }\n  kdtree.build(points);\n\n  int Q;\n  scanf(\"%d\", &Q);\n  for (size_t\
    \ i = 0; (int)i < Q; i++) {\n    int sx, tx, sy, ty;\n    scanf(\"%d %d %d %d\"\
    , &sx, &tx, &sy, &ty);\n    DataType::type low = {sx, sy}, high = {tx, ty};\n\
    \    Region<DataType::type> query_region(low, high);\n    std::vector<size_t>\
    \ out;\n    kdtree.query(query_region, out);\n    std::sort(out.begin(), out.end());\n\
    \    for (size_t i : out) printf(\"%lu\\n\", i);\n    printf(\"\\n\");\n  }\n\
    }\n\nint main() {\n  std::cin.tie(0);\n  std::ios_base::sync_with_stdio(false);\n\
    \  aoj();\n  return 0;\n}\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: c++-library/kd_tree.cpp
  requiredBy: []
  timestamp: '2020-01-21 04:11:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: c++-library/kd_tree.cpp
layout: document
redirect_from:
- /library/c++-library/kd_tree.cpp
- /library/c++-library/kd_tree.cpp.html
title: An implementation of kd-tree
---
