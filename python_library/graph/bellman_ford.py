class BellmanFord:
    """Bellman-Ford algorithm : find the shortest path from a vertex
       Complexity: O(VE)
       used in GRL1A(AOJ)
    """

    def __init__(self, V, E, start, INF=10**9):
        """ V: the number of vertexes
            E: adjacency list
            start: start vertex
            INF: Infinity distance
        """
        self.V = V
        self.E = E
        self.bellman_ford(start, INF)

    def bellman_ford(self, start, INF):
        self.distance = [INF] * self.V  # distance from start
        self.prev = [-1] * self.V  # prev vertex of shortest path
        self.distance[start] = 0
        self.negativeCycle = False

        for i in range(self.V):
            update = False
            for fr in range(self.V):
                for to, cost in self.E[fr]:
                    if self.distance[fr] != INF and \
                       self.distance[fr] + cost < self.distance[to]:
                        self.distance[to] = self.distance[fr] + cost
                        self.prev[to] = fr
                        update = True
                        if i == self.V - 1:
                            self.negativeCycle = True
            if update:
                break

    def getPath(self, end):
        assert self.hasNegativeCycle() == False
        path = [end]
        while self.prev[end] != -1:
            end = self.prev[end]
        return path[::-1]

    def hasNegativeCycle(self):
        return self.negativeCycle
