# verify-helper: PROBLEM https://judge.yosupo.jp/problem/point_add_range_sum
# @import python_library/data_structures/fenwick_tree.py
import sys

sys.path.insert(0, ".")
input = sys.stdin.buffer.readline

from python_library.data_structures.fenwick_tree import FenwickTree


def main() -> None:
    _, Q = map(int, input().split())
    fwt = FenwickTree([int(x) for x in input().split()])
    ans = []
    for _ in range(Q):
        type_, l, r = map(int, input().split())
        if type_ == 0:
            fwt.add(l, r)
        else:
            ans.append(fwt.query(l - 1, r - 1))
    print(*ans, sep="\n")


if __name__ == "__main__":
    main()
