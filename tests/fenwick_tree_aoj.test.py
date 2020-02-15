# verify-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
# @import python_library/data_structures/fenwick_tree.py
import sys

sys.path.insert(0, ".")
input = sys.stdin.buffer.readline

from python_library.data_structures.fenwick_tree import FenwickTree


def main() -> None:
    N, Q = map(int, input().split())
    fwt = FenwickTree([0] * N)
    ans = []
    for _ in range(Q):
        type_, l, r = map(int, input().split())
        if type_ == 0:
            fwt.add(l - 1, r)
        else:
            ans.append(fwt.query(l - 2, r - 1))
    print(*ans, sep="\n")


if __name__ == "__main__":
    main()
