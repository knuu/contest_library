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

template <std::uint_fast64_t Modulus = 1'000'000'007>
class ModInt {
  using u64 = std::uint_fast64_t;

 public:
  using type = ModInt;

  u64 value;

  constexpr ModInt(const u64 x = 0) noexcept : value(x % Modulus) {
    if (value < 0) value += Modulus;
  }
  constexpr ModInt operator-() const noexcept {
    return value ? Modulus - value : 0;
  }
  constexpr ModInt operator+(const ModInt rhs) const noexcept {
    return ModInt(*this) += rhs;
  }
  constexpr ModInt operator-(const ModInt rhs) const noexcept {
    return ModInt(*this) -= rhs;
  }
  constexpr ModInt operator*(const ModInt rhs) const noexcept {
    return ModInt(*this) *= rhs;
  }
  constexpr ModInt operator/(const ModInt rhs) const noexcept {
    return ModInt(*this) /= rhs;
  }
  constexpr ModInt &operator+=(const ModInt rhs) noexcept {
    value += rhs.value;
    if (value >= Modulus) value -= Modulus;
    return *this;
  }
  constexpr ModInt &operator-=(const ModInt rhs) noexcept {
    if (value < rhs.value) value += Modulus;
    value -= rhs.value;
    return *this;
  }
  constexpr ModInt &operator*=(const ModInt rhs) noexcept {
    value = value * rhs.value % Modulus;
    return *this;
  }
  constexpr bool operator==(const ModInt &r) const noexcept {
    return value == r.value;
  }
  constexpr bool operator!=(const ModInt &r) const noexcept {
    return value != r.value;
  }
  constexpr ModInt &operator/=(ModInt rhs) noexcept {
    u64 exp = Modulus - 2;
    while (exp) {
      if (exp % 2) *this *= rhs;
      rhs *= rhs;
      exp /= 2;
    }
    return *this;
  }

  friend constexpr std::ostream &operator<<(std::ostream &os,
                                            const ModInt &x) noexcept {
    return os << x.value;
  }

  static ModInt identity_zero() { return ModInt(); }
  static ModInt identity_one() { return ModInt(1); }
};

template <typename T>
struct RangeCompositeQuery {
  using type = std::pair<T, T>;
  static type identity() { return type{1, 0}; }
  static type merge(const type &l, const type &r) {
    return type{l.first * r.first, l.second * r.first + r.second};
  }
};

using mint = ModInt<998'244'353>;
using mint_p = std::pair<mint, mint>;

void yosupo_composite() {
  // https://judge.yosupo.jp/problem/point_set_range_composite
  int N, Q;
  std::cin >> N >> Q;

  std::vector<mint_p> funcs;
  funcs.reserve(N);
  for (int i = 0; i < N; i++) {
    int a, b;
    std::cin >> a >> b;
    funcs.emplace_back(mint(a), mint(b));
  }
  SegmentTree<RangeCompositeQuery<mint>> segt(funcs);

  for (int i = 0; i < Q; i++) {
    int t, a, b, c;
    std::cin >> t >> a >> b >> c;
    if (t == 0) {
      segt.update(a, mint_p{b, c});
    } else {
      mint_p func = segt.query(a, b);
      std::cout << func.first * c + func.second << '\n';
    }
  }
}

void yosupo_que_composite() {
  // https://judge.yosupo.jp/problem/queue_operate_all_composite
  int Q;
  std::cin >> Q;
  SegmentTree<RangeCompositeQuery<mint>> segt(Q);
  int left = 0, right = 0;
  for (int i = 0; i < Q; i++) {
    int t;
    std::cin >> t;
    if (t == 0) {
      int a, b;
      std::cin >> a >> b;
      segt.update(right++, mint_p{a, b});
    } else if (t == 1) {
      left++;
    } else {
      int x;
      std::cin >> x;
      mint_p func = segt.query(left, right);
      std::cout << func.first * mint{x} + func.second << '\n';
    }
  }
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);
  // aoj_min();
  // aoj_sum();
  // yosupo_static_rmq();
  // yosupo_rsq();
  // yosupo_composite();
  yosupo_que_composite();
  return 0;
}