from typing import List


class Graph_AdjMat:
    def __init__(self, V: int, init: int = 10**9) -> None:
        self.V: int = V
        self.E: List[List[int]] = [[init] * V for _ in range(V)]

    def add_edge(self, src: int, dst: int, weight: int) -> None:
        self.E[src][dst] = weight
