---
data:
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "from copy import deepcopy\nfrom functools import reduce\nfrom typing import\
    \ Dict, List\n\n\nclass Divisor:\n    \"\"\" make divisors list and prime factorization\
    \ list of n\n        complexity: O(n^(1/2))\n        used in ProjectEuler No.12,\
    \ yukicoder No.36\n    \"\"\"\n    def __init__(self, n: int) -> None:\n     \
    \   assert(n >= 1)\n        number = n\n        if number == 1:\n            self.primeFactorization\
    \ = {1: 1}\n        else:\n            self.primeFactorization = {}\n        \
    \    for i in range(2, int(n**0.5)+1):\n                cnt = 0\n            \
    \    while number % i == 0:\n                    cnt += 1\n                  \
    \  number //= i\n                if cnt > 0:\n                    self.primeFactorization[i]\
    \ = cnt\n            if number > 1:\n                self.primeFactorization[number]\
    \ = 1\n\n    def primeFactors(self) -> Dict[int, int]:\n        return deepcopy(self.primeFactorization)\n\
    \n    def numDivisors(self) -> int:\n        \"\"\" the number of divisors \"\"\
    \"\n        if self.primeFactorization.get(1, 0) == 1:\n            return 1\n\
    \        numDiv = 1\n        for _, cnt in self.primeFactorization.items():\n\
    \            numDiv *= cnt+1\n        return numDiv\n\n    def sumDivisors(self)\
    \ -> int:\n        return reduce(lambda x, y: x * y, [sum(p**i for i in range(n+1))\
    \ for p, n in self.primeFactorization.items()])\n\n\ndef divisorsList(n: int)\
    \ -> List[int]:\n    assert(n >= 1)\n    divsList = []\n    for i in range(1,\
    \ int(n**0.5)+1):\n        if n % i == 0:\n            divsList.append(i)\n  \
    \          if n // i != i:\n                divsList.append(n//i)\n    return\
    \ sorted(divsList)\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: python_library_typed/math/divisor.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: python_library_typed/math/divisor.py
layout: document
redirect_from:
- /library/python_library_typed/math/divisor.py
- /library/python_library_typed/math/divisor.py.html
title: python_library_typed/math/divisor.py
---
