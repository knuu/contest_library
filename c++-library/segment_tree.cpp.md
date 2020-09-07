---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"c++-library/segment_tree.cpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <iostream>\n#include <limits>\n#include <vector>\n\ntemplate\
    \ <class Monoid>\nstruct SegmentTree {\n  using T = typename Monoid::type;\n \
    \ int N_, N;\n  std::vector<T> dat;\n\n  SegmentTree(const int N_) : N_(N_) {\n\
    \    assert(N_ > 0);\n    N = 1;\n    while (N < N_) {\n      N <<= 1;\n    }\n\
    \    dat.assign(2 * N - 1, Monoid::identity());\n  }\n\n  SegmentTree(const std::vector<T>\
    \ &dat_) : N_(dat_.size()) {\n    assert(N_ > 0);\n    N = 1;\n    while (N <\
    \ N_) {\n      N <<= 1;\n    }\n    dat.assign(2 * N - 1, Monoid::identity());\n\
    \    std::copy(dat_.begin(), dat_.end(), dat.begin() + N - 1);\n    for (int i\
    \ = N - 2; i >= 0; i--) {\n      dat[i] = Monoid::merge(dat[2 * i + 1], dat[2\
    \ * i + 2]);\n    }\n  }\n\n  int size() { return N_; }\n\n  void update(int key,\
    \ T val) {\n    assert(0 <= key && key < N_);\n\n    key += N - 1;\n    dat[key]\
    \ = val;\n\n    while (key > 0) {\n      key = (key - 1) / 2;\n      dat[key]\
    \ =\n          Monoid::merge(dat[2 * key + 1], dat[2 * key + 2]);  // rewrite\
    \ here\n    }\n  }\n\n  inline const T &operator[](const int k) const { return\
    \ dat.at(N - 1 + k); }\n  inline T &operator[](const int k) { return dat.at(N\
    \ - 1 + k); }\n\n  T query(int low, int high) const {\n    T left_ret = Monoid::identity(),\
    \ right_ret = Monoid::identity();\n    for (low += N, high += N; low < high; low\
    \ >>= 1, high >>= 1) {\n      if (low & 1) {\n        left_ret = Monoid::merge(left_ret,\
    \ dat[low - 1]);\n        low++;\n      }\n      if (high & 1) {\n        high--;\n\
    \        right_ret = Monoid::merge(dat[high - 1], right_ret);\n      }\n    }\n\
    \    return Monoid::merge(left_ret, right_ret);\n  }\n};\n\ntemplate <typename\
    \ T>\nstruct RangeSumQuery {\n  using type = T;\n  static type identity() { return\
    \ T(0); }\n  static type merge(const type &l, const type &r) { return l + r; }\n\
    };\n\ntemplate <typename T>\nstruct RangeMinQuery {\n  using type = T;\n  static\
    \ type identity() { return std::numeric_limits<T>::max(); }\n  static type merge(const\
    \ type &l, const type &r) { return std::min(l, r); }\n};\n\ntemplate <typename\
    \ T>\nstruct RangeMaxQuery {\n  using type = T;\n  static type identity() { return\
    \ T(0); }\n  static type merge(const type &l, const type &r) { return std::max(l,\
    \ r); }\n};\n\nvoid aoj_min() {\n  // https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\n\
    \  int N, Q;\n  std::cin >> N >> Q;\n  SegmentTree<RangeMinQuery<int>> rmq(N);\n\
    \  for (int i = 0; i < Q; i++) {\n    int t, x, y;\n    std::cin >> t >> x >>\
    \ y;\n    if (t == 0) {\n      rmq.update(x, y);\n    } else {\n      std::cout\
    \ << rmq.query(x, y + 1) << '\\n';\n    }\n  }\n}\n\nvoid aoj_sum() {\n  int N,\
    \ Q;\n  std::cin >> N >> Q;\n  SegmentTree<RangeSumQuery<int>> rsq(N);\n  for\
    \ (int i = 0; i < Q; i++) {\n    int t, x, y;\n    std::cin >> t >> x >> y;\n\
    \    x--;\n    if (t == 0) {\n      rsq.update(x, rsq[x] + y);\n    } else {\n\
    \      std::cout << rsq.query(x, y) << '\\n';\n    }\n  }\n}\n\nvoid yosupo_static_rmq()\
    \ {\n  int N, Q;\n  std::cin >> N >> Q;\n  std::vector<int> arr(N);\n  for (int\
    \ i = 0; i < N; i++) std::cin >> arr[i];\n  SegmentTree<RangeMinQuery<int>> rsq(arr);\n\
    \  for (int i = 0; i < Q; i++) {\n    int x, y;\n    std::cin >> x >> y;\n   \
    \ std::cout << rsq.query(x, y) << '\\n';\n  }\n}\n\nvoid yosupo_rsq() {\n  int\
    \ N, Q;\n  std::cin >> N >> Q;\n  std::vector<long long> arr(N);\n  for (int i\
    \ = 0; i < N; i++) std::cin >> arr[i];\n  SegmentTree<RangeSumQuery<long long>>\
    \ rsq(arr);\n  for (int i = 0; i < Q; i++) {\n    int t, x, y;\n    std::cin >>\
    \ t >> x >> y;\n    if (t == 0) {\n      rsq.update(x, rsq[x] + y);\n    } else\
    \ {\n      std::cout << rsq.query(x, y) << '\\n';\n    }\n  }\n}\n\ntemplate <std::uint_fast64_t\
    \ Modulus = 1'000'000'007>\nclass ModInt {\n  using u64 = std::uint_fast64_t;\n\
    \n public:\n  using type = ModInt;\n\n  u64 value;\n\n  constexpr ModInt(const\
    \ u64 x = 0) noexcept : value(x % Modulus) {\n    if (value < 0) value += Modulus;\n\
    \  }\n  constexpr ModInt operator-() const noexcept {\n    return value ? Modulus\
    \ - value : 0;\n  }\n  constexpr ModInt operator+(const ModInt rhs) const noexcept\
    \ {\n    return ModInt(*this) += rhs;\n  }\n  constexpr ModInt operator-(const\
    \ ModInt rhs) const noexcept {\n    return ModInt(*this) -= rhs;\n  }\n  constexpr\
    \ ModInt operator*(const ModInt rhs) const noexcept {\n    return ModInt(*this)\
    \ *= rhs;\n  }\n  constexpr ModInt operator/(const ModInt rhs) const noexcept\
    \ {\n    return ModInt(*this) /= rhs;\n  }\n  constexpr ModInt &operator+=(const\
    \ ModInt rhs) noexcept {\n    value += rhs.value;\n    if (value >= Modulus) value\
    \ -= Modulus;\n    return *this;\n  }\n  constexpr ModInt &operator-=(const ModInt\
    \ rhs) noexcept {\n    if (value < rhs.value) value += Modulus;\n    value -=\
    \ rhs.value;\n    return *this;\n  }\n  constexpr ModInt &operator*=(const ModInt\
    \ rhs) noexcept {\n    value = value * rhs.value % Modulus;\n    return *this;\n\
    \  }\n  constexpr bool operator==(const ModInt &r) const noexcept {\n    return\
    \ value == r.value;\n  }\n  constexpr bool operator!=(const ModInt &r) const noexcept\
    \ {\n    return value != r.value;\n  }\n  constexpr ModInt &operator/=(ModInt\
    \ rhs) noexcept {\n    u64 exp = Modulus - 2;\n    while (exp) {\n      if (exp\
    \ % 2) *this *= rhs;\n      rhs *= rhs;\n      exp /= 2;\n    }\n    return *this;\n\
    \  }\n\n  friend constexpr std::ostream &operator<<(std::ostream &os,\n      \
    \                                      const ModInt &x) noexcept {\n    return\
    \ os << x.value;\n  }\n\n  static ModInt identity_zero() { return ModInt(); }\n\
    \  static ModInt identity_one() { return ModInt(1); }\n};\n\ntemplate <typename\
    \ T>\nstruct RangeCompositeQuery {\n  using type = std::pair<T, T>;\n  static\
    \ type identity() { return type{1, 0}; }\n  static type merge(const type &l, const\
    \ type &r) {\n    return type{l.first * r.first, l.second * r.first + r.second};\n\
    \  }\n};\n\nusing mint = ModInt<998'244'353>;\nusing mint_p = std::pair<mint,\
    \ mint>;\n\nvoid yosupo_composite() {\n  // https://judge.yosupo.jp/problem/point_set_range_composite\n\
    \  int N, Q;\n  std::cin >> N >> Q;\n\n  std::vector<mint_p> funcs;\n  funcs.reserve(N);\n\
    \  for (int i = 0; i < N; i++) {\n    int a, b;\n    std::cin >> a >> b;\n   \
    \ funcs.emplace_back(mint(a), mint(b));\n  }\n  SegmentTree<RangeCompositeQuery<mint>>\
    \ segt(funcs);\n\n  for (int i = 0; i < Q; i++) {\n    int t, a, b, c;\n    std::cin\
    \ >> t >> a >> b >> c;\n    if (t == 0) {\n      segt.update(a, mint_p{b, c});\n\
    \    } else {\n      mint_p func = segt.query(a, b);\n      std::cout << func.first\
    \ * c + func.second << '\\n';\n    }\n  }\n}\n\nvoid yosupo_que_composite() {\n\
    \  // https://judge.yosupo.jp/problem/queue_operate_all_composite\n  int Q;\n\
    \  std::cin >> Q;\n  SegmentTree<RangeCompositeQuery<mint>> segt(Q);\n  int left\
    \ = 0, right = 0;\n  for (int i = 0; i < Q; i++) {\n    int t;\n    std::cin >>\
    \ t;\n    if (t == 0) {\n      int a, b;\n      std::cin >> a >> b;\n      segt.update(right++,\
    \ mint_p{a, b});\n    } else if (t == 1) {\n      left++;\n    } else {\n    \
    \  int x;\n      std::cin >> x;\n      mint_p func = segt.query(left, right);\n\
    \      std::cout << func.first * mint{x} + func.second << '\\n';\n    }\n  }\n\
    }\n\nint main() {\n  std::cin.tie(0);\n  std::ios_base::sync_with_stdio(false);\n\
    \  // aoj_min();\n  // aoj_sum();\n  // yosupo_static_rmq();\n  // yosupo_rsq();\n\
    \  // yosupo_composite();\n  yosupo_que_composite();\n  return 0;\n}\n"
  code: "#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include <limits>\n\
    #include <vector>\n\ntemplate <class Monoid>\nstruct SegmentTree {\n  using T\
    \ = typename Monoid::type;\n  int N_, N;\n  std::vector<T> dat;\n\n  SegmentTree(const\
    \ int N_) : N_(N_) {\n    assert(N_ > 0);\n    N = 1;\n    while (N < N_) {\n\
    \      N <<= 1;\n    }\n    dat.assign(2 * N - 1, Monoid::identity());\n  }\n\n\
    \  SegmentTree(const std::vector<T> &dat_) : N_(dat_.size()) {\n    assert(N_\
    \ > 0);\n    N = 1;\n    while (N < N_) {\n      N <<= 1;\n    }\n    dat.assign(2\
    \ * N - 1, Monoid::identity());\n    std::copy(dat_.begin(), dat_.end(), dat.begin()\
    \ + N - 1);\n    for (int i = N - 2; i >= 0; i--) {\n      dat[i] = Monoid::merge(dat[2\
    \ * i + 1], dat[2 * i + 2]);\n    }\n  }\n\n  int size() { return N_; }\n\n  void\
    \ update(int key, T val) {\n    assert(0 <= key && key < N_);\n\n    key += N\
    \ - 1;\n    dat[key] = val;\n\n    while (key > 0) {\n      key = (key - 1) /\
    \ 2;\n      dat[key] =\n          Monoid::merge(dat[2 * key + 1], dat[2 * key\
    \ + 2]);  // rewrite here\n    }\n  }\n\n  inline const T &operator[](const int\
    \ k) const { return dat.at(N - 1 + k); }\n  inline T &operator[](const int k)\
    \ { return dat.at(N - 1 + k); }\n\n  T query(int low, int high) const {\n    T\
    \ left_ret = Monoid::identity(), right_ret = Monoid::identity();\n    for (low\
    \ += N, high += N; low < high; low >>= 1, high >>= 1) {\n      if (low & 1) {\n\
    \        left_ret = Monoid::merge(left_ret, dat[low - 1]);\n        low++;\n \
    \     }\n      if (high & 1) {\n        high--;\n        right_ret = Monoid::merge(dat[high\
    \ - 1], right_ret);\n      }\n    }\n    return Monoid::merge(left_ret, right_ret);\n\
    \  }\n};\n\ntemplate <typename T>\nstruct RangeSumQuery {\n  using type = T;\n\
    \  static type identity() { return T(0); }\n  static type merge(const type &l,\
    \ const type &r) { return l + r; }\n};\n\ntemplate <typename T>\nstruct RangeMinQuery\
    \ {\n  using type = T;\n  static type identity() { return std::numeric_limits<T>::max();\
    \ }\n  static type merge(const type &l, const type &r) { return std::min(l, r);\
    \ }\n};\n\ntemplate <typename T>\nstruct RangeMaxQuery {\n  using type = T;\n\
    \  static type identity() { return T(0); }\n  static type merge(const type &l,\
    \ const type &r) { return std::max(l, r); }\n};\n\nvoid aoj_min() {\n  // https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\n\
    \  int N, Q;\n  std::cin >> N >> Q;\n  SegmentTree<RangeMinQuery<int>> rmq(N);\n\
    \  for (int i = 0; i < Q; i++) {\n    int t, x, y;\n    std::cin >> t >> x >>\
    \ y;\n    if (t == 0) {\n      rmq.update(x, y);\n    } else {\n      std::cout\
    \ << rmq.query(x, y + 1) << '\\n';\n    }\n  }\n}\n\nvoid aoj_sum() {\n  int N,\
    \ Q;\n  std::cin >> N >> Q;\n  SegmentTree<RangeSumQuery<int>> rsq(N);\n  for\
    \ (int i = 0; i < Q; i++) {\n    int t, x, y;\n    std::cin >> t >> x >> y;\n\
    \    x--;\n    if (t == 0) {\n      rsq.update(x, rsq[x] + y);\n    } else {\n\
    \      std::cout << rsq.query(x, y) << '\\n';\n    }\n  }\n}\n\nvoid yosupo_static_rmq()\
    \ {\n  int N, Q;\n  std::cin >> N >> Q;\n  std::vector<int> arr(N);\n  for (int\
    \ i = 0; i < N; i++) std::cin >> arr[i];\n  SegmentTree<RangeMinQuery<int>> rsq(arr);\n\
    \  for (int i = 0; i < Q; i++) {\n    int x, y;\n    std::cin >> x >> y;\n   \
    \ std::cout << rsq.query(x, y) << '\\n';\n  }\n}\n\nvoid yosupo_rsq() {\n  int\
    \ N, Q;\n  std::cin >> N >> Q;\n  std::vector<long long> arr(N);\n  for (int i\
    \ = 0; i < N; i++) std::cin >> arr[i];\n  SegmentTree<RangeSumQuery<long long>>\
    \ rsq(arr);\n  for (int i = 0; i < Q; i++) {\n    int t, x, y;\n    std::cin >>\
    \ t >> x >> y;\n    if (t == 0) {\n      rsq.update(x, rsq[x] + y);\n    } else\
    \ {\n      std::cout << rsq.query(x, y) << '\\n';\n    }\n  }\n}\n\ntemplate <std::uint_fast64_t\
    \ Modulus = 1'000'000'007>\nclass ModInt {\n  using u64 = std::uint_fast64_t;\n\
    \n public:\n  using type = ModInt;\n\n  u64 value;\n\n  constexpr ModInt(const\
    \ u64 x = 0) noexcept : value(x % Modulus) {\n    if (value < 0) value += Modulus;\n\
    \  }\n  constexpr ModInt operator-() const noexcept {\n    return value ? Modulus\
    \ - value : 0;\n  }\n  constexpr ModInt operator+(const ModInt rhs) const noexcept\
    \ {\n    return ModInt(*this) += rhs;\n  }\n  constexpr ModInt operator-(const\
    \ ModInt rhs) const noexcept {\n    return ModInt(*this) -= rhs;\n  }\n  constexpr\
    \ ModInt operator*(const ModInt rhs) const noexcept {\n    return ModInt(*this)\
    \ *= rhs;\n  }\n  constexpr ModInt operator/(const ModInt rhs) const noexcept\
    \ {\n    return ModInt(*this) /= rhs;\n  }\n  constexpr ModInt &operator+=(const\
    \ ModInt rhs) noexcept {\n    value += rhs.value;\n    if (value >= Modulus) value\
    \ -= Modulus;\n    return *this;\n  }\n  constexpr ModInt &operator-=(const ModInt\
    \ rhs) noexcept {\n    if (value < rhs.value) value += Modulus;\n    value -=\
    \ rhs.value;\n    return *this;\n  }\n  constexpr ModInt &operator*=(const ModInt\
    \ rhs) noexcept {\n    value = value * rhs.value % Modulus;\n    return *this;\n\
    \  }\n  constexpr bool operator==(const ModInt &r) const noexcept {\n    return\
    \ value == r.value;\n  }\n  constexpr bool operator!=(const ModInt &r) const noexcept\
    \ {\n    return value != r.value;\n  }\n  constexpr ModInt &operator/=(ModInt\
    \ rhs) noexcept {\n    u64 exp = Modulus - 2;\n    while (exp) {\n      if (exp\
    \ % 2) *this *= rhs;\n      rhs *= rhs;\n      exp /= 2;\n    }\n    return *this;\n\
    \  }\n\n  friend constexpr std::ostream &operator<<(std::ostream &os,\n      \
    \                                      const ModInt &x) noexcept {\n    return\
    \ os << x.value;\n  }\n\n  static ModInt identity_zero() { return ModInt(); }\n\
    \  static ModInt identity_one() { return ModInt(1); }\n};\n\ntemplate <typename\
    \ T>\nstruct RangeCompositeQuery {\n  using type = std::pair<T, T>;\n  static\
    \ type identity() { return type{1, 0}; }\n  static type merge(const type &l, const\
    \ type &r) {\n    return type{l.first * r.first, l.second * r.first + r.second};\n\
    \  }\n};\n\nusing mint = ModInt<998'244'353>;\nusing mint_p = std::pair<mint,\
    \ mint>;\n\nvoid yosupo_composite() {\n  // https://judge.yosupo.jp/problem/point_set_range_composite\n\
    \  int N, Q;\n  std::cin >> N >> Q;\n\n  std::vector<mint_p> funcs;\n  funcs.reserve(N);\n\
    \  for (int i = 0; i < N; i++) {\n    int a, b;\n    std::cin >> a >> b;\n   \
    \ funcs.emplace_back(mint(a), mint(b));\n  }\n  SegmentTree<RangeCompositeQuery<mint>>\
    \ segt(funcs);\n\n  for (int i = 0; i < Q; i++) {\n    int t, a, b, c;\n    std::cin\
    \ >> t >> a >> b >> c;\n    if (t == 0) {\n      segt.update(a, mint_p{b, c});\n\
    \    } else {\n      mint_p func = segt.query(a, b);\n      std::cout << func.first\
    \ * c + func.second << '\\n';\n    }\n  }\n}\n\nvoid yosupo_que_composite() {\n\
    \  // https://judge.yosupo.jp/problem/queue_operate_all_composite\n  int Q;\n\
    \  std::cin >> Q;\n  SegmentTree<RangeCompositeQuery<mint>> segt(Q);\n  int left\
    \ = 0, right = 0;\n  for (int i = 0; i < Q; i++) {\n    int t;\n    std::cin >>\
    \ t;\n    if (t == 0) {\n      int a, b;\n      std::cin >> a >> b;\n      segt.update(right++,\
    \ mint_p{a, b});\n    } else if (t == 1) {\n      left++;\n    } else {\n    \
    \  int x;\n      std::cin >> x;\n      mint_p func = segt.query(left, right);\n\
    \      std::cout << func.first * mint{x} + func.second << '\\n';\n    }\n  }\n\
    }\n\nint main() {\n  std::cin.tie(0);\n  std::ios_base::sync_with_stdio(false);\n\
    \  // aoj_min();\n  // aoj_sum();\n  // yosupo_static_rmq();\n  // yosupo_rsq();\n\
    \  // yosupo_composite();\n  yosupo_que_composite();\n  return 0;\n}"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: c++-library/segment_tree.cpp
  requiredBy: []
  timestamp: '2020-09-08 04:11:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: c++-library/segment_tree.cpp
layout: document
redirect_from:
- /library/c++-library/segment_tree.cpp
- /library/c++-library/segment_tree.cpp.html
title: c++-library/segment_tree.cpp
---
