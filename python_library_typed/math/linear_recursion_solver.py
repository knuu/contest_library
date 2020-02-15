from copy import deepcopy
from typing import List


def linear_recursion_solver(a: List[int], x: List[int], k: int, e0: int = 0, e1: int = 1) -> int:
    def rec(k: int) -> List[int]:
        c = [e0] * n
        if k < n:
            c[k] = e1
            return c[:]
        b = rec(k // 2)
        t = [e0] * (2 * n + 1)
        for i in range(n):
            for j in range(n):
                t[i + j + (k & 1)] += b[i] * b[j]
        for i in reversed(range(n, 2*n)):
            for j in range(n):
                t[i - n + j] += a[j] * t[i]
        for i in range(n):
            c[i] = t[i]
        return c[:]
    n = len(a)
    c = rec(k)
    return sum(ci * xi for ci, xi in zip(c, x))

assert(linear_recursion_solver([1, 2, 3], [6, 5, 4], 10) == 220696)
