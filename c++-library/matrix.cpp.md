---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"c++-library/matrix.cpp\"\n#include <cassert>\n#include <cstdint>\n\
    #include <iostream>\n#include <vector>\n\ntemplate <typename T>\nstruct Int {\n\
    \  using type = T;\n\n  static type identity_zero() { return T(0); }\n  static\
    \ type identity_one() { return T(1); }\n};\n\ntemplate <std::uint_fast64_t Modulus\
    \ = 1'000'000'007>\nclass ModInt {\n  using u64 = std::uint_fast64_t;\n\n public:\n\
    \  using type = ModInt;\n\n  u64 a;\n\n  constexpr ModInt(const u64 x = 0) noexcept\
    \ : a(x % Modulus) {}\n  constexpr u64 &value() noexcept { return a; }\n  constexpr\
    \ const u64 &value() const noexcept { return a; }\n  constexpr ModInt operator+(const\
    \ ModInt rhs) const noexcept {\n    return ModInt(*this) += rhs;\n  }\n  constexpr\
    \ ModInt operator*(const ModInt rhs) const noexcept {\n    return ModInt(*this)\
    \ *= rhs;\n  }\n  constexpr ModInt &operator+=(const ModInt rhs) noexcept {\n\
    \    a += rhs.a;\n    if (a >= Modulus) {\n      a -= Modulus;\n    }\n    return\
    \ *this;\n  }\n\n  constexpr ModInt &operator*=(const ModInt rhs) noexcept {\n\
    \    a = a * rhs.a % Modulus;\n    return *this;\n  }\n\n  friend constexpr std::ostream\
    \ &operator<<(std::ostream &os,\n                                            const\
    \ ModInt &x) noexcept {\n    return os << x.a;\n  }\n\n  static ModInt identity_zero()\
    \ { return ModInt(0); }\n  static ModInt identity_one() { return ModInt(1); }\n\
    };\n\ntemplate <typename Semiring>\nstruct Matrix {\n  using T = typename Semiring::type;\n\
    \  size_t n_row, n_col;\n  T zero = Semiring::identity_zero(), one = Semiring::identity_one();\n\
    \  std::vector<std::vector<T>> data;\n\n  Matrix() {}\n  Matrix(size_t n, size_t\
    \ m)\n      : n_row(n), n_col(m), data(n, std::vector<T>(m, zero)) {}\n  Matrix(size_t\
    \ n) : n_row(n), n_col(n), data(n, std::vector<T>(n, zero)) {}\n  Matrix(std::vector<std::vector<T>>\
    \ &arr) : n_row(arr.size()) {\n    n_col = arr.size() ? arr[0].size() : 0;\n \
    \   data.resize(n_row);\n    for (size_t row = 0; row < n_row; row++) data[row]\
    \ = arr[row];\n  }\n\n  inline const std::vector<T> &operator[](const int k) const\
    \ {\n    return data.at(k);\n  }\n  inline std::vector<T> &operator[](const int\
    \ k) { return data.at(k); }\n\n  static Matrix<Semiring> identity(size_t n) {\n\
    \    Matrix<Semiring> mat(n);\n    for (size_t i = 0; i < n; i++) mat[i][i] =\
    \ Semiring::identity_one();\n    return mat;\n  }\n};\n\ntemplate <typename Semiring>\n\
    Matrix<Semiring> operator*(const Matrix<Semiring> &A,\n                      \
    \     const Matrix<Semiring> &B) {\n  size_t n = A.n_row, m = B.n_col, p = A.n_col;\n\
    \  assert(p == B.n_row);\n  Matrix<Semiring> C(n, m);\n  for (size_t i = 0; i\
    \ < n; i++)\n    for (size_t j = 0; j < m; j++)\n      for (size_t k = 0; k <\
    \ p; k++) C[i][j] = (C[i][j] + A[i][k] * B[k][j]);\n  return C;\n}\n\nvoid aoj()\
    \ {\n  // https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/all/ITP1_7_D\n\
    \  int N, M, L;\n  std::cin >> N >> M >> L;\n  Matrix<Int<long long>> mat1(N,\
    \ M), mat2(M, L);\n  for (int i = 0; i < N; i++) {\n    for (int j = 0; j < M;\
    \ j++) std::cin >> mat1.data[i][j];\n  }\n  for (int i = 0; i < M; i++) {\n  \
    \  for (int j = 0; j < L; j++) std::cin >> mat2.data[i][j];\n  }\n  Matrix<Int<long\
    \ long>> res = mat1 * mat2;\n  for (size_t i = 0; i < res.n_row; i++) {\n    for\
    \ (size_t j = 0; j < res.n_col; j++) {\n      std::cout << res.data[i][j] << (j\
    \ + 1 == res.n_col ? '\\n' : ' ');\n    }\n  }\n}\n\nvoid example() {\n  Matrix<ModInt<>>\
    \ mat(2);\n  mat[0][0] = 1, mat[0][1] = 2, mat[1][0] = 3, mat[1][1] = 4;\n  Matrix<ModInt<>>\
    \ res = mat * mat;\n  for (size_t i = 0; i < res.n_row; i++) {\n    for (size_t\
    \ j = 0; j < res.n_col; j++) {\n      std::cout << res[i][j] << (j + 1 == res.n_col\
    \ ? '\\n' : ' ');\n    }\n  }\n}\n\nint main() {\n  std::cin.tie(0);\n  std::ios_base::sync_with_stdio(false);\n\
    \  // aoj();\n  example();\n  return 0;\n}\n"
  code: "#include <cassert>\n#include <cstdint>\n#include <iostream>\n#include <vector>\n\
    \ntemplate <typename T>\nstruct Int {\n  using type = T;\n\n  static type identity_zero()\
    \ { return T(0); }\n  static type identity_one() { return T(1); }\n};\n\ntemplate\
    \ <std::uint_fast64_t Modulus = 1'000'000'007>\nclass ModInt {\n  using u64 =\
    \ std::uint_fast64_t;\n\n public:\n  using type = ModInt;\n\n  u64 a;\n\n  constexpr\
    \ ModInt(const u64 x = 0) noexcept : a(x % Modulus) {}\n  constexpr u64 &value()\
    \ noexcept { return a; }\n  constexpr const u64 &value() const noexcept { return\
    \ a; }\n  constexpr ModInt operator+(const ModInt rhs) const noexcept {\n    return\
    \ ModInt(*this) += rhs;\n  }\n  constexpr ModInt operator*(const ModInt rhs) const\
    \ noexcept {\n    return ModInt(*this) *= rhs;\n  }\n  constexpr ModInt &operator+=(const\
    \ ModInt rhs) noexcept {\n    a += rhs.a;\n    if (a >= Modulus) {\n      a -=\
    \ Modulus;\n    }\n    return *this;\n  }\n\n  constexpr ModInt &operator*=(const\
    \ ModInt rhs) noexcept {\n    a = a * rhs.a % Modulus;\n    return *this;\n  }\n\
    \n  friend constexpr std::ostream &operator<<(std::ostream &os,\n            \
    \                                const ModInt &x) noexcept {\n    return os <<\
    \ x.a;\n  }\n\n  static ModInt identity_zero() { return ModInt(0); }\n  static\
    \ ModInt identity_one() { return ModInt(1); }\n};\n\ntemplate <typename Semiring>\n\
    struct Matrix {\n  using T = typename Semiring::type;\n  size_t n_row, n_col;\n\
    \  T zero = Semiring::identity_zero(), one = Semiring::identity_one();\n  std::vector<std::vector<T>>\
    \ data;\n\n  Matrix() {}\n  Matrix(size_t n, size_t m)\n      : n_row(n), n_col(m),\
    \ data(n, std::vector<T>(m, zero)) {}\n  Matrix(size_t n) : n_row(n), n_col(n),\
    \ data(n, std::vector<T>(n, zero)) {}\n  Matrix(std::vector<std::vector<T>> &arr)\
    \ : n_row(arr.size()) {\n    n_col = arr.size() ? arr[0].size() : 0;\n    data.resize(n_row);\n\
    \    for (size_t row = 0; row < n_row; row++) data[row] = arr[row];\n  }\n\n \
    \ inline const std::vector<T> &operator[](const int k) const {\n    return data.at(k);\n\
    \  }\n  inline std::vector<T> &operator[](const int k) { return data.at(k); }\n\
    \n  static Matrix<Semiring> identity(size_t n) {\n    Matrix<Semiring> mat(n);\n\
    \    for (size_t i = 0; i < n; i++) mat[i][i] = Semiring::identity_one();\n  \
    \  return mat;\n  }\n};\n\ntemplate <typename Semiring>\nMatrix<Semiring> operator*(const\
    \ Matrix<Semiring> &A,\n                           const Matrix<Semiring> &B)\
    \ {\n  size_t n = A.n_row, m = B.n_col, p = A.n_col;\n  assert(p == B.n_row);\n\
    \  Matrix<Semiring> C(n, m);\n  for (size_t i = 0; i < n; i++)\n    for (size_t\
    \ j = 0; j < m; j++)\n      for (size_t k = 0; k < p; k++) C[i][j] = (C[i][j]\
    \ + A[i][k] * B[k][j]);\n  return C;\n}\n\nvoid aoj() {\n  // https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/all/ITP1_7_D\n\
    \  int N, M, L;\n  std::cin >> N >> M >> L;\n  Matrix<Int<long long>> mat1(N,\
    \ M), mat2(M, L);\n  for (int i = 0; i < N; i++) {\n    for (int j = 0; j < M;\
    \ j++) std::cin >> mat1.data[i][j];\n  }\n  for (int i = 0; i < M; i++) {\n  \
    \  for (int j = 0; j < L; j++) std::cin >> mat2.data[i][j];\n  }\n  Matrix<Int<long\
    \ long>> res = mat1 * mat2;\n  for (size_t i = 0; i < res.n_row; i++) {\n    for\
    \ (size_t j = 0; j < res.n_col; j++) {\n      std::cout << res.data[i][j] << (j\
    \ + 1 == res.n_col ? '\\n' : ' ');\n    }\n  }\n}\n\nvoid example() {\n  Matrix<ModInt<>>\
    \ mat(2);\n  mat[0][0] = 1, mat[0][1] = 2, mat[1][0] = 3, mat[1][1] = 4;\n  Matrix<ModInt<>>\
    \ res = mat * mat;\n  for (size_t i = 0; i < res.n_row; i++) {\n    for (size_t\
    \ j = 0; j < res.n_col; j++) {\n      std::cout << res[i][j] << (j + 1 == res.n_col\
    \ ? '\\n' : ' ');\n    }\n  }\n}\n\nint main() {\n  std::cin.tie(0);\n  std::ios_base::sync_with_stdio(false);\n\
    \  // aoj();\n  example();\n  return 0;\n}"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: c++-library/matrix.cpp
  requiredBy: []
  timestamp: '2020-01-21 04:11:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: c++-library/matrix.cpp
layout: document
redirect_from:
- /library/c++-library/matrix.cpp
- /library/c++-library/matrix.cpp.html
title: c++-library/matrix.cpp
---
