# verify-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C
# @import python_library/data_structres/range_tree_2d.py
import sys

sys.path.insert(0, ".")
input = sys.stdin.buffer.readline

from python_library.data_structures.range_tree_2d import RangeTree2D


def main() -> None:
    N = int(input())
    points = [tuple(map(int, input().split())) for _ in range(N)]
    rt = RangeTree2D()
    rt.build(points)
    for _ in range(int(input())):
        x1, x2, y1, y2 = map(int, input().split())
        output = []
        rt.query((x1, x2), (y1, y2), output)
        if output:
            output.sort()
            print(*output, sep="\n")
        print()


if __name__ == "__main__":
    main()
