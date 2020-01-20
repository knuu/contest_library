/**
 * @file kd_tree.cpp
 * @brief An implementation of kd-tree
 * @author knuu
 * @date 2018/09/16
 *
 * Usage:
 * 1. Define struct Data for Input data, comparing function, and == operator.
 * 2. Construct KD-tree.build(Array of Data)
 * 3. Use KDTree.range_query(Array of Region).
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
 * @brief type for input data of kd-tree
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
  const T &operator[](const size_t i) const {
    return *(this->data.begin() + i);
  }
  T &operator[](const size_t i) { return *(this->data.begin() + i); }
};

/**
 * Orthogonal Region for kd-tree
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

/**
 * Node for kd-tree
 */
struct KDTreeNode {
  /// The axis for splitting
  size_t axis;
  /// The index of data for splitting
  size_t idx;
  /// Children of the node
  KDTreeNode *left, *right;

  KDTreeNode(size_t axis, size_t idx)
      : axis(axis), idx(idx), left(nullptr), right(nullptr) {}
  bool is_leaf_node() const {
    return this->left == nullptr and this->right == nullptr;
  }
};

/**
 * class KDTree
 */
template <typename DataType>
struct KDTree {
  using T = typename DataType::type;
  using VT = typename T::value_type;
  size_t dim;                 /**< Dimension of Data */
  std::vector<DataType> data; /**< Data in kd-tree */
  VT min_range, max_range;    /**< Initial Range for range query */
  KDTreeNode *root;           /**< Root Node of kd-tree */

  /**
   * Constructor for kd-tree
   *
   * @param dim Dimension of each data
   * @param min_range Minimun value of query range
   * @param max_range Maximun value of query range
   */
  KDTree(size_t dim = 2, VT min_range = std::numeric_limits<VT>::min(),
         VT max_range = std::numeric_limits<VT>::max())
      : dim(dim), min_range(min_range), max_range(max_range) {}

  /**
   * Recursive Builder of kd-tree
   *
   * @param data Array of data
   * @param depth Depth for data dividing
   *
   * @return Pointer for kd-tree node
   */
  KDTreeNode *build(std::vector<std::vector<size_t>> &data, size_t depth) {
    if (data[0].size() == 1) {
      return new KDTreeNode(this->dim, data[0][0]);
    } else {
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
      KDTreeNode *node = new KDTreeNode(depth % this->dim, median);
      node->left = build(left_data, depth + 1);
      node->right = build(right_data, depth + 1);
      return node;
    }
  }

  /**
   * Builder for kd-tree
   *
   * @param data Array of input data
   */
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

  /**
   * Reporting Function for kd-tree
   * This function report all leafs of subtree whose root is given node.
   *
   * @param node root of subtree for reporting
   * @param output array of reported data
   */
  void report_subtree(KDTreeNode *node, std::vector<size_t> &output) const {
    if (node->is_leaf_node()) {
      output.emplace_back(node->idx);
    } else {
      report_subtree(node->left, output);
      report_subtree(node->right, output);
    }
  }

  /**
   * Range Query for kd-tree
   *
   * @param query_region Given query
   *
   * @return Reported indices
   */
  void query(Region<T> query_region, std::vector<size_t> &output) const {
    T node_low, node_high;
    node_low.fill(this->min_range);
    node_high.fill(this->max_range);
    Region<T> node_region(node_low, node_high);
    query(this->root, query_region, node_region, output);
  }

  /**
   *
   * @param node
   * @param query_region
   * @param node_region
   * @param output
   */
  void query(KDTreeNode *node, Region<T> query_region, Region<T> node_region,
             std::vector<size_t> &output) const {
    T data = this->data[node->idx].data;
    if (node->is_leaf_node()) {
      if (query_region.include(data)) {
        output.emplace_back(node->idx);
      }
    } else {
      Region<T> left_region = node_region, right_region = node_region;
      Region<T> left_query_region = query_region,
                right_query_region = query_region;

      left_region.high[node->axis] = data[node->axis];
      right_region.low[node->axis] = data[node->axis];
      if (query_region.low[node->axis] <= data[node->axis] and
          data[node->axis] < query_region.high[node->axis]) {
        left_query_region.high[node->axis] = data[node->axis];
      }
      if (data[node->axis] <= query_region.high[node->axis] and
          query_region.low[node->axis] < data[node->axis]) {
        right_query_region.low[node->axis] = data[node->axis];
      }
      if (left_query_region.include(left_region)) {
        report_subtree(node->left, output);
      } else if (left_region.overlap(left_query_region)) {
        query(node->left, left_query_region, left_region, output);
      }

      if (right_query_region.include(right_region)) {
        report_subtree(node->right, output);
      } else if (right_region.overlap(right_query_region)) {
        query(node->right, right_query_region, right_region, output);
      }
    }
  }

  /**
   *
   */
  void output() const { output_kdtree(this->root); }

  /**
   *
   *
   * @param node
   */
  void output_kdtree(KDTreeNode *node) const {
    std::cout << "idx: " << node->idx << ", (";
    for (size_t i = 0; i < this->dim; i++) {
      if (i > 0) {
        std::cout << ',';
      }
      std::cout << this->data[node->idx][i];
    }
    std::cout << ") ";
    if (not node->is_leaf_node()) {
      std::cout << "(left, right) = (" << node->left->idx << ','
                << node->right->idx << ')' << std::endl;
      output_kdtree(node->left);
      output_kdtree(node->right);
    } else {
      std::cout << std::endl;
    }
  }
};

/*
 * Example of Usage (AOJ DSL_2_C
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C)
 */

void aoj() {
  using DataType = Data<std::array<int, 2>>;
  KDTree<DataType> kdtree;
  std::vector<DataType> points;
  int N;
  scanf("%d", &N);
  for (size_t i = 0; (int)i < N; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    DataType::type tmp = {x, y};
    points.emplace_back(DataType(tmp));
  }
  kdtree.build(points);

  int Q;
  scanf("%d", &Q);
  for (size_t i = 0; (int)i < Q; i++) {
    int sx, tx, sy, ty;
    scanf("%d %d %d %d", &sx, &tx, &sy, &ty);
    DataType::type low = {sx, sy}, high = {tx, ty};
    Region<DataType::type> query_region(low, high);
    std::vector<size_t> out;
    kdtree.query(query_region, out);
    std::sort(out.begin(), out.end());
    for (size_t i : out) printf("%lu\n", i);
    printf("\n");
  }
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);
  aoj();
  return 0;
}
