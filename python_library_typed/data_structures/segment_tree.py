import math
from typing import Generic, TypeVar, Callable, List

T = TypeVar("T", int, float)



class SegmentTree(Generic[T]):
    """
    Segment Tree
    query:
    1. update(i, val): update i-th value to val
    2. query(low, high): find f(value) in [low, high)
    time complexity: O(log n)
    space complexity: O(2n)
    """
    def __init__(self, N: int, f: Callable[[T, T], T], default: T) -> None:
        self.N = 1 << math.ceil(math.log(N, 2))
        self.default: T = default
        self.f: Callable[[T, T], T] = f
        self.segtree: List[T] = [self.default] * (self.N * 2 - 1)

    def update(self, i: int, val: T) -> None:
        i += self.N - 1
        self.segtree[i] = val
        while i > 0:
            i = (i - 1) // 2
            self.segtree[i] = self.f(self.segtree[2*i+1], self.segtree[2*i+2])

    def query(self, low: int, high: int, k: int = 0, left: int = 0, right: int = -1) -> T:
        if right == -1:
            right = self.N
        if right <= low or high <= left:
            return self.default

        if low <= left and right <= high:
            return self.segtree[k]
        else:
            mid = (left + right) // 2
            return self.f(self.query(low, high, 2*k+1, left, mid),
                          self.query(low, high, 2*k+2, mid, right))
