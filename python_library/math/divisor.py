from copy import deepcopy
from functools import reduce


class Divisor:
    def __init__(self, n):
        """ make divisors list and prime factorization list of n
            complexity: O(n^(1/2))
            used in ProjectEuler No.12, yukicoder No.36
        """
        assert n >= 1
        number = n
        if number == 1:
            self.primeFactorization = {1: 1}
        else:
            self.primeFactorization = {}
            for i in range(2, int(n ** 0.5) + 1):
                cnt = 0
                while number % i == 0:
                    cnt += 1
                    number //= i
                if cnt > 0:
                    self.primeFactorization[i] = cnt
            if number > 1:
                self.primeFactorization[number] = 1

    def primeFactors(self):
        return deepcopy(self.primeFactorization)

    def numDivisors(self):
        """ the number of divisors """
        if self.primeFactorization.get(1, 0) == 1:
            return 1
        numDiv = 1
        for _, cnt in self.primeFactorization.items():
            numDiv *= cnt + 1
        return numDiv

    def sumDivisors(self):
        return reduce(
            lambda x, y: x * y,
            [
                sum(p ** i for i in range(n + 1))
                for p, n in self.primeFactorization.items()
            ],
        )


def divisorsList(n):
    assert n >= 1
    divsList = []
    for i in range(1, int(n ** 0.5) + 1):
        if n % i == 0:
            divsList.append(i)
            if n // i != i:
                divsList.append(n // i)
    return sorted(divsList)


def yosupo():
    # https://judge.yosupo.jp/problem/factorize
    Q = int(input())
    for _ in range(Q):
        a = int(input())
        if a == 1:
            print(0)
            continue
        pf = Divisor(a)
        ans = []
        for k in sorted(pf.primeFactorization):
            ans.extend([k] * pf.primeFactorization[k])
        print(len(ans), *ans)


if __name__ == "__main__":
    yosupo()
