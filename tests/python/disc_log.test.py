# verify-helper: PROBLEM https://judge.yosupo.jp/problem/discrete_logarithm_mod
import sys

from python_library.math.disc_log import solve_discrete_logarithm

input = sys.stdin.buffer.readline


def main() -> None:
    for _ in range(int(input())):
        print(solve_discrete_logarithm(*map(int, input().split())))


if __name__ == "__main__":
    main()
