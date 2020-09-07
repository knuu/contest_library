# verify-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
# @import python_library/graph/dinic.py
import sys

sys.path.insert(0, ".")
input = sys.stdin.buffer.readline

from python_library.graph.dinic import MaxFlow


def main() -> None:
    V, E = map(int, input().split())
    mf = MaxFlow(V)
    for _ in range(E):
        mf.add_edge(*map(int, input().split()))
    print(mf.run(0, V - 1))


if __name__ == "__main__":
    main()
