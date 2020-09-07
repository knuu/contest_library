# verify-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
import sys

from python_library.math.prime import miller_rabin

input = sys.stdin.buffer.readline


def main() -> None:
    N = int(input())
    print(sum(miller_rabin(int(input())) for _ in range(N)))


if __name__ == "__main__":
    main()
