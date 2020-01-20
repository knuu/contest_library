import collections


class MaxFlow:
    """Calculate max flow by Dinic's algorithm
       complexity: O(EV^2)
       used in GRL6A(AOJ)
    """
    class Edge:
        """edge in flow networks"""

        def __init__(self, to, cap, rev):
            self.to, self.cap, self.rev = to, cap, rev

    def __init__(self, V):
        """ V: the number of vertexes
            E: adjacency list
            source: start point
            sink: goal point
        """
        self.V = V
        self.E = [[] for _ in range(V)]

    def add_edge(self, fr, to, cap):
        self.E[fr].append(self.Edge(to, cap, len(self.E[to])))
        self.E[to].append(self.Edge(fr, 0, len(self.E[fr])-1))

    def dinic(self, source, sink, INF=10**9):
        """find max-flow"""
        maxflow = 0
        while True:
            self.bfs(source)
            if self.level[sink] < 0:
                return maxflow
            self.itr = [0] * self.V
            while True:
                flow = self.dfs(source, sink, INF)
                if flow > 0:
                    maxflow += flow
                else:
                    break

    def dfs(self, vertex, sink, flow):
        """find augmenting path"""
        if vertex == sink:
            return flow
        for i in range(self.itr[vertex], len(self.E[vertex])):
            self.itr[vertex] = i
            e = self.E[vertex][i]
            if e.cap > 0 and self.level[vertex] < self.level[e.to]:
                d = self.dfs(e.to, sink, min(flow, e.cap))
                if d > 0:
                    e.cap -= d
                    self.E[e.to][e.rev].cap += d
                    return d
        return 0

    def bfs(self, start):
        """find shortest path from start"""
        que = collections.deque()
        self.level = [-1] * self.V
        que.append(start)
        self.level[start] = 0

        while que:
            fr = que.popleft()
            for e in self.E[fr]:
                if e.cap > 0 and self.level[e.to] < 0:
                    self.level[e.to] = self.level[fr] + 1
                    que.append(e.to)


def yosupo_bi():
    L, R, M = map(int, input().split())
    source, sink = L + R, L + R + 1
    mf = MaxFlow(L + R + 2)
    for _ in range(M):
        a, b = map(int, input().split())
        mf.add_edge(a, L + b, 1)
    for i in range(L):
        mf.add_edge(source, i, 1)
    for i in range(R):
        mf.add_edge(L + i, sink, 1)
    print(mf.dinic(source, sink))

    for i in range(L):
        for e in mf.E[i]:
            if e.cap == 0 and e.to < L + R:
                print(i, e.to - L)


if __name__ == "__main__":
    yosupo_bi()
