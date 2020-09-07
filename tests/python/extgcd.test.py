# verify-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E
# @import python_library/math/extgcd.py
import sys

sys.path.insert(0, ".")
input = sys.stdin.buffer.readline

from python_library.math.extgcd import extgcd


def main() -> None:
    print(*extgcd(*map(int, input().split()))[:-1])


if __name__ == "__main__":
    main()
