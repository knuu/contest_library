# verify-helper: PROBLEM https://judge.yosupo.jp/problem/scc
# @import python_library/graph/scc.py
import sys

sys.path.insert(0, ".")
input = sys.stdin.buffer.readline
sys.setrecursionlimit(6 * 10 ** 5)

from python_library.graph.scc import StronglyConnectedComponets


def main() -> None:
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


if __name__ == "__main__":
    main()
