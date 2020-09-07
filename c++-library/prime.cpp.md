---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"c++-library/prime.cpp\"\nstruct Prime {\n  vector<bool>\
    \ sieve;\n  vector<int> primes;\n  Prime(int N) {\n    assert(N >= 1);\n    sieve.resize(N+1,\
    \ true);\n    sieve[0] = sieve[1] = false;\n    for (int i = 2; i <= N; i++) {\n\
    \      if (sieve[i]) {\n        primes.push_back(i);\n        for (int j = 2 *\
    \ i; j <= N; j += i) sieve[j] = false;\n      }\n    }\n  }\n};\n"
  code: "struct Prime {\n  vector<bool> sieve;\n  vector<int> primes;\n  Prime(int\
    \ N) {\n    assert(N >= 1);\n    sieve.resize(N+1, true);\n    sieve[0] = sieve[1]\
    \ = false;\n    for (int i = 2; i <= N; i++) {\n      if (sieve[i]) {\n      \
    \  primes.push_back(i);\n        for (int j = 2 * i; j <= N; j += i) sieve[j]\
    \ = false;\n      }\n    }\n  }\n};\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: c++-library/prime.cpp
  requiredBy: []
  timestamp: '2019-04-11 03:52:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: c++-library/prime.cpp
layout: document
redirect_from:
- /library/c++-library/prime.cpp
- /library/c++-library/prime.cpp.html
title: c++-library/prime.cpp
---
