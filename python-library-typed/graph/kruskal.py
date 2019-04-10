from typing import List, TypeVar, Generic, Tuple
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
        self.edge_size: int = 0

    def add_edge(self, src: int, dst: int, weight: T) -> None:
        self.E[src].append(Edge(dst, weight))
        self.edge_size += 1


class UnionFindTree:
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


class MinimumSpanningTree(Generic[T]):
    def __init__(self, G: Graph) -> None:
        self.G = G

    def run(self) -> None:
        edges: List[Tuple[T, int, int]] = []
        for v1 in range(self.G.V):
            for e in self.G.E[v1]:
                v2: int = e.dst
                if v1 < v2:
                    edges.append((e.weight, v1, v2))
        edges.sort(reverse=True)

        self.mincost: T = 0
        self.minSpanningTree: Graph[T] = Graph(self.G.V)
        uf: UnionFindTree = UnionFindTree(self.G.V)

        while self.minSpanningTree.edge_size < self.G.V - 1:
            cost, v1, v2 = edges.pop()
            if not uf.same(v1, v2):
                self.mincost += cost
                uf.unite(v1, v2)
                self.minSpanningTree.add_edge(v1, v2, cost)
                self.minSpanningTree.add_edge(v2, v1, cost)

    def minCost(self) -> T:
        return self.mincost

    def getMinSpanningTree(self) -> Graph[T]:
        return self.minSpanningTree
