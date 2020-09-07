---
data:
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "from typing import List\n\nclass Prime:\n    \"\"\" make prime numbers lists\n\
    \        complexity: O(n^(1/2))\n        used in AOJ0202\n    \"\"\"\n\n    def\
    \ __init__(self, n: int) -> None:\n        assert(n >= 1)\n        self.is_prime\
    \ = [True for _ in range(n+1)]\n        self.primeList: List[int] = []\n     \
    \   self.is_prime[0] = self.is_prime[1] = False\n        for i in range(2, int(pow(n,\
    \ 0.5))+1):\n            if self.is_prime[i] == True:\n                self.primeList.append(i)\n\
    \                for j in range(2*i, n+1, i):\n                    self.is_prime[j]\
    \ = False\n        for i in range(int(pow(n, 0.5))+1, n+1):\n            if self.is_prime[i]\
    \ == True:\n                self.primeList.append(i)\n\n    def isPrime(self,\
    \ n: int) -> bool:\n        return self.is_prime[n]\n\n    def nthPrime(self,\
    \ n: int) -> int:\n        return self.primeList[n-1]\n\n\ndef miller_rabin(n:\
    \ int) -> bool:\n    \"\"\" primality Test\n        if n < 3,825,123,056,546,413,051,\
    \ it is enough to test\n        a = 2, 3, 5, 7, 11, 13, 17, 19, and 23.\n    \
    \    Complexity: O(log^3 n)\n    \"\"\"\n    assert(n >= 1)\n    if n == 2:\n\
    \        return True\n    if n <= 1 or not n & 1:\n        return False\n\n  \
    \  primes = [2, 3, 5, 7, 11, 13, 17, 19, 23]\n\n    d = n - 1\n    s = 0\n   \
    \ while not d & 1:\n        d >>= 1\n        s += 1\n\n    for prime in primes:\n\
    \        if prime >= n:\n            continue\n        x = pow(prime, d, n)\n\
    \        if x == 1:\n            continue\n        for r in range(s):\n      \
    \      if x == n - 1:\n                break\n            if r + 1 == s:\n   \
    \             return False\n            x = x * x % n\n    return True\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: python_library_typed/math/prime.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: python_library_typed/math/prime.py
layout: document
redirect_from:
- /library/python_library_typed/math/prime.py
- /library/python_library_typed/math/prime.py.html
title: python_library_typed/math/prime.py
---
