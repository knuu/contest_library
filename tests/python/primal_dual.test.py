# verify-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B
# @import python_library/graph/primal_dual.py
import sys

sys.path.insert(0, ".")
input = sys.stdin.buffer.readline

from python_library.graph.primal_dual import MinCostFlow


def main() -> None:
    V, E, F = map(int, input().split())
    mcf = MinCostFlow(V)
    for _ in range(E):
        u, v, c, d = map(int, input().split())
        mcf.add_edge(u, v, c, d)
    print(mcf.run(0, V - 1, F))


if __name__ == "__main__":
    main()
