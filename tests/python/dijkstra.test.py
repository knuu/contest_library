# verify-helper: PROBLEM https://judge.yosupo.jp/problem/shortest_path
import sys

from python_library.graph.dijkstra import ShortestPath

input = sys.stdin.buffer.readline


def yosupo_sp():
    N, M, start, goal = map(int, input().split())
    g = Graph(N)
    for _ in range(M):
        a, b, c = map(int, input().split())
        g.add_edge(a, b, c)
    sp = ShortestPath(g, 10**18)
    sp.dijkstra(start, goal)
    if sp.dist[goal] == sp.INF:
        print(-1)
    else:
        path = sp.getPath(goal)
        print(sp.dist[goal], len(path) - 1)
        for s, t in zip(path, path[1:]):
            print(s, t)


if __name__ == "__main__":
    yosupo_sp()