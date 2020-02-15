# verify-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A
# @import python_library/geometry/geometry.py
# @import python_library/geometry/convex_hull.py
import sys

sys.path.insert(0, ".")
input = sys.stdin.buffer.readline

from python_library.geometry.geometry import Point
from python_library.geometry.convex_hull import ConvexHull


def main() -> None:
    N = int(input())
    ps = []
    for _ in range(N):
        x, y = map(int, input().split())
        ps.append(Point(x, y))
    hull = ConvexHull(ps)
    convex = hull.run()
    print(len(convex))
    min_idx = -1
    min_x, min_y = 10001, 10001
    for i, p in enumerate(convex):
        if p.y < min_y or (p.y == min_y and p.x < min_x):
            min_idx = i
            min_x, min_y = p.x, p.y
    for p in convex[min_idx:]:
        print(p.x, p.y)
    for p in convex[:min_idx]:
        print(p.x, p.y)


if __name__ == "__main__":
    main()
