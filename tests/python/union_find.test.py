# verify-helper: PROBLEM https://judge.yosupo.jp/problem/unionfind
import sys

from python_library.data_structures.unionfind import UnionFindTree

input = sys.stdin.buffer.readline


def main() -> None:
    N, Q = map(int, input().split())
    uft = UnionFindTree(N)
    for _ in range(Q):
        t, u, v = map(int, input().split())
        if t == 0:
            uft.unite(u, v)
        else:
            print(int(uft.is_same(u, v)))


if __name__ == "__main__":
    main()
