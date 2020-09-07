---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"c++-library/combination.cpp\"\ntemplate <typename T>\nT\
    \ powmod(T n, T k, T mod) {\n  if (k == 0) {\n    return 1;\n  } else if (k %\
    \ 2 == 0) {\n    return powmod(n * n % mod, k / 2, mod);\n  } else {\n    return\
    \ n * powmod(n, k-1, mod) % mod;\n  }\n}\n\ntemplate <typename T>\nT inv(T x,\
    \ T mod) {\n  return powmod(x, mod-2, mod);\n}\n\ntemplate <typename T>\nT comb(T\
    \ n, T k, T mod) {\n  assert (0 <= k && k <= n);\n  T ret = 1;\n  for (T i = 0;\
    \ i < k; i++) {\n    ret *= n - i;\n    ret %= mod;\n    ret *= inv(i+1);\n  \
    \  ret %= mod;\n  }\n  return ret;\n}\n"
  code: "template <typename T>\nT powmod(T n, T k, T mod) {\n  if (k == 0) {\n   \
    \ return 1;\n  } else if (k % 2 == 0) {\n    return powmod(n * n % mod, k / 2,\
    \ mod);\n  } else {\n    return n * powmod(n, k-1, mod) % mod;\n  }\n}\n\ntemplate\
    \ <typename T>\nT inv(T x, T mod) {\n  return powmod(x, mod-2, mod);\n}\n\ntemplate\
    \ <typename T>\nT comb(T n, T k, T mod) {\n  assert (0 <= k && k <= n);\n  T ret\
    \ = 1;\n  for (T i = 0; i < k; i++) {\n    ret *= n - i;\n    ret %= mod;\n  \
    \  ret *= inv(i+1);\n    ret %= mod;\n  }\n  return ret;\n}\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: c++-library/combination.cpp
  requiredBy: []
  timestamp: '2019-04-11 03:52:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: c++-library/combination.cpp
layout: document
redirect_from:
- /library/c++-library/combination.cpp
- /library/c++-library/combination.cpp.html
title: c++-library/combination.cpp
---
