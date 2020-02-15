import heapq
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


class Node(Generic[T]):
    def __init__(self, v: int, cost: T) -> None:
        self.v: int = v
        self.cost: T = cost

    def __lt__(self, n: 'Node') -> bool:
        return self.cost < n.cost


class ShortestPath(Generic[T]):
    def __init__(self, G: Graph[T], inf: T = 10**9) -> None:
        self.G: Graph[T] = G
        self.inf: T = inf
        self.dist: List[T] = [self.inf] * self.G.V  # distance from start
        self.prev: List[int] = [-1] * self.G.V  # prev vertex of shortest path

    def run(self, start: int, goal: int = -1) -> None:
        que: List[Node] = list()
        self.dist[start] = 0
        heapq.heappush(que, Node[T](start, 0))

        while que:
            node: Node[T] = heapq.heappop(que)
            if self.dist[node.v] < node.cost:
                continue
            if goal != -1 and node.v == goal:
                return
            for edge in self.G.E[node.v]:
                if self.dist[node.v] + edge.weight < self.dist[edge.dst]:
                    self.dist[edge.dst] = self.dist[node.v] + edge.weight
                    heapq.heappush(que, Node(edge.dst, self.dist[edge.dst]))
                    self.prev[edge.dst] = node.v

    def getPath(self, end: int) -> List[int]:
        path: List[int] = [end]
        while self.prev[end] != -1:
            end = self.prev[end]
        return path[::-1]
