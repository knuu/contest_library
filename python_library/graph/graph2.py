class Edge:
    def __init__(self, src, dst):
        self.src, self.dst = src, dst


class WeightedEdge(Edge):
    def __init__(self, src, dst, weight):
        self.src, self.dst, self.weight = src, dst, weight


class ResidualEdge(Edge):
    def __init__(self, src, dst, cap):
        self.src, self.dst, self.cap = src, dst, cap

    def reverse(self):
        return ResidualEdge(self.dst, self.src, 0)


class Graph:
    def __init__(self, n, EdgeClass):
        pass

    def add_edge(self, *args):
        pass

    def add_undirected_edge(self, *args):
        pass


class AdjacencyList(Graph):
    def __init__(self, n, EdgeClass):
        self._graph = [[] for _ in range(n)]
        self.EdgeClass = EdgeClass

    def add_edge(self, *args):
        edge = self.EdgeClass(*args)
        self._graph[edge.src].append(edge)

    def add_undirected_edge(self, *args):
        edge = self.EdgeClass(*args)
        self._graph[edge.src].append(edge)
        edge.src, edge.dst = edge.dst, edge.src
        self._graph[edge.src].append(edge)

    def __getitem__(self, key):
        return self._graph[key]


class ResidualGraph(AdjacencyList):
    def __init__(self, n):
        super().__init__(n, ResidualEdge)

    def add_edge(self, *args):
        edge = self.EdgeClass(*args)
        edge.rev = len(self._graph[edge.dst])
        self._graph[edge.src].append(edge)
        rev = edge.reverse()
        rev.rev = len(self._graph[rev.dst]) - 1
        self._graph[edge.src].append(rev)
