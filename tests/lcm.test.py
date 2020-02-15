# verify-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C
# @import python_library/math/lcm.py
import sys

sys.path.insert(0, ".")
input = sys.stdin.buffer.readline

from python_library.math.lcm import lcm


def main() -> None:
    _ = int(input())
    print(lcm([int(x) for x in input().split()]))


if __name__ == "__main__":
    main()
