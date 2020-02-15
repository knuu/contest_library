from collections import deque

from python_library.graph.graph import Graph


class HeavyLightDecomposition:
    def __init__(self, g: Graph, root: int = 0, need_subtree: bool = False) -> None:
        self.g = g
        self.vid, self.head = [-1] * g.V, [0] * g.V
        self.heavy, self.parent = [-1] * g.V, [0] * g.V
        self.dfs(root)
        if not need_subtree:
            self.bfs(root)
        else:
            self.tail = [0] * g.V
            self.dfs2(root)

    def dfs(self, root=-1):
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
        k, que = 0, deque([root])
        while que:
            r = v = que.popleft()
            while v != -1:
                self.vid[v], self.head[v] = k, r
                k += 1
                for e in self.g.E[v]:
                    if e.dst != self.parent[v] and e.dst != self.heavy[v]:
                        que.append(e.dst)
                v = self.heavy[v]

    def dfs2(self, root: int = 0) -> None:
        stack = [(root, 0)]
        k = 0
        while stack:
            v, state = stack.pop()
            if state == 0:
                u = v
                while u != -1:
                    self.vid[u] = k
                    k += 1
                    self.head[u] = v
                    stack.append((u, 1))
                    u = self.heavy[u]
            elif state == 1:
                stack.append((v, 2))
                for child in self.g.E[v]:
                    if child.dst not in [self.parent[v], self.heavy[v]]:
                        stack.append((child.dst, 0))
            else:
                self.tail[v] = k

    def lca(self, u, v):
        while self.head[u] != self.head[v]:
            if self.vid[u] > self.vid[v]:
                u, v = v, u
            v = self.parent[self.head[v]]
        else:
            if self.vid[u] > self.vid[v]:
                u, v = v, u
        return u

    def query_path(self, u, v, one, query, merge, edge: bool = False):
        # u, v の間のパスに対するクエリを計算する
        # one は単位元、query は列に対するクエリ、merge はマージする演算
        left = right = one
        while True:
            if self.vid[u] > self.vid[v]:
                u, v = v, u
                left, right = right, left
            if self.head[u] == self.head[v]:
                break
            left = merge(query(self.vid[self.head[v]], self.vid[v] + 1), left)
            v = self.parent[self.head[v]]
        return merge(merge(query(self.vid[u] + edge, self.vid[v] + 1), left), right)
