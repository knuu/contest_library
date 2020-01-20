#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

template <typename T>
struct Int {
  using type = T;

  static type identity_zero() { return T(0); }
  static type identity_one() { return T(1); }
};

template <std::uint_fast64_t Modulus = 1'000'000'007>
class ModInt {
  using u64 = std::uint_fast64_t;

 public:
  using type = ModInt;

  u64 a;

  constexpr ModInt(const u64 x = 0) noexcept : a(x % Modulus) {}
  constexpr u64 &value() noexcept { return a; }
  constexpr const u64 &value() const noexcept { return a; }
  constexpr ModInt operator+(const ModInt rhs) const noexcept {
    return ModInt(*this) += rhs;
  }
  constexpr ModInt operator*(const ModInt rhs) const noexcept {
    return ModInt(*this) *= rhs;
  }
  constexpr ModInt &operator+=(const ModInt rhs) noexcept {
    a += rhs.a;
    if (a >= Modulus) {
      a -= Modulus;
    }
    return *this;
  }

  constexpr ModInt &operator*=(const ModInt rhs) noexcept {
    a = a * rhs.a % Modulus;
    return *this;
  }

  friend constexpr std::ostream &operator<<(std::ostream &os,
                                            const ModInt &x) noexcept {
    return os << x.a;
  }

  static ModInt identity_zero() { return ModInt(0); }
  static ModInt identity_one() { return ModInt(1); }
};

template <typename Semiring>
struct Matrix {
  using T = typename Semiring::type;
  size_t n_row, n_col;
  T zero = Semiring::identity_zero(), one = Semiring::identity_one();
  std::vector<std::vector<T>> data;

  Matrix() {}
  Matrix(size_t n, size_t m)
      : n_row(n), n_col(m), data(n, std::vector<T>(m, zero)) {}
  Matrix(size_t n) : n_row(n), n_col(n), data(n, std::vector<T>(n, zero)) {}
  Matrix(std::vector<std::vector<T>> &arr) : n_row(arr.size()) {
    n_col = arr.size() ? arr[0].size() : 0;
    data.resize(n_row);
    for (size_t row = 0; row < n_row; row++) data[row] = arr[row];
  }

  inline const std::vector<T> &operator[](const int k) const {
    return data.at(k);
  }
  inline std::vector<T> &operator[](const int k) { return data.at(k); }

  static Matrix<Semiring> identity(size_t n) {
    Matrix<Semiring> mat(n);
    for (size_t i = 0; i < n; i++) mat[i][i] = Semiring::identity_one();
    return mat;
  }
};

template <typename Semiring>
Matrix<Semiring> operator*(const Matrix<Semiring> &A,
                           const Matrix<Semiring> &B) {
  size_t n = A.n_row, m = B.n_col, p = A.n_col;
  assert(p == B.n_row);
  Matrix<Semiring> C(n, m);
  for (size_t i = 0; i < n; i++)
    for (size_t j = 0; j < m; j++)
      for (size_t k = 0; k < p; k++) C[i][j] = (C[i][j] + A[i][k] * B[k][j]);
  return C;
}

void aoj() {
  // https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/all/ITP1_7_D
  int N, M, L;
  std::cin >> N >> M >> L;
  Matrix<Int<long long>> mat1(N, M), mat2(M, L);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) std::cin >> mat1.data[i][j];
  }
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < L; j++) std::cin >> mat2.data[i][j];
  }
  Matrix<Int<long long>> res = mat1 * mat2;
  for (size_t i = 0; i < res.n_row; i++) {
    for (size_t j = 0; j < res.n_col; j++) {
      std::cout << res.data[i][j] << (j + 1 == res.n_col ? '\n' : ' ');
    }
  }
}

void example() {
  Matrix<ModInt<>> mat(2);
  mat[0][0] = 1, mat[0][1] = 2, mat[1][0] = 3, mat[1][1] = 4;
  Matrix<ModInt<>> res = mat * mat;
  for (size_t i = 0; i < res.n_row; i++) {
    for (size_t j = 0; j < res.n_col; j++) {
      std::cout << res[i][j] << (j + 1 == res.n_col ? '\n' : ' ');
    }
  }
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);
  // aoj();
  example();
  return 0;
}