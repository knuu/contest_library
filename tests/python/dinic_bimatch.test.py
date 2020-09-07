# verify-helper: PROBLEM https://judge.yosupo.jp/problem/bipartitematching
# @import python_library/graph/dinic.py
import sys

sys.path.insert(0, ".")
input = sys.stdin.buffer.readline

from python_library.graph.dinic import MaxFlow


def main() -> None:
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
    print(mf.run(source, sink))

    for i in range(L):
        for e in mf.E[i]:
            if e.cap == 0 and e.to < L + R:
                print(i, e.to - L)


if __name__ == "__main__":
    main()
