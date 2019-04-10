from typing import List


class Graph_AdjMat:
    def __init__(self, V: int, init: int = 10**9) -> None:
        self.V: int = V
        self.E: List[List[int]] = [[init] * V for _ in range(V)]

    def add_edge(self, src: int, dst: int, weight: int) -> None:
        self.E[src][dst] = weight


class WarshallFloyd():
    def __init__(self, G: Graph_AdjMat, INF: int = 10**9) -> None:
        self.G: Graph_AdjMat = G
        self.INF: int = INF
        self.distance: List[List[int]] = [[self.INF] * G.V for _ in range(G.V)]
        for i in range(G.V):
            self.distance[i][i] = 0
        for fr in range(G.V):
            for to in range(G.V):
                self.distance[fr][to] = G.E[fr][to]

    def run(self) -> None:
        for k in range(self.G.V):
            for i in range(self.G.V):
                for j in range(self.G.V):
                    if self.distance[i][k] != self.INF and \
                       self.distance[k][j] != self.INF:
                        self.distance[i][j] \
                            = min(self.distance[i][j],
                                  self.distance[i][k] + self.distance[k][j])

    def hasNegativeCycle(self) -> bool:
        for i in range(self.G.V):
            if self.distance[i][i] < 0:
                return True
        return False
