# verify-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C
# @import python_library/graph/scc.py
import sys

sys.path.insert(0, ".")
input = sys.stdin.buffer.readline
sys.setrecursionlimit(6 * 10 ** 5)

from python_library.graph.scc import StronglyConnectedComponets


def main() -> None:
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
    main()
