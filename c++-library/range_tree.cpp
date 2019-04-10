/**
 * @file range_tree.cpp
 * @brief An implementation of range tree
 * @author knuu
 * @date 2018/09/16
 *
 */

#include <algorithm>
#include <array>
#include <cassert>
#include <cstddef>
#include <iostream>
#include <limits>
#include <numeric>
#include <vector>

/**
 * @brief type for input data of range-tree
 */
template <typename T>
struct Data {
  using type = T;
  type data;

  /**
   * Constructor for Data
   * @param data Data should be std::array or std::vector.
   */
  Data(type data) : data(data) {}

  /**
   * Comparing function for data.
   * This function compares two data in lexicographical order.
   *
   * @param data1 First data for comparing
   * @param data2 Second data for comparing
   * @param base Start dimension for comparing.
   *
   * @return If data1 < data1 in lexicographical order, then true, otherwise
   * false.
   */
  static bool compare(const Data<type> &data1, const Data<type> &data2,
                      size_t base = 1) {
    const size_t dim = data1.data.size();
    for (size_t i = 0; i < dim; i++) {
      if (data1.data[(i + base) % dim] != data2.data[(i + base) % dim]) {
        return data1.data[(i + base) % dim] < data2.data[(i + base) % dim];
      }
    }
    return false;
  }
  /**
   * == operator for data
   */
  bool operator==(const Data<type> &data) const {
    return this->data == data.data;
  }
};

/**
 * Orthogonal Region for range-tree
 */
template <typename T>
struct Region {
  T low, high;
  /**
   * Constructor for struct Region
   * If d = low.size(), then corresponding orthogonal region R is following.
   * R = [low[0], high[0]] * [low[1], high[1]] * ... * [low[d-1], high[d-1]]
   *
   * @param low lower borders of orthogonal region
   * @param high higher borders of orthogonal region
   */
  Region(T low, T high) : low(low), high(high){};

  /**
   * Checking Function of Inclusion for Data and Region.
   *
   * @param data A data
   * @return If this region include the data, then return true, otherwise return
   * false.
   */
  bool include(T data) const {
    size_t dim = this->low.size();
    for (size_t i = 0; i < dim; i++) {
      if (data[i] < low[i] or high[i] < data[i]) {
        return false;
      }
    }
    return true;
  }

  /**
   * Checking Function of Inclusion for Two Regions.
   *
   * @param region A region.
   * @return If this region include the given region, then return true,
   * otherwise return false.
   */
  bool include(Region<T> region) const {
    size_t dim = this->low.size();
    for (size_t bit = 0; bit < (1U << dim); bit++) {
      T data;
      for (size_t i = 0; i < dim; i++) {
        if (bit >> i & 1) {
          data[i] = region.low[i];
        } else {
          data[i] = region.high[i];
        }
      }
      if (not this->include(data)) {
        return false;
      }
    }
    return true;
  }

  /**
   * Cheking Function of Overlapping for Two Regions.
   *
   * @param region A region.
   * @return If this region overlaps the given region, then return true,
   * otherwise return false.
   */
  bool overlap(Region<T> region) const {
    size_t dim = this->low.size();
    for (size_t bit = 0; bit < (1U << dim); bit++) {
      T data;
      for (size_t i = 0; i < dim; i++) {
        if (bit >> i & 1) {
          data[i] = region.low[i];
        } else {
          data[i] = region.high[i];
        }
      }
      if (this->include(data)) {
        return true;
      }
    }
    return false;
  }

  /**
   * overloading of << operator
   */
  friend std::ostream &operator<<(std::ostream &os, const Region<T> &region) {
    for (size_t i = 0; i < region.low.size(); i++) {
      if (i > 0) {
        os << 'x';
      }
      os << '[' << region.low[i] << ',' << region.high[i] << ']';
    }
    return os;
  }
};

