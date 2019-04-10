from typing import List, TypeVar, Generic, Type, Any
# WeightType = Union[int, float]
WeightType = TypeVar("WeightType", int, float)


class Edge(Generic[WeightType]):
    def __init__(self, src: int, dst: int) -> None:
        self.src: int = src
        self.dst: int = dst


class WeightedEdge(Edge[WeightType]):
    def __init__(self, src: int, dst: int, weight: WeightType) -> None:
        self.src: int = src
        self.dst: int = dst
        self.weight: WeightType = weight


class ResidualEdge(Edge[WeightType]):
    def __init__(self, src: int, dst: int, cap: WeightType) -> None:
        self.src: int = src
        self.dst: int = dst
        self.cap: WeightType = cap
        self.rev: int

    def reverse(self) -> "ResidualEdge":
        return ResidualEdge(self.dst, self.src, 0)


# EdgeType = Union[Edge, WeightedEdge, ResidualEdge]
EdgeType = TypeVar("EdgeType", Edge, WeightedEdge, ResidualEdge)


class Graph(Generic[WeightType, EdgeType]):
    def __init__(self, n: int, EdgeClass: Type[EdgeType]) -> None:
        pass

    def add_edge(self, *args: Any) -> None:
        pass

    def add_undirected_edge(self, *args: Any) -> None:
        pass


class AdjacencyList(Graph[WeightType, EdgeType]):
    def __init__(self, n: int, EdgeClass: Type[EdgeType]) -> None:
        self._graph: List[List[EdgeType]] = [[] for _ in range(n)]
        self.EdgeClass: Type[EdgeType] = EdgeClass

    def add_edge(self, *args: Any) -> None:
        edge: EdgeType = self.EdgeClass(*args)
        self._graph[edge.src].append(edge)

    def add_undirected_edge(self, *args: Any) -> None:
        edge: EdgeType = self.EdgeClass(*args)
        self._graph[edge.src].append(edge)
        edge.src, edge.dst = edge.dst, edge.src
        self._graph[edge.src].append(edge)

    def __getitem__(self, key: int) -> List[EdgeType]:
        return self._graph[key]


class ResidualGraph(AdjacencyList[WeightType, ResidualEdge]):
    def __init__(self, n: int) -> None:
        super().__init__(n, ResidualEdge)

    def add_edge(self, *args: Any) -> None:
        edge: ResidualEdge = self.EdgeClass(*args)
        edge.rev = len(self._graph[edge.dst])
        self._graph[edge.src].append(edge)
        rev: ResidualEdge = edge.reverse()
        rev.rev = len(self._graph[rev.dst]) - 1
        self._graph[edge.src].append(rev)
