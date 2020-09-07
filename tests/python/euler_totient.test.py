# verify-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D
# @import python_library/math/euler_totient.py
import sys

sys.path.insert(0, ".")
input = sys.stdin.buffer.readline

from python_library.math.euler_totient import euler_totient


def main() -> None:
    print(euler_totient(int(input())))


if __name__ == "__main__":
    main()
