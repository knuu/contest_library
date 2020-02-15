class Edge:
    def __init__(self, dst, weight):
        self.dst, self.weight = dst, weight

    def __lt__(self, e):
        return self.weight > e.weight


class Graph:
    def __init__(self, V):
        self.V = V
        self.E = [[] for _ in range(V)]

    def add_edge(self, src, dst, weight):
        self.E[src].append(Edge(dst, weight))
