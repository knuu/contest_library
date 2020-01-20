import sys
input = sys.stdin.buffer.readline
sys.setrecursionlimit(6 * 10 ** 5)


class StronglyConnectedComponets:
    def __init__(self, n: int) -> None:
        self.n = n
        self.edges = [[] for _ in range(n)]
        self.rev_edeges = [[] for _ in range(n)]
        self.vs = []
        self.order = [0] * n
        self.used = [False] * n

    def add_edge(self, from_v: int, to_v: int) -> None:
        self.edges[from_v].append(to_v)
        self.rev_edeges[to_v].append(from_v)

    def dfs(self, v) -> None:
        self.used[v] = True
        for child in self.edges[v]:
            if not self.used[child]:
                self.dfs(child)
        self.vs.append(v)

    def rdfs(self, v, k) -> None:
        self.used[v] = True
        self.order[v] = k
        for child in self.rev_edeges[v]:
            if not self.used[child]:
                self.rdfs(child, k)

    def run(self) -> int:
        self.used = [False] * self.n
        self.vs.clear()
        for v in range(self.n):
            if not self.used[v]:
                self.dfs(v)
        self.used = [False] * self.n
        k = 0
        for v in reversed(self.vs):
            if not self.used[v]:
                self.rdfs(v, k)
                k += 1
        return k


def yosupo():
    # https://judge.yosupo.jp/problem/scc
    N, M = map(int, input().split())
    scc = StronglyConnectedComponets(N)
    for _ in range(M):
        u, v = map(int, input().split())
        scc.add_edge(u, v)
    scc.run()
    ans_size = max(scc.order) + 1
    ans = [[] for _ in range(ans_size)]
    for i, c in enumerate(scc.order):
        ans[c].append(i)
    print(ans_size)
    for row in ans:
        print(len(row), *row)


def aoj():
    # https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C
    V, E = map(int, input().split())
    scc = StronglyConnectedComponets(V)
    for _ in range(E):
        u, v = map(int, input().split())
        scc.add_edge(u, v)
    scc.run()
    for _ in range(int(input())):
        u, v = map(int, input().split())
        print(int(scc.order[u] == scc.order[v]))


if __name__ == "__main__":
    yosupo()
    # aoj()
