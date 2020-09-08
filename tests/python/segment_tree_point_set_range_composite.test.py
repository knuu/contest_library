# verify-helper: PROBLEM https://judge.yosupo.jp/problem/point_set_range_composite
import sys

from python_library.data_structures.segment_tree import SegmentTree

input = sys.stdin.buffer.readline


def main() -> None:
    N, Q = map(int, input().split())
    A = [tuple(map(int, input().split())) for _ in range(N)]
    mod = 998244353

    def merge(l, r, mod=mod):
        return l[0] * r[0] % mod, (l[1] * r[0] + r[1]) % mod

    segt = SegmentTree.create_from_array(A, merge, (1, 0))
    ans = []
    for _ in range(Q):
        t, a, b, c = map(int, input().split())
        if t == 0:
            segt[a] = (b, c)
        else:
            a1, a2 = segt.query(a, b)
            ans.append((a1 * c + a2) % mod)
    print(*ans, sep="\n")


if __name__ == "__main__":
    main()
