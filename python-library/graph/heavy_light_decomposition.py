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


class HeavyLightDecomposition:
    def __init__(self, g, root=0):
        self.g = g
        self.vid, self.head, self.heavy, self.parent = [0] * g.V, [-1] * g.V, [-1] * g.V, [0] * g.V
        self.dfs(root)
        self.bfs(root)

    def dfs(self, root=0):
        stack = [(root, -1, False)]
        sub, max_sub = [1] * self.g.V, [(0, -1)] * self.g.V
        while stack:
            v, par, flag = stack.pop()
            if not flag:
                self.parent[v] = par
                stack.append((v, par, True))
                stack.extend((e.dst, v, False) for e in self.g.E[v] if e.dst != par)
            else:
                if par != -1:
                    sub[par] += sub[v]
                    max_sub[par] = max(max_sub[par], (sub[v], v))
                self.heavy[v] = max_sub[v][1]

    def bfs(self, root=0):
        from collections import deque
        k, que = 0, deque([root])
        while que:
            r = v = que.popleft()
            while v != -1:
                self.vid[v], self.head[v] = k, r
                for e in self.g.E[v]:
                    if e.dst != self.parent[v] and e.dst != self.heavy[v]:
                        que.append(v)
                k += 1
                v = self.heavy[v]

    def lca(self, u, v):
        while self.head[u] != self.head[v]:
            if self.vid[u] > self.vid[v]:
                u, v = v, u
            v = self.parent[self.head[v]]
        else:
            if self.vid[u] > self.vid[v]:
                u, v = v, u
        return u
