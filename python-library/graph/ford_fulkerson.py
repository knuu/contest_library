class FordFulkerson:
    """Ford-Fulkerson Algorithm: find max-flow
       complexity: O(FE) (F: max flow)
       used in GRL6A(AOJ)
    """
    class edge:
        def __init__(self, to, cap, rev):
            self.to, self.cap, self.rev = to, cap, rev

    def __init__(self, V, E, source, sink):
        """ V: the number of vertexes
            E: adjacency list
            source: start point
            sink: goal point
        """
        self.V = V
        self.E = [[] for _ in range(V)]
        for fr in range(V):
            for to, cap in E[fr]:
                self.E[fr].append(self.edge(to, cap, len(self.E[to])))
                self.E[to].append(self.edge(fr, 0, len(self.E[fr])-1))
        self.maxflow = self.ford_fulkerson(source, sink)

    def ford_fulkerson(self, source, sink, INF=10**9):
        """find max-flow"""
        maxflow = 0
        while True:
            self.used = [False] * self.V
            flow = self.dfs(source, sink, INF)
            if flow == 0:
                return maxflow
            else:
                maxflow += flow

    def dfs(self, vertex, sink, flow):
        """find augmenting path"""
        if vertex == sink:
            return flow
        self.used[vertex] = True
        for e in self.E[vertex]:
            if not self.used[e.to] and e.cap > 0:
                d = self.dfs(e.to, sink, min(flow, e.cap))
                if d > 0:
                    e.cap -= d
                    self.E[e.to][e.rev].cap += d
                    return d
        return 0
