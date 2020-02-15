from copy import deepcopy
import sys
if sys.version[0] == '2':
    range, input = xrange, raw_input


def linear_recursion_solver(a, x, k, e0=0, e1=1):
    def rec(k):
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
