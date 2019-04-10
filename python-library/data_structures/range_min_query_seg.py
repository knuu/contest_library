import math


class RangeMinimumQuery:
    """
    RangeMinimumQuery by Segment Tree
    query:
    1. update(i, val): update i-th value to val
    2. query(low, high): find minimun value in [low, high)
    time complexity: O(log n)
    space complexity: O(2n)
    used in DSL2A(AOJ)
    """
    def __init__(self, N, INF=float('inf')):
        self.N = 1 << math.ceil(math.log(N, 2))
        self.INF = INF
        self.segtree = [self.INF] * (self.N * 2 - 1)

    def update(self, i, val):
        i += self.N - 1
        self.segtree[i] = val
        while i > 0:
            i = (i - 1) // 2
            self.segtree[i] = min(self.segtree[2*i+1], self.segtree[2*i+2])

    def query(self, low, high, k=0, left=0, right=-1):
        if right == -1:
            right = self.N
        if right <= low or high <= left:
            return self.INF

        if low <= left and right <= high:
            return self.segtree[k]
        else:
            mid = (left + right) // 2
            return min(self.query(low, high, 2*k+1, left, mid),
                       self.query(low, high, 2*k+2, mid, right))
