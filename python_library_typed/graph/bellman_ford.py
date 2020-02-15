from typing import List, TypeVar, Generic
T = TypeVar('T', int, float)


class Edge(Generic[T]):
    def __init__(self, dst: int, weight: T) -> None:
        self.dst: int = dst
        self.weight: T = weight

    def __lt__(self, e: 'Edge') -> bool:
        return self.weight > e.weight


class Graph(Generic[T]):
    def __init__(self, V: int) -> None:
        self.V: int = V
        self.E: List[List[Edge[T]]] = [[] for _ in range(V)]

    def add_edge(self, src: int, dst: int, weight: T) -> None:
        self.E[src].append(Edge(dst, weight))


class BellmanFord(Generic[T]):
    def __init__(self, G: Graph[T]) -> None:
        self.G: Graph[T] = G

    def run(self, start: int = 0, INF: T = 10**9) -> None:
        self.distance: List[T] = [INF] * self.G.V  # distance from start
        self.prev: List[int] = [-1] * self.G.V  # prev vertex of shortest path
        self.distance[start] = 0
        self.negativeCycle: bool = False

        for i in range(self.G.V):
            update: bool = False
            for fr in range(self.G.V):
                for e in self.G.E[fr]:
                    if self.distance[fr] != INF and \
                       self.distance[fr] + e.weight < self.distance[e.dst]:
                        self.distance[e.dst] = self.distance[fr] + e.weight
                        self.prev[e.dst] = fr
                        update = True
                        if i == self.G.V - 1:
                            self.negativeCycle = True
            if update:
                break

    def getPath(self, end: int) -> List[int]:
        assert(not self.hasNegativeCycle())
        path: List[int] = [end]
        while self.prev[end] != -1:
            end = self.prev[end]
        return path[::-1]

    def hasNegativeCycle(self) -> bool:
        return self.negativeCycle
