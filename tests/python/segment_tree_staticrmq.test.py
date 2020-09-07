# verify-helper: PROBLEM https://judge.yosupo.jp/problem/staticrmq
import sys

from python_library.data_structures.segment_tree import SegmentTree

input = sys.stdin.buffer.readline


def main() -> None:
    _, Q = map(int, input().split())
    A = [int(x) for x in input().split()]
    rmq = SegmentTree.create_from_array(A, min, 10 ** 9)
    ans = []
    for _ in range(Q):
        l, r = map(int, input().split())
        ans.append(rmq.query(l, r))
    print(*ans, sep="\n")


if __name__ == "__main__":
    main()
