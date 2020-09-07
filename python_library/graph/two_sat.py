# @import python_library/graph/scc.py
from python_library.graph.scc import StronglyConnectedComponets


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
