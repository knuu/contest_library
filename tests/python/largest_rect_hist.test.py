# verify-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C
import sys

from python_library.dynamic_programming.largest_rect_hist import (
    calc_largest_rect_in_hist,
)

input = sys.stdin.buffer.readline


def main() -> None:
    input()
    print(calc_largest_rect_in_hist([int(x) for x in input().split()]))


if __name__ == "__main__":
    main()