struct RangeTreeNode {
  size_t idx;                  /**< Node index */
  RangeTreeNode *assoc;        /**< Pointer of associated structure */
  RangeTreeNode *left, *right; /**< Pointer of left & right node */
  RangeTreeNode(size_t idx)
      : idx(idx), assoc(nullptr), left(nullptr), right(nullptr) {}
  bool is_leaf_node() const { return left == nullptr and right == nullptr; }
};

template <typename DataType>
struct RangeTree {
  using T = typename DataType::type;
  using VT = typename T::value_type;
  size_t dim;                 /**< Dimension of Data */
  std::vector<DataType> data; /**< Data in range tree */
  VT min_range, max_range;    /**< Initial Range for range query */
  RangeTreeNode *root;        /**< Root Node of range-tree */

  RangeTree(size_t dim = 2, VT min_range = std::numeric_limits<VT>::min(),
            VT max_range = std::numeric_limits<VT>::max())
      : dim(dim), min_range(min_range), max_range(max_range) {}

  RangeTreeNode *build_1d(std::vector<size_t> &data, size_t low, size_t high) {
    if (low + 1 == high) {
      return new RangeTreeNode(data[low]);
    }
    size_t median = (low + high + 1) / 2;
    RangeTreeNode *node = new RangeTreeNode(data[median - 1]);
    node->left = build_1d(data, low, median);
    node->right = build_1d(data, median, high);
    return node;
  }

  RangeTreeNode *build(std::vector<std::vector<size_t>> &data, size_t depth) {
    RangeTreeNode *assoc;
    if (depth + 2 == this->dim) {
      assoc = build_1d(data[depth + 1], 0, data[0].size());
    } else {
      assoc = build(data, depth + 1);
    }

    if (data[0].size() == 1) {
      RangeTreeNode *node = new RangeTreeNode(data[0][0]);
      node->assoc = new RangeTreeNode(data[0][0]);
      return node;
    }
    std::vector<std::vector<size_t>> left_data(this->dim),
        right_data(this->dim);
    size_t median_idx =
        static_cast<size_t>(static_cast<int>(data[0].size() - 1) / 2);
    size_t median = data[depth % this->dim][median_idx];
    for (size_t i = 0; i < this->dim; i++) {
      for (size_t j : data[i]) {
        if (this->data[j] == this->data[median] or
            DataType::compare(this->data[j], this->data[median],
                              depth % this->dim)) {
          left_data[i].emplace_back(j);
        } else {
          right_data[i].emplace_back(j);
        }
      }
    }
    assert(left_data[0].size() > 0 and right_data[0].size() > 0);
    RangeTreeNode *node = new RangeTreeNode(median);
    node->left = build(left_data, depth);
    node->right = build(right_data, depth);
    node->assoc = assoc;
    return node;
  }

  void build(std::vector<DataType> &data) {
    assert(data.size() > 0);
    this->data = data;
    std::vector<std::vector<size_t>> _data(this->dim,
                                           std::vector<size_t>(data.size()));
    for (size_t i = 0; i < this->dim; i++) {
      std::iota(_data[i].begin(), _data[i].end(), 0);
      sort(_data[i].begin(), _data[i].end(),
           [&](const size_t &a, const size_t &b) {
             return DataType::compare(this->data[a], this->data[b], i);
           });
    }
    this->root = build(_data, 0);
  }

  void output(bool assoc = true) const { output(this->root, assoc); }

  void output(RangeTreeNode *node, bool assoc = true) const {
    std::cout << "idx: " << node->idx << ", (";
    for (size_t i = 0; i < this->dim; i++) {
      if (i > 0) {
        std::cout << ',';
      }
      std::cout << this->data[node->idx].data[i];
    }
    std::cout << ") ";
    if (not node->is_leaf_node()) {
      std::cout << "(left, right) = (" << node->left->idx << ','
                << node->right->idx << ')' << std::endl;
      if (node->assoc != nullptr and assoc) {
        std::cout << "assoc start" << std::endl;
        output(node->assoc, assoc);
        std::cout << "assoc end" << std::endl;
      }
      output(node->left, assoc);
      output(node->right, assoc);

    } else {
      std::cout << std::endl;
    }
  }

