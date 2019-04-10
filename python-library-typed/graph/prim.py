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


class MinimumSpanningTree(Generic[T]):
    def __init__(self, G: Graph[T]) -> None:
        self.G: Graph[T] = G
        self.mincost: T = 0

    def run(self, start: int = 0) -> None:
        used: List[bool] = [False] * self.G.V
        que: List[Node] = []
        heapq.heappush(que, Node[T](start, 0))
        while que:
            node: Node = heapq.heappop(que)
            if used[node.v]:
                continue
            used[node.v] = True
            self.mincost += node.cost
            for edge in self.G.E[node.v]:
                heapq.heappush(que, Node[T](edge.dst, edge.weight))

    def minCost(self) -> T:
        return self.mincost
