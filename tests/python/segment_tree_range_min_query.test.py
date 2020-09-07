# verify-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
import sys

from python_library.data_structures.segment_tree import SegmentTree

input = sys.stdin.buffer.readline


def main() -> None:
    N, Q = map(int, input().split())
    default = (1 << 31) - 1
    rmq = SegmentTree(N, min, default)
    for _ in range(Q):
        com, x, y = map(int, input().split())
        if com == 0:
            rmq.update(x, y)
        else:
            print(rmq.query(x, y + 1))


if __name__ == "__main__":
    main()