  RangeTreeNode *find_split_node(RangeTreeNode *node, size_t dim, DataType low,
                                 DataType high) const {
    DataType node_data = this->data[node->idx];
    while (not node->is_leaf_node() and
           (DataType::compare(node_data, low, dim) or
            not DataType::compare(node_data, high, dim))) {
      if (DataType::compare(node_data, low, dim)) {
        node = node->right;
      } else {
        node = node->left;
      }
      node_data = this->data[node->idx];
    }
    return node;
  }

  void report_subtree(RangeTreeNode *node, std::vector<size_t> &output) const {
    if (node->is_leaf_node()) {
      output.emplace_back(node->idx);
    } else {
      report_subtree(node->left, output);
      report_subtree(node->right, output);
    }
  }

  std::vector<size_t> query(Region<T> query_region) const {
    std::vector<size_t> output;
    query(this->root, query_region, 0, output);
    return output;
  }

  void query(RangeTreeNode *node, Region<T> &query_region, size_t dim,
             std::vector<size_t> &output) const {
    T low_, high_;
    low_.fill(this->min_range), high_.fill(this->max_range);
    low_[dim] = query_region.low[dim], high_[dim] = query_region.high[dim];
    DataType low(low_), high(high_);

    RangeTreeNode *split_node = this->find_split_node(node, dim, low, high);
    // std::cout << split_node->idx << ' ' << this->is_leaf_node(split_node) <<
    // std::endl;

    if (split_node->is_leaf_node()) {
      if (query_region.include(this->data[split_node->idx].data)) {
        output.emplace_back(split_node->idx);
      }
      return;
    }

    node = split_node->left;
    DataType node_data = this->data[node->idx];
    while (not node->is_leaf_node()) {
      // std::cout << node->idx << ' ' << this->is_leaf_node(node) << std::endl;
      if (DataType::compare(node_data, low, dim)) {
        node = node->right;
      } else {
        if (dim + 1 == this->dim) {
          report_subtree(node->right, output);
        } else {
          query(node->right->assoc, query_region, dim + 1, output);
        }
        node = node->left;
      }
      node_data = this->data[node->idx];
    }
    if (query_region.include(this->data[node->idx].data)) {
      output.emplace_back(node->idx);
    }

    node = split_node->right;
    node_data = this->data[node->idx];
    while (not node->is_leaf_node()) {
      // std::cout << node->idx << ' ' << this->is_leaf_node(node) << std::endl;
      if (DataType::compare(node_data, high, dim)) {
        if (dim + 1 == this->dim) {
          report_subtree(node->left, output);
        } else {
          query(node->left->assoc, query_region, dim + 1, output);
        }
        node = node->right;
      } else {
        node = node->left;
      }
      node_data = this->data[node->idx];
    }
    if (query_region.include(this->data[node->idx].data)) {
      output.emplace_back(node->idx);
    }
  }
};

/*
 * Example of Usage (AOJ DSL_2_C
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C)
 */
int main() {
  using DataType = Data<std::array<int, 2>>;
  RangeTree<DataType> range_tree;
  std::vector<DataType> points;
  int N;
  scanf("%d", &N);
  for (size_t i = 0; (int)i < N; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    DataType::type tmp = {x, y};
    points.emplace_back(DataType(tmp));
  }
  range_tree.build(points);
  // range_tree.output(false);

  ///*
  int Q;
  scanf("%d", &Q);
  for (size_t i = 0; (int)i < Q; i++) {
    int sx, tx, sy, ty;
    scanf("%d %d %d %d", &sx, &tx, &sy, &ty);
    DataType::type low = {sx, sy}, high = {tx, ty};
    Region<DataType::type> query_region(low, high);
    std::vector<size_t> out = range_tree.query(query_region);
    std::sort(out.begin(), out.end());
    for (size_t i : out) printf("%lu\n", i);
    printf("\n");
  }
  //*/
  return 0;
}
