# verify-helper: PROBLEM https://judge.yosupo.jp/problem/zalgorithm
import sys

from python_library.string.z_algorithm import z_algorithm

input = sys.stdin.buffer.readline


def main() -> None:
    print(*z_algorithm(input().strip()))


if __name__ == "__main__":
    main()
