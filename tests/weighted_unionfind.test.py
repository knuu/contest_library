# verify-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
# @import python_library/data_structures/weighted_unionfind.py
import sys

sys.path.insert(0, ".")
input = sys.stdin.buffer.readline

from python_library.data_structures.weighted_unionfind import WeightedUnionFindTree


def main() -> None:
    N, Q = map(int, input().split())
    uft = WeightedUnionFindTree(N)
    ans = []
    for _ in range(Q):
        type_, u, v, *weight = map(int, input().split())
        if type_ == 0:
            uft.unite(u, v, weight[0])
        else:
            ans.append(uft.diff(u, v) if uft.is_same(u, v) else "?")
    print("\n".join(map(str, ans)))


if __name__ == "__main__":
    main()
