# verify-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
# @import python_library/math/prime.py
import sys

sys.path.insert(0, ".")
input = sys.stdin.buffer.readline

from python_library.math.prime import miller_rabin


def main() -> None:
    N = int(input())
    print(sum(miller_rabin(int(input())) for _ in range(N)))


if __name__ == "__main__":
    main()
