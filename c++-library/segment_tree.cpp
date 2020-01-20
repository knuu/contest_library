#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <vector>

template <class Monoid>
struct SegmentTree {
  using T = typename Monoid::type;
  int N_, N;
  std::vector<T> dat;

  SegmentTree(const int N_) : N_(N_) {
    assert(N_ > 0);
    N = 1;
    while (N < N_) {
      N <<= 1;
    }
    dat.assign(2 * N - 1, Monoid::identity());
  }

  SegmentTree(const std::vector<T> &dat_) : N_(dat_.size()) {
    assert(N_ > 0);
    N = 1;
    while (N < N_) {
      N <<= 1;
    }
    dat.assign(2 * N - 1, Monoid::identity());
    std::copy(dat_.begin(), dat_.end(), dat.begin() + N - 1);
    for (int i = N - 2; i >= 0; i--) {
      dat[i] = Monoid::merge(dat[2 * i + 1], dat[2 * i + 2]);
    }
  }

  int size() { return N_; }

  void update(int key, T val) {
    assert(0 <= key && key < N_);

    key += N - 1;
    dat[key] = val;

    while (key > 0) {
      key = (key - 1) / 2;
      dat[key] =
          Monoid::merge(dat[2 * key + 1], dat[2 * key + 2]);  // rewrite here
    }
  }

  inline const T &operator[](const int k) const { return dat.at(N - 1 + k); }
  inline T &operator[](const int k) { return dat.at(N - 1 + k); }

  T query(int low, int high) const {
    T left_ret = Monoid::identity(), right_ret = Monoid::identity();
    for (low += N, high += N; low < high; low >>= 1, high >>= 1) {
      if (low & 1) {
        left_ret = Monoid::merge(left_ret, dat[low - 1]);
        low++;
      }
      if (high & 1) {
        high--;
        right_ret = Monoid::merge(dat[high - 1], right_ret);
      }
    }
    return Monoid::merge(left_ret, right_ret);
  }
};

template <typename T>
struct RangeSumQuery {
  using type = T;
  static type identity() { return T(0); }
  static type merge(const type &l, const type &r) { return l + r; }
};

template <typename T>
struct RangeMinQuery {
  using type = T;
  static type identity() { return std::numeric_limits<T>::max(); }
  static type merge(const type &l, const type &r) { return std::min(l, r); }
};

template <typename T>
struct RangeMaxQuery {
  using type = T;
  static type identity() { return T(0); }
  static type merge(const type &l, const type &r) { return std::max(l, r); }
};

void aoj_min() {
  // https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
  int N, Q;
  std::cin >> N >> Q;
  SegmentTree<RangeMinQuery<int>> rmq(N);
  for (int i = 0; i < Q; i++) {
    int t, x, y;
    std::cin >> t >> x >> y;
    if (t == 0) {
      rmq.update(x, y);
    } else {
      std::cout << rmq.query(x, y + 1) << '\n';
    }
  }
}

void aoj_sum() {
  int N, Q;
  std::cin >> N >> Q;
  SegmentTree<RangeSumQuery<int>> rsq(N);
  for (int i = 0; i < Q; i++) {
    int t, x, y;
    std::cin >> t >> x >> y;
    x--;
    if (t == 0) {
      rsq.update(x, rsq[x] + y);
    } else {
      std::cout << rsq.query(x, y) << '\n';
    }
  }
}

void yosupo_static_rmq() {
  int N, Q;
  std::cin >> N >> Q;
  std::vector<int> arr(N);
  for (int i = 0; i < N; i++) std::cin >> arr[i];
  SegmentTree<RangeMinQuery<int>> rsq(arr);
  for (int i = 0; i < Q; i++) {
    int x, y;
    std::cin >> x >> y;
    std::cout << rsq.query(x, y) << '\n';
  }
}

void yosupo_rsq() {
  int N, Q;
  std::cin >> N >> Q;
  std::vector<long long> arr(N);
  for (int i = 0; i < N; i++) std::cin >> arr[i];
  SegmentTree<RangeSumQuery<long long>> rsq(arr);
  for (int i = 0; i < Q; i++) {
    int t, x, y;
    std::cin >> t >> x >> y;
    if (t == 0) {
      rsq.update(x, rsq[x] + y);
    } else {
      std::cout << rsq.query(x, y) << '\n';
    }
  }
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);
  // aoj_min();
  // aoj_sum();
  // yosupo_static_rmq();
  yosupo_rsq();
  return 0;
}