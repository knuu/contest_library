# verify-helper: PROBLEM https://judge.yosupo.jp/problem/maximum_independent_set
# @import python_library/graph/maximum_independet_set.py
import sys

sys.path.insert(0, ".")
input = sys.stdin.buffer.readline

from python_library.graph.maximum_independet_set import maximum_independet_set


def main() -> None:
    N, M = map(int, input().split())
    adj_mat = [0] * N
    for _ in range(M):
        u, v = map(int, input().split())
        adj_mat[u] |= 1 << v
        adj_mat[v] |= 1 << u
    size, mis = maximum_independet_set(0, 0, adj_mat)
    print(size)
    print(*[i for i in range(N) if mis >> i & 1])


if __name__ == "__main__":
    main()
