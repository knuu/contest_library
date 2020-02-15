# used in AOJ No.68, yukicoder No.199
# complexity: O(n^(1/2))

from python_library.geometry.geometry import Point


class ConvexHull:
    def __init__(self, points) -> None:
        self.ps = points

    def run(self):
        ps = sorted(self.ps)
        lower_hull = self.get_bounds(ps)
        ps = ps[::-1]
        upper_hull = self.get_bounds(ps)
        del upper_hull[-1]
        del lower_hull[-1]
        lower_hull.extend(upper_hull)
        return lower_hull

    def get_bounds(self, ps):
        qs = [ps[0], ps[1]]
        for p in ps[2:]:
            while len(qs) > 1 and (qs[-1] - qs[-2]).det(p - qs[-1]) < 0:
                del qs[-1]
            qs.append(p)
        return qs


def aoj():
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
    aoj()
