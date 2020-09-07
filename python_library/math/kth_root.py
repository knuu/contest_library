def kth_root(n: int, k: int) -> int:
    ret = int(pow(n, 1/k))
    while pow(ret, k) > n:
        ret -= 1
    while pow(ret + 1, k) <= n:
        ret += 1
    return ret
