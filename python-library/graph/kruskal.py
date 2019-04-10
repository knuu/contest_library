class MinimumSpanningTree:
    """ Kruskal's algorithm: find minimum spanning tree
        Complexity: O(E log(V))
        used in GRL2A(AOJ)
    """

    def __init__(self, V, E, start=0, INF=10**9):
        """ V: the number of vertexes
            E: adjacency list (undirected graph)
        """
        self.kruskal(V, E)

    def kruskal(self, V, E):
        edges = []
        for v1 in range(V):
            for v2, cost in E[v1]:
                if v1 < v2:
                    edges.append((cost, v1, v2))
        edges.sort(reverse=True)
        self.mincost = 0
        self.minSpanningTree = []
        uf = UnionFindTree(V)
        while len(self.minSpanningTree) < V-1:
            cost, v1, v2 = edges.pop()
            if uf.same(v1, v2) == False:
                self.mincost += cost
                uf.unite(v1, v2)
                self.minSpanningTree.append((v1, v2, cost))

    def minCost(self):
        return self.mincost

    def getMinSpanningTree(self):
        return sorted(self.minSpanningTree)
