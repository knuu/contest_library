---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"c++-library/modint.cpp\"\n#include <cstdint>\n#include <iostream>\n\
    \ntemplate <std::uint_fast64_t Modulus = 1'000'000'007>\nclass ModInt {\n  using\
    \ u64 = std::uint_fast64_t;\n\n public:\n  using type = ModInt;\n\n  u64 value;\n\
    \n  constexpr ModInt(const u64 x = 0) noexcept : value(x % Modulus) {\n    if\
    \ (value < 0) value += Modulus;\n  }\n  constexpr ModInt operator-() const noexcept\
    \ {\n    return value ? Modulus - value : 0;\n  }\n  constexpr ModInt operator+(const\
    \ ModInt rhs) const noexcept {\n    return ModInt(*this) += rhs;\n  }\n  constexpr\
    \ ModInt operator-(const ModInt rhs) const noexcept {\n    return ModInt(*this)\
    \ -= rhs;\n  }\n  constexpr ModInt operator*(const ModInt rhs) const noexcept\
    \ {\n    return ModInt(*this) *= rhs;\n  }\n  constexpr ModInt operator/(const\
    \ ModInt rhs) const noexcept {\n    return ModInt(*this) /= rhs;\n  }\n  constexpr\
    \ ModInt &operator+=(const ModInt rhs) noexcept {\n    value += rhs.value;\n \
    \   if (value >= Modulus) value -= Modulus;\n    return *this;\n  }\n  constexpr\
    \ ModInt &operator-=(const ModInt rhs) noexcept {\n    if (value < rhs.value)\
    \ value += Modulus;\n    value -= rhs.value;\n    return *this;\n  }\n  constexpr\
    \ ModInt &operator*=(const ModInt rhs) noexcept {\n    value = value * rhs.value\
    \ % Modulus;\n    return *this;\n  }\n  constexpr bool operator==(const ModInt\
    \ &r) const noexcept {\n    return value == r.value;\n  }\n  constexpr bool operator!=(const\
    \ ModInt &r) const noexcept {\n    return value != r.value;\n  }\n  constexpr\
    \ ModInt &operator/=(ModInt rhs) noexcept {\n    u64 exp = Modulus - 2;\n    while\
    \ (exp) {\n      if (exp % 2) *this *= rhs;\n      rhs *= rhs;\n      exp /= 2;\n\
    \    }\n    return *this;\n  }\n\n  friend constexpr std::ostream &operator<<(std::ostream\
    \ &os,\n                                            const ModInt &x) noexcept\
    \ {\n    return os << x.value;\n  }\n\n  static ModInt identity_zero() { return\
    \ ModInt(); }\n  static ModInt identity_one() { return ModInt(1); }\n};\n"
  code: "#include <cstdint>\n#include <iostream>\n\ntemplate <std::uint_fast64_t Modulus\
    \ = 1'000'000'007>\nclass ModInt {\n  using u64 = std::uint_fast64_t;\n\n public:\n\
    \  using type = ModInt;\n\n  u64 value;\n\n  constexpr ModInt(const u64 x = 0)\
    \ noexcept : value(x % Modulus) {\n    if (value < 0) value += Modulus;\n  }\n\
    \  constexpr ModInt operator-() const noexcept {\n    return value ? Modulus -\
    \ value : 0;\n  }\n  constexpr ModInt operator+(const ModInt rhs) const noexcept\
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
    \  static ModInt identity_one() { return ModInt(1); }\n};\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: c++-library/modint.cpp
  requiredBy: []
  timestamp: '2020-09-08 04:11:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: c++-library/modint.cpp
layout: document
redirect_from:
- /library/c++-library/modint.cpp
- /library/c++-library/modint.cpp.html
title: c++-library/modint.cpp
---
