# verify-helper: PROBLEM https://judge.yosupo.jp/problem/unionfind
import sys

from python_library.data_structures.unionfind import UnionFindTree

input = sys.stdin.buffer.readline


def main() -> None:
    N, Q = map(int, input().split())
    uft = UnionFindTree(N)
    ans = []
    for _ in range(Q):
        t, u, v = map(int, input().split())
        if t == 0:
            uft.unite(u, v)
        else:
            ans.append(int(uft.is_same(u, v)))
    print(*ans, sep="\n")


if __name__ == "__main__":
    main()
