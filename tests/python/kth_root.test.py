# verify-helper: PROBLEM https://judge.yosupo.jp/problem/kth_root_integer
import sys

from python_library.math.kth_root import kth_root

input = sys.stdin.buffer.readline


def main() -> None:
    ans = [kth_root(*map(int, input().split())) for _ in range(int(input()))]
    print(*ans, sep="\n")


if __name__ == "__main__":
    main()
