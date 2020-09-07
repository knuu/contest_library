# verify-helper: PROBLEM https://judge.yosupo.jp/problem/discrete_logarithm_mod
# @import python_library/math/disc_log.py
import sys

sys.path.insert(0, ".")
input = sys.stdin.buffer.readline

from python_library.math.disc_log import solve_discrete_logarithm


def main() -> None:
    for _ in range(int(input())):
        print(solve_discrete_logarithm(*map(int, input().split())))


if __name__ == "__main__":
    main()
