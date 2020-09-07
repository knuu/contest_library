#include <cstdint>
#include <iostream>

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
