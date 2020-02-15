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
