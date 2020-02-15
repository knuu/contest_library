# verify-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0068
# @import python_library/geometry/geometry.py
# @import python_library/geometry/convex_hull.py
import sys

sys.path.insert(0, ".")
input = sys.stdin.buffer.readline

from python_library.geometry.geometry import Point
from python_library.geometry.convex_hull import ConvexHull


def main() -> None:
    while True:
        n = int(input())
        if n == 0:
            break
        points = []
        for _ in range(n):
            x, y = map(float, input().split(b","))
            points.append(Point(x, y))
        hull = ConvexHull(points)
        print(len(points) - len(hull.run()))


if __name__ == "__main__":
    main()
