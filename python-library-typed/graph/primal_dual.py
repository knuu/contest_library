import heapq


class MinCostFlow:
    class Edge:
        def __init__(self, to, cap, rev, cost):
            self.to, self.cap, self.rev, self.cost = to, cap, rev, cost

    def __init__(self, V):
        self.V = V
        self.E = [[] for _ in range(V)]

    def add_edge(self, fr, to, cap, cost):
        self.E[fr].append(self.Edge(to, cap, len(self.E[to]), cost))
        self.E[to].append(self.Edge(fr, 0, len(self.E[fr])-1, -cost))

    def run(self, source, sink, f, INF=10**5):
        res = 0
        h, prevv, preve = [0] * self.V, [0] * self.V, [0] * self.V
        while (f > 0):
            pque = []
            dist = [INF] * self.V
            dist[source] = 0
            heapq.heappush(pque, (0, source))
            while pque:
                cost, v = heapq.heappop(pque)
                cost = -cost
                if dist[v] < cost:
                    continue
                for i, e in enumerate(self.E[v]):
                    if e.cap > 0 and dist[v] - h[e.to] < dist[e.to] - e.cost - h[v]:
                        dist[e.to] = dist[v] + e.cost + h[v] - h[e.to]
                        prevv[e.to], preve[e.to] = v, i
                        heapq.heappush(pque, (-dist[e.to], e.to))
            if dist[sink] == INF:
                return -1
            for v in range(self.V):
                h[v] += dist[v]

            d, v = f, sink
            while v != source:
                d = min(d, self.E[prevv[v]][preve[v]].cap)
                v = prevv[v]
            f -= d
            res += d * h[sink]
            v = sink
            while v != source:
                self.E[prevv[v]][preve[v]].cap -= d
                self.E[v][self.E[prevv[v]][preve[v]].rev].cap += d
                v = prevv[v]
        return res
