# verify-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D
import sys

from python_library.math.euler_totient import euler_totient

input = sys.stdin.buffer.readline


def main() -> None:
    print(euler_totient(int(input())))


if __name__ == "__main__":
    main()
