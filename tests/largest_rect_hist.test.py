# verify-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C
# @import python_library/dynamic_programming/largest_rect_hist.py
import sys

sys.path.insert(0, ".")
input = sys.stdin.buffer.readline

from python_library.dynamic_programming.largest_rect_hist import (
    calc_largest_rect_in_hist,
)


def main() -> None:
    input()
    print(calc_largest_rect_in_hist([int(x) for x in input().split()]))


if __name__ == "__main__":
    main()
