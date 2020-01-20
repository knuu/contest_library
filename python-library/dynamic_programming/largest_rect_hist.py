def calc_largest_rect_in_hist(heights):
    heights.append(0)
    stack = []
    left = [0] * len(heights)
    ans = 0
    for i, height in enumerate(heights):
        while stack and heights[stack[-1]] >= height:
            idx = stack.pop()
            ans = max(ans, (i - left[idx] - 1) * heights[idx])
        left[i] = stack[-1] if stack else -1
        stack.append(i)
    heights.pop()
    return ans


def aoj_hist():
    # https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_3_C
    input()
    print(calc_largest_rect_in_hist([int(x) for x in input().split()]))


def aoj_rect():
    # https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_3_B
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
    # aoj_hist()
    aoj_rect()
