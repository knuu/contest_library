class StronglyConnectedComponets:
    def __init__(self, n: int) -> None:
        self.n = n
        self.edges = [[] for _ in range(n)]
        self.rev_edeges = [[] for _ in range(n)]
        self.vs = []
        self.order = [0] * n
        self.used = [False] * n

    def add_edge(self, from_v: int, to_v: int) -> None:
        self.edges[from_v].append(to_v)
        self.rev_edeges[to_v].append(from_v)

    def dfs(self, v) -> None:
        self.used[v] = True
        for child in self.edges[v]:
            if not self.used[child]:
                self.dfs(child)
        self.vs.append(v)

    def rdfs(self, v, k) -> None:
        self.used[v] = True
        self.order[v] = k
        for child in self.rev_edeges[v]:
            if not self.used[child]:
                self.rdfs(child, k)

    def run(self) -> int:
        self.used = [False] * self.n
        self.vs.clear()
        for v in range(self.n):
            if not self.used[v]:
                self.dfs(v)
        self.used = [False] * self.n
        k = 0
        for v in reversed(self.vs):
            if not self.used[v]:
                self.rdfs(v, k)
                k += 1
        return k


class TwoSat(StronglyConnectedComponets):
    def __init__(self, num_var: int) -> None:
        super().__init__(2 * num_var + 1)
        self.num_var = num_var
        self.ans = []

    def add_constraint(self, a: int, b: int) -> None:
        super().add_edge(self._neg(a), self._pos(b))
        super().add_edge(self._neg(b), self._pos(a))

    def _pos(self, v: int) -> int:
        return v if v > 0 else self.num_var - v

    def _neg(self, v: int) -> int:
        return self.num_var + v if v > 0 else -v

    def run(self) -> bool:
        super().run()
        self.ans.clear()
        for i in range(self.num_var):
            if self.order[i + 1] == self.order[i + self.num_var + 1]:
                return False
            self.ans.append(self.order[i + 1] > self.order[i + self.num_var + 1])
        return True
