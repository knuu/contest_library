def solve_discrete_logarithm(g: int, y: int, m: int) -> int:
    """find x >= 0 s.t. g^x≡y (mod m) by baby-step giant-step
    """
    if m == 1:
        return 0
    if y == 1:
        return 0
    if g == 0 and y == 0:
        return 1

    sqrt_m = int(pow(m, 0.5) + 100)

    # Baby-step
    memo = {}
    baby = 1
    for b in range(sqrt_m):
        if baby == y:
            return b
        memo[baby * y % m] = b
        baby = baby * g % m

    # Giant-step
    giant = 1
    for a in range(1, sqrt_m + 3):
        giant = giant * baby % m
        b = memo.get(giant, -1)
        if b >= 0:
            x = a * sqrt_m - b
            return x if pow(g, x, m) == y else -1
    return -1
