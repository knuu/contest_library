from __future__ import annotations
from typing import Generic, TypeVar, Callable, Sequence

T = TypeVar('T')


class SegmentTree(Generic[T]):
    """Segment Tree (Point Update & Range Query)

    Query
        1. update(i, val): update i-th value to val
        2. query(low, high): find f(value) in [low, high)

    Complexity
        time complexity: O(log n)
        space complexity: O(n)
    """

    def __init__(self, N: int, f: Callable[[T, T], T], default: T) -> None:
        self._N = N
        self.N = 1 << (N - 1).bit_length()
        self.default = default
        self.f = f
        self.segtree = [self.default] * ((self.N << 1) - 1)

    @classmethod
    def create_from_array(cls, arr: Sequence[T],
                          f: Callable[[T, T], T], default: T
                          ) -> SegmentTree[T]:
        N = len(arr)
        self = cls(N, f, default)
        for i in range(N):
            self.segtree[self.N - 1 + i] = arr[i]

        for i in reversed(range(self.N - 1)):
            self.segtree[i] = self.f(
                self.segtree[(i << 1) + 1], self.segtree[(i << 1) + 2]
            )
        return self

    def __getitem__(self, k: int) -> T:
        return self.segtree[self.N - 1 + k]

    def __setitem__(self, key: int, value: T) -> None:
        key += self.N - 1
        self.segtree[key] = value
        while key > 0:
            key = (key - 1) >> 1
            self.segtree[key] = self.f(
                self.segtree[(key << 1) + 1], self.segtree[(key << 1) + 2]
            )

    def __len__(self) -> int:
        return self._N

    def query(self, low: int, high: int) -> T:
        # query [l, r)
        # TODO: rewrite as __getitem__
        low, high = low + self.N, high + self.N
        left_ret, right_ret = self.default, self.default
        while low < high:
            if low & 1:
                left_ret = self.f(left_ret, self.segtree[low - 1])
                low += 1
            if high & 1:
                high -= 1
                right_ret = self.f(self.segtree[high - 1], right_ret)
            low, high = low >> 1, high >> 1
        return self.f(left_ret, right_ret)
