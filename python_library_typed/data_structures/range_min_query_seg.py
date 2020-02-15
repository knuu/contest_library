import math
from typing import List, Generic, TypeVar

T = TypeVar('T', int, float, complex)


class RangeMinimumQuery(Generic[T]):
    def __init__(self, N: int, INF: T = 10**9) -> None:
        self.N: int = 1 << math.ceil(math.log(N, 2))
        self.INF: T = INF
        self.segtree: List[T] = [self.INF] * (self.N * 2 - 1)

    def update(self, idx: int, val: int) -> None:
        idx += self.N - 1
        self.segtree[idx] = val
        while idx > 0:
            idx = (idx - 1) // 2
            self.segtree[idx] = min(self.segtree[2 * idx + 1], self.segtree[2 * idx + 2])

    def query(self, low: int, high: int, k: int = 0, left: int = 0, right: int = -1) -> T:
        if right == -1:
            right = self.N
        if right <= low or high <= left:
            return self.INF

        if low <= left and right <= high:
            return self.segtree[k]
        else:
            mid: int = (left + right) // 2
            return min(self.query(low, high, 2*k+1, left, mid),
                       self.query(low, high, 2*k+2, mid, right))
