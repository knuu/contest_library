---
data:
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "from copy import deepcopy\nfrom functools import reduce\n\n\nclass Divisor:\n\
    \    def __init__(self, n):\n        \"\"\" make divisors list and prime factorization\
    \ list of n\n            complexity: O(n^(1/2))\n            used in ProjectEuler\
    \ No.12, yukicoder No.36\n        \"\"\"\n        assert n >= 1\n        number\
    \ = n\n        if number == 1:\n            self.primeFactorization = {1: 1}\n\
    \        else:\n            self.primeFactorization = {}\n            for i in\
    \ range(2, int(n ** 0.5) + 1):\n                cnt = 0\n                while\
    \ number % i == 0:\n                    cnt += 1\n                    number //=\
    \ i\n                if cnt > 0:\n                    self.primeFactorization[i]\
    \ = cnt\n            if number > 1:\n                self.primeFactorization[number]\
    \ = 1\n\n    def primeFactors(self):\n        return deepcopy(self.primeFactorization)\n\
    \n    def numDivisors(self):\n        \"\"\" the number of divisors \"\"\"\n \
    \       if self.primeFactorization.get(1, 0) == 1:\n            return 1\n   \
    \     numDiv = 1\n        for _, cnt in self.primeFactorization.items():\n   \
    \         numDiv *= cnt + 1\n        return numDiv\n\n    def sumDivisors(self):\n\
    \        return reduce(\n            lambda x, y: x * y,\n            [\n    \
    \            sum(p ** i for i in range(n + 1))\n                for p, n in self.primeFactorization.items()\n\
    \            ],\n        )\n\n\ndef divisorsList(n):\n    assert n >= 1\n    divsList\
    \ = []\n    for i in range(1, int(n ** 0.5) + 1):\n        if n % i == 0:\n  \
    \          divsList.append(i)\n            if n // i != i:\n                divsList.append(n\
    \ // i)\n    return sorted(divsList)\n\n\ndef yosupo():\n    # https://judge.yosupo.jp/problem/factorize\n\
    \    Q = int(input())\n    for _ in range(Q):\n        a = int(input())\n    \
    \    if a == 1:\n            print(0)\n            continue\n        pf = Divisor(a)\n\
    \        ans = []\n        for k in sorted(pf.primeFactorization):\n         \
    \   ans.extend([k] * pf.primeFactorization[k])\n        print(len(ans), *ans)\n\
    \n\nif __name__ == \"__main__\":\n    yosupo()\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith:
  - icon: ':x:'
    path: tests/python/prime_factorization.test.py
    title: tests/python/prime_factorization.test.py
  isVerificationFile: false
  path: python_library/math/divisor.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_ALL_WA
  verificationStatusIcon: ':x:'
  verifiedWith:
  - tests/python/prime_factorization.test.py
documentation_of: python_library/math/divisor.py
layout: document
redirect_from:
- /library/python_library/math/divisor.py
- /library/python_library/math/divisor.py.html
title: python_library/math/divisor.py
---
