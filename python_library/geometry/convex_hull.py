# @import python_library/geometry/geometry.py
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
