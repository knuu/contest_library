# verify-helper: PROBLEM https://judge.yosupo.jp/problem/two_sat
# @import python_library/graph/two_sat.py
import sys

sys.path.insert(0, ".")

input = sys.stdin.buffer.readline
sys.setrecursionlimit(10 ** 6 + 100)

from python_library.graph.two_sat import TwoSat


def main() -> None:
    _, _, *NM = input().split()
    N, M = map(int, NM)
    sat = TwoSat(N)
    for _ in range(M):
        u, v, _ = map(int, input().split())
        sat.add_constraint(u, v)
    if sat.run():
        print("s SATISFIABLE")
        print("v", *[i + 1 if sat.ans[i] else -(i + 1) for i in range(N)], 0)
    else:
        print("s UNSATISFIABLE")


if __name__ == "__main__":
    main()
