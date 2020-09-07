# verify-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_B
import sys

from python_library.dynamic_programming.largest_rect_hist import (
    calc_largest_rect_in_hist,
)

input = sys.stdin.buffer.readline


def main() -> None:
    H, W = map(int, input().split())
    board = [[int(x) for x in input().split()] for _ in range(H)]
    dp = [0] * W
    ret = 0
    for r in range(H):
        for c in range(W):
            dp[c] = dp[c] + 1 if board[r][c] == 0 else 0
        ret = max(ret, calc_largest_rect_in_hist(dp))
    print(ret)


if __name__ == "__main__":
    main()
