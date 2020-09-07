# verify-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E
import sys

from python_library.math.extgcd import extgcd

input = sys.stdin.buffer.readline


def main() -> None:
    print(*extgcd(*map(int, input().split()))[:-1])


if __name__ == "__main__":
    main()
