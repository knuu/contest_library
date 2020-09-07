# verify-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
import sys

from python_library.graph.dinic import MaxFlow

input = sys.stdin.buffer.readline


def main() -> None:
    V, E = map(int, input().split())
    mf = MaxFlow(V)
    for _ in range(E):
        mf.add_edge(*map(int, input().split()))
    print(mf.run(0, V - 1))


if __name__ == "__main__":
    main()
