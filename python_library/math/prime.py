class Prime:
    """ make prime numbers lists
        complexity: O(n^(1/2))
        used in AOJ0202
    """

    def __init__(self, n):
        assert n >= 1
        self.is_prime = [True for _ in range(n + 1)]
        self.primeList = []
        self.is_prime[0] = self.is_prime[1] = False
        for i in range(2, int(pow(n, 0.5)) + 1):
            if self.is_prime[i]:
                self.primeList.append(i)
                for j in range(2 * i, n + 1, i):
                    self.is_prime[j] = False
        for i in range(int(pow(n, 0.5)) + 1, n + 1):
            if self.is_prime[i]:
                self.primeList.append(i)

    def isPrime(self, n):
        return self.is_prime[n]

    def nthPrime(self, n):
        return self.primeList[n - 1]


def miller_rabin(n):
    """ primality Test
        if n < 3,825,123,056,546,413,051, it is enough to test
        a = 2, 3, 5, 7, 11, 13, 17, 19, and 23.
        Complexity: O(log^3 n)
    """
    assert n >= 1
    if n == 2:
        return True
    if n <= 1 or not n & 1:
        return False

    primes = [2, 3, 5, 7, 11, 13, 17, 19, 23]

    d = n - 1
    s = 0
    while not d & 1:
        d >>= 1
        s += 1

    for prime in primes:
        if prime >= n:
            continue
        x = pow(prime, d, n)
        if x == 1:
            continue
        for r in range(s):
            if x == n - 1:
                break
            if r + 1 == s:
                return False
            x = x * x % n
    return True
