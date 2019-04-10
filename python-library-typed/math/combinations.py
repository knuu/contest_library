mod = 10**9+7


def inv(x: int) -> int:
    return pow(x, mod - 2, mod)


def nCk(n: int, k: int) -> int:
    assert 0 <= k <= n
    k = min(k, n - k)
    ret = 1
    for i in range(k):
        ret *= n - i
        ret %= mod
        ret *= inv(i + 1)
        ret %= mod
    return ret


def nHk(n: int, k: int) -> int:
    assert 1 <= k <= n
    return nCk(n + k - 1, k - 1)
