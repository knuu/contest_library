import itertools
import sys
from functools import cmp_to_key
from typing import Iterable, List, Tuple


input = sys.stdin.buffer.readline


def argsort_numpy(points: List[Tuple[float, float]]
                  ) -> List[Tuple[float, float]]:
    import numpy as np
    args = [(np.arctan2(y, x, dtype=np.longdouble), idx)
            for idx, (x, y) in enumerate(points)]
    args.sort()
    return [points[i] for _, i in args]


def compare(p1, p2):
    (x1, y1), (x2, y2) = p1, p2
    if x1 * y2 == x2 * y1:
        return 0
    return 1 if x1 * y2 < x2 * y1 else -1


def argsort(points: List[Tuple[float, float]]
            ) -> Iterable[Tuple[float, float]]:
    lowers, uppers, origins = [], [], []

    for x, y in points:
        if y < 0 or (y == 0 and x > 0):
            lowers.append((x, y))
        elif y > 0 or (y == 0 and x < 0):
            uppers.append((x, y))
        else:
            origins.append((x, y))
    lowers.sort(key=cmp_to_key(compare))
    uppers.sort(key=cmp_to_key(compare))
    origins.sort(key=cmp_to_key(compare))
    return itertools.chain(lowers, origins, uppers)


def yosupo():
    # https://judge.yosupo.jp/problem/sort_points_by_argument
    N = int(input())
    points = [tuple(int(val) for val in input().split()) for _ in range(N)]
    for x, y in argsort_numpy(points):
        print(x, y)


def yosupo2():
    # https://judge.yosupo.jp/problem/sort_points_by_argument
    N = int(input())
    points = [tuple(int(val) for val in input().split()) for _ in range(N)]
    for x, y in argsort(points):
        print(x, y)


if __name__ == "__main__":
    # yosupo()
    yosupo2()
