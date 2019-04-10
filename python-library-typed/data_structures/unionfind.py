from typing import List


class UnionFindTree:
    """Disjoint-Set Data Structure
       Union-Find Tree
       complexity:
          init: O(n)
          find, unite, same: O(alpha(n))
       used in SRM505 div.2 900, ATC001 A, DSL1A(AOJ)
    """
    def __init__(self, N: int) -> None:
        self.par: List[int] = list(range(N))  # parent
        self.rank: List[int] = [0] * N  # depth of tree

    def find(self, x: int) -> int:
        if self.par[x] == x:
            return x
        else:
            self.par[x] = self.find(self.par[x])
            return self.par[x]

    def unite(self, x: int, y: int) -> None:
        x, y = self.find(x), self.find(y)
        if x == y:
            return
        if self.rank[x] < self.rank[y]:
            self.par[x] = y
        else:
            self.par[y] = x
            if self.rank[x] == self.rank[y]:
                self.rank[x] += 1

    def same(self, x: int, y: int) -> bool:
        return self.find(x) == self.find(y)
