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


class HeavyLightDecomposition(Generic[T]):
    def __init__(self, G: Graph[T]) -> None:
        self.G: Graph[T] = G
        self.vid: List[int] = [0] * G.V
        self.head: List[int] = [0] * G.V
        self.heavy: List[int] = [-1] * G.V
        self.parent: List[int] = [0] * G.V

    def run(self, root: int = 0) -> None:
        self.dfs(root)
        self.bfs(root)

    def dfs(self, root: int = 0) -> None:
        stack: List[Tuple[int, int, bool]] = [(root, -1, False)]
        sub: List[int] = [1] * self.G.V
        max_sub: List[Tuple[int, int]] = [(0, -1)] * self.G.V
        while stack:
            v: int
            par: int
            flag: bool
            v, par, flag = stack.pop()
            if not flag:
                self.parent[v] = par
                stack.append((v, par, True))
                stack.extend((e.dst, v, False) for e in self.G.E[v] if e.dst != par)
            else:
                if par != -1:
                    sub[par] += sub[v]
                    max_sub[par] = max(max_sub[par], (sub[v], v))
                self.heavy[v] = max_sub[v][1]

    def bfs(self, root: int = 0) -> None:
        from collections import deque
        k: int
        que: deque
        k, que = 0, deque([root])
        while que:
            r: int
            v: int
            r = v = que.popleft()
            while v != -1:
                self.vid[v], self.head[v] = k, r
                for e in self.G.E[v]:
                    if e.dst != self.parent[v] and e.dst != self.heavy[v]:
                        que.append(v)
                k += 1
                v = self.heavy[v]

    def lca(self, u: int, v: int) -> int:
        while self.head[u] != self.head[v]:
            if self.vid[u] > self.vid[v]:
                u, v = v, u
            v = self.parent[self.head[v]]
        else:
            if self.vid[u] > self.vid[v]:
                u, v = v, u
        return u
