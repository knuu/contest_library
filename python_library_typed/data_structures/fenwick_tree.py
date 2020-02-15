import math
from typing import List


class FenwickTree1:
    """
    FenwickTree(Binary Indexed Tree)
    total number: n
    queries:
    1. add(i, val): add val to i-th value
    2. sum(n): sum(bit[1] + ... + bit[n])
    complexity: O(log n)

    Self-balancing binary search tree or Segment Tree can do the same,
    it takes longer to program and complexity also increases.
    Thanks: http://hos.ac/slides/20140319_bit.pdf

    used in ARC031 C, indeednow finalB E
    """
    def __init__(self, a_list: List[int]) -> None:
        # 1-index
        self.N: int = len(a_list)
        self.bit: List[int] = a_list[:]
        for i in range(1, self.N):
            self.bit[i + (i & -i)] += self.bit[i]

    def add(self, idx: int, val: int) -> None:
        while idx <= self.N:
            self.bit[idx] += val
            idx += idx & -idx

    def sum(self, n: int) -> int:
        ret: int = 0
        while n > 0:
            ret += self.bit[n]
            n -= n & -n
        return ret


class FenwickTree:
    def __init__(self, a_list: List[int]) -> None:
        # 0-indexed
        self.N: int = len(a_list)
        self.bit: List[int] = a_list[:]
        for _ in range(self.N, 1 << (math.ceil(math.log(self.N, 2)))):
            self.bit.append(0)
        for i in range(self.N-1):
            self.bit[i | (i+1)] += self.bit[i]

    def add(self, i: int, val: int) -> None:
        while i < self.N:
            self.bit[i] += val
            i |= i + 1

    def sum(self, n: int) -> int:
        ret: int = 0
        while n >= 0:
            ret += self.bit[n]
            n = (n & (n + 1)) - 1
        return ret
