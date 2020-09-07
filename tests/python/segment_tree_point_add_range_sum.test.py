# verify-helper: PROBLEM https://judge.yosupo.jp/problem/point_add_range_sum
import operator
import sys

from python_library.data_structures.segment_tree import SegmentTree

input = sys.stdin.buffer.readline


def main() -> None:
    _, Q = map(int, input().split())
    A = [int(x) for x in input().split()]
    rsq = SegmentTree.create_from_array(A, operator.add, 0)
    ans = []
    for _ in range(Q):
        type_, l, r = map(int, input().split())
        if type_ == 0:
            rsq.update(l, rsq[l] + r)
        else:
            ans.append(rsq.query(l, r))
    print(*ans, sep="\n")


if __name__ == "__main__":
    main()
