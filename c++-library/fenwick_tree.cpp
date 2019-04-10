/**
 * @brief ange Sum Query by FenwickTree(Binary Indexed Tree)
 *
 * total number: n
 * queries:
 *    1. add(i, val): bit[i] += val
 *    2. sum(n): sum(bit[0] + ... + bit[n-1])
 * query time complexity: O(log n)
 * space complexity: O(N)
 *
 * Self-balancing binary search tree or Segment Tree can do the same, it takes
 * longer to program and complexity also increases.

 * Thanks: http://hos.ac/slides/20140319_bit.pdf
 * used in ARC031 C, indeednow finalB E, DSL2B(AOJ), ARC033 C, yukicoder No.59
 */

#include <cassert>
#include <vector>

template <typename T>
struct RangeSumQuery {
  int N;
  std::vector<T> dat;

  RangeSumQuery(int N) : N(N) {
    assert(N > 0);
    dat.resize(N, 0);
  }

  void add(int k, T val) {
    assert(0 <= k && k < N);
    for (int x = k; x < N; x |= x + 1) {
      dat[x] += val;
    }
  }

  // [0, k)
  T sum(int k) {
    assert(k >= 0);
    T ret = 0;
    for (int x = k - 1; x >= 0; x = (x & (x + 1)) - 1) {
      ret += dat[x];
    }
    return ret;
  }
  // [l, r)
  T sum(int l, int r) {
    assert(0 <= l && l <= r && r <= N);
    return sum(r) - sum(l);
  }

  T index(int k) {
    assert(0 <= k && k < N);
    return sum(k + 1) - sum(k);
  }
};
